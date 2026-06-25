// Copyright (C) 2026 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef ODDS_AND_ENDS__GRAPH__ZETA_GRID_HPP
#define ODDS_AND_ENDS__GRAPH__ZETA_GRID_HPP

namespace odds_and_ends { namespace graph { namespace _detail {

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    struct zeta_grid_reverse_edge_map;
}}}  // namespace odds_and_ends::graph::_detail

#include <cstddef>
#include <type_traits>
#include <functional>
#include <algorithm>
#include <utility>
#include <array>
#include <bitset>
#include <vector>
#include <iterator>
#include <odds_and_ends/graph/_detail/edge_iterator.hpp>
#include <odds_and_ends/graph/parameter/template.hpp>
#include <odds_and_ends/node/parameter/template.hpp>
#include <odds_and_ends/node/container/elemental_interval_map.hpp>
#include <odds_and_ends/node/container/set.hpp>
#include <odds_and_ends/node/balancer/adelson_velskii_landis_tree.hpp>
#include <odds_and_ends/node/with_balance_factor.hpp>
#include <odds_and_ends/static_introspection/concept/is_math_integral_type.hpp>
#include <odds_and_ends/static_introspection/concept/is_mpl_integral_constant.hpp>
#include <odds_and_ends/static_introspection/math/integral_power.hpp>
#include <odds_and_ends/use_default_policy.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_iterator.hpp>
#include <boost/iterator/counting_iterator.hpp>
#include <boost/parameter/optional.hpp>
#include <boost/parameter/parameters.hpp>
#include <boost/parameter/value_type.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/mpl/range_c.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/quote.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/mpl/assert.hpp>

namespace odds_and_ends { namespace graph {

    template <
        typename DimCount,
        typename T0 = ::boost::parameter::void_,
        typename T1 = ::boost::parameter::void_,
        typename T2 = ::boost::parameter::void_,
        typename T3 = ::boost::parameter::void_,
        typename T4 = ::boost::parameter::void_,
        typename T5 = ::boost::parameter::void_
    >
    class zeta_grid
    {
        typedef typename ::boost::parameter::parameters<
            ::boost::parameter::optional<
                ::odds_and_ends::graph::parameter::tag::_vertex_index
            >,
            ::boost::parameter::optional<
                ::odds_and_ends::graph::parameter::tag::_edge_index
            >,
            ::boost::parameter::optional<
                ::odds_and_ends::graph::parameter::tag::_index_difference
            >,
            ::boost::parameter::optional<
                ::odds_and_ends::node::parameter::tag::_pointer_transform
            >,
            ::boost::parameter::optional<
                ::odds_and_ends::node::parameter::tag::_compare_generator
            >,
            ::boost::parameter::optional<
                ::odds_and_ends::node::parameter::tag::_container_generator
            >
        >::template bind<T0,T1,T2,T3,T4,T5>::type _template_args;
        typedef typename ::boost::parameter::value_type<
            _template_args,
            ::odds_and_ends::graph::parameter::tag::_index_difference,
            ::std::ptrdiff_t
        >::type _index_difference;
        typedef typename ::boost::parameter::value_type<
            _template_args,
            ::odds_and_ends::node::parameter::tag::_compare_generator,
            ::boost::mpl::quote1< ::std::less>
        >::type _compare_gen;
        typedef typename ::boost::parameter::value_type<
            _template_args,
            ::odds_and_ends::node::parameter::tag::_container_generator,
            ::odds_and_ends::use_default_policy
        >::type _container_gen;

    public:
        // If only template specializations could be friends instead...
        typedef typename ::boost::parameter::value_type<
            _template_args,
            ::odds_and_ends::node::parameter::tag::_pointer_transform,
            ::boost::mpl::quote1< ::std::add_pointer>
        >::type _ptr_xform;

    public:
        typedef ::odds_and_ends::graph::zeta_grid<DimCount,T0,T1,T2,T3,T4,T5> type;
        typedef DimCount dimension_count;
        typedef typename ::boost::parameter::value_type<
            _template_args,
            ::odds_and_ends::graph::parameter::tag::_vertex_index,
            ::std::size_t
        >::type vertices_size_type;
        typedef typename ::boost::parameter::value_type<
            _template_args,
            ::odds_and_ends::graph::parameter::tag::_edge_index,
            vertices_size_type
        >::type edges_size_type;

    private:
        BOOST_MPL_ASSERT((
            ::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<DimCount>
        ));
        BOOST_MPL_ASSERT((
            ::odds_and_ends::static_introspection::concept
            ::is_math_integral_type<vertices_size_type>
        ));
        BOOST_MPL_ASSERT((
            ::odds_and_ends::static_introspection::concept::is_math_integral_type<edges_size_type>
        ));
        BOOST_MPL_ASSERT((
            ::odds_and_ends::static_introspection::concept
            ::is_math_integral_type<_index_difference>
        ));
        static_assert(1 < DimCount::value, "The minimum acceptable value of DimCount is 2.");

    public:
        typedef typename dimension_count::value_type degree_size_type;
        typedef ::std::array<vertices_size_type,dimension_count::value> vertex_descriptor;
        typedef ::std::array<short,dimension_count::value> edge_key;
        typedef ::std::pair<
            ::std::pair<vertex_descriptor,vertex_descriptor>,
            edge_key
        > edge_descriptor;
        typedef ::boost::bidirectional_tag directed_category;
        typedef ::boost::mpl::false_ edge_parallel_category;
        typedef ::odds_and_ends::graph::_detail
        ::edge_iterator<type,_ptr_xform,_index_difference> edge_iterator;

        struct traversal_category :
            ::boost::bidirectional_graph_tag,
            ::boost::adjacency_graph_tag,
            ::boost::vertex_list_graph_tag,
            ::boost::edge_list_graph_tag,
            ::boost::adjacency_matrix_tag
        {
        };

    private:
        /*
        For example, a 2-dimensional zeta grid has 9 vertex categories:
        one for each corner, one for each side, and one for the interior.
        A 3-dimensional zeta grid has 27 vertex categories, corresponding to
        2^3 corners + 3*2*2 edges + 3*2 faces + the interior.
        The category of a vertex determines its out-degree, its in-degree,
        and which edge keys are valid for it.
        */
        typedef ::odds_and_ends::static_introspection::math::integral_power<
            ::boost::mpl::integral_c<degree_size_type,3>,
            dimension_count
        > _vertex_category_count;
        typedef ::boost::mpl::minus<
            _vertex_category_count,
            ::boost::mpl::integral_c<degree_size_type,1>
        > _edge_key_count;
        typedef typename ::boost::mpl::apply_wrap1<_ptr_xform,type const>::type _g_c_ptr;

        template <typename K>
        struct _edge_key_function
        {
            bool operator()(K const& k_lhs, K const& k_rhs) const;
        };

