// Copyright (C) 2011-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__ITERATOR__IN_ORDER_TREE_HPP
#define ODDS_AND_ENDS__NODE__ITERATOR__IN_ORDER_TREE_HPP

#include <type_traits>
#include <iterator>
#include <odds_and_ends/node/traversal_state.hpp>
#include <boost/core/enable_if.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/equal_to.hpp>

namespace odds_and_ends { namespace node {

    template <
        typename Node,
        typename IsReverse = ::boost::mpl::false_,
        typename Difference = ::std::ptrdiff_t
    >
    class in_order_tree_iterator
    {
        struct _enabler
        {
        };

    public:
        typedef ::std::bidirectional_iterator_tag iterator_category;
        typedef Node value_type;
        typedef Difference difference_type;
        typedef typename ::boost::mpl::if_<
            ::std::is_const<Node>,
            typename ::std::remove_const<Node>::type::traits::const_pointer,
            typename ::std::remove_const<Node>::type::traits::pointer
        >::type pointer;
        typedef Node& reference;

    private:
        class _proxy
        {
            in_order_tree_iterator _itr;

        public:
            _proxy(pointer const& p, difference_type const& n);

            operator in_order_tree_iterator&();
        };

        pointer _root;
        pointer _current;
        ::odds_and_ends::node::traversal_state _state;

    public:
        in_order_tree_iterator();
        in_order_tree_iterator(reference node);
        in_order_tree_iterator(reference node, bool is_end);

        template <typename N, typename I, typename D>
        in_order_tree_iterator(
            in_order_tree_iterator<N,I,D> const& other,
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

        template <typename N, typename I, typename D>
        in_order_tree_iterator(
            in_order_tree_iterator<N,I,D>&& other,
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

        in_order_tree_iterator(in_order_tree_iterator const& other);
        in_order_tree_iterator(in_order_tree_iterator&& other);
        ~in_order_tree_iterator();
        in_order_tree_iterator& operator=(in_order_tree_iterator const& other);
        in_order_tree_iterator& operator=(in_order_tree_iterator&& other);
        operator ::odds_and_ends::node::traversal_state() const;
        bool operator!() const;
        reference operator*() const;
        pointer operator->() const;
        _proxy operator[](difference_type const& n) const;
        in_order_tree_iterator& operator++();
        in_order_tree_iterator operator++(int);
        in_order_tree_iterator& operator--();
        in_order_tree_iterator operator--(int);
        in_order_tree_iterator& operator+=(difference_type const& n);
        in_order_tree_iterator& operator-=(difference_type const& n);

    private:
        void _initialize(::boost::mpl::false_);
        void _initialize(::boost::mpl::true_);
        void _increment(::boost::mpl::false_);
        void _increment(::boost::mpl::true_);
        void _advance(difference_type n);

        template <typename N, typename I, typename D>
        friend class in_order_tree_iterator;

        template <typename N1, typename I1, typename D1, typename N2, typename I2, typename D2>
        friend typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
            operator==(
                in_order_tree_iterator<N1,I1,D1> const& lhs,
                in_order_tree_iterator<N2,I2,D2> const& rhs
            );

        template <typename N1, typename I1, typename D1, typename N2, typename I2, typename D2>
        friend typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
            operator<(
                in_order_tree_iterator<N1,I1,D1> const& lhs,
                in_order_tree_iterator<N2,I2,D2> const& rhs
            );

        template <typename N1, typename I1, typename D1, typename N2, typename I2, typename D2>
        friend typename ::std::common_type<D1,D2>::type
            operator-(
                in_order_tree_iterator<N1,I1,D1> const& lhs,
                in_order_tree_iterator<N2,I2,D2> const& rhs
            );
    };
}}  // namespace odds_and_ends::node

#include <utility>
#include <memory>
#include <odds_and_ends/node/algorithm/is_ancestor_of.hpp>
#include <odds_and_ends/node/algorithm/increment_in_binary_tree.hpp>
#include <odds_and_ends/node/algorithm/advance_in_binary_tree.hpp>
#include <odds_and_ends/node/algorithm/binary_tree_index_of.hpp>
#include <boost/mpl/not.hpp>
#include <boost/utility/value_init.hpp>
#include <boost/assert.hpp>

namespace odds_and_ends { namespace node {

