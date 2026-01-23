// Copyright (C) 2011-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__ITERATOR__POST_ORDER_TREE_HPP
#define ODDS_AND_ENDS__NODE__ITERATOR__POST_ORDER_TREE_HPP

#include <type_traits>
#include <iterator>
#include <odds_and_ends/node/container/stack.hpp>
#include <odds_and_ends/node/traversal_state.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_forward_iterator.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_traits.hpp>
#include <odds_and_ends/use_default_policy.hpp>
#include <boost/core/enable_if.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/apply_wrap.hpp>

namespace odds_and_ends { namespace node {

    template <
        typename Node,
        typename IsReverse = ::boost::mpl::false_,
        typename StackGen = ::odds_and_ends::use_default_policy
    >
    class post_order_tree_iterator
    {
        struct _enabler
        {
        };

    public:
        typedef ::odds_and_ends::node::post_order_tree_iterator<Node,IsReverse,StackGen> type;
        typedef ::std::forward_iterator_tag iterator_category;
        typedef Node value_type;
        typedef typename ::boost::mpl::if_<
            ::std::is_const<Node>,
            typename ::std::remove_const<Node>::type::traits::const_pointer,
            typename ::std::remove_const<Node>::type::traits::pointer
        >::type pointer;
        typedef value_type& reference;

    private:
        typedef typename ::boost::mpl::lambda<
            typename ::boost::mpl::if_<
                ::std::is_same<StackGen,::odds_and_ends::use_default_policy>,
                ::odds_and_ends::node::container::stack< ::boost::mpl::_>,
                StackGen
            >::type
        >::type _stack_gen_lambda;
        typedef typename ::boost::mpl::apply_wrap1<_stack_gen_lambda,pointer>::type _stack_t;

        _stack_t _stack;
        pointer _current;
        ::odds_and_ends::node::traversal_state _state;

    public:
        template <typename A0, typename ...Args>
        explicit post_order_tree_iterator(
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
        explicit post_order_tree_iterator(reference node, Args&&... args);

        template <typename N, typename I, typename SG>
        post_order_tree_iterator(
            post_order_tree_iterator<N,I,SG> const& other,
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
        post_order_tree_iterator(
            post_order_tree_iterator<N,I,SG>&& other,
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

        post_order_tree_iterator(post_order_tree_iterator const& other);
        post_order_tree_iterator(post_order_tree_iterator&& other);
        post_order_tree_iterator();
        ~post_order_tree_iterator();
        post_order_tree_iterator& operator=(post_order_tree_iterator const& other);
        post_order_tree_iterator& operator=(post_order_tree_iterator&& other);

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
            post_order_tree_iterator&
        >::type
            operator=(post_order_tree_iterator<N,I,SG> const& other);

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
            post_order_tree_iterator&
        >::type
            operator=(post_order_tree_iterator<N,I,SG>&& other);

        operator ::odds_and_ends::node::traversal_state() const;
        bool operator!() const;
        reference operator*() const;
        pointer operator->() const;
        post_order_tree_iterator& operator++();
        post_order_tree_iterator operator++(int);

    private:
        template <typename Itr>
        static pointer _get(Itr itr, ::boost::mpl::true_);

        template <typename Itr>
        static pointer _get(Itr itr, ::boost::mpl::false_);

        template <typename S>
        void _init(S&, ::boost::mpl::false_);

        template <typename S>
        void _init(S&, ::boost::mpl::true_);

        void _init(::boost::mpl::false_, ::boost::mpl::false_);
        void _init(::boost::mpl::false_, ::boost::mpl::true_);
        void _init(::boost::mpl::true_, ::boost::mpl::false_);
        void _init(::boost::mpl::true_, ::boost::mpl::true_);

        template <typename N, typename I, typename SG>
        friend class post_order_tree_iterator;

        template <typename N1, typename I1, typename SG1, typename N2, typename I2, typename SG2>
        friend typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
            operator==(
                post_order_tree_iterator<N1,I1,SG1> const& lhs,
                post_order_tree_iterator<N2,I2,SG2> const& rhs
            );

        template <typename N1, typename I1, typename SG1, typename N2, typename I2, typename SG2>
        friend typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
            operator!=(
                post_order_tree_iterator<N1,I1,SG1> const& lhs,
                post_order_tree_iterator<N2,I2,SG2> const& rhs
            );
    };
}}  // namespace odds_and_ends::node

#include <utility>
#include <memory>
#include <odds_and_ends/static_introspection/member_function/has_get_allocator.hpp>

namespace odds_and_ends { namespace node {

