// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MATH_MIXED_NUMERIC_TYPE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MATH_MIXED_NUMERIC_TYPE_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/is_math_real_type.hpp>
#include <odds_and_ends/static_introspection/free_function/has_integral_part.hpp>
#include <odds_and_ends/static_introspection/free_function/has_fractional_part.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename PlaceholderExpr>
    struct is_math_mixed_numeric_type :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::is_math_real_type<T>,
            ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::free_function
                ::has_integral_part<T,PlaceholderExpr>,
                ::odds_and_ends::static_introspection::free_function
                ::has_fractional_part<T,PlaceholderExpr>,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MATH_MIXED_NUMERIC_TYPE_HPP

