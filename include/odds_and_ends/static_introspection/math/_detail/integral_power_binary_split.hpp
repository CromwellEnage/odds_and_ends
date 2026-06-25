// Copyright (C) 2005-2026 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__MATH__DETAIL__INTEGRAL_POWER_BINARY_SPLIT_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__MATH__DETAIL__INTEGRAL_POWER_BINARY_SPLIT_HPP

namespace odds_and_ends { namespace static_introspection { namespace math { namespace _detail {

    template <typename NumericConstantBase, typename IntegralConstantPower>
    class integral_power_binary_split;
}}}}  // namespace odds_and_ends::static_introspection::math::_detail

#include <type_traits>

namespace odds_and_ends { namespace static_introspection { namespace math { namespace _detail {

    template <typename IntegralConstantPower>
    struct integral_power_binary_split_next_step_0
    {
        typedef ::std::integral_constant<
            typename IntegralConstantPower::value_type,
            (1+IntegralConstantPower::value)
        > type;
    };

    template <typename NumericConstantBase, typename IntegralConstantPower>
    struct integral_power_binary_split_next_step_1
    {
        typedef typename ::odds_and_ends::static_introspection
        ::math::_detail::integral_power_binary_split<
            NumericConstantBase,
            ::std::integral_constant<
                typename IntegralConstantPower::value_type,
                (IntegralConstantPower::value>>1)
            >
        >::type type;
    };

    template <typename NumericConstantBase, typename NextStep, typename IsOdd>
    struct integral_power_binary_split_times_std
    {
        typedef ::std::integral_constant<
            typename NumericConstantBase::value_type,
            (IsOdd::value) ?
            (NextStep::value * NextStep::value * NumericConstantBase::value) :
            (NextStep::value * NextStep::value)
        > type;
    };
}}}}  // namespace odds_and_ends::static_introspection::math::_detail

#include <odds_and_ends/static_introspection/math/is_zero.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_tag.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/shift_right.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace math { namespace _detail {

    template <typename NumericConstantBase, typename IntegralConstantPower>
    struct integral_power_binary_split_next_step :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::math::is_zero<IntegralConstantPower>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::nested_type::has_tag<IntegralConstantPower>,
                ::boost::mpl::plus<IntegralConstantPower,::boost::mpl::int_<1> >,
                ::odds_and_ends::static_introspection::math::_detail
                ::integral_power_binary_split_next_step_0<IntegralConstantPower>
            >,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::nested_type::has_tag<IntegralConstantPower>,
                ::odds_and_ends::static_introspection::math::_detail::integral_power_binary_split<
                    NumericConstantBase,
                    ::boost::mpl::shift_right<IntegralConstantPower,::boost::mpl::int_<1> >
                >,
                ::odds_and_ends::static_introspection::math
                ::_detail::integral_power_binary_split_next_step_1<
                    NumericConstantBase,
                    IntegralConstantPower
                >
            >
        >
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::math::_detail

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/times.hpp>

namespace odds_and_ends { namespace static_introspection { namespace math { namespace _detail {

    template <typename NumericConstantBase, typename NextStep, typename IsOdd>
    struct integral_power_binary_split_times_mpl :
        ::boost::mpl::eval_if<
            IsOdd,
            ::boost::mpl::times<NextStep,NextStep,NumericConstantBase>,
            ::boost::mpl::times<NextStep,NextStep>
        >
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::math::_detail

#include <ratio>

namespace odds_and_ends { namespace static_introspection { namespace math { namespace _detail {

    template <typename NumericConstantBase, typename NextStep, typename IsOdd>
    struct integral_power_binary_split_times_ratio_ratio
    {
        typedef typename ::boost::mpl::eval_if<
            IsOdd,
            ::std::ratio<
                NumericConstantBase::num*NextStep::num*NextStep::num,
                NumericConstantBase::den*NextStep::den*NextStep::den
            >,
            ::std::ratio<NextStep::num*NextStep::num,NextStep::den*NextStep::den>
        >::type type;
    };

    template <typename NumericConstantBase, typename NextStep, typename IsOdd>
    struct integral_power_binary_split_times_ratio_integral
    {
        typedef typename ::boost::mpl::eval_if<
            IsOdd,
            ::std::ratio<
                NumericConstantBase::num*NextStep::value*NextStep::value,
                NumericConstantBase::den
            >,
            ::std::ratio<NextStep::value*NextStep::value,1>
        >::type type;
    };
}}}}  // namespace odds_and_ends::static_introspection::math::_detail

#include <odds_and_ends/static_introspection/math/is_odd.hpp>
#include <odds_and_ends/static_introspection/concept/is_std_ratio.hpp>
#include <boost/mpl/and.hpp>

namespace odds_and_ends { namespace static_introspection { namespace math { namespace _detail {

    template <typename NumericConstantBase, typename IntegralConstantPower>
    class integral_power_binary_split
    {
        typedef typename ::odds_and_ends::static_introspection
        ::math::_detail::integral_power_binary_split_next_step<
            NumericConstantBase,
            IntegralConstantPower
        >::type _next_step;

    public:
        typedef typename ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::math::is_zero<IntegralConstantPower>,
            _next_step,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept::is_std_ratio<NumericConstantBase>,
                ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::concept::is_std_ratio<_next_step>,
                    ::odds_and_ends::static_introspection::math::_detail
                    ::integral_power_binary_split_times_ratio_ratio<
                        NumericConstantBase,
                        _next_step,
                        ::odds_and_ends::static_introspection::math::is_odd<IntegralConstantPower>
                    >,
                    ::odds_and_ends::static_introspection::math::_detail
                    ::integral_power_binary_split_times_ratio_integral<
                        NumericConstantBase,
                        _next_step,
                        ::odds_and_ends::static_introspection::math::is_odd<IntegralConstantPower>
                    >
                >,
                ::boost::mpl::eval_if<
                    ::boost::mpl::and_<
                        ::odds_and_ends::static_introspection
                        ::nested_type::has_tag<NumericConstantBase>,
                        ::odds_and_ends::static_introspection::nested_type::has_tag<_next_step>
                    >,
                    ::odds_and_ends::static_introspection::math
                    ::_detail::integral_power_binary_split_times_mpl<
                        NumericConstantBase,
                        _next_step,
                        ::odds_and_ends::static_introspection::math::is_odd<IntegralConstantPower>
                    >,
                    ::odds_and_ends::static_introspection::math
                    ::_detail::integral_power_binary_split_times_std<
                        NumericConstantBase,
                        _next_step,
                        ::odds_and_ends::static_introspection::math::is_odd<IntegralConstantPower>
                    >
                >
            >
        >::type type;
    };
}}}}  // namespace odds_and_ends::static_introspection::math::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__MATH__DETAIL__INTEGRAL_POWER_BINARY_SPLIT_HPP

