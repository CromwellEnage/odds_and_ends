// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MATH_INTEGRAL_TYPE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MATH_INTEGRAL_TYPE_HPP

#include <odds_and_ends/static_introspection/concept/is_math_real_type.hpp>
#include <odds_and_ends/static_introspection/concept/is_modulus_operable.hpp>
#include <odds_and_ends/static_introspection/concept/is_incrementable.hpp>
#include <odds_and_ends/static_introspection/concept/is_decrementable.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename PlaceholderExpr>
    struct is_math_integral_type :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::is_math_real_type<T,PlaceholderExpr>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept::is_modulus_operable<T>,
                ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection::concept::is_incrementable<T>,
                    ::odds_and_ends::static_introspection::concept::is_decrementable<T>,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/is_convertible_to_cref_of.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename PlaceholderExpr>
    struct is_math_integral_type :
        ::odds_and_ends::static_introspection::concept::_detail::is_math_integral_type<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type,
            PlaceholderExpr
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MATH_INTEGRAL_TYPE_HPP

