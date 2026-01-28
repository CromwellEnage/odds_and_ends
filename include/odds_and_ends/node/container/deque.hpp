// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__CONTAINER__DEQUE_HPP
#define ODDS_AND_ENDS__NODE__CONTAINER__DEQUE_HPP

#include <cstddef>
#include <type_traits>
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
#include <odds_and_ends/static_introspection/concept/is_legacy_input_iterator.hpp>
#include <boost/parameter/optional.hpp>
#include <boost/parameter/required.hpp>
#include <boost/parameter/parameters.hpp>
#include <boost/parameter/value_type.hpp>
#include <boost/core/enable_if.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/quote.hpp>
#include <boost/limits.hpp>

namespace odds_and_ends { namespace node { namespace container {

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3 = ::boost::parameter::void_,
        typename T4 = ::boost::parameter::void_,
        typename T5 = ::boost::parameter::void_,
        typename T6 = ::boost::parameter::void_
    >
    class deque
    {
        struct _enabler
        {
        };

        typedef typename ::boost::parameter::parameters<
            ::boost::parameter::required<
                ::odds_and_ends::node::parameter::tag::_node_parent_generator_list
            >,
            ::boost::parameter::required< ::odds_and_ends::node::parameter::tag::_balancer>,
            ::boost::parameter::optional< ::odds_and_ends::node::parameter::tag::_size>,
            ::boost::parameter::optional< ::odds_and_ends::node::parameter::tag::_difference>,
            ::boost::parameter::optional<
                ::odds_and_ends::node::parameter::tag::_pointer_transform
            >,
            ::boost::parameter::optional<
                ::odds_and_ends::node::parameter::tag::_allocator_transform
            >
        >::template bind<T1,T2,T3,T4,T5,T6>::type _template_args;
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
            ::odds_and_ends::node::parameter::tag::_pointer_transform,
            ::boost::mpl::quote1< ::std::add_pointer>
        >::type _ptr_xform;
        typedef typename ::boost::parameter::value_type<
            _template_args,
            ::odds_and_ends::node::parameter::tag::_allocator_transform,
            ::boost::mpl::quote1< ::std::allocator>
        >::type _alloc_xform;

    public:
        typedef ::odds_and_ends::node::container::deque<T0,T1,T2,T3,T4,T5,T6> type;
        typedef T0 value_type;
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
        typedef value_type& reference;
        typedef value_type const& const_reference;
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

    private:
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

        allocator_type _alloc;
        _node_ptr_t _root_ptr;

