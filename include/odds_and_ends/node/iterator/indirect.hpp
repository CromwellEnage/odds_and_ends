// Copyright (C) 2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__ITERATOR__INDIRECT_HPP
#define ODDS_AND_ENDS__NODE__ITERATOR__INDIRECT_HPP

#include <type_traits>
#include <iterator>
#include <boost/core/enable_if.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace node {

    template <typename Iterator>
    class indirect_iterator
    {
        struct _enabler
        {
        };

        typedef typename Iterator::value_type _node_t;
        typedef typename ::std::remove_const<_node_t>::type::traits::value_type _value_t;

    public:
        typedef typename Iterator::iterator_category iterator_category;
        typedef typename Iterator::difference_type difference_type;
        typedef typename ::boost::mpl::if_<
            ::std::is_const<_node_t>,
            _value_t const,
            _value_t
        >::type value_type;
        typedef value_type* pointer;
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
        template <typename Itr>
        indirect_iterator(
            indirect_iterator<Itr> const& other,
            typename ::boost::enable_if<
                ::std::is_convertible<Itr,Iterator>,
                _enabler
            >::type = _enabler()
        );

        template <typename Itr>
        indirect_iterator(
            indirect_iterator<Itr>&& other,
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
        template <typename Itr>
        friend class indirect_iterator;

        template <typename Itr1, typename Itr2>
        friend bool
            operator==(indirect_iterator<Itr1> const& lhs, indirect_iterator<Itr2> const& rhs);

        template <typename Itr1, typename Itr2>
        friend bool
            operator<(indirect_iterator<Itr1> const& lhs, indirect_iterator<Itr2> const& rhs);

        template <typename Itr1, typename Itr2>
        friend ::std::common_type<
            typename indirect_iterator<Itr1>::difference_type,
            typename indirect_iterator<Itr2>::difference_type
        >
            operator-(indirect_iterator<Itr1> const& lhs, indirect_iterator<Itr2> const& rhs);
    };
}}  // namespace odds_and_ends::node

#include <utility>

namespace odds_and_ends { namespace node {

    template <typename Iterator>
    indirect_iterator<Iterator>::_proxy::_proxy(Iterator const& itr, difference_type const& n) :
        _itr(itr)
    {
        this->_itr += n;
    }

    template <typename Iterator>
    inline indirect_iterator<Iterator>::_proxy::operator indirect_iterator&()
    {
        return this->_itr;
    }

    template <typename Iterator>
    indirect_iterator<Iterator>::indirect_iterator() : _current()
    {
    }

    template <typename Iterator>
    indirect_iterator<Iterator>::indirect_iterator(Iterator const& itr) : _current(itr)
    {
    }

    template <typename Iterator>
    inline indirect_iterator<Iterator>::indirect_iterator(indirect_iterator const& other) :
        _current(other._current)
    {
    }

    template <typename Iterator>
    template <typename Itr>
    inline indirect_iterator<Iterator>::indirect_iterator(
        indirect_iterator<Itr> const& other,
        typename ::boost::enable_if<
            ::std::is_convertible<Itr,Iterator>,
            _enabler
        >::type
    ) : _current(other._current)
    {
    }

    template <typename Iterator>
    inline indirect_iterator<Iterator>::indirect_iterator(indirect_iterator&& other) :
        _current(::std::move(other._current))
    {
    }

    template <typename Iterator>
    template <typename Itr>
    inline indirect_iterator<Iterator>::indirect_iterator(
        indirect_iterator<Itr>&& other,
        typename ::boost::enable_if<
            ::std::is_convertible<Itr,Iterator>,
            _enabler
        >::type
    ) : _current(::std::move(other._current))
    {
    }

    template <typename Iterator>
    inline indirect_iterator<Iterator>::~indirect_iterator()
    {
    }

    template <typename Iterator>
    inline indirect_iterator<Iterator>&
        indirect_iterator<Iterator>::operator=(indirect_iterator const& other)
    {
        if (this != &other)
        {
            this->_current = other._current;
        }

        return *this;
    }

    template <typename Iterator>
    inline indirect_iterator<Iterator>&
        indirect_iterator<Iterator>::operator=(indirect_iterator&& other)
    {
        if (this != &static_cast<indirect_iterator&>(other))
        {
            this->_current = ::std::move(other._current);
        }

        return *this;
    }

    template <typename Iterator>
    inline Iterator indirect_iterator<Iterator>::base() const
    {
        return this->_current;
    }

