// Copyright (C) 2005-2026 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <type_traits>
#include <odds_and_ends/static_introspection/math/integral_power.hpp>
#include <boost/mpl/aux_/test.hpp>

MPL_TEST_CASE()
{
    typedef ::odds_and_ends::static_introspection::math::integral_power<
        ::std::integral_constant<int,-7>,
        ::std::integral_constant<int,5>
    > n16807;

    static_assert(-16807 == n16807::value, "");
}

#include <odds_and_ends/static_introspection/concept/is_mpl_integral_constant.hpp>
#include <boost/mpl/int.hpp>

MPL_TEST_CASE()
{
    typedef ::odds_and_ends::static_introspection::math::integral_power<
        ::boost::mpl::int_<-7>,
        ::boost::mpl::int_<5>
    > n16807;

    static_assert(-16807 == n16807::value, "");
}

#include <ratio>

MPL_TEST_CASE()
{
    typedef ::odds_and_ends::static_introspection::math::integral_power<
        ::std::ratio<5,1>,
        ::boost::mpl::int_<-3>
    >::type p1_125;

    static_assert(1 == p1_125::num, "");
    static_assert(125 == p1_125::den, "");
}