    public:
        template <typename Alloc>
        deque(
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename Alloc>
        deque(
            ::std::initializer_list<value_type> l,
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename Alloc>
        deque(
            deque const& copy,
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename Alloc>
        deque(
            deque&& source,
            Alloc const& alloc,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                _enabler
            >::type = _enabler()
        );

        template <typename Iterator>
        deque(
            Iterator itr_begin,
            Iterator itr_end,
            typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::concept::is_legacy_input_iterator<Iterator>,
                _enabler
            >::type = _enabler()
        );

        template <typename Iterator, typename Alloc>
        deque(
            Iterator itr_begin,
            Iterator itr_end,
            Alloc const& alloc,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection
                    ::concept::is_legacy_input_iterator<Iterator>,
                    ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <
            typename U0,
            typename U1,
            typename U2,
            typename U3,
            typename U4,
            typename U5,
            typename U6
        >
        deque(
            deque<U0,U1,U2,U3,U4,U5,U6> const& copy,
            typename ::boost::enable_if< ::std::is_convertible<U0,T0>,_enabler>::type = _enabler()
        );

        template <
            typename U0,
            typename U1,
            typename U2,
            typename U3,
            typename U4,
            typename U5,
            typename U6,
            typename Alloc
        >
        deque(
            deque<U0,U1,U2,U3,U4,U5,U6> const& copy,
            Alloc const& alloc,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::std::is_convertible<U0,T0>,
                    ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        deque();
        explicit deque(size_type n);
        deque(size_type n, const_reference t);
        deque(::std::initializer_list<value_type> l);
        deque(deque const& copy);
        deque(deque&& source);
        ~deque();
        deque& operator=(::std::initializer_list<value_type> l);
        deque& operator=(deque const& copy);
        deque& operator=(deque&& source);
        allocator_type get_allocator() const;
        _node_const_ptr_t data() const;
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
        const_reference back() const;
        reference back();
        const_reference front() const;
        reference front();
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

        const_reference at(size_type const& index) const;
        reference at(size_type const& index);
        const_reference operator[](size_type const& index) const;
        reference operator[](size_type const& index);
        iterator erase(const_iterator pos);
        iterator erase(const_iterator itr_begin, const_iterator itr_end);
        void pop_front();
        void pop_back();
        void swap(deque& other);
        void clear();
        void resize(size_type const& n);
        void resize(size_type const& n, value_type const& t);
        static size_type max_size();

    private:
        static void _fill_construct(allocator_type& alloc, _node_ptr_t& root_ptr, size_type n);

        static void
            _fill_construct(
                allocator_type& alloc,
                _node_ptr_t& root_ptr,
                size_type n,
                const_reference t
            );

        template <typename Iterator>
        static void
            _fill_construct(
                allocator_type& alloc,
                _node_ptr_t& root_ptr,
                Iterator itr,
                Iterator itr_end
            );

        _node_const_ptr_t _front() const;
        _node_ptr_t _front();
        _node_const_ptr_t _back() const;
        _node_ptr_t _back();
        _node_const_ptr_t _at(size_type const& index) const;
        _node_ptr_t _at(size_type const& index);
        iterator _erase(allocator_type& alloc, _node_ptr_t node_ptr);
    };
}}}  // namespace odds_and_ends::node::container

#include <tuple>
#include <utility>
#include <odds_and_ends/node/iterator/breadth_first_tree.hpp>
#include <odds_and_ends/node/iterator/post_order_tree.hpp>
#include <odds_and_ends/node/algorithm/add_distance.hpp>
#include <odds_and_ends/node/algorithm/binary_tree_descendant_at_index.hpp>
#include <odds_and_ends/node/algorithm/is_ancestor_of.hpp>
#include <odds_and_ends/node/algorithm/increment_in_binary_tree.hpp>
#include <boost/utility/value_init.hpp>
#include <boost/assert.hpp>

namespace odds_and_ends { namespace node { namespace container {

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline deque<T0,T1,T2,T3,T4,T5,T6>::deque() : _alloc(), _root_ptr(nullptr)
    {
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename Alloc>
    inline deque<T0,T1,T2,T3,T4,T5,T6>::deque(
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _alloc(alloc), _root_ptr(nullptr)
    {
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    void
        deque<T0,T1,T2,T3,T4,T5,T6>::_fill_construct(
            allocator_type& alloc,
            _node_ptr_t& root_ptr,
            size_type n
        )
    {
        root_ptr = ::std::allocator_traits<allocator_type>::allocate(alloc, 1);
        ::std::allocator_traits<allocator_type>::construct(alloc, root_ptr);
        _node_ptr_t node_ptr;

        for (
            ::odds_and_ends::node::breadth_first_tree_iterator<node_type> itr(*root_ptr);
            n && !(!itr);
            ++itr
        )
        {
            if (--n)
            {
                node_ptr = ::std::allocator_traits<allocator_type>::allocate(alloc, 1);
                ::std::allocator_traits<allocator_type>::construct(alloc, node_ptr);
                itr->set_left_ptr(node_ptr);

                if (--n)
                {
                    node_ptr = ::std::allocator_traits<allocator_type>::allocate(alloc, 1);
                    ::std::allocator_traits<allocator_type>::construct(alloc, node_ptr);
                    itr->set_right_ptr(node_ptr);
                }
            }
        }

        _balancer_t::post_fill(*root_ptr);
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    void
        deque<T0,T1,T2,T3,T4,T5,T6>::_fill_construct(
            allocator_type& alloc,
            _node_ptr_t& root_ptr,
            size_type n,
            const_reference t
        )
    {
        root_ptr = ::std::allocator_traits<allocator_type>::allocate(alloc, 1);
        ::std::allocator_traits<allocator_type>::construct(alloc, root_ptr, t);
        _node_ptr_t node_ptr;

        for (
            ::odds_and_ends::node::breadth_first_tree_iterator<node_type> itr(*root_ptr);
            n && !(!itr);
            ++itr
        )
        {
            if (--n)
            {
                node_ptr = ::std::allocator_traits<allocator_type>::allocate(alloc, 1);
                ::std::allocator_traits<allocator_type>::construct(alloc, node_ptr, t);
                itr->set_left_ptr(node_ptr);

                if (--n)
                {
                    node_ptr = ::std::allocator_traits<allocator_type>::allocate(alloc, 1);
                    ::std::allocator_traits<allocator_type>::construct(alloc, node_ptr, t);
                    itr->set_right_ptr(node_ptr);
                }
            }
        }

        _balancer_t::post_fill(*root_ptr);
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline deque<T0,T1,T2,T3,T4,T5,T6>::deque(size_type n) : _alloc(), _root_ptr(nullptr)
    {
        if (n)
        {
            type::_fill_construct(this->_alloc, this->_root_ptr, n);
        }
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline deque<T0,T1,T2,T3,T4,T5,T6>::deque(size_type n, const_reference t) :
        _alloc(), _root_ptr(nullptr)
    {
        if (n)
        {
            type::_fill_construct(this->_alloc, this->_root_ptr, n, t);
        }
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename Iterator>
    void
        deque<T0,T1,T2,T3,T4,T5,T6>::_fill_construct(
            allocator_type& alloc,
            _node_ptr_t& root_ptr,
            Iterator itr,
            Iterator itr_end
        )
    {
        size_type n = ::boost::initialized_value;

        ::odds_and_ends::node::algorithm::add_distance(n, itr, itr_end);

        if (n)
        {
            type::_fill_construct(alloc, root_ptr, n, *itr);

            for (_itr_t out_itr(*root_ptr, false); !(!out_itr); ++out_itr)
            {
                **out_itr = *itr;
                ++itr;
            }
        }
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline deque<T0,T1,T2,T3,T4,T5,T6>::deque(::std::initializer_list<value_type> l) :
        _alloc(), _root_ptr(nullptr)
    {
        type::_fill_construct(this->_alloc, this->_root_ptr, l.begin(), l.end());
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename Alloc>
    inline deque<T0,T1,T2,T3,T4,T5,T6>::deque(
        ::std::initializer_list<value_type> l,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _alloc(alloc), _root_ptr(nullptr)
    {
        type::_fill_construct(this->_alloc, this->_root_ptr, l.begin(), l.end());
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename Iterator>
    inline deque<T0,T1,T2,T3,T4,T5,T6>::deque(
        Iterator itr,
        Iterator itr_end,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_legacy_input_iterator<Iterator>,
            _enabler
        >::type
    ) : _alloc(), _root_ptr(nullptr)
    {
        type::_fill_construct(this->_alloc, this->_root_ptr, itr, itr_end);
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename Iterator, typename Alloc>
    inline deque<T0,T1,T2,T3,T4,T5,T6>::deque(
        Iterator itr,
        Iterator itr_end,
        Alloc const& alloc,
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::odds_and_ends::static_introspection
                ::concept::is_legacy_input_iterator<Iterator>,
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _alloc(alloc), _root_ptr(nullptr)
    {
        type::_fill_construct(this->_alloc, this->_root_ptr, itr, itr_end);
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline deque<T0,T1,T2,T3,T4,T5,T6>::deque(deque&& source) :
        _alloc(source._alloc), _root_ptr(source._root_ptr)
    {
        source._root_ptr = nullptr;
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename Alloc>
    inline deque<T0,T1,T2,T3,T4,T5,T6>::deque(
        deque&& source,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _alloc(alloc), _root_ptr(source._root_ptr)
    {
        source._root_ptr = nullptr;
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline deque<T0,T1,T2,T3,T4,T5,T6>::deque(deque const& copy) :
        _alloc(copy._alloc), _root_ptr(nullptr)
    {
        type::_fill_construct(this->_alloc, this->_root_ptr, copy.cbegin(), copy.cend());
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename Alloc>
    inline deque<T0,T1,T2,T3,T4,T5,T6>::deque(
        deque const& copy,
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _alloc(alloc), _root_ptr(nullptr)
    {
        type::_fill_construct(this->_alloc, this->_root_ptr, copy.cbegin(), copy.cend());
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <
        typename U0,
        typename U1,
        typename U2,
        typename U3,
        typename U4,
        typename U5,
        typename U6
    >
    inline deque<T0,T1,T2,T3,T4,T5,T6>::deque(
        deque<U0,U1,U2,U3,U4,U5,U6> const& copy,
        typename ::boost::enable_if< ::std::is_convertible<U0,T0>,_enabler>::type
    ) : _alloc(copy._alloc), _root_ptr(nullptr)
    {
        type::_fill_construct(this->_alloc, this->_root_ptr, copy.cbegin(), copy.cend());
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <
        typename U0,
        typename U1,
        typename U2,
        typename U3,
        typename U4,
        typename U5,
        typename U6,
        typename Alloc
    >
    inline deque<T0,T1,T2,T3,T4,T5,T6>::deque(
        deque<U0,U1,U2,U3,U4,U5,U6> const& copy,
        Alloc const& alloc,
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::std::is_convertible<U0,T0>,
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _alloc(alloc), _root_ptr(nullptr)
    {
        type::_fill_construct(this->_alloc, this->_root_ptr, copy.cbegin(), copy.cend());
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    void deque<T0,T1,T2,T3,T4,T5,T6>::clear()
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
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline deque<T0,T1,T2,T3,T4,T5,T6>::~deque()
    {
        this->clear();
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline deque<T0,T1,T2,T3,T4,T5,T6>& deque<T0,T1,T2,T3,T4,T5,T6>::operator=(deque&& source)
    {
        if (this != &static_cast<deque&>(source))
        {
            this->clear();
            this->_root_ptr = source._root_ptr;
            source._root_ptr = nullptr;
        }

        return *this;
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline deque<T0,T1,T2,T3,T4,T5,T6>& deque<T0,T1,T2,T3,T4,T5,T6>::operator=(deque const& copy)
    {
        if (this != &copy)
        {
            this->clear();
            type::_fill_construct(this->_alloc, this->_root_ptr, copy.cbegin(), copy.cend());
        }

        return *this;
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline deque<T0,T1,T2,T3,T4,T5,T6>&
        deque<T0,T1,T2,T3,T4,T5,T6>::operator=(::std::initializer_list<value_type> l)
    {
        this->clear();
        type::_fill_construct(this->_alloc, this->_root_ptr, l.begin(), l.end());
        return *this;
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::allocator_type
        deque<T0,T1,T2,T3,T4,T5,T6>::get_allocator() const
    {
        return this->_alloc;
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline bool deque<T0,T1,T2,T3,T4,T5,T6>::empty() const
    {
        return !this->_root_ptr;
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::_node_const_ptr_t
        deque<T0,T1,T2,T3,T4,T5,T6>::data() const
    {
        return this->_root_ptr;
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::const_iterator
        deque<T0,T1,T2,T3,T4,T5,T6>::cbegin() const
    {
        return this->_root_ptr ? const_iterator(
            ::odds_and_ends::node
            ::make_in_order_tree_iterator_begin<difference_type>(*this->_root_ptr)
        ) : this->cend();
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::const_iterator
        deque<T0,T1,T2,T3,T4,T5,T6>::begin() const
    {
        return this->_root_ptr ? const_iterator(
            ::odds_and_ends::node
            ::make_in_order_tree_iterator_begin<difference_type>(*this->_root_ptr)
        ) : this->end();
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::iterator deque<T0,T1,T2,T3,T4,T5,T6>::begin()
    {
        return this->_root_ptr ? iterator(
            ::odds_and_ends::node
            ::make_in_order_tree_iterator_begin<difference_type>(*this->_root_ptr)
        ) : this->end();
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::const_iterator
        deque<T0,T1,T2,T3,T4,T5,T6>::cend() const
    {
        return this->_root_ptr ? const_iterator(
            ::odds_and_ends::node
            ::make_in_order_tree_iterator_end<difference_type>(*this->_root_ptr)
        ) : const_iterator();
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::const_iterator
        deque<T0,T1,T2,T3,T4,T5,T6>::end() const
    {
        return this->_root_ptr ? const_iterator(
            ::odds_and_ends::node
            ::make_in_order_tree_iterator_end<difference_type>(*this->_root_ptr)
        ) : const_iterator();
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::iterator deque<T0,T1,T2,T3,T4,T5,T6>::end()
    {
        return this->_root_ptr ? iterator(
            ::odds_and_ends::node
            ::make_in_order_tree_iterator_end<difference_type>(*this->_root_ptr)
        ) : iterator();
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::const_reverse_iterator
        deque<T0,T1,T2,T3,T4,T5,T6>::crbegin() const
    {
        return this->_root_ptr ? const_reverse_iterator(
            ::odds_and_ends::node::make_in_order_tree_reverse_iterator_begin<difference_type>(
                *this->_root_ptr
            )
        ) : this->crend();
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::const_reverse_iterator
        deque<T0,T1,T2,T3,T4,T5,T6>::rbegin() const
    {
        return this->_root_ptr ? const_reverse_iterator(
            ::odds_and_ends::node::make_in_order_tree_reverse_iterator_begin<difference_type>(
                *this->_root_ptr
            )
        ) : this->rend();
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::reverse_iterator
        deque<T0,T1,T2,T3,T4,T5,T6>::rbegin()
    {
        return this->_root_ptr ? reverse_iterator(
            ::odds_and_ends::node::make_in_order_tree_reverse_iterator_begin<difference_type>(
                *this->_root_ptr
            )
        ) : this->rend();
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::const_reverse_iterator
        deque<T0,T1,T2,T3,T4,T5,T6>::crend() const
    {
        return this->_root_ptr ? const_reverse_iterator(
            ::odds_and_ends::node
            ::make_in_order_tree_reverse_iterator_end<difference_type>(*this->_root_ptr)
        ) : const_reverse_iterator();
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::const_reverse_iterator
        deque<T0,T1,T2,T3,T4,T5,T6>::rend() const
    {
        return this->_root_ptr ? const_reverse_iterator(
            ::odds_and_ends::node
            ::make_in_order_tree_reverse_iterator_end<difference_type>(*this->_root_ptr)
        ) : const_reverse_iterator();
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::reverse_iterator
        deque<T0,T1,T2,T3,T4,T5,T6>::rend()
    {
        return this->_root_ptr ? reverse_iterator(
            ::odds_and_ends::node
            ::make_in_order_tree_reverse_iterator_end<difference_type>(*this->_root_ptr)
        ) : reverse_iterator();
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::size_type const&
        deque<T0,T1,T2,T3,T4,T5,T6>::size() const
    {
        static size_type const z = ::boost::initialized_value;
        return this->_root_ptr ? this->_root_ptr->size() : z;
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::size_type deque<T0,T1,T2,T3,T4,T5,T6>::max_size()
    {
        return (::std::numeric_limits<size_type>::max)();
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::_node_const_ptr_t
        deque<T0,T1,T2,T3,T4,T5,T6>::_front() const
    {
        return ::odds_and_ends::node::algorithm::increment_in_binary_tree(
            static_cast<_node_const_ptr_t>(nullptr),
            this->_root_ptr
        );
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::const_reference
        deque<T0,T1,T2,T3,T4,T5,T6>::front() const
    {
        return **this->_front();
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::_node_ptr_t deque<T0,T1,T2,T3,T4,T5,T6>::_front()
    {
        return ::odds_and_ends::node::algorithm::increment_in_binary_tree(
            static_cast<_node_ptr_t>(nullptr),
            this->_root_ptr
        );
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::reference deque<T0,T1,T2,T3,T4,T5,T6>::front()
    {
        return **this->_front();
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::_node_const_ptr_t
        deque<T0,T1,T2,T3,T4,T5,T6>::_back() const
    {
        return ::odds_and_ends::node::algorithm::decrement_in_binary_tree(
            static_cast<_node_const_ptr_t>(nullptr),
            this->_root_ptr
        );
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::const_reference
        deque<T0,T1,T2,T3,T4,T5,T6>::back() const
    {
        return **this->_back();
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::_node_ptr_t deque<T0,T1,T2,T3,T4,T5,T6>::_back()
    {
        return ::odds_and_ends::node::algorithm::decrement_in_binary_tree(
            static_cast<_node_ptr_t>(nullptr),
            this->_root_ptr
        );
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::reference deque<T0,T1,T2,T3,T4,T5,T6>::back()
    {
        return **this->_back();
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::_node_const_ptr_t
        deque<T0,T1,T2,T3,T4,T5,T6>::_at(size_type const& index) const
    {
        BOOST_ASSERT_MSG(this->_root_ptr, "There are no elements to index.");
        BOOST_ASSERT_MSG(index < this->size(), "The index is out of bounds.");
        return ::odds_and_ends::node::algorithm::binary_tree_descendant_at_index(
            this->_root_ptr,
            index
        );
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::const_reference
        deque<T0,T1,T2,T3,T4,T5,T6>::at(size_type const& index) const
    {
        return **this->_at(index);
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::const_reference
        deque<T0,T1,T2,T3,T4,T5,T6>::operator[](size_type const& index) const
    {
        return **this->_at(index);
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::_node_ptr_t
        deque<T0,T1,T2,T3,T4,T5,T6>::_at(size_type const& index)
    {
        BOOST_ASSERT_MSG(this->_root_ptr, "There are no elements to index.");
        BOOST_ASSERT_MSG(index < this->size(), "The index is out of bounds.");
        return ::odds_and_ends::node::algorithm::binary_tree_descendant_at_index(
            this->_root_ptr,
            index
        );
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::reference
        deque<T0,T1,T2,T3,T4,T5,T6>::at(size_type const& index)
    {
        return **this->_at(index);
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline typename deque<T0,T1,T2,T3,T4,T5,T6>::reference
        deque<T0,T1,T2,T3,T4,T5,T6>::operator[](size_type const& index)
    {
        return **this->_at(index);
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline void deque<T0,T1,T2,T3,T4,T5,T6>::push_front(const_reference t)
    {
        if (this->_root_ptr)
        {
            _node_ptr_t p = this->_front();
            _node_ptr_t n = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);

            ::std::allocator_traits<allocator_type>::construct(this->_alloc, n, t);
            p->set_left_ptr(n);
            p = _balancer_t::post_insert(*n);

            if (!p->parent())
            {
                this->_root_ptr = p;
            }
        }
        else  // if (!this->_root_ptr)
        {
            type::_fill_construct(this->_alloc, this->_root_ptr, 1, t);
        }
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline void
        deque<T0,T1,T2,T3,T4,T5,T6>::push_front(
            typename ::std::remove_reference<value_type>::type&& t
        )
    {
        if (this->_root_ptr)
        {
            _node_ptr_t p = this->_front();
            _node_ptr_t n = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);

            ::std::allocator_traits<allocator_type>::construct(
                this->_alloc,
                n,
                static_cast<value_type&&>(t)
            );
            p->set_left_ptr(n);
            p = _balancer_t::post_insert(*n);

            if (!p->parent())
            {
                this->_root_ptr = p;
            }
        }
        else  // if (!this->_root_ptr)
        {
            type::_fill_construct(this->_alloc, this->_root_ptr, 1, static_cast<value_type&&>(t));
        }
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename ...Args>
    inline void deque<T0,T1,T2,T3,T4,T5,T6>::emplace_front(Args&& ...args)
    {
        if (this->_root_ptr)
        {
            _node_ptr_t p = this->_front();
            _node_ptr_t n = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);

            ::std::allocator_traits<allocator_type>::construct(
                this->_alloc,
                n,
                ::std::forward<Args>(args)...
            );
            p->set_left_ptr(n);
            p = _balancer_t::post_insert(*n);

            if (!p->parent())
            {
                this->_root_ptr = p;
            }
        }
        else  // if (!this->_root_ptr)
        {
            type::_fill_construct(
                this->_alloc,
                this->_root_ptr,
                1,
                ::std::forward<Args>(args)...
            );
        }
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline void deque<T0,T1,T2,T3,T4,T5,T6>::push_back(const_reference t)
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
            type::_fill_construct(this->_alloc, this->_root_ptr, 1, t);
        }
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline void
        deque<T0,T1,T2,T3,T4,T5,T6>::push_back(
            typename ::std::remove_reference<value_type>::type&& t
        )
    {
        if (this->_root_ptr)
        {
            _node_ptr_t p = this->_back();
            _node_ptr_t n = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);

            ::std::allocator_traits<allocator_type>::construct(
                this->_alloc,
                n,
                static_cast<value_type&&>(t)
            );
            p->set_right_ptr(n);
            p = _balancer_t::post_insert(*n);

            if (!p->parent())
            {
                this->_root_ptr = p;
            }
        }
        else  // if (!this->_root_ptr)
        {
            type::_fill_construct(this->_alloc, this->_root_ptr, 1, static_cast<value_type&&>(t));
        }
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename ...Args>
    inline void deque<T0,T1,T2,T3,T4,T5,T6>::emplace_back(Args&& ...args)
    {
        if (this->_root_ptr)
        {
            _node_ptr_t p = this->_back();
            _node_ptr_t n = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);

            ::std::allocator_traits<allocator_type>::construct(
                this->_alloc,
                n,
                ::std::forward<Args>(args)...
            );
            p->set_right_ptr(n);
            p = _balancer_t::post_insert(*n);

            if (!p->parent())
            {
                this->_root_ptr = p;
            }
        }
        else  // if (!this->_root_ptr)
        {
            type::_fill_construct(
                this->_alloc,
                this->_root_ptr,
                1,
                ::std::forward<Args>(args)...
            );
        }
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    typename deque<T0,T1,T2,T3,T4,T5,T6>::iterator
        deque<T0,T1,T2,T3,T4,T5,T6>::insert(const_iterator pos, const_reference t)
    {
        if (!pos.base())
        {
            this->push_back(t);
            return iterator(
                ::odds_and_ends::node
                ::make_in_order_tree_iterator_position<difference_type>(*this->_back())
            );
        }
        else
        {
            BOOST_ASSERT_MSG(
                this->_root_ptr && ::odds_and_ends::node::algorithm::is_ancestor_of(
                    this->data(),
                    ::std::pointer_traits<_node_const_ptr_t>::pointer_to(*pos.base())
                ),
                "The iterator does not point to any element in this container!"
            );

            _node_ptr_t node_ptr = const_cast<_node_ptr_t>(pos.base()->left());

            if (node_ptr)
            {
                for (; node_ptr->right(); node_ptr = node_ptr->right())
                {
                }

                _node_ptr_t n = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);

                ::std::allocator_traits<allocator_type>::construct(this->_alloc, n, t);
                node_ptr->set_right_ptr(n);
                node_ptr = n;
            }
            else  // if (!pos.base()->left())
            {
                node_ptr = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);
                ::std::allocator_traits<allocator_type>::construct(this->_alloc, node_ptr, t);
                const_cast<node_type&>(*pos.base()).set_left_ptr(node_ptr);
            }

            _node_ptr_t anc_ptr = _balancer_t::post_insert(*node_ptr);

            if (!anc_ptr->parent())
            {
                this->_root_ptr = anc_ptr;
            }

            return iterator(
                ::odds_and_ends::node
                ::make_in_order_tree_iterator_position<difference_type>(*node_ptr)
            );
        }
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    typename deque<T0,T1,T2,T3,T4,T5,T6>::iterator
        deque<T0,T1,T2,T3,T4,T5,T6>::insert(
            const_iterator pos,
            typename ::std::remove_reference<value_type>::type&& t
        )
    {
        if (!pos.base())
        {
            this->push_back(static_cast<value_type&&>(t));
            return iterator(
                ::odds_and_ends::node
                ::make_in_order_tree_iterator_position<difference_type>(*this->_back())
            );
        }
        else
        {
            BOOST_ASSERT_MSG(
                this->_root_ptr && ::odds_and_ends::node::algorithm::is_ancestor_of(
                    this->data(),
                    ::std::pointer_traits<_node_const_ptr_t>::pointer_to(*pos.base())
                ),
                "The iterator does not point to any element in this container!"
            );

            _node_ptr_t node_ptr = const_cast<_node_ptr_t>(pos.base()->left());

            if (node_ptr)
            {
                for (; node_ptr->right(); node_ptr = node_ptr->right())
                {
                }

                _node_ptr_t n = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);

                ::std::allocator_traits<allocator_type>::construct(
                    this->_alloc,
                    n,
                    static_cast<value_type&&>(t)
                );
                node_ptr->set_right_ptr(n);
                node_ptr = n;
            }
            else  // if (!pos.base()->left())
            {
                node_ptr = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);
                ::std::allocator_traits<allocator_type>::construct(
                    this->_alloc,
                    node_ptr,
                    static_cast<value_type&&>(t)
                );
                const_cast<node_type&>(*pos.base()).set_left_ptr(node_ptr);
            }

            _node_ptr_t anc_ptr = _balancer_t::post_insert(*node_ptr);

            if (!anc_ptr->parent())
            {
                this->_root_ptr = anc_ptr;
            }

            return iterator(
                ::odds_and_ends::node
                ::make_in_order_tree_iterator_position<difference_type>(*node_ptr)
            );
        }
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename ...Args>
    typename deque<T0,T1,T2,T3,T4,T5,T6>::iterator
        deque<T0,T1,T2,T3,T4,T5,T6>::emplace(const_iterator pos, Args&& ...args)
    {
        if (!pos.base())
        {
            this->emplace_back(::std::forward<Args>(args)...);
            return iterator(
                ::odds_and_ends::node
                ::make_in_order_tree_iterator_position<difference_type>(*this->_back())
            );
        }
        else
        {
            BOOST_ASSERT_MSG(
                this->_root_ptr && ::odds_and_ends::node::algorithm::is_ancestor_of(
                    this->data(),
                    ::std::pointer_traits<_node_const_ptr_t>::pointer_to(*pos.base())
                ),
                "The iterator does not point to any element in this container!"
            );

            _node_ptr_t node_ptr = const_cast<_node_ptr_t>(pos.base()->left());

            if (node_ptr)
            {
                for (; node_ptr->right(); node_ptr = node_ptr->right())
                {
                }

                _node_ptr_t n = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);

                ::std::allocator_traits<allocator_type>::construct(
                    this->_alloc,
                    n,
                    ::std::forward<Args>(args)...
                );
                node_ptr->set_right_ptr(n);
                node_ptr = n;
            }
            else  // if (!pos.base()->left())
            {
                node_ptr = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);
                ::std::allocator_traits<allocator_type>::construct(
                    this->_alloc,
                    node_ptr,
                    ::std::forward<Args>(args)...
                );
                const_cast<node_type&>(*pos.base()).set_left_ptr(node_ptr);
            }

            _node_ptr_t anc_ptr = _balancer_t::post_insert(*node_ptr);

            if (!anc_ptr->parent())
            {
                this->_root_ptr = anc_ptr;
            }

            return iterator(
                ::odds_and_ends::node
                ::make_in_order_tree_iterator_position<difference_type>(*node_ptr)
            );
        }
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    typename deque<T0,T1,T2,T3,T4,T5,T6>::iterator
        deque<T0,T1,T2,T3,T4,T5,T6>::insert(const_iterator pos, size_type n, const_reference t)
    {
        if (n)
        {
            if (this->_root_ptr)
            {
                iterator result = this->insert(pos, t);

                for (iterator pos_itr; --n; pos = ++pos_itr)
                {
                    pos_itr = this->insert(pos, t);
                }

                return result;
            }
            else
            {
                type::_fill_construct(this->_alloc, this->_root_ptr, n, t);
                return this->begin();
            }
        }
        else if (!pos.base())
        {
            BOOST_ASSERT(this->cend() == pos);
            return this->end();
        }
        else
        {
            BOOST_ASSERT_MSG(
                this->_root_ptr && ::odds_and_ends::node::algorithm::is_ancestor_of(
                    this->data(),
                    ::std::pointer_traits<_node_const_ptr_t>::pointer_to(*pos.base())
                ),
                "The iterator does not point to any element in this container!"
            );
            iterator result(
                ::odds_and_ends::node::make_in_order_tree_iterator_position<difference_type>(
                    const_cast<node_type&>(*pos.base())
                )
            );
            BOOST_ASSERT(result == pos);
            return result;
        }
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    template <typename Iterator>
    typename ::boost::enable_if<
        ::odds_and_ends::static_introspection::concept::is_legacy_input_iterator<Iterator>,
        typename deque<T0,T1,T2,T3,T4,T5,T6>::iterator
    >::type
        deque<T0,T1,T2,T3,T4,T5,T6>::insert(const_iterator pos, Iterator itr, Iterator itr_end)
    {
        if (itr == itr_end)
        {
            if (!pos.base())
            {
                BOOST_ASSERT(this->cend() == pos);
                return this->end();
            }
            else
            {
                BOOST_ASSERT_MSG(
                    this->_root_ptr && ::odds_and_ends::node::algorithm::is_ancestor_of(
                        this->data(),
                        ::std::pointer_traits<_node_const_ptr_t>::pointer_to(*pos.base())
                    ),
                    "The iterator does not point to any element in this container!"
                );
                iterator result(
                    ::odds_and_ends::node::make_in_order_tree_iterator_position<difference_type>(
                        const_cast<node_type&>(*pos.base())
                    )
                );
                BOOST_ASSERT(result == pos);
                return result;
            }
        }
        else if (this->_root_ptr)
        {
            iterator result = this->insert(pos, *itr);

            pos = result;

            for (iterator pos_itr; ++itr != itr_end; pos = pos_itr)
            {
                pos_itr = this->insert(++pos, *itr);
            }

            return result;
        }
        else
        {
            type::_fill_construct(this->_alloc, this->_root_ptr, itr, itr_end);
            return this->begin();
        }
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    void deque<T0,T1,T2,T3,T4,T5,T6>::pop_front()
    {
        ::std::tuple<_node_ptr_t,_node_ptr_t,_node_ptr_t> sep_result = _balancer_t::separate(
            *this->_front()
        );

        ::std::allocator_traits<allocator_type>::destroy(this->_alloc, ::std::get<0>(sep_result));
        ::std::allocator_traits<
            allocator_type
        >::deallocate(this->_alloc, ::std::get<0>(sep_result), 1);
        this->_root_ptr = ::std::get<2>(sep_result);
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    void deque<T0,T1,T2,T3,T4,T5,T6>::pop_back()
    {
        ::std::tuple<_node_ptr_t,_node_ptr_t,_node_ptr_t> sep_result = _balancer_t::separate(
            *this->_back()
        );

        ::std::allocator_traits<allocator_type>::destroy(this->_alloc, ::std::get<0>(sep_result));
        ::std::allocator_traits<
            allocator_type
        >::deallocate(this->_alloc, ::std::get<0>(sep_result), 1);
        this->_root_ptr = ::std::get<2>(sep_result);
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    typename deque<T0,T1,T2,T3,T4,T5,T6>::iterator
        deque<T0,T1,T2,T3,T4,T5,T6>::erase(const_iterator pos)
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
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    typename deque<T0,T1,T2,T3,T4,T5,T6>::iterator
        deque<T0,T1,T2,T3,T4,T5,T6>::erase(const_iterator itr, const_iterator itr_end)
    {
        iterator result = this->end();

        if (itr_end != this->cend())
        {
            result = ::odds_and_ends::node::make_in_order_tree_iterator_position<difference_type>(
                const_cast<node_type&>(*itr_end.base())
            );
        }

        for (; itr != itr_end; itr = result)
        {
            result = this->erase(itr);
        }

        return result;
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline void deque<T0,T1,T2,T3,T4,T5,T6>::swap(deque& other)
    {
        using ::std::swap;
        swap(this->_root_ptr, other._root_ptr);
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    void deque<T0,T1,T2,T3,T4,T5,T6>::resize(size_type const& n)
    {
        if (this->_root_ptr)
        {
            if (this->size() < n)
            {
                for (; this->size() < n; this->emplace_back())
                {
                }
            }
            else if (n < this->size())
            {
                for (; n < this->size(); this->pop_back())
                {
                }
            }
        }
        else if (n)
        {
            type::_fill_construct(this->_alloc, this->_root_ptr, n);
        }
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    void deque<T0,T1,T2,T3,T4,T5,T6>::resize(size_type const& n, value_type const& t)
    {
        if (this->_root_ptr)
        {
            if (this->size() < n)
            {
                for (; this->size() < n; this->push_back(t))
                {
                }
            }
            else if (n < this->size())
            {
                for (; n < this->size(); this->pop_back())
                {
                }
            }
        }
        else if (n)
        {
            type::_fill_construct(this->_alloc, this->_root_ptr, n, t);
        }
    }

    template <
        typename T0,
        typename T1,
        typename T2,
        typename T3,
        typename T4,
        typename T5,
        typename T6
    >
    inline void swap(deque<T0,T1,T2,T3,T4,T5,T6>& lhs, deque<T0,T1,T2,T3,T4,T5,T6>& rhs)
    {
        lhs.swap(rhs);
    }
}}}  // namespace odds_and_ends::node::container

#endif  // ODDS_AND_ENDS__NODE__CONTAINER__DEQUE_HPP

