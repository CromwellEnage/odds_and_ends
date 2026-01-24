// Copyright (C) 2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__CONTAINER__TRIE_MAP_HPP
#define ODDS_AND_ENDS__NODE__CONTAINER__TRIE_MAP_HPP

#include <cstddef>
#include <type_traits>
#include <optional>
#include <functional>
#include <utility>
#include <memory>
#include <initializer_list>
#include <odds_and_ends/node/data.hpp>
#include <odds_and_ends/node/tree/base.hpp>
#include <odds_and_ends/node/tree/associative.hpp>
#include <odds_and_ends/node/iterator/pre_order_tree.hpp>
#include <odds_and_ends/node/iterator/post_order_tree.hpp>
#include <odds_and_ends/node/iterator/stack_or_queue.hpp>
#include <odds_and_ends/node/iterator/transform.hpp>
#include <odds_and_ends/node/iterator/filter.hpp>
#include <odds_and_ends/composite_type/composite_type.hpp>
#include <odds_and_ends/static_introspection/concept/is_allocator.hpp>
#include <odds_and_ends/static_introspection/concept/is_runtime_pair.hpp>
#include <odds_and_ends/static_introspection/concept/is_single_pass_range.hpp>
#include <odds_and_ends/static_introspection/nested_type/is_value_type_of.hpp>
#include <odds_and_ends/use_default_policy.hpp>
#include <boost/optional.hpp>
#include <boost/core/enable_if.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/quote.hpp>

namespace odds_and_ends { namespace node { namespace container {

    template <
        typename Key,
        typename Mapped,
        typename ContainerGenerator = ::odds_and_ends::use_default_policy,
        typename Size = ::std::size_t,
        typename PtrXForm = ::boost::mpl::quote1< ::std::add_pointer>,
        typename AllocXForm = ::boost::mpl::quote1< ::std::allocator>
    >
    class trie_map
    {
        struct _enabler
        {
        };

        typedef ::boost::optional<Mapped> _opt_mapped;

    public:
        typedef ::odds_and_ends::node::container::trie_map<
            Key,
            Mapped,
            ContainerGenerator,
            Size,
            PtrXForm,
            AllocXForm
        > type;
        typedef Mapped mapped_type;
        typedef ::odds_and_ends::composite_type::composite_type<
            ::boost::mpl::deque<
                ::odds_and_ends::node::data<_opt_mapped>,
                ::odds_and_ends::node::tree::base<PtrXForm>,
                ::odds_and_ends::node::tree::associative<Key,ContainerGenerator,PtrXForm>
            >
        > node_type;

    private:
        typedef typename node_type::traits::const_pointer _node_ptr_const_t;
        typedef typename node_type::traits::pointer _node_ptr_t;
        typedef ::odds_and_ends::node::stack_or_queue_iterator<
            Key,
            ::boost::mpl::true_,
            Size,
            PtrXForm,
            AllocXForm
        > _s_or_q_itr;

    public:
        typedef typename ::boost::mpl::apply_wrap1<AllocXForm,node_type>::type allocator_type;
        typedef ::std::pair<_s_or_q_itr,_s_or_q_itr> key_type;
        typedef ::std::pair<key_type,mapped_type> value_type;
        typedef value_type const& const_reference;
        typedef value_type& reference;

    private:
        typedef ::std::pair<key_type,_opt_mapped> _value_opt_t;

        struct _xform_func_0
        {
            _value_opt_t operator()() const;
            _value_opt_t operator()(node_type& n) const;
        };

        struct _xform_func_1
        {
            value_type operator()() const;
            value_type operator()(_value_opt_t& p) const;
        };

        struct _filter_func
        {
            bool operator()(_value_opt_t& p) const;
        };

        typedef ::odds_and_ends::node
        ::pre_order_tree_iterator<node_type,::boost::mpl::false_> _itr_t_0;
        typedef ::odds_and_ends::node
        ::post_order_tree_iterator<node_type,::boost::mpl::true_> _r_itr_t_0;
        typedef ::odds_and_ends::node
        ::transform_iterator<_itr_t_0,_xform_func_0,PtrXForm,::boost::mpl::false_> _itr_t_1;
        typedef ::odds_and_ends::node
        ::transform_iterator<_r_itr_t_0,_xform_func_0,PtrXForm,::boost::mpl::false_> _r_itr_t_1;
        typedef ::odds_and_ends::node::filter_iterator<_itr_t_1,_filter_func> _itr_t_2;
        typedef ::odds_and_ends::node::filter_iterator<_r_itr_t_1,_filter_func> _r_itr_t_2;

