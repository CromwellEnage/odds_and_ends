// Copyright (C) 2025-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__ITERATOR__INDIRECT_HPP
#define ODDS_AND_ENDS__NODE__ITERATOR__INDIRECT_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/nested_type/has_difference_type.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_traits.hpp>
#include <odds_and_ends/static_introspection/iterator_value_of.hpp>
#include <boost/core/enable_if.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/apply_wrap.hpp>

namespace odds_and_ends { namespace node {

    template <
        typename Iterator,
        typename PtrXForm,
        typename HasDiff = typename ::odds_and_ends::static_introspection
        ::nested_type::has_difference_type<Iterator>::type
    >
    class indirect_iterator
    {
        struct _enabler
        {
        };

        typedef typename Iterator::value_type _iterator_value;
        typedef typename ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::nested_type::has_traits<_iterator_value>,
            ::boost::mpl::identity<_iterator_value>,
            ::odds_and_ends::static_introspection::iterator_value_of<_iterator_value>
        >::type _node_t;
        typedef typename ::std::remove_const<_node_t>::type::traits::value_type _value_t;

    public:
        typedef typename Iterator::iterator_category iterator_category;
        typedef typename Iterator::difference_type difference_type;
        typedef typename ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::nested_type::has_traits<_iterator_value>,
            ::boost::mpl::if_< ::std::is_const<_node_t>,_value_t const,_value_t>,
            ::boost::mpl::identity<_node_t>
        >::type value_type;
        typedef typename ::boost::mpl::apply_wrap1<PtrXForm,value_type>::type pointer;
        typedef value_type& reference;

    private:
        class _proxy
        {
            indirect_iterator _itr;

        public:
            _proxy(Iterator const& itr, difference_type const& n);

            operator indirect_iterator&();
        };

        Iterator _current;

    public:
        template <typename Itr, typename PX, typename B>
        indirect_iterator(
            indirect_iterator<Itr,PX,B> const& other,
            typename ::boost::enable_if<
                ::std::is_convertible<Itr,Iterator>,
                _enabler
            >::type = _enabler()
        );

        template <typename Itr, typename PX, typename B>
        indirect_iterator(
            indirect_iterator<Itr,PX,B>&& other,
            typename ::boost::enable_if<
                ::std::is_convertible<Itr,Iterator>,
                _enabler
            >::type = _enabler()
        );

        indirect_iterator(indirect_iterator const& other);
        indirect_iterator(indirect_iterator&& other);
        indirect_iterator(Iterator const& itr);
        indirect_iterator();
        ~indirect_iterator();
        indirect_iterator& operator=(indirect_iterator const& other);
        indirect_iterator& operator=(indirect_iterator&& other);
        Iterator base() const;
        reference operator*() const;
        pointer operator->() const;
        _proxy operator[](difference_type const& n) const;
        indirect_iterator& operator++();
        indirect_iterator operator++(int);
        indirect_iterator& operator--();
        indirect_iterator operator--(int);
        indirect_iterator& operator+=(difference_type const& n);
        indirect_iterator& operator-=(difference_type const& n);

    private:
        template <typename Itr, typename PX, typename B>
        friend class indirect_iterator;

        template <typename I1, typename PX1, typename B1, typename I2, typename PX2, typename B2>
        friend typename ::boost::enable_if< ::boost::mpl::equal_to<B1,B2>,bool>::type
            operator==(
                indirect_iterator<I1,PX1,B1> const& lhs,
                indirect_iterator<I2,PX2,B2> const& rhs
            );

        template <typename I1, typename PX1, typename B1, typename I2, typename PX2, typename B2>
        friend typename ::boost::enable_if<
            typename ::boost::mpl::if_<B1,B2,::boost::mpl::false_>::type,
            bool
        >::type
            operator<(
                indirect_iterator<I1,PX1,B1> const& lhs,
                indirect_iterator<I2,PX2,B2> const& rhs
            );

        template <typename I1, typename PX1, typename B1, typename I2, typename PX2, typename B2>
        friend typename ::std::common_type<
            typename indirect_iterator<I1,PX1,B1>::difference_type,
            typename indirect_iterator<I2,PX2,B2>::difference_type
        >::type
            operator-(
                indirect_iterator<I1,PX1,B1> const& lhs,
                indirect_iterator<I2,PX2,B2> const& rhs
            );
    };
}}  // namespace odds_and_ends::node

#include <utility>
#include <memory>

namespace odds_and_ends { namespace node {

    template <typename Iterator, typename PtrXForm>
    class indirect_iterator<Iterator,PtrXForm,::boost::mpl::false_>
    {
        struct _enabler
        {
        };

