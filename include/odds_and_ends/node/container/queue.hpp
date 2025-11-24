// Copyright (C) 2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__CONTAINER__QUEUE_HPP
#define ODDS_AND_ENDS__NODE__CONTAINER__QUEUE_HPP

#include <cstddef>
#include <type_traits>
#include <memory>
#include <odds_and_ends/node/data.hpp>
#include <odds_and_ends/node/linked/base.hpp>
#include <odds_and_ends/composite_type/composite_type.hpp>
#include <boost/core/enable_if.hpp>
#include <boost/mpl/deque.hpp>

namespace odds_and_ends { namespace node { namespace container {

    template <typename T, typename Size = ::std::size_t>
    class queue
    {
        typedef ::odds_and_ends::composite_type::composite_type<
            ::boost::mpl::deque<
                ::odds_and_ends::node::data<T>,
                ::odds_and_ends::node::linked::base<>
            >
        > _node_t;
        typedef ::std::allocator<_node_t> allocator_type;

        struct _enabler
        {
        };

        typename _node_t::traits::pointer _front;
        typename _node_t::traits::pointer _back;
        Size _size;

    public:
        typedef T value_type;
        typedef Size size_type;

        queue();

        template <typename Itr>
        queue(Itr itr_begin, Itr itr_end);

        template <typename U, typename S>
        queue(
            queue<U,S> const& copy,
            typename ::boost::enable_if< ::std::is_convertible<U,T>,_enabler>::type = _enabler()
        );

        template <typename U, typename S>
        queue(
            queue<U,S>&& source,
            typename ::boost::enable_if< ::std::is_convertible<U,T>,_enabler>::type = _enabler()
        );

        ~queue();

        template <typename U, typename S>
        typename ::boost::enable_if< ::std::is_convertible<U,T>,queue&>::type
            operator=(queue<U,S> const& copy);

        template <typename U, typename S>
        typename ::boost::enable_if< ::std::is_convertible<U,T>,queue&>::type
            operator=(queue<U,S>&& source);

        bool empty() const;

        Size const& size() const;

        value_type const& front() const;

        void push(value_type const& t);

        void push(value_type&& t);

        template <typename ...Args>
        value_type const& emplace(Args&&... args);

        void pop();

        void clear();
    };
}}}  // namespace odds_and_ends::node::container

#include <utility>
#include <boost/utility/value_init.hpp>

namespace odds_and_ends { namespace node { namespace container {

    template <typename T, typename Size>
    inline queue<T,Size>::queue() :
        _front(nullptr), _back(nullptr), _size(::boost::initialized_value)
    {
    }

    template <typename T, typename Size>
    template <typename Itr>
    inline queue<T,Size>::queue(Itr itr, Itr itr_end) :
        _front(nullptr), _back(nullptr), _size(::boost::initialized_value)
    {
        allocator_type alloc;

        for (typename _node_t::traits::pointer p; itr != itr_end; ++itr)
        {
            p = ::std::allocator_traits<allocator_type>::allocate(alloc, 1);
            ::std::allocator_traits<allocator_type>::construct(alloc, p, *itr);

            if (this->_back)
            {
                this->_back->insert_next(p);
            }

            this->_back = p;

            if (!this->_front)
            {
                this->_front = p;
            }

            ++this->_size;
        }
    }

    template <typename T, typename Size>
    template <typename U, typename S>
    inline queue<T,Size>::queue(
        queue<U,S> const& copy,
        typename ::boost::enable_if< ::std::is_convertible<U,T>,_enabler>::type
    ) : _front(nullptr), _back(nullptr), _size(::boost::initialized_value)
    {
        allocator_type alloc;
        typename queue<U,S>::_node::traits::pointer q = copy._front;

        for (typename _node_t::traits::pointer p; q; q = q->next())
        {
            p = ::std::allocator_traits<allocator_type>::allocate(alloc, 1);
            ::std::allocator_traits<allocator_type>::construct(alloc, p, **q);

            if (this->_back)
            {
                this->_back->insert_next(p);
            }

            this->_back = p;

            if (!this->_front)
            {
                this->_front = p;
            }

            ++this->_size;
        }
    }

    template <typename T, typename Size>
    template <typename U, typename S>
    inline queue<T,Size>::queue(
        queue<U,S>&& source,
        typename ::boost::enable_if< ::std::is_convertible<U,T>,_enabler>::type
    ) : _front(nullptr), _back(nullptr), _size(::boost::initialized_value)
    {
        allocator_type alloc;

        for (typename _node_t::traits::pointer p; !source.empty(); source.pop())
        {
            p = ::std::allocator_traits<allocator_type>::allocate(alloc, 1);
            ::std::allocator_traits<allocator_type>::construct(
                alloc,
                p,
                ::std::move(source.front())
            );

            if (this->_back)
            {
                this->_back->insert_next(p);
            }

            this->_back = p;

            if (!this->_front)
            {
                this->_front = p;
            }

            ++this->_size;
        }
    }

