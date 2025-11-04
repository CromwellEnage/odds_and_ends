// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_LESS_THAN_COMPARABLE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_LESS_THAN_COMPARABLE_HPP

#include <utility>
#include <odds_and_ends/static_introspection/concept/is_boolean_expression.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename U>
    struct is_less_than_comparable_impl :
        ::odds_and_ends::static_introspection::concept::is_boolean_expression<
            decltype(::std::declval<T>() < ::std::declval<U>())
        >
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <type_traits>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename U>
    class has_less_than_comparable_operator
    {
        template <typename L, typename R>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(::boost::declval<L>() < ::boost::declval<R>())
                >::type
            );

        template <typename L, typename R>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::concept::_detail
                ::has_less_than_comparable_operator<T,U>::template _check<T,U>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename U>
    struct is_less_than_comparable :
        ::boost::mpl::eval_if<
            typename ::boost::mpl::eval_if<
                typename ::odds_and_ends::static_introspection::concept
                ::_detail::has_less_than_comparable_operator<T,U>::type,
                ::odds_and_ends::static_introspection::concept
                ::_detail::has_less_than_comparable_operator<U,T>,
                ::boost::mpl::false_
            >::type,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_less_than_comparable_impl<T,U>,
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_less_than_comparable_impl<U,T>,
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
    struct is_less_than_comparable<T,::odds_and_ends::use_default_policy> :
        ::boost::mpl::eval_if<
            typename ::odds_and_ends::static_introspection::concept
            ::_detail::has_less_than_comparable_operator<T,T>::type,
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_less_than_comparable_impl<T,T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_LESS_THAN_COMPARABLE_HPP

