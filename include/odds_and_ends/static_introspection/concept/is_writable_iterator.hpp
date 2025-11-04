// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_WRITABLE_ITERATOR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_WRITABLE_ITERATOR_HPP

#include <type_traits>
#include <utility>
#include <odds_and_ends/static_introspection/declref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename Value>
    class has_writable_iterator_operator
    {
        template <typename B, typename V>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(
                        *::odds_and_ends::static_introspection::declmref<B>() = ::std::declval<V>()
                    )
                >::type
            );

        template <typename B, typename V>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::concept::_detail
                ::has_writable_iterator_operator<T,Value>::template _check<T,Value>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename Value>
    struct is_writable_iterator_ext :
        ::boost::mpl::eval_if<
            ::std::is_constructible<T>,
            ::boost::mpl::eval_if<
                ::std::is_void<Value>,
                ::boost::mpl::false_,
                ::odds_and_ends::static_introspection::concept
                ::_detail::has_writable_iterator_operator<T,Value>
            >,
            ::boost::mpl::false_
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <odds_and_ends/static_introspection/iterator_value_of.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <
        typename T,
        typename Value = typename ::odds_and_ends
        ::static_introspection::iterator_value_of<T>::type
    >
    struct is_writable_iterator :
        ::odds_and_ends::static_introspection::concept::is_writable_iterator_ext<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type,
            Value
        >
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename Value>
    struct is_writable_iterator :
        ::boost::mpl::eval_if<
            ::std::is_same<Value,::odds_and_ends::use_default_policy>,
            ::odds_and_ends::static_introspection
            ::concept::_detail::is_writable_iterator<T>,
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_writable_iterator<T,Value>
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#include <boost/iterator/indirect_iterator.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename I, typename V, typename C, typename R, typename D, typename Value>
    struct is_writable_iterator_ext< ::boost::iterators::indirect_iterator<I,V,C,R,D>,Value> :
        ::odds_and_ends::static_introspection::concept::is_writable_iterator<I,Value>
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#include <boost/iterator/transform_iterator.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename U, typename I, typename R, typename V, typename Value>
    struct is_writable_iterator_ext<
        ::boost::iterators::transform_iterator<U,I,R,V>,
        Value
    > : ::odds_and_ends::static_introspection::concept::is_writable_iterator<I,Value>
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_WRITABLE_ITERATOR_HPP

