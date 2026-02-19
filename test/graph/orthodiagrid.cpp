// Copyright (C) 2026 Cromwell D. Enage

#include <odds_and_ends/graph/orthodiagrid.hpp>
#include <boost/mpl/size_t.hpp>

typedef ::odds_and_ends::graph::orthodiagrid<> Grid;

#include <cstddef>
#include <utility>
#include <algorithm>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/properties.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/core/lightweight_test.hpp>

void test_out_edges(Grid const& g, ::boost::graph_traits<Grid>::vertex_descriptor v)
{
    ::boost::graph_traits<Grid>::out_edge_iterator oe_itr, oe_itr_end;

    ::boost::tie(oe_itr, oe_itr_end) = out_edges(v, g);
    BOOST_TEST(out_degree(v, g) == ::std::distance(oe_itr, oe_itr_end));

    ::boost::graph_traits<Grid>::vertex_descriptor u, w;
    ::boost::graph_traits<Grid>::edge_descriptor re;
    ::std::ptrdiff_t d;
    Grid::edge_key k, k_r;

    for (
        ::std::pair< ::boost::graph_traits<Grid>::edge_descriptor,bool> p_e_b;
        oe_itr != oe_itr_end;
        ++oe_itr
    )
    {
        BOOST_TEST(v == source(*oe_itr, g));
        k = key(*oe_itr, g);
        u = target(*oe_itr, g);
        BOOST_TEST(u == g.next(v, k));
        BOOST_TEST(u == g.next(v, k, 1));
        BOOST_TEST(u == g.previous(v, k, -1));
        BOOST_TEST(v == g.previous(u, k));
        BOOST_TEST(v == g.previous(u, k, 1));
        BOOST_TEST(v == g.next(u, k, -1));
        re = get(get(::boost::edge_reverse, g), *oe_itr);
        BOOST_TEST(v == target(re, g));
        BOOST_TEST(u == source(re, g));
        k_r = key(re, g);
        BOOST_TEST(v == g.next(u, k_r));
        BOOST_TEST(v == g.next(u, k_r, 1));
        BOOST_TEST(v == g.previous(u, k_r, -1));
        BOOST_TEST(u == g.previous(v, k_r));
        BOOST_TEST(u == g.previous(v, k_r, 1));
        BOOST_TEST(u == g.next(v, k_r, -1));
        BOOST_TEST(*oe_itr == edge(get(get(::boost::edge_index, g), *oe_itr), g));
        p_e_b = edge(v, u, g);
        BOOST_TEST(p_e_b.second);
        BOOST_TEST(*oe_itr == p_e_b.first);

        for (d = 1; d < 10; ++d)
        {
            w = g.next(u, k, d);

            if (w != Grid::null_vertex())
            {
                BOOST_TEST(w == g.next(v, k, d + 1));
                BOOST_TEST(w == g.previous(v, k, -d - 1));
            }
        }
    }
}

void test_in_edges(Grid const& g, ::boost::graph_traits<Grid>::vertex_descriptor v)
{
    ::boost::graph_traits<Grid>::in_edge_iterator ie_itr, ie_itr_end;

    ::boost::tie(ie_itr, ie_itr_end) = in_edges(v, g);
    BOOST_TEST(in_degree(v, g) == ::std::distance(ie_itr, ie_itr_end));

    ::boost::graph_traits<Grid>::vertex_descriptor u, w;
    ::boost::graph_traits<Grid>::edge_descriptor re;
    ::std::ptrdiff_t d;
    Grid::edge_key k, k_r;

    for (
        ::std::pair< ::boost::graph_traits<Grid>::edge_descriptor,bool> p_e_b;
        ie_itr != ie_itr_end;
        ++ie_itr
    )
    {
        BOOST_TEST(v == target(*ie_itr, g));
        k = key(*ie_itr, g);
        u = source(*ie_itr, g);
        BOOST_TEST(u == g.previous(v, k));
        BOOST_TEST(u == g.previous(v, k, 1));
        BOOST_TEST(u == g.next(v, k, -1));
        BOOST_TEST(v == g.next(u, k));
        BOOST_TEST(v == g.next(u, k, 1));
        BOOST_TEST(v == g.previous(u, k, -1));
        re = get(get(::boost::edge_reverse, g), *ie_itr);
        BOOST_TEST(v == source(re, g));
        BOOST_TEST(u == target(re, g));
        k_r = key(re, g);
        BOOST_TEST(v == g.previous(u, k_r));
        BOOST_TEST(v == g.previous(u, k_r, 1));
        BOOST_TEST(v == g.next(u, k_r, -1));
        BOOST_TEST(u == g.next(v, k_r));
        BOOST_TEST(u == g.next(v, k_r, 1));
        BOOST_TEST(u == g.previous(v, k_r, -1));
        BOOST_TEST(*ie_itr == edge(get(get(::boost::edge_index, g), *ie_itr), g));
        p_e_b = edge(u, v, g);
        BOOST_TEST(p_e_b.second);
        BOOST_TEST(*ie_itr == p_e_b.first);

        for (d = 1; d < 10; ++d)
        {
            w = g.previous(u, k, d);

            if (w != Grid::null_vertex())
            {
                BOOST_TEST(w == g.previous(v, k, d + 1));
                BOOST_TEST(w == g.next(v, k, -d - 1));
            }
        }
    }
}

