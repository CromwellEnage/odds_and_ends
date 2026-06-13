// Copyright (C) 2005-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__MATH__RECIPROCAL_IMPL_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__MATH__RECIPROCAL_IMPL_HPP

#include <odds_and_ends/static_introspection/math/reciprocal_impl_fwd.hpp>
#include <odds_and_ends/static_introspection/math/is_zero.hpp>
#include <odds_and_ends/static_introspection/math/_detail/error__zero_divisor.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/divides.hpp>

namespace odds_and_ends { namespace static_introspection { namespace math {

    template <typename NumericTag>
    struct reciprocal_impl
    {
        template <typename NumericConstant>
        struct apply :
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::math::is_zero<NumericConstant>,
                ::odds_and_ends::static_introspection::math::_detail::error__zero_divisor,
                ::boost::mpl::divides< ::boost::mpl::int_<1>,NumericConstant>
            >
        {
        };
    };
}}}  // namespace odds_and_ends::static_introspection::math

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__MATH__RECIPROCAL_IMPL_HPP

