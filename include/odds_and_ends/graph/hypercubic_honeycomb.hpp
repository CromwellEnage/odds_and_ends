// Copyright (C) 2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__GRAPH__HYPERCUBIC_HONEYCOMB_HPP
#define ODDS_AND_ENDS__GRAPH__HYPERCUBIC_HONEYCOMB_HPP

#include <cstddef>
#include <type_traits>
#include <utility>
#include <array>
#include <bitset>
#include <iterator>
#include <odds_and_ends/graph/parameter/template.hpp>
#include <odds_and_ends/node/parameter/template.hpp>
#include <odds_and_ends/static_introspection/concept/is_math_integral_type.hpp>
#include <odds_and_ends/static_introspection/concept/is_mpl_integral_constant.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_iterator.hpp>
#include <boost/parameter/optional.hpp>
#include <boost/parameter/parameters.hpp>
#include <boost/parameter/value_type.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/quote.hpp>
#include <boost/mpl/assert.hpp>

namespace odds_and_ends { namespace graph {

    template <
        typename DimCount,
        typename T0 = ::boost::parameter::void_,
        typename T1 = ::boost::parameter::void_,
        typename T2 = ::boost::parameter::void_,
        typename T3 = ::boost::parameter::void_
    >
    class hypercubic_honeycomb
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
            >
        >::template bind<T0,T1,T2,T3>::type _template_args;
        typedef typename ::boost::parameter::value_type<
            _template_args,
            ::odds_and_ends::graph::parameter::tag::_index_difference,
            ::std::ptrdiff_t
        >::type _index_difference;

    public:
        // If only template specializations could be friends instead...
        typedef typename ::boost::parameter::value_type<
            _template_args,
            ::odds_and_ends::node::parameter::tag::_pointer_transform,
            ::boost::mpl::quote1< ::std::add_pointer>
        >::type _ptr_xform;

    public:
        typedef ::odds_and_ends::graph::hypercubic_honeycomb<DimCount,T0,T1,T2,T3> type;
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
        typedef ::std::pair<degree_size_type,bool> edge_key;
        typedef
        ::std::pair< ::std::pair<vertex_descriptor,vertex_descriptor>,edge_key> edge_descriptor;
        typedef ::boost::bidirectional_tag directed_category;
        typedef ::boost::mpl::false_ edge_parallel_category;

        struct traversal_category :
            ::boost::bidirectional_graph_tag,
            ::boost::adjacency_graph_tag,
            ::boost::vertex_list_graph_tag,
            ::boost::edge_list_graph_tag,
            ::boost::adjacency_matrix_tag
        {
        };

    private:
        typedef typename ::boost::mpl::apply_wrap1<_ptr_xform,type const>::type _g_c_ptr;

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

        class edge_iterator
        {
            _g_c_ptr _g;
            edges_size_type _current_index;
            edge_descriptor _current_edge;

        public:
            typedef edge_descriptor const value_type;
            typedef value_type& reference;
            typedef typename ::boost::mpl::apply_wrap1<_ptr_xform,value_type>::type pointer;
            typedef _index_difference difference_type;
            typedef ::std::random_access_iterator_tag iterator_category;

            edge_iterator();
            edge_iterator(type const& g, edges_size_type index);
            reference operator*() const;
            pointer operator->() const;
            edge_iterator& operator++();
            edge_iterator operator++(int);
            edge_iterator& operator--();
            edge_iterator operator--(int);
            edge_iterator& operator+=(difference_type const& d);
            edge_iterator operator+(difference_type const& d) const;
            edge_iterator& operator-=(difference_type const& d);
            edge_iterator operator-(difference_type const& d) const;

        private:
            friend inline bool operator==(edge_iterator const& lhs, edge_iterator const& rhs)
            {
                return lhs._current_index == rhs._current_index;
            }

            friend inline bool operator!=(edge_iterator const& lhs, edge_iterator const& rhs)
            {
                return lhs._current_index != rhs._current_index;
            }

            friend inline bool operator<(edge_iterator const& lhs, edge_iterator const& rhs)
            {
                return lhs._current_index < rhs._current_index;
            }

            friend inline bool operator<=(edge_iterator const& lhs, edge_iterator const& rhs)
            {
                return lhs._current_index <= rhs._current_index;
            }

            friend inline bool operator>(edge_iterator const& lhs, edge_iterator const& rhs)
            {
                return lhs._current_index > rhs._current_index;
            }

            friend inline bool operator>=(edge_iterator const& lhs, edge_iterator const& rhs)
            {
                return lhs._current_index >= rhs._current_index;
            }

            friend inline difference_type
                operator-(edge_iterator const& lhs, edge_iterator const& rhs)
            {
                difference_type d = static_cast<difference_type>(lhs._current_index);
                d -= rhs._current_index;
                return d;
            }
        };

        class edge_key_iterator
        {
            edge_key _current_key;
            degree_size_type _current_index;

