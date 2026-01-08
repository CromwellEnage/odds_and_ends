// Copyright (C) 2011-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__ITERATOR__DEPTH_FIRST_TREE_HPP
#define ODDS_AND_ENDS__NODE__ITERATOR__DEPTH_FIRST_TREE_HPP

#include <type_traits>
#include <iterator>
#include <odds_and_ends/node/container/stack.hpp>
#include <odds_and_ends/node/traversal_state.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_bidirectional_iterator.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_traits.hpp>
#include <boost/core/enable_if.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace node {

    template <
        typename Node,
        typename IsReverse = ::boost::mpl::false_,
        typename StackGen = ::odds_and_ends::node::container::stack< ::boost::mpl::_>
    >
    class depth_first_tree_iterator
    {
        struct _enabler
        {
        };

        template <typename N, typename I, typename SG>
        friend class depth_first_tree_iterator;

        typedef typename ::boost::mpl::eval_if<
            IsReverse,
            ::boost::mpl::if_<
                ::std::is_const<Node>,
                typename ::std::remove_const<Node>::type::traits::child_const_reverse_iterator,
                typename ::std::remove_const<Node>::type::traits::child_reverse_iterator
            >,
            ::boost::mpl::if_<
                ::std::is_const<Node>,
                typename ::std::remove_const<Node>::type::traits::child_const_iterator,
                typename ::std::remove_const<Node>::type::traits::child_iterator
            >
        >::type _child_iterator;

    public:
        typedef ::odds_and_ends::node::depth_first_tree_iterator<Node,IsReverse,StackGen> type;
        typedef typename ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::concept
            ::is_legacy_bidirectional_iterator<_child_iterator>,
            ::std::bidirectional_iterator_tag,
            ::std::forward_iterator_tag
        >::type iterator_category;
        typedef Node value_type;
        typedef typename ::boost::mpl::if_<
            ::std::is_const<Node>,
            typename ::std::remove_const<Node>::type::traits::const_pointer,
            typename ::std::remove_const<Node>::type::traits::pointer
        >::type pointer;
        typedef value_type& reference;

    private:
        typedef typename ::boost::mpl::apply1<StackGen,pointer>::type _node_stack_t;
        typedef typename ::boost::mpl::apply1<
            StackGen,
            _child_iterator
        >::type _child_iterator_stack_t;

        _node_stack_t _node_stack;
        _child_iterator_stack_t _itr_stack;
        pointer _current_ptr;
        pointer _root_ptr;
        ::odds_and_ends::node::traversal_state _state;

    public:
        template <typename ...Args>
        explicit depth_first_tree_iterator(pointer const& node_ptr = nullptr, Args&&... args);

        template <typename ...Args>
        explicit depth_first_tree_iterator(reference node, bool is_end = false, Args&&... args);

        template <typename N, typename I, typename SG>
        depth_first_tree_iterator(
            depth_first_tree_iterator<N,I,SG> const& other,
            typename ::boost::enable_if<
                typename ::boost::mpl::eval_if<
                    ::boost::mpl::equal_to<I,IsReverse>,
                    ::boost::mpl::if_<
                        ::std::is_same<N,Node>,
                        ::boost::mpl::false_,
                        ::std::is_convertible<N,Node>
                    >,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename N, typename I, typename SG, typename Alloc>
        depth_first_tree_iterator(
            depth_first_tree_iterator<N,I,SG> const& other,
            Alloc const& alloc,
            typename ::boost::enable_if<
                typename ::boost::mpl::eval_if<
                    ::boost::mpl::equal_to<I,IsReverse>,
                    ::boost::mpl::if_<
                        ::std::is_same<N,Node>,
                        ::boost::mpl::false_,
                        ::std::is_convertible<N,Node>
                    >,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename N, typename I, typename SG>
        depth_first_tree_iterator(
            depth_first_tree_iterator<N,I,SG>&& other,
            typename ::boost::enable_if<
                typename ::boost::mpl::eval_if<
                    ::boost::mpl::equal_to<I,IsReverse>,
                    ::boost::mpl::if_<
                        ::std::is_same<N,Node>,
                        ::boost::mpl::false_,
                        ::std::is_convertible<N,Node>
                    >,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename N, typename I, typename SG, typename Alloc>
        depth_first_tree_iterator(
            depth_first_tree_iterator<N,I,SG>&& other,
            Alloc const& alloc,
            typename ::boost::enable_if<
                typename ::boost::mpl::eval_if<
                    ::boost::mpl::equal_to<I,IsReverse>,
                    ::boost::mpl::if_<
                        ::std::is_same<N,Node>,
                        ::boost::mpl::false_,
                        ::std::is_convertible<N,Node>
                    >,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        depth_first_tree_iterator(depth_first_tree_iterator const& other);
        depth_first_tree_iterator(depth_first_tree_iterator&& other);
        depth_first_tree_iterator& operator=(depth_first_tree_iterator const& other);
        depth_first_tree_iterator& operator=(depth_first_tree_iterator&& other);
        operator ::odds_and_ends::node::traversal_state() const;
        bool operator!() const;
        reference operator*() const;
        pointer operator->() const;
        depth_first_tree_iterator& operator++();
        depth_first_tree_iterator operator++(int);
        depth_first_tree_iterator& operator--();
        depth_first_tree_iterator operator--(int);

    private:
        static pointer _get(_child_iterator itr, ::boost::mpl::true_);
        static pointer _get(_child_iterator itr, ::boost::mpl::false_);
        static ::odds_and_ends::node::traversal_state _inc_state(::boost::mpl::true_);
        static ::odds_and_ends::node::traversal_state _inc_state(::boost::mpl::false_);
        static ::odds_and_ends::node::traversal_state _dec_state(::boost::mpl::true_);
        static ::odds_and_ends::node::traversal_state _dec_state(::boost::mpl::false_);
        _child_iterator _current_begin(::boost::mpl::false_);
        _child_iterator _current_begin(::boost::mpl::true_);
        _child_iterator _current_end(::boost::mpl::false_);
        _child_iterator _current_end(::boost::mpl::true_);

        template <typename N, typename I, typename SG>
        friend class depth_first_tree_iterator;

        template <typename N1, typename I1, typename SG1, typename N2, typename I2, typename SG2>
        friend typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
            operator==(
                depth_first_tree_iterator<N1,I1,SG1> const& lhs,
                depth_first_tree_iterator<N2,I2,SG2> const& rhs
            );

        template <typename N1, typename I1, typename SG1, typename N2, typename I2, typename SG2>
        friend typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
            operator!=(
                depth_first_tree_iterator<N1,I1,SG1> const& lhs,
                depth_first_tree_iterator<N2,I2,SG2> const& rhs
            );
    };
}}  // namespace odds_and_ends::node

#include <utility>
#include <memory>
#include <odds_and_ends/static_introspection/member_function/has_clear.hpp>

namespace odds_and_ends { namespace node {

    template <typename Node, typename IsReverse, typename StackGen>
    inline ::odds_and_ends::node::traversal_state
        depth_first_tree_iterator<Node,IsReverse,StackGen>::_inc_state(::boost::mpl::true_)
    {
        return ::odds_and_ends::node::pre_order_traversal;
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline ::odds_and_ends::node::traversal_state
        depth_first_tree_iterator<Node,IsReverse,StackGen>::_inc_state(::boost::mpl::false_)
    {
        return ::odds_and_ends::node::post_order_traversal;
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline ::odds_and_ends::node::traversal_state
        depth_first_tree_iterator<Node,IsReverse,StackGen>::_dec_state(::boost::mpl::true_)
    {
        return ::odds_and_ends::node::post_order_traversal;
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline ::odds_and_ends::node::traversal_state
        depth_first_tree_iterator<Node,IsReverse,StackGen>::_dec_state(::boost::mpl::false_)
    {
        return ::odds_and_ends::node::pre_order_traversal;
    }

    template <typename Node, typename IsReverse, typename StackGen>
    template <typename ...Args>
    depth_first_tree_iterator<Node,IsReverse,StackGen>::depth_first_tree_iterator(
        reference node,
        bool is_end,
        Args&&... args
    ) : _node_stack(::std::forward<Args>(args)...),
        _itr_stack(::std::forward<Args>(args)...),
        _current_ptr(is_end ? nullptr : ::std::pointer_traits<pointer>::pointer_to(node)),
        _root_ptr(::std::pointer_traits<pointer>::pointer_to(node)),
        _state(is_end ? ::odds_and_ends::node::no_traversal : type::_dec_state(IsReverse()))
    {
    }

    template <typename Node, typename IsReverse, typename StackGen>
    depth_first_tree_iterator<Node,IsReverse,StackGen>::depth_first_tree_iterator(
        depth_first_tree_iterator const& other
    ) : _node_stack(other._node_stack),
        _itr_stack(other._itr_stack),
        _current_ptr(other._current_ptr),
        _root_ptr(other._root_ptr),
        _state(other._state)
    {
    }

    template <typename Node, typename IsReverse, typename StackGen>
    template <typename N, typename I, typename SG>
    depth_first_tree_iterator<Node,IsReverse,StackGen>::depth_first_tree_iterator(
        depth_first_tree_iterator<N,I,SG> const& other,
        typename ::boost::enable_if<
            typename ::boost::mpl::eval_if<
                ::boost::mpl::equal_to<I,IsReverse>,
                ::boost::mpl::if_<
                    ::std::is_same<N,Node>,
                    ::boost::mpl::false_,
                    ::std::is_convertible<N,Node>
                >,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _node_stack(other._node_stack),
        _itr_stack(other._itr_stack),
        _current_ptr(other._current_ptr),
        _root_ptr(other._root_ptr),
        _state(other._state)
    {
    }

    template <typename Node, typename IsReverse, typename StackGen>
    template <typename N, typename I, typename SG, typename Alloc>
    depth_first_tree_iterator<Node,IsReverse,StackGen>::depth_first_tree_iterator(
        depth_first_tree_iterator<N,I,SG> const& other,
        Alloc const& alloc,
        typename ::boost::enable_if<
            typename ::boost::mpl::eval_if<
                ::boost::mpl::equal_to<I,IsReverse>,
                ::boost::mpl::if_<
                    ::std::is_same<N,Node>,
                    ::boost::mpl::false_,
                    ::std::is_convertible<N,Node>
                >,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _node_stack(other._node_stack, alloc),
        _itr_stack(other._itr_stack, alloc),
        _current_ptr(other._current_ptr),
        _root_ptr(other._root_ptr),
        _state(other._state)
    {
    }

    template <typename Node, typename IsReverse, typename StackGen>
    depth_first_tree_iterator<Node,IsReverse,StackGen>::depth_first_tree_iterator(
        depth_first_tree_iterator&& other
    ) : _node_stack(::std::move(other._node_stack)),
        _itr_stack(::std::move(other._itr_stack)),
        _current_ptr(::std::move(other._current_ptr)),
        _root_ptr(::std::move(other._root_ptr)),
        _state(other._state)
    {
    }

    template <typename Node, typename IsReverse, typename StackGen>
    template <typename N, typename I, typename SG>
    depth_first_tree_iterator<Node,IsReverse,StackGen>::depth_first_tree_iterator(
        depth_first_tree_iterator<N,I,SG>&& other,
        typename ::boost::enable_if<
            typename ::boost::mpl::eval_if<
                ::boost::mpl::equal_to<I,IsReverse>,
                ::boost::mpl::if_<
                    ::std::is_same<N,Node>,
                    ::boost::mpl::false_,
                    ::std::is_convertible<N,Node>
                >,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _node_stack(::std::move(other._node_stack)),
        _itr_stack(::std::move(other._itr_stack)),
        _current_ptr(::std::move(other._current_ptr)),
        _root_ptr(::std::move(other._root_ptr)),
        _state(other._state)
    {
    }

    template <typename Node, typename IsReverse, typename StackGen>
    template <typename N, typename I, typename SG, typename Alloc>
    depth_first_tree_iterator<Node,IsReverse,StackGen>::depth_first_tree_iterator(
        depth_first_tree_iterator<N,I,SG>&& other,
        Alloc const& alloc,
        typename ::boost::enable_if<
            typename ::boost::mpl::eval_if<
                ::boost::mpl::equal_to<I,IsReverse>,
                ::boost::mpl::if_<
                    ::std::is_same<N,Node>,
                    ::boost::mpl::false_,
                    ::std::is_convertible<N,Node>
                >,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _node_stack(::std::move(other._node_stack), alloc),
        _itr_stack(::std::move(other._itr_stack), alloc),
        _current_ptr(::std::move(other._current_ptr)),
        _root_ptr(::std::move(other._root_ptr)),
        _state(other._state)
    {
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline depth_first_tree_iterator<Node,IsReverse,StackGen>&
        depth_first_tree_iterator<Node,IsReverse,StackGen>::operator=(
            depth_first_tree_iterator const& other
        )
    {
        if (this != &other)
        {
            this->_node_stack = other._node_stack;
            this->_itr_stack = other._itr_stack;
            this->_current_ptr = other._current_ptr;
            this->_root_ptr = other._root_ptr;
            this->_state = other._state;
        }

        return *this;
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline depth_first_tree_iterator<Node,IsReverse,StackGen>&
        depth_first_tree_iterator<Node,IsReverse,StackGen>::operator=(
            depth_first_tree_iterator&& other
        )
    {
        if (this != &static_cast<depth_first_tree_iterator&>(other))
        {
            this->_node_stack = ::std::move(other._node_stack);
            this->_itr_stack = ::std::move(other._itr_stack);
            this->_current_ptr = ::std::move(other._current_ptr);
            this->_root_ptr = ::std::move(other._root_ptr);
            this->_state = other._state;
        }

        return *this;
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline depth_first_tree_iterator<Node,IsReverse,StackGen>::operator
        ::odds_and_ends::node::traversal_state() const
    {
        return this->_state;
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline bool depth_first_tree_iterator<Node,IsReverse,StackGen>::operator!() const
    {
        return !this->_state.get();
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline typename depth_first_tree_iterator<Node,IsReverse,StackGen>::reference
        depth_first_tree_iterator<Node,IsReverse,StackGen>::operator*() const
    {
        return *this->_current_ptr;
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline typename depth_first_tree_iterator<Node,IsReverse,StackGen>::pointer
        depth_first_tree_iterator<Node,IsReverse,StackGen>::operator->() const
    {
        return this->_current_ptr;
    }

    template <typename Node, typename IsR, typename SG>
    inline typename depth_first_tree_iterator<Node,IsR,SG>::pointer
        depth_first_tree_iterator<Node,IsR,SG>::_get(_child_iterator itr, ::boost::mpl::true_)
    {
        return ::std::pointer_traits<pointer>::pointer_to(*itr);
    }

    template <typename Node, typename IsR, typename SG>
    inline typename depth_first_tree_iterator<Node,IsR,SG>::pointer
        depth_first_tree_iterator<Node,IsR,SG>::_get(_child_iterator itr, ::boost::mpl::false_)
    {
        return itr->second;
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline depth_first_tree_iterator<Node,IsReverse,StackGen>&
        depth_first_tree_iterator<Node,IsReverse,StackGen>::operator++()
    {
        if (type::_dec_state(IsReverse()) == this->_state)
        {
            _child_iterator itr = this->_current_begin(IsReverse());

            if (itr == this->_current_end(IsReverse()))
            {
                // No children: change state.
                this->_state = type::_inc_state(IsReverse());
            }
            else
            {
                // Go deeper.
                this->_node_stack.push(this->_current_ptr);
                this->_current_ptr = type::_get(
                    itr,
                    ::odds_and_ends::static_introspection::nested_type
                    ::has_traits<typename _child_iterator::value_type>()
                );
                this->_itr_stack.push(itr);
            }
        }
        else if (type::_inc_state(IsReverse()) == this->_state)
        {
            if (this->_node_stack.empty())
            {
                BOOST_ASSERT(this->_itr_stack.empty());
                // Pass the end.
                this->_state = ::odds_and_ends::node::no_traversal;
                this->_current_ptr = nullptr;
            }
            else
            {
                BOOST_ASSERT(!this->_itr_stack.empty());

                _child_iterator itr = this->_itr_stack.top();

                this->_current_ptr = this->_node_stack.top();
                this->_node_stack.pop();
                this->_itr_stack.pop();

                if (++itr != this->_current_end(IsReverse()))
                {
                    // Traverse the next sibling.
                    this->_state = type::_dec_state(IsReverse());
                    this->_node_stack.push(this->_current_ptr);
                    this->_current_ptr = type::_get(
                        itr,
                        ::odds_and_ends::static_introspection::nested_type
                        ::has_traits<typename _child_iterator::value_type>()
                    );
                    this->_itr_stack.push(itr);
                }
            }
        }
        else  // if (::odds_and_ends::node::no_traversal == this->_state)
        {
            BOOST_ASSERT_MSG(false, "Do not increment past-the-end!");
        }

        return *this;
    }

    template <typename Node, typename IsReverse, typename StackGen>
    depth_first_tree_iterator<Node,IsReverse,StackGen>
        depth_first_tree_iterator<Node,IsReverse,StackGen>::operator++(int)
    {
        depth_first_tree_iterator<Node,IsReverse,StackGen> result(*this);
        ++(*this);
        return result;
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline depth_first_tree_iterator<Node,IsReverse,StackGen>&
        depth_first_tree_iterator<Node,IsReverse,StackGen>::operator--()
    {
        if (type::_inc_state(IsReverse()) == this->_state)
        {
            _child_iterator itr = this->_current_end(IsReverse());

            if (itr == this->_current_begin(IsReverse()))
            {
                // No children: change state.
                this->_state = type::_dec_state(IsReverse());
            }
            else
            {
                // Go deeper.
                this->_node_stack.push(this->_current_ptr);
                this->_current_ptr = type::_get(
                    (--itr),
                    ::odds_and_ends::static_introspection::nested_type
                    ::has_traits<typename _child_iterator::value_type>()
                );
                this->_itr_stack.push(itr);
            }
        }
        else if (type::_dec_state(IsReverse()) == this->_state)
        {
            if (this->_node_stack.empty())
            {
                BOOST_ASSERT(this->_itr_stack.empty());
                // Pass the end.
                this->_state = ::odds_and_ends::node::no_traversal;
                this->_current_ptr = nullptr;
            }
            else
            {
                BOOST_ASSERT(!this->_itr_stack.empty());

                _child_iterator itr = this->_itr_stack.top();

                this->_current_ptr = this->_node_stack.top();
                this->_node_stack.pop();
                this->_itr_stack.pop();

                if (this->_current_begin(IsReverse()) != itr)
                {
                    // Traverse the previous sibling.
                    this->_state = type::_inc_state(IsReverse());
                    this->_node_stack.push(this->_current_ptr);
                    this->_current_ptr = type::_get(
                        (--itr),
                        ::odds_and_ends::static_introspection::nested_type
                        ::has_traits<typename _child_iterator::value_type>()
                    );
                    this->_itr_stack.push(itr);
                }
            }
        }
        else  // if (::odds_and_ends::node::no_traversal == this->_state)
        {
            BOOST_ASSERT_MSG(this->_root_ptr, "Do not decrement past-the-end of nullptr!");
            this->_current_ptr = this->_root_ptr;
            this->_state = type::_inc_state(IsReverse());
        }

        return *this;
    }

    template <typename Node, typename IsReverse, typename StackGen>
    depth_first_tree_iterator<Node,IsReverse,StackGen>
        depth_first_tree_iterator<Node,IsReverse,StackGen>::operator--(int)
    {
        depth_first_tree_iterator<Node,IsReverse,StackGen> result(*this);
        --(*this);
        return result;
    }

    template <typename N1, typename I1, typename SG1, typename N2, typename I2, typename SG2>
    inline typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
        operator==(
            depth_first_tree_iterator<N1,I1,SG1> const& lhs,
            depth_first_tree_iterator<N2,I2,SG2> const& rhs
        )
    {
        if (lhs._state == rhs._state)
        {
            return lhs._state ? (lhs._current_ptr == rhs._current_ptr) : !rhs._state;
        }
        else
        {
            return false;
        }
    }

    template <typename N1, typename I1, typename SG1, typename N2, typename I2, typename SG2>
    inline typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
        operator!=(
            depth_first_tree_iterator<N1,I1,SG1> const& lhs,
            depth_first_tree_iterator<N2,I2,SG2> const& rhs
        )
    {
        return !(lhs == rhs);
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline typename depth_first_tree_iterator<Node,IsReverse,StackGen>::_child_iterator
        depth_first_tree_iterator<Node,IsReverse,StackGen>::_current_begin(::boost::mpl::false_)
    {
        return this->_current_ptr->begin();
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline typename depth_first_tree_iterator<Node,IsReverse,StackGen>::_child_iterator
        depth_first_tree_iterator<Node,IsReverse,StackGen>::_current_begin(::boost::mpl::true_)
    {
        return this->_current_ptr->rbegin();
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline typename depth_first_tree_iterator<Node,IsReverse,StackGen>::_child_iterator
        depth_first_tree_iterator<Node,IsReverse,StackGen>::_current_end(::boost::mpl::false_)
    {
        return this->_current_ptr->end();
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline typename depth_first_tree_iterator<Node,IsReverse,StackGen>::_child_iterator
        depth_first_tree_iterator<Node,IsReverse,StackGen>::_current_end(::boost::mpl::true_)
    {
        return this->_current_ptr->rend();
    }

    template <
        typename StackGen = ::odds_and_ends::node::container::stack< ::boost::mpl::_>,
        typename Node,
        typename ...Args
    >
    inline depth_first_tree_iterator<Node,::boost::mpl::false_,StackGen>
        make_depth_first_tree_iterator(Node& node, Args&&... args)
    {
        return depth_first_tree_iterator<Node,::boost::mpl::false_,StackGen>(
            node,
            false,
            ::std::forward<Args>(args)...
        );
    }

    template <
        typename StackGen = ::odds_and_ends::node::container::stack< ::boost::mpl::_>,
        typename Node,
        typename ...Args
    >
    inline depth_first_tree_iterator<Node,::boost::mpl::false_,StackGen>
        make_depth_first_tree_iterator_end(Node& node, Args&&... args)
    {
        return depth_first_tree_iterator<Node,::boost::mpl::false_,StackGen>(
            node,
            true,
            ::std::forward<Args>(args)...
        );
    }

    template <
        typename StackGen = ::odds_and_ends::node::container::stack< ::boost::mpl::_>,
        typename Node,
        typename ...Args
    >
    inline depth_first_tree_iterator<Node,::boost::mpl::true_,StackGen>
        make_depth_first_tree_reverse_iterator(Node& node, Args&&... args)
    {
        return depth_first_tree_iterator<Node,::boost::mpl::true_,StackGen>(
            node,
            false,
            ::std::forward<Args>(args)...
        );
    }

    template <
        typename StackGen = ::odds_and_ends::node::container::stack< ::boost::mpl::_>,
        typename Node,
        typename ...Args
    >
    inline depth_first_tree_iterator<Node,::boost::mpl::true_,StackGen>
        make_depth_first_tree_reverse_iterator_end(Node& node, Args&&... args)
    {
        return depth_first_tree_iterator<Node,::boost::mpl::true_,StackGen>(
            node,
            true,
            ::std::forward<Args>(args)...
        );
    }
}}  // namespace odds_and_ends::node

#endif  // ODDS_AND_ENDS__NODE__ITERATOR__DEPTH_FIRST_TREE_HPP

