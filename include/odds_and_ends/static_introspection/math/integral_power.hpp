// Copyright (C) 2005-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__MATH__INTEGRAL_POWER_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__MATH__INTEGRAL_POWER_HPP

#include <odds_and_ends/static_introspection/math/abs.hpp>
#include <odds_and_ends/static_introspection/math/reciprocal.hpp>
#include <odds_and_ends/static_introspection/math/is_negative.hpp>
#include <odds_and_ends/static_introspection/math/_detail/integral_power_binary_split.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace math { namespace _detail {

    template <typename NumericConstantBase, typename IntegralConstantPower>
    class integral_power
    {
        typedef typename ::odds_and_ends::static_introspection
        ::math::_detail::integral_power_binary_split<
            NumericConstantBase,
            typename ::odds_and_ends::static_introspection::math::abs<IntegralConstantPower>::type
        >::type _result;

    public:
        typedef typename ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::math::is_negative<IntegralConstantPower>,
            ::odds_and_ends::static_introspection::math::reciprocal<_result>,
            _result
        >::type type;
    };
}}}}  // namespace odds_and_ends::static_introspection::math::_detail

namespace odds_and_ends { namespace static_introspection { namespace math {

    template <typename NumericConstantBase, typename IntegralConstantPower>
    struct integral_power :
        ::odds_and_ends::static_introspection::math::_detail
        ::integral_power<NumericConstantBase,IntegralConstantPower>::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::math

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__MATH__INTEGRAL_POWER_HPP

