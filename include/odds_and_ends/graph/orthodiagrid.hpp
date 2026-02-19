// Copyright (C) 2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__GRAPH__ORTHODIAGRID_HPP
#define ODDS_AND_ENDS__GRAPH__ORTHODIAGRID_HPP

#include <cstddef>
#include <type_traits>
#include <functional>
#include <utility>
#include <array>
#include <bitset>
#include <vector>
#include <iterator>
#include <odds_and_ends/graph/_detail/edge_iterator.hpp>
#include <odds_and_ends/graph/parameter/template.hpp>
#include <odds_and_ends/node/parameter/template.hpp>
#include <odds_and_ends/node/container/elemental_interval_map.hpp>
#include <odds_and_ends/node/container/deque.hpp>
#include <odds_and_ends/node/balancer/adelson_velskii_landis_tree.hpp>
#include <odds_and_ends/node/with_balance_factor.hpp>
#include <odds_and_ends/static_introspection/concept/is_math_integral_type.hpp>
#include <odds_and_ends/static_introspection/concept/is_mpl_integral_constant.hpp>
#include <odds_and_ends/use_default_policy.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_iterator.hpp>
#include <boost/parameter/optional.hpp>
#include <boost/parameter/parameters.hpp>
#include <boost/parameter/value_type.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/quote.hpp>
#include <boost/mpl/assert.hpp>

namespace odds_and_ends { namespace graph {

    template <
        typename T0 = ::boost::parameter::void_,
        typename T1 = ::boost::parameter::void_,
        typename T2 = ::boost::parameter::void_,
        typename T3 = ::boost::parameter::void_,
        typename T4 = ::boost::parameter::void_,
        typename T5 = ::boost::parameter::void_
    >
    class orthodiagrid
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
            ::odds_and_ends::node::parameter::tag::_pointer_transform,
            ::boost::mpl::quote1< ::std::add_pointer>
        >::type _ptr_xform;
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
        typedef ::odds_and_ends::graph::orthodiagrid<T0,T1,T2,T3,T4,T5> type;
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

    public:
        typedef unsigned short degree_size_type;
        typedef ::std::array<vertices_size_type,2> vertex_descriptor;
        typedef ::std::pair<degree_size_type,::std::array<short,2> > edge_key;
        typedef ::std::pair<
            ::std::pair<vertex_descriptor,vertex_descriptor>,
            ::std::pair<edge_key,degree_size_type>
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

        class edge_key_iterator
        {
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
                return lhs._current_key.first == rhs._current_key.first;
            }

            friend inline bool
                operator!=(edge_key_iterator const& lhs, edge_key_iterator const& rhs)
            {
                return lhs._current_key.first != rhs._current_key.first;
            }

            friend inline bool
                operator<(edge_key_iterator const& lhs, edge_key_iterator const& rhs)
            {
                return lhs._current_key.first < rhs._current_key.first;
            }

            friend inline bool
                operator<=(edge_key_iterator const& lhs, edge_key_iterator const& rhs)
            {
                return lhs._current_key.first <= rhs._current_key.first;
            }

            friend inline bool
                operator>(edge_key_iterator const& lhs, edge_key_iterator const& rhs)
            {
                return lhs._current_key.first > rhs._current_key.first;
            }

            friend inline bool
                operator>=(edge_key_iterator const& lhs, edge_key_iterator const& rhs)
            {
                return lhs._current_key.first >= rhs._current_key.first;
            }

            friend inline difference_type
                operator-(edge_key_iterator const& lhs, edge_key_iterator const& rhs)
            {
                difference_type d = static_cast<difference_type>(lhs._current_key.first);
                d -= rhs._current_key.first;
                return d;
            }
        };

        class out_edge_iterator
        {
            _g_c_ptr _g;
            degree_size_type _offset;
            edge_key_iterator _current_itr;
            edge_descriptor _current_edge;

        public:
            typedef edge_descriptor const value_type;
            typedef value_type& reference;
            typedef typename ::boost::mpl::apply_wrap1<_ptr_xform,value_type>::type pointer;
            typedef typename edge_key_iterator::difference_type difference_type;
            typedef ::std::random_access_iterator_tag iterator_category;

            out_edge_iterator();
            out_edge_iterator(type const& g, vertex_descriptor v, degree_size_type index);
            degree_size_type const& offset() const;
            reference operator*() const;
            pointer operator->() const;
            out_edge_iterator& operator++();
            out_edge_iterator operator++(int);
            out_edge_iterator& operator--();
            out_edge_iterator operator--(int);
            out_edge_iterator& operator+=(difference_type const& d);
            out_edge_iterator operator+(difference_type const& d) const;
            out_edge_iterator& operator-=(difference_type const& d);
            out_edge_iterator operator-(difference_type const& d) const;

        private:
            void _post_operation();

            friend inline bool
                operator==(out_edge_iterator const& lhs, out_edge_iterator const& rhs)
            {
                return lhs._current_itr == rhs._current_itr;
            }

            friend inline bool
                operator!=(out_edge_iterator const& lhs, out_edge_iterator const& rhs)
            {
                return lhs._current_itr != rhs._current_itr;
            }

            friend inline bool
                operator<(out_edge_iterator const& lhs, out_edge_iterator const& rhs)
            {
                return lhs._current_itr < rhs._current_itr;
            }

            friend inline bool
                operator<=(out_edge_iterator const& lhs, out_edge_iterator const& rhs)
            {
                return lhs._current_itr <= rhs._current_itr;
            }