    public:
        class vertex_iterator
        {
            _g_c_ptr _g;
            vertices_size_type _current_index;
            vertex_descriptor _current_vertex;

        public:
            typedef vertex_descriptor const value_type;
            typedef value_type& reference;
            typedef typename ::boost::mpl::apply_wrap1<_ptr_xform,value_type>::type pointer;
            typedef _index_difference difference_type;
            typedef ::std::random_access_iterator_tag iterator_category;

            vertex_iterator();
            vertex_iterator(type const& g, vertices_size_type index);
            reference operator*() const;
            pointer operator->() const;
            vertex_iterator& operator++();
            vertex_iterator operator++(int);
            vertex_iterator& operator--();
            vertex_iterator operator--(int);
            vertex_iterator& operator+=(difference_type const& d);
            vertex_iterator operator+(difference_type const& d) const;
            vertex_iterator& operator-=(difference_type const& d);
            vertex_iterator operator-(difference_type const& d) const;

        private:
            friend inline bool operator==(vertex_iterator const& lhs, vertex_iterator const& rhs)
            {
                return lhs._current_index == rhs._current_index;
            }

            friend inline bool operator!=(vertex_iterator const& lhs, vertex_iterator const& rhs)
            {
                return lhs._current_index != rhs._current_index;
            }

            friend inline bool operator<(vertex_iterator const& lhs, vertex_iterator const& rhs)
            {
                return lhs._current_index < rhs._current_index;
            }

            friend inline bool operator<=(vertex_iterator const& lhs, vertex_iterator const& rhs)
            {
                return lhs._current_index <= rhs._current_index;
            }

            friend inline bool operator>(vertex_iterator const& lhs, vertex_iterator const& rhs)
            {
                return lhs._current_index > rhs._current_index;
            }

            friend inline bool operator>=(vertex_iterator const& lhs, vertex_iterator const& rhs)
            {
                return lhs._current_index >= rhs._current_index;
            }

            friend inline difference_type
                operator-(vertex_iterator const& lhs, vertex_iterator const& rhs)
            {
                difference_type d = static_cast<difference_type>(lhs._current_index);
                d -= rhs._current_index;
                return d;
            }
        };

        class edge_key_iterator
        {
            degree_size_type _current_index;
            edge_key _current_key;

        public:
            typedef edge_key const value_type;
            typedef value_type& reference;
            typedef typename ::boost::mpl::apply_wrap1<_ptr_xform,value_type>::type pointer;
            typedef typename ::std::make_signed<degree_size_type>::type difference_type;
            typedef ::std::random_access_iterator_tag iterator_category;

            explicit edge_key_iterator(degree_size_type index = 0);
            reference operator*() const;
            pointer operator->() const;
            edge_key_iterator& operator++();
            edge_key_iterator operator++(int);
            edge_key_iterator& operator--();
            edge_key_iterator operator--(int);
            edge_key_iterator& operator+=(difference_type const& d);
            edge_key_iterator operator+(difference_type const& d) const;
            edge_key_iterator& operator-=(difference_type const& d);
            edge_key_iterator operator-(difference_type const& d) const;

        private:
            void _post_operation();

            friend inline bool
                operator==(edge_key_iterator const& lhs, edge_key_iterator const& rhs)
            {
                return lhs._current_index == rhs._current_index;
            }

            friend inline bool
                operator!=(edge_key_iterator const& lhs, edge_key_iterator const& rhs)
            {
                return lhs._current_index != rhs._current_index;
            }

            friend inline bool
                operator<(edge_key_iterator const& lhs, edge_key_iterator const& rhs)
            {
                return lhs._current_index < rhs._current_index;
            }

            friend inline bool
                operator<=(edge_key_iterator const& lhs, edge_key_iterator const& rhs)
            {
                return lhs._current_index <= rhs._current_index;
            }

            friend inline bool
                operator>(edge_key_iterator const& lhs, edge_key_iterator const& rhs)
            {
                return lhs._current_index > rhs._current_index;
            }

            friend inline bool
                operator>=(edge_key_iterator const& lhs, edge_key_iterator const& rhs)
            {
                return lhs._current_index >= rhs._current_index;
            }

            friend inline difference_type
                operator-(edge_key_iterator const& lhs, edge_key_iterator const& rhs)
            {
                difference_type d = static_cast<difference_type>(lhs._current_index);
                d -= rhs._current_index;
                return d;
            }
        };

    private:
        template <bool IsOut>
        class _ext_edge_iterator
        {
            _g_c_ptr _g;
            degree_size_type _current_index;
            edge_descriptor _current_edge;

        public:
            typedef edge_descriptor const value_type;
            typedef value_type& reference;
            typedef typename ::boost::mpl::apply_wrap1<_ptr_xform,value_type>::type pointer;
            typedef typename edge_key_iterator::difference_type difference_type;
            typedef ::std::random_access_iterator_tag iterator_category;

            _ext_edge_iterator();
            _ext_edge_iterator(type const& g, vertex_descriptor v, degree_size_type index);
            reference operator*() const;
            pointer operator->() const;
            _ext_edge_iterator& operator++();
            _ext_edge_iterator operator++(int);
            _ext_edge_iterator& operator--();
            _ext_edge_iterator operator--(int);
            _ext_edge_iterator& operator+=(difference_type const& d);
            _ext_edge_iterator operator+(difference_type const& d) const;
            _ext_edge_iterator& operator-=(difference_type const& d);
            _ext_edge_iterator operator-(difference_type const& d) const;

        private:
            void _post_operation();

            friend inline bool
                operator==(_ext_edge_iterator const& lhs, _ext_edge_iterator const& rhs)
            {
                return lhs._current_index == rhs._current_index;
            }

            friend inline bool
                operator!=(_ext_edge_iterator const& lhs, _ext_edge_iterator const& rhs)
            {
                return lhs._current_index != rhs._current_index;
            }

            friend inline bool
                operator<(_ext_edge_iterator const& lhs, _ext_edge_iterator const& rhs)
            {
                return lhs._current_index < rhs._current_index;
            }

            friend inline bool
                operator<=(_ext_edge_iterator const& lhs, _ext_edge_iterator const& rhs)
            {
                return lhs._current_index <= rhs._current_index;
            }

            friend inline bool
                operator>(_ext_edge_iterator const& lhs, _ext_edge_iterator const& rhs)
            {
                return lhs._current_index > rhs._current_index;
            }

            friend inline bool
                operator>=(_ext_edge_iterator const& lhs, _ext_edge_iterator const& rhs)
            {
                return lhs._current_index >= rhs._current_index;
            }

            friend inline difference_type
                operator-(_ext_edge_iterator const& lhs, _ext_edge_iterator const& rhs)
            {
                return lhs._current_index - rhs._current_index;
            }
        };