    template <typename T, typename Size>
    inline queue<T,Size>::~queue()
    {
        this->clear();
    }

    template <typename T, typename Size>
    template <typename U, typename S>
    inline typename ::boost::enable_if< ::std::is_convertible<U,T>,queue<T,Size>&>::type
        queue<T,Size>::operator=(queue<U,S> const& copy)
    {
        if (this != &copy)
        {
            this->clear();

            allocator_type alloc;
            typename queue<U,S>::_node::traits::pointer q = copy._front;

            for (typename _node_t::traits::pointer p; q; q = q->next())
            {
                p = ::std::allocator_traits<allocator_type>::allocate(alloc, 1);
                ::std::allocator_traits<allocator_type>::construct(alloc, p, **q);

                if (this->_back)
                {
                    this->_back->insert_next(p);
                }

                this->_back = p;

                if (!this->_front)
                {
                    this->_front = p;
                }

                ++this->_size;
            }
        }

        return *this;
    }

    template <typename T, typename Size>
    template <typename U, typename S>
    inline typename ::boost::enable_if< ::std::is_convertible<U,T>,queue<T,Size>&>::type
        queue<T,Size>::operator=(queue<U,S>&& source)
    {
        if (this != &static_cast<queue<U,S>&&>(source))
        {
            this->clear();

            allocator_type alloc;

            for (typename _node_t::traits::pointer p; !source.empty(); source.pop())
            {
                p = ::std::allocator_traits<allocator_type>::allocate(alloc, 1);
                ::std::allocator_traits<allocator_type>::construct(
                    alloc,
                    p,
                    ::std::move(source.front())
                );

                if (this->_back)
                {
                    this->_back->insert_next(p);
                }

                this->_back = p;

                if (!this->_front)
                {
                    this->_front = p;
                }

                ++this->_size;
            }
        }

        return *this;
    }

    template <typename T, typename Size>
    inline bool queue<T,Size>::empty() const
    {
        return !this->_front;
    }

    template <typename T, typename Size>
    inline Size const& queue<T,Size>::size() const
    {
        return this->_size;
    }

    template <typename T, typename Size>
    inline typename queue<T,Size>::value_type const& queue<T,Size>::front() const
    {
        return **this->_front;
    }

    template <typename T, typename Size>
    inline void queue<T,Size>::push(value_type const& t)
    {
        allocator_type alloc;
        typename _node_t::traits::pointer p = (
            ::std::allocator_traits<allocator_type>::allocate(alloc, 1)
        );
        ::std::allocator_traits<allocator_type>::construct(alloc, p, t);

        if (this->_back)
        {
            this->_back->insert_next(p);
        }

        this->_back = p;

        if (!this->_front)
        {
            this->_front = p;
        }

        ++this->_size;
    }

    template <typename T, typename Size>
    inline void queue<T,Size>::push(value_type&& t)
    {
        allocator_type alloc;
        typename _node_t::traits::pointer p = (
            ::std::allocator_traits<allocator_type>::allocate(alloc, 1)
        );
        ::std::allocator_traits<allocator_type>::construct(alloc, p, ::std::move(t));

        if (this->_back)
        {
            this->_back->insert_next(p);
        }

        this->_back = p;

        if (!this->_front)
        {
            this->_front = p;
        }

        ++this->_size;
    }

    template <typename T, typename Size>
    template <typename ...Args>
    inline typename queue<T,Size>::value_type const& queue<T,Size>::emplace(Args&&... args)
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

        if (this->_back)
        {
            this->_back->insert_next(p);
        }

        this->_back = p;

        if (!this->_front)
        {
            this->_front = p;
        }

        ++this->_size;
        return **this->_back;
    }

    template <typename T, typename Size>
    inline void queue<T,Size>::pop()
    {
        allocator_type alloc;
        typename _node_t::traits::pointer p = this->_front;
        this->_front = this->_front->next();

        if (!this->_front)
        {
            this->_back = nullptr;
        }

        ::std::allocator_traits<allocator_type>::destroy(alloc, p);
        ::std::allocator_traits<allocator_type>::deallocate(alloc, p, 1);
        --this->_size;
    }

    template <typename T, typename Size>
    void queue<T,Size>::clear()
    {
        allocator_type alloc;

        for (typename _node_t::traits::pointer p = this->_front; p; p = this->_front)
        {
            this->_front = this->_front->next();
            ::std::allocator_traits<allocator_type>::destroy(alloc, p);
            ::std::allocator_traits<allocator_type>::deallocate(alloc, p, 1);
        }

        this->_back = nullptr;
        this->_size = ::boost::initialized_value;
    }
}}}  // namespace odds_and_ends::node::container

#endif  // ODDS_AND_ENDS__NODE__CONTAINER__QUEUE_HPP