    template <typename Node, typename IsReverse, typename StackGen>
    inline post_order_tree_iterator<Node,IsReverse,StackGen>::post_order_tree_iterator() :
        _stack(), _current(nullptr), _state(::odds_and_ends::node::no_traversal)
    {
    }

    template <typename Node, typename IsReverse, typename StackGen>
    template <typename A0, typename ...Args>
    inline post_order_tree_iterator<Node,IsReverse,StackGen>::post_order_tree_iterator(
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
    ) : _stack(::std::forward<A0>(a0), ::std::forward<Args>(args)...),
        _current(nullptr),
        _state(::odds_and_ends::node::no_traversal)
    {
    }

    template <typename Node, typename IsReverse, typename StackGen>
    template <typename ...Args>
    post_order_tree_iterator<Node,IsReverse,StackGen>::post_order_tree_iterator(
        reference node,
        Args&&... args
    ) : _stack(),
        _current(::std::pointer_traits<pointer>::pointer_to(node)),
        _state(::odds_and_ends::node::post_order_traversal)
    {
        this->_init(
            IsReverse(),
            ::odds_and_ends::static_introspection::member_function::has_get_allocator<_stack_t>()
        );
    }

    template <typename Node, typename IsReverse, typename StackGen>
    template <typename N, typename I, typename SG>
    inline post_order_tree_iterator<Node,IsReverse,StackGen>::post_order_tree_iterator(
        post_order_tree_iterator<N,I,SG> const& other,
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
    ) : _stack(other._stack), _current(other._current), _state(other._state)
    {
    }

