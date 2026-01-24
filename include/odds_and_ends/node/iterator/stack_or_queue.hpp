// Copyright (C) 2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__ITERATOR__STACK_OR_QUEUE_HPP
#define ODDS_AND_ENDS__NODE__ITERATOR__STACK_OR_QUEUE_HPP

#include <cstddef>
#include <type_traits>
#include <memory>
#include <iterator>
#include <odds_and_ends/node/container/stack.hpp>
#include <odds_and_ends/node/container/queue.hpp>
#include <boost/core/enable_if.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/quote.hpp>
#include <boost/mpl/apply_wrap.hpp>

namespace odds_and_ends { namespace node {

    template <
        typename T,
        typename IsStack,
        typename Size = ::std::size_t,
        typename XForm = ::boost::mpl::quote1< ::std::add_pointer>,
        typename AllocGen = ::boost::mpl::quote1< ::std::allocator>
    >
    class stack_or_queue_iterator
    {
        typedef typename ::boost::mpl::if_<
            IsStack,
            ::odds_and_ends::node::container::stack<T,Size,AllocGen>,
            ::odds_and_ends::node::container::queue<T,Size,AllocGen>
        >::type _stack_or_queue_t;

        _stack_or_queue_t _stack_or_queue;

    public:
        typedef ::std::input_iterator_tag iterator_category;
        typedef T value_type;
        typedef typename ::boost::mpl::apply_wrap1<XForm,value_type const>::type pointer;
        typedef value_type const& reference;

        stack_or_queue_iterator();
        stack_or_queue_iterator(stack_or_queue_iterator const& other);
        stack_or_queue_iterator(stack_or_queue_iterator&& other);
        stack_or_queue_iterator& operator=(stack_or_queue_iterator const& other);
        stack_or_queue_iterator& operator=(stack_or_queue_iterator&& other);
        operator bool() const;
        reference operator*() const;
        pointer operator->() const;
        stack_or_queue_iterator& operator++();
        stack_or_queue_iterator operator++(int);
        void operator()(reference t);
        void operator()(value_type&& t);

        template <typename ...Args>
        void operator()(Args&&... args);

    private:
        reference _get(::boost::mpl::true_) const;
        reference _get(::boost::mpl::false_) const;

        template <
            typename T1,
            typename I1,
            typename S1,
            typename X1,
            typename A1,
            typename T2,
            typename I2,
            typename S2,
            typename X2,
            typename A2
        >
        friend typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
            operator==(
                stack_or_queue_iterator<T1,I1,S1,X1,A2> const& lhs,
                stack_or_queue_iterator<T2,I2,S2,X2,A2> const& rhs
            );

        template <typename U, typename I, typename S, typename X, typename A>
        friend class stack_or_queue_iterator;
    };
}}  // namespace odds_and_ends::node

#include <utility>
#include <boost/utility/value_init.hpp>
#include <boost/assert.hpp>

namespace odds_and_ends { namespace node {

    template <
        typename T,
        typename IsStack,
        typename Size,
        typename XForm,
        typename AllocGen
    >
    inline stack_or_queue_iterator<T,IsStack,Size,XForm,AllocGen>::stack_or_queue_iterator() :
        _stack_or_queue()
    {
    }

    template <
        typename T,
        typename IsStack,
        typename Size,
        typename XForm,
        typename AllocGen
    >
    inline stack_or_queue_iterator<T,IsStack,Size,XForm,AllocGen>::stack_or_queue_iterator(
        stack_or_queue_iterator const& other
    ) : _stack_or_queue(other._stack_or_queue)
    {
    }

    template <
        typename T,
        typename IsStack,
        typename Size,
        typename XForm,
        typename AllocGen
    >
    inline stack_or_queue_iterator<T,IsStack,Size,XForm,AllocGen>::stack_or_queue_iterator(
        stack_or_queue_iterator&& other
    ) : _stack_or_queue(::std::move(other._stack_or_queue))
    {
    }

    template <
        typename T,
        typename IsStack,
        typename Size,
        typename XForm,
        typename AllocGen
    >
    inline stack_or_queue_iterator<T,IsStack,Size,XForm,AllocGen>&
        stack_or_queue_iterator<T,IsStack,Size,XForm,AllocGen>::operator=(
            stack_or_queue_iterator const& other
        )
    {
        if (this != &other)
        {
            this->_stack_or_queue = other._stack_or_queue;
        }

        return *this;
    }

    template <
        typename T,
        typename IsStack,
        typename Size,
        typename XForm,
        typename AllocGen
    >
    inline stack_or_queue_iterator<T,IsStack,Size,XForm,AllocGen>&
        stack_or_queue_iterator<T,IsStack,Size,XForm,AllocGen>::operator=(
            stack_or_queue_iterator&& other
        )
    {
        if (this != &static_cast<stack_or_queue_iterator&>(other))
        {
            this->_stack_or_queue = ::std::move(other._stack_or_queue);
        }

        return *this;
    }