        public:
            typedef edge_key const value_type;
            typedef value_type& reference;
            typedef typename ::boost::mpl::apply_wrap1<_ptr_xform,value_type>::type pointer;
            typedef typename ::std::make_signed<degree_size_type>::type difference_type;
            typedef ::std::random_access_iterator_tag iterator_category;

            explicit edge_key_iterator(degree_size_type index = dimension_count::value);
            degree_size_type const& index() const;
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

        static vertex_descriptor null_vertex();
        static edge_descriptor null_edge();
        static ::std::pair<edge_key_iterator,edge_key_iterator> edge_keys();

    private:
        template <bool IsOut>
        class _adj_edge_iterator
        {
            _g_c_ptr _g;
            edge_key_iterator _current_itr;
            edge_descriptor _current_edge;

        public:
            typedef edge_descriptor const value_type;
            typedef value_type& reference;
            typedef typename ::boost::mpl::apply_wrap1<_ptr_xform,value_type>::type pointer;
            typedef typename edge_key_iterator::difference_type difference_type;
            typedef ::std::forward_iterator_tag iterator_category;

            _adj_edge_iterator();
            _adj_edge_iterator(type const& g, vertex_descriptor v, degree_size_type index);
            reference operator*() const;
            pointer operator->() const;
            _adj_edge_iterator& operator++();
            _adj_edge_iterator operator++(int);

        private:
            void _post_operation();

            friend inline bool
                operator==(_adj_edge_iterator const& lhs, _adj_edge_iterator const& rhs)
            {
                return lhs._current_itr == rhs._current_itr;
            }

            friend inline bool
                operator!=(_adj_edge_iterator const& lhs, _adj_edge_iterator const& rhs)
            {
                return !(lhs._current_itr == rhs._current_itr);
            }
        };

    public:
        typedef _adj_edge_iterator<true> out_edge_iterator;
        typedef _adj_edge_iterator<false> in_edge_iterator;
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

    private:
        vertex_descriptor _dimension_lengths;
        ::std::bitset<dimension_count::value> _wraparound;
        ::std::array<edges_size_type,dimension_count::value> _edge_count;
        edges_size_type _total_edge_count;
        vertices_size_type _vertex_count;

    public:
        hypercubic_honeycomb(vertex_descriptor dimension_lengths, bool wraparound_all = false);
        hypercubic_honeycomb(
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

        friend inline vertices_size_type num_vertices(type const& g)
        {
            return g._vertex_count;
        }

        friend inline edges_size_type num_edges(type const& g)
        {
            return g._total_edge_count;
        }

        friend inline edge_descriptor edge(edges_size_type i, type const& g)
        {
            return g._edge_at(i);
        }
    };
}}  // namespace odds_and_ends::graph

#include <boost/utility/value_init.hpp>

namespace odds_and_ends { namespace graph { namespace _detail {

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    bool
        is_valid_vertex(
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_descriptor v,
            hypercubic_honeycomb<DC,T0,T1,T2,T3> const& g
        )
    {
        static typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertices_size_type const z = (
            ::boost::initialized_value
        );

        for (
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::degree_size_type d = 0;
            d < DC::value;
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

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline bool
        is_valid_edge(
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_descriptor e,
            hypercubic_honeycomb<DC,T0,T1,T2,T3> const& g
        )
    {
        return (
            ::odds_and_ends::graph::_detail::is_valid_vertex(e.first.first, g) &&
            ::odds_and_ends::graph::_detail::is_valid_vertex(e.first.second, g) &&
            (e.second.first < DC::value)
        );
    }
}}}  // namespace odds_and_ends::graph::_detail

#include <boost/assert.hpp>

namespace odds_and_ends { namespace graph {

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_descriptor
        source(
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_descriptor e,
            hypercubic_honeycomb<DC,T0,T1,T2,T3> const& g
        )
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_edge(e, g));
        return e.first.first;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_descriptor
        target(
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_descriptor e,
            hypercubic_honeycomb<DC,T0,T1,T2,T3> const& g
        )
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_edge(e, g));
        return e.first.second;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key
        key(
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_descriptor e,
            hypercubic_honeycomb<DC,T0,T1,T2,T3> const& g
        )
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_edge(e, g));
        return e.second;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_descriptor
        vertex(
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertices_size_type i,
            hypercubic_honeycomb<DC,T0,T1,T2,T3> const& g
        )
    {
        if (i < num_vertices(g))
        {
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_descriptor result;
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertices_size_type n;

            for (
                typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::degree_size_type d = 0;
                d < DC::value;
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
            return hypercubic_honeycomb<DC,T0,T1,T2,T3>::null_vertex();
        }
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    ::std::pair<
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_descriptor,
        bool
    >
        edge(
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_descriptor u,
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_descriptor v,
            hypercubic_honeycomb<DC,T0,T1,T2,T3> const& g
        )
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_vertex(u, g));
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_vertex(v, g));

