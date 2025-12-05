// Copyright (C) 2011-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__ITERATOR__BREADTH_FIRST_TREE_HPP
#define ODDS_AND_ENDS__NODE__ITERATOR__BREADTH_FIRST_TREE_HPP

#include <type_traits>
#include <iterator>
#include <odds_and_ends/node/container/queue.hpp>
#include <odds_and_ends/node/traversal_state.hpp>
#include <odds_and_ends/static_introspection/concept/is_stack_or_heap.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_forward_iterator.hpp>
#include <odds_and_ends/static_introspection/member_function/has_get_allocator.hpp>
#include <boost/core/enable_if.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace node {

    template <
        typename Node,
        typename QGen = ::odds_and_ends::node::container::queue< ::boost::mpl::_>
    >
    class breadth_first_tree_iterator
    {
        struct _enabler
        {
        };

    public:
        typedef ::odds_and_ends::node::breadth_first_tree_iterator<Node,QGen> type;
        typedef ::std::forward_iterator_tag iterator_category;
        typedef Node value_type;
        typedef typename ::boost::mpl::if_<
            ::std::is_const<Node>,
            typename ::std::remove_const<Node>::type::traits::const_pointer,
            typename ::std::remove_const<Node>::type::traits::pointer
        >::type pointer;
        typedef value_type& reference;

    private:
        typedef typename ::boost::mpl::apply1<QGen,pointer>::type _queue_t;

        _queue_t _queue;
        pointer _current;
        ::odds_and_ends::node::traversal_state _state;

    public:
        template <typename A0, typename ...Args>
        explicit breadth_first_tree_iterator(
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
        explicit breadth_first_tree_iterator(reference node, Args&&... args);

        template <typename N, typename Q>
        breadth_first_tree_iterator(
            breadth_first_tree_iterator<N,Q> const& other,
            typename ::boost::enable_if<
                typename ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::concept::is_stack_or_heap<_queue_t>,
                    ::boost::mpl::false_,
                    ::boost::mpl::if_<
                        ::std::is_convertible<N,Node>,
                        ::odds_and_ends::static_introspection::member_function::has_get_allocator<
                            typename breadth_first_tree_iterator<N,Q>::_queue_t
                        >,
                        ::boost::mpl::false_
                    >
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename N, typename Q>
        breadth_first_tree_iterator(
            breadth_first_tree_iterator<N,Q> const& other,
            typename ::boost::enable_if<
                typename ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::concept::is_stack_or_heap<_queue_t>,
                    ::boost::mpl::false_,
                    ::boost::mpl::if_<
                        ::odds_and_ends::static_introspection::member_function::has_get_allocator<
                            typename breadth_first_tree_iterator<N,Q>::_queue_t
                        >,
                        ::boost::mpl::false_,
                        ::std::is_convertible<N,Node>
                    >
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename N, typename Q>
        breadth_first_tree_iterator(
            breadth_first_tree_iterator<N,Q> const& other,
            typename ::boost::enable_if<
                typename ::boost::mpl::eval_if<
                    ::std::is_convertible<N,Node>,
                    ::boost::mpl::if_<
                        ::odds_and_ends::static_introspection::concept::is_stack_or_heap<_queue_t>,
                        ::odds_and_ends::static_introspection::member_function::has_get_allocator<
                            typename breadth_first_tree_iterator<N,Q>::_queue_t
                        >,
                        ::boost::mpl::false_
                    >,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename N, typename Q>
        breadth_first_tree_iterator(
            breadth_first_tree_iterator<N,Q> const& other,
            typename ::boost::enable_if<
                typename ::boost::mpl::eval_if<
                    ::std::is_convertible<N,Node>,
                    ::boost::mpl::if_<
                        ::odds_and_ends::static_introspection::member_function::has_get_allocator<
                            typename breadth_first_tree_iterator<N,Q>::_queue_t
                        >,
                        ::boost::mpl::false_,
                        ::odds_and_ends::static_introspection::concept::is_stack_or_heap<_queue_t>
                    >,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename N, typename Q>
        breadth_first_tree_iterator(
            breadth_first_tree_iterator<N,Q>&& other,
            typename ::boost::enable_if<
                typename ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::concept::is_stack_or_heap<_queue_t>,
                    ::boost::mpl::false_,
                    ::boost::mpl::if_<
                        ::std::is_convertible<N,Node>,
                        ::odds_and_ends::static_introspection::member_function::has_get_allocator<
                            typename breadth_first_tree_iterator<N,Q>::_queue_t
                        >,
                        ::boost::mpl::false_
                    >
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename N, typename Q>
        breadth_first_tree_iterator(
            breadth_first_tree_iterator<N,Q>&& other,
            typename ::boost::enable_if<
                typename ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::concept::is_stack_or_heap<_queue_t>,
                    ::boost::mpl::false_,
                    ::boost::mpl::if_<
                        ::odds_and_ends::static_introspection::member_function::has_get_allocator<
                            typename breadth_first_tree_iterator<N,Q>::_queue_t
                        >,
                        ::boost::mpl::false_,
                        ::std::is_convertible<N,Node>
                    >
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename N, typename Q>
        breadth_first_tree_iterator(
            breadth_first_tree_iterator<N,Q>&& other,
            typename ::boost::enable_if<
                typename ::boost::mpl::eval_if<
                    ::std::is_convertible<N,Node>,
                    ::boost::mpl::if_<
                        ::odds_and_ends::static_introspection::concept::is_stack_or_heap<_queue_t>,
                        ::odds_and_ends::static_introspection::member_function::has_get_allocator<
                            typename breadth_first_tree_iterator<N,Q>::_queue_t
                        >,
                        ::boost::mpl::false_
                    >,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename N, typename Q>
        breadth_first_tree_iterator(
            breadth_first_tree_iterator<N,Q>&& other,
            typename ::boost::enable_if<
                typename ::boost::mpl::eval_if<
                    ::std::is_convertible<N,Node>,
                    ::boost::mpl::if_<
                        ::odds_and_ends::static_introspection::member_function::has_get_allocator<
                            typename breadth_first_tree_iterator<N,Q>::_queue_t
                        >,
                        ::boost::mpl::false_,
                        ::odds_and_ends::static_introspection::concept::is_stack_or_heap<_queue_t>
                    >,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        breadth_first_tree_iterator();
        ~breadth_first_tree_iterator();
        breadth_first_tree_iterator& operator=(breadth_first_tree_iterator const& other);
        breadth_first_tree_iterator& operator=(breadth_first_tree_iterator&& other);

        template <typename N, typename Q>
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::concept::is_stack_or_heap<_queue_t>,
                ::boost::mpl::false_,
                ::std::is_convertible<N,Node>
            >::type,
            breadth_first_tree_iterator&
        >::type
            operator=(breadth_first_tree_iterator<N,Q> const& other);

        template <typename N, typename Q>
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::std::is_convertible<N,Node>,
                ::odds_and_ends::static_introspection::concept::is_stack_or_heap<_queue_t>,
                ::boost::mpl::false_
            >::type,
            breadth_first_tree_iterator&
        >::type
            operator=(breadth_first_tree_iterator<N,Q> const& other);

        template <typename N, typename Q>
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::concept::is_stack_or_heap<_queue_t>,
                ::boost::mpl::false_,
                ::std::is_convertible<N,Node>
            >::type,
            breadth_first_tree_iterator&
        >::type
            operator=(breadth_first_tree_iterator<N,Q>&& other);

        template <typename N, typename Q>
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::std::is_convertible<N,Node>,
                ::odds_and_ends::static_introspection::concept::is_stack_or_heap<_queue_t>,
                ::boost::mpl::false_
            >::type,
            breadth_first_tree_iterator&
        >::type
            operator=(breadth_first_tree_iterator<N,Q>&& other);

        operator ::odds_and_ends::node::traversal_state() const;
        reference operator*() const;
        pointer operator->() const;
        breadth_first_tree_iterator& operator++();
        breadth_first_tree_iterator operator++(int);

    private:
        _queue_t const& queue() const;
        _queue_t& queue();
        pointer const& current() const;
        pointer& current();
        void _pop(::boost::mpl::true_);
        void _pop(::boost::mpl::false_);
        void _clear_queue(::boost::mpl::true_);
        void _clear_queue(::boost::mpl::false_);
        void _clone(breadth_first_tree_iterator const& other, ::boost::mpl::true_);
        void _clone(breadth_first_tree_iterator const& other, ::boost::mpl::false_);
        void _move(breadth_first_tree_iterator&& other, ::boost::mpl::true_);
        void _move(breadth_first_tree_iterator&& other, ::boost::mpl::false_);

        template <typename Itr>
        void _push_all(Itr itr_begin, Itr itr_end);

        template <typename OtherQueue>
        static void
            _merge_queue(
                _queue_t& this_queue,
                OtherQueue& other_queue,
                ::boost::mpl::true_
            );

        template <typename OtherQueue>
        static void
            _merge_queue(
                _queue_t& this_queue,
                OtherQueue& other_queue,
                ::boost::mpl::false_
            );

        static void
            _merge_heap(
                _queue_t& this_queue,
                _queue_t& other_queue,
                ::boost::mpl::true_
            );

        template <typename OtherQueue>
        static void
            _merge_heap(
                _queue_t& this_queue,
                OtherQueue& other_queue,
                ::boost::mpl::false_
            );

//        breadth_first_tree_iterator(breadth_first_tree_iterator const&) = delete;
//        breadth_first_tree_iterator(breadth_first_tree_iterator&&) = delete;

        template <typename N, typename Q>
        friend class breadth_first_tree_iterator;

        template <typename N1, typename Q1, typename N2, typename Q2>
        friend bool
            operator==(
                breadth_first_tree_iterator<N1,Q1> const& lhs,
                breadth_first_tree_iterator<N2,Q2> const& rhs
            );

        template <typename N1, typename Q1, typename N2, typename Q2>
        friend bool
            operator!=(
                breadth_first_tree_iterator<N1,Q1> const& lhs,
                breadth_first_tree_iterator<N2,Q2> const& rhs
            );
    };
}}  // namespace odds_and_ends::node

#include <utility>
#include <memory>
#include <odds_and_ends/static_introspection/concept/is_mergeable_heap.hpp>
#include <odds_and_ends/static_introspection/member_function/has_clear.hpp>
#include <boost/heap/heap_merge.hpp>

namespace odds_and_ends { namespace node {

    template <typename Node, typename QGen>
    inline breadth_first_tree_iterator<Node,QGen>::breadth_first_tree_iterator() :
        _queue(), _current(nullptr), _state(::odds_and_ends::node::no_traversal)
    {
    }

    template <typename Node, typename QGen>
    template <typename A0, typename ...Args>
    inline breadth_first_tree_iterator<Node,QGen>::breadth_first_tree_iterator(
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
    ) : _queue(::std::forward<A0>(a0), ::std::forward<Args>(args)...),
        _current(nullptr),
        _state(::odds_and_ends::node::no_traversal)
    {
    }

    template <typename Node, typename QGen>
    template <typename ...Args>
    inline breadth_first_tree_iterator<Node,QGen>::breadth_first_tree_iterator(
        reference node,
        Args&&... args
    ) : _queue(::std::forward<Args>(args)...),
        _current(::std::pointer_traits<pointer>::pointer_to(node)),
        _state(::odds_and_ends::node::breadth_first_traversal)
    {
    }

    template <typename Node, typename QGen>
    template <typename OtherQueue>
    void
        breadth_first_tree_iterator<Node,QGen>::_merge_queue(
            _queue_t& this_queue,
            OtherQueue& other_queue,
            ::boost::mpl::true_
        )
    {
        for (; !other_queue.empty(); other_queue.pop())
        {
            this_queue.push(other_queue.top());
        }
    }

    template <typename Node, typename QGen>
    template <typename OtherQueue>
    void
        breadth_first_tree_iterator<Node,QGen>::_merge_queue(
            _queue_t& this_queue,
            OtherQueue& other_queue,
            ::boost::mpl::false_
        )
    {
        for (; !other_queue.empty(); other_queue.pop())
        {
            this_queue.push(other_queue.front());
        }
    }

    template <typename Node, typename QGen>
    inline void
        breadth_first_tree_iterator<Node,QGen>::_merge_heap(
            _queue_t& this_queue,
            _queue_t& other_queue,
            ::boost::mpl::true_
        )
    {
        this_queue.merge(other_queue);
    }

    template <typename Node, typename QGen>
    template <typename OtherQueue>
    inline void
        breadth_first_tree_iterator<Node,QGen>::_merge_heap(
            _queue_t& this_queue,
            OtherQueue& other_queue,
            ::boost::mpl::false_
        )
    {
        ::boost::heap::heap_merge(this_queue, other_queue);
    }

    template <typename Node, typename QGen>
    template <typename N, typename Q>
    breadth_first_tree_iterator<Node,QGen>::breadth_first_tree_iterator(
        breadth_first_tree_iterator<N,Q> const& other,
        typename ::boost::enable_if<
            typename ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept::is_stack_or_heap<_queue_t>,
                ::boost::mpl::false_,
                ::boost::mpl::if_<
                    ::std::is_convertible<N,Node>,
                    ::odds_and_ends::static_introspection::member_function::has_get_allocator<
                        typename breadth_first_tree_iterator<N,Q>::_queue_t
                    >,
                    ::boost::mpl::false_
                >
            >::type,
            _enabler
        >::type
    ) : _queue(other.queue().get_allocator()),
        _current(other.current()),
        _state(::odds_and_ends::node::traversal_state(other))
    {
        typedef typename breadth_first_tree_iterator<N,Q>::_queue_t other_queue_t;
        other_queue_t other_queue(other.queue());

        type::_merge_queue(
            this->_queue,
            other_queue,
            ::odds_and_ends::static_introspection::concept::is_stack_or_heap<other_queue_t>()
        );
    }

    template <typename Node, typename QGen>
    template <typename N, typename Q>
    breadth_first_tree_iterator<Node,QGen>::breadth_first_tree_iterator(
        breadth_first_tree_iterator<N,Q> const& other,
        typename ::boost::enable_if<
            typename ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept::is_stack_or_heap<_queue_t>,
                ::boost::mpl::false_,
                ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection::member_function::has_get_allocator<
                        typename breadth_first_tree_iterator<N,Q>::_queue_t
                    >,
                    ::boost::mpl::false_,
                    ::std::is_convertible<N,Node>
                >
            >::type,
            _enabler
        >::type
    ) : _queue(), _current(other.current()), _state(::odds_and_ends::node::traversal_state(other))
    {
        typedef typename breadth_first_tree_iterator<N,Q>::_queue_t other_queue_t;
        other_queue_t other_queue(other.queue());

        type::_merge_queue(
            this->_queue,
            other_queue,
            ::odds_and_ends::static_introspection::concept::is_stack_or_heap<other_queue_t>()
        );
    }

    template <typename Node, typename QGen>
    template <typename N, typename Q>
    breadth_first_tree_iterator<Node,QGen>::breadth_first_tree_iterator(
        breadth_first_tree_iterator<N,Q> const& other,
        typename ::boost::enable_if<
            typename ::boost::mpl::eval_if<
                ::std::is_convertible<N,Node>,
                ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection::concept::is_stack_or_heap<_queue_t>,
                    ::odds_and_ends::static_introspection::member_function::has_get_allocator<
                        typename breadth_first_tree_iterator<N,Q>::_queue_t
                    >,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _queue(other.queue().get_allocator()),
        _current(other.current()),
        _state(::odds_and_ends::node::traversal_state(other))
    {
        typedef typename breadth_first_tree_iterator<N,Q>::_queue_t other_queue_t;
        other_queue_t other_queue(other.queue());

        type::_merge_heap(
            this->_queue,
            other_queue,
            typename ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept::is_mergeable_heap<_queue_t>,
                ::boost::mpl::if_<
                    ::std::is_same<_queue_t,other_queue_t>,
                    ::boost::mpl::true_,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >::type()
        );
    }

    template <typename Node, typename QGen>
    template <typename N, typename Q>
    breadth_first_tree_iterator<Node,QGen>::breadth_first_tree_iterator(
        breadth_first_tree_iterator<N,Q> const& other,
        typename ::boost::enable_if<
            typename ::boost::mpl::eval_if<
                ::std::is_convertible<N,Node>,
                ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection::member_function::has_get_allocator<
                        typename breadth_first_tree_iterator<N,Q>::_queue_t
                    >,
                    ::boost::mpl::false_,
                    ::odds_and_ends::static_introspection::concept::is_stack_or_heap<_queue_t>
                >,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _queue(), _current(other.current()), _state(::odds_and_ends::node::traversal_state(other))
    {
        typedef typename breadth_first_tree_iterator<N,Q>::_queue_t other_queue_t;
        other_queue_t other_queue(other.queue());

        type::_merge_heap(
            this->_queue,
            other_queue,
            typename ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept::is_mergeable_heap<_queue_t>,
                ::boost::mpl::if_<
                    ::std::is_same<_queue_t,other_queue_t>,
                    ::boost::mpl::true_,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >::type()
        );
    }

    template <typename Node, typename QGen>
    template <typename N, typename Q>
    inline breadth_first_tree_iterator<Node,QGen>::breadth_first_tree_iterator(
        breadth_first_tree_iterator<N,Q>&& other,
        typename ::boost::enable_if<
            typename ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept::is_stack_or_heap<_queue_t>,
                ::boost::mpl::false_,
                ::boost::mpl::if_<
                    ::std::is_convertible<N,Node>,
                    ::odds_and_ends::static_introspection::member_function::has_get_allocator<
                        typename breadth_first_tree_iterator<N,Q>::_queue_t
                    >,
                    ::boost::mpl::false_
                >
            >::type,
            _enabler
        >::type
    ) : _queue(other.queue().get_allocator()),
        _current(::std::move(other.current())),
        _state(::odds_and_ends::node::traversal_state(other))
    {
        type::_merge_queue(
            this->_queue,
            other.queue(),
            ::odds_and_ends::static_introspection::concept::is_stack_or_heap<
                typename breadth_first_tree_iterator<N,Q>::_queue_t
            >()
        );
    }

    template <typename Node, typename QGen>
    template <typename N, typename Q>
    inline breadth_first_tree_iterator<Node,QGen>::breadth_first_tree_iterator(
        breadth_first_tree_iterator<N,Q>&& other,
        typename ::boost::enable_if<
            typename ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept::is_stack_or_heap<_queue_t>,
                ::boost::mpl::false_,
                ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection::member_function::has_get_allocator<
                        typename breadth_first_tree_iterator<N,Q>::_queue_t
                    >,
                    ::boost::mpl::false_,
                    ::std::is_convertible<N,Node>
                >
            >::type,
            _enabler
        >::type
    ) : _queue(),
        _current(::std::move(other.current())),
        _state(::odds_and_ends::node::traversal_state(other))
    {
        type::_merge_queue(
            this->_queue,
            other.queue(),
            ::odds_and_ends::static_introspection::concept::is_stack_or_heap<
                typename breadth_first_tree_iterator<N,Q>::_queue_t
            >()
        );
    }

    template <typename Node, typename QGen>
    template <typename N, typename Q>
    inline breadth_first_tree_iterator<Node,QGen>::breadth_first_tree_iterator(
        breadth_first_tree_iterator<N,Q>&& other,
        typename ::boost::enable_if<
            typename ::boost::mpl::eval_if<
                ::std::is_convertible<N,Node>,
                ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection::concept::is_stack_or_heap<_queue_t>,
                    ::odds_and_ends::static_introspection::member_function::has_get_allocator<
                        typename breadth_first_tree_iterator<N,Q>::_queue_t
                    >,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _queue(other.queue().get_allocator()),
        _current(::std::move(other.current())),
        _state(::odds_and_ends::node::traversal_state(other))
    {
        type::_merge_heap(
            this->_queue,
            other.queue(),
            typename ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept::is_mergeable_heap<_queue_t>,
                ::boost::mpl::if_<
                    ::std::is_same<_queue_t,typename breadth_first_tree_iterator<N,Q>::_queue_t>,
                    ::boost::mpl::true_,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >::type()
        );
    }

    template <typename Node, typename QGen>
    template <typename N, typename Q>
    inline breadth_first_tree_iterator<Node,QGen>::breadth_first_tree_iterator(
        breadth_first_tree_iterator<N,Q>&& other,
        typename ::boost::enable_if<
            typename ::boost::mpl::eval_if<
                ::std::is_convertible<N,Node>,
                ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection::member_function::has_get_allocator<
                        typename breadth_first_tree_iterator<N,Q>::_queue_t
                    >,
                    ::boost::mpl::false_,
                    ::odds_and_ends::static_introspection::concept::is_stack_or_heap<_queue_t>
                >,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _queue(),
        _current(::std::move(other.current())),
        _state(::odds_and_ends::node::traversal_state(other))
    {
        type::_merge_heap(
            this->_queue,
            other.queue(),
            typename ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept::is_mergeable_heap<_queue_t>,
                ::boost::mpl::if_<
                    ::std::is_same<_queue_t,typename breadth_first_tree_iterator<N,Q>::_queue_t>,
                    ::boost::mpl::true_,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >::type()
        );
    }

    template <typename Node, typename QGen>
    inline breadth_first_tree_iterator<Node,QGen>::~breadth_first_tree_iterator()
    {
    }

    template <typename Node, typename QGen>
    inline void breadth_first_tree_iterator<Node,QGen>::_clear_queue(::boost::mpl::true_)
    {
        this->_queue.clear();
    }

    template <typename Node, typename QGen>
    inline void breadth_first_tree_iterator<Node,QGen>::_clear_queue(::boost::mpl::false_)
    {
        for (; !this->_queue.empty(); )
        {
            this->_queue.pop();
        }
    }

    template <typename Node, typename QGen>
    void
        breadth_first_tree_iterator<Node,QGen>::_clone(
            breadth_first_tree_iterator const& other,
            ::boost::mpl::true_
        )
    {
        _queue_t other_queue(other.queue());

        type::_merge_heap(
            this->_queue,
            other_queue,
            ::odds_and_ends::static_introspection::concept::is_mergeable_heap<_queue_t>()
        );
    }

    template <typename Node, typename QGen>
    void
        breadth_first_tree_iterator<Node,QGen>::_clone(
            breadth_first_tree_iterator const& other,
            ::boost::mpl::false_ f
        )
    {
        _queue_t other_queue(other.queue());

        type::_merge_queue(this->_queue, other_queue, f);
    }

    template <typename Node, typename QGen>
    inline breadth_first_tree_iterator<Node,QGen>&
        breadth_first_tree_iterator<Node,QGen>::operator=(breadth_first_tree_iterator const& other)
    {
        if (this != &other)
        {
            this->_clear_queue(
                ::odds_and_ends::static_introspection::member_function::has_clear<_queue_t>()
            );
            this->_current = other.current();
            this->_state = ::odds_and_ends::node::traversal_state(other);
            this->_clone(
                other,
                ::odds_and_ends::static_introspection::concept::is_stack_or_heap<_queue_t>()
            );
        }

        return *this;
    }

    template <typename Node, typename QGen>
    inline void
        breadth_first_tree_iterator<Node,QGen>::_move(
            breadth_first_tree_iterator&& other,
            ::boost::mpl::true_
        )
    {
        type::_merge_heap(
            this->_queue,
            other.queue(),
            ::odds_and_ends::static_introspection::concept::is_mergeable_heap<_queue_t>()
        );
    }

    template <typename Node, typename QGen>
    inline void
        breadth_first_tree_iterator<Node,QGen>::_move(
            breadth_first_tree_iterator&& other,
            ::boost::mpl::false_ f
        )
    {
        type::_merge_queue(this->_queue, other.queue(), f);
    }

    template <typename Node, typename QGen>
    inline breadth_first_tree_iterator<Node,QGen>&
        breadth_first_tree_iterator<Node,QGen>::operator=(breadth_first_tree_iterator&& other)
    {
        if (this != &static_cast<breadth_first_tree_iterator&>(other))
        {
            this->_clear_queue(
                ::odds_and_ends::static_introspection::member_function::has_clear<_queue_t>()
            );
            this->_current = other.current();
            this->_state = ::odds_and_ends::node::traversal_state(other);
            this->_move(
                static_cast<breadth_first_tree_iterator&&>(other),
                ::odds_and_ends::static_introspection::concept::is_stack_or_heap<_queue_t>()
            );
        }

        return *this;
    }

    template <typename Node, typename QGen>
    template <typename N, typename Q>
    typename ::boost::enable_if<
        typename ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::concept::is_stack_or_heap<
                typename breadth_first_tree_iterator<Node,QGen>::_queue_t
            >,
            ::boost::mpl::false_,
            ::std::is_convertible<N,Node>
        >::type,
        breadth_first_tree_iterator<Node,QGen>&
    >::type
        breadth_first_tree_iterator<Node,QGen>::operator=(
            breadth_first_tree_iterator<N,Q> const& other
        )
    {
        if (this != &other)
        {
            this->_clear_queue(
                ::odds_and_ends::static_introspection::member_function::has_clear<_queue_t>()
            );
            this->_current = other.current();
            this->_state = ::odds_and_ends::node::traversal_state(other);

            typedef typename breadth_first_tree_iterator<N,Q>::_queue_t other_queue_t;
            other_queue_t other_queue(other.queue());

            type::_merge_queue(
                this->_queue,
                other_queue,
                ::odds_and_ends::static_introspection::concept::is_stack_or_heap<other_queue_t>()
            );
        }

        return *this;
    }

    template <typename Node, typename QGen>
    template <typename N, typename Q>
    typename ::boost::enable_if<
        typename ::boost::mpl::if_<
            ::std::is_convertible<N,Node>,
            ::odds_and_ends::static_introspection::concept::is_stack_or_heap<
                typename breadth_first_tree_iterator<Node,QGen>::_queue_t
            >,
            ::boost::mpl::false_
        >::type,
        breadth_first_tree_iterator<Node,QGen>&
    >::type
        breadth_first_tree_iterator<Node,QGen>::operator=(
            breadth_first_tree_iterator<N,Q> const& other
        )
    {
        if (this != &other)
        {
            this->_clear_queue(
                ::odds_and_ends::static_introspection::member_function::has_clear<_queue_t>()
            );
            this->_current = other.current();
            this->_state = ::odds_and_ends::node::traversal_state(other);

            typedef typename breadth_first_tree_iterator<N,Q>::_queue_t other_queue_t;
            other_queue_t other_queue(other.queue());

            type::_merge_heap(
                this->_queue,
                other_queue,
                typename ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::concept::is_mergeable_heap<_queue_t>,
                    ::boost::mpl::if_<
                        ::std::is_same<_queue_t,other_queue_t>,
                        ::boost::mpl::true_,
                        ::boost::mpl::false_
                    >,
                    ::boost::mpl::false_
                >::type()
            );
        }

        return *this;
    }

    template <typename Node, typename QGen>
    template <typename N, typename Q>
    inline typename ::boost::enable_if<
        typename ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::concept::is_stack_or_heap<
                typename breadth_first_tree_iterator<Node,QGen>::_queue_t
            >,
            ::boost::mpl::false_,
            ::std::is_convertible<N,Node>
        >::type,
        breadth_first_tree_iterator<Node,QGen>&
    >::type
        breadth_first_tree_iterator<Node,QGen>::operator=(
            breadth_first_tree_iterator<N,Q>&& other
        )
    {
        if (this != &static_cast<breadth_first_tree_iterator<N,Q>&>(other))
        {
            this->_clear_queue(
                ::odds_and_ends::static_introspection::member_function::has_clear<_queue_t>()
            );
            this->_current = other.current();
            this->_state = ::odds_and_ends::node::traversal_state(other);
            type::_merge_queue(
                this->_queue,
                other.queue(),
                ::odds_and_ends::static_introspection::concept::is_stack_or_heap<
                    typename breadth_first_tree_iterator<N,Q>::_queue_t
                >()
            );
        }

        return *this;
    }

    template <typename Node, typename QGen>
    template <typename N, typename Q>
    inline typename ::boost::enable_if<
        typename ::boost::mpl::if_<
            ::std::is_convertible<N,Node>,
            ::odds_and_ends::static_introspection::concept::is_stack_or_heap<
                typename breadth_first_tree_iterator<Node,QGen>::_queue_t
            >,
            ::boost::mpl::false_
        >::type,
        breadth_first_tree_iterator<Node,QGen>&
    >::type
        breadth_first_tree_iterator<Node,QGen>::operator=(
            breadth_first_tree_iterator<N,Q>&& other
        )
    {
        if (this != &static_cast<breadth_first_tree_iterator<N,Q>&>(other))
        {
            this->_clear_queue(
                ::odds_and_ends::static_introspection::member_function::has_clear<_queue_t>()
            );
            this->_current = other.current();
            this->_state = ::odds_and_ends::node::traversal_state(other);
            type::_merge_heap(
                this->_queue,
                other.queue(),
                typename ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::concept::is_mergeable_heap<_queue_t>,
                    ::boost::mpl::if_<
                        ::std::is_same<
                            _queue_t,
                            typename breadth_first_tree_iterator<N,Q>::_queue_t
                        >,
                        ::boost::mpl::true_,
                        ::boost::mpl::false_
                    >,
                    ::boost::mpl::false_
                >::type()
            );
        }

        return *this;
    }

    template <typename Node, typename QGen>
    inline breadth_first_tree_iterator<Node,QGen>::operator
        ::odds_and_ends::node::traversal_state() const
    {
        return this->_state;
    }

    template <typename Node, typename QGen>
    inline typename breadth_first_tree_iterator<Node,QGen>::reference
        breadth_first_tree_iterator<Node,QGen>::operator*() const
    {
        return *this->_current;
    }

    template <typename Node, typename QGen>
    inline typename breadth_first_tree_iterator<Node,QGen>::pointer
        breadth_first_tree_iterator<Node,QGen>::operator->() const
    {
        return this->_current;
    }

    template <typename Node, typename QGen>
    inline typename breadth_first_tree_iterator<Node,QGen>::pointer const&
        breadth_first_tree_iterator<Node,QGen>::current() const
    {
        return this->_current;
    }

    template <typename Node, typename QGen>
    inline typename breadth_first_tree_iterator<Node,QGen>::pointer&
        breadth_first_tree_iterator<Node,QGen>::current()
    {
        return this->_current;
    }

    template <typename Node, typename QGen>
    inline typename breadth_first_tree_iterator<Node,QGen>::_queue_t const&
        breadth_first_tree_iterator<Node,QGen>::queue() const
    {
        return this->_queue;
    }

    template <typename Node, typename QGen>
    inline typename breadth_first_tree_iterator<Node,QGen>::_queue_t&
        breadth_first_tree_iterator<Node,QGen>::queue()
    {
        return this->_queue;
    }

    template <typename Node, typename QGen>
    template <typename Itr>
    void breadth_first_tree_iterator<Node,QGen>::_push_all(Itr itr, Itr itr_end)
    {
        for (; itr != itr_end; ++itr)
        {
            this->_queue.push(::std::pointer_traits<pointer>::pointer_to(*itr));
        }
    }

    template <typename Node, typename QGen>
    inline void breadth_first_tree_iterator<Node,QGen>::_pop(::boost::mpl::true_)
    {
        if (this->_queue.empty())
        {
            this->_current = nullptr;
            this->_state = ::odds_and_ends::node::no_traversal;
        }
        else
        {
            this->_current = this->_queue.top();
            this->_queue.pop();
        }
    }

    template <typename Node, typename QGen>
    inline void breadth_first_tree_iterator<Node,QGen>::_pop(::boost::mpl::false_)
    {
        if (this->_queue.empty())
        {
            this->_current = nullptr;
            this->_state = ::odds_and_ends::node::no_traversal;
        }
        else
        {
            this->_current = this->_queue.front();
            this->_queue.pop();
        }
    }

    template <typename Node, typename QGen>
    inline breadth_first_tree_iterator<Node,QGen>&
        breadth_first_tree_iterator<Node,QGen>::operator++()
    {
        BOOST_ASSERT_MSG(this->_state, "Do not increment past-the-end!");
        this->_push_all(this->_current->begin(), this->_current->end());
        this->_pop(::odds_and_ends::static_introspection::concept::is_stack_or_heap<_queue_t>());
        return *this;
    }

    template <typename Node, typename QGen>
    inline breadth_first_tree_iterator<Node,QGen>
        breadth_first_tree_iterator<Node,QGen>::operator++(int)
    {
        breadth_first_tree_iterator itr(*this);
        ++(*this);
        return itr;
    }

    template <typename N1, typename Q1, typename N2, typename Q2>
    inline bool
        operator==(
            breadth_first_tree_iterator<N1,Q1> const& lhs,
            breadth_first_tree_iterator<N2,Q2> const& rhs
        )
    {
        return (lhs._state == rhs._state) && (lhs._current == rhs._current);
    }

    template <typename N1, typename Q1, typename N2, typename Q2>
    inline bool
        operator!=(
            breadth_first_tree_iterator<N1,Q1> const& lhs,
            breadth_first_tree_iterator<N2,Q2> const& rhs
        )
    {
        return (lhs._state != rhs._state) || (lhs._current != rhs._current);
    }

    template <
        typename QGen = ::odds_and_ends::node::container::queue< ::boost::mpl::_>,
        typename Node,
        typename ...Args
    >
    inline breadth_first_tree_iterator<Node,QGen>
        make_breadth_first_tree_iterator(Node& node, Args&&... args)
    {
        return breadth_first_tree_iterator<Node,QGen>(node, ::std::forward<Args>(args)...);
    }
}}  // namespace odds_and_ends::node

#endif  // ODDS_AND_ENDS__NODE__ITERATOR__BREADTH_FIRST_TREE_HPP

