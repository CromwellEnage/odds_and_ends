// Copyright (C) 2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__ITERATOR__FILTER_HPP
#define ODDS_AND_ENDS__NODE__ITERATOR__FILTER_HPP

#include <type_traits>
#include <iterator>
#include <boost/core/enable_if.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace node {

    template <typename Iterator, typename Predicate>
    class filter_iterator
    {
        struct _enabler
        {
        };

        typedef typename Iterator::iterator_category _original_iterator_category;

        Predicate _predicate;
        Iterator _current_itr;

    public:
        typedef typename ::boost::mpl::if_<
            ::std::is_same<_original_iterator_category,::std::random_access_iterator_tag>,
            ::std::bidirectional_iterator_tag,
            _original_iterator_category
        >::type iterator_category;
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::reference reference;
        typedef typename Iterator::pointer pointer;

        template <typename I, typename P>
        filter_iterator(
            filter_iterator<I,P> const& other,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::std::is_convertible<P,Predicate>,
                    ::std::is_convertible<I,Iterator>,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename I, typename P>
        filter_iterator(
            filter_iterator<I,P> const& other,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::std::is_convertible<P,Predicate>,
                    ::boost::mpl::false_,
                    ::std::is_convertible<I,Iterator>
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename I, typename P>
        filter_iterator(
            filter_iterator<I,P>&& other,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::std::is_convertible<P,Predicate>,
                    ::std::is_convertible<I,Iterator>,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename I, typename P>
        filter_iterator(
            filter_iterator<I,P>&& other,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::std::is_convertible<P,Predicate>,
                    ::boost::mpl::false_,
                    ::std::is_convertible<I,Iterator>
                >::type,
                _enabler
            >::type = _enabler()
        );

        filter_iterator(Iterator const& itr, Predicate p);
        filter_iterator(Iterator const& itr);
        explicit filter_iterator(Predicate p);
        filter_iterator(filter_iterator const& other);
        filter_iterator(filter_iterator&& other);
        filter_iterator();
        ~filter_iterator();
        filter_iterator& operator=(filter_iterator const& other);
        filter_iterator& operator=(filter_iterator&& other);
        Iterator base() const;
        operator bool() const;
        reference operator*() const;
        pointer operator->() const;
        filter_iterator& operator++();
        filter_iterator operator++(int);
        filter_iterator& operator--();
        filter_iterator operator--(int);

    private:
        template <typename I1, typename P1, typename I2, typename P2>
        friend bool
            operator==(filter_iterator<I1,P1> const& lhs, filter_iterator<I2,P2> const& rhs);

        template <typename I, typename P>
        friend class filter_iterator;
    };
}}  // namespace odds_and_ends::node

#include <memory>
#include <utility>

namespace odds_and_ends { namespace node {

    template <typename Iterator, typename Predicate>
    inline filter_iterator<Iterator,Predicate>::filter_iterator() : _predicate(), _current_itr()
    {
    }

    template <typename Iterator, typename Predicate>
    filter_iterator<Iterator,Predicate>::filter_iterator(Iterator const& itr) :
        _predicate(), _current_itr(itr)
    {
        for (
            ;
            !(!this->_current_itr) && !this->_predicate(*this->_current_itr);
            ++this->_current_itr
        )
        {
        }
    }

    template <typename Iterator, typename Predicate>
    inline filter_iterator<Iterator,Predicate>::filter_iterator(Predicate p) :
        _predicate(p), _current_itr()
    {
    }

    template <typename Iterator, typename Predicate>
    filter_iterator<Iterator,Predicate>::filter_iterator(Iterator const& itr, Predicate p) :
        _predicate(p), _current_itr(itr)
    {
        for (
            ;
            !(!this->_current_itr) && !this->_predicate(*this->_current_itr);
            ++this->_current_itr
        )
        {
        }
    }

    template <typename Iterator, typename Predicate>
    inline filter_iterator<Iterator,Predicate>::filter_iterator(filter_iterator const& other) :
        _predicate(other._predicate), _current_itr(other._current_itr)
    {
    }

    template <typename Iterator, typename Predicate>
    template <typename I, typename P>
    inline filter_iterator<Iterator,Predicate>::filter_iterator(
        filter_iterator<I,P> const& other,
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::std::is_convertible<P,Predicate>,
                ::std::is_convertible<I,Iterator>,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _predicate(other._predicate), _current_itr(other._current_itr)
    {
    }

    template <typename Iterator, typename Predicate>
    template <typename I, typename P>
    inline filter_iterator<Iterator,Predicate>::filter_iterator(
        filter_iterator<I,P> const& other,
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::std::is_convertible<P,Predicate>,
                ::boost::mpl::false_,
                ::std::is_convertible<I,Iterator>
            >::type,
            _enabler
        >::type
    ) : _predicate(), _current_itr(other._current_itr)
    {
    }

    template <typename Iterator, typename Predicate>
    inline filter_iterator<Iterator,Predicate>::filter_iterator(filter_iterator&& other) :
        _predicate(other._predicate), _current_itr(::std::move(other._current_itr))
    {
    }

    template <typename Iterator, typename Predicate>
    template <typename I, typename P>
    inline filter_iterator<Iterator,Predicate>::filter_iterator(
        filter_iterator<I,P>&& other,
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::std::is_convertible<P,Predicate>,
                ::std::is_convertible<I,Iterator>,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _predicate(other._predicate), _current_itr(::std::move(other._current_itr))
    {
    }

    template <typename Iterator, typename Predicate>
    template <typename I, typename P>
    inline filter_iterator<Iterator,Predicate>::filter_iterator(
        filter_iterator<I,P>&& other,
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::std::is_convertible<P,Predicate>,
                ::boost::mpl::false_,
                ::std::is_convertible<I,Iterator>
            >::type,
            _enabler
        >::type
    ) : _predicate(), _current_itr(::std::move(other._current_itr))
    {
    }

    template <typename Iterator, typename Predicate>
    inline filter_iterator<Iterator,Predicate>::~filter_iterator()
    {
    }

    template <typename Iterator, typename Predicate>
    inline filter_iterator<Iterator,Predicate>&
        filter_iterator<Iterator,Predicate>::operator=(filter_iterator const& other)
    {
        if (this != &other)
        {
            this->_predicate = other._predicate;
            this->_current_itr = other._current_itr;
        }

        return *this;
    }

    template <typename Iterator, typename Predicate>
    inline filter_iterator<Iterator,Predicate>&
        filter_iterator<Iterator,Predicate>::operator=(filter_iterator&& other)
    {
        if (this != &static_cast<filter_iterator&>(other))
        {
            this->_predicate = other._predicate;
            this->_current_itr = ::std::move(other._current_itr);
        }

        return *this;
    }

    template <typename Iterator, typename Predicate>
    inline Iterator filter_iterator<Iterator,Predicate>::base() const
    {
        return this->_current_itr;
    }

    template <typename Iterator, typename Predicate>
    inline filter_iterator<Iterator,Predicate>::operator bool() const
    {
        return !(!this->_current_itr);
    }

    template <typename Iterator, typename Predicate>
    inline typename filter_iterator<Iterator,Predicate>::reference
        filter_iterator<Iterator,Predicate>::operator*() const
    {
        return *this->_current_itr;
    }

    template <typename Iterator, typename Predicate>
    inline typename filter_iterator<Iterator,Predicate>::pointer
        filter_iterator<Iterator,Predicate>::operator->() const
    {
        return ::std::pointer_traits<pointer>::pointer_to(*this->_current_itr);
    }

    template <typename Iterator, typename Predicate>
    filter_iterator<Iterator,Predicate>& filter_iterator<Iterator,Predicate>::operator++()
    {
        for (
            ++this->_current_itr;
            !(!this->_current_itr) && !this->_predicate(*this->_current_itr);
            ++this->_current_itr
        )
        {
        }

        return *this;
    }

    template <typename Iterator, typename Predicate>
    filter_iterator<Iterator,Predicate> filter_iterator<Iterator,Predicate>::operator++(int)
    {
        filter_iterator result(*this);
        ++(*this);
        return result;
    }

    template <typename Iterator, typename Predicate>
    filter_iterator<Iterator,Predicate>& filter_iterator<Iterator,Predicate>::operator--()
    {
        for (
            --this->_current_itr;
            !(!this->_current_itr) && !this->_predicate(*this->_current_itr);
            --this->_current_itr
        )
        {
        }

        return *this;
    }

    template <typename Iterator, typename Predicate>
    filter_iterator<Iterator,Predicate> filter_iterator<Iterator,Predicate>::operator--(int)
    {
        filter_iterator result(*this);
        --(*this);
        return result;
    }

    template <typename I1, typename P1, typename I2, typename P2>
    inline bool operator==(filter_iterator<I1,P1> const& lhs, filter_iterator<I2,P2> const& rhs)
    {
        return lhs._current_itr == rhs._current_itr;
    }

    template <typename I1, typename P1, typename I2, typename P2>
    inline bool operator!=(filter_iterator<I1,P1> const& lhs, filter_iterator<I2,P2> const& rhs)
    {
        return !(lhs == rhs);
    }
}}  // namespace odds_and_ends::node

#endif  // ODDS_AND_ENDS__NODE__ITERATOR__FILTER_HPP

