// Copyright (C) 2005-2026 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__MATH__RECIPROCAL_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__MATH__RECIPROCAL_HPP

#include <ratio>

namespace odds_and_ends { namespace static_introspection { namespace math { namespace _detail {

    template <typename NumericConstant>
    struct reciprocal_ratio
    {
        typedef typename ::std::ratio<NumericConstant::den,NumericConstant::num>::type type;
    };
}}}}  // namespace odds_and_ends::static_introspection::math::_detail

#include <odds_and_ends/static_introspection/math/reciprocal_impl.hpp>
#include <odds_and_ends/static_introspection/nested_type/tag_of.hpp>
#include <boost/mpl/apply_wrap.hpp>

namespace odds_and_ends { namespace static_introspection { namespace math { namespace _detail {

    template <typename NumericConstant>
    struct reciprocal
    {
        typedef typename ::boost::mpl::apply_wrap1<
            ::odds_and_ends::static_introspection::math::reciprocal_impl<
                typename ::odds_and_ends::static_introspection
                ::nested_type::tag_of<NumericConstant>::type
            >,
            NumericConstant
        >::type type;
    };
}}}}  // namespace odds_and_ends::static_introspection::math::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/is_std_ratio.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace math {

    template <typename NumericConstant>
    struct reciprocal :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::is_std_ratio<NumericConstant>,
            ::odds_and_ends::static_introspection::math
            ::_detail::reciprocal_ratio<NumericConstant>,
            ::odds_and_ends::static_introspection::math::_detail::reciprocal<NumericConstant>
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::math

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__MATH__RECIPROCAL_HPP

