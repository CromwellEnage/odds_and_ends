// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__CONTAINER__MAP_HPP
#define ODDS_AND_ENDS__NODE__CONTAINER__MAP_HPP

#include <cstddef>
#include <type_traits>
#include <functional>
#include <utility>
#include <memory>
#include <initializer_list>
#include <odds_and_ends/node/data.hpp>
#include <odds_and_ends/node/tree/base.hpp>
#include <odds_and_ends/node/tree/binary.hpp>
#include <odds_and_ends/node/tree/with_size.hpp>
#include <odds_and_ends/node/iterator/in_order_tree.hpp>
#include <odds_and_ends/node/iterator/indirect.hpp>
#include <odds_and_ends/node/parameter/template.hpp>
#include <odds_and_ends/composite_type/composite_type.hpp>
#include <odds_and_ends/static_introspection/concept/is_allocator.hpp>
#include <odds_and_ends/static_introspection/concept/is_indexable_iterator.hpp>
#include <odds_and_ends/static_introspection/concept/is_runtime_pair.hpp>
#include <boost/parameter/optional.hpp>
#include <boost/parameter/required.hpp>
#include <boost/parameter/parameters.hpp>
#include <boost/parameter/value_type.hpp>
#include <boost/core/enable_if.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/quote.hpp>
#include <boost/limits.hpp>

namespace odds_and_ends { namespace node { namespace container {

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2 = ::boost::parameter::void_,
        typename T3 = ::boost::parameter::void_,
        typename T4 = ::boost::parameter::void_,
        typename T5 = ::boost::parameter::void_,
        typename T6 = ::boost::parameter::void_
    >
    class map
    {
        struct _enabler
        {
        };

        typedef typename ::boost::parameter::parameters<
            ::boost::parameter::required<
                ::odds_and_ends::node::parameter::tag::_node_parent_generator_list
            >,
            ::boost::parameter::required< ::odds_and_ends::node::parameter::tag::_balancer>,
            ::boost::parameter::optional<
                ::odds_and_ends::node::parameter::tag::_compare_generator
            >,
            ::boost::parameter::optional< ::odds_and_ends::node::parameter::tag::_size>,
            ::boost::parameter::optional< ::odds_and_ends::node::parameter::tag::_difference>,
            ::boost::parameter::optional<
                ::odds_and_ends::node::parameter::tag::_pointer_transform
            >,
            ::boost::parameter::optional<
                ::odds_and_ends::node::parameter::tag::_allocator_transform
            >
        >::template bind<T0,T1,T2,T3,T4,T5,T6>::type _template_args;
        typedef typename ::boost::parameter::value_type<
            _template_args,
            ::odds_and_ends::node::parameter::tag::_node_parent_generator_list
        >::type _npgl_t;
        typedef typename ::boost::parameter::value_type<
            _template_args,
            ::odds_and_ends::node::parameter::tag::_balancer
        >::type _balancer_t;
        typedef typename ::boost::parameter::value_type<
            _template_args,
            ::odds_and_ends::node::parameter::tag::_compare_generator,
            ::boost::mpl::quote1< ::std::less>
        >::type _compare_gen;
        typedef typename ::boost::parameter::value_type<
            _template_args,
            ::odds_and_ends::node::parameter::tag::_pointer_transform,
            ::boost::mpl::quote1< ::std::add_pointer>
        >::type _ptr_xform;
        typedef typename ::boost::parameter::value_type<
            _template_args,
            ::odds_and_ends::node::parameter::tag::_allocator_transform,
            ::boost::mpl::quote1< ::std::allocator>
        >::type _alloc_xform;

    public:
        typedef ::odds_and_ends::node::container
        ::map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6> type;
        typedef Key key_type;
        typedef Mapped mapped_type;
        typedef ::std::pair<key_type const,mapped_type> value_type;
        typedef value_type& reference;
        typedef value_type const& const_reference;
        typedef typename ::boost::parameter::value_type<
            _template_args,
            ::odds_and_ends::node::parameter::tag::_size,
            ::std::size_t
        >::type size_type;
        typedef typename ::boost::parameter::value_type<
            _template_args,
            ::odds_and_ends::node::parameter::tag::_difference,
            ::std::ptrdiff_t
        >::type difference_type;
        typedef typename ::boost::mpl::apply_wrap1<_compare_gen,key_type>::type key_compare;
        typedef typename ::boost::mpl::apply_wrap1<_ptr_xform,value_type>::type pointer;
        typedef typename ::boost::mpl
        ::apply_wrap1<_ptr_xform,value_type const>::type const_pointer;
        typedef ::odds_and_ends::composite_type::composite_type<
            typename ::boost::mpl::push_front<
                typename ::boost::mpl::push_front<
                    typename ::boost::mpl::push_front<
                        typename ::boost::mpl::push_front<
                            _npgl_t,
                            ::odds_and_ends::node::tree::with_size<size_type>
                        >::type,
                        ::odds_and_ends::node::tree::binary<difference_type>
                    >::type,
                    ::odds_and_ends::node::tree::base<_ptr_xform>
                >::type,
                ::odds_and_ends::node::data<value_type>
            >::type
        > node_type;
        typedef typename ::boost::mpl::apply_wrap1<_alloc_xform,node_type>::type allocator_type;

        class value_compare
        {
            key_compare _comp;

