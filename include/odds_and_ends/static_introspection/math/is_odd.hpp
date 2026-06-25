// Copyright (C) 2005-2026 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__MATH__IS_ODD_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__MATH__IS_ODD_HPP

#include <boost/mpl/bool.hpp>

namespace odds_and_ends { namespace static_introspection { namespace math { namespace _detail {

    template <typename NumericConstant>
    struct is_odd_std
    {
        typedef ::boost::mpl::bool_<(1 & NumericConstant::value)> type;
    };
}}}}  // namespace odds_and_ends::static_introspection::math::_detail

#include <odds_and_ends/static_introspection/math/is_odd_impl_fwd.hpp>
#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/bitand.hpp>

namespace odds_and_ends { namespace static_introspection { namespace math {

    template <>
    struct is_odd_impl< ::boost::mpl::integral_c_tag>
    {
        template <typename NumericConstant>
        struct apply :
            ::boost::mpl::if_<
                ::boost::mpl::bitand_<
                    NumericConstant,
                    ::boost::mpl::integral_c<
                        typename NumericConstant::value_type,
                        1
                    >
                >,
                ::boost::mpl::true_,
                ::boost::mpl::false_
            >
        {
        };
    };
}}}  // namespace odds_and_ends::static_introspection::math

#include <odds_and_ends/static_introspection/nested_type/tag_of.hpp>
#include <boost/mpl/apply_wrap.hpp>

namespace odds_and_ends { namespace static_introspection { namespace math { namespace _detail {

    template <typename NumericConstant>
    struct is_odd_mpl
    {
        typedef typename ::boost::mpl::apply_wrap1<
            ::odds_and_ends::static_introspection::math::is_odd_impl<
                typename ::odds_and_ends::static_introspection
                ::nested_type::tag_of<NumericConstant>::type
            >,
            NumericConstant
        >::type type;
    };
}}}}  // namespace odds_and_ends::static_introspection::math::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_tag.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace math {

    template <typename NumericConstant>
    struct is_odd :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::nested_type::has_tag<NumericConstant>,
            ::odds_and_ends::static_introspection::math::_detail::is_odd_mpl<NumericConstant>,
            ::odds_and_ends::static_introspection::math::_detail::is_odd_std<NumericConstant>
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::math

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__MATH__IS_ODD_HPP

