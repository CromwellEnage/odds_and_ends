// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__CONTAINER__DEQUE_HPP
#define ODDS_AND_ENDS__NODE__CONTAINER__DEQUE_HPP

#include <cstddef>
#include <type_traits>
#include <memory>
//#include <initializer_list>
#include <odds_and_ends/node/data.hpp>
#include <odds_and_ends/node/tree/base.hpp>
#include <odds_and_ends/node/tree/binary.hpp>
#include <odds_and_ends/node/tree/with_size.hpp>
#include <odds_and_ends/node/iterator/in_order_tree.hpp>
#include <odds_and_ends/node/iterator/indirect.hpp>
#include <odds_and_ends/composite_type/composite_type.hpp>
#include <odds_and_ends/static_introspection/concept/is_allocator.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_input_iterator.hpp>
#include <boost/core/enable_if.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/quote.hpp>

#if !defined BOOST_NO_LIMITS
#include <boost/limits.hpp>
#endif

namespace odds_and_ends { namespace node { namespace container {

    template <
        typename T,
        typename NodeParentGeneratorList,
        typename Balancer,
        typename Size = ::std::size_t,
        typename Difference = ::std::ptrdiff_t,
        typename PtrXForm = ::boost::mpl::quote1< ::std::add_pointer>,
        typename AllocXForm = ::boost::mpl::quote1< ::std::allocator>
    >
    class deque
    {
        struct _enabler
        {
        };

    public:
        typedef ::odds_and_ends::node::container
        ::deque<T,NodeParentGeneratorList,Balancer,Size,Difference,PtrXForm,AllocXForm> type;
        typedef T value_type;
        typedef Size size_type;
        typedef Difference difference_type;
        typedef value_type& reference;
        typedef value_type const& const_reference;
        typedef typename ::boost::mpl::apply_wrap1<PtrXForm,value_type>::type pointer;
        typedef typename ::boost::mpl::apply_wrap1<PtrXForm,value_type const>::type const_pointer;
        typedef ::odds_and_ends::composite_type::composite_type<
            typename ::boost::mpl::push_front<
                typename ::boost::mpl::push_front<
                    typename ::boost::mpl::push_front<
                        typename ::boost::mpl::push_front<
                            NodeParentGeneratorList,
                            ::odds_and_ends::node::tree::with_size<Size>
                        >::type,
                        ::odds_and_ends::node::tree::binary<Difference>
                    >::type,
                    ::odds_and_ends::node::tree::base<PtrXForm>
                >::type,
                ::odds_and_ends::node::data<T>
            >::type
        > node_type;
        typedef typename ::boost::mpl::apply_wrap1<AllocXForm,node_type>::type allocator_type;

    private:
        typedef ::odds_and_ends::node
        ::in_order_tree_iterator<node_type,::boost::mpl::false_,Difference> _itr_t;
        typedef ::odds_and_ends::node
        ::in_order_tree_iterator<node_type const,::boost::mpl::false_,Difference> _c_itr_t;
        typedef ::odds_and_ends::node
        ::in_order_tree_iterator<node_type,::boost::mpl::true_,Difference> _r_itr_t;
        typedef ::odds_and_ends::node
        ::in_order_tree_iterator<node_type const,::boost::mpl::true_,Difference> _c_r_itr_t;

    public:
        typedef ::odds_and_ends::node::indirect_iterator<_itr_t,PtrXForm> iterator;
        typedef ::odds_and_ends::node::indirect_iterator<_c_itr_t,PtrXForm> const_iterator;
        typedef ::odds_and_ends::node::indirect_iterator<_r_itr_t,PtrXForm> reverse_iterator;
        typedef ::odds_and_ends::node
        ::indirect_iterator<_c_r_itr_t,PtrXForm> const_reverse_iterator;

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
            typename U,
            typename NPGL,
            typename B,
            typename S,
            typename D,
            typename PX,
            typename AX
        >
        deque(
            deque<U,NPGL,B,S,D,PX,AX> const& copy,
            typename ::boost::enable_if< ::std::is_convertible<U,T>,_enabler>::type = _enabler()
        );