    template <typename Iterator>
    inline typename indirect_iterator<Iterator>::reference
        indirect_iterator<Iterator>::operator*() const
    {
        return **this->_current;
    }

    template <typename Iterator>
    inline typename indirect_iterator<Iterator>::pointer
        indirect_iterator<Iterator>::operator->() const
    {
        return &**this->_current;
    }

    template <typename Iterator>
    inline typename indirect_iterator<Iterator>::_proxy
        indirect_iterator<Iterator>::operator[](difference_type const& n) const
    {
        return _proxy(this->_current, n);
    }

    template <typename Iterator>
    inline indirect_iterator<Iterator>& indirect_iterator<Iterator>::operator++()
    {
        ++this->_current;
        return *this;
    }

    template <typename Iterator>
    indirect_iterator<Iterator> indirect_iterator<Iterator>::operator++(int)
    {
        indirect_iterator itr(*this);
        ++this->_current;
        return itr;
    }

    template <typename Iterator>
    inline indirect_iterator<Iterator>& indirect_iterator<Iterator>::operator--()
    {
        --this->_current;
        return *this;
    }

    template <typename Iterator>
    indirect_iterator<Iterator> indirect_iterator<Iterator>::operator--(int)
    {
        indirect_iterator itr(*this);
        --this->_current;
        return itr;
    }

    template <typename Iterator>
    inline indirect_iterator<Iterator>&
        indirect_iterator<Iterator>::operator+=(difference_type const& n)
    {
        this->_current += n;
        return *this;
    }

    template <typename Iterator>
    indirect_iterator<Iterator>
        operator+(
            indirect_iterator<Iterator> const& operand,
            typename indirect_iterator<Iterator>::difference_type const& n
        )
    {
        indirect_iterator<Iterator> itr(operand);
        itr += n;
        return itr;
    }

    template <typename Iterator>
    indirect_iterator<Iterator>
        operator+(
            typename indirect_iterator<Iterator>::difference_type const& n,
            indirect_iterator<Iterator> const& operand
        )
    {
        indirect_iterator<Iterator> itr(operand);
        itr += n;
        return itr;
    }

    template <typename Iterator>
    inline indirect_iterator<Iterator>&
        indirect_iterator<Iterator>::operator-=(difference_type const& n)
    {
        this->_current -= n;
        return *this;
    }

    template <typename Iterator>
    indirect_iterator<Iterator>
        operator-(
            indirect_iterator<Iterator> const& operand,
            typename indirect_iterator<Iterator>::difference_type const& n
        )
    {
        indirect_iterator<Iterator> itr(operand);
        itr -= n;
        return itr;
    }

    template <typename Itr1, typename Itr2>
    inline bool
        operator==(indirect_iterator<Itr1> const& lhs, indirect_iterator<Itr2> const& rhs)
    {
        return lhs._current == rhs._current;
    }

    template <typename Itr1, typename Itr2>
    inline bool
        operator!=(indirect_iterator<Itr1> const& lhs, indirect_iterator<Itr2> const& rhs)
    {
        return !(lhs == rhs);
    }

    template <typename Itr1, typename Itr2>
    inline bool
        operator<(indirect_iterator<Itr1> const& lhs, indirect_iterator<Itr2> const& rhs)
    {
        return lhs._current < rhs._current;
    }

    template <typename Itr1, typename Itr2>
    inline bool
        operator>(indirect_iterator<Itr1> const& lhs, indirect_iterator<Itr2> const& rhs)
    {
        return rhs < lhs;
    }

    template <typename Itr1, typename Itr2>
    inline bool
        operator<=(indirect_iterator<Itr1> const& lhs, indirect_iterator<Itr2> const& rhs)
    {
        return !(rhs < lhs);
    }

    template <typename Itr1, typename Itr2>
    inline bool
        operator>=(indirect_iterator<Itr1> const& lhs, indirect_iterator<Itr2> const& rhs)
    {
        return !(lhs < rhs);
    }

    template <typename Itr1, typename Itr2>
    inline ::std::common_type<
        typename indirect_iterator<Itr1>::difference_type,
        typename indirect_iterator<Itr2>::difference_type
    >
        operator-(indirect_iterator<Itr1> const& lhs, indirect_iterator<Itr2> const& rhs)
    {
        return lhs._current - rhs._current;
    }
}}  // namespace odds_and_ends::node

#endif  // ODDS_AND_ENDS__NODE__ITERATOR__INDIRECT_HPP