        typedef typename Iterator::value_type _iterator_value;
        typedef typename ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::nested_type::has_traits<_iterator_value>,
            ::boost::mpl::identity<_iterator_value>,
            ::odds_and_ends::static_introspection::iterator_value_of<_iterator_value>
        >::type _node_t;
        typedef typename ::std::remove_const<_node_t>::type::traits::value_type _value_t;

    public:
        typedef typename Iterator::iterator_category iterator_category;
        typedef typename ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::nested_type::has_traits<_iterator_value>,
            ::boost::mpl::if_< ::std::is_const<_node_t>,_value_t const,_value_t>,
            ::boost::mpl::identity<_node_t>
        >::type value_type;
        typedef typename ::boost::mpl::apply_wrap1<PtrXForm,value_type>::type pointer;
        typedef value_type& reference;

    private:
        Iterator _current;

    public:
        template <typename Itr, typename PX, typename B>
        indirect_iterator(
            indirect_iterator<Itr,PX,B> const& other,
            typename ::boost::enable_if<
                ::std::is_convertible<Itr,Iterator>,
                _enabler
            >::type = _enabler()
        ) : _current(other._current)
        {
        }

        template <typename Itr, typename PX, typename B>
        indirect_iterator(
            indirect_iterator<Itr,PX,B>&& other,
            typename ::boost::enable_if<
                ::std::is_convertible<Itr,Iterator>,
                _enabler
            >::type = _enabler()
        ) : _current(::std::move(other._current))
        {
        }

        inline indirect_iterator(indirect_iterator const& other) : _current(other._current)
        {
        }

        inline indirect_iterator(indirect_iterator&& other) : _current(::std::move(other._current))
        {
        }

        inline indirect_iterator(Iterator const& itr) : _current(itr)
        {
        }

        inline indirect_iterator() : _current()
        {
        }

        inline ~indirect_iterator()
        {
        }

        inline indirect_iterator& operator=(indirect_iterator const& other)
        {
            if (this != &other)
            {
                this->_current = other._current;
            }

            return *this;
        }

        inline indirect_iterator& operator=(indirect_iterator&& other)
        {
            if (this != &static_cast<indirect_iterator&>(other))
            {
                this->_current = ::std::move(other._current);
            }

            return *this;
        }

        inline Iterator base() const
        {
            return this->_current;
        }

        inline reference operator*() const
        {
            return **this->_current;
        }

        inline pointer operator->() const
        {
            return ::std::pointer_traits<pointer>::pointer_to(**this->_current);
        }

        inline indirect_iterator& operator++()
        {
            ++this->_current;
            return *this;
        }

        indirect_iterator operator++(int)
        {
            indirect_iterator itr(*this);
            ++this->_current;
            return itr;
        }

        inline indirect_iterator& operator--()
        {
            --this->_current;
            return *this;
        }

        indirect_iterator operator--(int)
        {
            indirect_iterator itr(*this);
            --this->_current;
            return itr;
        }

    private:
        template <typename Itr, typename PX, typename B>
        friend class indirect_iterator;

        template <typename I1, typename PX1, typename B1, typename I2, typename PX2, typename B2>
        friend typename ::boost::enable_if< ::boost::mpl::equal_to<B1,B2>,bool>::type
            operator==(
                indirect_iterator<I1,PX1,B1> const& lhs,
                indirect_iterator<I2,PX2,B2> const& rhs
            );
    };

    template <typename I, typename PtrXForm, typename HasDiff>
    indirect_iterator<I,PtrXForm,HasDiff>::_proxy::_proxy(I const& itr, difference_type const& n) :
        _itr(itr)
    {
        this->_itr += n;
    }

    template <typename Iterator, typename PtrXForm, typename HasDiff>
    inline indirect_iterator<Iterator,PtrXForm,HasDiff>::_proxy::operator indirect_iterator&()
    {
        return this->_itr;
    }

    template <typename Iterator, typename PtrXForm, typename HasDiff>
    indirect_iterator<Iterator,PtrXForm,HasDiff>::indirect_iterator() : _current()
    {
    }

    template <typename Itr, typename PtrXForm, typename HasDiff>
    indirect_iterator<Itr,PtrXForm,HasDiff>::indirect_iterator(Itr const& itr) : _current(itr)
    {
    }

    template <typename Iterator, typename PtrXForm, typename HasDiff>
    inline indirect_iterator<Iterator,PtrXForm,HasDiff>::indirect_iterator(
        indirect_iterator const& other
    ) : _current(other._current)
    {
    }

    template <typename Iterator, typename PtrXForm, typename HasDiff>
    template <typename Itr, typename PX, typename B>
    inline indirect_iterator<Iterator,PtrXForm,HasDiff>::indirect_iterator(
        indirect_iterator<Itr,PX,B> const& other,
        typename ::boost::enable_if< ::std::is_convertible<Itr,Iterator>,_enabler>::type
    ) : _current(other._current)
    {
    }

