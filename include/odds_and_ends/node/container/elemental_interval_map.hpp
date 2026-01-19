// Copyright (C) 2025-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__CONTAINER__ELEMENTAL_INTERVAL_MAP_HPP
#define ODDS_AND_ENDS__NODE__CONTAINER__ELEMENTAL_INTERVAL_MAP_HPP

#include <type_traits>
#include <functional>
#include <utility>
#include <vector>
#include <initializer_list>
#include <odds_and_ends/static_introspection/concept/is_allocator.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_input_iterator.hpp>
#include <odds_and_ends/static_introspection/concept/is_indexable_container.hpp>
#include <odds_and_ends/use_default_policy.hpp>
//#include <boost/numeric/interval.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/assert.hpp>

namespace odds_and_ends { namespace node { namespace container {

    template <
        typename Key,
        typename Mapped,
        typename Compare = ::std::less<Key>,
        typename ContainerGen = ::odds_and_ends::use_default_policy
    >
    class elemental_interval_map
    {
        struct _enabler
        {
        };

    public:
        typedef ::odds_and_ends::node::container
        ::elemental_interval_map<Key,Mapped,Compare,ContainerGen> type;
        typedef Key key_type;
        typedef Mapped mapped_type;
        typedef Compare key_compare;

        class interval_type
        {
            key_type _l;
            key_type _u;

        public:
            interval_type();
            interval_type(key_type const& l, key_type const& u);
            key_type const& lower() const;
            key_type const& upper() const;
        };

//        typedef ::boost::numeric::interval<Key> interval_type;
        typedef ::std::pair<interval_type,mapped_type> value_type;
        typedef value_type const& const_reference;
        typedef const_reference reference;

        class value_compare
        {
            key_compare _comp;

        protected:
            value_compare();
            explicit value_compare(key_compare const& comp);

        public:
            bool operator()(const_reference lhs, const_reference rhs) const;
        };

    private:
        typedef typename ::boost::mpl::eval_if<
            ::std::is_same<ContainerGen,::odds_and_ends::use_default_policy>,
            ::boost::mpl::identity< ::std::vector<value_type> >,
            ::boost::mpl::apply_wrap1<ContainerGen,value_type>
        >::type _container_type;

        BOOST_MPL_ASSERT((
            ::odds_and_ends::static_introspection::concept::is_indexable_container<_container_type>
        ));

        key_compare _comp;
        _container_type _container;

    public:
        typedef typename _container_type::const_pointer const_pointer;
        typedef const_pointer pointer;
        typedef typename _container_type::const_iterator const_iterator;
        typedef const_iterator iterator;
        typedef typename _container_type::const_reverse_iterator const_reverse_iterator;
        typedef const_reverse_iterator reverse_iterator;
        typedef typename _container_type::size_type size_type;

