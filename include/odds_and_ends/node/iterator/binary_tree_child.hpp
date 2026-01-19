// Copyright (C) 2011-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__ITERATOR__BINARY_TREE_CHILD_HPP
#define ODDS_AND_ENDS__NODE__ITERATOR__BINARY_TREE_CHILD_HPP

#include <type_traits>
#include <iterator>
#include <boost/core/enable_if.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/equal_to.hpp>

namespace odds_and_ends { namespace node {

    template <typename Node, typename IsReverse, typename Difference = ::std::ptrdiff_t>
    class binary_tree_child_iterator
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
            binary_tree_child_iterator _itr;

        public:
            _proxy(pointer const& p, difference_type const& n);

            operator binary_tree_child_iterator&();
        };

        pointer _current;
        pointer _parent;

    public:
        binary_tree_child_iterator();
        explicit binary_tree_child_iterator(pointer const& p);
        binary_tree_child_iterator(pointer const& p, bool p_is_child);
        binary_tree_child_iterator(binary_tree_child_iterator const& other);
        binary_tree_child_iterator(binary_tree_child_iterator&& other);

        template <typename N, typename I, typename D>
        binary_tree_child_iterator(
            binary_tree_child_iterator<N,I,D> const& other,
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
        binary_tree_child_iterator(
            binary_tree_child_iterator<N,I,D>&& other,
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
/*
        template <typename N, typename I, typename D>
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
            binary_tree_child_iterator&
        >::type
            operator=(binary_tree_child_iterator<N,I,D> const& other);

        template <typename N, typename I, typename D>
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
            binary_tree_child_iterator&
        >::type
            operator=(binary_tree_child_iterator<N,I,D>&& other);
*/
        binary_tree_child_iterator& operator=(binary_tree_child_iterator const& other);
        binary_tree_child_iterator& operator=(binary_tree_child_iterator&& other);
        reference operator*() const;
        pointer operator->() const;
        _proxy operator[](difference_type const& n) const;
        binary_tree_child_iterator& operator++();
        binary_tree_child_iterator operator++(int);
        binary_tree_child_iterator& operator--();
        binary_tree_child_iterator operator--(int);
        binary_tree_child_iterator& operator+=(difference_type const& n);
        binary_tree_child_iterator& operator-=(difference_type const& n);

    private:
        void _iterate(pointer const& sibling);
        void _advance(difference_type const& n, ::std::true_type);
        void _advance(difference_type const& n, ::std::false_type);

        template <typename N1, typename I1, typename D1, typename N2, typename I2, typename D2>
        friend typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
            operator==(
                binary_tree_child_iterator<N1,I1,D1> const& lhs,
                binary_tree_child_iterator<N2,I2,D2> const& rhs
            );

        template <typename N1, typename I1, typename D1, typename N2, typename I2, typename D2>
        friend typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
            operator<(
                binary_tree_child_iterator<N1,I1,D1> const& lhs,
                binary_tree_child_iterator<N2,I2,D2> const& rhs
            );

        template <typename N1, typename I1, typename D1, typename N2, typename I2, typename D2>
        friend typename ::boost::lazy_enable_if<
            typename ::boost::mpl::if_<
                ::std::is_integral<D1>,
                ::std::is_integral<D2>,
                ::boost::mpl::false_
            >::type,
            ::std::common_type<D1,D2>
        >::type
            operator-(
                binary_tree_child_iterator<N1,I1,D1> const& lhs,
                binary_tree_child_iterator<N2,I2,D2> const& rhs
            );

        template <typename N1, typename I1, typename D1, typename N2, typename I2, typename D2>
        friend typename ::boost::lazy_disable_if<
            typename ::boost::mpl::if_<
                ::std::is_integral<D1>,
                ::std::is_integral<D2>,
                ::boost::mpl::false_
            >::type,
            ::std::common_type<D1,D2>
        >::type
            operator-(
                binary_tree_child_iterator<N1,I1,D1> const& lhs,
                binary_tree_child_iterator<N2,I2,D2> const& rhs
            );

    private:
        pointer const& current() const;
        pointer& current();
        pointer const& parent() const;
        pointer& parent();

        template <typename N, typename I, typename D>
        friend class binary_tree_child_iterator;
    };
}}  // namespace odds_and_ends::node

#include <utility>
#include <boost/utility/value_init.hpp>
#include <boost/assert.hpp>

namespace odds_and_ends { namespace node {

