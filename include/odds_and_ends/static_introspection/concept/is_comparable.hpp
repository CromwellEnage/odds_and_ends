// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_COMPARABLE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_COMPARABLE_HPP

#include <utility>
#include <odds_and_ends/static_introspection/concept/is_boolean_expression.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename U>
    struct is_comparable_impl :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::is_boolean_expression<
                decltype(::std::declval<T>() <= ::std::declval<U>())
            >,
            ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::concept::is_boolean_expression<
                    decltype(::std::declval<T>() >= ::std::declval<U>())
                >,
                ::odds_and_ends::static_introspection::concept::is_boolean_expression<
                    decltype(::std::declval<T>() > ::std::declval<U>())
                >,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <type_traits>
#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename U>
    class has_comparable_operators
    {
        template <typename L, typename R>
        static ::boost::type_traits::yes_type
            _check_le(
                typename ::std::add_pointer<
                    decltype(::std::declval<L>() <= ::std::declval<R>())
                >::type
            );

        template <typename L, typename R>
        static ::boost::type_traits::no_type _check_le(...);

        template <typename L, typename R>
        static ::boost::type_traits::yes_type
            _check_gt(
                typename ::std::add_pointer<
                    decltype(::std::declval<L>() > ::std::declval<R>())
                >::type
            );

        template <typename L, typename R>
        static ::boost::type_traits::no_type _check_gt(...);

        template <typename L, typename R>
        static ::boost::type_traits::yes_type
            _check_ge(
                typename ::std::add_pointer<
                    decltype(::std::declval<L>() >= ::std::declval<R>())
                >::type
            );

        template <typename L, typename R>
        static ::boost::type_traits::no_type _check_ge(...);

    public:
        typedef typename ::boost::mpl::eval_if_c<
            (
                sizeof(
                    ::odds_and_ends::static_introspection::concept::_detail
                    ::has_comparable_operators<T,U>::template _check_le<T,U>(nullptr)
                ) == sizeof(::boost::type_traits::yes_type)
            ) && (
                sizeof(
                    ::odds_and_ends::static_introspection::concept::_detail
                    ::has_comparable_operators<T,U>::template _check_gt<T,U>(nullptr)
                ) == sizeof(::boost::type_traits::yes_type)
            ) && (
                sizeof(
                    ::odds_and_ends::static_introspection::concept::_detail
                    ::has_comparable_operators<T,U>::template _check_ge<T,U>(nullptr)
                ) == sizeof(::boost::type_traits::yes_type)
            ),
            ::odds_and_ends::static_introspection::concept::_detail::is_comparable_impl<T,U>,
            ::boost::mpl::false_
        >::type type;
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/is_less_than_comparable.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename U>
    struct is_comparable :
        ::boost::mpl::eval_if<
            typename ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept::is_less_than_comparable<T,U>,
                ::odds_and_ends::static_introspection::concept
                ::_detail::has_comparable_operators<T,U>,
                ::boost::mpl::false_
            >::type,
            ::odds_and_ends::static_introspection::concept
            ::_detail::has_comparable_operators<U,T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#include <odds_and_ends/use_default_policy.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_comparable<T,::odds_and_ends::use_default_policy> :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::is_less_than_comparable<T>,
            ::odds_and_ends::static_introspection::concept
            ::_detail::has_comparable_operators<T,T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_COMPARABLE_HPP

