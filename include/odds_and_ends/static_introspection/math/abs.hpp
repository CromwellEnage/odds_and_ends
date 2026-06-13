// Copyright (C) 2005-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__MATH__ABS_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__MATH__ABS_HPP

#include <odds_and_ends/static_introspection/math/abs_impl_fwd.hpp>
#include <odds_and_ends/static_introspection/math/is_negative.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/negate.hpp>

namespace odds_and_ends { namespace static_introspection { namespace math {

    template <typename NumericTag>
    struct abs_impl
    {
        template <typename NumericConstant>
        struct apply :
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::math::is_negative<NumericConstant>,
                ::boost::mpl::negate<NumericConstant>,
                NumericConstant
            >
        {
        };
    };
}}}  // namespace odds_and_ends::static_introspection::math

#include <type_traits>

namespace odds_and_ends { namespace static_introspection { namespace math { namespace _detail {

    template <typename NumericConstant>
    struct abs_std
    {
        typedef ::std::integral_constant<
            typename NumericConstant::value_type,
            ((NumericConstant::value < 0)?(-NumericConstant::value):(NumericConstant::value))
        > type;
    };
}}}}  // namespace odds_and_ends::static_introspection::math::_detail

#include <ratio>

namespace odds_and_ends { namespace static_introspection { namespace math { namespace _detail {

    template <typename NumericConstant>
    struct abs_ratio
    {
        typedef ::std::ratio<
            ((NumericConstant::num < 0)?(-NumericConstant::num):(NumericConstant::num)),
            NumericConstant::den
        > type;
    };
}}}}  // namespace odds_and_ends::static_introspection::math::_detail

#include <odds_and_ends/static_introspection/nested_type/tag_of.hpp>
#include <boost/mpl/apply_wrap.hpp>

namespace odds_and_ends { namespace static_introspection { namespace math { namespace _detail {

    template <typename NumericConstant>
    struct abs_mpl
    {
        typedef typename ::boost::mpl::apply_wrap1<
            ::odds_and_ends::static_introspection::math::abs_impl<
                typename ::odds_and_ends::static_introspection
                ::nested_type::tag_of<NumericConstant>::type
            >,
            NumericConstant
        >::type type;
    };
}}}}  // namespace odds_and_ends::static_introspection::math::_detail

#include <odds_and_ends/static_introspection/concept/is_std_ratio.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_tag.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace math {

    template <typename NumericConstant>
    struct abs :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::is_std_ratio<NumericConstant>,
            ::odds_and_ends::static_introspection::math::_detail::abs_ratio<NumericConstant>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::nested_type::has_tag<NumericConstant>,
                ::odds_and_ends::static_introspection::math::_detail::abs_mpl<NumericConstant>,
                ::odds_and_ends::static_introspection::math::_detail::abs_std<NumericConstant>
            >
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::math

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__MATH__ABS_HPP

