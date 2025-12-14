// Copyright (C) 2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__CONTAINER__STACK_HPP
#define ODDS_AND_ENDS__NODE__CONTAINER__STACK_HPP

#include <cstddef>
#include <memory>
#include <odds_and_ends/node/data.hpp>
#include <odds_and_ends/node/linked/base.hpp>
#include <odds_and_ends/composite_type/composite_type.hpp>
#include <odds_and_ends/static_introspection/concept/is_stack_or_heap.hpp>
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
    class stack
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
        typedef ::odds_and_ends::node::container::stack<T,Size,AllocGen> type;
        typedef typename ::boost::mpl::apply_wrap1<AllocGen,_node_t>::type allocator_type;

    private:
        allocator_type _alloc;
        _pointer _top;
        Size _size;

    public:
        typedef T value_type;
        typedef value_type& reference;
        typedef value_type const& const_reference;
        typedef Size size_type;

        template <typename A0>
        explicit stack(
            A0&& a0,
            typename ::boost::disable_if<
                ::odds_and_ends::static_introspection::concept::is_stack_or_heap<A0>,
                _enabler
            >::type = _enabler()
        );

        template <typename A0, typename A1, typename ...Args>
        stack(
            A0&& a0,
            A1&& a1,
            Args&&... args,
            typename ::boost::disable_if<
                typename ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection::concept::is_stack_or_heap<A0>,
                    ::odds_and_ends::static_introspection::concept::is_allocator<A1>,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename V, typename I, typename AG>
        stack(
            stack<V,I,AG> const& copy,
            typename ::boost::enable_if< ::std::is_convertible<V,T>,_enabler>::type = _enabler()
        );

        template <typename Alloc>
        stack(
            stack const& copy,
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename V, typename I, typename AG, typename Alloc>
        stack(
            stack<V,I,AG> const& copy,
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
        stack(
            stack<V,I,AG>&& source,
            typename ::boost::enable_if< ::std::is_convertible<V,T>,_enabler>::type = _enabler()
        );

        template <typename Alloc>
        stack(
            stack&& source,
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename V, typename I, typename AG, typename Alloc>
        stack(
            stack<V,I,AG>&& source,
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

        stack(stack const& copy);
        stack(stack&& source);
        stack();
        ~stack();
        stack& operator=(stack const& copy);
        stack& operator=(stack&& source);

        template <typename V, typename I, typename AG>
        typename ::boost::enable_if< ::std::is_convertible<V,T>,stack&>::type
            operator=(stack<V,I,AG> const& copy);

        template <typename V, typename I, typename AG>
        typename ::boost::enable_if< ::std::is_convertible<V,T>,stack&>::type
            operator=(stack<V,I,AG>&& source);

        allocator_type get_allocator() const;
        bool empty() const;
        size_type const& size() const;
        const_reference top() const;
        void push(const_reference t);
        void push(value_type&& t);

        template <typename ...Args>
        value_type const& emplace(Args&&... args);

        void pop();
        void clear();

    private:
        typedef typename _node_t::traits::const_pointer _const_pointer;

        allocator_type const& _get_allocator_ref() const;
        _const_pointer _get_top() const;

        template <typename V, typename I, typename AG>
        void _clone(stack<V,I,AG> const& copy);

        template <typename V, typename I, typename AG>
        void _move(stack<V,I,AG>&& source);

        template <typename V, typename I, typename AG>
        friend class stack;
    };
}}}  // namespace odds_and_ends::node::container

#include <utility>
#include <boost/utility/value_init.hpp>

namespace odds_and_ends { namespace node { namespace container {

    template <typename T, typename Size, typename AllocGen>
    template <typename A0>
    inline stack<T,Size,AllocGen>::stack(
        A0&& a0,
        typename ::boost::disable_if<
            ::odds_and_ends::static_introspection::concept::is_stack_or_heap<A0>,
            _enabler
        >::type
    ) : _alloc(::std::forward<A0>(a0)),
        _top(nullptr),
        _size(::boost::initialized_value)
    {
    }

    template <typename T, typename Size, typename AllocGen>
    template <typename A0, typename A1, typename ...Args>
    inline stack<T,Size,AllocGen>::stack(
        A0&& a0,
        A1&& a1,
        Args&&... args,
        typename ::boost::disable_if<
            typename ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::concept::is_stack_or_heap<A0>,
                ::odds_and_ends::static_introspection::concept::is_allocator<A1>,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _alloc(::std::forward<A0>(a0), ::std::forward<A1>(a1), ::std::forward<Args>(args)...),
        _top(nullptr),
        _size(::boost::initialized_value)
    {
    }

    template <typename T, typename Size, typename AllocGen>
    template <typename V, typename I, typename AG>
    void stack<T,Size,AllocGen>::_clone(stack<V,I,AG> const& copy)
    {
        typename stack<V,I,AG>::_const_pointer o_p = copy._get_top();
        _pointer q;

        for (_pointer p; o_p; o_p = o_p->next())
        {
            p = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);
            ::std::allocator_traits<allocator_type>::construct(this->_alloc, p, **o_p);

            if (this->_top)
            {
                q->insert_next(p);
            }
            else
            {
                this->_top = p;
            }

            q = p;
            ++this->_size;
        }
    }

    template <typename T, typename Size, typename AllocGen>
    inline stack<T,Size,AllocGen>::stack(stack const& copy) :
        _alloc(copy._get_allocator_ref()), _top(nullptr), _size(::boost::initialized_value)
    {
        this->_clone(copy);
    }

    template <typename T, typename Size, typename AllocGen>
    template <typename V, typename I, typename AG>
    inline stack<T,Size,AllocGen>::stack(
        stack<V,I,AG> const& copy,
        typename ::boost::enable_if< ::std::is_convertible<V,T>,_enabler>::type
    ) : _alloc(copy._get_allocator_ref()), _top(nullptr), _size(::boost::initialized_value)
    {
        this->_clone(copy);
    }

    template <typename T, typename Size, typename AllocGen>
    template <typename Alloc>
    inline stack<T,Size,AllocGen>::stack(
        stack const& copy,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _alloc(alloc), _top(nullptr), _size(::boost::initialized_value)
    {
        this->_clone(copy);
    }

    template <typename T, typename Size, typename AllocGen>
    template <typename V, typename I, typename AG, typename Alloc>
    inline stack<T,Size,AllocGen>::stack(
        stack<V,I,AG> const& copy,
        Alloc const& alloc,
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::std::is_convertible<V,T>,
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _alloc(alloc), _top(nullptr), _size(::boost::initialized_value)
    {
        this->_clone(copy);
    }

    template <typename T, typename Size, typename AllocGen>
    template <typename V, typename I, typename AG>
    void stack<T,Size,AllocGen>::_move(stack<V,I,AG>&& source)
    {
        this->_clone(static_cast<stack<V,I,AG> const&>(source));
        source.clear();
    }

    template <typename T, typename Size, typename AllocGen>
    inline stack<T,Size,AllocGen>::stack(stack&& source) :
        _alloc(source._get_allocator_ref()), _top(nullptr), _size(::boost::initialized_value)
    {
        this->_move(static_cast<stack&&>(source));
    }

    template <typename T, typename Size, typename AllocGen>
    template <typename V, typename I, typename AG>
    inline stack<T,Size,AllocGen>::stack(
        stack<V,I,AG>&& source,
        typename ::boost::enable_if< ::std::is_convertible<V,T>,_enabler>::type
    ) : _alloc(source._get_allocator_ref()), _top(nullptr), _size(::boost::initialized_value)
    {
        this->_move(static_cast<stack<V,I,AG>&&>(source));
    }

    template <typename T, typename Size, typename AllocGen>
    template <typename Alloc>
    inline stack<T,Size,AllocGen>::stack(
        stack&& source,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _alloc(alloc), _top(nullptr), _size(::boost::initialized_value)
    {
        this->_move(static_cast<stack&&>(source));
    }

    template <typename T, typename Size, typename AllocGen>
    template <typename V, typename I, typename AG, typename Alloc>
    inline stack<T,Size,AllocGen>::stack(
        stack<V,I,AG>&& source,
        Alloc const& alloc,
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::std::is_convertible<V,T>,
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _alloc(alloc), _top(nullptr), _size(::boost::initialized_value)
    {
        this->_move(static_cast<stack<V,I,AG>&&>(source));
    }

    template <typename T, typename Size, typename AllocGen>
    inline stack<T,Size,AllocGen>::stack() :
        _alloc(), _top(nullptr), _size(::boost::initialized_value)
    {
    }

    template <typename T, typename Size, typename AllocGen>
    inline stack<T,Size,AllocGen>::~stack()
    {
        this->clear();
    }

    template <typename T, typename Size, typename AllocGen>
    inline stack<T,Size,AllocGen>& stack<T,Size,AllocGen>::operator=(stack const& copy)
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
    inline typename ::boost::enable_if< ::std::is_convertible<V,T>,stack<T,Size,AllocGen>&>::type
        stack<T,Size,AllocGen>::operator=(stack<V,I,AG> const& copy)
    {
        if (this != &copy)
        {
            this->clear();
            this->_clone(copy);
        }

        return *this;
    }

    template <typename T, typename Size, typename AllocGen>
    inline stack<T,Size,AllocGen>& stack<T,Size,AllocGen>::operator=(stack&& source)
    {
        if (this != &static_cast<stack&>(source))
        {
            this->clear();
            this->_move(static_cast<stack&&>(source));
        }

        return *this;
    }

    template <typename T, typename Size, typename AllocGen>
    template <typename V, typename I, typename AG>
    inline typename ::boost::enable_if< ::std::is_convertible<V,T>,stack<T,Size,AllocGen>&>::type
        stack<T,Size,AllocGen>::operator=(stack<V,I,AG>&& source)
    {
        if (this != &static_cast<stack<V,I,AG>&>(source))
        {
            this->clear();
            this->_move(static_cast<stack<V,I,AG>&&>(source));
        }

        return *this;
    }

    template <typename T, typename Size, typename AllocGen>
    inline typename stack<T,Size,AllocGen>::allocator_type
        stack<T,Size,AllocGen>::get_allocator() const
    {
        return this->_alloc;
    }

    template <typename T, typename Size, typename AllocGen>
    inline typename stack<T,Size,AllocGen>::allocator_type const&
        stack<T,Size,AllocGen>::_get_allocator_ref() const
    {
        return this->_alloc;
    }

    template <typename T, typename Size, typename AllocGen>
    inline typename stack<T,Size,AllocGen>::_const_pointer stack<T,Size,AllocGen>::_get_top() const
    {
        return this->_top;
    }

    template <typename T, typename Size, typename AllocGen>
    inline bool stack<T,Size,AllocGen>::empty() const
    {
        return !this->_top;
    }

    template <typename T, typename Size, typename AllocGen>
    inline typename stack<T,Size,AllocGen>::size_type const& stack<T,Size,AllocGen>::size() const
    {
        return this->_size;
    }

    template <typename T, typename Size, typename AllocGen>
    inline typename stack<T,Size,AllocGen>::const_reference stack<T,Size,AllocGen>::top() const
    {
        return **this->_top;
    }

    template <typename T, typename Size, typename AllocGen>
    inline void stack<T,Size,AllocGen>::push(const_reference t)
    {
        _pointer p = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);
        ::std::allocator_traits<allocator_type>::construct(this->_alloc, p, t);
        if (this->_top) p->insert_next(this->_top);
        this->_top = p;
        ++this->_size;
    }

    template <typename T, typename Size, typename AllocGen>
    inline void stack<T,Size,AllocGen>::push(value_type&& t)
    {
        _pointer p = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);
        ::std::allocator_traits<allocator_type>::construct(this->_alloc, p, ::std::move(t));
        if (this->_top) p->insert_next(this->_top);
        this->_top = p;
        ++this->_size;
    }

    template <typename T, typename Size, typename AllocGen>
    template <typename ...Args>
    inline typename stack<T,Size,AllocGen>::value_type const&
        stack<T,Size,AllocGen>::emplace(Args&&... args)
    {
        _pointer p = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);
        ::std::allocator_traits<allocator_type>::construct(
            this->_alloc,
            p,
            ::std::forward<Args>(args)...
        );
        if (this->_top) p->insert_next(this->_top);
        this->_top = p;
        ++this->_size;
        return **this->_top;
    }

    template <typename T, typename Size, typename AllocGen>
    inline void stack<T,Size,AllocGen>::pop()
    {
        _pointer p = this->_top;
        this->_top = this->_top->next();
        ::std::allocator_traits<allocator_type>::destroy(this->_alloc, p);
        ::std::allocator_traits<allocator_type>::deallocate(this->_alloc, p, 1);
        --this->_size;
    }

    template <typename T, typename Size, typename AllocGen>
    void stack<T,Size,AllocGen>::clear()
    {
        for (_pointer p = this->_top; p; p = this->_top)
        {
            this->_top = this->_top->next();
            ::std::allocator_traits<allocator_type>::destroy(this->_alloc, p);
            ::std::allocator_traits<allocator_type>::deallocate(this->_alloc, p, 1);
        }

        this->_size = ::boost::initialized_value;
    }
}}}  // namespace odds_and_ends::node::container

#endif  // ODDS_AND_ENDS__NODE__CONTAINER__STACK_HPP

