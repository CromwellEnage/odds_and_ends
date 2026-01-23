// Copyright (C) 2025-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__CONTAINER__LIST_HPP
#define ODDS_AND_ENDS__NODE__CONTAINER__LIST_HPP

#include <cstddef>
#include <type_traits>
#include <memory>
#include <initializer_list>
#include <odds_and_ends/node/data.hpp>
#include <odds_and_ends/node/linked/doubly.hpp>
#include <odds_and_ends/node/iterator/list.hpp>
#include <odds_and_ends/node/iterator/indirect.hpp>
#include <odds_and_ends/composite_type/composite_type.hpp>
#include <odds_and_ends/static_introspection/concept/is_single_pass_range.hpp>
#include <odds_and_ends/static_introspection/concept/is_allocator.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_input_iterator.hpp>
#include <boost/core/enable_if.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/quote.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/limits.hpp>

namespace odds_and_ends { namespace node { namespace container {

    template <
        typename T,
        typename Size = ::std::size_t,
        typename PtrXForm = ::boost::mpl::quote1< ::std::add_pointer>,
        typename AllocXForm = ::boost::mpl::quote1< ::std::allocator>
    >
    class list
    {
        struct _enabler
        {
        };

    public:
        typedef ::odds_and_ends::node::container::list<T,Size,PtrXForm,AllocXForm> type;
        typedef Size size_type;
        typedef T value_type;
        typedef value_type& reference;
        typedef value_type const& const_reference;
        typedef typename ::boost::mpl::apply_wrap1<PtrXForm,value_type>::type pointer;
        typedef typename ::boost::mpl::apply_wrap1<PtrXForm,value_type const>::type const_pointer;
        typedef ::odds_and_ends::composite_type::composite_type<
            ::boost::mpl::deque<
                ::odds_and_ends::node::data<T>,
                ::odds_and_ends::node::linked::doubly<PtrXForm>
            >
        > node_type;

    private:
        typedef ::odds_and_ends::node::list_iterator<node_type,::boost::mpl::false_> _itr_t;
        typedef ::odds_and_ends::node::list_iterator<node_type const,::boost::mpl::false_> _c_itr_t;
        typedef ::odds_and_ends::node::list_iterator<node_type,::boost::mpl::true_> _r_itr_t;
        typedef ::odds_and_ends::node::list_iterator<node_type const,::boost::mpl::true_> _c_r_itr_t;
        typedef typename node_type::traits::pointer _node_ptr_t;

    public:
        typedef typename ::boost::mpl::apply_wrap1<AllocXForm,node_type>::type allocator_type;
        typedef ::odds_and_ends::node::indirect_iterator<_itr_t,PtrXForm> iterator;
        typedef ::odds_and_ends::node::indirect_iterator<_c_itr_t,PtrXForm> const_iterator;
        typedef ::odds_and_ends::node::indirect_iterator<_r_itr_t,PtrXForm> reverse_iterator;
        typedef ::odds_and_ends::node
        ::indirect_iterator<_c_r_itr_t,PtrXForm> const_reverse_iterator;

    private:
        allocator_type _alloc;
        _node_ptr_t _front;
        _node_ptr_t _back;
        size_type _size;

    public:
        template <typename A0>
        explicit list(
            A0&& a0,
            typename ::boost::disable_if<
                ::odds_and_ends::static_introspection::concept::is_single_pass_range<A0>,
                _enabler
            >::type = _enabler()
        );