    public:
        typedef _ext_edge_iterator<true> out_edge_iterator;
        typedef _ext_edge_iterator<false> in_edge_iterator;
        typedef typename ::boost::adjacency_iterator_generator<
            type,
            vertex_descriptor,
            out_edge_iterator
        >::type adjacency_iterator;
        typedef typename ::boost::inv_adjacency_iterator_generator<
            type,
            vertex_descriptor,
            in_edge_iterator
        >::type inv_adjacency_iterator;

        static vertex_descriptor null_vertex();
        static edge_descriptor null_edge();
        static ::std::pair<edge_key_iterator,edge_key_iterator> edge_keys();

    private:
        typedef ::odds_and_ends::node::container::elemental_interval_map<
            vertices_size_type,
            edges_size_type,
            _compare_gen,
            _container_gen
        > _vertex_index_to_edge_index_offset_t;
        typedef ::odds_and_ends::node::container::elemental_interval_map<
            edges_size_type,
            vertices_size_type,
            _compare_gen,
            _container_gen
        > _edge_index_to_vertex_index_t;
        typedef ::odds_and_ends::node::container::elemental_interval_map<
            vertices_size_type,
            degree_size_type,
            _compare_gen,
            _container_gen
        > _vertex_index_to_category_t;
        typedef ::std::array<
            ::std::vector<degree_size_type>,
            _vertex_category_count::value
        > _vertex_category_to_degree_t;
        typedef ::odds_and_ends::node::container::set<
            edge_key,
            ::boost::mpl::false_,
            ::boost::mpl::deque< ::odds_and_ends::node::with_balance_factor>,
            ::odds_and_ends::node::adelson_velskii_landis_tree_balancer,
            ::boost::mpl::quote1<_edge_key_function>
        > _edge_key_set_t;
        typedef ::std::array<
            _edge_key_set_t,
            _vertex_category_count::value
        > _vertex_category_to_edge_key_set_t;

        static edge_key _reverse_key(edge_key k);

        _vertex_index_to_edge_index_offset_t _vertex_index_to_edge_index_offset;
        _edge_index_to_vertex_index_t _edge_index_to_source_vertex_index;
        _vertex_index_to_category_t _vertex_index_to_category;
        _vertex_category_to_degree_t _vertex_category_to_out_edge_key_indices;
        _vertex_category_to_degree_t _vertex_category_to_in_edge_key_indices;
        _vertex_category_to_edge_key_set_t _vertex_category_to_edge_key_set;
        vertex_descriptor _dimension_lengths;
        ::std::bitset<dimension_count::value> _wraparound_mask;
        edges_size_type _edge_count;
        vertices_size_type _vertex_count;

    public:
        zeta_grid(vertex_descriptor dimension_lengths, bool wraparound_all = false);
        zeta_grid(
            vertex_descriptor dimension_lengths,
            ::std::bitset<dimension_count::value> wraparound
        );
        vertices_size_type const& length(degree_size_type const& d) const;
        bool wrapped(degree_size_type const& d) const;
        vertex_descriptor next(vertex_descriptor v, edge_key key) const;
        vertex_descriptor next(vertex_descriptor v, edge_key key, _index_difference d) const;
        vertex_descriptor previous(vertex_descriptor v, edge_key key) const;
        vertex_descriptor previous(vertex_descriptor v, edge_key key, _index_difference d) const;
        vertices_size_type operator[](vertex_descriptor v) const;
        edges_size_type operator[](edge_descriptor e) const;

    private:
        void _post_construct();
        edge_descriptor _edge_at(edges_size_type i) const;
        ::std::pair<edge_descriptor,bool> _edge_at(vertex_descriptor u, vertex_descriptor v) const;

        friend inline vertices_size_type num_vertices(type const& g)
        {
            return g._vertex_count;
        }

        friend inline edges_size_type num_edges(type const& g)
        {
            return g._edge_count;
        }

        friend inline edge_descriptor edge(edges_size_type i, type const& g)
        {
            return g._edge_at(i);
        }

        friend inline ::std::pair<edge_descriptor,bool>
            edge(vertex_descriptor u, vertex_descriptor v, type const& g)
        {
            return g._edge_at(u, v);
        }

        friend inline degree_size_type out_degree(vertex_descriptor v, type const& g)
        {
            return g._vertex_category_to_out_edge_key_indices[
                g._vertex_index_to_category[g[v]]
            ].size();
        }

        friend inline degree_size_type in_degree(vertex_descriptor v, type const& g)
        {
            return g._vertex_category_to_in_edge_key_indices[
                g._vertex_index_to_category[g[v]]
            ].size();
        }

