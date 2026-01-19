// Copyright (C) 2025-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__CONTAINER__QUEUE_HPP
#define ODDS_AND_ENDS__NODE__CONTAINER__QUEUE_HPP

#include <cstddef>
#include <type_traits>
#include <memory>
#include <odds_and_ends/node/data.hpp>
#include <odds_and_ends/node/linked/base.hpp>
#include <odds_and_ends/composite_type/composite_type.hpp>
#include <odds_and_ends/static_introspection/concept/is_queue.hpp>
#include <odds_and_ends/static_introspection/concept/is_allocator.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_input_iterator.hpp>
#include <boost/core/enable_if.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/quote.hpp>
#include <boost/mpl/apply_wrap.hpp>

namespace odds_and_ends { namespace node { namespace container {

    template <
        typename T,
        typename Size = ::std::size_t,
        typename AllocGen = ::boost::mpl::quote1< ::std::allocator>
    >
    class queue
    {
        typedef ::odds_and_ends::composite_type::composite_type<
            ::boost::mpl::deque<
                ::odds_and_ends::node::data<T>,
                ::odds_and_ends::node::linked::base<>
            >
        > _node_t;
        typedef typename _node_t::traits::pointer _pointer;

        struct _enabler
        {
        };

    public:
        typedef ::odds_and_ends::node::container::queue<T,Size,AllocGen> type;
        typedef typename ::boost::mpl::apply_wrap1<AllocGen,_node_t>::type allocator_type;

    private:
        allocator_type _alloc;
        _pointer _front;
        _pointer _back;
        Size _size;

    public:
        typedef T value_type;
        typedef value_type& reference;
        typedef value_type const& const_reference;
        typedef Size size_type;

        template <typename A0>
        explicit queue(
            A0&& a0,
            typename ::boost::disable_if<
                ::odds_and_ends::static_introspection::concept::is_queue<A0>,
                _enabler
            >::type = _enabler()
        );

