// Copyright (C) 2025-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__ITERATOR__TRANSFORM_HPP
#define ODDS_AND_ENDS__NODE__ITERATOR__TRANSFORM_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/nested_type/has_difference_type.hpp>
#include <odds_and_ends/static_introspection/invoke_result.hpp>
#include <odds_and_ends/static_introspection/remove_vref.hpp>
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
        typename UnFun,
        typename PtrXForm,
        typename IsConst,
        typename HasDiff = typename ::odds_and_ends::static_introspection
        ::nested_type::has_difference_type<Iterator>::type
    >
    class transform_iterator
    {
        struct _enabler
        {
        };

        typedef typename Iterator::reference _argument_type;

    public:
        typedef typename Iterator::iterator_category iterator_category;
        typedef typename Iterator::difference_type difference_type;
        typedef typename ::odds_and_ends::static_introspection
        ::invoke_result<UnFun,_argument_type>::type value_type;
        typedef typename ::boost::mpl::eval_if<
            IsConst,
            ::boost::mpl::apply_wrap1<PtrXForm,value_type const>,
            ::boost::mpl::apply_wrap1<PtrXForm,value_type>
        >::type pointer;
        typedef typename ::boost::mpl::if_<IsConst,value_type const&,value_type&>::type reference;

    private:
        class _proxy
        {
            transform_iterator _itr;

        public:
            _proxy(Iterator const& itr, difference_type const& n);

            operator transform_iterator&();
        };

        Iterator _current;
        UnFun _un_fun;
        value_type _value;

    public:
        template <typename Itr, typename UF, typename PX, typename IC, typename B>
        transform_iterator(
            transform_iterator<Itr,UF,PX,IC,B> const& other,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::std::is_convertible<UF,UnFun>,
                    ::std::is_convertible<Itr,Iterator>,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename Itr, typename UF, typename PX, typename IC, typename B>
        transform_iterator(
            transform_iterator<Itr,UF,PX,IC,B> const& other,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::std::is_convertible<UF,UnFun>,
                    ::boost::mpl::false_,
                    ::std::is_convertible<Itr,Iterator>
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename Itr, typename UF, typename PX, typename IC, typename B>
        transform_iterator(
            transform_iterator<Itr,UF,PX,IC,B>&& other,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::std::is_convertible<UF,UnFun>,
                    ::std::is_convertible<Itr,Iterator>,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename Itr, typename UF, typename PX, typename IC, typename B>
        transform_iterator(
            transform_iterator<Itr,UF,PX,IC,B>&& other,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::std::is_convertible<UF,UnFun>,
                    ::boost::mpl::false_,
                    ::std::is_convertible<Itr,Iterator>
                >::type,
                _enabler
            >::type = _enabler()
        );

        transform_iterator(transform_iterator const& other);
        transform_iterator(transform_iterator&& other);
        transform_iterator(Iterator const& itr, UnFun uf);
        transform_iterator(Iterator const& itr);
        explicit transform_iterator(UnFun uf);
        transform_iterator();
        ~transform_iterator();
        transform_iterator& operator=(transform_iterator const& other);
        transform_iterator& operator=(transform_iterator&& other);
        Iterator base() const;
        bool operator!() const;
        reference operator*() const;
        pointer operator->() const;
        _proxy operator[](difference_type const& n) const;
        transform_iterator& operator++();
        transform_iterator operator++(int);
        transform_iterator& operator--();
        transform_iterator operator--(int);
        transform_iterator& operator+=(difference_type const& n);
        transform_iterator& operator-=(difference_type const& n);

    private:
        template <typename Itr, typename UF, typename PX, typename IC, typename B>
        friend class transform_iterator;

        template <
            typename I1,
            typename U1,
            typename PX1,
            typename IC1,
            typename B1,
            typename I2,
            typename U2,
            typename PX2,
            typename IC2,
            typename B2
        >
        friend typename ::boost::enable_if< ::boost::mpl::equal_to<B1,B2>,bool>::type
            operator==(
                transform_iterator<I1,U1,PX1,IC1,B1> const& lhs,
                transform_iterator<I2,U2,PX2,IC2,B2> const& rhs
            );

        template <
            typename I1,
            typename U1,
            typename PX1,
            typename IC1,
            typename B1,
            typename I2,
            typename U2,
            typename PX2,
            typename IC2,
            typename B2
        >
        friend typename ::boost::enable_if<
            typename ::boost::mpl::if_<B1,B2,::boost::mpl::false_>::type,
            bool
        >::type
            operator<(
                transform_iterator<I1,U1,PX1,IC1,B1> const& lhs,
                transform_iterator<I2,U2,PX2,IC2,B2> const& rhs
            );

        template <
            typename I1,
            typename U1,
            typename PX1,
            typename IC1,
            typename B1,
            typename I2,
            typename U2,
            typename PX2,
            typename IC2,
            typename B2
        >
        friend typename ::std::common_type<
            typename transform_iterator<I1,U1,PX1,IC1,B1>::difference_type,
            typename transform_iterator<I2,U2,PX2,IC2,B2>::difference_type
        >::type
            operator-(
                transform_iterator<I1,U1,PX1,IC1,B1> const& lhs,
                transform_iterator<I2,U2,PX2,IC2,B2> const& rhs
            );
    };
}}  // namespace odds_and_ends::node

#include <utility>

namespace odds_and_ends { namespace node {

    template <typename Iterator, typename UnFun, typename PtrXForm, typename IsConst>
    class transform_iterator<Iterator,UnFun,PtrXForm,IsConst,::boost::mpl::false_>
    {
        struct _enabler
        {
        };

        typedef typename Iterator::reference _argument_type;

    public:
        typedef typename Iterator::iterator_category iterator_category;
        typedef typename ::odds_and_ends::static_introspection
        ::invoke_result<UnFun,_argument_type>::type value_type;
        typedef typename ::boost::mpl::eval_if<
            IsConst,
            ::boost::mpl::apply_wrap1<PtrXForm,value_type const>,
            ::boost::mpl::apply_wrap1<PtrXForm,value_type>
        >::type pointer;
        typedef typename ::boost::mpl::if_<IsConst,value_type const&,value_type&>::type reference;

    private:
        Iterator _current;
        UnFun _un_fun;
        value_type _value;

    public:
        template <typename Itr, typename UF, typename PX, typename IC, typename B>
        transform_iterator(
            transform_iterator<Itr,UF,PX,IC,B> const& other,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::std::is_convertible<UF,UnFun>,
                    ::std::is_convertible<Itr,Iterator>,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        ) : _current(other._current),
            _un_fun(other._un_fun),
            _value(!_current ? _un_fun() : _un_fun(*_current))
        {
        }

        template <typename Itr, typename UF, typename PX, typename IC, typename B>
        transform_iterator(
            transform_iterator<Itr,UF,PX,IC,B> const& other,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::std::is_convertible<UF,UnFun>,
                    ::boost::mpl::false_,
                    ::std::is_convertible<Itr,Iterator>
                >::type,
                _enabler
            >::type = _enabler()
        ) : _current(other._current),
            _un_fun(),
            _value(!_current ? _un_fun() : _un_fun(*_current))
        {
        }

        template <typename Itr, typename UF, typename PX, typename IC, typename B>
        transform_iterator(
            transform_iterator<Itr,UF,PX,IC,B>&& other,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::std::is_convertible<UF,UnFun>,
                    ::std::is_convertible<Itr,Iterator>,
                    ::boost::mpl::false_
                >::type,
                _enabler
            >::type = _enabler()
        ) : _current(::std::move(other._current)),
            _un_fun(other._un_fun),
            _value(!_current ? _un_fun() : _un_fun(*_current))
        {
        }

        template <typename Itr, typename UF, typename PX, typename IC, typename B>
        transform_iterator(
            transform_iterator<Itr,UF,PX,IC,B>&& other,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::std::is_convertible<UF,UnFun>,
                    ::boost::mpl::false_,
                    ::std::is_convertible<Itr,Iterator>
                >::type,
                _enabler
            >::type = _enabler()
        ) : _current(::std::move(other._current)),
            _un_fun(),
            _value(!_current ? _un_fun() : _un_fun(*_current))
        {
        }

        inline transform_iterator(transform_iterator const& other) :
            _current(other._current),
            _un_fun(other._un_fun),
            _value(!_current ? _un_fun() : _un_fun(*_current))
        {
        }

        inline transform_iterator(transform_iterator&& other) :
            _current(::std::move(other._current)),
            _un_fun(other._un_fun),
            _value(!_current ? _un_fun() : _un_fun(*_current))
        {
        }

        inline transform_iterator(Iterator const& itr, UnFun uf) :
            _current(itr), _un_fun(uf), _value(!_current ? uf() : uf(*_current))
        {
        }

        inline transform_iterator(Iterator const& itr) :
            _current(itr), _un_fun(), _value(!_current ? _un_fun() : _un_fun(*_current))
        {
        }

        inline explicit transform_iterator(UnFun uf) : _current(), _un_fun(uf), _value(uf())
        {
        }

        inline transform_iterator() : _current(), _un_fun(), _value(_un_fun())
        {
        }

        inline ~transform_iterator()
        {
        }

        inline transform_iterator& operator=(transform_iterator const& other)
        {
            if (this != &other)
            {
                this->_current = other._current;
                this->_un_fun = other._un_fun;
                this->_value = !this->_current ? this->_un_fun() : this->_un_fun(*this->_current);
            }

            return *this;
        }

        inline transform_iterator& operator=(transform_iterator&& other)
        {
            if (this != &static_cast<transform_iterator&>(other))
            {
                this->_current = ::std::move(other._current);
                this->_un_fun = other._un_fun;
                this->_value = !this->_current ? this->_un_fun() : this->_un_fun(*this->_current);
            }

            return *this;
        }

        inline Iterator base() const
        {
            return this->_current;
        }

        inline bool operator!() const
        {
            return !this->_current;
        }

        inline reference operator*() const
        {
            return const_cast<reference>(this->_value);
        }

        inline pointer operator->() const
        {
            return ::std::pointer_traits<pointer>::pointer_to(const_cast<reference>(this->_value));
        }

        inline transform_iterator& operator++()
        {
            ++this->_current;
            this->_value = !this->_current ? this->_un_fun() : this->_un_fun(*this->_current);
            return *this;
        }

        transform_iterator operator++(int)
        {
            transform_iterator itr(*this);
            ++(*this);
            return itr;
        }

        inline transform_iterator& operator--()
        {
            --this->_current;
            this->_value = !this->_current ? this->_un_fun() : this->_un_fun(*this->_current);
            return *this;
        }

        transform_iterator operator--(int)
        {
            transform_iterator itr(*this);
            --(*this);
            return itr;
        }

    private:
        template <typename Itr, typename UF, typename PX, typename IC, typename B>
        friend class transform_iterator;

        template <
            typename I1,
            typename U1,
            typename PX1,
            typename IC1,
            typename B1,
            typename I2,
            typename U2,
            typename PX2,
            typename IC2,
            typename B2
        >
        friend typename ::boost::enable_if< ::boost::mpl::equal_to<B1,B2>,bool>::type
            operator==(
                transform_iterator<I1,U1,PX1,IC1,B1> const& lhs,
                transform_iterator<I2,U2,PX2,IC2,B2> const& rhs
            );
    };

    template <typename Itr, typename UF, typename PX, typename IC, typename B>
    transform_iterator<Itr,UF,PX,IC,B>::_proxy::_proxy(Itr const& itr, difference_type const& n) :
        _itr(itr)
    {
        this->_itr += n;
    }

    template <typename Itr, typename UnFun, typename PtrXForm, typename IC, typename HD>
    inline transform_iterator<Itr,UnFun,PtrXForm,IC,HD>::_proxy::operator transform_iterator&()
    {
        return this->_itr;
    }

    template <typename Iterator, typename UnFun, typename PtrXForm, typename IsConst, typename HD>
    inline transform_iterator<Iterator,UnFun,PtrXForm,IsConst,HD>::transform_iterator() :
        _current(), _un_fun(), _value(_un_fun())
    {
    }

    template <typename Itr, typename UnFun, typename PtrXForm, typename IsConst, typename HD>
    transform_iterator<Itr,UnFun,PtrXForm,IsConst,HD>::transform_iterator(Itr const& itr) :
        _current(itr), _un_fun(), _value(!_current ? _un_fun() : _un_fun(*_current))
    {
    }

    template <typename Iterator, typename UnFun, typename PtrXForm, typename IsConst, typename HD>
    inline transform_iterator<Iterator,UnFun,PtrXForm,IsConst,HD>::transform_iterator(UnFun uf) :
        _current(), _un_fun(uf), _value(uf())
    {
    }

    template <typename Itr, typename UnFun, typename PtrXForm, typename IC, typename B>
    transform_iterator<Itr,UnFun,PtrXForm,IC,B>::transform_iterator(Itr const& itr, UnFun uf) :
        _current(itr), _un_fun(uf), _value(!_current ? uf() : uf(*_current))
    {
    }

    template <typename Iterator, typename UnFun, typename PtrXForm, typename IsConst, typename HD>
    inline transform_iterator<Iterator,UnFun,PtrXForm,IsConst,HD>::transform_iterator(
        transform_iterator const& other
    ) : _current(other._current),
        _un_fun(other._un_fun),
        _value(!_current ? _un_fun() : _un_fun(*_current))
    {
    }

    template <typename Iterator, typename UnFun, typename PtrXForm, typename IsConst, typename HD>
    template <typename Itr, typename UF, typename PX, typename IC, typename B>
    inline transform_iterator<Iterator,UnFun,PtrXForm,IsConst,HD>::transform_iterator(
        transform_iterator<Itr,UF,PX,IC,B> const& other,
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::std::is_convertible<UF,UnFun>,
                ::std::is_convertible<Itr,Iterator>,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _current(other._current),
        _un_fun(other._un_fun),
        _value(!_current ? _un_fun() : _un_fun(*_current))
    {
    }

    template <typename Iterator, typename UnFun, typename PtrXForm, typename IsConst, typename HD>
    template <typename Itr, typename UF, typename PX, typename IC, typename B>
    inline transform_iterator<Iterator,UnFun,PtrXForm,IsConst,HD>::transform_iterator(
        transform_iterator<Itr,UF,PX,IC,B> const& other,
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::std::is_convertible<UF,UnFun>,
                ::boost::mpl::false_,
                ::std::is_convertible<Itr,Iterator>
            >::type,
            _enabler
        >::type
    ) : _current(other._current),
        _un_fun(),
        _value(!_current ? _un_fun() : _un_fun(*_current))
    {
    }

    template <typename Itr, typename UF, typename PX, typename IC, typename B>
    inline transform_iterator<Itr,UF,PX,IC,B>::transform_iterator(transform_iterator&& other) :
        _current(::std::move(other._current)),
        _un_fun(other._un_fun),
        _value(!_current ? _un_fun() : _un_fun(*_current))
    {
    }

    template <typename Iterator, typename UnFun, typename PtrXForm, typename IsConst, typename HD>
    template <typename Itr, typename UF, typename PX, typename IC, typename B>
    inline transform_iterator<Iterator,UnFun,PtrXForm,IsConst,HD>::transform_iterator(
        transform_iterator<Itr,UF,PX,IC,B>&& other,
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::std::is_convertible<UF,UnFun>,
                ::std::is_convertible<Itr,Iterator>,
                ::boost::mpl::false_
            >::type,
            _enabler
        >::type
    ) : _current(::std::move(other._current)),
        _un_fun(other._un_fun),
        _value(!_current ? _un_fun() : _un_fun(*_current))
    {
    }

    template <typename Iterator, typename UnFun, typename PtrXForm, typename IsConst, typename HD>
    template <typename Itr, typename UF, typename PX, typename IC, typename B>
    inline transform_iterator<Iterator,UnFun,PtrXForm,IsConst,HD>::transform_iterator(
        transform_iterator<Itr,UF,PX,IC,B>&& other,
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::std::is_convertible<UF,UnFun>,
                ::boost::mpl::false_,
                ::std::is_convertible<Itr,Iterator>
            >::type,
            _enabler
        >::type
    ) : _current(::std::move(other._current)),
        _un_fun(),
        _value(!_current ? _un_fun() : _un_fun(*_current))
    {
    }

    template <typename Iterator, typename UnFun, typename PtrXForm, typename IsConst, typename HD>
    inline transform_iterator<Iterator,UnFun,PtrXForm,IsConst,HD>::~transform_iterator()
    {
    }

    template <typename Itr, typename UnFun, typename PX, typename IsConst, typename HD>
    inline transform_iterator<Itr,UnFun,PX,IsConst,HD>&
        transform_iterator<Itr,UnFun,PX,IsConst,HD>::operator=(transform_iterator const& other)
    {
        if (this != &other)
        {
            this->_current = other._current;
            this->_un_fun = other._un_fun;
            this->_value = !this->_current ? this->_un_fun() : this->_un_fun(*this->_current);
        }

        return *this;
    }

    template <typename Iterator, typename UnFun, typename PX, typename IsConst, typename HD>
    inline transform_iterator<Iterator,UnFun,PX,IsConst,HD>&
        transform_iterator<Iterator,UnFun,PX,IsConst,HD>::operator=(transform_iterator&& other)
    {
        if (this != &static_cast<transform_iterator&>(other))
        {
            this->_current = ::std::move(other._current);
            this->_un_fun = other._un_fun;
            this->_value = !this->_current ? this->_un_fun() : this->_un_fun(*this->_current);
        }

        return *this;
    }

    template <typename Iterator, typename UnFun, typename PtrXForm, typename IsConst, typename HD>
    inline Iterator transform_iterator<Iterator,UnFun,PtrXForm,IsConst,HD>::base() const
    {
        return this->_current;
    }

    template <typename Iterator, typename UnFun, typename PtrXForm, typename IsConst, typename HD>
    inline bool transform_iterator<Iterator,UnFun,PtrXForm,IsConst,HD>::operator!() const
    {
        return !this->_current;
    }

    template <typename Iterator, typename UnFun, typename PtrXForm, typename IsConst, typename HD>
    inline typename transform_iterator<Iterator,UnFun,PtrXForm,IsConst,HD>::reference
        transform_iterator<Iterator,UnFun,PtrXForm,IsConst,HD>::operator*() const
    {
        return const_cast<reference>(this->_value);
    }

    template <typename Iterator, typename UnFun, typename PtrXForm, typename IsConst, typename HD>
    inline typename transform_iterator<Iterator,UnFun,PtrXForm,IsConst,HD>::pointer
        transform_iterator<Iterator,UnFun,PtrXForm,IsConst,HD>::operator->() const
    {
        return ::std::pointer_traits<pointer>::pointer_to(const_cast<reference>(this->_value));
    }

    template <typename Itr, typename UnFun, typename PX, typename IsConst, typename HD>
    inline typename transform_iterator<Itr,UnFun,PX,IsConst,HD>::_proxy
        transform_iterator<Itr,UnFun,PX,IsConst,HD>::operator[](difference_type const& n) const
    {
        return _proxy(this->_current, n);
    }

    template <typename Itr, typename UF, typename PX, typename IC, typename B>
    inline transform_iterator<Itr,UF,PX,IC,B>& transform_iterator<Itr,UF,PX,IC,B>::operator++()
    {
        ++this->_current;
        this->_value = !this->_current ? this->_un_fun() : this->_un_fun(*this->_current);
        return *this;
    }

    template <typename Itr, typename UF, typename PX, typename IC, typename B>
    transform_iterator<Itr,UF,PX,IC,B> transform_iterator<Itr,UF,PX,IC,B>::operator++(int)
    {
        transform_iterator itr(*this);
        ++(*this);
        return itr;
    }

    template <typename Itr, typename UF, typename PX, typename IC, typename B>
    inline transform_iterator<Itr,UF,PX,IC,B>& transform_iterator<Itr,UF,PX,IC,B>::operator--()
    {
        --this->_current;
        this->_value = !this->_current ? this->_un_fun() : this->_un_fun(*this->_current);
        return *this;
    }

    template <typename Itr, typename UF, typename PX, typename IC, typename B>
    transform_iterator<Itr,UF,PX,IC,B> transform_iterator<Itr,UF,PX,IC,B>::operator--(int)
    {
        transform_iterator itr(*this);
        --(*this);
        return itr;
    }

    template <typename Iterator, typename UnFun, typename PX, typename IsConst, typename HD>
    inline transform_iterator<Iterator,UnFun,PX,IsConst,HD>&
        transform_iterator<Iterator,UnFun,PX,IsConst,HD>::operator+=(difference_type const& n)
    {
        this->_current += n;
        this->_value = !this->_current ? this->_un_fun() : this->_un_fun(*this->_current);
        return *this;
    }

    template <typename Iterator, typename UnFun, typename PX, typename IsConst, typename HD>
    transform_iterator<Iterator,UnFun,PX,IsConst,HD>
        operator+(
            transform_iterator<Iterator,UnFun,PX,IsConst,HD> const& operand,
            typename transform_iterator<Iterator,UnFun,PX,IsConst,HD>::difference_type const& n
        )
    {
        transform_iterator<Iterator,UnFun,PX,IsConst,HD> itr(operand);
        itr += n;
        return itr;
    }

    template <typename Iterator, typename UnFun, typename PX, typename IsConst, typename HD>
    transform_iterator<Iterator,UnFun,PX,IsConst,HD>
        operator+(
            typename transform_iterator<Iterator,UnFun,PX,IsConst,HD>::difference_type const& n,
            transform_iterator<Iterator,UnFun,PX,IsConst,HD> const& operand
        )
    {
        transform_iterator<Iterator,UnFun,PX,IsConst,HD> itr(operand);
        itr += n;
        return itr;
    }

    template <typename Iterator, typename UnFun, typename PX, typename IsConst, typename HD>
    inline transform_iterator<Iterator,UnFun,PX,IsConst,HD>&
        transform_iterator<Iterator,UnFun,PX,IsConst,HD>::operator-=(difference_type const& n)
    {
        this->_current -= n;
        this->_value = !this->_current ? this->_un_fun() : this->_un_fun(*this->_current);
        return *this;
    }

    template <typename Iterator, typename UnFun, typename PX, typename IsConst, typename HD>
    transform_iterator<Iterator,UnFun,PX,IsConst,HD>
        operator-(
            transform_iterator<Iterator,UnFun,PX,IsConst,HD> const& operand,
            typename transform_iterator<Iterator,UnFun,PX,IsConst,HD>::difference_type const& n
        )
    {
        transform_iterator<Iterator,UnFun,PX,IsConst,HD> itr(operand);
        itr -= n;
        return itr;
    }

    template <
        typename I1,
        typename U1,
        typename PX1,
        typename IC1,
        typename B1,
        typename I2,
        typename U2,
        typename PX2,
        typename IC2,
        typename B2
    >
    inline typename ::boost::enable_if< ::boost::mpl::equal_to<B1,B2>,bool>::type
        operator==(
            transform_iterator<I1,U1,PX1,IC1,B1> const& lhs,
            transform_iterator<I2,U2,PX2,IC2,B2> const& rhs
        )
    {
        return !lhs._current ? !rhs._current : (lhs._current == rhs._current);
    }

    template <
        typename I1,
        typename U1,
        typename PX1,
        typename IC1,
        typename B1,
        typename I2,
        typename U2,
        typename PX2,
        typename IC2,
        typename B2
    >
    inline typename ::boost::enable_if< ::boost::mpl::equal_to<B1,B2>,bool>::type
        operator!=(
            transform_iterator<I1,U1,PX1,IC1,B1> const& lhs,
            transform_iterator<I2,U2,PX2,IC2,B2> const& rhs
        )
    {
        return !(lhs == rhs);
    }

    template <
        typename I1,
        typename U1,
        typename PX1,
        typename IC1,
        typename B1,
        typename I2,
        typename U2,
        typename PX2,
        typename IC2,
        typename B2
    >
    inline typename ::boost::enable_if<
        typename ::boost::mpl::if_<B1,B2,::boost::mpl::false_>::type,
        bool
    >::type
        operator<(
            transform_iterator<I1,U1,PX1,IC1,B1> const& lhs,
            transform_iterator<I2,U2,PX2,IC2,B2> const& rhs
        )
    {
        return lhs._current < rhs._current;
    }

    template <
        typename I1,
        typename U1,
        typename PX1,
        typename IC1,
        typename B1,
        typename I2,
        typename U2,
        typename PX2,
        typename IC2,
        typename B2
    >
    inline typename ::boost::enable_if<
        typename ::boost::mpl::if_<B1,B2,::boost::mpl::false_>::type,
        bool
    >::type
        operator>(
            transform_iterator<I1,U1,PX1,IC1,B1> const& lhs,
            transform_iterator<I2,U2,PX2,IC2,B2> const& rhs
        )
    {
        return rhs < lhs;
    }

    template <
        typename I1,
        typename U1,
        typename PX1,
        typename IC1,
        typename B1,
        typename I2,
        typename U2,
        typename PX2,
        typename IC2,
        typename B2
    >
    inline typename ::boost::enable_if<
        typename ::boost::mpl::if_<B1,B2,::boost::mpl::false_>::type,
        bool
    >::type
        operator<=(
            transform_iterator<I1,U1,PX1,IC1,B1> const& lhs,
            transform_iterator<I2,U2,PX2,IC2,B2> const& rhs
        )
    {
        return !(rhs < lhs);
    }

    template <
        typename I1,
        typename U1,
        typename PX1,
        typename IC1,
        typename B1,
        typename I2,
        typename U2,
        typename PX2,
        typename IC2,
        typename B2
    >
    inline typename ::boost::enable_if<
        typename ::boost::mpl::if_<B1,B2,::boost::mpl::false_>::type,
        bool
    >::type
        operator>=(
            transform_iterator<I1,U1,PX1,IC1,B1> const& lhs,
            transform_iterator<I2,U2,PX2,IC2,B2> const& rhs
        )
    {
        return !(lhs < rhs);
    }

    template <
        typename I1,
        typename U1,
        typename PX1,
        typename IC1,
        typename B1,
        typename I2,
        typename U2,
        typename PX2,
        typename IC2,
        typename B2
    >
    inline typename ::std::common_type<
        typename transform_iterator<I1,U1,PX1,IC1,B1>::difference_type,
        typename transform_iterator<I2,U2,PX2,IC2,B2>::difference_type
    >::type
        operator-(
            transform_iterator<I1,U1,PX1,IC1,B1> const& lhs,
            transform_iterator<I2,U2,PX2,IC2,B2> const& rhs
        )
    {
        return lhs._current - rhs._current;
    }
}}  // namespace odds_and_ends::node

#endif  // ODDS_AND_ENDS__NODE__ITERATOR__TRANSFORM_HPP

