// Copyright (C) 2025-2026 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <odds_and_ends/static_introspection/concept/is_value_generator.hpp>
#include <boost/random/linear_congruential.hpp>
#include <boost/random/additive_combine.hpp>
#include <boost/random/shuffle_order.hpp>
#include <boost/random/taus88.hpp>
#include <boost/random/inversive_congruential.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/lagged_fibonacci.hpp>
#include <boost/random/ranlux.hpp>
#include <boost/random/splitmix64.hpp>
#include <boost/random/xoshiro.hpp>
#include <boost/core/lightweight_test.hpp>

int main(int argc, char** argv)
{
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::minstd_rand0
        >::value,
        "::boost::random::minstd_rand0 is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::minstd_rand
        >::value,
        "::boost::random::minstd_rand is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::rand48
        >::value,
        "::boost::random::rand48 is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::ecuyer1988
        >::value,
        "::boost::random::ecuyer1988 is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::kreutzer1986
        >::value,
        "::boost::random::kreutzer1986 is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::knuth_b
        >::value,
        "::boost::random::knuth_b is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::taus88
        >::value,
        "::boost::random::taus88 is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::hellekalek1995
        >::value,
        "::boost::random::hellekalek1995 is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::mt11213b
        >::value,
        "::boost::random::mt11213b is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::mt19937
        >::value,
        "::boost::random::mt19937 is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::mt19937_64
        >::value,
        "::boost::random::mt19937_64 is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::lagged_fibonacci607
        >::value,
        "::boost::random::lagged_fibonacci607 is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::lagged_fibonacci1279
        >::value,
        "::boost::random::lagged_fibonacci1279 is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::lagged_fibonacci2281
        >::value,
        "::boost::random::lagged_fibonacci2281 is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::lagged_fibonacci3217
        >::value,
        "::boost::random::lagged_fibonacci3217 is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::lagged_fibonacci4423
        >::value,
        "::boost::random::lagged_fibonacci4423 is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::lagged_fibonacci9689
        >::value,
        "::boost::random::lagged_fibonacci9689 is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::lagged_fibonacci19937
        >::value,
        "::boost::random::lagged_fibonacci19937 is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::lagged_fibonacci23209
        >::value,
        "::boost::random::lagged_fibonacci23209 is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::lagged_fibonacci44497
        >::value,
        "::boost::random::lagged_fibonacci44497 is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::ranlux3
        >::value,
        "::boost::random::ranlux3 is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::ranlux4
        >::value,
        "::boost::random::ranlux4 is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::ranlux3_01
        >::value,
        "::boost::random::ranlux3_01 is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::ranlux4_01
        >::value,
        "::boost::random::ranlux4_01 is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::ranlux64_3_01
        >::value,
        "::boost::random::ranlux64_3_01 is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::ranlux64_4_01
        >::value,
        "::boost::random::ranlux64_4_01 is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::splitmix64
        >::value,
        "::boost::random::splitmix64 is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::xoshiro128f
        >::value,
        "::boost::random::xoshiro128f is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::xoshiro128mm
        >::value,
        "::boost::random::xoshiro128mm is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::xoshiro128pp
        >::value,
        "::boost::random::xoshiro128pp is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::xoshiro256d
        >::value,
        "::boost::random::xoshiro256d is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::xoshiro256mm
        >::value,
        "::boost::random::xoshiro256mm is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::xoshiro256pp
        >::value,
        "::boost::random::xoshiro256pp is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::xoshiro512d
        >::value,
        "::boost::random::xoshiro512d is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::xoshiro512mm
        >::value,
        "::boost::random::xoshiro512mm is a Random Number Generator."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_value_generator<
            ::boost::random::xoshiro512pp
        >::value,
        "::boost::random::xoshiro512pp is a Random Number Generator."
    );
    return ::boost::report_errors();
}