        template <typename A0, typename A1>
        queue(
            A0&& a0,
            A1&& a1,
            typename ::boost::disable_if<
                typename ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::concept::is_legacy_input_iterator<A0>,
                    ::odds_and_ends::static_introspection::concept::is_legacy_input_iterator<A1>,
                    ::boost::mpl::if_<
                        ::odds_and_ends::static_introspection::concept::is_queue<A0>,
                        ::odds_and_ends::static_introspection::concept::is_allocator<A1>,
                        ::boost::mpl::false_
                    >
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename A0, typename A1, typename A2, typename ...Args>
        queue(
            A0&& a0,
            A1&& a1,
            A2&& a2,
            Args&&... args,
            typename ::boost::disable_if<
                typename ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::concept::is_legacy_input_iterator<A0>,
                    ::boost::mpl::if_<
                        ::std::is_same<A0,A1>,
                        ::odds_and_ends::static_introspection::concept::is_allocator<A2>,
                        ::boost::mpl::false_
                    >,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename Itr>
        queue(
            Itr itr_begin,
            Itr itr_end,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_legacy_input_iterator<Itr>,
                _enabler
            >::type = _enabler()
        );

        template <typename Itr, typename Alloc>
        queue(
            Itr itr_begin,
            Itr itr_end,
            Alloc const& alloc,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection::concept::is_legacy_input_iterator<Itr>,
                    ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename V, typename I, typename AG>
        queue(
            queue<V,I,AG> const& copy,
            typename ::boost::enable_if< ::std::is_convertible<V,T>,_enabler>::type = _enabler()
        );

        template <typename Alloc>
        queue(
            queue const& copy,
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename V, typename I, typename AG, typename Alloc>
        queue(
            queue<V,I,AG> const& copy,
            Alloc const& alloc,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::std::is_convertible<V,T>,
                    ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename V, typename I, typename AG>
        queue(
            queue<V,I,AG>&& source,
            typename ::boost::enable_if< ::std::is_convertible<V,T>,_enabler>::type = _enabler()
        );

        template <typename Alloc>
        queue(
            queue&& source,
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename V, typename I, typename AG, typename Alloc>
        queue(
            queue<V,I,AG>&& source,
            Alloc const& alloc,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::std::is_convertible<V,T>,
                    ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        queue(queue const& copy);
        queue(queue&& source);
        queue();
        ~queue();
        queue& operator=(queue const& copy);
        queue& operator=(queue&& source);

        template <typename V, typename I, typename AG>
        typename ::boost::enable_if< ::std::is_convertible<V,T>,queue&>::type
            operator=(queue<V,I,AG> const& copy);

        template <typename V, typename I, typename AG>
        typename ::boost::enable_if< ::std::is_convertible<V,T>,queue&>::type
            operator=(queue<V,I,AG>&& source);

        allocator_type get_allocator() const;
        bool empty() const;
        size_type const& size() const;
        const_reference front() const;
        void push(const_reference t);
        void push(value_type&& t);

        template <typename ...Args>
        const_reference emplace(Args&&... args);

        void pop();
        void clear();

    private:
        typedef typename _node_t::traits::const_pointer _const_pointer;

        allocator_type const& _get_allocator_ref() const;
        allocator_type& _get_allocator_ref();
        _const_pointer _get_front() const;

        template <typename V, typename I, typename AG>
        void _clone(queue<V,I,AG> const& copy);

        template <typename V, typename I, typename AG>
        void _move(queue<V,I,AG>&& source);

        template <typename V, typename I, typename AG>
        friend class queue;
    };
}}}  // namespace odds_and_ends::node::container

#include <utility>
#include <boost/utility/value_init.hpp>

namespace odds_and_ends { namespace node { namespace container {

    template <typename T, typename Size, typename AllocGen>
    inline queue<T,Size,AllocGen>::queue() :
        _alloc(), _front(nullptr), _back(nullptr), _size(::boost::initialized_value)
    {
    }

    template <typename T, typename Size, typename AllocGen>
    template <typename A0>
    inline queue<T,Size,AllocGen>::queue(
        A0&& a0,
        typename ::boost::disable_if<
            ::odds_and_ends::static_introspection::concept::is_queue<A0>,
            _enabler
        >::type
    ) : _alloc(::std::forward<A0>(a0)),
        _front(nullptr),
        _back(nullptr),
        _size(::boost::initialized_value)
    {
    }

    template <typename T, typename Size, typename AllocGen>
    template <typename A0, typename A1>
    inline queue<T,Size,AllocGen>::queue(
        A0&& a0,
        A1&& a1,
        typename ::boost::disable_if<
            typename ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept::is_legacy_input_iterator<A0>,
                ::odds_and_ends::static_introspection::concept::is_legacy_input_iterator<A1>,
                ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection::concept::is_queue<A0>,
                    ::odds_and_ends::static_introspection::concept::is_allocator<A1>,
                    ::boost::mpl::false_
                >
            >::type,
            _enabler
        >::type
    ) : _alloc(::std::forward<A0>(a0), ::std::forward<A1>(a1)),
        _front(nullptr),
        _back(nullptr),
        _size(::boost::initialized_value)
    {
    }

    template <typename T, typename Size, typename AllocGen>
    template <typename A0, typename A1, typename A2, typename ...Args>
    inline queue<T,Size,AllocGen>::queue(
        A0&& a0,
        A1&& a1,
        A2&& a2,
        Args&&... args,
        typename ::boost::disable_if<
            typename ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept::is_legacy_input_iterator<A0>,
                ::boost::mpl::if_<
                    ::std::is_same<A0,A1>,
                    ::odds_and_ends::static_introspection::concept::is_allocator<A2>,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _alloc(
            ::std::forward<A0>(a0),
            ::std::forward<A1>(a1),
            ::std::forward<A2>(a2),
            ::std::forward<Args>(args)...
        ),
        _front(nullptr),
        _back(nullptr),
        _size(::boost::initialized_value)
    {
    }

    template <typename T, typename Size, typename AllocGen>
    template <typename Itr>
    inline queue<T,Size,AllocGen>::queue(
        Itr itr,
        Itr itr_end,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_legacy_input_iterator<Itr>,
            _enabler
        >::type
    ) : _alloc(), _front(nullptr), _back(nullptr), _size(::boost::initialized_value)
    {
        for (_pointer p; itr != itr_end; ++itr)
        {
            p = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);
            ::std::allocator_traits<allocator_type>::construct(this->_alloc, p, *itr);

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

    template <typename T, typename Size, typename AllocGen>
    template <typename Itr, typename Alloc>
    inline queue<T,Size,AllocGen>::queue(
        Itr itr,
        Itr itr_end,
        Alloc const& alloc,
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::concept::is_legacy_input_iterator<Itr>,
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _alloc(alloc), _front(nullptr), _back(nullptr), _size(::boost::initialized_value)
    {
        for (_pointer p; itr != itr_end; ++itr)
        {
            p = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);
            ::std::allocator_traits<allocator_type>::construct(this->_alloc, p, *itr);

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

    template <typename T, typename Size, typename AllocGen>
    template <typename V, typename I, typename AG>
    void queue<T,Size,AllocGen>::_clone(queue<V,I,AG> const& copy)
    {
        typename queue<V,I,AG>::_const_pointer q = copy._get_front();

        for (_pointer p; q; q = q->next())
        {
            p = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);
            ::std::allocator_traits<allocator_type>::construct(this->_alloc, p, **q);

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

    template <typename T, typename Size, typename AllocGen>
    inline queue<T,Size,AllocGen>::queue(queue const& copy) :
        _alloc(copy._get_allocator_ref()),
        _front(nullptr),
        _back(nullptr),
        _size(::boost::initialized_value)
    {
        this->_clone(copy);
    }

    template <typename T, typename Size, typename AllocGen>
    template <typename V, typename I, typename AG>
    inline queue<T,Size,AllocGen>::queue(
        queue<V,I,AG> const& copy,
        typename ::boost::enable_if< ::std::is_convertible<V,T>,_enabler>::type
    ) : _alloc(copy._get_allocator_ref()),
        _front(nullptr),
        _back(nullptr),
        _size(::boost::initialized_value)
    {
        this->_clone(copy);
    }

    template <typename T, typename Size, typename AllocGen>
    template <typename Alloc>
    inline queue<T,Size,AllocGen>::queue(
        queue const& copy,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _alloc(alloc), _front(nullptr), _back(nullptr), _size(::boost::initialized_value)
    {
        this->_clone(copy);
    }

    template <typename T, typename Size, typename AllocGen>
    template <typename V, typename I, typename AG, typename Alloc>
    inline queue<T,Size,AllocGen>::queue(
        queue<V,I,AG> const& copy,
        Alloc const& alloc,
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::std::is_convertible<V,T>,
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _alloc(alloc), _front(nullptr), _back(nullptr), _size(::boost::initialized_value)
    {
        this->_clone(copy);
    }

    template <typename T, typename Size, typename AllocGen>
    template <typename V, typename I, typename AG>
    void queue<T,Size,AllocGen>::_move(queue<V,I,AG>&& source)
    {
        for (_pointer p; !source.empty(); source.pop())
        {
            p = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);
            ::std::allocator_traits<allocator_type>::construct(
                this->_alloc,
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

    template <typename T, typename Size, typename AllocGen>
    inline queue<T,Size,AllocGen>::queue(queue&& source) :
        _alloc(source._get_allocator_ref()),
        _front(nullptr),
        _back(nullptr),
        _size(::boost::initialized_value)
    {
        this->_move(static_cast<queue&&>(source));
    }

    template <typename T, typename Size, typename AllocGen>
    template <typename V, typename I, typename AG>
    inline queue<T,Size,AllocGen>::queue(
        queue<V,I,AG>&& source,
        typename ::boost::enable_if< ::std::is_convertible<V,T>,_enabler>::type
    ) : _alloc(source._get_allocator_ref()),
        _front(nullptr),
        _back(nullptr),
        _size(::boost::initialized_value)
    {
        this->_move(static_cast<queue<V,I,AG>&&>(source));
    }

    template <typename T, typename Size, typename AllocGen>
    template <typename Alloc>
    inline queue<T,Size,AllocGen>::queue(
        queue&& source,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _alloc(alloc), _front(nullptr), _back(nullptr), _size(::boost::initialized_value)
    {
        this->_move(static_cast<queue&&>(source));
    }

    template <typename T, typename Size, typename AllocGen>
    template <typename V, typename I, typename AG, typename Alloc>
    inline queue<T,Size,AllocGen>::queue(
        queue<V,I,AG>&& source,
        Alloc const& alloc,
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::std::is_convertible<V,T>,
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _alloc(alloc), _front(nullptr), _back(nullptr), _size(::boost::initialized_value)
    {
        this->_move(static_cast<queue<V,I,AG>&&>(source));
    }

    template <typename T, typename Size, typename AllocGen>
    inline queue<T,Size,AllocGen>::~queue()
    {
        this->clear();
    }

    template <typename T, typename Size, typename AllocGen>
    inline queue<T,Size,AllocGen>& queue<T,Size,AllocGen>::operator=(queue const& copy)
    {
        if (this != &copy)
        {
            this->clear();
            this->_clone(copy);
        }

        return *this;
    }

    template <typename T, typename Size, typename AllocGen>
    template <typename V, typename I, typename AG>
    inline typename ::boost::enable_if< ::std::is_convertible<V,T>,queue<T,Size,AllocGen>&>::type
        queue<T,Size,AllocGen>::operator=(queue<V,I,AG> const& copy)
    {
        if (this != &copy)
        {
            this->clear();
            this->_clone(copy);
        }

        return *this;
    }

    template <typename T, typename Size, typename AllocGen>
    inline queue<T,Size,AllocGen>& queue<T,Size,AllocGen>::operator=(queue&& source)
    {
        if (this != &static_cast<queue&>(source))
        {
            this->clear();
            this->_move(static_cast<queue&&>(source));
        }

        return *this;
    }

    template <typename T, typename Size, typename AllocGen>
    template <typename V, typename I, typename AG>
    inline typename ::boost::enable_if< ::std::is_convertible<V,T>,queue<T,Size,AllocGen>&>::type
        queue<T,Size,AllocGen>::operator=(queue<V,I,AG>&& source)
    {
        if (this != &static_cast<queue<V,I,AG>&>(source))
        {
            this->clear();
            this->_move(static_cast<queue<V,I,AG>&&>(source));
        }

        return *this;
    }

    template <typename T, typename Size, typename AllocGen>
    inline typename queue<T,Size,AllocGen>::allocator_type queue<T,Size,AllocGen>::get_allocator() const
    {
        return this->_alloc;
    }

    template <typename T, typename Size, typename AllocGen>
    inline typename queue<T,Size,AllocGen>::allocator_type const&
        queue<T,Size,AllocGen>::_get_allocator_ref() const
    {
        return this->_alloc;
    }

    template <typename T, typename Size, typename AllocGen>
    inline typename queue<T,Size,AllocGen>::allocator_type&
        queue<T,Size,AllocGen>::_get_allocator_ref()
    {
        return this->_alloc;
    }

    template <typename T, typename Size, typename AllocGen>
    inline typename queue<T,Size,AllocGen>::_const_pointer
        queue<T,Size,AllocGen>::_get_front() const
    {
        return this->_front;
    }

    template <typename T, typename Size, typename AllocGen>
    inline bool queue<T,Size,AllocGen>::empty() const
    {
        return !this->_front;
    }

    template <typename T, typename Size, typename AllocGen>
    inline typename queue<T,Size,AllocGen>::size_type const& queue<T,Size,AllocGen>::size() const
    {
        return this->_size;
    }

    template <typename T, typename Size, typename AllocGen>
    inline typename queue<T,Size,AllocGen>::value_type const& queue<T,Size,AllocGen>::front() const
    {
        return **this->_front;
    }

    template <typename T, typename Size, typename AllocGen>
    inline void queue<T,Size,AllocGen>::push(const_reference t)
    {
        _pointer p = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);
        ::std::allocator_traits<allocator_type>::construct(this->_alloc, p, t);

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

    template <typename T, typename Size, typename AllocGen>
    inline void queue<T,Size,AllocGen>::push(value_type&& t)
    {
        _pointer p = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);
        ::std::allocator_traits<allocator_type>::construct(this->_alloc, p, ::std::move(t));

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

    template <typename T, typename Size, typename AllocGen>
    template <typename ...Args>
    inline typename queue<T,Size,AllocGen>::const_reference
        queue<T,Size,AllocGen>::emplace(Args&&... args)
    {
        _pointer p = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);
        ::std::allocator_traits<allocator_type>::construct(
            this->_alloc,
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

    template <typename T, typename Size, typename AllocGen>
    inline void queue<T,Size,AllocGen>::pop()
    {
        _pointer p = this->_front;
        this->_front = this->_front->next();

        if (!this->_front)
        {
            this->_back = nullptr;
        }

        ::std::allocator_traits<allocator_type>::destroy(this->_alloc, p);
        ::std::allocator_traits<allocator_type>::deallocate(this->_alloc, p, 1);
        --this->_size;
    }

    template <typename T, typename Size, typename AllocGen>
    void queue<T,Size,AllocGen>::clear()
    {
        for (_pointer p = this->_front; p; p = this->_front)
        {
            this->_front = this->_front->next();
            ::std::allocator_traits<allocator_type>::destroy(this->_alloc, p);
            ::std::allocator_traits<allocator_type>::deallocate(this->_alloc, p, 1);
        }

        this->_back = nullptr;
        this->_size = ::boost::initialized_value;
    }
}}}  // namespace odds_and_ends::node::container

#endif  // ODDS_AND_ENDS__NODE__CONTAINER__QUEUE_HPP