        ::std::pair<
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_descriptor,
            bool
        > result;
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertices_size_type one = (
            ::boost::initialized_value
        );
        bool flag = true;

        result.first.first.first = u;
        result.first.first.second = v;
        result.second = false;
        ++one;

        for (
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::degree_size_type d = 0;
            d < DC::value;
            ++d
        )
        {
            if (!u[d] && (v[d] + one == g.length(d)))
            {
                if (g.wrapped(d))
                {
                    if (result.second)
                    {
                        result.second = false;
                        return result;
                    }
                    else if (flag)
                    {
                        result.first.second.first = d;
                        result.first.second.second = false;
                        result.second = true;
                    }
                }
                else
                {
                    result.second = false;
                    return result;
                }
            }
            else if (!v[d] && (u[d] + one == g.length(d)))
            {
                if (g.wrapped(d))
                {
                    if (result.second)
                    {
                        result.second = false;
                        return result;
                    }
                    else if (flag)
                    {
                        result.first.second.first = d;
                        result.first.second.second = true;
                        result.second = true;
                    }
                }
                else
                {
                    result.second = false;
                    return result;
                }
            }
            else if ((u[d] + one < v[d]) || (v[d] + one < u[d]))
            {
                result.second = false;
                return result;
            }
            else if (u[d] + one == v[d])
            {
                if (result.second)
                {
                    result.second = false;
                    return result;
                }
                else if (flag)
                {
                    result.first.second.first = d;
                    result.first.second.second = true;
                    result.second = true;
                }
            }
            else if (v[d] + one == u[d])
            {
                if (result.second)
                {
                    result.second = false;
                    return result;
                }
                else if (flag)
                {
                    result.first.second.first = d;
                    result.first.second.second = false;
                    result.second = true;
                }
            }
        }