    template <typename Node, typename IsReverse, typename StackGen>
    template <typename N, typename I, typename SG>
    inline post_order_tree_iterator<Node,IsReverse,StackGen>::post_order_tree_iterator(
        post_order_tree_iterator<N,I,SG>&& other,
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
    ) : _stack(::std::move(other._stack)),
        _current(::std::move(other._current)),
        _state(other._state)
    {
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline post_order_tree_iterator<Node,IsReverse,StackGen>::post_order_tree_iterator(
        post_order_tree_iterator const& other
    ) : _stack(other._stack), _current(other._current), _state(other._state)
    {
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline post_order_tree_iterator<Node,IsReverse,StackGen>::post_order_tree_iterator(
        post_order_tree_iterator&& other
    ) : _stack(::std::move(other._stack)),
        _current(::std::move(other._current)),
        _state(other._state)
    {
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline post_order_tree_iterator<Node,IsReverse,StackGen>::~post_order_tree_iterator()
    {
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline post_order_tree_iterator<Node,IsReverse,StackGen>&
        post_order_tree_iterator<Node,IsReverse,StackGen>::operator=(
            post_order_tree_iterator const& other
        )
    {
        if (this != &other)
        {
            this->_stack = other._stack;
            this->_current = other._current;
            this->_state = other._state;
        }

        return *this;
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline post_order_tree_iterator<Node,IsReverse,StackGen>&
        post_order_tree_iterator<Node,IsReverse,StackGen>::operator=(
            post_order_tree_iterator&& other
        )
    {
        if (this != &static_cast<post_order_tree_iterator&>(other))
        {
            this->_stack = ::std::move(other._stack);
            this->_current = ::std::move(other._current);
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
        post_order_tree_iterator<Node,IsReverse,StackGen>&
    >::type
        post_order_tree_iterator<Node,IsReverse,StackGen>::operator=(
            post_order_tree_iterator<N,I,SG> const& other
        )
    {
        if (this != &other)
        {
            this->_stack = other._stack;
            this->_current = other._current;
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
        post_order_tree_iterator<Node,IsReverse,StackGen>&
    >::type
        post_order_tree_iterator<Node,IsReverse,StackGen>::operator=(
            post_order_tree_iterator<N,I,SG>&& other
        )
    {
        if (this != &static_cast<post_order_tree_iterator<N,I,SG>&>(other))
        {
            this->_stack = ::std::move(other._stack);
            this->_current = ::std::move(other._current);
            this->_state = other._state;
        }

        return *this;
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline post_order_tree_iterator<Node,IsReverse,StackGen>::operator
        ::odds_and_ends::node::traversal_state() const
    {
        return this->_state;
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline bool post_order_tree_iterator<Node,IsReverse,StackGen>::operator!() const
    {
        return !this->_state.get();
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline typename post_order_tree_iterator<Node,IsReverse,StackGen>::reference
        post_order_tree_iterator<Node,IsReverse,StackGen>::operator*() const
    {
        return *this->_current;
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline typename post_order_tree_iterator<Node,IsReverse,StackGen>::pointer
        post_order_tree_iterator<Node,IsReverse,StackGen>::operator->() const
    {
        return this->_current;
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline post_order_tree_iterator<Node,IsReverse,StackGen>&
        post_order_tree_iterator<Node,IsReverse,StackGen>::operator++()
    {
        if (this->_stack.empty())
        {
            this->_state = ::odds_and_ends::node::no_traversal;
        }
        else
        {
            this->_current = this->_stack.top();
            this->_stack.pop();
        }

        return *this;
    }

    template <typename Node, typename IsReverse, typename StackGen>
    inline post_order_tree_iterator<Node,IsReverse,StackGen>
        post_order_tree_iterator<Node,IsReverse,StackGen>::operator++(int)
    {
        post_order_tree_iterator<Node,IsReverse,StackGen> itr(*this);
        ++(*this);
        return itr;
    }

    template <typename N1, typename I1, typename SG1, typename N2, typename I2, typename SG2>
    inline typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
        operator==(
            post_order_tree_iterator<N1,I1,SG1> const& lhs,
            post_order_tree_iterator<N2,I2,SG2> const& rhs
        )
    {
        if (lhs._state == rhs._state)
        {
            return lhs._state.get() ? (lhs._current == rhs._current) : !rhs._state.get();
        }
        else
        {
            return false;
        }
    }

    template <typename N1, typename I1, typename SG1, typename N2, typename I2, typename SG2>
    inline typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
        operator!=(
            post_order_tree_iterator<N1,I1,SG1> const& lhs,
            post_order_tree_iterator<N2,I2,SG2> const& rhs
        )
    {
        return !(lhs == rhs);
    }

    template <typename Node, typename IsReverse, typename StackGen>
    template <typename Itr>
    inline typename post_order_tree_iterator<Node,IsReverse,StackGen>::pointer
        post_order_tree_iterator<Node,IsReverse,StackGen>::_get(Itr itr, ::boost::mpl::true_)
    {
        return ::std::pointer_traits<pointer>::pointer_to(*itr);
    }

    template <typename Node, typename IsReverse, typename StackGen>
    template <typename Itr>
    inline typename post_order_tree_iterator<Node,IsReverse,StackGen>::pointer
        post_order_tree_iterator<Node,IsReverse,StackGen>::_get(Itr itr, ::boost::mpl::false_)
    {
        return itr->second;
    }

    template <typename Node, typename IsReverse, typename StackGen>
    template <typename S>
    void post_order_tree_iterator<Node,IsReverse,StackGen>::_init(S& s, ::boost::mpl::false_)
    {
        typename S::value_type itr = this->_current->begin();
        typename S::value_type itr_end = this->_current->end();
        pointer p;

        if (itr != itr_end)
        {
            this->_stack.push(this->_current);

            for (;;)
            {
                for (; itr != itr_end; ++itr)
                {
                    s.push(itr);
                }

                this->_stack.push(
                    type::_get(
                        s.top(),
                        ::odds_and_ends::static_introspection::nested_type::has_traits<
                            typename ::std::remove_const<typename S::value_type>::type::value_type
                        >()
                    )
                );
                s.pop();

                if (s.empty())
                {
                    p = (this->_current = this->_stack.top());
                    itr = p->begin();
                    itr_end = p->end();

                    if (itr == itr_end)
                    {
                        this->_stack.pop();
                        break;
                    }
                }
                else
                {
                    p = this->_stack.top();
                    itr = p->begin();
                    itr_end = p->end();
                }
            }
        }
    }

    template <typename Node, typename IsReverse, typename StackGen>
    template <typename S>
    void post_order_tree_iterator<Node,IsReverse,StackGen>::_init(S& s, ::boost::mpl::true_)
    {
        typename S::value_type itr = this->_current->rbegin();
        typename S::value_type itr_end = this->_current->rend();
        pointer p;

        if (itr != itr_end)
        {
            this->_stack.push(this->_current);

            for (;;)
            {
                for (; itr != itr_end; ++itr)
                {
                    s.push(itr);
                }

                this->_stack.push(
                    type::_get(
                        s.top(),
                        ::odds_and_ends::static_introspection::nested_type::has_traits<
                            typename ::std::remove_const<typename S::value_type>::type::value_type
                        >()
                    )
                );
                s.pop();

                if (s.empty())
                {
                    p = (this->_current = this->_stack.top());
                    itr = p->rbegin();
                    itr_end = p->rend();

                    if (itr == itr_end)
                    {
                        this->_stack.pop();
                        break;
                    }
                }
                else
                {
                    p = this->_stack.top();
                    itr = p->rbegin();
                    itr_end = p->rend();
                }
            }
        }
    }

    template <typename Node, typename IsReverse, typename StackGen>
    void
        post_order_tree_iterator<Node,IsReverse,StackGen>::_init(
            ::boost::mpl::false_ f,
            ::boost::mpl::false_
        )
    {
        typedef typename ::boost::mpl::if_<
            ::std::is_const<Node>,
            typename ::std::remove_const<Node>::type::traits::child_const_iterator,
            typename ::std::remove_const<Node>::type::traits::child_iterator
        >::type child_iterator;

        typename ::boost::mpl::apply_wrap1<_stack_gen_lambda,child_iterator>::type s;

        this->_init(s, f);
    }

    template <typename Node, typename IsReverse, typename StackGen>
    void
        post_order_tree_iterator<Node,IsReverse,StackGen>::_init(
            ::boost::mpl::false_ f,
            ::boost::mpl::true_
        )
    {
        typedef typename ::boost::mpl::if_<
            ::std::is_const<Node>,
            typename ::std::remove_const<Node>::type::traits::child_const_iterator,
            typename ::std::remove_const<Node>::type::traits::child_iterator
        >::type child_iterator;

        typename ::boost::mpl::apply_wrap1<_stack_gen_lambda,child_iterator>::type s(
            this->_stack.get_allocator()
        );

        this->_init(s, f);
    }

    template <typename Node, typename IsReverse, typename StackGen>
    void
        post_order_tree_iterator<Node,IsReverse,StackGen>::_init(
            ::boost::mpl::true_ t,
            ::boost::mpl::false_
        )
    {
        typedef typename ::boost::mpl::if_<
            ::std::is_const<Node>,
            typename ::std::remove_const<Node>::type::traits::child_const_reverse_iterator,
            typename ::std::remove_const<Node>::type::traits::child_reverse_iterator
        >::type child_iterator;

        typename ::boost::mpl::apply_wrap1<_stack_gen_lambda,child_iterator>::type s;

        this->_init(s, t);
    }

    template <typename Node, typename IsReverse, typename StackGen>
    void
        post_order_tree_iterator<Node,IsReverse,StackGen>::_init(
            ::boost::mpl::true_ t,
            ::boost::mpl::true_
        )
    {
        typedef typename ::boost::mpl::if_<
            ::std::is_const<Node>,
            typename ::std::remove_const<Node>::type::traits::child_const_reverse_iterator,
            typename ::std::remove_const<Node>::type::traits::child_reverse_iterator
        >::type child_iterator;

        typename ::boost::mpl::apply_wrap1<_stack_gen_lambda,child_iterator>::type s(
            this->_stack.get_allocator()
        );

        this->_init(s, t);
    }

    template <
        typename StackGen = ::odds_and_ends::use_default_policy,
        typename Node,
        typename ...Args
    >
    inline post_order_tree_iterator<Node,::boost::mpl::false_,StackGen>
        make_post_order_tree_iterator(Node& node, Args&&... args)
    {
        return post_order_tree_iterator<Node,::boost::mpl::false_,StackGen>(
            node,
            ::std::forward<Args>(args)...
        );
    }

    template <
        typename StackGen = ::odds_and_ends::use_default_policy,
        typename Node,
        typename ...Args
    >
    inline post_order_tree_iterator<Node,::boost::mpl::true_,StackGen>
        make_pre_order_tree_reverse_iterator(Node& node, Args&&... args)
    {
        return post_order_tree_iterator<Node,::boost::mpl::true_,StackGen>(
            node,
            ::std::forward<Args>(args)...
        );
    }
}}  // namespace boost::tree_node

#endif  // ODDS_AND_ENDS__NODE__ITERATOR__POST_ORDER_TREE_HPP

