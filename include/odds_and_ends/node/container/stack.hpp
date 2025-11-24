// Copyright (C) 2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__CONTAINER__STACK_HPP
#define ODDS_AND_ENDS__NODE__CONTAINER__STACK_HPP

#include <cstddef>
#include <memory>
#include <odds_and_ends/node/data.hpp>
#include <odds_and_ends/node/linked/base.hpp>
#include <odds_and_ends/composite_type/composite_type.hpp>
#include <odds_and_ends/composite_type/preprocessor/noncopyable_nonmovable_body.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/mpl/apply_wrap.hpp>

namespace odds_and_ends { namespace node { namespace container {

    template <typename T, typename Size = ::std::size_t>
    class stack
    {
        typedef ::odds_and_ends::composite_type::composite_type<
            ::boost::mpl::deque<
                ::odds_and_ends::node::data<T>,
                ::odds_and_ends::node::linked::base<>
            >
        > _node_t;
        typedef ::std::allocator<_node_t> allocator_type;

        typename _node_t::traits::pointer _top;
        Size _size;

    public:
        typedef T value_type;
        typedef Size size_type;

        stack();
        ~stack();
        bool empty() const;
        size_type const& size() const;
        value_type const& top() const;
        void push(value_type const& t);
        void push(value_type&& t);

        template <typename ...Args>
        value_type const& emplace(Args&&... args);

        void pop();
        void clear();
        ODDS_AND_ENDS__COMPOSITE_TYPE__NONCOPYABLE_NONMOVABLE_BODY(stack)
    };
}}}  // namespace odds_and_ends::node::container

#include <utility>
#include <boost/utility/value_init.hpp>

namespace odds_and_ends { namespace node { namespace container {

    template <typename T, typename Size>
    inline stack<T,Size>::stack() : _top(nullptr), _size(::boost::initialized_value)
    {
    }

    template <typename T, typename Size>
    inline stack<T,Size>::~stack()
    {
        this->clear();
    }

    template <typename T, typename Size>
    inline bool stack<T,Size>::empty() const
    {
        return !this->_top;
    }

    template <typename T, typename Size>
    inline typename stack<T,Size>::size_type const& stack<T,Size>::size() const
    {
        return this->_size;
    }

    template <typename T, typename Size>
    inline typename stack<T,Size>::value_type const& stack<T,Size>::top() const
    {
        return **this->_top;
    }

    template <typename T, typename Size>
    inline void stack<T,Size>::push(value_type const& t)
    {
        allocator_type alloc;
        typename _node_t::traits::pointer p = (
            ::std::allocator_traits<allocator_type>::allocate(alloc, 1)
        );
        ::std::allocator_traits<allocator_type>::construct(alloc, p, t);
        if (this->_top) p->insert_next(this->_top);
        this->_top = p;
        ++this->_size;
    }

    template <typename T, typename Size>
    inline void stack<T,Size>::push(value_type&& t)
    {
        allocator_type alloc;
        typename _node_t::traits::pointer p = (
            ::std::allocator_traits<allocator_type>::allocate(alloc, 1)
        );
        ::std::allocator_traits<allocator_type>::construct(alloc, p, ::std::move(t));
        if (this->_top) p->insert_next(this->_top);
        this->_top = p;
        ++this->_size;
    }

    template <typename T, typename Size>
    template <typename ...Args>
    inline typename stack<T,Size>::value_type const& stack<T,Size>::emplace(Args&&... args)
    {
        allocator_type alloc;
        typename _node_t::traits::pointer p = (
            ::std::allocator_traits<allocator_type>::allocate(alloc, 1)
        );
        ::std::allocator_traits<allocator_type>::construct(
            alloc,
            p,
            ::std::forward<Args>(args)...
        );
        if (this->_top) p->insert_next(this->_top);
        this->_top = p;
        ++this->_size;
        return **this->_top;
    }

    template <typename T, typename Size>
    inline void stack<T,Size>::pop()
    {
        allocator_type alloc;
        typename _node_t::traits::pointer p = this->_top;
        this->_top = this->_top->next();
        ::std::allocator_traits<allocator_type>::destroy(alloc, p);
        ::std::allocator_traits<allocator_type>::deallocate(alloc, p, 1);
        --this->_size;
    }

    template <typename T, typename Size>
    void stack<T,Size>::clear()
    {
        allocator_type alloc;

        for (typename _node_t::traits::pointer p = this->_top; p; p = this->_top)
        {
            this->_top = this->_top->next();
            ::std::allocator_traits<allocator_type>::destroy(alloc, p);
            ::std::allocator_traits<allocator_type>::deallocate(alloc, p, 1);
        }

        this->_size = ::boost::initialized_value;
    }
}}}  // namespace odds_and_ends::node::container

#endif  // ODDS_AND_ENDS__NODE__CONTAINER__STACK_HPP