        protected:
            value_compare();
            explicit value_compare(key_compare const& comp);

        public:
            bool operator()(const_reference lhs, const_reference rhs) const;
            friend class map;
        };

    private:
        class _node_compare
        {
            key_compare const& _comp;

            explicit _node_compare(key_compare const& comp);

        public:
            template <typename K>
            bool operator()(K const& lhs, const_reference rhs) const;

            template <typename K>
            bool operator()(const_reference lhs, K const& rhs) const;

            bool operator()(key_type const& lhs, const_reference rhs) const;
            bool operator()(const_reference lhs, key_type const& rhs) const;
            friend class map;
        };

        typedef ::odds_and_ends::node
        ::in_order_tree_iterator<node_type,::boost::mpl::false_,difference_type> _itr_t;
        typedef ::odds_and_ends::node
        ::in_order_tree_iterator<node_type const,::boost::mpl::false_,difference_type> _c_itr_t;
        typedef ::odds_and_ends::node
        ::in_order_tree_iterator<node_type,::boost::mpl::true_,difference_type> _r_itr_t;
        typedef ::odds_and_ends::node
        ::in_order_tree_iterator<node_type const,::boost::mpl::true_,difference_type> _c_r_itr_t;

    public:
        typedef ::odds_and_ends::node::indirect_iterator<_itr_t,_ptr_xform> iterator;
        typedef ::odds_and_ends::node::indirect_iterator<_c_itr_t,_ptr_xform> const_iterator;
        typedef ::odds_and_ends::node::indirect_iterator<_r_itr_t,_ptr_xform> reverse_iterator;
        typedef ::odds_and_ends::node
        ::indirect_iterator<_c_r_itr_t,_ptr_xform> const_reverse_iterator;

    private:
        typedef typename node_type::traits::const_pointer _node_const_ptr_t;
        typedef typename node_type::traits::pointer _node_ptr_t;
        typedef typename ::boost::mpl
        ::if_<IsMulti,iterator,::std::pair<iterator,bool> >::type _insert_once_return_t;

        key_compare _comp;
        allocator_type _alloc;
        _node_ptr_t _root_ptr;

