// Copyright (C) 2005-2026 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__MATH__FACTORIAL_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__MATH__FACTORIAL_HPP

namespace odds_and_ends { namespace static_introspection { namespace math { namespace _detail {

    template <typename ValueT, ValueT Value>
    struct factorial_std_integral_step_0;

    template <typename ValueT, ValueT Value>
    struct factorial_mpl_integral_step_0;
}}}}  // namespace odds_and_ends::static_introspection::math::_detail

#include <type_traits>

namespace odds_and_ends { namespace static_introspection { namespace math { namespace _detail {

    template <typename ValueT, ValueT Value>
    class factorial_std_integral_step_1
    {
        typedef typename ::odds_and_ends::static_introspection::math::_detail
        ::factorial_std_integral_step_0<ValueT,(Value-1)>::type _step;

    public:
        typedef ::std::integral_constant<ValueT,(_step::value*Value)> type;
    };
}}}}  // namespace odds_and_ends::static_introspection::math::_detail

#include <boost/mpl/integral_c.hpp>

namespace odds_and_ends { namespace static_introspection { namespace math { namespace _detail {

    template <typename ValueT, ValueT Value>
    class factorial_mpl_integral_step_1
    {
        typedef typename ::odds_and_ends::static_introspection::math::_detail
        ::factorial_mpl_integral_step_0<ValueT,(Value-1)>::type _step;

    public:
        typedef ::boost::mpl::integral_c<ValueT,(_step::value*Value)> type;
    };
}}}}  // namespace odds_and_ends::static_introspection::math::_detail

#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace math { namespace _detail {

    template <typename ValueT, ValueT Value>
    struct factorial_std_integral_step_0
    {
        typedef typename ::boost::mpl::eval_if_c<
            (0 == Value),
            ::std::integral_constant<ValueT,1>,
            ::odds_and_ends::static_introspection::math::_detail
            ::factorial_std_integral_step_1<ValueT,Value>
        >::type type;
    };

    template <typename ValueT, ValueT Value>
    struct factorial_mpl_integral_step_0
    {
        typedef typename ::boost::mpl::eval_if_c<
            (0 == Value),
            ::boost::mpl::integral_c<ValueT,1>,
            ::odds_and_ends::static_introspection::math::_detail
            ::factorial_mpl_integral_step_1<ValueT,Value>
        >::type type;
    };
}}}}  // namespace odds_and_ends::static_introspection::math::_detail

#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace math { namespace _detail {

    template <typename NumericConstant>
    struct factorial_std_integral :
        ::odds_and_ends::static_introspection::math::_detail::factorial_mpl_integral_step_0<
            typename NumericConstant::value_type,
            NumericConstant::value
        >
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::math::_detail

#include <odds_and_ends/static_introspection/math/factorial_impl_fwd.hpp>

namespace odds_and_ends { namespace static_introspection { namespace math {

    template <>
    struct factorial_impl< ::boost::mpl::integral_c_tag>
    {
        template <typename IntegralConstant>
        struct apply
        {
            typedef typename ::odds_and_ends::static_introspection
            ::math::_detail::factorial_mpl_integral_step_0<
                typename IntegralConstant::value_type,
                IntegralConstant::value
            >::type type;
        };
    };
}}}  // namespace odds_and_ends::static_introspection::math

#include <odds_and_ends/static_introspection/nested_type/tag_of.hpp>
#include <boost/mpl/apply_wrap.hpp>

namespace odds_and_ends { namespace static_introspection { namespace math { namespace _detail {

    template <typename NumericConstant>
    struct factorial
    {
        typedef typename ::boost::mpl::apply_wrap1<
            ::odds_and_ends::static_introspection::math::factorial_impl<
                typename ::odds_and_ends::static_introspection
                ::nested_type::tag_of<NumericConstant>::type
            >,
            NumericConstant
        >::type type;
    };
}}}}  // namespace odds_and_ends::static_introspection::math::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/math/is_negative.hpp>
#include <odds_and_ends/static_introspection/math/_detail/error__input_out_of_domain.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_tag.hpp>

namespace odds_and_ends { namespace static_introspection { namespace math {

    template <typename NumericConstant>
    struct factorial :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::math::is_negative<NumericConstant>,
            ::odds_and_ends::static_introspection::math::_detail::error__input_out_of_domain,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::nested_type::has_tag<NumericConstant>,
                ::odds_and_ends::static_introspection::math::_detail::factorial<NumericConstant>,
                ::odds_and_ends::static_introspection::math
                ::_detail::factorial_std_integral<NumericConstant>
            >
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::math

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__MATH__FACTORIAL_HPP