    template <typename Node, typename IsReverse, typename Difference>
    binary_tree_child_iterator<Node,IsReverse,Difference>::_proxy::_proxy(
        pointer const& p,
        difference_type const& n
    ) : _itr(p, true)
    {
        this->_itr._advance(n, ::std::is_integral<Difference>());
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline binary_tree_child_iterator<Node,IsReverse,Difference>::_proxy::operator
        binary_tree_child_iterator&()
    {
        return this->_itr;
    }

    template <typename Node, typename IsReverse, typename Difference>
    binary_tree_child_iterator<Node,IsReverse,Difference>::binary_tree_child_iterator() :
        _current(nullptr), _parent(nullptr)
    {
    }

    template <typename Node, typename IsReverse, typename Difference>
    binary_tree_child_iterator<Node,IsReverse,Difference>::binary_tree_child_iterator(
        pointer const& p,
        bool p_is_child
    ) : _current(
            p_is_child ? p : IsReverse::value ? (
                p->right() ? p->right() : p->left()
            ) : (p->left() ? p->left() : p->right())
        ),
        _parent(p_is_child ? p->parent() : p)
    {
    }

    template <typename Node, typename IsReverse, typename Difference>
    binary_tree_child_iterator<Node,IsReverse,Difference>::binary_tree_child_iterator(
        pointer const& p
    ) : _current(nullptr), _parent(p)
    {
    }

    template <typename Node, typename IsReverse, typename Difference>
    binary_tree_child_iterator<Node,IsReverse,Difference>::binary_tree_child_iterator(
        binary_tree_child_iterator const& other
    ) : _current(other.current()), _parent(other.parent())
    {
    }

    template <typename Node, typename IsReverse, typename Difference>
    template <typename N, typename I, typename D>
    binary_tree_child_iterator<Node,IsReverse,Difference>::binary_tree_child_iterator(
        binary_tree_child_iterator<N,I,D> const& other,
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
            typename binary_tree_child_iterator<Node,IsReverse,Difference>::_enabler
        >::type
    ) : _current(other.current()), _parent(other.parent())
    {
    }

    template <typename Node, typename IsReverse, typename Difference>
    binary_tree_child_iterator<Node,IsReverse,Difference>::binary_tree_child_iterator(
        binary_tree_child_iterator&& other
    ) : _current(::std::move(other.current())), _parent(::std::move(other.parent()))
    {
    }

    template <typename Node, typename IsReverse, typename Difference>
    template <typename N, typename I, typename D>
    binary_tree_child_iterator<Node,IsReverse,Difference>::binary_tree_child_iterator(
        binary_tree_child_iterator<N,I,D>&& other,
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
            typename binary_tree_child_iterator<Node,IsReverse,Difference>::_enabler
        >::type
    ) : _current(::std::move(other.current())), _parent(::std::move(other.parent()))
    {
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline binary_tree_child_iterator<Node,IsReverse,Difference>&
        binary_tree_child_iterator<Node,IsReverse,Difference>::operator=(
            binary_tree_child_iterator const& other
        )
    {
        if (this != &other)
        {
            this->_current = other.current();
            this->_parent = other.parent();
        }

        return *this;
    }
/*
    template <typename Node, typename IsReverse, typename Difference>
    template <typename N, typename I, typename D>
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
        binary_tree_child_iterator<Node,IsReverse,Difference>&
    >::type
        binary_tree_child_iterator<Node,IsReverse,Difference>::operator=(
            binary_tree_child_iterator<N,I,D> const& other
        )
    {
        if (this != &other)
        {
            this->_current = other.current();
            this->_parent = other.parent();
        }

        return *this;
    }
*/
    template <typename Node, typename IsReverse, typename Difference>
    inline binary_tree_child_iterator<Node,IsReverse,Difference>&
        binary_tree_child_iterator<Node,IsReverse,Difference>::operator=(
            binary_tree_child_iterator&& other
        )
    {
        if (this != &static_cast<binary_tree_child_iterator&>(other))
        {
            this->_current = ::std::move(other.current());
            this->_parent = ::std::move(other.parent());
        }

        return *this;
    }
/*
    template <typename Node, typename IsReverse, typename Difference>
    template <typename N, typename I, typename D>
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
        binary_tree_child_iterator<Node,IsReverse,Difference>&
    >::type
        binary_tree_child_iterator<Node,IsReverse,Difference>::operator=(
            binary_tree_child_iterator<N,I,D>&& other
        )
    {
        if (this != &static_cast<binary_tree_child_iterator<N,I,D>&>(other))
        {
            this->_current = ::std::move(other.current());
            this->_parent = ::std::move(other.parent());
        }

        return *this;
    }
*/
    template <typename Node, typename IsReverse, typename Difference>
    inline typename binary_tree_child_iterator<Node,IsReverse,Difference>::reference
        binary_tree_child_iterator<Node,IsReverse,Difference>::operator*() const
    {
        return *this->_current;
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline typename binary_tree_child_iterator<Node,IsReverse,Difference>::pointer
        binary_tree_child_iterator<Node,IsReverse,Difference>::operator->() const
    {
        return this->_current;
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline typename binary_tree_child_iterator<Node,IsReverse,Difference>::_proxy
        binary_tree_child_iterator<Node,IsReverse,Difference>::operator[](
            difference_type const& n
        ) const
    {
        return _proxy(this->_current, n);
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline binary_tree_child_iterator<Node,IsReverse,Difference>&
        binary_tree_child_iterator<Node,IsReverse,Difference>::operator++()
    {
        this->_iterate(IsReverse::value ? this->_parent->left() : this->_parent->right());
        return *this;
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline binary_tree_child_iterator<Node,IsReverse,Difference>
        binary_tree_child_iterator<Node,IsReverse,Difference>::operator++(int)
    {
        binary_tree_child_iterator itr(*this);
        ++(*this);
        return itr;
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline binary_tree_child_iterator<Node,IsReverse,Difference>&
        binary_tree_child_iterator<Node,IsReverse,Difference>::operator--()
    {
        if (this->_current)
        {
            this->_iterate(IsReverse::value ? this->_parent->right() : this->_parent->left());
        }
        else if (IsReverse::value)
        {
            this->_current = this->_parent->left();

            if (!this->_current)
            {
                this->_current = this->_parent->right();
            }
        }
        else
        {
            this->_current = this->_parent->right();

            if (!this->_current)
            {
                this->_current = this->_parent->left();
            }
        }

        BOOST_ASSERT_MSG(this->_current, "Result not dereferenceable.");
        return *this;
    }

    template <typename Node, typename IsReverse, typename Difference>
    binary_tree_child_iterator<Node,IsReverse,Difference>
        binary_tree_child_iterator<Node,IsReverse,Difference>::operator--(int)
    {
        binary_tree_child_iterator itr(*this);
        --(*this);
        return itr;
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline binary_tree_child_iterator<Node,IsReverse,Difference>&
        binary_tree_child_iterator<Node,IsReverse,Difference>::operator+=(difference_type const& n)
    {
        this->_advance(n, ::std::is_integral<Difference>());
        return *this;
    }

    template <typename Node, typename IsReverse, typename Difference>
    binary_tree_child_iterator<Node,IsReverse,Difference>
        operator+(
            binary_tree_child_iterator<Node,IsReverse,Difference> const& operand,
            typename binary_tree_child_iterator<
                Node,
                IsReverse,
                Difference
            >::difference_type const& n
        )
    {
        binary_tree_child_iterator<Node,IsReverse,Difference> itr(operand);
        itr += n;
        return itr;
    }

    template <typename Node, typename IsReverse, typename Difference>
    binary_tree_child_iterator<Node,IsReverse,Difference>
        operator+(
            typename binary_tree_child_iterator<
                Node,
                IsReverse,
                Difference
            >::difference_type const& n,
            binary_tree_child_iterator<Node,IsReverse,Difference> const& operand
        )
    {
        binary_tree_child_iterator<Node,IsReverse,Difference> itr(operand);
        itr += n;
        return itr;
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline binary_tree_child_iterator<Node,IsReverse,Difference>&
        binary_tree_child_iterator<Node,IsReverse,Difference>::operator-=(difference_type const& n)
    {
        this->_advance(-n, ::std::is_integral<Difference>());
        return *this;
    }

    template <typename Node, typename IsReverse, typename Difference>
    binary_tree_child_iterator<Node,IsReverse,Difference>
        operator-(
            binary_tree_child_iterator<Node,IsReverse,Difference> const& operand,
            typename binary_tree_child_iterator<
                Node,
                IsReverse,
                Difference
            >::difference_type const& n
        )
    {
        binary_tree_child_iterator<Node,IsReverse,Difference> itr(operand);
        itr -= n;
        return itr;
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline typename binary_tree_child_iterator<Node,IsReverse,Difference>::pointer const&
        binary_tree_child_iterator<Node,IsReverse,Difference>::current() const
    {
        return this->_current;
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline typename binary_tree_child_iterator<Node,IsReverse,Difference>::pointer&
        binary_tree_child_iterator<Node,IsReverse,Difference>::current()
    {
        return this->_current;
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline typename binary_tree_child_iterator<Node,IsReverse,Difference>::pointer const&
        binary_tree_child_iterator<Node,IsReverse,Difference>::parent() const
    {
        return this->_parent;
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline typename binary_tree_child_iterator<Node,IsReverse,Difference>::pointer&
        binary_tree_child_iterator<Node,IsReverse,Difference>::parent()
    {
        return this->_parent;
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline void
        binary_tree_child_iterator<Node,IsReverse,Difference>::_iterate(pointer const& sibling)
    {
        this->_current = (this->_current == sibling) ? nullptr : sibling;
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline void
        binary_tree_child_iterator<Node,IsReverse,Difference>::_advance(
            difference_type const& n,
            ::std::true_type
        )
    {
        switch (n)
        {
            case -2:
            {
                if (this->_current)
                {
                    BOOST_ASSERT_MSG(
                        (
                            IsReverse::value ? (
                                (
                                    this->_current == this->_parent->left()
                                ) && this->_parent->right()
                            ) : (
                                (
                                    this->_current == this->_parent->right()
                                ) && this->_parent->left()
                            )
                        ),
                        "n must be greater than -2."
                    );

                    this->_current = nullptr;
                }
                else
                {
                    this->_current = (
                        IsReverse::value ? (
                            this->_parent->right() ?
                            this->_parent->right() :
                            this->_parent->left()
                        ) : (
                            this->_parent->left() ?
                            this->_parent->left() :
                            this->_parent->right()
                        )
                    );
                }

                break;
            }

            case -1:
            {
                --(*this);
                break;
            }

            case 0:
            {
                break;
            }

            case 1:
            {
                ++(*this);
                break;
            }

            case 2:
            {
                BOOST_ASSERT_MSG(
                    (
                        IsReverse::value ? (
                            (
                                this->_current == this->_parent->right()
                            ) && this->_parent->left()
                        ) : (
                            (
                                this->_current == this->_parent->left()
                            ) && this->_parent->right()
                        )
                    ),
                    "n must be less than 2."
                );

                this->_current = nullptr;
                break;
            }

            default:
            {
                BOOST_ASSERT_MSG(false, "|n| must be less than 3.");
            }
        }
    }

    template <typename Node, typename IsReverse, typename Difference>
    inline void
        binary_tree_child_iterator<Node,IsReverse,Difference>::_advance(
            difference_type const& n,
            ::std::false_type
        )
    {
        if (n < 0)
        {
            if (-1 == n)
            {
                --(*this);
            }
            else if (-2 == n)
            {
                if (this->_current)
                {
                    BOOST_ASSERT_MSG(
                        (
                            IsReverse::value ? (
                                (
                                    this->_current == this->_parent->left()
                                ) && this->_parent->right()
                            ) : (
                                (
                                    this->_current == this->_parent->right()
                                ) && this->_parent->left()
                            )
                        ),
                        "n must be greater than -2."
                    );

                    this->_current = nullptr;
                }
                else
                {
                    this->_current = (
                        IsReverse::value ? (
                            this->_parent->right() ?
                            this->_parent->right() :
                            this->_parent->left()
                        ) : (
                            this->_parent->left() ?
                            this->_parent->left() :
                            this->_parent->right()
                        )
                    );
                }
            }
            else
            {
                BOOST_ASSERT_MSG(false, "n must be greater than -3.");
            }
        }
        else if (1 == n)
        {
            ++(*this);
        }
        else if (2 == n)
        {
            BOOST_ASSERT_MSG(
                (
                    IsReverse::value ? (
                        (
                            this->_current == this->_parent->right()
                        ) && this->_parent->left()
                    ) : (
                        (
                            this->_current == this->_parent->left()
                        ) && this->_parent->right()
                    )
                ),
                "n must be less than 2."
            );

            this->_current = nullptr;
        }
        else
        {
            BOOST_ASSERT_MSG(false, "n must be less than 3.");
        }
    }

    template <typename N1, typename I1, typename D1, typename N2, typename I2, typename D2>
    inline typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
        operator==(
            binary_tree_child_iterator<N1,I1,D1> const& lhs,
            binary_tree_child_iterator<N2,I2,D2> const& rhs
        )
    {
        return lhs._current == rhs._current;
    }

    template <typename N1, typename I1, typename D1, typename N2, typename I2, typename D2>
    inline typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
        operator!=(
            binary_tree_child_iterator<N1,I1,D1> const& lhs,
            binary_tree_child_iterator<N2,I2,D2> const& rhs
        )
    {
        return !(lhs == rhs);
    }

    template <typename N1, typename I1, typename D1, typename N2, typename I2, typename D2>
    inline typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
        operator<(
            binary_tree_child_iterator<N1,I1,D1> const& lhs,
            binary_tree_child_iterator<N2,I2,D2> const& rhs
        )
    {
        BOOST_ASSERT_MSG(lhs._parent, "lhs is unreachable.");
        BOOST_ASSERT_MSG(rhs._parent, "rhs is unreachable.");
        BOOST_ASSERT_MSG(
            rhs._parent == lhs._parent,
            "Neither iterator is reachable from one other."
        );

        if (lhs._current)
        {
            if (rhs._current)
            {
                return rhs._current == (I1::value ? lhs._parent->left() : lhs._parent->right());
            }
            else
            {
                return true;
            }
        }
        else
        {
            return false;
        }
    }

    template <typename N1, typename I1, typename D1, typename N2, typename I2, typename D2>
    inline typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
        operator>(
            binary_tree_child_iterator<N1,I1,D1> const& lhs,
            binary_tree_child_iterator<N2,I2,D2> const& rhs
        )
    {
        return rhs < lhs;
    }

    template <typename N1, typename I1, typename D1, typename N2, typename I2, typename D2>
    inline typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
        operator<=(
            binary_tree_child_iterator<N1,I1,D1> const& lhs,
            binary_tree_child_iterator<N2,I2,D2> const& rhs
        )
    {
        return !(rhs < lhs);
    }

    template <typename N1, typename I1, typename D1, typename N2, typename I2, typename D2>
    inline typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
        operator>=(
            binary_tree_child_iterator<N1,I1,D1> const& lhs,
            binary_tree_child_iterator<N2,I2,D2> const& rhs
        )
    {
        return !(lhs < rhs);
    }

    template <typename N1, typename I1, typename D1, typename N2, typename I2, typename D2>
    inline typename ::boost::lazy_enable_if<
        typename ::boost::mpl::if_<
            ::std::is_integral<D1>,
            ::std::is_integral<D2>,
            ::boost::mpl::false_
        >::type,
        ::std::common_type<D1,D2>
    >::type
        operator-(
            binary_tree_child_iterator<N1,I1,D1> const& lhs,
            binary_tree_child_iterator<N2,I2,D2> const& rhs
        )
    {
        BOOST_ASSERT_MSG(lhs._parent, "lhs is unreachable.");
        BOOST_ASSERT_MSG(rhs._parent, "rhs is unreachable.");
        BOOST_ASSERT_MSG(
            rhs._parent == lhs._parent,
            "Neither iterator is reachable from one other."
        );

        if (lhs._current == rhs._current)
        {
            return 0;
        }
        else if (lhs._current)
        {
            if (rhs._current)
            {
                return (rhs._current == lhs._parent->left()) ? 1 : -1;
            }
            else
            {
                return (lhs._parent->left() && lhs._parent->right()) ? 2 : 1;
            }
        }
        else
        {
            return (rhs._parent->left() && rhs._parent->right()) ? -2 : -1;
        }
    }

    template <typename N1, typename I1, typename D1, typename N2, typename I2, typename D2>
    inline typename ::boost::lazy_disable_if<
        typename ::boost::mpl::if_<
            ::std::is_integral<D1>,
            ::std::is_integral<D2>,
            ::boost::mpl::false_
        >::type,
        ::std::common_type<D1,D2>
    >::type
        operator-(
            binary_tree_child_iterator<N1,I1,D1> const& lhs,
            binary_tree_child_iterator<N2,I2,D2> const& rhs
        )
    {
        BOOST_ASSERT_MSG(lhs._parent, "lhs is unreachable.");
        BOOST_ASSERT_MSG(rhs._parent, "rhs is unreachable.");
        BOOST_ASSERT_MSG(
            rhs._parent == lhs._parent,
            "Neither iterator is reachable from one other."
        );

        ::std::common_type<D1,D2> result = ::boost::initialized_value;

        if (lhs._current != rhs._current)
        {
            if (lhs._current)
            {
                if (rhs._current)
                {
                    if (rhs._current == lhs._parent->left())
                    {
                        ++result;
                    }
                    else
                    {
                        --result;
                    }
                }
                else
                {
                    ++result;

                    if (lhs._parent->left() && lhs._parent->right())
                    {
                        ++result;
                    }
                }
            }
            else
            {
                --result;

                if (rhs._parent->left() && rhs._parent->right())
                {
                    --result;
                }
            }
        }

        return result;
    }
}}  // namespace odds_and_ends::node

#endif  // ODDS_AND_ENDS__NODE__ITERATOR__BINARY_TREE_CHILD_HPP