    template <
        typename T,
        typename IsStack,
        typename Size,
        typename XForm,
        typename AllocGen
    >
    inline void stack_or_queue_iterator<T,IsStack,Size,XForm,AllocGen>::operator()(reference t)
    {
        this->_stack_or_queue.push(t);
    }

    template <
        typename T,
        typename IsStack,
        typename Size,
        typename XForm,
        typename AllocGen
    >
    inline void stack_or_queue_iterator<T,IsStack,Size,XForm,AllocGen>::operator()(value_type&& t)
    {
        this->_stack_or_queue.push(::std::move(t));
    }

    template <
        typename T,
        typename IsStack,
        typename Size,
        typename XForm,
        typename AllocGen
    >
    template <typename ...Args>
    inline void stack_or_queue_iterator<T,IsStack,Size,XForm,AllocGen>::operator()(Args&&... args)
    {
        this->_stack_or_queue.emplace(::std::forward<Args>(args)...);
    }

    template <
        typename T,
        typename IsStack,
        typename Size,
        typename XForm,
        typename AllocGen
    >
    inline stack_or_queue_iterator<T,IsStack,Size,XForm,AllocGen>::operator bool() const
    {
        return !this->_stack_or_queue.empty();
    }

    template <
        typename T,
        typename IsStack,
        typename Size,
        typename XForm,
        typename AllocGen
    >
    inline typename stack_or_queue_iterator<T,IsStack,Size,XForm,AllocGen>::reference
        stack_or_queue_iterator<T,IsStack,Size,XForm,AllocGen>::_get(::boost::mpl::true_) const
    {
        return this->_stack_or_queue.top();
    }

    template <
        typename T,
        typename IsStack,
        typename Size,
        typename XForm,
        typename AllocGen
    >
    inline typename stack_or_queue_iterator<T,IsStack,Size,XForm,AllocGen>::reference
        stack_or_queue_iterator<T,IsStack,Size,XForm,AllocGen>::_get(::boost::mpl::false_) const
    {
        return this->_stack_or_queue.front();
    }

    template <
        typename T,
        typename IsStack,
        typename Size,
        typename XForm,
        typename AllocGen
    >
    inline typename stack_or_queue_iterator<T,IsStack,Size,XForm,AllocGen>::reference
        stack_or_queue_iterator<T,IsStack,Size,XForm,AllocGen>::operator*() const
    {
        return this->_get(IsStack());
    }

    template <
        typename T,
        typename IsStack,
        typename Size,
        typename XForm,
        typename AllocGen
    >
    inline typename stack_or_queue_iterator<T,IsStack,Size,XForm,AllocGen>::pointer
        stack_or_queue_iterator<T,IsStack,Size,XForm,AllocGen>::operator->() const
    {
        return ::std::pointer_traits<pointer>::pointer_to(this->_get(IsStack()));
    }

    template <
        typename T,
        typename IsStack,
        typename Size,
        typename XForm,
        typename AllocGen
    >
    inline stack_or_queue_iterator<T,IsStack,Size,XForm,AllocGen>&
        stack_or_queue_iterator<T,IsStack,Size,XForm,AllocGen>::operator++()
    {
        this->_stack_or_queue.pop();
        return *this;
    }

    template <
        typename T,
        typename IsStack,
        typename Size,
        typename XForm,
        typename AllocGen
    >
    stack_or_queue_iterator<T,IsStack,Size,XForm,AllocGen>
        stack_or_queue_iterator<T,IsStack,Size,XForm,AllocGen>::operator++(int)
    {
        stack_or_queue_iterator result(*this);
        ++(*this);
        return result;
    }

    template <
        typename T1,
        typename I1,
        typename S1,
        typename X1,
        typename A1,
        typename T2,
        typename I2,
        typename S2,
        typename X2,
        typename A2
    >
    inline typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
        operator==(
            stack_or_queue_iterator<T1,I1,S1,X1,A2> const& lhs,
            stack_or_queue_iterator<T2,I2,S2,X2,A2> const& rhs
        )
    {
        if (lhs._stack_or_queue.empty())
        {
            return rhs._stack_or_queue.empty();
        }
        else if (rhs._stack_or_queue.empty())
        {
            return false;
        }
        else
        {
            return lhs._get(I1()) == rhs._get(I2());
        }
    }

    template <
        typename T1,
        typename I1,
        typename S1,
        typename X1,
        typename A1,
        typename T2,
        typename I2,
        typename S2,
        typename X2,
        typename A2
    >
    inline typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
        operator!=(
            stack_or_queue_iterator<T1,I1,S1,X1,A2> const& lhs,
            stack_or_queue_iterator<T2,I2,S2,X2,A2> const& rhs
        )
    {
        return !(lhs == rhs);
    }
}}  // namespace odds_and_ends::node

#endif  // ODDS_AND_ENDS__NODE__ITERATOR__STACK_OR_QUEUE_HPP

