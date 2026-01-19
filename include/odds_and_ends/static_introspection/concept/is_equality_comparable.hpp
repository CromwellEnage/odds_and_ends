// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_EQUALITY_COMPARABLE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_EQUALITY_COMPARABLE_HPP

#include <utility>
#include <odds_and_ends/static_introspection/concept/is_boolean_expression.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename U>
    struct is_equality_comparable_impl :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::concept::is_boolean_expression<
                decltype(::std::declval<T>() == ::std::declval<U>())
            >,
            ::odds_and_ends::static_introspection::concept::is_boolean_expression<
                decltype(::std::declval<T>() != ::std::declval<U>())
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <type_traits>
#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename U>
    class has_equality_comparable_operators
    {
        template <typename L, typename R>
        static ::boost::type_traits::yes_type
            _check_eq(
                typename ::std::add_pointer<
                    decltype(::std::declval<L>() == ::std::declval<R>())
                >::type
            );

        template <typename L, typename R>
        static ::boost::type_traits::no_type _check_eq(...);

        template <typename L, typename R>
        static ::boost::type_traits::yes_type
            _check_neq(
                typename ::std::add_pointer<
                    decltype(::std::declval<L>() != ::std::declval<R>())
                >::type
            );

        template <typename L, typename R>
        static ::boost::type_traits::no_type _check_neq(...);

    public:
        typedef ::boost::mpl::bool_<
            (
                sizeof(
                    ::odds_and_ends::static_introspection::concept::_detail
                    ::has_equality_comparable_operators<T,U>::template _check_eq<T,U>(nullptr)
                ) == sizeof(::boost::type_traits::yes_type)
            ) && (
                sizeof(
                    ::odds_and_ends::static_introspection::concept::_detail
                    ::has_equality_comparable_operators<T,U>::template _check_neq<T,U>(nullptr)
                ) == sizeof(::boost::type_traits::yes_type)
            )
        > type;
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename U>
    struct is_equality_comparable :
        ::boost::mpl::eval_if<
            typename ::boost::mpl::eval_if<
                typename ::odds_and_ends::static_introspection::concept
                ::_detail::has_equality_comparable_operators<T,U>::type,
                ::odds_and_ends::static_introspection::concept
                ::_detail::has_equality_comparable_operators<U,T>,
                ::boost::mpl::false_
            >::type,
            ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_equality_comparable_impl<T,U>,
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_equality_comparable_impl<U,T>,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#include <odds_and_ends/use_default_policy.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_equality_comparable<T,::odds_and_ends::use_default_policy> :
        ::boost::mpl::eval_if<
            typename ::odds_and_ends::static_introspection::concept
            ::_detail::has_equality_comparable_operators<T,T>::type,
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_equality_comparable_impl<T,T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#include <boost/range/adaptor/adjacent_filtered.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename Range, typename BinaryPredicate, bool b>
    struct is_equality_comparable<
        ::boost::adjacent_filtered_range<Range,BinaryPredicate,b>,
        ::odds_and_ends::use_default_policy
    > : ::boost::mpl::true_
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_EQUALITY_COMPARABLE_HPP