        return result;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertices_size_type const&
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::length(degree_size_type const& d) const
    {
        BOOST_ASSERT(d < dimension_count::value);
        return this->_dimension_lengths[d];
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline bool hypercubic_honeycomb<DC,T0,T1,T2,T3>::wrapped(degree_size_type const& d) const
    {
        BOOST_ASSERT(d < dimension_count::value);
        return this->_wraparound[d];
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    void hypercubic_honeycomb<DC,T0,T1,T2,T3>::_post_construct()
    {
        ++this->_vertex_count;

        for (degree_size_type d = 0; d < dimension_count::value; ++d)
        {
            this->_vertex_count *= this->length(d);
        }

        for (degree_size_type d = 0; d < dimension_count::value; ++d)
        {
            if (this->wrapped(d))
            {
                this->_edge_count[d] = this->_vertex_count << 1;
            }
            else
            {
                this->_edge_count[d] = (
                    this->_vertex_count - (this->_vertex_count / this->length(d))
                ) << 1;
            }

            this->_total_edge_count += this->_edge_count[d];
        }
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_descriptor
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::_edge_at(edges_size_type i) const
    {
        if (i < this->_total_edge_count)
        {
            degree_size_type d0 = 0;
            edges_size_type n = this->_edge_count[0];

            for (; n <= i; n = this->_edge_count[++d0])
            {
                i -= n;
            }

            edge_descriptor result;

            result.second.first = d0;
            result.second.second = !(i / (this->_edge_count[d0] >> 1));

            if (this->wrapped(d0))
            {
                if (result.second.second)
                {
                    result.first.first = vertex(i % this->_vertex_count, *this);
                }
                else
                {
                    result.first.second = vertex(i % this->_vertex_count, *this);
                }
            }
            else  // if (!this->wrapped(d))
            {
                edges_size_type e = i % this->_edge_count[d0];
                vertices_size_type v = ::boost::initialized_value;

                ++v;

                for (degree_size_type d1 = 0; d1 < dimension_count::value; ++d1)
                {
                    n = this->length(d1);

                    if (d1 == d0)
                    {
                        --n;
                    }

                    if (result.second.second)
                    {
                        result.first.first[d1] = (e / v) % n;
                    }
                    else
                    {
                        result.first.second[d1] = (e / v) % n;
                    }

                    v *= n;
                }
            }

            if (result.second.second)
            {
                result.first.second = this->next(result.first.first, result.second);
            }
            else
            {
                result.first.first = this->previous(result.first.second, result.second);
            }

            return result;
        }
        else
        {
            return type::null_edge();
        }
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline hypercubic_honeycomb<DC,T0,T1,T2,T3>::hypercubic_honeycomb(
        vertex_descriptor dimension_lengths,
        bool wraparound_all
    ) : _dimension_lengths(dimension_lengths),
        _wraparound(),
        _edge_count(),
        _total_edge_count(::boost::initialized_value),
        _vertex_count(::boost::initialized_value)
    {
        if (wraparound_all)
        {
            this->_wraparound.set();
        }

        this->_post_construct();
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline hypercubic_honeycomb<DC,T0,T1,T2,T3>::hypercubic_honeycomb(
        vertex_descriptor dimension_lengths,
        ::std::bitset<dimension_count::value> wraparound
    ) : _dimension_lengths(dimension_lengths),
        _wraparound(wraparound),
        _edge_count(),
        _total_edge_count(::boost::initialized_value),
        _vertex_count(::boost::initialized_value)
    {
        this->_post_construct();
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertices_size_type
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::operator[](vertex_descriptor v) const
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

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edges_size_type
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::operator[](edge_descriptor e) const
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_edge(e, *this));

        edges_size_type result = ::boost::initialized_value;

        for (degree_size_type d = 0; d < e.second.first; ++d)
        {
            result += this->_edge_count[d];
        }

        if (!e.second.second)
        {
            result += this->_edge_count[e.second.first] >> 1;
        }

        if (this->wrapped(e.second.first))
        {
            result += e.second.second ? (*this)[e.first.first] : (*this)[e.first.second];
        }
        else
        {
            vertices_size_type factor = ::boost::initialized_value;
            vertices_size_type n;

            ++factor;

            if (!e.second.second)
            {
                --e.first.first[e.second.first];
            }

            for (degree_size_type d = 0; d < dimension_count::value; ++d)
            {
                result += e.first.first[d] * factor;
                n = this->length(d);

                if (d == e.second.first)
                {
                    --n;
                }

                factor *= n;
            }
        }

        return result;
    }
}}  // namespace odds_and_ends::graph

#include <limits>

namespace odds_and_ends { namespace graph {

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_descriptor
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::null_vertex()
    {
        static vertex_descriptor _null_vertex;

        for (degree_size_type i = 0; i < dimension_count::value; ++i)
        {
            _null_vertex[i] = (::std::numeric_limits<vertices_size_type>::max)();
        }

        return _null_vertex;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_descriptor
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::null_edge()
    {
        static edge_descriptor _null_edge;

        _null_edge.first.first = type::null_vertex();
        _null_edge.first.second = type::null_vertex();
        return _null_edge;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_descriptor
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::next(vertex_descriptor v, edge_key key) const
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_vertex(v, *this));

        if (key.second)
        {
            if (++v[key.first] < this->length(key.first))
            {
                return v;
            }
            else if (this->wrapped(key.first))
            {
                v[key.first] = ::boost::initialized_value;
                return v;
            }
            else
            {
                return type::null_vertex();
            }
        }
        else  // if (!key.second)
        {
            if (v[key.first])
            {
                --v[key.first];
                return v;
            }
            else if (this->wrapped(key.first))
            {
                v[key.first] = this->length(key.first);
                --v[key.first];
                return v;
            }
            else
            {
                return type::null_vertex();
            }
        }
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_descriptor
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::previous(vertex_descriptor v, edge_key key) const
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_vertex(v, *this));

        if (key.second)
        {
            if (v[key.first])
            {
                --v[key.first];
                return v;
            }
            else if (this->wrapped(key.first))
            {
                v[key.first] = this->length(key.first);
                --v[key.first];
                return v;
            }
            else
            {
                return type::null_vertex();
            }
        }
        else  // if (!key.second)
        {
            if (++v[key.first] < this->length(key.first))
            {
                return v;
            }
            else if (this->wrapped(key.first))
            {
                v[key.first] = ::boost::initialized_value;
                return v;
            }
            else
            {
                return type::null_vertex();
            }
        }
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_descriptor
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::next(
            vertex_descriptor v,
            edge_key key,
            _index_difference d
        ) const
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_vertex(v, *this));

        static _index_difference const z_d = ::boost::initialized_value;

        if (key.second)
        {
            if (d < z_d)
            {
                if (this->wrapped(key.first))
                {
                    for (; v[key.first] < -d; v[key.first] += this->length(key.first))
                    {
                    }

                    v[key.first] += d;
                    v[key.first] %= this->length(key.first);
                    return v;
                }
                else if (v[key.first] < -d)
                {
                    return type::null_vertex();
                }
                else
                {
                    v[key.first] += d;
                    return v;
                }
            }
            else  // if (z_d <= d)
            {
                v[key.first] += d;

                if (v[key.first] < this->length(key.first))
                {
                    return v;
                }
                else if (this->wrapped(key.first))
                {
                    v[key.first] %= this->length(key.first);
                    return v;
                }
                else
                {
                    return type::null_vertex();
                }
            }
        }
        else  // if (!key.second)
        {
            if (d < z_d)
            {
                v[key.first] -= d;

                if (v[key.first] < this->length(key.first))
                {
                    return v;
                }
                else if (this->wrapped(key.first))
                {
                    v[key.first] %= this->length(key.first);
                    return v;
                }
                else
                {
                    return type::null_vertex();
                }
            }
            else  // if (z_d <= d)
            {
                if (this->wrapped(key.first))
                {
                    for (; v[key.first] < d; v[key.first] += this->length(key.first))
                    {
                    }

                    v[key.first] -= d;
                    v[key.first] %= this->length(key.first);
                    return v;
                }
                else if (v[key.first] < d)
                {
                    return type::null_vertex();
                }
                else
                {
                    v[key.first] -= d;
                    return v;
                }
            }
        }
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_descriptor
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::previous(
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_descriptor v,
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key key,
            _index_difference d
        ) const
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_vertex(v, *this));

        static _index_difference const z_d = ::boost::initialized_value;

        if (key.second)
        {
            if (d < z_d)
            {
                v[key.first] -= d;

                if (v[key.first] < this->length(key.first))
                {
                    return v;
                }
                else if (this->wrapped(key.first))
                {
                    v[key.first] %= this->length(key.first);
                    return v;
                }
                else
                {
                    return type::null_vertex();
                }
            }
            else  // if (z_d <= d)
            {
                if (this->wrapped(key.first))
                {
                    for (; v[key.first] < d; v[key.first] += this->length(key.first))
                    {
                    }

                    v[key.first] -= d;
                    v[key.first] %= this->length(key.first);
                    return v;
                }
                else if (v[key.first] < d)
                {
                    return type::null_vertex();
                }
                else
                {
                    v[key.first] -= d;
                    return v;
                }
            }
        }
        else  // if (!key.second)
        {
            if (d < z_d)
            {
                if (this->wrapped(key.first))
                {
                    for (; v[key.first] < -d; v[key.first] += this->length(key.first))
                    {
                    }

                    v[key.first] += d;
                    v[key.first] %= this->length(key.first);
                    return v;
                }
                else if (v[key.first] < -d)
                {
                    return type::null_vertex();
                }
                else
                {
                    v[key.first] += d;
                    return v;
                }
            }
            else  // if (z_d <= d)
            {
                v[key.first] += d;

                if (v[key.first] < this->length(key.first))
                {
                    return v;
                }
                else if (this->wrapped(key.first))
                {
                    v[key.first] %= this->length(key.first);
                    return v;
                }
                else
                {
                    return type::null_vertex();
                }
            }
        }
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator::vertex_iterator() :
        _g(nullptr), _current_index(), _current_vertex()
    {
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator::edge_iterator() :
        _g(nullptr), _current_index(), _current_edge()
    {
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator::reference
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator::operator*() const
    {
        return this->_current_vertex;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator::reference
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator::operator*() const
    {
        return this->_current_edge;
    }
}}  // namespace odds_and_ends::graph

#include <memory>

namespace odds_and_ends { namespace graph {

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator::vertex_iterator(
        type const& g,
        vertices_size_type index
    ) : _g(::std::pointer_traits<_g_c_ptr>::pointer_to(g)),
        _current_index(index),
        _current_vertex(vertex(index, g))
    {
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator::edge_iterator(
        type const& g,
        edges_size_type index
    ) : _g(::std::pointer_traits<_g_c_ptr>::pointer_to(g)),
        _current_index(index),
        _current_edge(edge(index, g))
    {
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator::pointer
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator::operator->() const
    {
        return ::std::pointer_traits<pointer>::pointer_to(this->_current_vertex);
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator::pointer
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator::operator->() const
    {
        return ::std::pointer_traits<pointer>::pointer_to(this->_current_edge);
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator&
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator::operator++()
    {
        this->_current_vertex = vertex((++this->_current_index), *this->_g);
        return *this;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator&
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator::operator++()
    {
        this->_current_edge = edge((++this->_current_index), *this->_g);
        return *this;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator::operator++(int)
    {
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator itr(*this);
        ++(*this);
        return itr;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator::operator++(int)
    {
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator itr(*this);
        ++(*this);
        return itr;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator&
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator::operator--()
    {
        this->_current_vertex = vertex((--this->_current_index), *this->_g);
        return *this;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator&
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator::operator--()
    {
        this->_current_edge = edge((--this->_current_index), *this->_g);
        return *this;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator::operator--(int)
    {
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator itr(*this);
        --(*this);
        return itr;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator::operator--(int)
    {
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator itr(*this);
        --(*this);
        return itr;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator&
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator::operator+=(difference_type const& d)
    {
        this->_current_vertex = vertex((this->_current_index += d), *this->_g);
        return *this;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator&
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator::operator+=(difference_type const& d)
    {
        this->_current_edge = edge((this->_current_index += d), *this->_g);
        return *this;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator::operator+(
            difference_type const& d
        ) const
    {
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator itr(*this);
        itr += d;
        return itr;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator::operator+(
            difference_type const& d
        ) const
    {
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator itr(*this);
        itr += d;
        return itr;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator&
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator::operator-=(difference_type const& d)
    {
        this->_current_vertex = vertex((this->_current_index -= d), *this->_g);
        return *this;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator&
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator::operator-=(difference_type const& d)
    {
        this->_current_edge = edge((this->_current_index -= d), *this->_g);
        return *this;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator::operator-(
            difference_type const& d
        ) const
    {
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator itr(*this);
        itr -= d;
        return itr;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator::operator-(
            difference_type const& d
        ) const
    {
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator itr(*this);
        itr -= d;
        return itr;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline ::std::pair<
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator,
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator
    >
        vertices(hypercubic_honeycomb<DC,T0,T1,T2,T3> const& g)
    {
        return ::std::make_pair(
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator(
                g,
                ::boost::initialized_value
            ),
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_iterator(g, num_vertices(g))
        );
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline ::std::pair<
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator,
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator
    >
        edges(hypercubic_honeycomb<DC,T0,T1,T2,T3> const& g)
    {
        return ::std::make_pair(
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator(
                g,
                ::boost::initialized_value
            ),
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_iterator(g, num_edges(g))
        );
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline void hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator::_post_operation()
    {
        this->_current_key.first = this->_current_index >> 1;
        this->_current_key.second = !(this->_current_index & 1);
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator::edge_key_iterator(
        degree_size_type index
    ) : _current_key(::boost::initialized_value, ::boost::initialized_value), _current_index(index)
    {
        this->_post_operation();
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::degree_size_type const&
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator::index() const
    {
        return this->_current_index;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator::reference
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator::operator*() const
    {
        return this->_current_key;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator::pointer
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator::operator->() const
    {
        return ::std::pointer_traits<pointer>::pointer_to(this->_current_key);
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator&
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator::operator++()
    {
        ++this->_current_index;
        this->_post_operation();
        return *this;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator::operator++(int)
    {
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator itr(*this);
        ++(*this);
        return itr;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator&
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator::operator--()
    {
        --this->_current_index;
        this->_post_operation();
        return *this;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator::operator--(int)
    {
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator itr(*this);
        --(*this);
        return itr;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator&
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator::operator+=(
            difference_type const& d
        )
    {
        this->_current_index += d;
        this->_post_operation();
        return *this;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator::operator+(
            difference_type const& d
        ) const
    {
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator itr(*this);
        itr += d;
        return itr;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator&
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator::operator-=(
            difference_type const& d
        )
    {
        this->_current_index -= d;
        this->_post_operation();
        return *this;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator::operator-(
            difference_type const& d
        ) const
    {
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator itr(*this);
        itr -= d;
        return itr;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline ::std::pair<
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator,
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator
    >
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_keys()
    {
        return ::std::make_pair(
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator(0),
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key_iterator(
                dimension_count::value << 1
            )
        );
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    template <bool IsOut>
    void hypercubic_honeycomb<DC,T0,T1,T2,T3>::_adj_edge_iterator<IsOut>::_post_operation()
    {
        degree_size_type index;

        for (
            ;
            this->_current_itr.index() < (dimension_count::value << 1);
            ++this->_current_itr
        )
        {
            this->_current_edge.second = *this->_current_itr;
            index = this->_current_itr->first;

            if (IsOut)
            {
                this->_current_edge.first.second[index] = this->_current_edge.first.first[index];

                if (this->_current_itr->second)
                {
                    if (++this->_current_edge.first.second[index] < this->_g->length(index))
                    {
                        break;
                    }
                    else if (this->_g->wrapped(index))
                    {
                        this->_current_edge.first.second[index] = ::boost::initialized_value;
                        break;
                    }
                    else
                    {
                        --this->_current_edge.first.second[index];
                    }
                }
                else if (this->_current_edge.first.second[index])
                {
                    --this->_current_edge.first.second[index];
                    break;
                }
                else if (this->_g->wrapped(index))
                {
                    this->_current_edge.first.second[index] = this->_g->length(index);
                    --this->_current_edge.first.second[index];
                    break;
                }
            }
            else  // if (!IsOut)
            {
                this->_current_edge.first.first[index] = this->_current_edge.first.second[index];

                if (this->_current_itr->second)
                {
                    if (this->_current_edge.first.first[index])
                    {
                        --this->_current_edge.first.first[index];
                        break;
                    }
                    else if (this->_g->wrapped(index))
                    {
                        this->_current_edge.first.first[index] = this->_g->length(index);
                        --this->_current_edge.first.first[index];
                        break;
                    }
                }
                else if (++this->_current_edge.first.first[index] < this->_g->length(index))
                {
                    break;
                }
                else if (this->_g->wrapped(index))
                {
                    this->_current_edge.first.first[index] = ::boost::initialized_value;
                    break;
                }
                else
                {
                    --this->_current_edge.first.first[index];
                }
            }
        }
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    template <bool IsOut>
    inline hypercubic_honeycomb<DC,T0,T1,T2,T3>::_adj_edge_iterator<IsOut>::_adj_edge_iterator() :
        _g(nullptr), _current_itr(), _current_edge()
    {
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    template <bool IsOut>
    inline hypercubic_honeycomb<DC,T0,T1,T2,T3>::_adj_edge_iterator<IsOut>::_adj_edge_iterator(
        type const& g,
        vertex_descriptor v,
        degree_size_type index
    ) : _g(::std::pointer_traits<_g_c_ptr>::pointer_to(g)),
        _current_itr(index),
        _current_edge(::std::make_pair(v, v), edge_key())
    {
        this->_post_operation();
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    template <bool IsOut>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::template _adj_edge_iterator<IsOut>&
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::_adj_edge_iterator<IsOut>::operator++()
    {
        if (IsOut)
        {
            this->_current_edge.first.second[
                this->_current_edge.second.first
            ] = this->_current_edge.first.first[this->_current_edge.second.first];
        }
        else
        {
            this->_current_edge.first.first[
                this->_current_edge.second.first
            ] = this->_current_edge.first.second[this->_current_edge.second.first];
        }

        ++this->_current_itr;
        this->_post_operation();
        return *this;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    template <bool IsOut>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::template _adj_edge_iterator<
        IsOut
    >::reference
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::_adj_edge_iterator<IsOut>::operator*() const
    {
        return this->_current_edge;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    template <bool IsOut>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::template _adj_edge_iterator<
        IsOut
    >::pointer
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::_adj_edge_iterator<IsOut>::operator->() const
    {
        return ::std::pointer_traits<pointer>::pointer_to(this->_current_edge);
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    template <bool IsOut>
    typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::template _adj_edge_iterator<IsOut>
        hypercubic_honeycomb<DC,T0,T1,T2,T3>::_adj_edge_iterator<IsOut>::operator++(int)
    {
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::template _adj_edge_iterator<IsOut> itr(
            *this
        );
        ++(*this);
        return itr;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline ::std::pair<
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::out_edge_iterator,
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::out_edge_iterator
    >
        out_edges(
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_descriptor v,
            hypercubic_honeycomb<DC,T0,T1,T2,T3> const& g
        )
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_vertex(v, g));
        return ::std::make_pair(
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::out_edge_iterator(g, v, 0),
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::out_edge_iterator(g, v, DC::value << 1)
        );
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline ::std::pair<
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::in_edge_iterator,
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::in_edge_iterator
    >
        in_edges(
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_descriptor v,
            hypercubic_honeycomb<DC,T0,T1,T2,T3> const& g
        )
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_vertex(v, g));
        return ::std::make_pair(
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::in_edge_iterator(g, v, 0),
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::in_edge_iterator(g, v, DC::value << 1)
        );
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::degree_size_type
        out_degree(
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_descriptor v,
            hypercubic_honeycomb<DC,T0,T1,T2,T3> const& g
        )
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_vertex(v, g));

        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::degree_size_type result = 0;
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertices_size_type o = (
            ::boost::initialized_value
        );

        ++o;

        for (
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::degree_size_type d = 0;
            d < DC::value;
            ++d
        )
        {
            if (g.wrapped(d) || (v[d] && (v[d] + o < g.length(d))))
            {
                result += 2;
            }
            else
            {
                ++result;
            }
        }

        return result;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::degree_size_type
        in_degree(
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_descriptor v,
            hypercubic_honeycomb<DC,T0,T1,T2,T3> const& g
        )
    {
        return out_degree(v, g);
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::degree_size_type
        degree(
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_descriptor v,
            hypercubic_honeycomb<DC,T0,T1,T2,T3> const& g
        )
    {
        return out_degree(v, g) << 1;
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline ::std::pair<
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::adjacency_iterator,
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::adjacency_iterator
    >
        adjacent_vertices(
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_descriptor v,
            hypercubic_honeycomb<DC,T0,T1,T2,T3> const& g
        )
    {
        ::std::pair<
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::out_edge_iterator,
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::out_edge_iterator
        > p = out_edges(v, g);
        return ::std::make_pair(
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::adjacency_iterator(p.first, &g),
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::adjacency_iterator(p.second, &g)
        );
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline ::std::pair<
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::inv_adjacency_iterator,
        typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::inv_adjacency_iterator
    >
        inv_adjacent_vertices(
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::vertex_descriptor v,
            hypercubic_honeycomb<DC,T0,T1,T2,T3> const& g
        )
    {
        ::std::pair<
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::in_edge_iterator,
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::in_edge_iterator
        > p = in_edges(v, g);
        return ::std::make_pair(
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::inv_adjacency_iterator(p.first, &g),
            typename hypercubic_honeycomb<DC,T0,T1,T2,T3>::inv_adjacency_iterator(p.second, &g)
        );
    }
}}  // namespace odds_and_ends::graph

#include <boost/property_map/property_map.hpp>

namespace odds_and_ends { namespace graph { namespace _detail {

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    struct hypercubic_honeycomb_reverse_edge_map
    {
        typedef typename ::odds_and_ends::graph
        ::hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_descriptor key_type;
        typedef key_type value_type;
        typedef value_type reference;
        typedef ::boost::readable_property_map_tag category;

        reference operator[](key_type key) const;
    };

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb_reverse_edge_map<DC,T0,T1,T2,T3>::reference
        hypercubic_honeycomb_reverse_edge_map<DC,T0,T1,T2,T3>::operator[](key_type key) const
    {
        return value_type(
            ::std::make_pair(key.first.second, key.first.first),
            typename ::odds_and_ends::graph
            ::hypercubic_honeycomb<DC,T0,T1,T2,T3>::edge_key(key.second.first, !key.second.second)
        );
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    inline typename hypercubic_honeycomb_reverse_edge_map<DC,T0,T1,T2,T3>::reference
        get(
            hypercubic_honeycomb_reverse_edge_map<DC,T0,T1,T2,T3> const& m,
            typename hypercubic_honeycomb_reverse_edge_map<DC,T0,T1,T2,T3>::key_type key
        )
    {
        return m[key];
    }
}}}  // namespace odds_and_ends::graph::_detail

#include <boost/graph/properties.hpp>

namespace boost {

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    struct property_map<
        ::odds_and_ends::graph::hypercubic_honeycomb<DC,T0,T1,T2,T3>,
        ::boost::edge_reverse_t
    >
    {
        typedef ::odds_and_ends::graph::_detail
        ::hypercubic_honeycomb_reverse_edge_map<DC,T0,T1,T2,T3> type;
        typedef type const_type;
    };

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    ::odds_and_ends::graph::_detail::hypercubic_honeycomb_reverse_edge_map<DC,T0,T1,T2,T3>
        get(
            ::boost::edge_reverse_t,
            ::odds_and_ends::graph::hypercubic_honeycomb<DC,T0,T1,T2,T3> const& g
        )
    {
        return (
            ::odds_and_ends::graph::_detail
            ::hypercubic_honeycomb_reverse_edge_map<DC,T0,T1,T2,T3>()
        );
    }
}  // namespace boost

#include <odds_and_ends/graph/_detail/index_map.hpp>

namespace boost {

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    struct property_map<
        ::odds_and_ends::graph::hypercubic_honeycomb<DC,T0,T1,T2,T3>,
        ::boost::vertex_index_t
    >
    {
        typedef ::odds_and_ends::graph::_detail::index_map<
            ::odds_and_ends::graph::hypercubic_honeycomb<DC,T0,T1,T2,T3>,
            typename ::odds_and_ends::graph::hypercubic_honeycomb<DC,T0,T1,T2,T3>::_ptr_xform,
            true
        > type;
        typedef type const_type;
    };

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    ::odds_and_ends::graph::_detail::index_map<
        ::odds_and_ends::graph::hypercubic_honeycomb<DC,T0,T1,T2,T3>,
        typename ::odds_and_ends::graph::hypercubic_honeycomb<DC,T0,T1,T2,T3>::_ptr_xform,
        true
    >
        get(
            ::boost::vertex_index_t,
            ::odds_and_ends::graph::hypercubic_honeycomb<DC,T0,T1,T2,T3> const& g
        )
    {
        return ::odds_and_ends::graph::_detail::index_map<
            ::odds_and_ends::graph::hypercubic_honeycomb<DC,T0,T1,T2,T3>,
            typename ::odds_and_ends::graph::hypercubic_honeycomb<DC,T0,T1,T2,T3>::_ptr_xform,
            true
        >(g);
    }

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    struct property_map<
        ::odds_and_ends::graph::hypercubic_honeycomb<DC,T0,T1,T2,T3>,
        ::boost::edge_index_t
    >
    {
        typedef ::odds_and_ends::graph::_detail::index_map<
            ::odds_and_ends::graph::hypercubic_honeycomb<DC,T0,T1,T2,T3>,
            typename ::odds_and_ends::graph::hypercubic_honeycomb<DC,T0,T1,T2,T3>::_ptr_xform,
            false
        > type;
        typedef type const_type;
    };

    template <typename DC, typename T0, typename T1, typename T2, typename T3>
    ::odds_and_ends::graph::_detail::index_map<
        ::odds_and_ends::graph::hypercubic_honeycomb<DC,T0,T1,T2,T3>,
        typename ::odds_and_ends::graph::hypercubic_honeycomb<DC,T0,T1,T2,T3>::_ptr_xform,
        false
    >
        get(
            ::boost::edge_index_t,
            ::odds_and_ends::graph::hypercubic_honeycomb<DC,T0,T1,T2,T3> const& g
        )
    {
        return ::odds_and_ends::graph::_detail::index_map<
            ::odds_and_ends::graph::hypercubic_honeycomb<DC,T0,T1,T2,T3>,
            typename ::odds_and_ends::graph::hypercubic_honeycomb<DC,T0,T1,T2,T3>::_ptr_xform,
            false
        >(g);
    }
}  // namespace boost

#endif  // ODDS_AND_ENDS__GRAPH__HYPERCUBIC_HONEYCOMB_HPP

