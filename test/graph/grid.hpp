// Copyright (C) 2026 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <cstddef>
#include <utility>
#include <algorithm>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/properties.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/core/lightweight_test.hpp>

template <typename Grid>
void test_out_edges(Grid const& g, typename ::boost::graph_traits<Grid>::vertex_descriptor v)
{
    typename ::boost::graph_traits<Grid>::out_edge_iterator oe_itr, oe_itr_end;

    ::boost::tie(oe_itr, oe_itr_end) = out_edges(v, g);
    BOOST_TEST(out_degree(v, g) == ::std::distance(oe_itr, oe_itr_end));

    typename ::boost::graph_traits<Grid>::vertex_descriptor u, w;
    typename ::boost::graph_traits<Grid>::edge_descriptor re;
    ::std::ptrdiff_t d;
    typename Grid::edge_key k, k_r;

    for (
        ::std::pair<typename ::boost::graph_traits<Grid>::edge_descriptor,bool> p_e_b;
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
                BOOST_TEST(v == g.next(w, k_r, d + 1));
                BOOST_TEST(w == g.previous(v, k, -d - 1));
                BOOST_TEST(v == g.previous(w, k_r, -d - 1));
            }
        }
    }
}

template <typename Grid>
void test_in_edges(Grid const& g, typename ::boost::graph_traits<Grid>::vertex_descriptor v)
{
    typename ::boost::graph_traits<Grid>::in_edge_iterator ie_itr, ie_itr_end;

    ::boost::tie(ie_itr, ie_itr_end) = in_edges(v, g);
    BOOST_TEST(in_degree(v, g) == ::std::distance(ie_itr, ie_itr_end));

    typename ::boost::graph_traits<Grid>::vertex_descriptor u, w;
    typename ::boost::graph_traits<Grid>::edge_descriptor re;
    ::std::ptrdiff_t d;
    typename Grid::edge_key k, k_r;

    for (
        ::std::pair<typename ::boost::graph_traits<Grid>::edge_descriptor,bool> p_e_b;
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
                BOOST_TEST(v == g.previous(w, k_r, d + 1));
                BOOST_TEST(w == g.next(v, k, -d - 1));
                BOOST_TEST(v == g.next(w, k_r, -d - 1));
            }
        }
    }
}

template <typename Grid>
void test_adjacency(Grid const& g, typename ::boost::graph_traits<Grid>::vertex_descriptor v)
{
    typename ::boost::graph_traits<Grid>::adjacency_iterator oa_itr, oa_itr_end;

    ::boost::tie(oa_itr, oa_itr_end) = adjacent_vertices(v, g);
    BOOST_TEST(out_degree(v, g) == ::std::distance(oa_itr, oa_itr_end));

    for (
        ::std::pair<typename ::boost::graph_traits<Grid>::edge_descriptor,bool> p_e_b;
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
        BOOST_TEST(v == g.next(*oa_itr, key(get(get(::boost::edge_reverse, g), p_e_b.first), g)));
        BOOST_TEST(
            *oa_itr == g.previous(v, key(get(get(::boost::edge_reverse, g), p_e_b.first), g))
        );
    }
}

template <typename Grid>
void
    test_inverse_adjacency(
        Grid const& g,
        typename ::boost::graph_traits<Grid>::vertex_descriptor v
    )
{
    typename Grid::inv_adjacency_iterator ia_itr, ia_itr_end;

    ::boost::tie(ia_itr, ia_itr_end) = inv_adjacent_vertices(v, g);
    BOOST_TEST(in_degree(v, g) == ::std::distance(ia_itr, ia_itr_end));

    for (
        ::std::pair<typename ::boost::graph_traits<Grid>::edge_descriptor,bool> p_e_b;
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
        BOOST_TEST(*ia_itr == g.next(v, key(get(get(::boost::edge_reverse, g), p_e_b.first), g)));
        BOOST_TEST(
            v == g.previous(*ia_itr, key(get(get(::boost::edge_reverse, g), p_e_b.first), g))
        );
    }
}

template <typename Grid, typename FnV, typename FnE0, typename FnE1>
void test_vertices_and_edges(Grid const& g, FnV fn_v, FnE0 fn_e0, FnE1 fn_e1)
{
//::std::cout << "test_vertices_and_edges" << ::std::endl;
    typename ::boost::graph_traits<Grid>::vertex_iterator u_itr, u_itr_end, v_itr, v_itr_end;
    ::std::pair<typename ::boost::graph_traits<Grid>::edge_descriptor,bool> p_e_b;
    typename ::boost::graph_traits<Grid>::vertices_size_type u_index, v_index;
    typename ::boost::graph_traits<Grid>::edges_size_type e_index;

    ::boost::tie(u_itr, u_itr_end) = vertices(g);

    for (BOOST_TEST(num_vertices(g) == u_itr_end - u_itr); u_itr < u_itr_end; ++u_itr)
    {
        u_index = get(get(::boost::vertex_index, g), *u_itr);
        BOOST_TEST(*u_itr == vertex(u_index, g));
        test_out_edges(g, *u_itr);
        test_in_edges(g, *u_itr);
        test_adjacency(g, *u_itr);
        test_inverse_adjacency(g, *u_itr);
        fn_v(*u_itr, u_index);

        for (::boost::tie(v_itr, v_itr_end) = vertices(g); v_itr < v_itr_end; ++v_itr)
        {
            p_e_b = edge(*u_itr, *v_itr, g);
            v_index = get(get(::boost::vertex_index, g), *v_itr);

            if (p_e_b.second)
            {
                BOOST_TEST(*u_itr == source(p_e_b.first, g));
                BOOST_TEST(*v_itr == target(p_e_b.first, g));
                BOOST_TEST(*v_itr == g.next(*u_itr, key(p_e_b.first, g)));
                BOOST_TEST(*v_itr == g.next(*u_itr, key(p_e_b.first, g), 1));
                BOOST_TEST(*u_itr == g.previous(*v_itr, key(p_e_b.first, g)));
                BOOST_TEST(*u_itr == g.previous(*v_itr, key(p_e_b.first, g), 1));
                e_index = get(get(::boost::edge_index, g), p_e_b.first);
                BOOST_TEST(p_e_b.first == edge(e_index, g));
                BOOST_TEST(!fn_e0(u_index, v_index));
                BOOST_TEST(fn_e1(u_index, v_index, key(p_e_b.first, g), e_index));
            }
            else
            {
                BOOST_TEST(fn_e0(u_index, v_index));
            }
        }
    }

    typename ::boost::graph_traits<Grid>::edge_iterator e_itr, e_itr_end;

    ::boost::tie(e_itr, e_itr_end) = edges(g);

    for (BOOST_TEST(num_edges(g) == e_itr_end - e_itr); e_itr < e_itr_end; ++e_itr)
    {
        BOOST_TEST(*e_itr == edge(get(get(::boost::edge_index, g), *e_itr), g));
        p_e_b = edge(source(*e_itr, g), target(*e_itr, g), g);
        BOOST_TEST(p_e_b.second);
        BOOST_TEST(p_e_b.first == *e_itr);
    }
}

