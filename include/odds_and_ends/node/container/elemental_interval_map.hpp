// Copyright (C) 2025-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__CONTAINER__ELEMENTAL_INTERVAL_MAP_HPP
#define ODDS_AND_ENDS__NODE__CONTAINER__ELEMENTAL_INTERVAL_MAP_HPP

#include <type_traits>
#include <functional>
#include <utility>
#include <vector>
#include <initializer_list>
#include <odds_and_ends/node/parameter/template.hpp>
#include <odds_and_ends/static_introspection/concept/is_allocator.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_input_iterator.hpp>
#include <odds_and_ends/static_introspection/concept/is_indexable_container.hpp>
#include <odds_and_ends/use_default_policy.hpp>
//#include <boost/numeric/interval.hpp>
#include <boost/parameter/optional.hpp>
#include <boost/parameter/parameters.hpp>
#include <boost/parameter/value_type.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/quote.hpp>
#include <boost/mpl/assert.hpp>

namespace odds_and_ends { namespace node { namespace container {

    template <
        typename Key,
        typename Mapped,
        typename T0 = ::boost::parameter::void_,
        typename T1 = ::boost::parameter::void_
    >
    class elemental_interval_map
    {
        struct _enabler
        {
        };

        typedef typename ::boost::parameter::parameters<
            ::boost::parameter::optional<
                ::odds_and_ends::node::parameter::tag::_compare_generator
            >,
            ::boost::parameter::optional<
                ::odds_and_ends::node::parameter::tag::_container_generator
            >
        >::template bind<T0,T1>::type _template_args;
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
        typedef ::odds_and_ends::node::container::elemental_interval_map<Key,Mapped,T0,T1> type;
        typedef Key key_type;
        typedef Mapped mapped_type;
        typedef typename ::boost::mpl::apply_wrap1<_compare_gen,key_type>::type key_compare;

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
            ::std::is_same<_container_gen,::odds_and_ends::use_default_policy>,
            ::boost::mpl::identity< ::std::vector<value_type> >,
            ::boost::mpl::apply_wrap1<_container_gen,value_type>
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