        template <
            typename DC,
            typename U0,
            typename U1,
            typename U2,
            typename U3,
            typename U4,
            typename U5
        >
        friend struct ::odds_and_ends::graph::_detail::zeta_grid_reverse_edge_map;
    };

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_key
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::_reverse_key(edge_key k)
    {
        for (degree_size_type d = 0; d < dimension_count::value; ++d)
        {
            k[d] = -k[d];
        }

        return k;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    template <typename K>
    bool
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::_edge_key_function<K>::operator()(
            K const& k_lhs,
            K const& k_rhs
        ) const
    {
        degree_size_type d_lhs = 0, d_rhs = 0, factor = 1;//_vertex_category_count::value;

        for (degree_size_type d = 0; d < dimension_count::value; ++d)
        {
//            factor /= 3;

            switch (k_lhs[d])
            {
                case -1:
                {
                    d_lhs += factor;
                    break;
                }

                case 1:
                {
                    d_lhs += factor << 1;
                    break;
                }

                case 0:
                {
                    break;
                }

                default:
                {
                    return false;
                }
            }

            switch (k_rhs[d])
            {
                case -1:
                {
                    d_rhs += factor;
                    break;
                }

                case 1:
                {
                    d_rhs += factor << 1;
                    break;
                }

                case 0:
                {
                    break;
                }

                default:
                {
                    return true;
                }
            }

            factor *= 3;
        }

        return d_lhs < d_rhs;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    void zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_key_iterator::_post_operation()
    {
        degree_size_type edge_key_index = (this->_current_index % _edge_key_count::value) + 1;

        for (degree_size_type d = 0; d < dimension_count::value; ++d)
        {
            if (edge_key_index)
            {
                switch (edge_key_index % 3)
                {
                    case 2:
                    {
                        this->_current_key[d] = 1;
                        break;
                    }

                    case 1:
                    {
                        this->_current_key[d] = -1;
                        break;
                    }

                    default:
                    {
                        this->_current_key[d] = 0;
                        break;
                    }
                }

                edge_key_index /= 3;
            }
            else
            {
                this->_current_key[d] = 0;
            }
        }
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    template <bool IsOut>
    void zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::_ext_edge_iterator<IsOut>::_post_operation()
    {
        if (IsOut)
        {
            this->_current_edge.second = *(
                type::edge_keys().first + this->_g->_vertex_category_to_out_edge_key_indices[
                    this->_g->_vertex_index_to_category[(*this->_g)[this->_current_edge.first.first]]
                ][this->_current_index]
            );
            this->_current_edge.first.second = (
                this->_g->next(this->_current_edge.first.first, this->_current_edge.second)
            );
        }
        else
        {
            this->_current_edge.second = *(
                type::edge_keys().first + this->_g->_vertex_category_to_in_edge_key_indices[
                    this->_g->_vertex_index_to_category[(*this->_g)[this->_current_edge.first.second]]
                ][this->_current_index]
            );
            this->_current_edge.first.first = (
                this->_g->previous(this->_current_edge.first.second, this->_current_edge.second)
            );
        }
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_key_iterator::edge_key_iterator(
        degree_size_type index
    ) : _current_index(index), _current_key()
    {
        this->_post_operation();
    }

    template <
        typename DC,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::edge_key_iterator::reference
        zeta_grid<DC,T0,T1,T2,T3,T4,T5>::edge_key_iterator::operator*() const
    {
        return this->_current_key;
    }

    template <
        typename DC,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    template <bool IsOut>
    inline typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::template _ext_edge_iterator<IsOut>::reference
        zeta_grid<DC,T0,T1,T2,T3,T4,T5>::_ext_edge_iterator<IsOut>::operator*() const
    {
        return this->_current_edge;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_key_iterator&
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_key_iterator::operator++()
    {
        ++this->_current_index;
        this->_post_operation();
        return *this;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    template <bool IsOut>
    inline typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::template _ext_edge_iterator<IsOut>&
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::_ext_edge_iterator<IsOut>::operator++()
    {
        ++this->_current_index;
        this->_post_operation();
        return *this;
    }

    template <
        typename DC,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::edge_key_iterator
        zeta_grid<DC,T0,T1,T2,T3,T4,T5>::edge_key_iterator::operator++(int)
    {
        typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::edge_key_iterator itr(*this);
        ++(*this);
        return itr;
    }

    template <
        typename DC,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    template <bool IsOut>
    typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::template _ext_edge_iterator<IsOut>
        zeta_grid<DC,T0,T1,T2,T3,T4,T5>::_ext_edge_iterator<IsOut>::operator++(int)
    {
        typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::template _ext_edge_iterator<IsOut> itr(*this);
        ++(*this);
        return itr;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_key_iterator&
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_key_iterator::operator--()
    {
        --this->_current_index;
        this->_post_operation();
        return *this;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    template <bool IsOut>
    inline typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::template _ext_edge_iterator<IsOut>&
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::_ext_edge_iterator<IsOut>::operator--()
    {
        --this->_current_index;
        this->_post_operation();
        return *this;
    }

    template <
        typename DC,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::edge_key_iterator
        zeta_grid<DC,T0,T1,T2,T3,T4,T5>::edge_key_iterator::operator--(int)
    {
        typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::edge_key_iterator itr(*this);
        --(*this);
        return itr;
    }

    template <
        typename DC,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    template <bool IsOut>
    typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::template _ext_edge_iterator<IsOut>
        zeta_grid<DC,T0,T1,T2,T3,T4,T5>::_ext_edge_iterator<IsOut>::operator--(int)
    {
        typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::template _ext_edge_iterator<IsOut> itr(*this);
        --(*this);
        return itr;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_key_iterator&
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_key_iterator::operator+=(
            difference_type const& d
        )
    {
        this->_current_index += d;
        this->_post_operation();
        return *this;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    template <bool IsOut>
    inline typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::template _ext_edge_iterator<IsOut>&
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::_ext_edge_iterator<IsOut>::operator+=(
            difference_type const& d
        )
    {
        this->_current_index += d;
        this->_post_operation();
        return *this;
    }

    template <
        typename DC,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::edge_key_iterator
        zeta_grid<DC,T0,T1,T2,T3,T4,T5>::edge_key_iterator::operator+(
            difference_type const& d
        ) const
    {
        typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::edge_key_iterator itr(*this);
        itr += d;
        return itr;
    }

    template <
        typename DC,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    template <bool IsOut>
    typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::template _ext_edge_iterator<IsOut>
        zeta_grid<DC,T0,T1,T2,T3,T4,T5>::_ext_edge_iterator<IsOut>::operator+(
            difference_type const& d
        ) const
    {
        typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::template _ext_edge_iterator<IsOut> itr(*this);
        itr += d;
        return itr;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_key_iterator&
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_key_iterator::operator-=(
            difference_type const& d
        )
    {
        this->_current_index -= d;
        this->_post_operation();
        return *this;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    template <bool IsOut>
    inline typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::template _ext_edge_iterator<IsOut>&
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::_ext_edge_iterator<IsOut>::operator-=(
            difference_type const& d
        )
    {
        this->_current_index -= d;
        this->_post_operation();
        return *this;
    }

    template <
        typename DC,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::edge_key_iterator
        zeta_grid<DC,T0,T1,T2,T3,T4,T5>::edge_key_iterator::operator-(
            difference_type const& d
        ) const
    {
        typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::edge_key_iterator itr(*this);
        itr -= d;
        return itr;
    }

    template <
        typename DC,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    template <bool IsOut>
    typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::template _ext_edge_iterator<IsOut>
        zeta_grid<DC,T0,T1,T2,T3,T4,T5>::_ext_edge_iterator<IsOut>::operator-(
            difference_type const& d
        ) const
    {
        typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::template _ext_edge_iterator<IsOut> itr(*this);
        itr -= d;
        return itr;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline ::std::pair<
        typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_key_iterator,
        typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_key_iterator
    >
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_keys()
    {
        return ::std::make_pair(
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_key_iterator(0),
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_key_iterator(
                _edge_key_count::value
            )
        );
    }
}}  // namespace odds_and_ends::graph

#include <limits>

namespace odds_and_ends { namespace graph {

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_descriptor
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::null_vertex()
    {
        static vertex_descriptor _null_vertex;

        for (degree_size_type i = 0; i < dimension_count::value; ++i)
        {
            _null_vertex[i] = (::std::numeric_limits<vertices_size_type>::max)();
        }

        return _null_vertex;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_descriptor
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::null_edge()
    {
        static edge_descriptor _null_edge;

        _null_edge.first.first = type::null_vertex();
        _null_edge.first.second = type::null_vertex();
        return _null_edge;
    }
}}  // namespace odds_and_ends::graph

#include <boost/utility/value_init.hpp>

namespace odds_and_ends { namespace graph { namespace _detail {

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    bool
        is_valid_vertex(
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_descriptor v,
            zeta_grid<DimCount,T0,T1,T2,T3,T4,T5> const& g
        )
    {
        static typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertices_size_type const z = (
            ::boost::initialized_value
        );

        for (
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::degree_size_type d = 0;
            d < DimCount::value;
            ++d
        )
        {
            if ((v[d] < z) || (g.length(d) <= v[d]))
            {
                return false;
            }
        }

        return true;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline bool
        is_valid_edge(
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_descriptor e,
            zeta_grid<DimCount,T0,T1,T2,T3,T4,T5> const& g
        )
    {
        return (
            (e.first.second == g.next(e.first.first, e.second)) &&
            (e.first.first == g.previous(e.first.second, e.second))
        );
    }
}}}  // namespace odds_and_ends::graph::_detail

#include <boost/assert.hpp>

namespace odds_and_ends { namespace graph {

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertices_size_type const&
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::length(degree_size_type const& d) const
    {
        BOOST_ASSERT(d < dimension_count::value);
        return this->_dimension_lengths[d];
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline bool zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::wrapped(degree_size_type const& d) const
    {
        BOOST_ASSERT(d < dimension_count::value);
        return this->_wraparound_mask[d];
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_descriptor
        source(
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_descriptor e,
            zeta_grid<DimCount,T0,T1,T2,T3,T4,T5> const& g
        )
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_edge(e, g));
        return e.first.first;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_descriptor
        target(
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_descriptor e,
            zeta_grid<DimCount,T0,T1,T2,T3,T4,T5> const& g
        )
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_edge(e, g));
        return e.first.second;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_key
        key(
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_descriptor e,
            zeta_grid<DimCount,T0,T1,T2,T3,T4,T5> const& g
        )
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_edge(e, g));
        return e.second;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_descriptor
        vertex(
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertices_size_type i,
            zeta_grid<DimCount,T0,T1,T2,T3,T4,T5> const& g
        )
    {
        if (i < num_vertices(g))
        {
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_descriptor result;
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertices_size_type n;

            for (
                typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::degree_size_type d = 0;
                d < DimCount::value;
                ++d
            )
            {
                n = g.length(d);
                result[d] = i % n;
                i /= n;
            }

            return result;
        }
        else
        {
            return zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::null_vertex();
        }
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    void zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::_post_construct()
    {
        ++this->_vertex_count;

        static vertices_size_type const z = ::boost::initialized_value;

        degree_size_type d;

        for (d = 0; d < dimension_count::value; ++d)
        {
            this->_vertex_count *= this->length(d);
        }

        static edge_key_iterator const ek_itr_begin = type::edge_keys().first;

        ::std::vector<vertices_size_type> vertex_index_keys;
        ::std::vector<edges_size_type> edge_index_offset_values;
        ::std::vector<degree_size_type> vertex_category_values;
        ::std::vector<degree_size_type> out_edge_key_indices;
        ::std::vector<degree_size_type> in_edge_key_indices;
        _edge_key_set_t edge_key_set;
        edge_key e_k;
        edges_size_type a = ::boost::initialized_value;
        degree_size_type c, current_category;

        vertex_index_keys.push_back(z);
        edge_index_offset_values.push_back(a);
        vertex_category_values.push_back(0);

        for (vertices_size_type vi = z; vi < this->_vertex_count; ++vi)
        {
            out_edge_key_indices.clear();
            in_edge_key_indices.clear();
            edge_key_set.clear();

            for (d = 0; d < _edge_key_count::value; ++d)
            {
                e_k = *(ek_itr_begin + d);

                if (
                    ::odds_and_ends::graph::_detail::is_valid_vertex(
                        this->next(vertex(vi, *this), e_k),
                        *this
                    )
                )
                {
                    out_edge_key_indices.push_back(d);
                    edge_key_set.insert(e_k);
                }

                if (
                    ::odds_and_ends::graph::_detail::is_valid_vertex(
                        this->previous(vertex(vi, *this), e_k),
                        *this
                    )
                )
                {
                    in_edge_key_indices.push_back(d);
                }
            }

            for (c = 0; c < _vertex_category_count::value; ++c)
            {
                if (this->_vertex_category_to_out_edge_key_indices[c].empty())
                {
                    BOOST_ASSERT(this->_vertex_category_to_in_edge_key_indices[c].empty());
                    BOOST_ASSERT(this->_vertex_category_to_edge_key_set[c].empty());
                    this->_vertex_category_to_out_edge_key_indices[c] = out_edge_key_indices;
                    this->_vertex_category_to_in_edge_key_indices[c] = in_edge_key_indices;
                    this->_vertex_category_to_edge_key_set[c] = edge_key_set;
                    current_category = c;
                    break;
                }
                else
                {
                    BOOST_ASSERT(!this->_vertex_category_to_in_edge_key_indices[c].empty());
                    BOOST_ASSERT(!this->_vertex_category_to_edge_key_set[c].empty());
                }

                if (
                    ::std::equal(
                        out_edge_key_indices.begin(),
                        out_edge_key_indices.end(),
                        this->_vertex_category_to_out_edge_key_indices[c].begin(),
                        this->_vertex_category_to_out_edge_key_indices[c].end()
                    )
                )
                {
                    BOOST_ASSERT(::std::equal(
                        in_edge_key_indices.begin(),
                        in_edge_key_indices.end(),
                        this->_vertex_category_to_in_edge_key_indices[c].begin(),
                        this->_vertex_category_to_in_edge_key_indices[c].end()
                    ));
                    current_category = c;
                    break;
                }
                else
                {
                    BOOST_ASSERT(!::std::equal(
                        in_edge_key_indices.begin(),
                        in_edge_key_indices.end(),
                        this->_vertex_category_to_in_edge_key_indices[c].begin(),
                        this->_vertex_category_to_in_edge_key_indices[c].end()
                    ));
                }
            }

            BOOST_ASSERT_MSG(c < _vertex_category_count::value, "Vertex category out of bounds!");

            if (vertex_category_values.back() != current_category)
            {
                vertex_index_keys.push_back(vi);
                edge_index_offset_values.push_back(a);
                vertex_category_values.push_back(current_category);
            }

            a += out_edge_key_indices.size();
        }

        this->_edge_count = a;
        vertex_index_keys.push_back(this->_vertex_count);
        this->_vertex_index_to_edge_index_offset = _vertex_index_to_category_t(
            vertex_index_keys.cbegin(),
            vertex_index_keys.cend(),
            edge_index_offset_values.cbegin(),
            edge_index_offset_values.cend()
        );
        this->_vertex_index_to_category = _vertex_index_to_category_t(
            vertex_index_keys.cbegin(),
            vertex_index_keys.cend(),
            vertex_category_values.cbegin(),
            vertex_category_values.cend()
        );
        edge_index_offset_values.push_back(a);
        vertex_index_keys.pop_back();
        this->_edge_index_to_source_vertex_index = _edge_index_to_vertex_index_t(
            edge_index_offset_values.cbegin(),
            edge_index_offset_values.cend(),
            vertex_index_keys.cbegin(),
            vertex_index_keys.cend()
        );
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::degree_size_type
        degree(
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_descriptor v,
            zeta_grid<DimCount,T0,T1,T2,T3,T4,T5> const& g
        )
    {
        return out_degree(v, g) << 1;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::zeta_grid(
        vertex_descriptor dimension_lengths,
        bool wraparound_all
    ) : _vertex_index_to_edge_index_offset(),
        _edge_index_to_source_vertex_index(),
        _vertex_index_to_category(),
        _vertex_category_to_out_edge_key_indices(),
        _vertex_category_to_in_edge_key_indices(),
        _vertex_category_to_edge_key_set(),
        _dimension_lengths(dimension_lengths),
        _wraparound_mask(),
        _edge_count(::boost::initialized_value),
        _vertex_count(::boost::initialized_value)
    {
        if (wraparound_all)
        {
            this->_wraparound_mask.set();
        }

        this->_post_construct();
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::zeta_grid(
        vertex_descriptor dimension_lengths,
        ::std::bitset<dimension_count::value> wraparound
    ) : _vertex_index_to_edge_index_offset(),
        _edge_index_to_source_vertex_index(),
        _vertex_index_to_category(),
        _vertex_category_to_out_edge_key_indices(),
        _vertex_category_to_in_edge_key_indices(),
        _vertex_category_to_edge_key_set(),
        _dimension_lengths(dimension_lengths),
        _wraparound_mask(wraparound),
        _edge_count(::boost::initialized_value),
        _vertex_count(::boost::initialized_value)
    {
        this->_post_construct();
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertices_size_type
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::operator[](vertex_descriptor v) const
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_vertex(v, *this));

        vertices_size_type result = ::boost::initialized_value;
        vertices_size_type factor = ::boost::initialized_value;

        ++factor;

        for (degree_size_type d = 0; d < dimension_count::value; ++d)
        {
            result += v[d] * factor;
            factor *= this->length(d);
        }

        return result;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edges_size_type
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::operator[](edge_descriptor e) const
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_edge(e, *this));

        vertices_size_type const source_index = (*this)[e.first.first];
        typename _vertex_index_to_edge_index_offset_t::const_iterator offset_itr = (
            this->_vertex_index_to_edge_index_offset.find(source_index)
        );
        _edge_key_set_t const& edge_key_set = (
            this->_vertex_category_to_edge_key_set[
                this->_vertex_index_to_category[source_index]
            ]
        );

        return (
            source_index - offset_itr->first.lower()
        ) * edge_key_set.size() + offset_itr->second + (
            edge_key_set.find(e.second) - edge_key_set.cbegin()
        );
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_descriptor
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::next(vertex_descriptor v, edge_key key) const
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_vertex(v, *this));

        static vertices_size_type const z = ::boost::initialized_value;
        vertices_size_type one = z;
        ++one;

        for (degree_size_type d = 0; d < dimension_count::value; ++d)
        {
            switch (key[d])
            {
                case 1:
                {
                    if (v[d] + one < this->length(d))
                    {
                        ++v[d];
                    }
                    else if (this->wrapped(d))
                    {
                        v[d] = z;
                    }
                    else
                    {
                        return type::null_vertex();
                    }

                    break;
                }

                case -1:
                {
                    if (v[d])
                    {
                        --v[d];
                    }
                    else if (this->wrapped(d))
                    {
                        v[d] = this->length(d);
                        --v[d];
                    }
                    else
                    {
                        return type::null_vertex();
                    }

                    break;
                }
            }
        }

        return v;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_descriptor
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::previous(vertex_descriptor v, edge_key key) const
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_vertex(v, *this));

        static vertices_size_type const z = ::boost::initialized_value;
        vertices_size_type one = z;
        ++one;

        for (degree_size_type d = 0; d < dimension_count::value; ++d)
        {
            switch (key[d])
            {
                case 1:
                {
                    if (v[d])
                    {
                        --v[d];
                    }
                    else if (this->wrapped(d))
                    {
                        v[d] = this->length(d);
                        --v[d];
                    }
                    else
                    {
                        return type::null_vertex();
                    }

                    break;
                }

                case -1:
                {
                    if (v[d] + one < this->length(d))
                    {
                        ++v[d];
                    }
                    else if (this->wrapped(d))
                    {
                        v[d] = z;
                    }
                    else
                    {
                        return type::null_vertex();
                    }

                    break;
                }
            }
        }

        return v;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_descriptor
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::next(
            vertex_descriptor v,
            edge_key key,
            _index_difference i_d
        ) const
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_vertex(v, *this));

        static vertices_size_type const z = ::boost::initialized_value;
        static _index_difference const z_d = ::boost::initialized_value;

        if (i_d < z_d)
        {
            for (degree_size_type d = 0; d < dimension_count::value; ++d)
            {
                switch (key[d])
                {
                    case 1:
                    {
                        if (-i_d <= v[d])
                        {
                            v[d] += i_d;
                        }
                        else if (this->wrapped(d))
                        {
                            v[d] += this->length(d);
                            v[d] -= -i_d % this->length(d);
                            v[d] %= this->length(d);
                        }
                        else
                        {
                            return type::null_vertex();
                        }

                        break;
                    }

                    case -1:
                    {
                        if (v[d] - i_d < this->length(d))
                        {
                            v[d] -= i_d;
                        }
                        else if (this->wrapped(d))
                        {
                            v[d] -= i_d;
                            v[d] %= this->length(d);
                        }
                        else
                        {
                            return type::null_vertex();
                        }

                        break;
                    }
                }
            }
        }
        else if (i_d)
        {
            for (degree_size_type d = 0; d < dimension_count::value; ++d)
            {
                switch (key[d])
                {
                    case 1:
                    {
                        if (v[d] + i_d < this->length(d))
                        {
                            v[d] += i_d;
                        }
                        else if (this->wrapped(d))
                        {
                            v[d] += i_d;
                            v[d] %= this->length(d);
                        }
                        else
                        {
                            return type::null_vertex();
                        }

                        break;
                    }

                    case -1:
                    {
                        if (i_d <= v[d])
                        {
                            v[d] -= i_d;
                        }
                        else if (this->wrapped(d))
                        {
                            v[d] += this->length(d);
                            v[d] -= i_d % this->length(d);
                            v[d] %= this->length(d);
                        }
                        else
                        {
                            return type::null_vertex();
                        }

                        break;
                    }
                }
            }
        }

        return v;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_descriptor
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::previous(
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_descriptor v,
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_key key,
            _index_difference i_d
        ) const
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_vertex(v, *this));

        static vertices_size_type const z = ::boost::initialized_value;
        static _index_difference const z_d = ::boost::initialized_value;

        if (i_d < z_d)
        {
            for (degree_size_type d = 0; d < dimension_count::value; ++d)
            {
                switch (key[d])
                {
                    case 1:
                    {
                        if (v[d] - i_d < this->length(d))
                        {
                            v[d] -= i_d;
                        }
                        else if (this->wrapped(d))
                        {
                            v[d] -= i_d;
                            v[d] %= this->length(d);
                        }
                        else
                        {
                            return type::null_vertex();
                        }

                        break;
                    }

                    case -1:
                    {
                        if (-i_d <= v[d])
                        {
                            v[d] += i_d;
                        }
                        else if (this->wrapped(d))
                        {
                            v[d] += this->length(d);
                            v[d] -= -i_d % this->length(d);
                            v[d] %= this->length(d);
                        }
                        else
                        {
                            return type::null_vertex();
                        }

                        break;
                    }
                }
            }
        }
        else if (i_d)
        {
            for (degree_size_type d = 0; d < dimension_count::value; ++d)
            {
                switch (key[d])
                {
                    case 1:
                    {
                        if (i_d <= v[d])
                        {
                            v[d] -= i_d;
                        }
                        else if (this->wrapped(d))
                        {
                            v[d] += this->length(d);
                            v[d] -= i_d % this->length(d);
                            v[d] %= this->length(d);
                        }
                        else
                        {
                            return type::null_vertex();
                        }

                        break;
                    }

                    case -1:
                    {
                        if (v[d] + i_d < this->length(d))
                        {
                            v[d] += i_d;
                        }
                        else if (this->wrapped(d))
                        {
                            v[d] += i_d;
                            v[d] %= this->length(d);
                        }
                        else
                        {
                            return type::null_vertex();
                        }

                        break;
                    }
                }
            }
        }

        return v;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator::vertex_iterator() :
        _g(nullptr),
        _current_index(::boost::initialized_value),
        _current_vertex(type::null_vertex())
    {
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    template <bool IsOut>
    inline zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::_ext_edge_iterator<IsOut>::_ext_edge_iterator() :
        _g(nullptr), _current_index(), _current_edge(type::null_edge())
    {
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator::reference
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator::operator*() const
    {
        return this->_current_vertex;
    }
}}  // namespace odds_and_ends::graph

#include <memory>

namespace odds_and_ends { namespace graph {

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator::vertex_iterator(
        type const& g,
        vertices_size_type index
    ) : _g(::std::pointer_traits<_g_c_ptr>::pointer_to(g)),
        _current_index(index),
        _current_vertex(vertex(index, g))
    {
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    template <bool IsOut>
    inline zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::_ext_edge_iterator<IsOut>::_ext_edge_iterator(
        type const& g,
        vertex_descriptor v,
        degree_size_type index
    ) : _g(::std::pointer_traits<_g_c_ptr>::pointer_to(g)), _current_index(index), _current_edge()
    {
        if (IsOut)
        {
            this->_current_edge.first.first = v;
        }
        else
        {
            this->_current_edge.first.second = v;
        }

        this->_post_operation();
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator::pointer
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator::operator->() const
    {
        return ::std::pointer_traits<pointer>::pointer_to(this->_current_vertex);
    }

    template <
        typename DC,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::edge_key_iterator::pointer
        zeta_grid<DC,T0,T1,T2,T3,T4,T5>::edge_key_iterator::operator->() const
    {
        return ::std::pointer_traits<pointer>::pointer_to(this->_current_key);
    }

    template <
        typename DC,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    template <bool IsOut>
    inline typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::template _ext_edge_iterator<IsOut>::pointer
        zeta_grid<DC,T0,T1,T2,T3,T4,T5>::_ext_edge_iterator<IsOut>::operator->() const
    {
        return ::std::pointer_traits<pointer>::pointer_to(this->_current_edge);
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator&
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator::operator++()
    {
        this->_current_vertex = vertex((++this->_current_index), *this->_g);
        return *this;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator::operator++(int)
    {
        typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator itr(*this);
        ++(*this);
        return itr;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator&
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator::operator--()
    {
        this->_current_vertex = vertex((--this->_current_index), *this->_g);
        return *this;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator::operator--(int)
    {
        typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator itr(*this);
        --(*this);
        return itr;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator&
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator::operator+=(difference_type const& d)
    {
        this->_current_vertex = vertex((this->_current_index += d), *this->_g);
        return *this;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator::operator+(
            difference_type const& d
        ) const
    {
        typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator itr(*this);
        itr += d;
        return itr;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator&
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator::operator-=(difference_type const& d)
    {
        this->_current_vertex = vertex((this->_current_index -= d), *this->_g);
        return *this;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator::operator-(
            difference_type const& d
        ) const
    {
        typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator itr(*this);
        itr -= d;
        return itr;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline ::std::pair<
        typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator,
        typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator
    >
        vertices(zeta_grid<DimCount,T0,T1,T2,T3,T4,T5> const& g)
    {
        return ::std::make_pair(
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator(
                g,
                ::boost::initialized_value
            ),
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_iterator(g, num_vertices(g))
        );
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline ::std::pair<
        typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_iterator,
        typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_iterator
    >
        edges(zeta_grid<DimCount,T0,T1,T2,T3,T4,T5> const& g)
    {
        return ::std::make_pair(
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_iterator(
                g,
                ::boost::initialized_value
            ),
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_iterator(g, num_edges(g))
        );
    }

    template <
        typename DC,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline ::std::pair<
        typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::out_edge_iterator,
        typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::out_edge_iterator
    >
        out_edges(
            typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::vertex_descriptor v,
            zeta_grid<DC,T0,T1,T2,T3,T4,T5> const& g
        )
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_vertex(v, g));
        return ::std::make_pair(
            typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::out_edge_iterator(g, v, 0),
            typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::out_edge_iterator(g, v, out_degree(v, g))
        );
    }

    template <
        typename DC,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline ::std::pair<
        typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::in_edge_iterator,
        typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::in_edge_iterator
    >
        in_edges(
            typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::vertex_descriptor v,
            zeta_grid<DC,T0,T1,T2,T3,T4,T5> const& g
        )
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_vertex(v, g));
        return ::std::make_pair(
            typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::in_edge_iterator(g, v, 0),
            typename zeta_grid<DC,T0,T1,T2,T3,T4,T5>::in_edge_iterator(g, v, in_degree(v, g))
        );
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline ::std::pair<
        typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::adjacency_iterator,
        typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::adjacency_iterator
    >
        adjacent_vertices(
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_descriptor v,
            zeta_grid<DimCount,T0,T1,T2,T3,T4,T5> const& g
        )
    {
        ::std::pair<
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::out_edge_iterator,
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::out_edge_iterator
        > p = out_edges(v, g);
        return ::std::make_pair(
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::adjacency_iterator(p.first, &g),
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::adjacency_iterator(p.second, &g)
        );
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline ::std::pair<
        typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::inv_adjacency_iterator,
        typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::inv_adjacency_iterator
    >
        inv_adjacent_vertices(
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_descriptor v,
            zeta_grid<DimCount,T0,T1,T2,T3,T4,T5> const& g
        )
    {
        ::std::pair<
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::in_edge_iterator,
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::in_edge_iterator
        > p = in_edges(v, g);
        return ::std::make_pair(
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::inv_adjacency_iterator(p.first, &g),
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::inv_adjacency_iterator(p.second, &g)
        );
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_descriptor
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::_edge_at(edges_size_type i_e) const
    {
        if (i_e < this->_edge_count)
        {
            vertices_size_type const i_v_min = this->_edge_index_to_source_vertex_index[i_e];
            edges_size_type const i_e_min = this->_vertex_index_to_edge_index_offset[i_v_min];
            degree_size_type const d_o = this->_vertex_category_to_out_edge_key_indices[
                this->_vertex_index_to_category[i_v_min]
            ].size();
            out_edge_iterator const itr(
                *this,
                vertex(((i_e - i_e_min) / d_o) + i_v_min, *this),
                degree_size_type((i_e - i_e_min) % d_o)
            );
            edge_descriptor const result = *itr;

            return result;
        }
        else
        {
            return type::null_edge();
        }
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    ::std::pair<typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_descriptor,bool>
        zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::_edge_at(
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_descriptor u,
            typename zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::vertex_descriptor v
        ) const
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_vertex(u, *this));
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_vertex(v, *this));

        // TODO:
        // Fix.
        ::std::pair<edge_descriptor,bool> result;
        vertices_size_type one = ::boost::initialized_value;
        ++one;

        for (degree_size_type d = 0; d < dimension_count::value; ++d)
        {
            result.first.second[d] = short(v[d] - u[d]);

            if (this->wrapped(d))
            {
                if (!u[d] && (v[d] + one == this->length(d)))
                {
                    result.first.second[d] = -1;
                }
                else if (!v[d] && (u[d] + one == this->length(d)))
                {
                    result.first.second[d] = 1;
                }
            }
        }

        _edge_key_set_t const& k2d = (
            this->_vertex_category_to_edge_key_set[
                this->_vertex_index_to_category[(*this)[u]]
            ]
        );

        if (k2d.cend() != k2d.find(result.first.second))
        {
            result.first.first.first = u;
            result.first.first.second = v;
            result.second = true;
        }
        else
        {
            result.first = type::null_edge();
            result.second = false;
        }

        return result;
    }
}}  // namespace odds_and_ends::graph

#include <boost/property_map/property_map.hpp>

namespace odds_and_ends { namespace graph { namespace _detail {

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    struct zeta_grid_reverse_edge_map
    {
        typedef typename ::odds_and_ends::graph
        ::zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::edge_descriptor key_type;
        typedef key_type value_type;
        typedef value_type reference;
        typedef ::boost::readable_property_map_tag category;

        reference operator[](key_type const& key) const;
    };

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline typename zeta_grid_reverse_edge_map<DimCount,T0,T1,T2,T3,T4,T5>::reference
        zeta_grid_reverse_edge_map<DimCount,T0,T1,T2,T3,T4,T5>::operator[](key_type const& k) const
    {
        value_type result;

        result.first.first = k.first.second;
        result.first.second = k.first.first;
        result.second = zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::_reverse_key(k.second);
        return result;
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    inline typename zeta_grid_reverse_edge_map<DimCount,T0,T1,T2,T3,T4,T5>::reference
        get(
            zeta_grid_reverse_edge_map<DimCount,T0,T1,T2,T3,T4,T5> const& m,
            typename zeta_grid_reverse_edge_map<DimCount,T0,T1,T2,T3,T4,T5>::key_type key
        )
    {
        return m[key];
    }
}}}  // namespace odds_and_ends::graph::_detail

#include <boost/graph/properties.hpp>

namespace boost {

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    struct property_map<
        ::odds_and_ends::graph::zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>,
        ::boost::edge_reverse_t
    >
    {
        typedef ::odds_and_ends::graph::_detail
        ::zeta_grid_reverse_edge_map<DimCount,T0,T1,T2,T3,T4,T5> type;
        typedef type const_type;
    };

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    ::odds_and_ends::graph::_detail::zeta_grid_reverse_edge_map<DimCount,T0,T1,T2,T3,T4,T5>
        get(
            ::boost::edge_reverse_t,
            ::odds_and_ends::graph::zeta_grid<DimCount,T0,T1,T2,T3,T4,T5> const& g
        )
    {
        return (
            ::odds_and_ends::graph::_detail
            ::zeta_grid_reverse_edge_map<DimCount,T0,T1,T2,T3,T4,T5>()
        );
    }
}  // namespace boost

#include <odds_and_ends/graph/_detail/index_map.hpp>

namespace boost {

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    struct property_map<
        ::odds_and_ends::graph::zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>,
        ::boost::vertex_index_t
    >
    {
        typedef ::odds_and_ends::graph::_detail::index_map<
            ::odds_and_ends::graph::zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>,
            typename ::odds_and_ends::graph::zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::_ptr_xform,
            true
        > type;
        typedef type const_type;
    };

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    ::odds_and_ends::graph::_detail::index_map<
        ::odds_and_ends::graph::zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>,
        typename ::odds_and_ends::graph::zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::_ptr_xform,
        true
    >
        get(
            ::boost::vertex_index_t,
            ::odds_and_ends::graph::zeta_grid<DimCount,T0,T1,T2,T3,T4,T5> const& g
        )
    {
        return ::odds_and_ends::graph::_detail::index_map<
            ::odds_and_ends::graph::zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>,
            typename ::odds_and_ends::graph::zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::_ptr_xform,
            true
        >(g);
    }

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    struct property_map<
        ::odds_and_ends::graph::zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>,
        ::boost::edge_index_t
    >
    {
        typedef ::odds_and_ends::graph::_detail::index_map<
            ::odds_and_ends::graph::zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>,
            typename ::odds_and_ends::graph::zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::_ptr_xform,
            false
        > type;
        typedef type const_type;
    };

    template <
        typename DimCount,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5
    >
    ::odds_and_ends::graph::_detail::index_map<
        ::odds_and_ends::graph::zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>,
        typename ::odds_and_ends::graph::zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::_ptr_xform,
        false
    >
        get(
            ::boost::edge_index_t,
            ::odds_and_ends::graph::zeta_grid<DimCount,T0,T1,T2,T3,T4,T5> const& g
        )
    {
        return ::odds_and_ends::graph::_detail::index_map<
            ::odds_and_ends::graph::zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>,
            typename ::odds_and_ends::graph::zeta_grid<DimCount,T0,T1,T2,T3,T4,T5>::_ptr_xform,
            false
        >(g);
    }
}  // namespace boost

#endif  // ODDS_AND_ENDS__GRAPH__ZETA_GRID_HPP