        template <typename Alloc>
        explicit elemental_interval_map(
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename Alloc>
        elemental_interval_map(
            key_compare const& comp,
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename Alloc>
        elemental_interval_map(
            elemental_interval_map const& copy,
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename Alloc>
        elemental_interval_map(
            elemental_interval_map const& copy,
            key_compare const& comp,
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename K, typename M, typename C, typename G>
        elemental_interval_map(
            elemental_interval_map<K,M,C,G> const& copy,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::std::is_convertible<K,Key>,
                    ::std::is_convertible<M,Mapped>,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename K, typename M, typename C, typename G>
        elemental_interval_map(
            elemental_interval_map<K,M,C,G> const& copy,
            key_compare const& comp,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::std::is_convertible<K,Key>,
                    ::std::is_convertible<M,Mapped>,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename K, typename M, typename C, typename G, typename Alloc>
        elemental_interval_map(
            elemental_interval_map<K,M,C,G> const& copy,
            Alloc const& alloc,
            typename ::boost::enable_if<
                typename ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                    ::boost::mpl::if_<
                        ::std::is_convertible<K,Key>,
                        ::std::is_convertible<M,Mapped>,
                        ::boost::mpl::false_
                    >,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename K, typename M, typename C, typename G, typename Alloc>
        elemental_interval_map(
            elemental_interval_map<K,M,C,G> const& copy,
            key_compare const& comp,
            Alloc const& alloc,
            typename ::boost::enable_if<
                typename ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                    ::boost::mpl::if_<
                        ::std::is_convertible<K,Key>,
                        ::std::is_convertible<M,Mapped>,
                        ::boost::mpl::false_
                    >,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename Alloc>
        elemental_interval_map(
            elemental_interval_map&& source,
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename Alloc>
        elemental_interval_map(
            elemental_interval_map&& source,
            key_compare const& comp,
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename KeyIterator, typename ValueIterator>
        elemental_interval_map(
            KeyIterator key_itr_begin,
            KeyIterator key_itr_end,
            ValueIterator value_itr_begin,
            ValueIterator value_itr_end,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection::concept
                    ::is_legacy_input_iterator<KeyIterator>,
                    ::odds_and_ends::static_introspection::concept
                    ::is_legacy_input_iterator<ValueIterator>,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename KeyIterator, typename ValueIterator>
        elemental_interval_map(
            KeyIterator key_itr_begin,
            KeyIterator key_itr_end,
            ValueIterator value_itr_begin,
            ValueIterator value_itr_end,
            key_compare const& comp,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection::concept
                    ::is_legacy_input_iterator<KeyIterator>,
                    ::odds_and_ends::static_introspection::concept
                    ::is_legacy_input_iterator<ValueIterator>,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename KeyIterator, typename ValueIterator, typename Alloc>
        elemental_interval_map(
            KeyIterator key_itr_begin,
            KeyIterator key_itr_end,
            ValueIterator value_itr_begin,
            ValueIterator value_itr_end,
            Alloc const& alloc,
            typename ::boost::enable_if<
                typename ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                    ::boost::mpl::if_<
                        ::odds_and_ends::static_introspection::concept
                        ::is_legacy_input_iterator<KeyIterator>,
                        ::odds_and_ends::static_introspection::concept
                        ::is_legacy_input_iterator<ValueIterator>,
                        ::boost::mpl::false_
                    >,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename KeyIterator, typename ValueIterator, typename Alloc>
        elemental_interval_map(
            KeyIterator key_itr_begin,
            KeyIterator key_itr_end,
            ValueIterator value_itr_begin,
            ValueIterator value_itr_end,
            key_compare const& comp,
            Alloc const& alloc,
            typename ::boost::enable_if<
                typename ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                    ::boost::mpl::if_<
                        ::odds_and_ends::static_introspection::concept
                        ::is_legacy_input_iterator<KeyIterator>,
                        ::odds_and_ends::static_introspection::concept
                        ::is_legacy_input_iterator<ValueIterator>,
                        ::boost::mpl::false_
                    >,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename K, typename M>
        elemental_interval_map(
            ::std::initializer_list<K> keys,
            ::std::initializer_list<M> values,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::std::is_convertible<K,key_type>,
                    ::std::is_convertible<M,mapped_type>,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename K, typename M>
        elemental_interval_map(
            ::std::initializer_list<K> keys,
            ::std::initializer_list<M> values,
            key_compare const& comp,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::std::is_convertible<K,key_type>,
                    ::std::is_convertible<M,mapped_type>,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename K, typename M, typename Alloc>
        elemental_interval_map(
            ::std::initializer_list<K> keys,
            ::std::initializer_list<M> values,
            Alloc const& alloc,
            typename ::boost::enable_if<
                typename ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                    ::boost::mpl::if_<
                        ::std::is_convertible<K,key_type>,
                        ::std::is_convertible<M,mapped_type>,
                        ::boost::mpl::false_
                    >,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename K, typename M, typename Alloc>
        elemental_interval_map(
            ::std::initializer_list<K> keys,
            ::std::initializer_list<M> values,
            key_compare const& comp,
            Alloc const& alloc,
            typename ::boost::enable_if<
                typename ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                    ::boost::mpl::if_<
                        ::std::is_convertible<K,key_type>,
                        ::std::is_convertible<M,mapped_type>,
                        ::boost::mpl::false_
                    >,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        elemental_interval_map();
        explicit elemental_interval_map(key_compare const& comp);
        elemental_interval_map(elemental_interval_map const& copy);
        elemental_interval_map(elemental_interval_map const& copy, key_compare const& comp);
        elemental_interval_map(elemental_interval_map&& source);
        elemental_interval_map(elemental_interval_map&& source, key_compare const& comp);
        ~elemental_interval_map();
        elemental_interval_map& operator=(elemental_interval_map const& copy);
        elemental_interval_map& operator=(elemental_interval_map&& source);
        void clear();
        bool empty() const;
        size_type size() const;
        const_iterator cbegin() const;
        const_iterator begin() const;
        const_iterator cend() const;
        const_iterator end() const;
        const_reverse_iterator crbegin() const;
        const_reverse_iterator rbegin() const;
        const_reverse_iterator crend() const;
        const_reverse_iterator rend() const;
        const_iterator find(key_type const& key) const;
        mapped_type const& operator[](key_type const& key) const;

        template <typename K>
        const_iterator find(K const& key) const;

        template <typename K>
        mapped_type const& operator[](K const& key) const;

    private:
        template <typename KeyIterator, typename ValueIterator>
        void _fill_construct(KeyIterator key_itr, KeyIterator key_itr_end, ValueIterator v_itr);
    };
}}}  // namespace odds_and_ends::node::container

#include <algorithm>
#include <iterator>
#include <boost/utility/value_init.hpp>
#include <boost/assert.hpp>

namespace odds_and_ends { namespace node { namespace container {

    template <typename Key, typename Mapped, typename Comp, typename ContainerGen>
    inline elemental_interval_map<Key,Mapped,Comp,ContainerGen>::interval_type::interval_type() :
        _l(::boost::initialized_value), _u(::boost::initialized_value)
    {
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>::interval_type::interval_type(
        key_type const& l,
        key_type const& u
    ) : _l(l), _u(u)
    {
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    inline typename elemental_interval_map<Key,Mapped,Compare,ContainerGen>::key_type const&
        elemental_interval_map<Key,Mapped,Compare,ContainerGen>::interval_type::lower() const
    {
        return this->_l;
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    inline typename elemental_interval_map<Key,Mapped,Compare,ContainerGen>::key_type const&
        elemental_interval_map<Key,Mapped,Compare,ContainerGen>::interval_type::upper() const
    {
        return this->_u;
    }

    template <typename Key, typename Mapped, typename Comp, typename ContainerGen>
    inline elemental_interval_map<Key,Mapped,Comp,ContainerGen>::value_compare::value_compare() :
        _comp()
    {
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>::value_compare::value_compare(
        key_compare const& c
    ) : _comp(c)
    {
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    inline bool
        elemental_interval_map<Key,Mapped,Compare,ContainerGen>::value_compare::operator()(
            const_reference lhs,
            const_reference rhs
        ) const
    {
        return this->_comp(lhs.first.lower(), rhs.first.lower());
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>::elemental_interval_map() :
        _comp(), _container()
    {
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>::elemental_interval_map(
        key_compare const& comp
    ) : _comp(comp), _container()
    {
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    template <typename Alloc>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>::elemental_interval_map(
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _comp(), _container(alloc)
    {
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    template <typename Alloc>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>::elemental_interval_map(
        key_compare const& comp,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _comp(comp), _container(alloc)
    {
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    template <typename KeyIterator, typename ValueIterator>
    void
        elemental_interval_map<Key,Mapped,Compare,ContainerGen>::_fill_construct(
            KeyIterator key_itr,
            KeyIterator key_itr_end,
            ValueIterator value_itr
        )
    {
        typename _container_type::iterator this_itr = this->_container.begin();

        for (KeyIterator key_itr_n = key_itr; ++key_itr_n != key_itr_end; key_itr = key_itr_n)
        {
            this_itr->first = interval_type(*key_itr, *key_itr_n);
            this_itr->second = *value_itr;
            ++value_itr;
            ++this_itr;
        }
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    template <typename KeyIterator, typename ValueIterator>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>::elemental_interval_map(
        KeyIterator key_itr_begin,
        KeyIterator key_itr_end,
        ValueIterator value_itr_begin,
        ValueIterator value_itr_end,
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::concept
                ::is_legacy_input_iterator<KeyIterator>,
                ::odds_and_ends::static_introspection::concept
                ::is_legacy_input_iterator<ValueIterator>,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _comp(), _container(::std::distance(value_itr_begin, value_itr_end), value_type())
    {
        this->_fill_construct(key_itr_begin, key_itr_end, value_itr_begin);
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    template <typename KeyIterator, typename ValueIterator>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>::elemental_interval_map(
        KeyIterator key_itr_begin,
        KeyIterator key_itr_end,
        ValueIterator value_itr_begin,
        ValueIterator value_itr_end,
        key_compare const& comp,
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::concept
                ::is_legacy_input_iterator<KeyIterator>,
                ::odds_and_ends::static_introspection::concept
                ::is_legacy_input_iterator<ValueIterator>,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _comp(comp), _container(::std::distance(value_itr_begin, value_itr_end), value_type())
    {
        this->_fill_construct(key_itr_begin, key_itr_end, value_itr_begin);
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    template <typename KeyIterator, typename ValueIterator, typename Alloc>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>::elemental_interval_map(
        KeyIterator key_itr_begin,
        KeyIterator key_itr_end,
        ValueIterator value_itr_begin,
        ValueIterator value_itr_end,
        Alloc const& alloc,
        typename ::boost::enable_if<
            typename ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection::concept
                    ::is_legacy_input_iterator<KeyIterator>,
                    ::odds_and_ends::static_introspection::concept
                    ::is_legacy_input_iterator<ValueIterator>,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _comp(), _container(::std::distance(value_itr_begin, value_itr_end), value_type(), alloc)
    {
        this->_fill_construct(key_itr_begin, key_itr_end, value_itr_begin);
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    template <typename KeyIterator, typename ValueIterator, typename Alloc>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>::elemental_interval_map(
        KeyIterator key_itr_begin,
        KeyIterator key_itr_end,
        ValueIterator value_itr_begin,
        ValueIterator value_itr_end,
        key_compare const& comp,
        Alloc const& alloc,
        typename ::boost::enable_if<
            typename ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection::concept
                    ::is_legacy_input_iterator<KeyIterator>,
                    ::odds_and_ends::static_introspection::concept
                    ::is_legacy_input_iterator<ValueIterator>,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _comp(comp),
        _container(::std::distance(value_itr_begin, value_itr_end), value_type(), alloc)
    {
        this->_fill_construct(key_itr_begin, key_itr_end, value_itr_begin);
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    template <typename K, typename M>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>::elemental_interval_map(
        ::std::initializer_list<K> keys,
        ::std::initializer_list<M> values,
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::std::is_convertible<K,key_type>,
                ::std::is_convertible<M,mapped_type>,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _comp(), _container(values.size(), value_type())
    {
        BOOST_ASSERT(values.size() + 1 == keys.size());
        this->_fill_construct(keys.begin(), keys.end(), values.begin());
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    template <typename K, typename M>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>::elemental_interval_map(
        ::std::initializer_list<K> keys,
        ::std::initializer_list<M> values,
        key_compare const& comp,
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::std::is_convertible<K,key_type>,
                ::std::is_convertible<M,mapped_type>,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _comp(comp), _container(values.size(), value_type())
    {
        BOOST_ASSERT(values.size() + 1 == keys.size());
        this->_fill_construct(keys.begin(), keys.end(), values.begin());
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    template <typename K, typename M, typename Alloc>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>::elemental_interval_map(
        ::std::initializer_list<K> keys,
        ::std::initializer_list<M> values,
        Alloc const& alloc,
        typename ::boost::enable_if<
            typename ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                ::boost::mpl::if_<
                    ::std::is_convertible<K,key_type>,
                    ::std::is_convertible<M,mapped_type>,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _comp(), _container(values.size(), value_type(), alloc)
    {
        BOOST_ASSERT(values.size() + 1 == keys.size());
        this->_fill_construct(keys.begin(), keys.end(), values.begin());
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    template <typename K, typename M, typename Alloc>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>::elemental_interval_map(
        ::std::initializer_list<K> keys,
        ::std::initializer_list<M> values,
        key_compare const& comp,
        Alloc const& alloc,
        typename ::boost::enable_if<
            typename ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                ::boost::mpl::if_<
                    ::std::is_convertible<K,key_type>,
                    ::std::is_convertible<M,mapped_type>,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _comp(comp), _container(values.size(), value_type(), alloc)
    {
        BOOST_ASSERT(values.size() + 1 == keys.size());
        this->_fill_construct(keys.begin(), keys.end(), values.begin());
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>::elemental_interval_map(
        elemental_interval_map const& copy
    ) : _comp(copy._comp), _container(copy._container)
    {
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>::elemental_interval_map(
        elemental_interval_map const& copy,
        key_compare const& comp
    ) : _comp(comp), _container(copy._container)
    {
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    template <typename Alloc>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>::elemental_interval_map(
        elemental_interval_map const& copy,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _comp(copy._comp), _container(copy._container, alloc)
    {
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    template <typename Alloc>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>::elemental_interval_map(
        elemental_interval_map const& copy,
        key_compare const& comp,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _comp(comp), _container(copy._container, alloc)
    {
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    template <typename K, typename M, typename C, typename G>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>::elemental_interval_map(
        elemental_interval_map<K,M,C,G> const& copy,
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::std::is_convertible<K,Key>,
                ::std::is_convertible<M,Mapped>,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _comp(copy._comp), _container(copy._container.begin(), copy._container.end())
    {
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    template <typename K, typename M, typename C, typename G>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>::elemental_interval_map(
        elemental_interval_map<K,M,C,G> const& copy,
        key_compare const& comp,
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::std::is_convertible<K,Key>,
                ::std::is_convertible<M,Mapped>,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _comp(comp), _container(copy._container.begin(), copy._container.end())
    {
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    template <typename K, typename M, typename C, typename G, typename Alloc>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>::elemental_interval_map(
        elemental_interval_map<K,M,C,G> const& copy,
        Alloc const& alloc,
        typename ::boost::enable_if<
            typename ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                ::boost::mpl::if_<
                    ::std::is_convertible<K,Key>,
                    ::std::is_convertible<M,Mapped>,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _comp(copy._comp), _container(copy._container.begin(), copy._container.end(), alloc)
    {
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    template <typename K, typename M, typename C, typename G, typename Alloc>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>::elemental_interval_map(
        elemental_interval_map<K,M,C,G> const& copy,
        key_compare const& comp,
        Alloc const& alloc,
        typename ::boost::enable_if<
            typename ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                ::boost::mpl::if_<
                    ::std::is_convertible<K,Key>,
                    ::std::is_convertible<M,Mapped>,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _comp(comp), _container(copy._container.begin(), copy._container.end(), alloc)
    {
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>::elemental_interval_map(
        elemental_interval_map&& source
    ) : _comp(source._comp), _container(::std::move(source._container))
    {
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>::elemental_interval_map(
        elemental_interval_map&& source,
        key_compare const& comp
    ) : _comp(comp), _container(::std::move(source._container))
    {
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    template <typename Alloc>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>::elemental_interval_map(
        elemental_interval_map&& source,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _comp(source._comp), _container(::std::move(source._container), alloc)
    {
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    template <typename Alloc>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>::elemental_interval_map(
        elemental_interval_map&& source,
        key_compare const& comp,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _comp(comp), _container(::std::move(source._container), alloc)
    {
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    inline void elemental_interval_map<Key,Mapped,Compare,ContainerGen>::clear()
    {
        this->_container.clear();
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>::~elemental_interval_map()
    {
        this->clear();
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>&
        elemental_interval_map<Key,Mapped,Compare,ContainerGen>::operator=(
            elemental_interval_map const& copy
        )
    {
        if (this != &copy)
        {
            this->_comp = copy._comp;
            this->_container = copy._container;
        }

        return *this;
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    inline elemental_interval_map<Key,Mapped,Compare,ContainerGen>&
        elemental_interval_map<Key,Mapped,Compare,ContainerGen>::operator=(
            elemental_interval_map&& source
        )
    {
        if (this != &static_cast<elemental_interval_map&>(source))
        {
            this->_comp = source._comp;
            this->_container = ::std::move(source._container);
        }

        return *this;
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    inline bool elemental_interval_map<Key,Mapped,Compare,ContainerGen>::empty() const
    {
        return this->_container.empty();
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    inline typename elemental_interval_map<Key,Mapped,Compare,ContainerGen>::size_type
        elemental_interval_map<Key,Mapped,Compare,ContainerGen>::size() const
    {
        return this->_container.size();
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    inline typename elemental_interval_map<Key,Mapped,Compare,ContainerGen>::const_iterator
        elemental_interval_map<Key,Mapped,Compare,ContainerGen>::cbegin() const
    {
        return this->_container.cbegin();
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    inline typename elemental_interval_map<Key,Mapped,Compare,ContainerGen>::const_iterator
        elemental_interval_map<Key,Mapped,Compare,ContainerGen>::begin() const
    {
        return this->_container.begin();
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    inline typename elemental_interval_map<Key,Mapped,Compare,ContainerGen>::const_iterator
        elemental_interval_map<Key,Mapped,Compare,ContainerGen>::cend() const
    {
        return this->_container.cend();
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    inline typename elemental_interval_map<Key,Mapped,Compare,ContainerGen>::const_iterator
        elemental_interval_map<Key,Mapped,Compare,ContainerGen>::end() const
    {
        return this->_container.end();
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    inline typename elemental_interval_map<Key,Mapped,Compare,ContainerGen>::const_reverse_iterator
        elemental_interval_map<Key,Mapped,Compare,ContainerGen>::crbegin() const
    {
        return this->_container.crbegin();
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    inline typename elemental_interval_map<Key,Mapped,Compare,ContainerGen>::const_reverse_iterator
        elemental_interval_map<Key,Mapped,Compare,ContainerGen>::rbegin() const
    {
        return this->_container.rbegin();
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    inline typename elemental_interval_map<Key,Mapped,Compare,ContainerGen>::const_reverse_iterator
        elemental_interval_map<Key,Mapped,Compare,ContainerGen>::crend() const
    {
        return this->_container.crend();
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    inline typename elemental_interval_map<Key,Mapped,Compare,ContainerGen>::const_reverse_iterator
        elemental_interval_map<Key,Mapped,Compare,ContainerGen>::rend() const
    {
        return this->_container.rend();
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    typename elemental_interval_map<Key,Mapped,Compare,ContainerGen>::const_iterator
        elemental_interval_map<Key,Mapped,Compare,ContainerGen>::find(key_type const& key) const
    {
        size_type index_l = ::boost::initialized_value;
        size_type one = index_l;
        ++one;
        size_type index_h = this->_container.size();

        for (size_type index_m; index_l < index_h; )
        {
            index_m = (index_l + index_h) >> one;

            if (this->_comp(key, this->_container[index_m].first.lower()))
            {
                index_h = index_m;
            }
            else if (!this->_comp(key, this->_container[index_m].first.upper()))
            {
                index_l = index_m + one;
            }
            else
            {
                return this->cbegin() + index_m;
            }
        }

        return this->cend();
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    template <typename K>
    typename elemental_interval_map<Key,Mapped,Compare,ContainerGen>::const_iterator
        elemental_interval_map<Key,Mapped,Compare,ContainerGen>::find(K const& key) const
    {
        size_type index_l = ::boost::initialized_value;
        size_type one = index_l;
        ++one;
        size_type index_h = this->_container.size();

        for (size_type index_m; index_l < index_h; )
        {
            index_m = (index_l + index_h) >> one;

            if (this->_comp(key, this->_container[index_m].first.lower()))
            {
                index_h = index_m;
            }
            else if (!this->_comp(key, this->_container[index_m].first.upper()))
            {
                index_l = index_m + one;
            }
            else
            {
                return this->cbegin() + index_m;
            }
        }

        return this->cend();
    }

    template <typename Key, typename Mapped, typename Comp, typename ContainerGen>
    inline typename elemental_interval_map<Key,Mapped,Comp,ContainerGen>::mapped_type const&
        elemental_interval_map<Key,Mapped,Comp,ContainerGen>::operator[](key_type const& key) const
    {
        return this->find(key)->second;
    }

    template <typename Key, typename Mapped, typename Compare, typename ContainerGen>
    template <typename K>
    inline typename elemental_interval_map<Key,Mapped,Compare,ContainerGen>::mapped_type const&
        elemental_interval_map<Key,Mapped,Compare,ContainerGen>::operator[](K const& key) const
    {
        return this->find(key)->second;
    }
}}}  // namespace odds_and_ends::node::container

#endif  // ODDS_AND_ENDS__NODE__CONTAINER__ELEMENTAL_INTERVAL_MAP_HPP