        template <typename K, typename M, typename U0, typename U1>
        elemental_interval_map(
            elemental_interval_map<K,M,U0,U1> const& copy,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::std::is_convertible<K,Key>,
                    ::std::is_convertible<M,Mapped>,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename K, typename M, typename U0, typename U1>
        elemental_interval_map(
            elemental_interval_map<K,M,U0,U1> const& copy,
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

        template <typename K, typename M, typename U0, typename U1, typename Alloc>
        elemental_interval_map(
            elemental_interval_map<K,M,U0,U1> const& copy,
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

        template <typename K, typename M, typename U0, typename U1, typename Alloc>
        elemental_interval_map(
            elemental_interval_map<K,M,U0,U1> const& copy,
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

    template <typename Key, typename Mapped, typename T0, typename T1>
    inline elemental_interval_map<Key,Mapped,T0,T1>::interval_type::interval_type() :
        _l(::boost::initialized_value), _u(::boost::initialized_value)
    {
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    inline elemental_interval_map<Key,Mapped,T0,T1>::interval_type::interval_type(
        key_type const& l,
        key_type const& u
    ) : _l(l), _u(u)
    {
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    inline typename elemental_interval_map<Key,Mapped,T0,T1>::key_type const&
        elemental_interval_map<Key,Mapped,T0,T1>::interval_type::lower() const
    {
        return this->_l;
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    inline typename elemental_interval_map<Key,Mapped,T0,T1>::key_type const&
        elemental_interval_map<Key,Mapped,T0,T1>::interval_type::upper() const
    {
        return this->_u;
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    inline elemental_interval_map<Key,Mapped,T0,T1>::value_compare::value_compare() : _comp()
    {
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    inline elemental_interval_map<Key,Mapped,T0,T1>::value_compare::value_compare(
        key_compare const& c
    ) : _comp(c)
    {
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    inline bool
        elemental_interval_map<Key,Mapped,T0,T1>::value_compare::operator()(
            const_reference lhs,
            const_reference rhs
        ) const
    {
        return this->_comp(lhs.first.lower(), rhs.first.lower());
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    inline elemental_interval_map<Key,Mapped,T0,T1>::elemental_interval_map() :
        _comp(), _container()
    {
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    inline elemental_interval_map<Key,Mapped,T0,T1>::elemental_interval_map(
        key_compare const& comp
    ) : _comp(comp), _container()
    {
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    template <typename Alloc>
    inline elemental_interval_map<Key,Mapped,T0,T1>::elemental_interval_map(
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _comp(), _container(alloc)
    {
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    template <typename Alloc>
    inline elemental_interval_map<Key,Mapped,T0,T1>::elemental_interval_map(
        key_compare const& comp,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _comp(comp), _container(alloc)
    {
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    template <typename KeyIterator, typename ValueIterator>
    void
        elemental_interval_map<Key,Mapped,T0,T1>::_fill_construct(
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

    template <typename Key, typename Mapped, typename T0, typename T1>
    template <typename KeyIterator, typename ValueIterator>
    inline elemental_interval_map<Key,Mapped,T0,T1>::elemental_interval_map(
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

    template <typename Key, typename Mapped, typename T0, typename T1>
    template <typename KeyIterator, typename ValueIterator>
    inline elemental_interval_map<Key,Mapped,T0,T1>::elemental_interval_map(
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

    template <typename Key, typename Mapped, typename T0, typename T1>
    template <typename KeyIterator, typename ValueIterator, typename Alloc>
    inline elemental_interval_map<Key,Mapped,T0,T1>::elemental_interval_map(
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

    template <typename Key, typename Mapped, typename T0, typename T1>
    template <typename KeyIterator, typename ValueIterator, typename Alloc>
    inline elemental_interval_map<Key,Mapped,T0,T1>::elemental_interval_map(
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

    template <typename Key, typename Mapped, typename T0, typename T1>
    template <typename K, typename M>
    inline elemental_interval_map<Key,Mapped,T0,T1>::elemental_interval_map(
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

    template <typename Key, typename Mapped, typename T0, typename T1>
    template <typename K, typename M>
    inline elemental_interval_map<Key,Mapped,T0,T1>::elemental_interval_map(
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

    template <typename Key, typename Mapped, typename T0, typename T1>
    template <typename K, typename M, typename Alloc>
    inline elemental_interval_map<Key,Mapped,T0,T1>::elemental_interval_map(
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

    template <typename Key, typename Mapped, typename T0, typename T1>
    template <typename K, typename M, typename Alloc>
    inline elemental_interval_map<Key,Mapped,T0,T1>::elemental_interval_map(
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

    template <typename Key, typename Mapped, typename T0, typename T1>
    inline elemental_interval_map<Key,Mapped,T0,T1>::elemental_interval_map(
        elemental_interval_map const& copy
    ) : _comp(copy._comp), _container(copy._container)
    {
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    inline elemental_interval_map<Key,Mapped,T0,T1>::elemental_interval_map(
        elemental_interval_map const& copy,
        key_compare const& comp
    ) : _comp(comp), _container(copy._container)
    {
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    template <typename Alloc>
    inline elemental_interval_map<Key,Mapped,T0,T1>::elemental_interval_map(
        elemental_interval_map const& copy,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _comp(copy._comp), _container(copy._container, alloc)
    {
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    template <typename Alloc>
    inline elemental_interval_map<Key,Mapped,T0,T1>::elemental_interval_map(
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

    template <typename Key, typename Mapped, typename T0, typename T1>
    template <typename K, typename M, typename U0, typename U1>
    inline elemental_interval_map<Key,Mapped,T0,T1>::elemental_interval_map(
        elemental_interval_map<K,M,U0,U1> const& copy,
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

    template <typename Key, typename Mapped, typename T0, typename T1>
    template <typename K, typename M, typename U0, typename U1>
    inline elemental_interval_map<Key,Mapped,T0,T1>::elemental_interval_map(
        elemental_interval_map<K,M,U0,U1> const& copy,
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

    template <typename Key, typename Mapped, typename T0, typename T1>
    template <typename K, typename M, typename U0, typename U1, typename Alloc>
    inline elemental_interval_map<Key,Mapped,T0,T1>::elemental_interval_map(
        elemental_interval_map<K,M,U0,U1> const& copy,
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

    template <typename Key, typename Mapped, typename T0, typename T1>
    template <typename K, typename M, typename U0, typename U1, typename Alloc>
    inline elemental_interval_map<Key,Mapped,T0,T1>::elemental_interval_map(
        elemental_interval_map<K,M,U0,U1> const& copy,
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

    template <typename Key, typename Mapped, typename T0, typename T1>
    inline elemental_interval_map<Key,Mapped,T0,T1>::elemental_interval_map(
        elemental_interval_map&& source
    ) : _comp(source._comp), _container(::std::move(source._container))
    {
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    inline elemental_interval_map<Key,Mapped,T0,T1>::elemental_interval_map(
        elemental_interval_map&& source,
        key_compare const& comp
    ) : _comp(comp), _container(::std::move(source._container))
    {
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    template <typename Alloc>
    inline elemental_interval_map<Key,Mapped,T0,T1>::elemental_interval_map(
        elemental_interval_map&& source,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _comp(source._comp), _container(::std::move(source._container), alloc)
    {
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    template <typename Alloc>
    inline elemental_interval_map<Key,Mapped,T0,T1>::elemental_interval_map(
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

    template <typename Key, typename Mapped, typename T0, typename T1>
    inline void elemental_interval_map<Key,Mapped,T0,T1>::clear()
    {
        this->_container.clear();
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    inline elemental_interval_map<Key,Mapped,T0,T1>::~elemental_interval_map()
    {
        this->clear();
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    inline elemental_interval_map<Key,Mapped,T0,T1>&
        elemental_interval_map<Key,Mapped,T0,T1>::operator=(
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

    template <typename Key, typename Mapped, typename T0, typename T1>
    inline elemental_interval_map<Key,Mapped,T0,T1>&
        elemental_interval_map<Key,Mapped,T0,T1>::operator=(
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

    template <typename Key, typename Mapped, typename T0, typename T1>
    inline bool elemental_interval_map<Key,Mapped,T0,T1>::empty() const
    {
        return this->_container.empty();
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    inline typename elemental_interval_map<Key,Mapped,T0,T1>::size_type
        elemental_interval_map<Key,Mapped,T0,T1>::size() const
    {
        return this->_container.size();
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    inline typename elemental_interval_map<Key,Mapped,T0,T1>::const_iterator
        elemental_interval_map<Key,Mapped,T0,T1>::cbegin() const
    {
        return this->_container.cbegin();
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    inline typename elemental_interval_map<Key,Mapped,T0,T1>::const_iterator
        elemental_interval_map<Key,Mapped,T0,T1>::begin() const
    {
        return this->_container.begin();
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    inline typename elemental_interval_map<Key,Mapped,T0,T1>::const_iterator
        elemental_interval_map<Key,Mapped,T0,T1>::cend() const
    {
        return this->_container.cend();
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    inline typename elemental_interval_map<Key,Mapped,T0,T1>::const_iterator
        elemental_interval_map<Key,Mapped,T0,T1>::end() const
    {
        return this->_container.end();
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    inline typename elemental_interval_map<Key,Mapped,T0,T1>::const_reverse_iterator
        elemental_interval_map<Key,Mapped,T0,T1>::crbegin() const
    {
        return this->_container.crbegin();
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    inline typename elemental_interval_map<Key,Mapped,T0,T1>::const_reverse_iterator
        elemental_interval_map<Key,Mapped,T0,T1>::rbegin() const
    {
        return this->_container.rbegin();
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    inline typename elemental_interval_map<Key,Mapped,T0,T1>::const_reverse_iterator
        elemental_interval_map<Key,Mapped,T0,T1>::crend() const
    {
        return this->_container.crend();
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    inline typename elemental_interval_map<Key,Mapped,T0,T1>::const_reverse_iterator
        elemental_interval_map<Key,Mapped,T0,T1>::rend() const
    {
        return this->_container.rend();
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    typename elemental_interval_map<Key,Mapped,T0,T1>::const_iterator
        elemental_interval_map<Key,Mapped,T0,T1>::find(key_type const& key) const
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

    template <typename Key, typename Mapped, typename T0, typename T1>
    template <typename K>
    typename elemental_interval_map<Key,Mapped,T0,T1>::const_iterator
        elemental_interval_map<Key,Mapped,T0,T1>::find(K const& key) const
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

    template <typename Key, typename Mapped, typename T0, typename T1>
    inline typename elemental_interval_map<Key,Mapped,T0,T1>::mapped_type const&
        elemental_interval_map<Key,Mapped,T0,T1>::operator[](key_type const& key) const
    {
        return this->find(key)->second;
    }

    template <typename Key, typename Mapped, typename T0, typename T1>
    template <typename K>
    inline typename elemental_interval_map<Key,Mapped,T0,T1>::mapped_type const&
        elemental_interval_map<Key,Mapped,T0,T1>::operator[](K const& key) const
    {
        return this->find(key)->second;
    }
}}}  // namespace odds_and_ends::node::container

#endif  // ODDS_AND_ENDS__NODE__CONTAINER__ELEMENTAL_INTERVAL_MAP_HPP