    template <typename Itr, typename PtrXForm, typename HasDiff>
    inline indirect_iterator<Itr,PtrXForm,HasDiff>::indirect_iterator(indirect_iterator&& other) :
        _current(::std::move(other._current))
    {
    }

    template <typename Iterator, typename PtrXForm, typename HasDiff>
    template <typename Itr, typename PX, typename B>
    inline indirect_iterator<Iterator,PtrXForm,HasDiff>::indirect_iterator(
        indirect_iterator<Itr,PX,B>&& other,
        typename ::boost::enable_if< ::std::is_convertible<Itr,Iterator>,_enabler>::type
    ) : _current(::std::move(other._current))
    {
    }

    template <typename Iterator, typename PtrXForm, typename HasDiff>
    inline indirect_iterator<Iterator,PtrXForm,HasDiff>::~indirect_iterator()
    {
    }

    template <typename Iterator, typename PtrXForm, typename HasDiff>
    inline indirect_iterator<Iterator,PtrXForm,HasDiff>&
        indirect_iterator<Iterator,PtrXForm,HasDiff>::operator=(indirect_iterator const& other)
    {
        if (this != &other)
        {
            this->_current = other._current;
        }

        return *this;
    }

    template <typename Iterator, typename PtrXForm, typename HasDiff>
    inline indirect_iterator<Iterator,PtrXForm,HasDiff>&
        indirect_iterator<Iterator,PtrXForm,HasDiff>::operator=(indirect_iterator&& other)
    {
        if (this != &static_cast<indirect_iterator&>(other))
        {
            this->_current = ::std::move(other._current);
        }

        return *this;
    }

    template <typename Iterator, typename PtrXForm, typename HasDiff>
    inline Iterator indirect_iterator<Iterator,PtrXForm,HasDiff>::base() const
    {
        return this->_current;
    }

    template <typename Iterator, typename PtrXForm, typename HasDiff>
    inline typename indirect_iterator<Iterator,PtrXForm,HasDiff>::reference
        indirect_iterator<Iterator,PtrXForm,HasDiff>::operator*() const
    {
        return **this->_current;
    }

    template <typename Iterator, typename PtrXForm, typename HasDiff>
    inline typename indirect_iterator<Iterator,PtrXForm,HasDiff>::pointer
        indirect_iterator<Iterator,PtrXForm,HasDiff>::operator->() const
    {
        return ::std::pointer_traits<pointer>::pointer_to(**this->_current);
    }

    template <typename Iterator, typename PtrXForm, typename HasDiff>
    inline typename indirect_iterator<Iterator,PtrXForm,HasDiff>::_proxy
        indirect_iterator<Iterator,PtrXForm,HasDiff>::operator[](difference_type const& n) const
    {
        return _proxy(this->_current, n);
    }

    template <typename Itr, typename PX, typename HasDiff>
    inline indirect_iterator<Itr,PX,HasDiff>& indirect_iterator<Itr,PX,HasDiff>::operator++()
    {
        ++this->_current;
        return *this;
    }

    template <typename Itr, typename PX, typename HasDiff>
    indirect_iterator<Itr,PX,HasDiff> indirect_iterator<Itr,PX,HasDiff>::operator++(int)
    {
        indirect_iterator itr(*this);
        ++this->_current;
        return itr;
    }

    template <typename Itr, typename PX, typename HasDiff>
    inline indirect_iterator<Itr,PX,HasDiff>& indirect_iterator<Itr,PX,HasDiff>::operator--()
    {
        --this->_current;
        return *this;
    }

    template <typename Itr, typename PX, typename HasDiff>
    indirect_iterator<Itr,PX,HasDiff> indirect_iterator<Itr,PX,HasDiff>::operator--(int)
    {
        indirect_iterator itr(*this);
        --this->_current;
        return itr;
    }

    template <typename Iterator, typename PtrXForm, typename HasDiff>
    inline indirect_iterator<Iterator,PtrXForm,HasDiff>&
        indirect_iterator<Iterator,PtrXForm,HasDiff>::operator+=(difference_type const& n)
    {
        this->_current += n;
        return *this;
    }

    template <typename Iterator, typename PtrXForm, typename HasDiff>
    indirect_iterator<Iterator,PtrXForm,HasDiff>
        operator+(
            indirect_iterator<Iterator,PtrXForm,HasDiff> const& operand,
            typename indirect_iterator<Iterator,PtrXForm,HasDiff>::difference_type const& n
        )
    {
        indirect_iterator<Iterator,PtrXForm,HasDiff> itr(operand);
        itr += n;
        return itr;
    }