        template <typename A0, typename A1>
        list(
            A0&& a0,
            A1&& a1,
            typename ::boost::disable_if<
                typename ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::concept::is_legacy_input_iterator<A0>,
                    ::odds_and_ends::static_introspection::concept::is_legacy_input_iterator<A1>,
                    ::boost::mpl::if_<
                        ::odds_and_ends::static_introspection
                        ::concept::is_single_pass_range<A0>,
                        ::odds_and_ends::static_introspection::concept::is_allocator<A1>,
                        ::boost::mpl::false_
                    >
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename A0, typename A1, typename A2, typename ...Args>
        list(
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

        template <typename Alloc>
        list(
            ::std::initializer_list<value_type> l,
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename Itr>
        list(
            Itr itr_begin,
            Itr itr_end,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_legacy_input_iterator<Itr>,
                _enabler
            >::type = _enabler()
        );

        template <typename Itr, typename Alloc>
        list(
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

        template <typename V, typename S, typename PX, typename AX>
        list(
            list<V,S,PX,AX> const& copy,
            typename ::boost::enable_if< ::std::is_convertible<V,T>,_enabler>::type = _enabler()
        );

        template <typename Alloc>
        list(
            list const& copy,
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename V, typename S, typename PX, typename AX, typename Alloc>
        list(
            list<V,S,PX,AX> const& copy,
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

        template <typename V, typename S, typename PX, typename AX>
        list(
            list<V,S,PX,AX>&& source,
            typename ::boost::enable_if< ::std::is_convertible<V,T>,_enabler>::type = _enabler()
        );

        template <typename Alloc>
        list(
            list&& source,
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename V, typename S, typename PX, typename AX, typename Alloc>
        list(
            list<V,S,PX,AX>&& source,
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

        list(::std::initializer_list<value_type> l);
        list(list const& copy);
        list(list&& source);
        list();
        ~list();
        list& operator=(::std::initializer_list<value_type> l);
        list& operator=(list const& copy);
        list& operator=(list&& source);
        allocator_type get_allocator() const;
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
        bool empty() const;
        size_type const& size() const;
        const_reference front() const;
        reference front();
        const_reference back() const;
        reference back();
        void push_front(const_reference t);
        void push_front(typename ::std::remove_reference<value_type>::type&& t);
        void push_back(const_reference t);
        void push_back(typename ::std::remove_reference<value_type>::type&& t);
        iterator insert(const_iterator pos, const_reference t);
        iterator
            insert(const_iterator pos, typename ::std::remove_reference<value_type>::type&& t);
        iterator insert(const_iterator pos, size_type n, const_reference t);

        template <typename Iterator>
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_legacy_input_iterator<Iterator>,
            iterator
        >::type
            insert(const_iterator pos, Iterator itr_begin, Iterator itr_end);

        template <typename ...Args>
        void emplace_front(Args&& ...args);

        template <typename ...Args>
        void emplace_back(Args&& ...args);

        template <typename ...Args>
        iterator emplace(const_iterator pos, Args&& ...args);

        iterator erase(const_iterator pos);
        iterator erase(const_iterator itr_begin, const_iterator itr_end);
        void pop_front();
        void pop_back();
        void swap(list& other);
        void clear();
        static size_type max_size();

    private:
        void _push_front(_node_ptr_t p);
        void _push_back(_node_ptr_t p);
        void _insert(_c_itr_t pos, _node_ptr_t p);
        _node_ptr_t _erase(_node_ptr_t p);

        template <typename Itr>
        void _init(Itr itr_begin, Itr itr_end);

        template <typename V, typename S, typename PX, typename AX>
        void _clone(list<V,S,PX,AX> const& copy);

        template <typename V, typename S, typename PX, typename AX>
        void _move(list<V,S,PX,AX>&& copy);

        template <typename V, typename S, typename PX, typename AX>
        friend class list;
    };
}}}  // namespace odds_and_ends::node::container

#include <utility>
#include <boost/utility/value_init.hpp>
#include <boost/assert.hpp>

namespace odds_and_ends { namespace node { namespace container {

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline list<T,Size,PtrXForm,AllocXForm>::list() :
        _alloc(), _front(nullptr), _back(nullptr), _size(::boost::initialized_value)
    {
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    template <typename A0>
    inline list<T,Size,PtrXForm,AllocXForm>::list(
        A0&& a0,
        typename ::boost::disable_if<
            ::odds_and_ends::static_introspection::concept::is_single_pass_range<A0>,
            _enabler
        >::type
    ) : _alloc(::std::forward<A0>(a0)),
        _front(nullptr),
        _back(nullptr),
        _size(::boost::initialized_value)
    {
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    template <typename A0, typename A1>
    inline list<T,Size,PtrXForm,AllocXForm>::list(
        A0&& a0,
        A1&& a1,
        typename ::boost::disable_if<
            typename ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept::is_legacy_input_iterator<A0>,
                ::odds_and_ends::static_introspection::concept::is_legacy_input_iterator<A1>,
                ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection
                    ::concept::is_single_pass_range<A0>,
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

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    template <typename A0, typename A1, typename A2, typename ...Args>
    inline list<T,Size,PtrXForm,AllocXForm>::list(
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

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    template <typename Itr>
    void list<T,Size,PtrXForm,AllocXForm>::_init(Itr itr, Itr itr_end)
    {
        for (_node_ptr_t p; itr != itr_end; ++itr)
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

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline list<T,Size,PtrXForm,AllocXForm>::list(::std::initializer_list<value_type> l) :
        _alloc(), _front(nullptr), _back(nullptr), _size(::boost::initialized_value)
    {
        this->_init(l.begin(), l.end());
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    template <typename Alloc>
    inline list<T,Size,PtrXForm,AllocXForm>::list(
        ::std::initializer_list<value_type> l,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _alloc(alloc), _front(nullptr), _back(nullptr), _size(::boost::initialized_value)
    {
        this->_init(l.begin(), l.end());
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    template <typename Itr>
    inline list<T,Size,PtrXForm,AllocXForm>::list(
        Itr itr_begin,
        Itr itr_end,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_legacy_input_iterator<Itr>,
            _enabler
        >::type
    ) : _alloc(), _front(nullptr), _back(nullptr), _size(::boost::initialized_value)
    {
        this->_init(itr_begin, itr_end);
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    template <typename Itr, typename Alloc>
    inline list<T,Size,PtrXForm,AllocXForm>::list(
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
        >::type
    ) : _alloc(alloc), _front(nullptr), _back(nullptr), _size(::boost::initialized_value)
    {
        this->_init(itr_begin, itr_end);
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    template <typename V, typename S, typename PX, typename AX>
    void list<T,Size,PtrXForm,AllocXForm>::_clone(list<V,S,PX,AX> const& copy)
    {
        typename list<V,S,PX,AX>::node_type::traits::const_pointer q = copy._front;

        for (_node_ptr_t p; q; q = q->next())
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

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline list<T,Size,PtrXForm,AllocXForm>::list(list const& copy) :
        _alloc(copy._alloc), _front(nullptr), _back(nullptr), _size(::boost::initialized_value)
    {
        this->_clone(copy);
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    template <typename Alloc>
    inline list<T,Size,PtrXForm,AllocXForm>::list(
        list const& copy,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _alloc(_alloc), _front(nullptr), _back(nullptr), _size(::boost::initialized_value)
    {
        this->_clone(copy);
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    template <typename V, typename S, typename PX, typename AX>
    inline list<T,Size,PtrXForm,AllocXForm>::list(
        list<V,S,PX,AX> const& copy,
        typename ::boost::enable_if< ::std::is_convertible<V,T>,_enabler>::type
    ) : _alloc(copy._alloc), _front(nullptr), _back(nullptr), _size(::boost::initialized_value)
    {
        this->_clone(copy);
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    template <typename V, typename S, typename PX, typename AX, typename Alloc>
    inline list<T,Size,PtrXForm,AllocXForm>::list(
        list<V,S,PX,AX> const& copy,
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

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    template <typename V, typename S, typename PX, typename AX>
    void list<T,Size,PtrXForm,AllocXForm>::_move(list<V,S,PX,AX>&& source)
    {
        for (_node_ptr_t p; !source.empty(); source.pop_front())
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

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline list<T,Size,PtrXForm,AllocXForm>::list(list&& source) :
        _alloc(source._alloc), _front(nullptr), _back(nullptr), _size(::boost::initialized_value)
    {
        this->_move(static_cast<list&&>(source));
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    template <typename Alloc>
    inline list<T,Size,PtrXForm,AllocXForm>::list(
        list&& source,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _alloc(alloc), _front(nullptr), _back(nullptr), _size(::boost::initialized_value)
    {
        this->_move(static_cast<list&&>(source));
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    template <typename V, typename S, typename PX, typename AX>
    inline list<T,Size,PtrXForm,AllocXForm>::list(
        list<V,S,PX,AX>&& source,
        typename ::boost::enable_if< ::std::is_convertible<V,T>,_enabler>::type
    ) : _alloc(source._alloc), _front(nullptr), _back(nullptr), _size(::boost::initialized_value)
    {
        this->_move(static_cast<list<V,S,PX,AX>&&>(source));
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    template <typename V, typename S, typename PX, typename AX, typename Alloc>
    inline list<T,Size,PtrXForm,AllocXForm>::list(
        list<V,S,PX,AX>&& source,
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
        this->_move(static_cast<list<V,S,PX,AX>&&>(source));
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    void list<T,Size,PtrXForm,AllocXForm>::clear()
    {
        for (_node_ptr_t p = this->_front; p; p = this->_front)
        {
            this->_front = this->_front->next();
            ::std::allocator_traits<allocator_type>::destroy(this->_alloc, p);
            ::std::allocator_traits<allocator_type>::deallocate(this->_alloc, p, 1);
        }

        this->_back = nullptr;
        this->_size = ::boost::initialized_value;
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline list<T,Size,PtrXForm,AllocXForm>::~list()
    {
        this->clear();
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline list<T,Size,PtrXForm,AllocXForm>&
        list<T,Size,PtrXForm,AllocXForm>::operator=(::std::initializer_list<value_type> l)
    {
        this->clear();
        this->_init(l.begin(), l.end());
        return *this;
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline list<T,Size,PtrXForm,AllocXForm>&
        list<T,Size,PtrXForm,AllocXForm>::operator=(list const& copy)
    {
        if (this != &copy)
        {
            this->clear();
            this->_clone(copy);
        }

        return *this;
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline list<T,Size,PtrXForm,AllocXForm>&
        list<T,Size,PtrXForm,AllocXForm>::operator=(list&& source)
    {
        if (this != &static_cast<list&>(source))
        {
            this->clear();
            this->_move(::std::move(source));
        }

        return *this;
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline bool list<T,Size,PtrXForm,AllocXForm>::empty() const
    {
        return !this->_front;
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline typename list<T,Size,PtrXForm,AllocXForm>::size_type const&
        list<T,Size,PtrXForm,AllocXForm>::size() const
    {
        return this->_size;
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline typename list<T,Size,PtrXForm,AllocXForm>::size_type
        list<T,Size,PtrXForm,AllocXForm>::max_size()
    {
        return (::std::numeric_limits<size_type>::max)();
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline typename list<T,Size,PtrXForm,AllocXForm>::const_iterator
        list<T,Size,PtrXForm,AllocXForm>::cbegin() const
    {
        return const_iterator(_c_itr_t(this->_front, this->_back));
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline typename list<T,Size,PtrXForm,AllocXForm>::const_iterator
        list<T,Size,PtrXForm,AllocXForm>::begin() const
    {
        return const_iterator(_c_itr_t(this->_front, this->_back));
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline typename list<T,Size,PtrXForm,AllocXForm>::iterator
        list<T,Size,PtrXForm,AllocXForm>::begin()
    {
        return iterator(_itr_t(this->_front, this->_back));
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline typename list<T,Size,PtrXForm,AllocXForm>::const_iterator
        list<T,Size,PtrXForm,AllocXForm>::cend() const
    {
        return const_iterator(_c_itr_t(nullptr, this->_back));
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline typename list<T,Size,PtrXForm,AllocXForm>::const_iterator
        list<T,Size,PtrXForm,AllocXForm>::end() const
    {
        return const_iterator(_c_itr_t(nullptr, this->_back));
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline typename list<T,Size,PtrXForm,AllocXForm>::iterator
        list<T,Size,PtrXForm,AllocXForm>::end()
    {
        return iterator(_itr_t(nullptr, this->_back));
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline typename list<T,Size,PtrXForm,AllocXForm>::const_reverse_iterator
        list<T,Size,PtrXForm,AllocXForm>::crbegin() const
    {
        return const_reverse_iterator(_c_r_itr_t(this->_back, this->_front));
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline typename list<T,Size,PtrXForm,AllocXForm>::const_reverse_iterator
        list<T,Size,PtrXForm,AllocXForm>::rbegin() const
    {
        return const_reverse_iterator(_c_r_itr_t(this->_back, this->_front));
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline typename list<T,Size,PtrXForm,AllocXForm>::reverse_iterator
        list<T,Size,PtrXForm,AllocXForm>::rbegin()
    {
        return reverse_iterator(_r_itr_t(this->_back, this->_front));
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline typename list<T,Size,PtrXForm,AllocXForm>::const_reverse_iterator
        list<T,Size,PtrXForm,AllocXForm>::crend() const
    {
        return const_reverse_iterator(_c_r_itr_t(nullptr, this->_front));
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline typename list<T,Size,PtrXForm,AllocXForm>::const_reverse_iterator
        list<T,Size,PtrXForm,AllocXForm>::rend() const
    {
        return const_reverse_iterator(_c_r_itr_t(nullptr, this->_front));
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline typename list<T,Size,PtrXForm,AllocXForm>::reverse_iterator
        list<T,Size,PtrXForm,AllocXForm>::rend()
    {
        return reverse_iterator(_r_itr_t(nullptr, this->_front));
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline typename list<T,Size,PtrXForm,AllocXForm>::const_reference
        list<T,Size,PtrXForm,AllocXForm>::front() const
    {
        return **this->_front;
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline typename list<T,Size,PtrXForm,AllocXForm>::reference
        list<T,Size,PtrXForm,AllocXForm>::front()
    {
        return **this->_front;
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline typename list<T,Size,PtrXForm,AllocXForm>::const_reference
        list<T,Size,PtrXForm,AllocXForm>::back() const
    {
        return **this->_back;
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline typename list<T,Size,PtrXForm,AllocXForm>::reference
        list<T,Size,PtrXForm,AllocXForm>::back()
    {
        return **this->_back;
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline void list<T,Size,PtrXForm,AllocXForm>::_push_front(_node_ptr_t p)
    {
        if (this->_front)
        {
            this->_front->insert_prior(p);
        }

        this->_front = p;

        if (!this->_back)
        {
            this->_back = p;
        }

        ++this->_size;
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline void list<T,Size,PtrXForm,AllocXForm>::push_front(const_reference t)
    {
        _node_ptr_t p = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);
        ::std::allocator_traits<allocator_type>::construct(this->_alloc, p, t);
        this->_push_front(p);
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline void
        list<T,Size,PtrXForm,AllocXForm>::push_front(
            typename ::std::remove_reference<value_type>::type&& t
        )
    {
        _node_ptr_t p = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);
        ::std::allocator_traits<allocator_type>::construct(this->_alloc, p, ::std::move(t));
        this->_push_front(p);
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    template <typename ...Args>
    inline void list<T,Size,PtrXForm,AllocXForm>::emplace_front(Args&&... args)
    {
        _node_ptr_t p = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);
        ::std::allocator_traits<allocator_type>::construct(
            this->_alloc,
            p,
            ::std::forward<Args>(args)...
        );
        this->_push_front(p);
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline void list<T,Size,PtrXForm,AllocXForm>::_push_back(_node_ptr_t p)
    {
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

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline void list<T,Size,PtrXForm,AllocXForm>::push_back(const_reference t)
    {
        _node_ptr_t p = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);
        ::std::allocator_traits<allocator_type>::construct(this->_alloc, p, t);
        this->_push_back(p);
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline void
        list<T,Size,PtrXForm,AllocXForm>::push_back(
            typename ::std::remove_reference<value_type>::type&& t
        )
    {
        _node_ptr_t p = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);
        ::std::allocator_traits<allocator_type>::construct(this->_alloc, p, ::std::move(t));
        this->_push_back(p);
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    template <typename ...Args>
    inline void list<T,Size,PtrXForm,AllocXForm>::emplace_back(Args&&... args)
    {
        _node_ptr_t p = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);
        ::std::allocator_traits<allocator_type>::construct(
            this->_alloc,
            p,
            ::std::forward<Args>(args)...
        );
        this->_push_back(p);
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline void list<T,Size,PtrXForm,AllocXForm>::_insert(_c_itr_t pos, _node_ptr_t p)
    {
        _node_ptr_t q = const_cast<_node_ptr_t>(pos.operator->());

        q->insert_prior(p);

        if (q == this->_front)
        {
            this->_front = p;
        }
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline typename list<T,Size,PtrXForm,AllocXForm>::iterator
        list<T,Size,PtrXForm,AllocXForm>::insert(const_iterator pos, const_reference t)
    {
        BOOST_ASSERT_MSG(
            this->_back == pos.base()._last(),
            "The iterator does not point to any position in this container!"
        );

        if (pos == this->cend())
        {
            this->push_back(t);
            return this->end();
        }
        else
        {
            _node_ptr_t p = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);
            ::std::allocator_traits<allocator_type>::construct(this->_alloc, p, t);
            this->_insert(pos.base(), p);
            return iterator(_itr_t(p, this->_back));
        }
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline typename list<T,Size,PtrXForm,AllocXForm>::iterator
        list<T,Size,PtrXForm,AllocXForm>::insert(
            const_iterator pos,
            typename ::std::remove_reference<value_type>::type&& t
        )
    {
        BOOST_ASSERT_MSG(
            this->_back == pos.base()._last(),
            "The iterator does not point to any position in this container!"
        );

        if (pos == this->cend())
        {
            this->push_back(::std::move(t));
            return this->end();
        }
        else
        {
            _node_ptr_t p = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);
            ::std::allocator_traits<allocator_type>::construct(this->_alloc, p, ::std::move(t));
            this->_insert(pos.base(), p);
            return iterator(_itr_t(p, this->_back));
        }
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    template <typename ...Args>
    inline typename list<T,Size,PtrXForm,AllocXForm>::iterator
        list<T,Size,PtrXForm,AllocXForm>::emplace(const_iterator pos, Args&&... args)
    {
        BOOST_ASSERT_MSG(
            this->_back == pos.base()._last(),
            "The iterator does not point to any position in this container!"
        );

        if (pos == this->cend())
        {
            this->emplace_back(::std::forward<Args>(args)...);
            return this->end();
        }
        else
        {
            _node_ptr_t p = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);
            ::std::allocator_traits<allocator_type>::construct(
                this->_alloc,
                p,
                ::std::forward<Args>(args)...
            );
            this->_insert(pos.base(), p);
            return iterator(_itr_t(p, this->_back));
        }
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline typename list<T,Size,PtrXForm,AllocXForm>::iterator
        list<T,Size,PtrXForm,AllocXForm>::insert(const_iterator pos, size_type n, const_reference t)
    {
        BOOST_ASSERT_MSG(
            this->_back == pos.base()._last(),
            "The iterator does not point to any position in this container!"
        );

        if (n)
        {
            if (pos == this->cend())
            {
                this->push_back(t);

                iterator result = this->end();

                for (--result; --n; this->push_back(t))
                {
                }

                return result;
            }
            else
            {
                iterator result = this->insert(pos, t);

                for (; --n; this->insert(pos, t))
                {
                }

                return result;
            }
        }
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    template <typename Itr>
    typename ::boost::enable_if<
        ::odds_and_ends::static_introspection::concept::is_legacy_input_iterator<Itr>,
        typename list<T,Size,PtrXForm,AllocXForm>::iterator
    >::type
        list<T,Size,PtrXForm,AllocXForm>::insert(const_iterator pos, Itr itr, Itr itr_end)
    {
        if (itr != itr_end)
        {
            BOOST_ASSERT_MSG(
                this->_back == pos.base()._last(),
                "The iterator does not point to any position in this container!"
            );

            if (pos == this->cend())
            {
                this->push_back(*itr);

                iterator result = this->end();

                for (--result; ++itr != itr_end; this->push_back(*itr))
                {
                }

                return result;
            }
            else
            {
                iterator result = this->insert(pos, *itr);

                for (; ++itr != itr_end; this->insert(pos, *itr))
                {
                }

                return result;
            }
        }
        else if (pos == this->cend())
        {
            return this->end();
        }
        else
        {
            return iterator(_itr_t(const_cast<_node_ptr_t>(pos.base().operator->()), this->_back));
        }
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline void list<T,Size,PtrXForm,AllocXForm>::pop_front()
    {
        _node_ptr_t p = this->_front;
        this->_front = this->_front->next();

        if (this->_front)
        {
            this->_front->erase_prior();
        }
        else
        {
            this->_back = nullptr;
        }

        ::std::allocator_traits<allocator_type>::destroy(this->_alloc, p);
        ::std::allocator_traits<allocator_type>::deallocate(this->_alloc, p, 1);
        --this->_size;
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline void list<T,Size,PtrXForm,AllocXForm>::pop_back()
    {
        _node_ptr_t p = this->_back;
        this->_back = this->_back->prior();

        if (this->_back)
        {
            this->_back->erase_next();
        }
        else
        {
            this->_front = nullptr;
        }

        ::std::allocator_traits<allocator_type>::destroy(this->_alloc, p);
        ::std::allocator_traits<allocator_type>::deallocate(this->_alloc, p, 1);
        --this->_size;
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline typename list<T,Size,PtrXForm,AllocXForm>::_node_ptr_t
        list<T,Size,PtrXForm,AllocXForm>::_erase(_node_ptr_t p)
    {
        if (p == this->_front)
        {
            this->pop_front();
            return this->_front;
        }
        else if (p == this->_back)
        {
            this->pop_back();
            return nullptr;
        }
        else
        {
            _node_ptr_t q = p->next();

            p = q->erase_prior();
            ::std::allocator_traits<allocator_type>::destroy(this->_alloc, p);
            ::std::allocator_traits<allocator_type>::deallocate(this->_alloc, p, 1);
            --this->_size;
            return q;
        }
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline typename list<T,Size,PtrXForm,AllocXForm>::iterator
        list<T,Size,PtrXForm,AllocXForm>::erase(const_iterator pos)
    {
        BOOST_ASSERT_MSG(
            this->_back == pos.base()._last(),
            "The iterator does not point to any position in this container!"
        );
        return iterator(
            _itr_t(this->_erase(const_cast<_node_ptr_t>(pos.base().operator->())), this->_back)
        );
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    typename list<T,Size,PtrXForm,AllocXForm>::iterator
        list<T,Size,PtrXForm,AllocXForm>::erase(const_iterator itr, const_iterator itr_end)
    {
        iterator result = this->end();

        if (itr_end != this->cend())
        {
            result = iterator(
                _itr_t(const_cast<_node_ptr_t>(itr_end.base().operator->()), this->_back)
            );
        }

        for (; itr != itr_end; itr = result)
        {
            result = this->erase(itr);
        }

        return result;
    }

    template <typename T, typename Size, typename PtrXForm, typename AllocXForm>
    inline void list<T,Size,PtrXForm,AllocXForm>::swap(list& other)
    {
        using ::std::swap;
        swap(this->_front, other._front);
        swap(this->_back, other._back);
        swap(this->_size, other._size);
    }
}}}  // namespace odds_and_ends::node::container

#endif  // ODDS_AND_ENDS__NODE__CONTAINER__LIST_HPP