    public:
        template <typename Alloc>
        explicit map(
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename Alloc>
        map(
            key_compare const& comp,
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename Alloc>
        map(
            ::std::initializer_list<value_type> ilist,
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename Alloc>
        map(
            ::std::initializer_list<value_type> ilist,
            key_compare const& comp,
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename Alloc>
        map(
            map const& copy,
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename Alloc>
        map(
            map const& copy,
            key_compare const& comp,
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename Alloc>
        map(
            map&& source,
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename Alloc>
        map(
            map&& source,
            key_compare const& comp,
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        map();
        explicit map(key_compare const& comp);
        map(::std::initializer_list<value_type> ilist);
        map(::std::initializer_list<value_type> ilist, key_compare const& comp);
        map(map const& copy);
        map(map const& copy, key_compare const& comp);
        map(map&& source);
        map(map&& source, key_compare const& comp);
        ~map();
        map& operator=(::std::initializer_list<value_type> ilist);
        map& operator=(map const& copy);
        map& operator=(map&& source);
        key_compare key_comp() const;
        value_compare value_comp() const;
        allocator_type get_allocator() const;
        _node_const_ptr_t data() const;
        void clear();
        bool empty() const;
        size_type size() const;
        const_iterator cbegin() const;
        const_iterator begin() const;
        iterator begin();
        const_iterator cend() const;
        const_iterator end() const;
        iterator end();
        const_reverse_iterator crbegin() const;
        const_reverse_iterator rbegin() const;
        reverse_iterator rbegin();
        const_reverse_iterator crend() const;
        const_reverse_iterator rend() const;
        reverse_iterator rend();
        const_iterator find(key_type const& key) const;
        iterator find(key_type const& key);
        const_iterator lower_bound(key_type const& key) const;
        iterator lower_bound(key_type const& key);
        const_iterator upper_bound(key_type const& key) const;
        iterator upper_bound(key_type const& key);
        ::std::pair<const_iterator,const_iterator> equal_range(key_type const& key) const;
        ::std::pair<iterator,iterator> equal_range(key_type const& key);
        size_type count(key_type const& key) const;
        _insert_once_return_t insert(const_reference t);
        _insert_once_return_t insert(typename ::std::remove_reference<value_type>::type&& t);
        void insert(::std::initializer_list<value_type> ilist);
        iterator erase(const_iterator pos);
        iterator erase(const_iterator itr_begin, const_iterator itr_end);
        size_type erase(key_type const& key);
        void swap(map& other);

        template <typename K>
        const_iterator find(K const& key) const;

        template <typename K>
        iterator find(K const& key);

        template <typename K>
        const_iterator lower_bound(K const& key) const;

        template <typename K>
        iterator lower_bound(K const& key);

        template <typename K>
        const_iterator upper_bound(K const& key) const;

        template <typename K>
        iterator upper_bound(K const& key);

        template <typename K>
        ::std::pair<const_iterator,const_iterator> equal_range(K const& key) const;

        template <typename K>
        ::std::pair<iterator,iterator> equal_range(K const& key);

        template <typename K>
        size_type count(K const& key) const;

        template <typename ...Args>
        _insert_once_return_t emplace(Args&&... args);

        template <typename P>
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_runtime_pair<P>,
            _insert_once_return_t
        >::type
            insert(P&& t);

        template <typename Iterator>
        void insert(Iterator itr_begin, Iterator itr_end);

        template <typename K>
        typename ::boost::disable_if<
            ::std::is_convertible<K,const_iterator>,
            size_type
        >::type
            erase(K&& key);

        static size_type max_size();

    private:
        _node_const_ptr_t _back() const;
        _node_ptr_t _back();
        void _push_back(const_reference t);
        void _push_back(typename ::std::remove_reference<value_type>::type&& t);
        void _insert_before(_node_ptr_t n, _node_ptr_t p);
        ::std::pair<iterator,bool> _insert(const_reference t, ::boost::mpl::false_);
        ::std::pair<iterator,bool>
            _insert(typename ::std::remove_reference<value_type>::type&& t, ::boost::mpl::false_);
        iterator _insert(const_reference t, ::boost::mpl::true_);
        iterator
            _insert(typename ::std::remove_reference<value_type>::type&& t, ::boost::mpl::true_);

        template <typename ...Args>
        ::std::pair<iterator,bool> _emplace(::boost::mpl::false_, Args&&... args);

        template <typename ...Args>
        iterator _emplace(::boost::mpl::true_, Args&&... args);

        template <typename Iterator>
        void _copy_from(Iterator itr_begin, Iterator itr_end);
    };
}}}  // namespace odds_and_ends::node::container

#include <tuple>
#include <iterator>
#include <odds_and_ends/node/iterator/breadth_first_tree.hpp>
#include <odds_and_ends/node/iterator/post_order_tree.hpp>
#include <odds_and_ends/node/algorithm/add_distance.hpp>
#include <odds_and_ends/node/algorithm/binary_tree_descendant.hpp>
#include <odds_and_ends/node/algorithm/binary_tree_lower_bound.hpp>
#include <odds_and_ends/node/algorithm/binary_tree_upper_bound.hpp>
#include <odds_and_ends/node/algorithm/is_ancestor_of.hpp>
#include <odds_and_ends/node/algorithm/increment_in_binary_tree.hpp>
#include <boost/utility/value_init.hpp>
#include <boost/assert.hpp>

namespace odds_and_ends { namespace node { namespace container {

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::value_compare::value_compare() : _comp()
    {
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::value_compare::value_compare(
        key_compare const& comp
    ) : _comp(comp)
    {
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline bool
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::value_compare::operator()(
            const_reference lhs,
            const_reference rhs
        ) const
    {
        return this->_comp(lhs.first, rhs.first);
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::_node_compare::_node_compare(
        key_compare const& comp
    ) : _comp(comp)
    {
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline bool
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::_node_compare::operator()(
            key_type const& lhs,
            const_reference rhs
        ) const
    {
        return this->_comp(lhs, rhs.first);
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename K>
    inline bool
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::_node_compare::operator()(
            K const& lhs,
            const_reference rhs
        ) const
    {
        return this->_comp(lhs, rhs.first);
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline bool
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::_node_compare::operator()(
            const_reference lhs,
            key_type const& rhs
        ) const
    {
        return this->_comp(lhs.first, rhs);
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename K>
    inline bool
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::_node_compare::operator()(
            const_reference lhs,
            K const& rhs
        ) const
    {
        return this->_comp(lhs.first, rhs);
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::map() :
        _comp(), _alloc(), _root_ptr(nullptr)
    {
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::map(key_compare const& comp) :
        _comp(comp), _alloc(), _root_ptr(nullptr)
    {
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename Alloc>
    inline map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::map(
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _comp(), _alloc(alloc), _root_ptr(nullptr)
    {
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename Alloc>
    inline map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::map(
        key_compare const& comp,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _comp(comp), _alloc(alloc), _root_ptr(nullptr)
    {
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::map(::std::initializer_list<value_type> ilist) :
        _comp(), _alloc(), _root_ptr(nullptr)
    {
        for (
            typename ::std::initializer_list<value_type>::iterator itr = ilist.begin();
            itr != ilist.end();
            ++itr
        )
        {
            this->_insert(*itr, IsMulti());
        }
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::map(
        ::std::initializer_list<value_type> ilist,
        key_compare const& comp
    ) : _comp(comp), _alloc(), _root_ptr(nullptr)
    {
        for (
            typename ::std::initializer_list<value_type>::iterator itr = ilist.begin();
            itr != ilist.end();
            ++itr
        )
        {
            this->_insert(*itr, IsMulti());
        }
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename Alloc>
    map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::map(
        ::std::initializer_list<value_type> ilist,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _comp(), _alloc(alloc), _root_ptr(nullptr)
    {
        for (
            typename ::std::initializer_list<value_type>::iterator itr = ilist.begin();
            itr != ilist.end();
            ++itr
        )
        {
            this->_insert(*itr, IsMulti());
        }
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename Alloc>
    map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::map(
        ::std::initializer_list<value_type> ilist,
        key_compare const& comp,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _comp(comp), _alloc(alloc), _root_ptr(nullptr)
    {
        for (
            typename ::std::initializer_list<value_type>::iterator itr = ilist.begin();
            itr != ilist.end();
            ++itr
        )
        {
            this->_insert(*itr, IsMulti());
        }
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename Iterator>
    void map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::_copy_from(Iterator itr, Iterator itr_end)
    {
        for (; itr != itr_end; ++itr)
        {
            this->_insert(*itr, IsMulti());
        }
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::map(map const& copy) :
        _comp(copy._comp), _alloc(copy._alloc), _root_ptr(nullptr)
    {
        this->_copy_from(copy.cbegin(), copy.cend());
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::map(
        map const& copy,
        key_compare const& comp
    ) : _comp(comp), _alloc(copy._alloc), _root_ptr(nullptr)
    {
        this->_copy_from(copy.cbegin(), copy.cend());
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename Alloc>
    inline map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::map(
        map const& copy,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _comp(copy._comp), _alloc(alloc), _root_ptr(nullptr)
    {
        this->_copy_from(copy.cbegin(), copy.cend());
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename Alloc>
    inline map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::map(
        map const& copy,
        key_compare const& comp,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _comp(comp), _alloc(alloc), _root_ptr(nullptr)
    {
        this->_copy_from(copy.cbegin(), copy.cend());
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::map(map&& source) :
        _comp(source._comp), _alloc(source._alloc), _root_ptr(source._root_ptr)
    {
        source._root_ptr = nullptr;
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::map(
        map&& source,
        key_compare const& comp
    ) : _comp(comp), _alloc(source._alloc), _root_ptr(source._root_ptr)
    {
        source._root_ptr = nullptr;
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename Alloc>
    inline map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::map(
        map&& source,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _comp(source._comp), _alloc(alloc), _root_ptr(source._root_ptr)
    {
        source._root_ptr = nullptr;
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename Alloc>
    inline map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::map(
        map&& source,
        key_compare const& comp,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _comp(comp), _alloc(alloc), _root_ptr(source._root_ptr)
    {
        source._root_ptr = nullptr;
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    void map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::clear()
    {
        if (this->_root_ptr)
        {
            for (
                ::odds_and_ends::node::post_order_tree_iterator<node_type> itr(*this->_root_ptr);
                !(!itr);
                ++itr
            )
            {
                if (itr->left())
                {
                    ::std::allocator_traits<allocator_type>::destroy(this->_alloc, itr->left());
                    ::std::allocator_traits<allocator_type>::deallocate(
                        this->_alloc,
                        itr->left(),
                        1
                    );
                }

                if (itr->right())
                {
                    ::std::allocator_traits<allocator_type>::destroy(this->_alloc, itr->right());
                    ::std::allocator_traits<allocator_type>::deallocate(
                        this->_alloc,
                        itr->right(),
                        1
                    );
                }
            }

            ::std::allocator_traits<allocator_type>::destroy(this->_alloc, this->_root_ptr);
            ::std::allocator_traits<allocator_type>::deallocate(this->_alloc, this->_root_ptr, 1);
            this->_root_ptr = nullptr;
        }
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::~map()
    {
        this->clear();
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>&
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::operator=(map const& copy)
    {
        if (this != &copy)
        {
            this->clear();
            this->_copy_from(copy.cbegin(), copy.cend());
        }

        return *this;
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>&
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::operator=(map&& source)
    {
        if (this != &static_cast<map&>(source))
        {
            this->clear();
            this->_root_ptr = source._root_ptr;
            source._root_ptr = nullptr;
        }

        return *this;
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>&
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::operator=(
            ::std::initializer_list<value_type> ilist
        )
    {
        this->clear();

        for (
            typename ::std::initializer_list<value_type>::iterator itr = ilist.begin();
            itr != ilist.end();
            ++itr
        )
        {
            this->_insert(*itr, IsMulti());
        }

        return *this;
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    void map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::swap(map& other)
    {
        using ::std::swap;
        swap(this->_root_ptr, other._root_ptr);
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline void
        swap(
            map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>& lhs,
            map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>& rhs
        )
    {
        lhs.swap(rhs);
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::key_compare
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::key_comp() const
    {
        return this->_comp;
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::value_compare
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::value_comp() const
    {
        return value_compare(this->_comp);
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::allocator_type
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::get_allocator() const
    {
        return this->_alloc;
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline bool map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::empty() const
    {
        return !this->_root_ptr;
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::size_type
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::size() const
    {
        static size_type const z = ::boost::initialized_value;
        return this->_root_ptr ? this->_root_ptr->size() : z;
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::size_type
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::max_size()
    {
        return (::std::numeric_limits<size_type>::max)();
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::_node_const_ptr_t
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::data() const
    {
        return this->_root_ptr;
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::const_iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::cbegin() const
    {
        return this->_root_ptr ? const_iterator(
            ::odds_and_ends::node
            ::make_in_order_tree_iterator_begin<difference_type>(*this->_root_ptr)
        ) : this->cend();
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::const_iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::begin() const
    {
        return this->_root_ptr ? const_iterator(
            ::odds_and_ends::node
            ::make_in_order_tree_iterator_begin<difference_type>(*this->_root_ptr)
        ) : this->end();
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::begin()
    {
        return this->_root_ptr ? iterator(
            ::odds_and_ends::node
            ::make_in_order_tree_iterator_begin<difference_type>(*this->_root_ptr)
        ) : this->end();
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::const_iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::cend() const
    {
        return this->_root_ptr ? const_iterator(
            ::odds_and_ends::node
            ::make_in_order_tree_iterator_end<difference_type>(*this->_root_ptr)
        ) : const_iterator();
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::const_iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::end() const
    {
        return this->_root_ptr ? const_iterator(
            ::odds_and_ends::node
            ::make_in_order_tree_iterator_end<difference_type>(*this->_root_ptr)
        ) : const_iterator();
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::end()
    {
        return this->_root_ptr ? iterator(
            ::odds_and_ends::node
            ::make_in_order_tree_iterator_end<difference_type>(*this->_root_ptr)
        ) : iterator();
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::const_reverse_iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::crbegin() const
    {
        return this->_root_ptr ? const_reverse_iterator(
            ::odds_and_ends::node::make_in_order_tree_reverse_iterator_begin<difference_type>(
                *this->_root_ptr
            )
        ) : this->crend();
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::const_reverse_iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::rbegin() const
    {
        return this->_root_ptr ? const_reverse_iterator(
            ::odds_and_ends::node::make_in_order_tree_reverse_iterator_begin<difference_type>(
                *this->_root_ptr
            )
        ) : this->rend();
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::reverse_iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::rbegin()
    {
        return this->_root_ptr ? reverse_iterator(
            ::odds_and_ends::node::make_in_order_tree_reverse_iterator_begin<difference_type>(
                *this->_root_ptr
            )
        ) : this->rend();
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::const_reverse_iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::crend() const
    {
        return this->_root_ptr ? const_reverse_iterator(
            ::odds_and_ends::node::make_in_order_tree_reverse_iterator_end<difference_type>(
                *this->_root_ptr
            )
        ) : const_reverse_iterator();
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::const_reverse_iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::rend() const
    {
        return this->_root_ptr ? const_reverse_iterator(
            ::odds_and_ends::node::make_in_order_tree_reverse_iterator_end<difference_type>(
                *this->_root_ptr
            )
        ) : const_reverse_iterator();
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::reverse_iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::rend()
    {
        return this->_root_ptr ? reverse_iterator(
            ::odds_and_ends::node::make_in_order_tree_reverse_iterator_end<difference_type>(
                *this->_root_ptr
            )
        ) : reverse_iterator();
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::const_iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::find(key_type const& key) const
    {
        _node_const_ptr_t node_ptr = ::odds_and_ends::node::algorithm::binary_tree_descendant(
            this->_root_ptr,
            key,
            _node_compare(this->_comp)
        );
        return node_ptr ? const_iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_position<difference_type>(*node_ptr)
        ) : this->cend();
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename K>
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::const_iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::find(K const& key) const
    {
        _node_const_ptr_t node_ptr = ::odds_and_ends::node::algorithm::binary_tree_descendant(
            this->_root_ptr,
            key,
            _node_compare(this->_comp)
        );
        return node_ptr ? const_iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_position<difference_type>(*node_ptr)
        ) : this->cend();
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::find(key_type const& key)
    {
        _node_ptr_t node_ptr = ::odds_and_ends::node::algorithm::binary_tree_descendant(
            this->_root_ptr,
            key,
            _node_compare(this->_comp)
        );
        return node_ptr ? iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_position<difference_type>(*node_ptr)
        ) : this->end();
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename K>
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::find(K const& key)
    {
        _node_ptr_t node_ptr = ::odds_and_ends::node::algorithm::binary_tree_descendant(
            this->_root_ptr,
            key,
            _node_compare(this->_comp)
        );
        return node_ptr ? iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_position<difference_type>(*node_ptr)
        ) : this->end();
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::const_iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::lower_bound(key_type const& key) const
    {
        _node_const_ptr_t node_ptr = ::odds_and_ends::node::algorithm::binary_tree_lower_bound(
            this->_root_ptr,
            key,
            _node_compare(this->_comp)
        );
        return node_ptr ? const_iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_position<difference_type>(*node_ptr)
        ) : this->upper_bound(key);
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename K>
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::const_iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::lower_bound(K const& key) const
    {
        _node_const_ptr_t node_ptr = ::odds_and_ends::node::algorithm::binary_tree_lower_bound(
            this->_root_ptr,
            key,
            _node_compare(this->_comp)
        );
        return node_ptr ? const_iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_position<difference_type>(*node_ptr)
        ) : this->upper_bound(key);
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::lower_bound(key_type const& key)
    {
        _node_ptr_t node_ptr = ::odds_and_ends::node::algorithm::binary_tree_lower_bound(
            this->_root_ptr,
            key,
            _node_compare(this->_comp)
        );
        return node_ptr ? iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_position<difference_type>(*node_ptr)
        ) : this->upper_bound(key);
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename K>
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::lower_bound(K const& key)
    {
        _node_ptr_t node_ptr = ::odds_and_ends::node::algorithm::binary_tree_lower_bound(
            this->_root_ptr,
            key,
            _node_compare(this->_comp)
        );
        return node_ptr ? iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_position<difference_type>(*node_ptr)
        ) : this->upper_bound(key);
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::const_iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::upper_bound(key_type const& key) const
    {
        _node_const_ptr_t node_ptr = ::odds_and_ends::node::algorithm::binary_tree_upper_bound(
            this->_root_ptr,
            key,
            _node_compare(this->_comp)
        );
        return node_ptr ? const_iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_position<difference_type>(*node_ptr)
        ) : this->cend();
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename K>
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::const_iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::upper_bound(K const& key) const
    {
        _node_const_ptr_t node_ptr = ::odds_and_ends::node::algorithm::binary_tree_upper_bound(
            this->_root_ptr,
            key,
            _node_compare(this->_comp)
        );
        return node_ptr ? const_iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_position<difference_type>(*node_ptr)
        ) : this->cend();
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::upper_bound(key_type const& key)
    {
        _node_ptr_t node_ptr = ::odds_and_ends::node::algorithm::binary_tree_upper_bound(
            this->_root_ptr,
            key,
            _node_compare(this->_comp)
        );
        return node_ptr ? iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_position<difference_type>(*node_ptr)
        ) : this->end();
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename K>
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::upper_bound(K const& key)
    {
        _node_ptr_t node_ptr = ::odds_and_ends::node::algorithm::binary_tree_upper_bound(
            this->_root_ptr,
            key,
            _node_compare(this->_comp)
        );
        return node_ptr ? iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_position<difference_type>(*node_ptr)
        ) : this->end();
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline ::std::pair<
        typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::const_iterator,
        typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::const_iterator
    >
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::equal_range(key_type const& key) const
    {
        return ::std::make_pair(this->lower_bound(key), this->upper_bound(key));
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename K>
    inline ::std::pair<
        typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::const_iterator,
        typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::const_iterator
    >
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::equal_range(K const& key) const
    {
        return ::std::make_pair(this->lower_bound(key), this->upper_bound(key));
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline ::std::pair<
        typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::iterator,
        typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::iterator
    >
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::equal_range(key_type const& key)
    {
        return ::std::make_pair(this->lower_bound(key), this->upper_bound(key));
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename K>
    inline ::std::pair<
        typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::iterator,
        typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::iterator
    >
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::equal_range(K const& key)
    {
        return ::std::make_pair(this->lower_bound(key), this->upper_bound(key));
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::size_type
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::count(key_type const& key) const
    {
        return this->upper_bound(key) - this->lower_bound(key);
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename K>
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::size_type
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::count(K const& key) const
    {
        return this->upper_bound(key) - this->lower_bound(key);
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::_node_const_ptr_t
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::_back() const
    {
        return ::odds_and_ends::node::algorithm::decrement_in_binary_tree(
            static_cast<_node_const_ptr_t>(nullptr),
            this->_root_ptr
        );
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::_node_ptr_t
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::_back()
    {
        return ::odds_and_ends::node::algorithm::decrement_in_binary_tree(
            static_cast<_node_ptr_t>(nullptr),
            this->_root_ptr
        );
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    void map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::_push_back(const_reference t)
    {
        if (this->_root_ptr)
        {
            _node_ptr_t p = this->_back();
            _node_ptr_t n = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);

            ::std::allocator_traits<allocator_type>::construct(this->_alloc, n, t);
            p->set_right_ptr(n);
            p = _balancer_t::post_insert(*n);

            if (!p->parent())
            {
                this->_root_ptr = p;
            }
        }
        else  // if (!this->_root_ptr)
        {
            this->_root_ptr = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);
            ::std::allocator_traits<allocator_type>::construct(this->_alloc, this->_root_ptr, t);
            _balancer_t::post_fill(*this->_root_ptr);
        }
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    void
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::_push_back(
            typename ::std::remove_reference<value_type>::type&& t
        )
    {
        if (this->_root_ptr)
        {
            _node_ptr_t p = this->_back();
            _node_ptr_t n = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);

            ::std::allocator_traits<allocator_type>::construct(this->_alloc, n, ::std::move(t));
            p->set_right_ptr(n);
            p = _balancer_t::post_insert(*n);

            if (!p->parent())
            {
                this->_root_ptr = p;
            }
        }
        else  // if (!this->_root_ptr)
        {
            this->_root_ptr = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);
            ::std::allocator_traits<allocator_type>::construct(
                this->_alloc,
                this->_root_ptr,
                ::std::move(t)
            );
            _balancer_t::post_fill(*this->_root_ptr);
        }
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    void map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::_insert_before(_node_ptr_t n, _node_ptr_t p)
    {
        if (p->left())
        {
            for (p = p->left(); p->right(); p = p->right())
            {
            }

            p->set_right_ptr(n);
        }
        else
        {
            p->set_left_ptr(n);
        }

        p = _balancer_t::post_insert(*n);

        if (!p->parent())
        {
            this->_root_ptr = p;
        }
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::_insert(
            const_reference t,
            ::boost::mpl::true_
        )
    {
        _node_ptr_t p = ::odds_and_ends::node::algorithm::binary_tree_upper_bound(
            this->_root_ptr,
            t,
            value_compare(this->_comp)
        );

        if (p)
        {
            _node_ptr_t n = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);

            ::std::allocator_traits<allocator_type>::construct(this->_alloc, n, t);
            this->_insert_before(n, p);
            return iterator(
                ::odds_and_ends::node::make_in_order_tree_iterator_position<difference_type>(*n)
            );
        }
        else
        {
            this->_push_back(t);
            iterator result = this->end();
            return --result;
        }
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::_insert(
            typename ::std::remove_reference<value_type>::type&& t,
            ::boost::mpl::true_
        )
    {
        _node_ptr_t p = ::odds_and_ends::node::algorithm::binary_tree_upper_bound(
            this->_root_ptr,
            t.first,
            _node_compare(this->_comp)
        );

        if (p)
        {
            _node_ptr_t n = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);

            ::std::allocator_traits<allocator_type>::construct(this->_alloc, n, ::std::move(t));
            this->_insert_before(n, p);
            return iterator(
                ::odds_and_ends::node::make_in_order_tree_iterator_position<difference_type>(*n)
            );
        }
        else
        {
            this->_push_back(::std::move(t));
            iterator result = this->end();
            return --result;
        }
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename ...Args>
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::_emplace(::boost::mpl::true_, Args&&... args)
    {
        value_type t(::std::forward<Args>(args)...);
        _node_ptr_t p = ::odds_and_ends::node::algorithm::binary_tree_upper_bound(
            this->_root_ptr,
            t,
            value_compare(this->_comp)
        );

        if (p)
        {
            _node_ptr_t n = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);

            ::std::allocator_traits<allocator_type>::construct(this->_alloc, n, t);
            this->_insert_before(n, p);
            return iterator(
                ::odds_and_ends::node::make_in_order_tree_iterator_position<difference_type>(*n)
            );
        }
        else
        {
            this->_push_back(t);
            iterator result = this->end();
            return --result;
        }
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline ::std::pair<
        typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::iterator,
        bool
    >
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::_insert(
            const_reference t,
            ::boost::mpl::false_
        )
    {
        _node_ptr_t p = ::odds_and_ends::node::algorithm::binary_tree_descendant(
            this->_root_ptr,
            t,
            value_compare(this->_comp)
        );

        if (p)
        {
            return ::std::make_pair(
                iterator(
                    ::odds_and_ends::node
                    ::make_in_order_tree_iterator_position<difference_type>(*p)
                ),
                false
            );
        }

        p = ::odds_and_ends::node::algorithm::binary_tree_upper_bound(
            this->_root_ptr,
            t,
            value_compare(this->_comp)
        );

        if (p)
        {
            _node_ptr_t n = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);

            ::std::allocator_traits<allocator_type>::construct(this->_alloc, n, t);
            this->_insert_before(n, p);
            return ::std::make_pair(
                iterator(
                    ::odds_and_ends::node
                    ::make_in_order_tree_iterator_position<difference_type>(*n)
                ),
                true
            );
        }
        else
        {
            this->_push_back(t);
            iterator result = this->end();
            return ::std::make_pair(--result, true);
        }
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline ::std::pair<
        typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::iterator,
        bool
    >
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::_insert(
            typename ::std::remove_reference<value_type>::type&& t,
            ::boost::mpl::false_
        )
    {
        _node_ptr_t p = ::odds_and_ends::node::algorithm::binary_tree_descendant(
            this->_root_ptr,
            t.first,
            _node_compare(this->_comp)
        );

        if (p)
        {
            return ::std::make_pair(
                iterator(
                    ::odds_and_ends::node
                    ::make_in_order_tree_iterator_position<difference_type>(*p)
                ),
                false
            );
        }

        p = ::odds_and_ends::node::algorithm::binary_tree_upper_bound(
            this->_root_ptr,
            t.first,
            _node_compare(this->_comp)
        );

        if (p)
        {
            _node_ptr_t n = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);

            ::std::allocator_traits<allocator_type>::construct(this->_alloc, n, ::std::move(t));
            this->_insert_before(n, p);
            return ::std::make_pair(
                iterator(
                    ::odds_and_ends::node
                    ::make_in_order_tree_iterator_position<difference_type>(*n)
                ),
                true
            );
        }
        else
        {
            this->_push_back(::std::move(t));
            iterator result = this->end();
            return ::std::make_pair(--result, true);
        }
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename ...Args>
    inline ::std::pair<
        typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::iterator,
        bool
    >
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::_emplace(
            ::boost::mpl::false_,
            Args&&... args
        )
    {
        value_type t(::std::forward<Args>(args)...);
        _node_ptr_t p = ::odds_and_ends::node::algorithm::binary_tree_descendant(
            this->_root_ptr,
            t,
            value_compare(this->_comp)
        );

        if (p)
        {
            return ::std::make_pair(
                iterator(
                    ::odds_and_ends::node
                    ::make_in_order_tree_iterator_position<difference_type>(*p)
                ),
                false
            );
        }

        p = ::odds_and_ends::node::algorithm::binary_tree_upper_bound(
            this->_root_ptr,
            t,
            value_compare(this->_comp)
        );

        if (p)
        {
            _node_ptr_t n = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);

            ::std::allocator_traits<allocator_type>::construct(this->_alloc, n, t);
            this->_insert_before(n, p);
            return ::std::make_pair(
                iterator(
                    ::odds_and_ends::node
                    ::make_in_order_tree_iterator_position<difference_type>(*n)
                ),
                true
            );
        }
        else
        {
            this->_push_back(t);
            iterator result = this->end();
            return ::std::make_pair(--result, true);
        }
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::_insert_once_return_t
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::insert(const_reference t)
    {
        return this->_insert(t, IsMulti());
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::_insert_once_return_t
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::insert(
            typename ::std::remove_reference<value_type>::type&& t
        )
    {
        return this->_insert(::std::move(t), IsMulti());
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename ...Args>
    inline typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::_insert_once_return_t
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::emplace(Args&&... args)
    {
        return this->_emplace(IsMulti(), ::std::forward<Args>(args)...);
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename P>
    inline typename ::boost::enable_if<
        ::odds_and_ends::static_introspection::concept::is_runtime_pair<P>,
        typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::_insert_once_return_t
    >::type
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::insert(P&& t)
    {
        return this->_emplace(IsMulti(), ::std::forward<P>(t));
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename Iterator>
    void map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::insert(Iterator itr, Iterator itr_end)
    {
        for (; itr != itr_end; ++itr)
        {
            this->_emplace(IsMulti(), *itr);
        }
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    void
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::insert(
            ::std::initializer_list<value_type> ilist
        )
    {
        for (
            typename ::std::initializer_list<value_type>::iterator itr = ilist.begin();
            itr != ilist.end();
            ++itr
        )
        {
            this->_insert(*itr, IsMulti());
        }
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::erase(const_iterator pos)
    {
        BOOST_ASSERT(pos != this->cend());

        _node_ptr_t node_ptr = const_cast<_node_ptr_t>(
            ::std::pointer_traits<_node_const_ptr_t>::pointer_to(*pos.base())
        );

        BOOST_ASSERT_MSG(this->_root_ptr, "This container cannot be empty!");
        BOOST_ASSERT_MSG(
            ::odds_and_ends::node::algorithm::is_ancestor_of(this->_root_ptr, node_ptr),
            "The iterator does not point to any element in this container!"
        );

        ::std::tuple<_node_ptr_t,_node_ptr_t,_node_ptr_t> sep_result = _balancer_t::separate(
            *node_ptr
        );

        ::std::allocator_traits<allocator_type>::destroy(this->_alloc, ::std::get<0>(sep_result));
        ::std::allocator_traits<
            allocator_type
        >::deallocate(this->_alloc, ::std::get<0>(sep_result), 1);
        this->_root_ptr = ::std::get<2>(sep_result);
        return ::std::get<1>(sep_result) ? iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_position<difference_type>(
                *::std::get<1>(sep_result)
            )
        ) : this->end();
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::iterator
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::erase(
            const_iterator itr,
            const_iterator itr_end
        )
    {
        iterator result = this->end();

        if (itr_end != this->cend())
        {
            result = iterator(
                ::odds_and_ends::node::make_in_order_tree_iterator_position<difference_type>(
                    const_cast<node_type&>(*itr_end.base())
                )
            );
        }

        for (; itr != itr_end; itr = result)
        {
            result = this->erase(itr);
        }

        return result;
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::size_type
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::erase(key_type const& key)
    {
        ::std::tuple<_node_ptr_t,_node_ptr_t,_node_ptr_t> sep_result;
        _node_ptr_t end_ptr = ::odds_and_ends::node::algorithm::binary_tree_upper_bound(
            this->_root_ptr,
            key,
            _node_compare(this->_comp)
        );
        size_type result = ::boost::initialized_value;

        for (
            _node_ptr_t node_ptr = ::odds_and_ends::node::algorithm::binary_tree_lower_bound(
                this->_root_ptr,
                key,
                _node_compare(this->_comp)
            );
            node_ptr != end_ptr;
            node_ptr = ::std::get<1>(sep_result)
        )
        {
            sep_result = _balancer_t::separate(*node_ptr);
            ::std::allocator_traits<
                allocator_type
            >::destroy(this->_alloc, ::std::get<0>(sep_result));
            ::std::allocator_traits<
                allocator_type
            >::deallocate(this->_alloc, ::std::get<0>(sep_result), 1);
            this->_root_ptr = ::std::get<2>(sep_result);
            ++result;
        }

        return result;
    }

    template <
        typename Key,
        typename Mapped,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename K>
    typename ::boost::disable_if<
        ::std::is_convertible<
            K,
            typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::const_iterator
        >,
        typename map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::size_type
    >::type
        map<Key,Mapped,IsMulti,T0,T1,T2,T3,T4,T5,T6>::erase(K&& key)
    {
        ::std::tuple<_node_ptr_t,_node_ptr_t,_node_ptr_t> sep_result;
        _node_ptr_t end_ptr = ::odds_and_ends::node::algorithm::binary_tree_upper_bound(
            this->_root_ptr,
            ::std::forward<K>(key),
            _node_compare(this->_comp)
        );
        size_type result = ::boost::initialized_value;

        for (
            _node_ptr_t node_ptr = ::odds_and_ends::node::algorithm::binary_tree_lower_bound(
                this->_root_ptr,
                ::std::forward<K>(key),
                _node_compare(this->_comp)
            );
            node_ptr != end_ptr;
            node_ptr = ::std::get<1>(sep_result)
        )
        {
            sep_result = _balancer_t::separate(*node_ptr);
            ::std::allocator_traits<
                allocator_type
            >::destroy(this->_alloc, ::std::get<0>(sep_result));
            ::std::allocator_traits<
                allocator_type
            >::deallocate(this->_alloc, ::std::get<0>(sep_result), 1);
            this->_root_ptr = ::std::get<2>(sep_result);
            ++result;
        }

        return result;
    }
}}}  // namespace odds_and_ends::node::container

#endif  // ODDS_AND_ENDS__NODE__CONTAINER__MAP_HPP

