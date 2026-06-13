// Copyright (C) 2026 Cromwell D. Enage

#include <vector>
#include <boost/graph/graph_traits.hpp>
#include <boost/core/lightweight_test.hpp>

template <typename Grid>
class vertex_position_test
{
    ::std::vector<typename ::boost::graph_traits<Grid>::vertex_descriptor> _v_positions;

public:
    explicit vertex_position_test(
        ::std::vector<typename ::boost::graph_traits<Grid>::vertex_descriptor> v_positions
    ) : _v_positions(v_positions)
    {
    }

    void
        operator()(
            typename ::boost::graph_traits<Grid>::vertex_descriptor v,
            typename ::boost::graph_traits<Grid>::vertices_size_type v_index
        ) const
    {
        BOOST_TEST(v == this->_v_positions[v_index]);
    }
};

#include <tuple>

template <typename Grid>
class edge_position_yes_test
{
    ::std::vector<
        ::std::tuple<
            typename ::boost::graph_traits<Grid>::vertices_size_type,
            typename ::boost::graph_traits<Grid>::vertices_size_type,
            typename Grid::edge_key
        >
    > _endpoints;

public:
    explicit edge_position_yes_test(
        ::std::vector<
            ::std::tuple<
                typename ::boost::graph_traits<Grid>::vertices_size_type,
                typename ::boost::graph_traits<Grid>::vertices_size_type,
                typename Grid::edge_key
            >
        > endpoints
    ) : _endpoints(endpoints)
    {
    }

    bool
        operator()(
            typename ::boost::graph_traits<Grid>::vertices_size_type u_index,
            typename ::boost::graph_traits<Grid>::vertices_size_type v_index,
            typename Grid::edge_key k,
            typename ::boost::graph_traits<Grid>::edges_size_type e_index
        ) const
    {
        return ::std::make_tuple(u_index, v_index, k) == this->_endpoints[e_index];
    }
};

#include <utility>
#include <set>

template <typename Grid>
class edge_position_no_test
{
    ::std::set<
        ::std::pair<
            typename ::boost::graph_traits<Grid>::vertices_size_type,
            typename ::boost::graph_traits<Grid>::vertices_size_type
        >
    > _endpoints;

public:
    explicit edge_position_no_test(
        ::std::vector<
            ::std::tuple<
                typename ::boost::graph_traits<Grid>::vertices_size_type,
                typename ::boost::graph_traits<Grid>::vertices_size_type,
                typename Grid::edge_key
            >
        > endpoints
    ) : _endpoints()
    {
        for (::std::size_t i = 0; i < endpoints.size(); ++i)
        {
            this->_endpoints.insert(
                ::std::make_pair(::std::get<0>(endpoints[i]), ::std::get<1>(endpoints[i]))
            );
        }
    }

    bool
        operator()(
            typename ::boost::graph_traits<Grid>::vertices_size_type u_index,
            typename ::boost::graph_traits<Grid>::vertices_size_type v_index
        ) const
    {
        return (
            this->_endpoints.cend() == this->_endpoints.find(::std::make_pair(u_index, v_index))
        );
    }
};

#include <bitset>
#include "grid.hpp"

template <typename Grid>
void
    test_positions(
        typename ::boost::graph_traits<Grid>::vertex_descriptor const lengths,
        ::std::size_t const value,
        ::std::vector<typename ::boost::graph_traits<Grid>::vertex_descriptor> v_positions,
        ::std::vector<
            ::std::tuple<
                typename ::boost::graph_traits<Grid>::vertices_size_type,
                typename ::boost::graph_traits<Grid>::vertices_size_type,
                typename Grid::edge_key
            >
        > endpoints
    )
{
    typedef typename Grid::dimension_count DimCount;

    ::std::bitset<DimCount::value> mask(value);
    Grid grid(lengths, mask);

    for (typename ::boost::graph_traits<Grid>::degree_size_type d = 0; d < DimCount::value; ++d)
    {
        BOOST_TEST(grid.length(d) == lengths[d]);
    }

    BOOST_TEST(num_vertices(grid) == v_positions.size());
    BOOST_TEST(num_edges(grid) == endpoints.size());
    test_vertices_and_edges(
        grid,
        vertex_position_test<Grid>(v_positions),
        edge_position_no_test<Grid>(endpoints),
        edge_position_yes_test<Grid>(endpoints)
    );
}