    template <typename Node, typename IsReverse, typename Difference>
    in_order_tree_iterator<Node,IsReverse,Difference>::_proxy::_proxy(
        pointer const& p,
        difference_type const& n
    ) : _itr(p, true)
    {
        this->_itr._advance(n);
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline in_order_tree_iterator<Node,IsReverse,Difference>::_proxy::operator
        in_order_tree_iterator&()
    {
        return this->_itr;
    }

    template <typename Node, typename IsReverse, typename Difference>
    in_order_tree_iterator<Node,IsReverse,Difference>::in_order_tree_iterator() :
        _root(nullptr), _current(nullptr), _state(::odds_and_ends::node::no_traversal)
    {
    }

    template <typename Node, typename IsReverse, typename Difference>
    in_order_tree_iterator<Node,IsReverse,Difference>::in_order_tree_iterator(
        reference node
    ) : _root(::std::pointer_traits<pointer>::pointer_to(node)),
        _current(::std::pointer_traits<pointer>::pointer_to(node)),
        _state(::odds_and_ends::node::in_order_traversal)
    {
        for (; this->_root->parent(); this->_root = this->_root->parent())
        {
        }
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline in_order_tree_iterator<Node,IsReverse,Difference>::in_order_tree_iterator(
        reference node,
        bool is_end
    ) : _root(::std::pointer_traits<pointer>::pointer_to(node)),
        _current(is_end ? nullptr : ::std::pointer_traits<pointer>::pointer_to(node)),
        _state(
            is_end ?
            ::odds_and_ends::node::no_traversal :
            ::odds_and_ends::node::in_order_traversal
        )
    {
        if (this->_current)
        {
            this->_initialize(IsReverse());
        }
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline in_order_tree_iterator<Node,IsReverse,Difference>::in_order_tree_iterator(
        in_order_tree_iterator const& other
    ) : _root(other._root), _current(other._current), _state(other._state)
    {
    }

    template <typename Node, typename IsReverse, typename Difference>
    template <typename N, typename I, typename D>
    inline in_order_tree_iterator<Node,IsReverse,Difference>::in_order_tree_iterator(
        in_order_tree_iterator<N,I,D> const& other,
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
    ) : _root(other._root), _current(other._current), _state(other._state)
    {
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline in_order_tree_iterator<Node,IsReverse,Difference>::in_order_tree_iterator(
        in_order_tree_iterator&& other
    ) : _root(::std::move(other._root)),
        _current(::std::move(other._current)),
        _state(other._state)
    {
    }

    template <typename Node, typename IsReverse, typename Difference>
    template <typename N, typename I, typename D>
    inline in_order_tree_iterator<Node,IsReverse,Difference>::in_order_tree_iterator(
        in_order_tree_iterator<N,I,D>&& other,
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
    ) : _root(::std::move(other._root)),
        _current(::std::move(other._current)),
        _state(other._state)
    {
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline in_order_tree_iterator<Node,IsReverse,Difference>::~in_order_tree_iterator()
    {
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline in_order_tree_iterator<Node,IsReverse,Difference>&
        in_order_tree_iterator<Node,IsReverse,Difference>::operator=(
            in_order_tree_iterator const& other
        )
    {
        if (this != &other)
        {
            this->_root = other._root;
            this->_current = other._current;
            this->_state = other._state;
        }

        return *this;
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline in_order_tree_iterator<Node,IsReverse,Difference>&
        in_order_tree_iterator<Node,IsReverse,Difference>::operator=(
            in_order_tree_iterator&& other
        )
    {
        if (this != &static_cast<in_order_tree_iterator&>(other))
        {
            this->_root = ::std::move(other._root);
            this->_current = ::std::move(other._current);
            this->_state = other._state;
        }

        return *this;
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline in_order_tree_iterator<Node,IsReverse,Difference>::operator
        ::odds_and_ends::node::traversal_state() const
    {
        return this->_state;
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline bool in_order_tree_iterator<Node,IsReverse,Difference>::operator!() const
    {
        return !this->_state.get();
    }

    template <typename Node, typename IsReverse, typename Difference>
    void in_order_tree_iterator<Node,IsReverse,Difference>::_initialize(::boost::mpl::false_)
    {
        this->_current = ::odds_and_ends::node::algorithm::increment_in_binary_tree(
            static_cast<pointer>(nullptr),
            this->_root
        );
    }

    template <typename Node, typename IsReverse, typename Difference>
    void in_order_tree_iterator<Node,IsReverse,Difference>::_initialize(::boost::mpl::true_)
    {
        this->_current = ::odds_and_ends::node::algorithm::decrement_in_binary_tree(
            static_cast<pointer>(nullptr),
            this->_root
        );
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline typename in_order_tree_iterator<Node,IsReverse,Difference>::reference
        in_order_tree_iterator<Node,IsReverse,Difference>::operator*() const
    {
        return *this->_current;
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline typename in_order_tree_iterator<Node,IsReverse,Difference>::pointer
        in_order_tree_iterator<Node,IsReverse,Difference>::operator->() const
    {
        return this->_current;
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline typename in_order_tree_iterator<Node,IsReverse,Difference>::_proxy
        in_order_tree_iterator<Node,IsReverse,Difference>::operator[](
            difference_type const& n
        ) const
    {
        return _proxy(this->_current, n);
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline void
        in_order_tree_iterator<Node,IsReverse,Difference>::_increment(::boost::mpl::false_ tag)
    {
        if (this->_current)
        {
            this->_current = ::odds_and_ends::node::algorithm::increment_in_binary_tree(
                this->_current,
                this->_root
            );

            if (!this->_current)
            {
                this->_state = ::odds_and_ends::node::no_traversal;
            }
        }
        else  // if (!this->_current)
        {
            this->_current = this->_root;
            this->_state = ::odds_and_ends::node::in_order_traversal;
            this->_initialize(tag);
        }
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline void
        in_order_tree_iterator<Node,IsReverse,Difference>::_increment(::boost::mpl::true_ tag)
    {
        if (this->_current)
        {
            this->_current = ::odds_and_ends::node::algorithm::decrement_in_binary_tree(
                this->_current,
                this->_root
            );

            if (!this->_current)
            {
                this->_state = ::odds_and_ends::node::no_traversal;
            }
        }
        else  // if (!this->_current)
        {
            this->_current = this->_root;
            this->_state = ::odds_and_ends::node::in_order_traversal;
            this->_initialize(tag);
        }
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline in_order_tree_iterator<Node,IsReverse,Difference>&
        in_order_tree_iterator<Node,IsReverse,Difference>::operator++()
    {
        BOOST_ASSERT_MSG(this->_state.get(), "Do not increment past-the-end!");
        this->_increment(IsReverse());
        return *this;
    }

    template <typename Node, typename IsReverse, typename Difference>
    in_order_tree_iterator<Node,IsReverse,Difference>
        in_order_tree_iterator<Node,IsReverse,Difference>::operator++(int)
    {
        in_order_tree_iterator itr(*this);
        ++(*this);
        return itr;
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline in_order_tree_iterator<Node,IsReverse,Difference>&
        in_order_tree_iterator<Node,IsReverse,Difference>::operator--()
    {
        this->_increment(::boost::mpl::not_<IsReverse>());
        return *this;
    }

    template <typename Node, typename IsReverse, typename Difference>
    in_order_tree_iterator<Node,IsReverse,Difference>
        in_order_tree_iterator<Node,IsReverse,Difference>::operator--(int)
    {
        in_order_tree_iterator itr(*this);
        --(*this);
        return itr;
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline void in_order_tree_iterator<Node,IsReverse,Difference>::_advance(difference_type n)
    {
        if (!n)
        {
            return;
        }

        static difference_type const z = ::boost::initialized_value;

        if (n < z)
        {
            if (this->_state.get())
            {
                BOOST_ASSERT_MSG(
                    IsReverse::value ? !(
                        this->_root->size() <
                        ::odds_and_ends::node::algorithm::binary_tree_index_of(
                            this->_current,
                            -n,
                            this->_root,
                            false
                        )
                    ) : !(
                        ::odds_and_ends::node::algorithm::binary_tree_index_of(
                            this->_current,
                            n,
                            this->_root,
                            false
                        ) < z
                    ),
                    "Index out of bounds."
                );
            }
            else
            {
                this->_increment(::boost::mpl::not_<IsReverse>());

                if (!++n)
                {
                    return;
                }
            }
        }

        if (
            !(
                this->_current = ::odds_and_ends::node::algorithm::advance_in_binary_tree(
                    this->_current,
                    IsReverse::value ? -n : n,
                    this->_root
                )
            )
        )
        {
            this->_state = ::odds_and_ends::node::no_traversal;
        }
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline in_order_tree_iterator<Node,IsReverse,Difference>&
        in_order_tree_iterator<Node,IsReverse,Difference>::operator+=(difference_type const& n)
    {
        this->_advance(n);
        return *this;
    }

    template <typename Node, typename IsReverse, typename Difference>
    in_order_tree_iterator<Node,IsReverse,Difference>
        operator+(
            in_order_tree_iterator<Node,IsReverse,Difference> const& operand,
            typename in_order_tree_iterator<Node,IsReverse,Difference>::difference_type const& n
        )
    {
        in_order_tree_iterator<Node,IsReverse,Difference> itr(operand);
        itr += n;
        return itr;
    }

    template <typename Node, typename IsReverse, typename Difference>
    in_order_tree_iterator<Node,IsReverse,Difference>
        operator+(
            typename in_order_tree_iterator<Node,IsReverse,Difference>::difference_type const& n,
            in_order_tree_iterator<Node,IsReverse,Difference> const& operand
        )
    {
        in_order_tree_iterator<Node,IsReverse,Difference> itr(operand);
        itr += n;
        return itr;
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline in_order_tree_iterator<Node,IsReverse,Difference>&
        in_order_tree_iterator<Node,IsReverse,Difference>::operator-=(difference_type const& n)
    {
        this->_advance(-n);
        return *this;
    }

    template <typename Node, typename IsReverse, typename Difference>
    in_order_tree_iterator<Node,IsReverse,Difference>
        operator-(
            in_order_tree_iterator<Node,IsReverse,Difference> const& operand,
            typename in_order_tree_iterator<Node,IsReverse,Difference>::difference_type const& n
        )
    {
        in_order_tree_iterator<Node,IsReverse,Difference> itr(operand);
        itr -= n;
        return itr;
    }

    template <typename N1, typename I1, typename D1, typename N2, typename I2, typename D2>
    inline typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
        operator==(
            in_order_tree_iterator<N1,I1,D1> const& lhs,
            in_order_tree_iterator<N2,I2,D2> const& rhs
        )
    {
        return (lhs._state.get() == rhs._state.get()) && (lhs._current == rhs._current);
    }

    template <typename N1, typename I1, typename D1, typename N2, typename I2, typename D2>
    inline typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
        operator!=(
            in_order_tree_iterator<N1,I1,D1> const& lhs,
            in_order_tree_iterator<N2,I2,D2> const& rhs
        )
    {
        return !(lhs == rhs);
    }

    template <typename N1, typename I1, typename D1, typename N2, typename I2, typename D2>
    inline typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
        operator<(
            in_order_tree_iterator<N1,I1,D1> const& lhs,
            in_order_tree_iterator<N2,I2,D2> const& rhs
        )
    {
        BOOST_ASSERT_MSG(lhs._root == rhs._root, "Iterators are unreachable from each other.");

        static typename ::std::common_type<D1,D2>::type const zero_d = ::boost::initialized_value;

        if (lhs._state.get() && rhs._state.get())
        {
            return (
                ::odds_and_ends::node::algorithm
                ::binary_tree_index_of(lhs._current, zero_d, lhs._root, I1::value) <
                ::odds_and_ends::node::algorithm
                ::binary_tree_index_of(rhs._current, zero_d, rhs._root, I2::value)
            );
        }
        else
        {
            return I1::value ? (
                rhs._state.get() && !lhs._state.get()
            ) : (lhs._state.get() && !rhs._state.get());
        }
    }

    template <typename N1, typename I1, typename D1, typename N2, typename I2, typename D2>
    inline typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
        operator>(
            in_order_tree_iterator<N1,I1,D1> const& lhs,
            in_order_tree_iterator<N2,I2,D2> const& rhs
        )
    {
        return rhs < lhs;
    }

    template <typename N1, typename I1, typename D1, typename N2, typename I2, typename D2>
    inline typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
        operator<=(
            in_order_tree_iterator<N1,I1,D1> const& lhs,
            in_order_tree_iterator<N2,I2,D2> const& rhs
        )
    {
        return !(rhs < lhs);
    }

    template <typename N1, typename I1, typename D1, typename N2, typename I2, typename D2>
    inline typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
        operator>=(
            in_order_tree_iterator<N1,I1,D1> const& lhs,
            in_order_tree_iterator<N2,I2,D2> const& rhs
        )
    {
        return !(lhs < rhs);
    }

    template <typename N1, typename I1, typename D1, typename N2, typename I2, typename D2>
    inline typename ::std::common_type<D1,D2>::type
        operator-(
            in_order_tree_iterator<N1,I1,D1> const& lhs,
            in_order_tree_iterator<N2,I2,D2> const& rhs
        )
    {
        BOOST_ASSERT_MSG(lhs._root == rhs._root, "Iterators are unreachable from each other.");

        typename ::std::common_type<D1,D2>::type v = ::boost::initialized_value;

        if (lhs._state.get())
        {
            if (rhs._state.get())
            {
                v = typename ::std::common_type<D1,D2>::type(
                    ::odds_and_ends::node::algorithm
                    ::binary_tree_index_of(rhs._current, v, rhs._root, I2::value)
                );
                v = typename ::std::common_type<D1,D2>::type(
                    ::odds_and_ends::node::algorithm
                    ::binary_tree_index_of(lhs._current, -v, lhs._root, I1::value)
                );
            }
            else
            {
                v = typename ::std::common_type<D1,D2>::type(lhs._root->size());
                v = typename ::std::common_type<D1,D2>::type(
                    ::odds_and_ends::node::algorithm
                    ::binary_tree_index_of(lhs._current, -v, lhs._root, I2::value)
                );
            }
        }
        else if (rhs._state.get())
        {
            v = typename ::std::common_type<D1,D2>::type(
                ::odds_and_ends::node::algorithm
                ::binary_tree_index_of(rhs._current, v, rhs._root, I1::value)
            );
            v = typename ::std::common_type<D1,D2>::type(rhs._root->size()) - v;
        }

        return v;
    }

    template <typename Difference = ::std::ptrdiff_t, typename Node>
    inline in_order_tree_iterator<Node,::boost::mpl::false_,Difference>
        make_in_order_tree_iterator(Node& node)
    {
        return in_order_tree_iterator<Node,::boost::mpl::false_,Difference>(node, false);
    }

    template <typename Difference = ::std::ptrdiff_t, typename Node>
    inline in_order_tree_iterator<Node,::boost::mpl::false_,Difference>
        make_in_order_tree_iterator_begin(Node& node)
    {
        return in_order_tree_iterator<Node,::boost::mpl::false_,Difference>(node, false);
    }

    template <typename Difference = ::std::ptrdiff_t, typename Node>
    inline in_order_tree_iterator<Node,::boost::mpl::false_,Difference>
        make_in_order_tree_iterator_end(Node& node)
    {
        return in_order_tree_iterator<Node,::boost::mpl::false_,Difference>(node, true);
    }

    template <typename Difference = ::std::ptrdiff_t, typename Node>
    inline in_order_tree_iterator<Node,::boost::mpl::true_,Difference>
        make_in_order_tree_reverse_iterator(Node& node)
    {
        return in_order_tree_iterator<Node,::boost::mpl::true_,Difference>(node, false);
    }

    template <typename Difference = ::std::ptrdiff_t, typename Node>
    inline in_order_tree_iterator<Node,::boost::mpl::true_,Difference>
        make_in_order_tree_reverse_iterator_begin(Node& node)
    {
        return in_order_tree_iterator<Node,::boost::mpl::true_,Difference>(node, false);
    }

    template <typename Difference = ::std::ptrdiff_t, typename Node>
    inline in_order_tree_iterator<Node,::boost::mpl::true_,Difference>
        make_in_order_tree_reverse_iterator_end(Node& node)
    {
        return in_order_tree_iterator<Node,::boost::mpl::true_,Difference>(node, true);
    }

    template <typename Difference = ::std::ptrdiff_t, typename Node>
    inline in_order_tree_iterator<Node,::boost::mpl::false_,Difference>
        make_in_order_tree_iterator_position(Node& node)
    {
        return in_order_tree_iterator<Node,::boost::mpl::false_,Difference>(node);
    }
}}  // namespace odds_and_ends::node

#endif  // ODDS_AND_ENDS__NODE__ITERATOR__IN_ORDER_TREE_HPP

