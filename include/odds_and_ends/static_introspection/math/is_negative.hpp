// Copyright (C) 2005-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__MATH__IS_NEGATIVE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__MATH__IS_NEGATIVE_HPP

#include <odds_and_ends/static_introspection/math/is_negative_impl_fwd.hpp>
#include <boost/mpl/less.hpp>
#include <boost/mpl/negate.hpp>

namespace odds_and_ends { namespace static_introspection { namespace math {

    template <typename NumericTag>
    struct is_negative_impl
    {
        template <typename NumericConstant>
        struct apply :
            ::boost::mpl::less<
                NumericConstant,
                ::boost::mpl::negate<NumericConstant>
            >
        {
        };
    };
}}}  // namespace odds_and_ends::static_introspection::math

#include <boost/mpl/integral_c.hpp>

namespace odds_and_ends { namespace static_introspection { namespace math {

    template <>
    struct is_negative_impl< ::boost::mpl::integral_c_tag>
    {
        template <typename NumericConstant>
        struct apply :
            ::boost::mpl::less<
                NumericConstant,
                ::boost::mpl::integral_c<
                    typename NumericConstant::value_type,
                    0
                >
            >
        {
        };
    };
}}}  // namespace odds_and_ends::static_introspection::math

#include <boost/mpl/bool.hpp>

namespace odds_and_ends { namespace static_introspection { namespace math { namespace _detail {

    template <typename NumericConstant>
    struct is_negative_std
    {
        typedef ::boost::mpl::bool_<(NumericConstant::value < 0)> type;
    };

    template <typename NumericConstant>
    struct is_negative_ratio
    {
        typedef ::boost::mpl::bool_<(NumericConstant::num < 0)> type;
    };
}}}}  // namespace odds_and_ends::static_introspection::math::_detail

#include <odds_and_ends/static_introspection/nested_type/tag_of.hpp>
#include <boost/mpl/apply_wrap.hpp>

namespace odds_and_ends { namespace static_introspection { namespace math { namespace _detail {

    template <typename NumericConstant>
    struct is_negative_mpl
    {
        typedef typename ::boost::mpl::apply_wrap1<
            ::odds_and_ends::static_introspection::math::is_negative_impl<
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
    struct is_negative :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::is_std_ratio<NumericConstant>,
            ::odds_and_ends::static_introspection::math
            ::_detail::is_negative_ratio<NumericConstant>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::nested_type::has_tag<NumericConstant>,
                ::odds_and_ends::static_introspection::math
                ::_detail::is_negative_mpl<NumericConstant>,
                ::odds_and_ends::static_introspection::math
                ::_detail::is_negative_std<NumericConstant>
            >
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::math

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__MATH__IS_NEGATIVE_HPP