        template <
            typename U,
            typename NPGL,
            typename B,
            typename S,
            typename D,
            typename PX,
            typename AX,
            typename Alloc
        >
        deque(
            deque<U,NPGL,B,S,D,PX,AX> const& copy,
            Alloc const& alloc,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::std::is_convertible<U,T>,
                    ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        deque();
        explicit deque(size_type n);
        deque(size_type n, const_reference t);
        deque(deque const& copy);
        deque(deque&& source);
        ~deque();
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
        size_type size() const;
        const_reference back() const;
        reference back();
        const_reference front() const;
        reference front();
        void push_front(const_reference t);
        void push_front(value_type&& t);
        void push_back(const_reference t);
        void push_back(value_type&& t);
        iterator insert(const_iterator pos, const_reference t);
        iterator insert(const_iterator pos, value_type&& t);
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

        const_reference operator[](size_type index) const;
        reference operator[](size_type index);
        iterator erase(const_iterator pos);
        iterator erase(const_iterator itr_begin, const_iterator itr_end);
        void pop_front();
        void pop_back();
        void swap(deque& other);
        void clear();
        void resize(size_type n);
        void resize(size_type n, value_type const& t);

#if !defined BOOST_NO_LIMITS
        static size_type max_size();
#endif

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
        _node_const_ptr_t _at(size_type index) const;
        _node_ptr_t _at(size_type index);
        iterator _erase(allocator_type& alloc, _node_ptr_t node_ptr);
    };
}}}  // namespace odds_and_ends::node::container

#include <tuple>
#include <utility>
#include <algorithm>
#include <odds_and_ends/node/iterator/breadth_first_tree.hpp>
#include <odds_and_ends/node/iterator/post_order_tree.hpp>
#include <odds_and_ends/node/algorithm/binary_tree_descendant_at_index.hpp>
#include <odds_and_ends/node/algorithm/is_ancestor_of.hpp>
#include <odds_and_ends/node/algorithm/increment_in_binary_tree.hpp>
#include <boost/utility/value_init.hpp>
#include <boost/assert.hpp>

namespace odds_and_ends { namespace node { namespace container {

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::deque() :
        _alloc(), _root_ptr(nullptr)
    {
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    template <typename Alloc>
    inline deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::deque(
        Alloc const& alloc,
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>,
            _enabler
        >::type
    ) : _alloc(alloc), _root_ptr(nullptr)
    {
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    void
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::_fill_construct(
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

        Balancer::post_fill(*root_ptr);
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    void
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::_fill_construct(
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

        Balancer::post_fill(*root_ptr);
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::deque(size_type n) :
        _alloc(), _root_ptr(nullptr)
    {
        if (n)
        {
            type::_fill_construct(this->_alloc, this->_root_ptr, n);
        }
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::deque(
        size_type n,
        const_reference t
    ) : _alloc(), _root_ptr(nullptr)
    {
        if (n)
        {
            type::_fill_construct(this->_alloc, this->_root_ptr, n, t);
        }
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    template <typename Iterator>
    void
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::_fill_construct(
            allocator_type& alloc,
            _node_ptr_t& root_ptr,
            Iterator itr,
            Iterator itr_end
        )
    {
        size_type const n = static_cast<size_type>(::std::distance(itr, itr_end));

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
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    template <typename Iterator>
    deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::deque(
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
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    template <typename Iterator, typename Alloc>
    deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::deque(
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
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::deque(deque&& source) :
        _alloc(source._alloc), _root_ptr(source._root_ptr)
    {
        source._root_ptr = nullptr;
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    template <typename Alloc>
    inline deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::deque(
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
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::deque(deque const& copy) :
        _alloc(copy._alloc), _root_ptr(nullptr)
    {
        type::_fill_construct(this->_alloc, this->_root_ptr, copy.cbegin(), copy.cend());
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    template <typename Alloc>
    inline deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::deque(
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
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    template <
        typename U,
        typename NPGL,
        typename B,
        typename S,
        typename D,
        typename PX,
        typename AX
    >
    inline deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::deque(
        deque<U,NPGL,B,S,D,PX,AX> const& copy,
        typename ::boost::enable_if< ::std::is_convertible<U,T>,_enabler>::type
    ) : _alloc(copy._alloc), _root_ptr(nullptr)
    {
        type::_fill_construct(this->_alloc, this->_root_ptr, copy.cbegin(), copy.cend());
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    template <
        typename U,
        typename NPGL,
        typename B,
        typename S,
        typename D,
        typename PX,
        typename AX,
        typename Alloc
    >
    inline deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::deque(
        deque<U,NPGL,B,S,D,PX,AX> const& copy,
        Alloc const& alloc,
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::std::is_convertible<U,T>,
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
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    void deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::clear()
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
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::~deque()
    {
        this->clear();
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>&
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::operator=(deque&& source)
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
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>&
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::operator=(deque const& copy)
    {
        if (this != &copy)
        {
            this->clear();
            type::_fill_construct(this->_alloc, this->_root_ptr, copy.cbegin(), copy.cend());
        }

        return *this;
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::allocator_type
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::get_allocator() const
    {
        return this->_alloc;
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline bool deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::empty() const
    {
        return !this->_root_ptr;
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::_node_const_ptr_t
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::data() const
    {
        return this->_root_ptr;
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::const_iterator
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::cbegin() const
    {
        return this->_root_ptr ? const_iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_begin<Diff>(*this->_root_ptr)
        ) : this->cend();
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::const_iterator
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::begin() const
    {
        return this->_root_ptr ? const_iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_begin<Diff>(*this->_root_ptr)
        ) : this->end();
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::iterator
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::begin()
    {
        return this->_root_ptr ? iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_begin<Diff>(*this->_root_ptr)
        ) : this->end();
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::const_iterator
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::cend() const
    {
        return this->_root_ptr ? const_iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_end<Diff>(*this->_root_ptr)
        ) : const_iterator();
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::const_iterator
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::end() const
    {
        return this->_root_ptr ? const_iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_end<Diff>(*this->_root_ptr)
        ) : const_iterator();
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::iterator
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::end()
    {
        return this->_root_ptr ? iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_end<Diff>(*this->_root_ptr)
        ) : iterator();
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::const_reverse_iterator
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::crbegin() const
    {
        return this->_root_ptr ? const_reverse_iterator(
            ::odds_and_ends::node::make_in_order_tree_reverse_iterator_begin<Diff>(
                *this->_root_ptr
            )
        ) : this->crend();
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::const_reverse_iterator
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::rbegin() const
    {
        return this->_root_ptr ? const_reverse_iterator(
            ::odds_and_ends::node::make_in_order_tree_reverse_iterator_begin<Diff>(
                *this->_root_ptr
            )
        ) : this->rend();
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::reverse_iterator
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::rbegin()
    {
        return this->_root_ptr ? reverse_iterator(
            ::odds_and_ends::node::make_in_order_tree_reverse_iterator_begin<Diff>(
                *this->_root_ptr
            )
        ) : this->rend();
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::const_reverse_iterator
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::crend() const
    {
        return this->_root_ptr ? const_reverse_iterator(
            ::odds_and_ends::node::make_in_order_tree_reverse_iterator_end<Diff>(*this->_root_ptr)
        ) : const_reverse_iterator();
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::const_reverse_iterator
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::rend() const
    {
        return this->_root_ptr ? const_reverse_iterator(
            ::odds_and_ends::node::make_in_order_tree_reverse_iterator_end<Diff>(*this->_root_ptr)
        ) : const_reverse_iterator();
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::reverse_iterator
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::rend()
    {
        return this->_root_ptr ? reverse_iterator(
            ::odds_and_ends::node::make_in_order_tree_reverse_iterator_end<Diff>(*this->_root_ptr)
        ) : reverse_iterator();
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::size_type
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::size() const
    {
        static size_type const z = ::boost::initialized_value;
        return this->_root_ptr ? this->_root_ptr->size() : z;
    }

#if !defined BOOST_NO_LIMITS
    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::size_type
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::max_size()
    {
        return (::std::numeric_limits<size_type>::max)();
    }
#endif

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::_node_const_ptr_t
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::_front() const
    {
        return ::odds_and_ends::node::algorithm::increment_in_binary_tree(
            static_cast<_node_const_ptr_t>(nullptr),
            this->_root_ptr
        );
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::const_reference
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::front() const
    {
        return **this->_front();
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::_node_ptr_t
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::_front()
    {
        return ::odds_and_ends::node::algorithm::increment_in_binary_tree(
            static_cast<_node_ptr_t>(nullptr),
            this->_root_ptr
        );
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::reference
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::front()
    {
        return **this->_front();
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::_node_const_ptr_t
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::_back() const
    {
        return ::odds_and_ends::node::algorithm::decrement_in_binary_tree(
            static_cast<_node_const_ptr_t>(nullptr),
            this->_root_ptr
        );
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::const_reference
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::back() const
    {
        return **this->_back();
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::_node_ptr_t
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::_back()
    {
        return ::odds_and_ends::node::algorithm::decrement_in_binary_tree(
            static_cast<_node_ptr_t>(nullptr),
            this->_root_ptr
        );
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::reference
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::back()
    {
        return **this->_back();
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::_node_const_ptr_t
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::_at(size_type index) const
    {
        BOOST_ASSERT_MSG(this->_root_ptr, "There are no elements to index.");
        BOOST_ASSERT_MSG(index < this->size(), "The index is out of bounds.");
        return ::odds_and_ends::node::algorithm::binary_tree_descendant_at_index(
            this->_root_ptr,
            index
        );
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::const_reference
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::operator[](size_type index) const
    {
        return **this->_at(index);
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::_node_ptr_t
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::_at(size_type index)
    {
        BOOST_ASSERT_MSG(this->_root_ptr, "There are no elements to index.");
        BOOST_ASSERT_MSG(index < this->size(), "The index is out of bounds.");
        return ::odds_and_ends::node::algorithm::binary_tree_descendant_at_index(
            this->_root_ptr,
            index
        );
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::reference
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::operator[](size_type index)
    {
        return **this->_at(index);
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline void
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::push_front(const_reference t)
    {
        if (this->_root_ptr)
        {
            _node_ptr_t p = this->_front();
            _node_ptr_t n = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);

            ::std::allocator_traits<allocator_type>::construct(this->_alloc, n, t);
            p->set_left_ptr(n);
            p = Balancer::post_insert(*n);

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
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline void deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::push_front(value_type&& t)
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
            p = Balancer::post_insert(*n);

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
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    template <typename ...Args>
    void deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::emplace_front(Args&& ...args)
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
            p = Balancer::post_insert(*n);

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
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline void
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::push_back(const_reference t)
    {
        if (this->_root_ptr)
        {
            _node_ptr_t p = this->_back();
            _node_ptr_t n = ::std::allocator_traits<allocator_type>::allocate(this->_alloc, 1);

            ::std::allocator_traits<allocator_type>::construct(this->_alloc, n, t);
            p->set_right_ptr(n);
            p = Balancer::post_insert(*n);

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
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline void deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::push_back(value_type&& t)
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
            p = Balancer::post_insert(*n);

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
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    template <typename ...Args>
    void deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::emplace_back(Args&& ...args)
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
            p = Balancer::post_insert(*n);

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
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::iterator
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::insert(
            const_iterator pos,
            const_reference t
        )
    {
        if (!pos.base())
        {
            this->push_back(t);
            return iterator(
                ::odds_and_ends::node::make_in_order_tree_iterator_position<Diff>(*this->_back())
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

            _node_ptr_t anc_ptr = Balancer::post_insert(*node_ptr);

            if (!anc_ptr->parent())
            {
                this->_root_ptr = anc_ptr;
            }

            return iterator(
                ::odds_and_ends::node::make_in_order_tree_iterator_position<Diff>(*node_ptr)
            );
        }
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::iterator
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::insert(
            const_iterator pos,
            value_type&& t
        )
    {
        if (!pos.base())
        {
            this->push_back(static_cast<value_type&&>(t));
            return iterator(
                ::odds_and_ends::node::make_in_order_tree_iterator_position<Diff>(*this->_back())
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

            _node_ptr_t anc_ptr = Balancer::post_insert(*node_ptr);

            if (!anc_ptr->parent())
            {
                this->_root_ptr = anc_ptr;
            }

            return iterator(
                ::odds_and_ends::node::make_in_order_tree_iterator_position<Diff>(*node_ptr)
            );
        }
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    template <typename ...Args>
    typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::iterator
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::emplace(
            const_iterator pos,
            Args&& ...args
        )
    {
        if (!pos.base())
        {
            this->emplace_back(::std::forward<Args>(args)...);
            return iterator(
                ::odds_and_ends::node::make_in_order_tree_iterator_position<Diff>(*this->_back())
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

            _node_ptr_t anc_ptr = Balancer::post_insert(*node_ptr);

            if (!anc_ptr->parent())
            {
                this->_root_ptr = anc_ptr;
            }

            return iterator(
                ::odds_and_ends::node::make_in_order_tree_iterator_position<Diff>(*node_ptr)
            );
        }
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::iterator
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::insert(
            const_iterator pos,
            size_type n,
            const_reference t
        )
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
                ::odds_and_ends::node::make_in_order_tree_iterator_position<Diff>(
                    const_cast<node_type&>(*pos.base())
                )
            );
            BOOST_ASSERT(result == pos);
            return result;
        }
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    template <typename Iterator>
    typename ::boost::enable_if<
        ::odds_and_ends::static_introspection::concept::is_legacy_input_iterator<Iterator>,
        typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::iterator
    >::type
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::insert(
            const_iterator pos,
            Iterator itr,
            Iterator itr_end
        )
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
                    ::odds_and_ends::node::make_in_order_tree_iterator_position<Diff>(
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
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    void deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::pop_front()
    {
        ::std::tuple<_node_ptr_t,_node_ptr_t,_node_ptr_t> sep_result = Balancer::separate(
            *this->_front()
        );

        ::std::allocator_traits<allocator_type>::destroy(this->_alloc, ::std::get<0>(sep_result));
        ::std::allocator_traits<
            allocator_type
        >::deallocate(this->_alloc, ::std::get<0>(sep_result), 1);
        this->_root_ptr = ::std::get<2>(sep_result);
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    void deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::pop_back()
    {
        ::std::tuple<_node_ptr_t,_node_ptr_t,_node_ptr_t> sep_result = Balancer::separate(
            *this->_back()
        );

        ::std::allocator_traits<allocator_type>::destroy(this->_alloc, ::std::get<0>(sep_result));
        ::std::allocator_traits<
            allocator_type
        >::deallocate(this->_alloc, ::std::get<0>(sep_result), 1);
        this->_root_ptr = ::std::get<2>(sep_result);
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::iterator
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::erase(const_iterator pos)
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

        ::std::tuple<_node_ptr_t,_node_ptr_t,_node_ptr_t> sep_result = Balancer::separate(
            *node_ptr
        );

        ::std::allocator_traits<allocator_type>::destroy(this->_alloc, ::std::get<0>(sep_result));
        ::std::allocator_traits<
            allocator_type
        >::deallocate(this->_alloc, ::std::get<0>(sep_result), 1);
        this->_root_ptr = ::std::get<2>(sep_result);

        return ::std::get<1>(sep_result) ? iterator(
            ::odds_and_ends::node::make_in_order_tree_iterator_position<Diff>(
                *::std::get<1>(sep_result)
            )
        ) : this->end();
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    typename deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::iterator
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::erase(
            const_iterator itr,
            const_iterator itr_end
        )
    {
        iterator result = this->end();

        if (itr_end != this->cend())
        {
            result = ::odds_and_ends::node::make_in_order_tree_iterator_position<Diff>(
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
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline void deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::swap(deque& other)
    {
        using ::std::swap;
        swap(this->_root_ptr, other._root_ptr);
    }

    template <
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    void deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::resize(size_type n)
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
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    void
        deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>::resize(
            size_type n,
            value_type const& t
        )
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
        typename T,
        typename NPGList,
        typename Balancer,
        typename Size,
        typename Diff,
        typename PtrXForm,
        typename AllocXForm
    >
    inline void
        swap(
            deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>& lhs,
            deque<T,NPGList,Balancer,Size,Diff,PtrXForm,AllocXForm>& rhs
        )
    {
        lhs.swap(rhs);
    }
}}}  // namespace odds_and_ends::node::container

#endif  // ODDS_AND_ENDS__NODE__CONTAINER__DEQUE_HPP

