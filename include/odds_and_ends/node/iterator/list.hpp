// Copyright (C) 2025-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__ITERATOR__LIST_HPP
#define ODDS_AND_ENDS__NODE__ITERATOR__LIST_HPP

#include <type_traits>
#include <iterator>
#include <boost/core/enable_if.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/not.hpp>

namespace odds_and_ends { namespace node {

    template <typename Node, typename IsReverse>
    class list_iterator
    {
        struct _enabler
        {
        };

    public:
        typedef ::std::bidirectional_iterator_tag iterator_category;
        typedef Node value_type;
        typedef typename ::boost::mpl::if_<
            ::std::is_const<Node>,
            typename ::std::remove_const<Node>::type::traits::const_pointer,
            typename ::std::remove_const<Node>::type::traits::pointer
        >::type pointer;
        typedef Node& reference;

    private:
        pointer _current;
        pointer _before_end;

    public:
        list_iterator();
        list_iterator(pointer const& b, pointer const& e);
        list_iterator(list_iterator const& other);
        list_iterator(list_iterator&& other);

        template <typename N, typename I>
        list_iterator(
            list_iterator<N,I> const& other,
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

        template <typename N, typename I>
        list_iterator(
            list_iterator<N,I>&& other,
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

        list_iterator& operator=(list_iterator const& other);
        list_iterator& operator=(list_iterator&& other);
        reference operator*() const;
        pointer operator->() const;
        list_iterator& operator++();
        list_iterator operator++(int);
        list_iterator& operator--();
        list_iterator operator--(int);
        pointer _last() const;  // Should be private, with container::list as friend.

    private:
        void _iterate(::boost::mpl::false_);
        void _iterate(::boost::mpl::true_);

        template <typename N1, typename I1, typename N2, typename I2>
        friend typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
            operator==(list_iterator<N1,I1> const& lhs, list_iterator<N2,I2> const& rhs);

        template <typename N, typename I>
        friend class list_iterator;
    };
}}  // namespace odds_and_ends::node

#include <utility>
#include <boost/utility/value_init.hpp>
#include <boost/assert.hpp>

namespace odds_and_ends { namespace node {

    template <typename Node, typename IsReverse>
    list_iterator<Node,IsReverse>::list_iterator() : _current(nullptr), _before_end(nullptr)
    {
    }

    template <typename Node, typename IsReverse>
    list_iterator<Node,IsReverse>::list_iterator(pointer const& f, pointer const& b) :
        _current(f), _before_end(b)
    {
    }

    template <typename Node, typename IsReverse>
    list_iterator<Node,IsReverse>::list_iterator(list_iterator const& other) :
        _current(other._current), _before_end(other._before_end)
    {
    }

    template <typename Node, typename IsReverse>
    template <typename N, typename I>
    list_iterator<Node,IsReverse>::list_iterator(
        list_iterator<N,I> const& other,
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
    ) : _current(other._current), _before_end(other._before_end)
    {
    }

    template <typename Node, typename IsReverse>
    list_iterator<Node,IsReverse>::list_iterator(list_iterator&& other) :
        _current(::std::move(other._current)), _before_end(::std::move(other._before_end))
    {
    }

    template <typename Node, typename IsReverse>
    template <typename N, typename I>
    list_iterator<Node,IsReverse>::list_iterator(
        list_iterator<N,I>&& other,
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
    ) : _current(::std::move(other._current)), _before_end(::std::move(other._before_end))
    {
    }

    template <typename Node, typename IsReverse>
    inline list_iterator<Node,IsReverse>&
        list_iterator<Node,IsReverse>::operator=(list_iterator const& other)
    {
        if (this != &other)
        {
            this->_current = other._current;
            this->_before_end = other._before_end;
        }

        return *this;
    }

    template <typename Node, typename IsReverse>
    inline list_iterator<Node,IsReverse>&
        list_iterator<Node,IsReverse>::operator=(list_iterator&& other)
    {
        if (this != &static_cast<list_iterator&>(other))
        {
            this->_current = ::std::move(other._current);
            this->_before_end = ::std::move(other._before_end);
        }

        return *this;
    }

    template <typename Node, typename IsReverse>
    inline typename list_iterator<Node,IsReverse>::reference
        list_iterator<Node,IsReverse>::operator*() const
    {
        return *this->_current;
    }

    template <typename Node, typename IsReverse>
    inline typename list_iterator<Node,IsReverse>::pointer
        list_iterator<Node,IsReverse>::operator->() const
    {
        return this->_current;
    }

    template <typename Node, typename IsReverse>
    inline typename list_iterator<Node,IsReverse>::pointer
        list_iterator<Node,IsReverse>::_last() const
    {
        return this->_before_end;
    }

    template <typename Node, typename IsReverse>
    inline list_iterator<Node,IsReverse>& list_iterator<Node,IsReverse>::operator++()
    {
        this->_iterate(IsReverse());
        return *this;
    }

    template <typename Node, typename IsReverse>
    list_iterator<Node,IsReverse> list_iterator<Node,IsReverse>::operator++(int)
    {
        list_iterator itr(*this);
        ++(*this);
        return itr;
    }

    template <typename Node, typename IsReverse>
    inline list_iterator<Node,IsReverse>& list_iterator<Node,IsReverse>::operator--()
    {
        if (this->_current)
        {
            this->_iterate( ::boost::mpl::not_<IsReverse>());
        }
        else
        {
            this->_current = this->_before_end;
        }

        BOOST_ASSERT_MSG(this->_current, "Result not dereferenceable.");
        return *this;
    }

    template <typename Node, typename IsReverse>
    list_iterator<Node,IsReverse> list_iterator<Node,IsReverse>::operator--(int)
    {
        list_iterator itr(*this);
        --(*this);
        return itr;
    }

    template <typename Node, typename IsReverse>
    inline void list_iterator<Node,IsReverse>::_iterate(::boost::mpl::false_)
    {
        this->_current = this->_current->next();
    }

    template <typename Node, typename IsReverse>
    inline void list_iterator<Node,IsReverse>::_iterate(::boost::mpl::true_)
    {
        this->_current = this->_current->prior();
    }

    template <typename N1, typename I1, typename N2, typename I2>
    inline typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
        operator==(list_iterator<N1,I1> const& lhs, list_iterator<N2,I2> const& rhs)
    {
        return lhs._current == rhs._current;
    }

    template <typename N1, typename I1, typename N2, typename I2>
    inline typename ::boost::enable_if< ::boost::mpl::equal_to<I1,I2>,bool>::type
        operator!=(list_iterator<N1,I1> const& lhs, list_iterator<N2,I2> const& rhs)
    {
        return !(lhs == rhs);
    }
}}  // namespace odds_and_ends::node

#endif  // ODDS_AND_ENDS__NODE__ITERATOR__LIST_HPP