void test_adjacency(Grid const& g, ::boost::graph_traits<Grid>::vertex_descriptor v)
{
    ::boost::graph_traits<Grid>::adjacency_iterator oa_itr, oa_itr_end;

    ::boost::tie(oa_itr, oa_itr_end) = adjacent_vertices(v, g);
    BOOST_TEST(out_degree(v, g) == ::std::distance(oa_itr, oa_itr_end));

    for (
        ::std::pair< ::boost::graph_traits<Grid>::edge_descriptor,bool> p_e_b;
        oa_itr != oa_itr_end;
        ++oa_itr
    )
    {
        p_e_b = edge(v, *oa_itr, g);
        BOOST_TEST(p_e_b.second);
        BOOST_TEST(v == source(p_e_b.first, g));
        BOOST_TEST(*oa_itr == target(p_e_b.first, g));
        BOOST_TEST(*oa_itr == g.next(v, key(p_e_b.first, g)));
        BOOST_TEST(v == g.previous(target(p_e_b.first, g), key(p_e_b.first, g)));
        BOOST_TEST(v == target(get(get(::boost::edge_reverse, g), p_e_b.first), g));
        BOOST_TEST(*oa_itr == source(get(get(::boost::edge_reverse, g), p_e_b.first), g));
    }
}

void test_inverse_adjacency(Grid const& g, ::boost::graph_traits<Grid>::vertex_descriptor v)
{
    Grid::inv_adjacency_iterator ia_itr, ia_itr_end;

    ::boost::tie(ia_itr, ia_itr_end) = inv_adjacent_vertices(v, g);
    BOOST_TEST(in_degree(v, g) == ::std::distance(ia_itr, ia_itr_end));

    for (
        ::std::pair< ::boost::graph_traits<Grid>::edge_descriptor,bool> p_e_b;
        ia_itr != ia_itr_end;
        ++ia_itr
    )
    {
        p_e_b = edge(*ia_itr, v, g);
        BOOST_TEST(p_e_b.second);
        BOOST_TEST(v == target(p_e_b.first, g));
        BOOST_TEST(*ia_itr == source(p_e_b.first, g));
        BOOST_TEST(*ia_itr == g.previous(v, key(p_e_b.first, g)));
        BOOST_TEST(v == g.next(source(p_e_b.first, g), key(p_e_b.first, g)));
        BOOST_TEST(v == source(get(get(::boost::edge_reverse, g), p_e_b.first), g));
        BOOST_TEST(*ia_itr == target(get(get(::boost::edge_reverse, g), p_e_b.first), g));
    }
}

#include <bitset>

void
    test(
        ::boost::graph_traits<Grid>::vertices_size_type const l0,
        ::boost::graph_traits<Grid>::vertices_size_type const l1,
        bool w0,
        bool w1,
        ::boost::graph_traits<Grid>::vertices_size_type const expected_vertex_count,
        ::boost::graph_traits<Grid>::edges_size_type const expected_edge_count
    )
{
    Grid grid(l0, l1, w0, w1);
    ::boost::graph_traits<Grid>::vertex_iterator v_itr, v_itr_end;
    ::boost::graph_traits<Grid>::edge_iterator e_itr, e_itr_end;
    ::std::pair< ::boost::graph_traits<Grid>::edge_descriptor,bool> p_e_b;

    BOOST_TEST(l0 == grid.length(0));
    BOOST_TEST(l1 == grid.length(1));
    BOOST_TEST(w0 == !!grid.wrapped(0));
    BOOST_TEST(w1 == !!grid.wrapped(1));
    BOOST_TEST(expected_vertex_count == num_vertices(grid));
    BOOST_TEST(expected_edge_count == num_edges(grid));
    ::boost::tie(v_itr, v_itr_end) = vertices(grid);
    BOOST_TEST(expected_vertex_count == v_itr_end - v_itr);

    for (; v_itr < v_itr_end; ++v_itr)
    {
        BOOST_TEST(*v_itr == vertex(get(get(::boost::vertex_index, grid), *v_itr), grid));
        test_out_edges(grid, *v_itr);
        test_in_edges(grid, *v_itr);
        test_adjacency(grid, *v_itr);
        test_inverse_adjacency(grid, *v_itr);
    }

    ::boost::tie(e_itr, e_itr_end) = edges(grid);
    BOOST_TEST(expected_edge_count == e_itr_end - e_itr);

    for (; e_itr < e_itr_end; ++e_itr)
    {
        BOOST_TEST(*e_itr == edge(get(get(::boost::edge_index, grid), *e_itr), grid));
        p_e_b = edge(source(*e_itr, grid), target(*e_itr, grid), grid);
        BOOST_TEST(p_e_b.second);
        BOOST_TEST(p_e_b.first == *e_itr);
    }
}

int main(int argc, char** argv)
{
    test(4, 5, true, true, 20, 160);
    test(4, 5, false, false, 20, 110);
    test(4, 5, false, true, 20, 130);
    test(4, 5, true, false, 20, 136);
    return ::boost::report_errors();
}