    template <typename Iterator, typename PtrXForm, typename HasDiff>
    indirect_iterator<Iterator,PtrXForm,HasDiff>
        operator+(
            typename indirect_iterator<Iterator,PtrXForm,HasDiff>::difference_type const& n,
            indirect_iterator<Iterator,PtrXForm,HasDiff> const& operand
        )
    {
        indirect_iterator<Iterator,PtrXForm,HasDiff> itr(operand);
        itr += n;
        return itr;
    }

    template <typename Iterator, typename PtrXForm, typename HasDiff>
    inline indirect_iterator<Iterator,PtrXForm,HasDiff>&
        indirect_iterator<Iterator,PtrXForm,HasDiff>::operator-=(difference_type const& n)
    {
        this->_current -= n;
        return *this;
    }

    template <typename Iterator, typename PtrXForm, typename HasDiff>
    indirect_iterator<Iterator,PtrXForm,HasDiff>
        operator-(
            indirect_iterator<Iterator,PtrXForm,HasDiff> const& operand,
            typename indirect_iterator<Iterator,PtrXForm,HasDiff>::difference_type const& n
        )
    {
        indirect_iterator<Iterator,PtrXForm,HasDiff> itr(operand);
        itr -= n;
        return itr;
    }

    template <typename Itr1, typename PX1, typename B1, typename Itr2, typename PX2, typename B2>
    inline typename ::boost::enable_if< ::boost::mpl::equal_to<B1,B2>,bool>::type
        operator==(
            indirect_iterator<Itr1,PX1,B1> const& lhs,
            indirect_iterator<Itr2,PX2,B2> const& rhs
        )
    {
        return lhs._current == rhs._current;
    }

    template <typename Itr1, typename PX1, typename B1, typename Itr2, typename PX2, typename B2>
    inline typename ::boost::enable_if< ::boost::mpl::equal_to<B1,B2>,bool>::type
        operator!=(
            indirect_iterator<Itr1,PX1,B1> const& lhs,
            indirect_iterator<Itr2,PX2,B2> const& rhs
        )
    {
        return !(lhs == rhs);
    }

    template <typename Itr1, typename PX1, typename B1, typename Itr2, typename PX2, typename B2>
    inline typename ::boost::enable_if<
        typename ::boost::mpl::if_<B1,B2,::boost::mpl::false_>::type,
        bool
    >::type
        operator<(
            indirect_iterator<Itr1,PX1,B1> const& lhs,
            indirect_iterator<Itr2,PX2,B2> const& rhs
        )
    {
        return lhs._current < rhs._current;
    }

    template <typename Itr1, typename PX1, typename B1, typename Itr2, typename PX2, typename B2>
    inline typename ::boost::enable_if<
        typename ::boost::mpl::if_<B1,B2,::boost::mpl::false_>::type,
        bool
    >::type
        operator>(
            indirect_iterator<Itr1,PX1,B1> const& lhs,
            indirect_iterator<Itr2,PX2,B2> const& rhs
        )
    {
        return rhs < lhs;
    }

    template <typename Itr1, typename PX1, typename B1, typename Itr2, typename PX2, typename B2>
    inline typename ::boost::enable_if<
        typename ::boost::mpl::if_<B1,B2,::boost::mpl::false_>::type,
        bool
    >::type
        operator<=(
            indirect_iterator<Itr1,PX1,B1> const& lhs,
            indirect_iterator<Itr2,PX2,B2> const& rhs
        )
    {
        return !(rhs < lhs);
    }

    template <typename Itr1, typename PX1, typename B1, typename Itr2, typename PX2, typename B2>
    inline typename ::boost::enable_if<
        typename ::boost::mpl::if_<B1,B2,::boost::mpl::false_>::type,
        bool
    >::type
        operator>=(
            indirect_iterator<Itr1,PX1,B1> const& lhs,
            indirect_iterator<Itr2,PX2,B2> const& rhs
        )
    {
        return !(lhs < rhs);
    }

    template <typename Itr1, typename PX1, typename B1, typename Itr2, typename PX2, typename B2>
    inline typename ::std::common_type<
        typename indirect_iterator<Itr1,PX1,B1>::difference_type,
        typename indirect_iterator<Itr2,PX2,B2>::difference_type
    >::type
        operator-(
            indirect_iterator<Itr1,PX1,B1> const& lhs,
            indirect_iterator<Itr2,PX2,B2> const& rhs
        )
    {
        return lhs._current - rhs._current;
    }
}}  // namespace odds_and_ends::node

#endif  // ODDS_AND_ENDS__NODE__ITERATOR__INDIRECT_HPP

