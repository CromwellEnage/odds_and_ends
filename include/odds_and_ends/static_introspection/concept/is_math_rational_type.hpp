// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MATH_RATIONAL_TYPE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MATH_RATIONAL_TYPE_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/is_math_real_type.hpp>
#include <odds_and_ends/static_introspection/nested_type/is_int_type_of.hpp>
#include <odds_and_ends/static_introspection/member_function/has_numerator.hpp>
#include <odds_and_ends/static_introspection/member_function/has_denominator.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename PlaceholderExpr>
    struct is_math_rational_type :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::is_math_real_type<T>,
            ::boost::mpl::if_<
                ::odds_and_ends::static_introspection
                ::member_function::has_numerator<T,PlaceholderExpr>,
                ::odds_and_ends::static_introspection
                ::member_function::has_denominator<T,PlaceholderExpr>,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MATH_RATIONAL_TYPE_HPP