    public:
        typedef ::odds_and_ends::node
        ::transform_iterator<_itr_t_2,_xform_func_1,PtrXForm,::boost::mpl::false_> iterator;
        typedef ::odds_and_ends::node
        ::transform_iterator<_itr_t_2,_xform_func_1,PtrXForm,::boost::mpl::true_> const_iterator;
        typedef ::odds_and_ends::node::transform_iterator<
            _r_itr_t_2,
            _xform_func_1,
            PtrXForm,
            ::boost::mpl::false_
        > reverse_iterator;
        typedef ::odds_and_ends::node::transform_iterator<
            _r_itr_t_2,
            _xform_func_1,
            PtrXForm,
            ::boost::mpl::true_
        > const_reverse_iterator;

    private:
        static key_type const _dummy;

        allocator_type _alloc;
        node_type _root;

    public:
        trie_map();
        ~trie_map();
        void clear();
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

        template <typename A0, typename ...Args>
        iterator emplace(A0&& a0, Args&&... args);

        template <typename K>
        const_iterator find(K const& key) const;

        template <typename K>
        iterator find(K const& key);
    };
}}}   // namespace odds_and_ends::node::container

#include <boost/range/begin.hpp>
#include <boost/range/end.hpp>

namespace odds_and_ends { namespace node { namespace container {

    template <
        typename Key,
        typename Mapped,
        typename ContainerGenerator,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    typename trie_map<Key,Mapped,ContainerGenerator,Size,PtrXForm,AllocXForm>::key_type const
        trie_map<Key,Mapped,ContainerGenerator,Size,PtrXForm,AllocXForm>::_dummy =
        typename trie_map<Key,Mapped,ContainerGenerator,Size,PtrXForm,AllocXForm>::key_type();

    template <
        typename Key,
        typename Mapped,
        typename ConGen,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::_value_opt_t
        trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::_xform_func_0::operator()() const
    {
        return _value_opt_t(type::_dummy, _opt_mapped());
    }

    template <
        typename Key,
        typename Mapped,
        typename ConGen,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::_value_opt_t
        trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::_xform_func_0::operator()(
            node_type& n
        ) const
    {
        _s_or_q_itr itr;

        for (
            _node_ptr_t p = ::std::pointer_traits<_node_ptr_t>::pointer_to(n);
            p->parent();
            p = p->parent()
        )
        {
            itr(p->key());
        }

        return _value_opt_t(key_type(itr, _s_or_q_itr()), *n);
    }

    template <
        typename Key,
        typename Mapped,
        typename ConGen,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::value_type
        trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::_xform_func_1::operator()() const
    {
        return value_type(type::_dummy, mapped_type());
    }

    template <
        typename Key,
        typename Mapped,
        typename ConGen,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::value_type
        trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::_xform_func_1::operator()(
            _value_opt_t& p
        ) const
    {
        return value_type(p.first, *p.second);
    }

    template <
        typename Key,
        typename Mapped,
        typename ConGen,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline bool
        trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::_filter_func::operator()(
            _value_opt_t& p
        ) const
    {
        return !!p.second;
    }

    template <
        typename Key,
        typename Mapped,
        typename ContainerGenerator,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline trie_map<Key,Mapped,ContainerGenerator,Size,PtrXForm,AllocXForm>::trie_map() :
        _alloc(), _root()
    {
    }

    template <
        typename Key,
        typename Mapped,
        typename ContainerGenerator,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    void trie_map<Key,Mapped,ContainerGenerator,Size,PtrXForm,AllocXForm>::clear()
    {
        typename node_type::traits::pointer p = nullptr;

        for (
            ::odds_and_ends::node::post_order_tree_iterator<node_type> post_itr(this->_root);
            !(!post_itr);
            ++post_itr
        )
        {
            for (
                typename node_type::traits::child_iterator child_itr = post_itr->begin();
                child_itr != post_itr->end();
            )
            {
                p = child_itr->second;
                child_itr = post_itr->unset(child_itr->first);
                ::std::allocator_traits<allocator_type>::destroy(this->_alloc, p);
                ::std::allocator_traits<allocator_type>::deallocate(this->_alloc, p, 1);
            }
        }
    }

    template <
        typename Key,
        typename Mapped,
        typename ContainerGenerator,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline trie_map<Key,Mapped,ContainerGenerator,Size,PtrXForm,AllocXForm>::~trie_map()
    {
        this->clear();
    }

    template <
        typename Key,
        typename Mapped,
        typename ConGen,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::const_iterator
        trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::cbegin() const
    {
        return const_iterator(_itr_t_2(_itr_t_1(_itr_t_0(const_cast<node_type&>(this->_root)))));
    }

    template <
        typename Key,
        typename Mapped,
        typename ConGen,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::const_iterator
        trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::begin() const
    {
        return const_iterator(_itr_t_2(_itr_t_1(_itr_t_0(const_cast<node_type&>(this->_root)))));
    }

