// Copyright (C) 2005-2026 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__MATH__RECIPROCAL_INTEGRAL_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__MATH__RECIPROCAL_INTEGRAL_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/math/reciprocal_impl.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/numeric_cast.hpp>

namespace odds_and_ends { namespace static_introspection { namespace math {

    template <typename NumericTag, typename IntegralConstant>
    struct reciprocal_integral :
        ::boost::mpl::apply_wrap1<
            ::odds_and_ends::static_introspection::math::reciprocal_impl<NumericTag>,
            typename ::boost::mpl::apply_wrap1<
                BOOST_MPL_AUX_NUMERIC_CAST<
                    typename IntegralConstant::tag,
                    NumericTag
                >,
                IntegralConstant
            >::type
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::math

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__MATH__RECIPROCAL_INTEGRAL_HPP