            friend inline bool
                operator>(out_edge_iterator const& lhs, out_edge_iterator const& rhs)
            {
                return lhs._current_itr > rhs._current_itr;
            }

            friend inline bool
                operator>=(out_edge_iterator const& lhs, out_edge_iterator const& rhs)
            {
                return lhs._current_itr >= rhs._current_itr;
            }

            friend inline difference_type
                operator-(out_edge_iterator const& lhs, out_edge_iterator const& rhs)
            {
                return lhs._current_itr - rhs._current_itr;
            }
        };

        class in_edge_iterator
        {
            _g_c_ptr _g;
            edge_key_iterator _current_itr;
            edge_descriptor _current_edge;

        public:
            typedef edge_descriptor const value_type;
            typedef value_type& reference;
            typedef typename ::boost::mpl::apply_wrap1<_ptr_xform,value_type>::type pointer;
            typedef typename edge_key_iterator::difference_type difference_type;
            typedef ::std::random_access_iterator_tag iterator_category;

            in_edge_iterator();
            in_edge_iterator(type const& g, vertex_descriptor v, degree_size_type index);
            reference operator*() const;
            pointer operator->() const;
            in_edge_iterator& operator++();
            in_edge_iterator operator++(int);
            in_edge_iterator& operator--();
            in_edge_iterator operator--(int);
            in_edge_iterator& operator+=(difference_type const& d);
            in_edge_iterator operator+(difference_type const& d) const;
            in_edge_iterator& operator-=(difference_type const& d);
            in_edge_iterator operator-(difference_type const& d) const;

        private:
            void _post_operation();

            friend inline bool
                operator==(in_edge_iterator const& lhs, in_edge_iterator const& rhs)
            {
                return lhs._current_itr == rhs._current_itr;
            }

            friend inline bool
                operator!=(in_edge_iterator const& lhs, in_edge_iterator const& rhs)
            {
                return lhs._current_itr != rhs._current_itr;
            }

            friend inline bool
                operator<(in_edge_iterator const& lhs, in_edge_iterator const& rhs)
            {
                return lhs._current_itr < rhs._current_itr;
            }

            friend inline bool
                operator<=(in_edge_iterator const& lhs, in_edge_iterator const& rhs)
            {
                return lhs._current_itr <= rhs._current_itr;
            }

            friend inline bool
                operator>(in_edge_iterator const& lhs, in_edge_iterator const& rhs)
            {
                return lhs._current_itr > rhs._current_itr;
            }

            friend inline bool
                operator>=(in_edge_iterator const& lhs, in_edge_iterator const& rhs)
            {
                return lhs._current_itr >= rhs._current_itr;
            }

            friend inline difference_type
                operator-(in_edge_iterator const& lhs, in_edge_iterator const& rhs)
            {
                return lhs._current_itr - rhs._current_itr;
            }
        };

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
        typedef typename ::boost::mpl::eval_if<
            ::std::is_same<_container_gen,::odds_and_ends::use_default_policy>,
            ::boost::mpl::if_<
                ::std::is_same<vertices_size_type,::std::size_t>,
                ::std::vector<edges_size_type>,
                ::odds_and_ends::node::container::deque<
                    edges_size_type,
                    ::boost::mpl::deque< ::odds_and_ends::node::with_balance_factor>,
                    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer,
                    vertices_size_type
                >
            >,
            ::boost::mpl::apply_wrap1<_container_gen,edges_size_type>
        >::type _edge_index_offset_t;
        typedef ::odds_and_ends::node::container::elemental_interval_map<
            edges_size_type,
            vertices_size_type,
            _compare_gen,
            _container_gen
        > _ei2vi_map_t;

        vertex_descriptor _dimension_lengths;
        degree_size_type _wraparound_mask;
        vertices_size_type _vertex_count;
        edges_size_type _edge_count;
        _edge_index_offset_t _edge_index_offset;
        _ei2vi_map_t _ei2vi_map;

    public:
        orthodiagrid(vertices_size_type const& l0, vertices_size_type const& l1, bool w0, bool w1);
        orthodiagrid(vertices_size_type const& l0, vertices_size_type const& l1);
        vertices_size_type const& length(degree_size_type const& d) const;
        degree_size_type wrapped(degree_size_type const& d) const;
        vertex_descriptor next(vertex_descriptor v, edge_key key) const;
        vertex_descriptor next(vertex_descriptor v, edge_key key, _index_difference d) const;
        vertex_descriptor previous(vertex_descriptor v, edge_key key) const;
        vertex_descriptor previous(vertex_descriptor v, edge_key key, _index_difference d) const;
        vertices_size_type operator[](vertex_descriptor v) const;
        edges_size_type operator[](edge_descriptor e) const;