    template <
        typename Key,
        typename Mapped,
        typename ConGen,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::iterator
        trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::begin()
    {
        return iterator(_itr_t_2(_itr_t_1(_itr_t_0(this->_root))));
    }

    template <
        typename Key,
        typename Mapped,
        typename ConGen,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::const_iterator
        trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::cend() const
    {
        return const_iterator();
    }

    template <
        typename Key,
        typename Mapped,
        typename ConGen,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::const_iterator
        trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::end() const
    {
        return const_iterator();
    }

    template <
        typename Key,
        typename Mapped,
        typename ConGen,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::iterator
        trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::end()
    {
        return iterator();
    }

    template <
        typename Key,
        typename Mapped,
        typename ConGen,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::const_reverse_iterator
        trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::crbegin() const
    {
        return const_reverse_iterator(_r_itr_t_2(_r_itr_t_1(_r_itr_t_0(
            const_cast<node_type&>(this->_root)
        ))));
    }

    template <
        typename Key,
        typename Mapped,
        typename ConGen,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::const_reverse_iterator
        trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::rbegin() const
    {
        return const_reverse_iterator(_r_itr_t_2(_r_itr_t_1(_r_itr_t_0(
            const_cast<node_type&>(this->_root)
        ))));
    }

    template <
        typename Key,
        typename Mapped,
        typename ConGen,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::reverse_iterator
        trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::rbegin()
    {
        return reverse_iterator(_r_itr_t_2(_r_itr_t_1(_r_itr_t_0(this->_root))));
    }

    template <
        typename Key,
        typename Mapped,
        typename ConGen,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::const_reverse_iterator
        trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::crend() const
    {
        return const_reverse_iterator();
    }

    template <
        typename Key,
        typename Mapped,
        typename ConGen,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::const_reverse_iterator
        trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::rend() const
    {
        return const_reverse_iterator();
    }

    template <
        typename Key,
        typename Mapped,
        typename ConGen,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::reverse_iterator
        trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::rend()
    {
        return reverse_iterator();
    }

    template <
        typename Key,
        typename Mapped,
        typename ConGen,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    template <typename A0, typename ...Args>
    inline typename trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::iterator
        trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::emplace(A0&& a0, Args&&... args)
    {
        _node_ptr_t p = ::std::pointer_traits<_node_ptr_t>::pointer_to(this->_root);
        _node_ptr_t n;

        for (
            typename ::boost::range_iterator<A0>::type itr = ::boost::begin(a0);
            itr != ::boost::end(a0);
            ++itr
        )
        {
            n = p->get(*itr);

            if (!n)
            {
                n = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);
                ::std::allocator_traits<allocator_type>::construct(this->_alloc, n);
                p->set_ptr(*itr, n);
            }

            p = n;
        }

        **p = Mapped(::std::forward<Args>(args)...);
        return iterator(_itr_t_2(_itr_t_1(_itr_t_0(*p))));
    }

    template <
        typename Key,
        typename Mapped,
        typename ConGen,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    template <typename K>
    inline typename trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::const_iterator
        trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::find(K const& key) const
    {
        _node_ptr_const_t p = ::std::pointer_traits<_node_ptr_const_t>::pointer_to(this->_root);

        for (
            typename ::boost::range_iterator<K const>::type itr = ::boost::begin(key);
            itr != ::boost::end(key);
            ++itr
        )
        {
            p = p->get(*itr);

            if (!p)
            {
                return this->cend();
            }
        }

        return **p ? const_iterator(_itr_t_2(_itr_t_1(_itr_t_0(
            const_cast<node_type&>(*p)
        )))) : this->cend();
    }

    template <
        typename Key,
        typename Mapped,
        typename ConGen,
        typename Size,
        typename PtrXForm,
        typename AllocXForm
    >
    template <typename K>
    inline typename trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::iterator
        trie_map<Key,Mapped,ConGen,Size,PtrXForm,AllocXForm>::find(K const& key)
    {
        _node_ptr_t p = ::std::pointer_traits<_node_ptr_t>::pointer_to(this->_root);

        for (
            typename ::boost::range_iterator<K const>::type itr = ::boost::begin(key);
            itr != ::boost::end(key);
            ++itr
        )
        {
            p = p->get(*itr);

            if (!p)
            {
                return this->end();
            }
        }

        return **p ? iterator(_itr_t_2(_itr_t_1(_itr_t_0(*p)))) : this->end();
    }
}}}   // namespace odds_and_ends::node::container

#endif  // ODDS_AND_ENDS__NODE__CONTAINER__TRIE_MAP_HPP

