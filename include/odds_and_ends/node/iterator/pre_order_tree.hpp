// Copyright (C) 2011-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__ITERATOR__PRE_ORDER_TREE_HPP
#define ODDS_AND_ENDS__NODE__ITERATOR__PRE_ORDER_TREE_HPP

#include <type_traits>
#include <iterator>
#include <odds_and_ends/node/container/stack.hpp>
#include <odds_and_ends/node/traversal_state.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_forward_iterator.hpp>
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
    class pre_order_tree_iterator
    {
        struct _enabler
        {
        };

    public:
        typedef ::std::forward_iterator_tag iterator_category;
        typedef Node value_type;
        typedef typename ::boost::mpl::if_<
            ::std::is_const<Node>,
            typename ::std::remove_const<Node>::type::traits::const_pointer,
            typename ::std::remove_const<Node>::type::traits::pointer
        >::type pointer;
        typedef value_type& reference;

    private:
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
        typedef typename ::boost::mpl::apply1<StackGen,pointer>::type _node_stack_t;
        typedef typename ::boost::mpl::apply1<
            StackGen,
            _child_iterator
        >::type _child_iterator_stack_t;

        _node_stack_t _node_stack;
        _child_iterator_stack_t _itr_stack;
        _child_iterator _current_itr;
        pointer _current_ptr;
        ::odds_and_ends::node::traversal_state _state;

    public:
        template <typename A0, typename ...Args>
        explicit pre_order_tree_iterator(
            A0&& a0,
            Args&&... args,
            typename ::boost::disable_if<
                typename ::boost::mpl::if_<
                    ::std::is_convertible<A0,Node>,
                    ::boost::mpl::true_,
                    ::odds_and_ends::static_introspection::concept::is_legacy_forward_iterator<A0>
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename ...Args>
        explicit pre_order_tree_iterator(reference node, Args&&... args);

        template <typename N, typename I, typename SG>
        pre_order_tree_iterator(
            pre_order_tree_iterator<N,I,SG> const& other,
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
        pre_order_tree_iterator(
            pre_order_tree_iterator<N,I,SG>&& other,
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

        pre_order_tree_iterator(pre_order_tree_iterator const& other);
        pre_order_tree_iterator(pre_order_tree_iterator&& other);
        pre_order_tree_iterator();
        ~pre_order_tree_iterator();
        pre_order_tree_iterator& operator=(pre_order_tree_iterator const& other);
        pre_order_tree_iterator& operator=(pre_order_tree_iterator&& other);

        template <typename N, typename I, typename SG>
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
            pre_order_tree_iterator&
        >::type
            operator=(pre_order_tree_iterator<N,I,SG> const& other);

        template <typename N, typename I, typename SG>
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
            pre_order_tree_iterator&
        >::type
            operator=(pre_order_tree_iterator<N,I,SG>&& other);

        operator ::odds_and_ends::node::traversal_state() const;
        reference operator*() const;
        pointer operator->() const;
        pre_order_tree_iterator& operator++();
        pre_order_tree_iterator operator++(int);

    private:
        void _push(::boost::mpl::false_);
        void _push(::boost::mpl::true_);
        void _clear_itr_stack(::boost::mpl::false_);
        void _clear_itr_stack(::boost::mpl::true_);
        _child_iterator _end(::boost::mpl::false_);
        _child_iterator _end(::boost::mpl::true_);

        template <typename N, typename I, typename SG>
        friend class pre_order_tree_iterator;

        template <typename N1, typename I1, typename SG1, typename N2, typename I2, typename SG2>
        friend typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
            operator==(
                pre_order_tree_iterator<N1,I1,SG1> const& lhs,
                pre_order_tree_iterator<N2,I2,SG2> const& rhs
            );

        template <typename N1, typename I1, typename SG1, typename N2, typename I2, typename SG2>
        friend typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
            operator!=(
                pre_order_tree_iterator<N1,I1,SG1> const& lhs,
                pre_order_tree_iterator<N2,I2,SG2> const& rhs
            );
    };
}}  // namespace odds_and_ends::node

#include <utility>
#include <memory>
#include <odds_and_ends/static_introspection/member_function/has_clear.hpp>

namespace odds_and_ends { namespace node {

    template <typename Node, typename IsReverse, typename StackGen>
    inline pre_order_tree_iterator<Node,IsReverse,StackGen>::pre_order_tree_iterator() :
        _node_stack(),
        _itr_stack(),
        _current_itr(),
        _current_ptr(nullptr),
        _state(::odds_and_ends::node::no_traversal)
    {
    }

    template <typename Node, typename IsReverse, typename StackGen>
    template <typename A0, typename ...Args>
    inline pre_order_tree_iterator<Node,IsReverse,StackGen>::pre_order_tree_iterator(
        A0&& a0,
        Args&&... args,
        typename ::boost::disable_if<
            typename ::boost::mpl::if_<
                ::std::is_convertible<A0,Node>,
                ::boost::mpl::true_,
                ::odds_and_ends::static_introspection::concept::is_legacy_forward_iterator<A0>
            >::type,
            _enabler
        >::type
    ) : _node_stack(::std::forward<A0>(a0), ::std::forward<Args>(args)...),
        _itr_stack(::std::forward<A0>(a0), ::std::forward<Args>(args)...),
        _current_itr(),
        _current_ptr(nullptr),
        _state(::odds_and_ends::node::no_traversal)
    {
    }

    template <typename Node, typename IsReverse, typename StackGen>
    template <typename ...Args>
    inline pre_order_tree_iterator<Node,IsReverse,StackGen>::pre_order_tree_iterator(
        reference node,
        Args&&... args
    ) : _node_stack(::std::forward<Args>(args)...),
        _itr_stack(::std::forward<Args>(args)...),
        _current_itr(),
        _current_ptr(::std::pointer_traits<pointer>::pointer_to(node)),
        _state(::odds_and_ends::node::pre_order_traversal)
    {
        this->_push(IsReverse());
    }

    template <typename Node, typename IsReverse, typename StackGen>
    template <typename N, typename I, typename SG>
    inline pre_order_tree_iterator<Node,IsReverse,StackGen>::pre_order_tree_iterator(
        pre_order_tree_iterator<N,I,SG> const& other,
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
        _current_itr(other._current_itr),
        _current_ptr(other._current_ptr),
        _state(other._state)
    {
    }

    template <typename Node, typename IsReverse, typename StackGen>
    template <typename N, typename I, typename SG>
    inline pre_order_tree_iterator<Node,IsReverse,StackGen>::pre_order_tree_iterator(
        pre_order_tree_iterator<N,I,SG>&& other,
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
        _current_itr(::std::move(other._current_itr)),
        _current_ptr(::std::move(other._current_ptr)),
        _state(other._state)
    {
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline pre_order_tree_iterator<Node,IsReverse,StackGen>::pre_order_tree_iterator(
        pre_order_tree_iterator const& other
    ) : _node_stack(other._node_stack),
        _itr_stack(other._itr_stack),
        _current_itr(other._current_itr),
        _current_ptr(other._current_ptr),
        _state(other._state)
    {
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline pre_order_tree_iterator<Node,IsReverse,StackGen>::pre_order_tree_iterator(
        pre_order_tree_iterator&& other
    ) : _node_stack(::std::move(other._node_stack)),
        _itr_stack(::std::move(other._itr_stack)),
        _current_itr(::std::move(other._current_itr)),
        _current_ptr(::std::move(other._current_ptr)),
        _state(other._state)
    {
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline pre_order_tree_iterator<Node,IsReverse,StackGen>::~pre_order_tree_iterator()
    {
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline pre_order_tree_iterator<Node,IsReverse,StackGen>&
        pre_order_tree_iterator<Node,IsReverse,StackGen>::operator=(
            pre_order_tree_iterator const& other
        )
    {
        if (this != &other)
        {
            this->_node_stack = other._node_stack;
            this->_itr_stack = other._itr_stack;
            this->_current_itr = other._current_itr;
            this->_current_ptr = other._current_ptr;
            this->_state = other._state;
        }

        return *this;
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline pre_order_tree_iterator<Node,IsReverse,StackGen>&
        pre_order_tree_iterator<Node,IsReverse,StackGen>::operator=(
            pre_order_tree_iterator&& other
        )
    {
        if (this != &static_cast<pre_order_tree_iterator&>(other))
        {
            this->_node_stack = ::std::move(other._node_stack);
            this->_itr_stack = ::std::move(other._itr_stack);
            this->_current_itr = ::std::move(other._current_itr);
            this->_current_ptr = ::std::move(other._current_ptr);
            this->_state = other._state;
        }

        return *this;
    }

    template <typename Node, typename IsReverse, typename StackGen>
    template <typename N, typename I, typename SG>
    inline typename ::boost::enable_if<
        typename ::boost::mpl::eval_if<
            ::boost::mpl::equal_to<I,IsReverse>,
            ::boost::mpl::if_<
                ::std::is_same<N,Node>,
                ::boost::mpl::false_,
                ::std::is_convertible<N,Node>
            >,
            ::boost::mpl::false_
        >::type,
        pre_order_tree_iterator<Node,IsReverse,StackGen>&
    >::type
        pre_order_tree_iterator<Node,IsReverse,StackGen>::operator=(
            pre_order_tree_iterator<N,I,SG> const& other
        )
    {
        if (this != &other)
        {
            this->_node_stack = other._node_stack;
            this->_itr_stack = other._itr_stack;
            this->_current_itr = other._current_itr;
            this->_current_ptr = other._current_ptr;
            this->_state = other._state;
        }

        return *this;
    }

    template <typename Node, typename IsReverse, typename StackGen>
    template <typename N, typename I, typename SG>
    inline typename ::boost::enable_if<
        typename ::boost::mpl::eval_if<
            ::boost::mpl::equal_to<I,IsReverse>,
            ::boost::mpl::if_<
                ::std::is_same<N,Node>,
                ::boost::mpl::false_,
                ::std::is_convertible<N,Node>
            >,
            ::boost::mpl::false_
        >::type,
        pre_order_tree_iterator<Node,IsReverse,StackGen>&
    >::type
        pre_order_tree_iterator<Node,IsReverse,StackGen>::operator=(
            pre_order_tree_iterator<N,I,SG>&& other
        )
    {
        if (this != &static_cast<pre_order_tree_iterator<N,I,SG>&>(other))
        {
            this->_node_stack = ::std::move(other._node_stack);
            this->_itr_stack = ::std::move(other._itr_stack);
            this->_current_itr = ::std::move(other._current_itr);
            this->_current_ptr = ::std::move(other._current_ptr);
            this->_state = other._state;
        }

        return *this;
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline pre_order_tree_iterator<Node,IsReverse,StackGen>::operator
        ::odds_and_ends::node::traversal_state() const
    {
        return this->_state;
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline typename pre_order_tree_iterator<Node,IsReverse,StackGen>::reference
        pre_order_tree_iterator<Node,IsReverse,StackGen>::operator*() const
    {
        return *this->_current_ptr;
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline typename pre_order_tree_iterator<Node,IsReverse,StackGen>::pointer
        pre_order_tree_iterator<Node,IsReverse,StackGen>::operator->() const
    {
        return this->_current_ptr;
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline pre_order_tree_iterator<Node,IsReverse,StackGen>&
        pre_order_tree_iterator<Node,IsReverse,StackGen>::operator++()
    {
        if (this->_itr_stack.top() == this->_end(IsReverse()))
        {
            for (bool is_post_order = true; is_post_order; )
            {
                this->_itr_stack.pop();

                if (this->_node_stack.empty())
                {
                    this->_state = ::odds_and_ends::node::no_traversal;
                    this->_clear_itr_stack(
                        ::odds_and_ends::static_introspection::member_function::has_clear<
                            _child_iterator_stack_t
                        >()
                    );
                    is_post_order = false;
                }
                else
                {
                    this->_current_ptr = this->_node_stack.top();
                    this->_node_stack.pop();

                    if (++this->_current_itr == this->_end(IsReverse()))
                    {
                        _child_iterator itr(this->_itr_stack.top());

                        this->_itr_stack.pop();

                        if (!this->_itr_stack.empty())
                        {
                            this->_current_itr = this->_itr_stack.top();
                        }

                        this->_itr_stack.push(itr);
                    }
                    else
                    {
                        this->_itr_stack.pop();
                        this->_node_stack.push(this->_current_ptr);
                        this->_itr_stack.push(this->_current_itr);
                        this->_current_ptr = ::std::pointer_traits<pointer>::pointer_to(
                            *this->_current_itr
                        );
                        this->_push(IsReverse());
                        is_post_order = false;
                    }
                }
            }
        }
        else
        {
            this->_node_stack.push(this->_current_ptr);
            this->_current_ptr = ::std::pointer_traits<pointer>::pointer_to(
                *(this->_current_itr = this->_itr_stack.top())
            );
            this->_push(IsReverse());
        }

        return *this;
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline pre_order_tree_iterator<Node,IsReverse,StackGen>
        pre_order_tree_iterator<Node,IsReverse,StackGen>::operator++(int)
    {
        pre_order_tree_iterator<Node,IsReverse,StackGen> itr(*this);
        ++(*this);
        return itr;
    }

    template <typename N1, typename I1, typename SG1, typename N2, typename I2, typename SG2>
    inline typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
        operator==(
            pre_order_tree_iterator<N1,I1,SG1> const& lhs,
            pre_order_tree_iterator<N2,I2,SG2> const& rhs
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
            pre_order_tree_iterator<N1,I1,SG1> const& lhs,
            pre_order_tree_iterator<N2,I2,SG2> const& rhs
        )
    {
        return !(lhs == rhs);
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline void pre_order_tree_iterator<Node,IsReverse,StackGen>::_push(::boost::mpl::false_)
    {
        this->_itr_stack.push(this->_current_ptr->begin());
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline void pre_order_tree_iterator<Node,IsReverse,StackGen>::_push(::boost::mpl::true_)
    {
        this->_itr_stack.push(this->_current_ptr->rbegin());
    }

    template <typename Node, typename IsReverse, typename StackGen>
    void pre_order_tree_iterator<Node,IsReverse,StackGen>::_clear_itr_stack(::boost::mpl::false_)
    {
        for (; !this->_itr_stack.empty(); )
        {
            this->_itr_stack.pop();
        }
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline void
        pre_order_tree_iterator<Node,IsReverse,StackGen>::_clear_itr_stack(::boost::mpl::true_)
    {
        this->_itr_stack.clear();
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline typename pre_order_tree_iterator<Node,IsReverse,StackGen>::_child_iterator
        pre_order_tree_iterator<Node,IsReverse,StackGen>::_end(::boost::mpl::false_)
    {
        return this->_current_ptr->end();
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline typename pre_order_tree_iterator<Node,IsReverse,StackGen>::_child_iterator
        pre_order_tree_iterator<Node,IsReverse,StackGen>::_end(::boost::mpl::true_)
    {
        return this->_current_ptr->rend();
    }

    template <
        typename StackGen = ::odds_and_ends::node::container::stack< ::boost::mpl::_>,
        typename Node,
        typename ...Args
    >
    inline pre_order_tree_iterator<Node,::boost::mpl::false_,StackGen>
        make_pre_order_tree_iterator(Node& node, Args&&... args)
    {
        return pre_order_tree_iterator<Node,::boost::mpl::false_,StackGen>(
            node,
            ::std::forward<Args>(args)...
        );
    }

    template <
        typename StackGen = ::odds_and_ends::node::container::stack< ::boost::mpl::_>,
        typename Node,
        typename ...Args
    >
    inline pre_order_tree_iterator<Node,::boost::mpl::true_,StackGen>
        make_post_order_tree_reverse_iterator(Node& node, Args&&... args)
    {
        return pre_order_tree_iterator<Node,::boost::mpl::true_,StackGen>(
            node,
            ::std::forward<Args>(args)...
        );
    }
}}  // namespace odds_and_ends::node

#endif  // ODDS_AND_ENDS__NODE__ITERATOR__PRE_ORDER_TREE_HPP