    private:
        void _post_construct();
        edge_descriptor _edge_at(edges_size_type i) const;
        degree_size_type _compute_out_edge_offset(vertex_descriptor v) const;

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
    };

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline void orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator::_post_operation()
    {
        switch (7 & this->_current_key.first)
        {
            case 0:
            {
                this->_current_key.second[0] = 1;
                this->_current_key.second[1] = 0;
                break;
            }

            case 1:
            {
                this->_current_key.second[0] = 1;
                this->_current_key.second[1] = 1;
                break;
            }

            case 2:
            {
                this->_current_key.second[0] = 0;
                this->_current_key.second[1] = 1;
                break;
            }

            case 3:
            {
                this->_current_key.second[0] = -1;
                this->_current_key.second[1] = 1;
                break;
            }

            case 4:
            {
                this->_current_key.second[0] = -1;
                this->_current_key.second[1] = 0;
                break;
            }

            case 5:
            {
                this->_current_key.second[0] = -1;
                this->_current_key.second[1] = -1;
                break;
            }

            case 6:
            {
                this->_current_key.second[0] = 0;
                this->_current_key.second[1] = -1;
                break;
            }

            case 7:
            {
                this->_current_key.second[0] = 1;
                this->_current_key.second[1] = -1;
                break;
            }

            default:
            {
                break;
            }
        }
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator::edge_key_iterator(
        degree_size_type index
    ) : _current_key(index, ::std::array<short,2>())
    {
        this->_post_operation();
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator::reference
        orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator::operator*() const
    {
        return this->_current_key;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator&
        orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator::operator++()
    {
        ++this->_current_key.first;
        this->_post_operation();
        return *this;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator
        orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator::operator++(int)
    {
        typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator itr(*this);
        ++(*this);
        return itr;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator&
        orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator::operator--()
    {
        --this->_current_key.first;
        this->_post_operation();
        return *this;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator
        orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator::operator--(int)
    {
        typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator itr(*this);
        --(*this);
        return itr;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator&
        orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator::operator+=(difference_type const& d)
    {
        this->_current_key.first += d;
        this->_post_operation();
        return *this;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator
        orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator::operator+(
            difference_type const& d
        ) const
    {
        typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator itr(*this);
        itr += d;
        return itr;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator&
        orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator::operator-=(difference_type const& d)
    {
        this->_current_key.first -= d;
        this->_post_operation();
        return *this;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator
        orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator::operator-(
            difference_type const& d
        ) const
    {
        typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator itr(*this);
        itr -= d;
        return itr;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline ::std::pair<
        typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator,
        typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator
    >
        orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_keys()
    {
        return ::std::make_pair(
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator(0),
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator(8)
        );
    }
}}  // namespace odds_and_ends::graph

#include <limits>

namespace odds_and_ends { namespace graph {

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_descriptor
        orthodiagrid<T0,T1,T2,T3,T4,T5>::null_vertex()
    {
        static vertex_descriptor _null_vertex = {
            (::std::numeric_limits<vertices_size_type>::max)(),
            (::std::numeric_limits<vertices_size_type>::max)()
        };
        return _null_vertex;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_descriptor
        orthodiagrid<T0,T1,T2,T3,T4,T5>::null_edge()
    {
        static edge_descriptor _null_edge;

        _null_edge.first.first = type::null_vertex();
        _null_edge.first.second = type::null_vertex();
        return _null_edge;
    }
}}  // namespace odds_and_ends::graph

#include <boost/utility/value_init.hpp>

namespace odds_and_ends { namespace graph { namespace _detail {

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline bool
        is_valid_vertex(
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_descriptor v,
            orthodiagrid<T0,T1,T2,T3,T4,T5> const& g
        )
    {
        typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertices_size_type const z = (
            ::boost::initialized_value
        );
        return (z <= v[0]) && (v[0] < g.length(0)) && (z <= v[1]) && (v[1] < g.length(1));
    }
}}}  // namespace odds_and_ends::graph::_detail

#include <boost/assert.hpp>

namespace odds_and_ends { namespace graph {

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline ::std::pair<
        typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_iterator,
        typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_iterator
    >
        edges(orthodiagrid<T0,T1,T2,T3,T4,T5> const& g)
    {
        return ::std::make_pair(
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_iterator(g, ::boost::initialized_value),
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_iterator(g, num_edges(g))
        );
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertices_size_type const&
        orthodiagrid<T0,T1,T2,T3,T4,T5>::length(degree_size_type const& d) const
    {
        BOOST_ASSERT(d < 2);
        return this->_dimension_lengths[d];
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::degree_size_type
        orthodiagrid<T0,T1,T2,T3,T4,T5>::wrapped(degree_size_type const& d) const
    {
        BOOST_ASSERT(d < 2);
        return (1 << d) & this->_wraparound_mask;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::degree_size_type
        orthodiagrid<T0,T1,T2,T3,T4,T5>::_compute_out_edge_offset(vertex_descriptor v) const
    {
        return (
            (!this->wrapped(0) && !v[0] && (this->wrapped(1) || v[1])) ?
            6 :
            (!this->wrapped(1) && (v[1] + 1 == this->length(1)) && (this->wrapped(0) || v[0])) ?
            4 :
            (
                !this->wrapped(0) &&
                (v[0] + 1 == this->length(0)) &&
                (this->wrapped(1) || (v[1] + 1 < this->length(1)))
            ) ?
            2 :
            0
        );
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_descriptor
        orthodiagrid<T0,T1,T2,T3,T4,T5>::next(vertex_descriptor v, edge_key key) const
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_vertex(v, *this));

        switch (key.second[0])
        {
            case 1:
            {
                if (++v[0] == this->length(0))
                {
                    if (this->wrapped(0))
                    {
                        v[0] = ::boost::initialized_value;
                    }
                    else
                    {
                        return type::null_vertex();
                    }
                }

                break;
            }

            case -1:
            {
                if (v[0])
                {
                    --v[0];
                }
                else if (this->wrapped(0))
                {
                    v[0] = this->length(0);
                    --v[0];
                }
                else
                {
                    return type::null_vertex();
                }

                break;
            }
        }

        switch (key.second[1])
        {
            case 1:
            {
                if (++v[1] == this->length(1))
                {
                    if (this->wrapped(1))
                    {
                        v[1] = ::boost::initialized_value;
                    }
                    else
                    {
                        return type::null_vertex();
                    }
                }

                break;
            }

            case -1:
            {
                if (v[1])
                {
                    --v[1];
                }
                else if (this->wrapped(1))
                {
                    v[1] = this->length(1);
                    --v[1];
                }
                else
                {
                    return type::null_vertex();
                }

                break;
            }
        }

        return v;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_descriptor
        orthodiagrid<T0,T1,T2,T3,T4,T5>::previous(vertex_descriptor v, edge_key key) const
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_vertex(v, *this));

        switch (key.second[0])
        {
            case -1:
            {
                if (++v[0] == this->length(0))
                {
                    if (this->wrapped(0))
                    {
                        v[0] = ::boost::initialized_value;
                    }
                    else
                    {
                        return type::null_vertex();
                    }
                }

                break;
            }

            case 1:
            {
                if (v[0])
                {
                    --v[0];
                }
                else if (this->wrapped(0))
                {
                    v[0] = this->length(0);
                    --v[0];
                }
                else
                {
                    return type::null_vertex();
                }

                break;
            }
        }

        switch (key.second[1])
        {
            case -1:
            {
                if (++v[1] == this->length(1))
                {
                    if (this->wrapped(1))
                    {
                        v[1] = ::boost::initialized_value;
                    }
                    else
                    {
                        return type::null_vertex();
                    }
                }

                break;
            }

            case 1:
            {
                if (v[1])
                {
                    --v[1];
                }
                else if (this->wrapped(1))
                {
                    v[1] = this->length(1);
                    --v[1];
                }
                else
                {
                    return type::null_vertex();
                }

                break;
            }
        }

        return v;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_descriptor
        orthodiagrid<T0,T1,T2,T3,T4,T5>::next(
            vertex_descriptor v,
            edge_key key,
            _index_difference d
        ) const
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_vertex(v, *this));

        static _index_difference const z_d = ::boost::initialized_value;

        for (degree_size_type i = 0; !(2 & i); ++i)
        {
            switch (key.second[i])
            {
                case 1:
                {
                    if (d < z_d)
                    {
                        if (v[i] < -d)
                        {
                            if (this->wrapped(i))
                            {
                                for (; v[i] < -d; v[i] += this->length(i))
                                {
                                }

                                v[i] += d;
                                v[i] %= this->length(i);
                            }
                            else
                            {
                                return type::null_vertex();
                            }
                        }
                        else  // if (-d <= v[i])
                        {
                            v[i] += d;
                        }
                    }
                    else  // if (z_d <= d)
                    {
                        v[i] += d;

                        if (this->length(i) <= v[i])
                        {
                            if (this->wrapped(i))
                            {
                                v[i] %= this->length(i);
                            }
                            else
                            {
                                return type::null_vertex();
                            }
                        }
                    }

                    break;
                }

                case -1:
                {
                    if (d < z_d)
                    {
                        v[i] -= d;

                        if (this->length(i) <= v[i])
                        {
                            if (this->wrapped(i))
                            {
                                v[i] %= this->length(i);
                            }
                            else
                            {
                                return type::null_vertex();
                            }
                        }
                    }
                    else  // if (z_d <= d)
                    {
                        if (v[i] < d)
                        {
                            if (this->wrapped(i))
                            {
                                for (; v[i] < d; v[i] += this->length(i))
                                {
                                }

                                v[i] -= d;
                                v[i] %= this->length(i);
                            }
                            else
                            {
                                return type::null_vertex();
                            }
                        }
                        else  // if (d <= v[i])
                        {
                            v[i] -= d;
                        }
                    }

                    break;
                }
            }
        }

        return v;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_descriptor
        orthodiagrid<T0,T1,T2,T3,T4,T5>::previous(
            vertex_descriptor v,
            edge_key key,
            _index_difference d
        ) const
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_vertex(v, *this));

        static _index_difference const z_d = ::boost::initialized_value;

        for (degree_size_type i = 0; !(2 & i); ++i)
        {
            switch (key.second[i])
            {
                case -1:
                {
                    if (d < z_d)
                    {
                        if (v[i] < -d)
                        {
                            if (this->wrapped(i))
                            {
                                for (; v[i] < -d; v[i] += this->length(i))
                                {
                                }

                                v[i] += d;
                                v[i] %= this->length(i);
                            }
                            else
                            {
                                return type::null_vertex();
                            }
                        }
                        else  // if (-d <= v[i])
                        {
                            v[i] += d;
                        }
                    }
                    else  // if (z_d <= d)
                    {
                        v[i] += d;

                        if (this->length(i) <= v[i])
                        {
                            if (this->wrapped(i))
                            {
                                v[i] %= this->length(i);
                            }
                            else
                            {
                                return type::null_vertex();
                            }
                        }
                    }

                    break;
                }

                case 1:
                {
                    if (d < z_d)
                    {
                        v[i] -= d;

                        if (this->length(i) <= v[i])
                        {
                            if (this->wrapped(i))
                            {
                                v[i] %= this->length(i);
                            }
                            else
                            {
                                return type::null_vertex();
                            }
                        }
                    }
                    else  // if (z_d <= d)
                    {
                        if (v[i] < d)
                        {
                            if (this->wrapped(i))
                            {
                                for (; v[i] < d; v[i] += this->length(i))
                                {
                                }

                                v[i] -= d;
                                v[i] %= this->length(i);
                            }
                            else
                            {
                                return type::null_vertex();
                            }
                        }
                        else  // if (d <= v[i])
                        {
                            v[i] -= d;
                        }
                    }

                    break;
                }
            }
        }

        return v;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::degree_size_type
        out_degree(
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_descriptor v,
            orthodiagrid<T0,T1,T2,T3,T4,T5> const& g
        )
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_vertex(v, g));

        static typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertices_size_type const z = (
            ::boost::initialized_value
        );
        typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertices_size_type o = z;

        ++o;

        unsigned char const c = (
            (g.wrapped(0) || ((z < v[0]) && (v[0] + o < g.length(0)))) ?
            ((g.wrapped(1) || ((z < v[1]) && (v[1] + o < g.length(1)))) ? 0 : 1) :
            ((g.wrapped(1) || ((z < v[1]) && (v[1] + o < g.length(1)))) ? 1 : 2)
        );

        switch (c)
        {
            case 2:
            {
                return 3;
            }

            case 1:
            {
                return 5;
            }

            default:
            {
                return 8;
            }
        }
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::degree_size_type
        in_degree(
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_descriptor v,
            orthodiagrid<T0,T1,T2,T3,T4,T5> const& g
        )
    {
        return out_degree(v, g);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::degree_size_type
        degree(
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_descriptor v,
            orthodiagrid<T0,T1,T2,T3,T4,T5> const& g
        )
    {
        return out_degree(v, g) << 1;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline void orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator::_post_operation()
    {
        this->_current_edge.second.first = *this->_current_itr;
        this->_current_edge.second.first.first &= 7;
        this->_current_edge.second.second &= 7;
        this->_current_edge.first.second = (
            this->_g->next(this->_current_edge.first.first, this->_current_edge.second.first)
        );
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator::out_edge_iterator() :
        _g(nullptr), _offset(), _current_itr(), _current_edge()
    {
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::degree_size_type const&
        orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator::offset() const
    {
        return this->_offset;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator::reference
        orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator::operator*() const
    {
        return this->_current_edge;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator&
        orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator::operator++()
    {
        ++this->_current_itr;
        ++this->_current_edge.second.second;
        this->_post_operation();
        return *this;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    typename orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator
        orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator::operator++(int)
    {
        out_edge_iterator itr(*this);
        ++(*this);
        return itr;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator&
        orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator::operator--()
    {
        --this->_current_itr;
        --this->_current_edge.second.second;
        this->_post_operation();
        return *this;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    typename orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator
        orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator::operator--(int)
    {
        out_edge_iterator itr(*this);
        --(*this);
        return itr;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator&
        orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator::operator+=(
            difference_type const& d
        )
    {
        this->_current_itr += d;
        this->_current_edge.second.second += d;
        this->_post_operation();
        return *this;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    typename orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator
        orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator::operator+(
            difference_type const& d
        ) const
    {
        out_edge_iterator itr(*this);
        itr += d;
        return itr;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator&
        orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator::operator-=(
            difference_type const& d
        )
    {
        this->_current_itr -= d;
        this->_current_edge.second.second -= d;
        this->_post_operation();
        return *this;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    typename orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator
        orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator::operator-(
            difference_type const& d
        ) const
    {
        out_edge_iterator itr(*this);
        itr -= d;
        return itr;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline ::std::pair<
        typename orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator,
        typename orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator
    >
        out_edges(
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_descriptor v,
            orthodiagrid<T0,T1,T2,T3,T4,T5> const& g
        )
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_vertex(v, g));
        return ::std::make_pair(
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator(g, v, 0),
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator(g, v, out_degree(v, g))
        );
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_descriptor
        vertex(
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertices_size_type i,
            orthodiagrid<T0,T1,T2,T3,T4,T5> const& g
        )
    {
        if (i < num_vertices(g))
        {
            return {i % g.length(0), (i / g.length(0)) % g.length(1)};
        }
        else
        {
            return orthodiagrid<T0,T1,T2,T3,T4,T5>::null_vertex();
        }
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator::vertex_iterator() :
        _g(nullptr), _current_index(), _current_vertex()
    {
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator::reference
        orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator::operator*() const
    {
        return this->_current_vertex;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator&
        orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator::operator++()
    {
        this->_current_vertex = vertex((++this->_current_index), *this->_g);
        return *this;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator
        orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator::operator++(int)
    {
        typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator itr(*this);
        ++(*this);
        return itr;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator&
        orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator::operator--()
    {
        this->_current_vertex = vertex((--this->_current_index), *this->_g);
        return *this;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator
        orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator::operator--(int)
    {
        typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator itr(*this);
        --(*this);
        return itr;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator&
        orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator::operator+=(difference_type const& d)
    {
        this->_current_vertex = vertex((this->_current_index += d), *this->_g);
        return *this;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator
        orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator::operator+(difference_type const& d) const
    {
        typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator itr(*this);
        itr += d;
        return itr;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator&
        orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator::operator-=(difference_type const& d)
    {
        this->_current_vertex = vertex((this->_current_index -= d), *this->_g);
        return *this;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator
        orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator::operator-(difference_type const& d) const
    {
        typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator itr(*this);
        itr -= d;
        return itr;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline ::std::pair<
        typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator,
        typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator
    >
        vertices(orthodiagrid<T0,T1,T2,T3,T4,T5> const& g)
    {
        return ::std::make_pair(
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator(
                g,
                ::boost::initialized_value
            ),
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator(g, num_vertices(g))
        );
    }
}}  // namespace odds_and_ends::graph

namespace odds_and_ends { namespace graph { namespace _detail {

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline bool
        is_valid_edge(
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_descriptor e,
            orthodiagrid<T0,T1,T2,T3,T4,T5> const& g
        )
    {
        return (
            ::odds_and_ends::graph::_detail::is_valid_vertex(e.first.first, g) &&
            ::odds_and_ends::graph::_detail::is_valid_vertex(e.first.second, g)
        );
    }
}}}  // namespace odds_and_ends::graph::_detail

#include <boost/iterator/counting_iterator.hpp>

namespace odds_and_ends { namespace graph {

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    void orthodiagrid<T0,T1,T2,T3,T4,T5>::_post_construct()
    {
        if (this->_wraparound_mask < 3)
        {
            static vertices_size_type const z = ::boost::initialized_value;
            vertices_size_type o = z;
            edges_size_type a = ::boost::initialized_value;

            this->_edge_index_offset[z] = a;
            ++o;

            for (vertices_size_type i = z; i < this->_vertex_count; ++i)
            {
                a += out_degree(vertex(i, *this), *this);
                this->_edge_index_offset[i + o] = a;
            }

            this->_ei2vi_map = _ei2vi_map_t(
                this->_edge_index_offset.cbegin(),
                this->_edge_index_offset.cend(),
                ::boost::counting_iterator<vertices_size_type>(z),
                ::boost::counting_iterator<vertices_size_type>(this->_vertex_count)
            );
        }
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline orthodiagrid<T0,T1,T2,T3,T4,T5>::orthodiagrid(
        vertices_size_type const& l0,
        vertices_size_type const& l1,
        bool w0,
        bool w1
    ) : _dimension_lengths({l0, l1}),
        _wraparound_mask((w0 ? 1 : 0) | (w1 ? 2 : 0)),
        _vertex_count(l0 * l1),
        _edge_count(
            w0 ? (w1 ? ((l0 * l1) << 3) : (((l0 * l1) << 3) - (l0 * edges_size_type(6)))) : (
                w1 ? (((l0 * l1) << 3) - (l1 * edges_size_type(6))) : (
                    ((l0 * l1) << 3) - ((l0 + l1) * edges_size_type(6)) + edges_size_type(4)
                )
            )
        ),
        _edge_index_offset(
            (w0 && w1) ?
            (typename _edge_index_offset_t::size_type(0)) :
            ((l0 * l1) + typename _edge_index_offset_t::size_type(1))
        ),
        _ei2vi_map()
    {
        this->_post_construct();
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline orthodiagrid<T0,T1,T2,T3,T4,T5>::orthodiagrid(
        vertices_size_type const& l0,
        vertices_size_type const& l1
    ) : _dimension_lengths({l0, l1}),
        _wraparound_mask(0),
        _vertex_count(l0 * l1),
        _edge_count(((l0 * l1) << 3) - ((l0 + l1) * edges_size_type(6)) + edges_size_type(4)),
        _edge_index_offset((l0 * l1) + typename _edge_index_offset_t::size_type(1)),
        _ei2vi_map()
    {
        this->_post_construct();
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertices_size_type
        orthodiagrid<T0,T1,T2,T3,T4,T5>::operator[](vertex_descriptor v) const
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_vertex(v, *this));
        return v[1] * this->length(0) + v[0];
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edges_size_type
        orthodiagrid<T0,T1,T2,T3,T4,T5>::operator[](edge_descriptor e) const
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_edge(e, *this));
        return (
            (3 == this->_wraparound_mask) ?
            edges_size_type((*this)[e.first.first] << 3) :
            this->_edge_index_offset[(*this)[e.first.first]]
        ) + edges_size_type(e.second.second);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_descriptor
        source(
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_descriptor e,
            orthodiagrid<T0,T1,T2,T3,T4,T5> const& g
        )
    {
        return e.first.first;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_descriptor
        target(
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_descriptor e,
            orthodiagrid<T0,T1,T2,T3,T4,T5> const& g
        )
    {
        return e.first.second;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key
        key(
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_descriptor e,
            orthodiagrid<T0,T1,T2,T3,T4,T5> const& g
        )
    {
        return e.second.first;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    ::std::pair<typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_descriptor,bool>
        edge(
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_descriptor u,
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_descriptor v,
            orthodiagrid<T0,T1,T2,T3,T4,T5> const& g
        )
    {
        ::std::pair<typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_descriptor,bool> result;
        typename orthodiagrid<T0,T1,T2,T3,T4,T5>::degree_size_type d = 0;

        for (
            ::std::pair<
                typename orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator,
                typename orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator
            > p_oe_itr_2 = out_edges(u, g);
            p_oe_itr_2.first < p_oe_itr_2.second;
            ++p_oe_itr_2.first
        )
        {
            if (target(*p_oe_itr_2.first, g) == v)
            {
                result.first = *p_oe_itr_2.first;
                result.second = true;
                return result;
            }

            ++d;
        }

        result.second = false;
        return result;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator::in_edge_iterator() :
        _g(nullptr), _current_itr(), _current_edge()
    {
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator::reference
        orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator::operator*() const
    {
        return this->_current_edge;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    void orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator::_post_operation()
    {
        vertex_descriptor v = this->_current_edge.first.second;

        this->_current_edge.second.first = *this->_current_itr;
        this->_current_edge.second.first.first &= 7;

        vertex_descriptor u = this->_g->previous(v, this->_current_edge.second.first);

        if (::odds_and_ends::graph::_detail::is_valid_vertex(u, *this->_g))
        {
            this->_current_edge.second.second = edge(u, v, *this->_g).first.second.second;
            this->_current_edge.first.first = u;
        }
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator&
        orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator::operator++()
    {
        ++this->_current_itr;
        this->_post_operation();
        return *this;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    typename orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator
        orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator::operator++(int)
    {
        in_edge_iterator itr(*this);
        ++(*this);
        return itr;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator&
        orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator::operator--()
    {
        --this->_current_itr;
        this->_post_operation();
        return *this;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    typename orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator
        orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator::operator--(int)
    {
        in_edge_iterator itr(*this);
        --(*this);
        return itr;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator&
        orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator::operator+=(
            difference_type const& d
        )
    {
        this->_current_itr += d;
        this->_post_operation();
        return *this;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    typename orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator
        orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator::operator+(
            difference_type const& d
        ) const
    {
        in_edge_iterator itr(*this);
        itr += d;
        return itr;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator&
        orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator::operator-=(
            difference_type const& d
        )
    {
        this->_current_itr -= d;
        this->_post_operation();
        return *this;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    typename orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator
        orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator::operator-(
            difference_type const& d
        ) const
    {
        in_edge_iterator itr(*this);
        itr -= d;
        return itr;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline ::std::pair<
        typename orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator,
        typename orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator
    >
        in_edges(
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_descriptor v,
            orthodiagrid<T0,T1,T2,T3,T4,T5> const& g
        )
    {
        BOOST_ASSERT(::odds_and_ends::graph::_detail::is_valid_vertex(v, g));
        return ::std::make_pair(
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator(g, v, 0),
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator(g, v, in_degree(v, g))
        );
    }
}}  // namespace odds_and_ends::graph

#include <memory>

namespace odds_and_ends { namespace graph {

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator::vertex_iterator(
        type const& g,
        vertices_size_type index
    ) : _g(::std::pointer_traits<_g_c_ptr>::pointer_to(g)),
        _current_index(index),
        _current_vertex(vertex(_current_index, g))
    {
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator::pointer
        orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_iterator::operator->() const
    {
        return ::std::pointer_traits<pointer>::pointer_to(this->_current_vertex);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator::pointer
        orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_key_iterator::operator->() const
    {
        return ::std::pointer_traits<pointer>::pointer_to(this->_current_key);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator::out_edge_iterator(
        type const& g,
        vertex_descriptor v,
        degree_size_type index
    ) : _g(::std::pointer_traits<_g_c_ptr>::pointer_to(g)),
        _offset(g._compute_out_edge_offset(v)),
        _current_itr(index + _offset),
        _current_edge(
            ::std::make_pair(v, g.next(v, *_current_itr)),
            ::std::make_pair(*_current_itr, 7 & index)
        )
    {
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator::in_edge_iterator(
        type const& g,
        vertex_descriptor v,
        degree_size_type index
    ) : _g(::std::pointer_traits<_g_c_ptr>::pointer_to(g)),
        _current_itr(
            (!g.wrapped(0) && !v[0] && (g.wrapped(1) || v[1])) ?
            (index + 2) :
            (!g.wrapped(1) && (v[1] + 1 == g.length(1)) && (g.wrapped(0) || v[0])) ?
            index :
            (
                !g.wrapped(0) &&
                (v[0] + 1 == g.length(0)) &&
                (g.wrapped(1) || (v[1] + 1 < g.length(1)))
            ) ?
            (index + 6) :
            (index + 4)
        ),
        _current_edge()
    {
        _current_edge.first.second = v;
        this->_post_operation();
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_descriptor
        orthodiagrid<T0,T1,T2,T3,T4,T5>::_edge_at(
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::edges_size_type i_e
        ) const
    {
        if (i_e < this->_edge_count)
        {
            if (3 == this->_wraparound_mask)
            {
                out_edge_iterator itr(*this, vertex(i_e >> 3, *this), degree_size_type(7 & i_e));
                return *itr;
            }
            else
            {
                vertices_size_type i_v = this->_ei2vi_map[i_e];
                out_edge_iterator itr(
                    *this,
                    vertex(i_v, *this),
                    degree_size_type(i_e - this->_edge_index_offset[i_v])
                );
                edge_descriptor result = *itr;
                result.second.first.first &= 7;
                return result;
            }
        }
        else
        {
            return type::null_edge();
        }
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator::pointer
        orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator::operator->() const
    {
        return ::std::pointer_traits<pointer>::pointer_to(this->_current_edge);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator::pointer
        orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator::operator->() const
    {
        return ::std::pointer_traits<pointer>::pointer_to(this->_current_edge);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline ::std::pair<
        typename orthodiagrid<T0,T1,T2,T3,T4,T5>::adjacency_iterator,
        typename orthodiagrid<T0,T1,T2,T3,T4,T5>::adjacency_iterator
    >
        adjacent_vertices(
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_descriptor v,
            orthodiagrid<T0,T1,T2,T3,T4,T5> const& g
        )
    {
        ::std::pair<
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator,
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::out_edge_iterator
        > p = out_edges(v, g);
        return ::std::make_pair(
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::adjacency_iterator(p.first, &g),
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::adjacency_iterator(p.second, &g)
        );
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline ::std::pair<
        typename orthodiagrid<T0,T1,T2,T3,T4,T5>::inv_adjacency_iterator,
        typename orthodiagrid<T0,T1,T2,T3,T4,T5>::inv_adjacency_iterator
    >
        inv_adjacent_vertices(
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::vertex_descriptor v,
            orthodiagrid<T0,T1,T2,T3,T4,T5> const& g
        )
    {
        ::std::pair<
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator,
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::in_edge_iterator
        > p = in_edges(v, g);
        return ::std::make_pair(
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::inv_adjacency_iterator(p.first, &g),
            typename orthodiagrid<T0,T1,T2,T3,T4,T5>::inv_adjacency_iterator(p.second, &g)
        );
    }
}}  // namespace odds_and_ends::graph

#include <boost/property_map/property_map.hpp>

namespace odds_and_ends { namespace graph { namespace _detail {

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    struct orthodiagrid_reverse_edge_map
    {
        typedef typename ::odds_and_ends::graph
        ::orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_descriptor key_type;
        typedef key_type value_type;
        typedef value_type reference;
        typedef ::boost::readable_property_map_tag category;

        reference operator[](key_type key) const;
    };

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid_reverse_edge_map<T0,T1,T2,T3,T4,T5>::reference
        orthodiagrid_reverse_edge_map<T0,T1,T2,T3,T4,T5>::operator[](key_type key) const
    {
        return value_type(
            ::std::make_pair(key.first.second, key.first.first),
            ::std::make_pair(
                *(
                    ::odds_and_ends::graph::orthodiagrid<T0,T1,T2,T3,T4,T5>::edge_keys().first +
                    (4 ^ key.second.first.first)
                ),
                4 ^ key.second.second
            )
        );
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline typename orthodiagrid_reverse_edge_map<T0,T1,T2,T3,T4,T5>::reference
        get(
            orthodiagrid_reverse_edge_map<T0,T1,T2,T3,T4,T5> const& m,
            typename orthodiagrid_reverse_edge_map<T0,T1,T2,T3,T4,T5>::key_type key
        )
    {
        return m[key];
    }
}}}  // namespace odds_and_ends::graph::_detail

#include <odds_and_ends/graph/_detail/index_map.hpp>
#include <boost/graph/properties.hpp>

namespace boost {

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    struct property_map<
        ::odds_and_ends::graph::orthodiagrid<T0,T1,T2,T3,T4,T5>,
        ::boost::edge_reverse_t
    >
    {
        typedef ::odds_and_ends::graph::_detail
        ::orthodiagrid_reverse_edge_map<T0,T1,T2,T3,T4,T5> type;
        typedef type const_type;
    };

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline ::odds_and_ends::graph::_detail::orthodiagrid_reverse_edge_map<T0,T1,T2,T3,T4,T5>
        get(
            ::boost::edge_reverse_t,
            ::odds_and_ends::graph::orthodiagrid<T0,T1,T2,T3,T4,T5> const& g
        )
    {
        return (
            ::odds_and_ends::graph::_detail::orthodiagrid_reverse_edge_map<T0,T1,T2,T3,T4,T5>()
        );
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    struct property_map<
        ::odds_and_ends::graph::orthodiagrid<T0,T1,T2,T3,T4,T5>,
        ::boost::vertex_index_t
    >
    {
        typedef ::odds_and_ends::graph::_detail::index_map<
            ::odds_and_ends::graph::orthodiagrid<T0,T1,T2,T3,T4,T5>,
            true
        > type;
        typedef type const_type;
    };

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline ::odds_and_ends::graph::_detail::index_map<
        ::odds_and_ends::graph::orthodiagrid<T0,T1,T2,T3,T4,T5>,
        true
    >
        get(
            ::boost::vertex_index_t,
            ::odds_and_ends::graph::orthodiagrid<T0,T1,T2,T3,T4,T5> const& g
        )
    {
        return ::odds_and_ends::graph::_detail::index_map<
            ::odds_and_ends::graph::orthodiagrid<T0,T1,T2,T3,T4,T5>,
            true
        >(g);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    struct property_map<
        ::odds_and_ends::graph::orthodiagrid<T0,T1,T2,T3,T4,T5>,
        ::boost::edge_index_t
    >
    {
        typedef ::odds_and_ends::graph::_detail::index_map<
            ::odds_and_ends::graph::orthodiagrid<T0,T1,T2,T3,T4,T5>,
            false
        > type;
        typedef type const_type;
    };

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    inline ::odds_and_ends::graph::_detail::index_map<
        ::odds_and_ends::graph::orthodiagrid<T0,T1,T2,T3,T4,T5>,
        false
    >
        get(
            ::boost::edge_index_t,
            ::odds_and_ends::graph::orthodiagrid<T0,T1,T2,T3,T4,T5> const& g
        )
    {
        return ::odds_and_ends::graph::_detail::index_map<
            ::odds_and_ends::graph::orthodiagrid<T0,T1,T2,T3,T4,T5>,
            false
        >(g);
    }
}  // namespace boost

#endif  // ODDS_AND_ENDS__GRAPH__ORTHODIAGRID_HPP

