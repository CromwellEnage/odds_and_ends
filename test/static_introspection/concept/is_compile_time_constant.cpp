// Copyright (C) 2025-2026 Cromwell D. Enage

#include <type_traits>
#include <ratio>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/int.hpp>
#include <boost/ratio/ratio.hpp>
#include <odds_and_ends/static_introspection/concept/is_std_integral_constant.hpp>

void test_std_integral_constants()
{
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::std::integral_constant<int,1>
        >::value,
        "::std::integral_constant<int,1> is a C++-Standard Integral Constant."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::std::true_type
        >::value,
        "::std::true_type is a C++-Standard Integral Constant."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::std::false_type
        >::value,
        "::std::false_type is a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::std::atto
        >::value,
        "::std::atto is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::std::femto
        >::value,
        "::std::femto is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::std::pico
        >::value,
        "::std::pico is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::std::nano
        >::value,
        "::std::nano is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::std::micro
        >::value,
        "::std::micro is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::std::milli
        >::value,
        "::std::milli is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::std::centi
        >::value,
        "::std::centi is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::std::deci
        >::value,
        "::std::deci is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::std::deca
        >::value,
        "::std::deca is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::std::hecto
        >::value,
        "::std::hecto is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::std::kilo
        >::value,
        "::std::kilo is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::std::mega
        >::value,
        "::std::mega is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::std::giga
        >::value,
        "::std::giga is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::std::tera
        >::value,
        "::std::tera is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::std::peta
        >::value,
        "::std::peta is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::std::exa
        >::value,
        "::std::exa is not a C++-Standard Integral Constant."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::boost::mpl::int_<1>
        >::value,
        "::boost::mpl::integral_c<int,1> is a C++-Standard Integral Constant."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::boost::mpl::true_
        >::value,
        "::boost::mpl::true_ is a C++-Standard Integral Constant."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::boost::mpl::false_
        >::value,
        "::boost::mpl::false_ is a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::boost::atto
        >::value,
        "::boost::atto is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::boost::femto
        >::value,
        "::boost::femto is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::boost::pico
        >::value,
        "::boost::pico is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::boost::nano
        >::value,
        "::boost::nano is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::boost::micro
        >::value,
        "::boost::micro is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::boost::milli
        >::value,
        "::boost::milli is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::boost::centi
        >::value,
        "::boost::centi is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::boost::deci
        >::value,
        "::boost::deci is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::boost::deca
        >::value,
        "::boost::deca is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::boost::hecto
        >::value,
        "::boost::hecto is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::boost::kilo
        >::value,
        "::boost::kilo is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::boost::mega
        >::value,
        "::boost::mega is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::boost::giga
        >::value,
        "::boost::giga is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::boost::tera
        >::value,
        "::boost::tera is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::boost::peta
        >::value,
        "::boost::peta is not a C++-Standard Integral Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            ::boost::exa
        >::value,
        "::boost::exa is not a C++-Standard Integral Constant."
    );
}

#include <odds_and_ends/static_introspection/concept/is_std_boolean_constant.hpp>

void test_std_boolean_constants()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::std::integral_constant<int,1>
        >::value,
        "::std::integral_constant is not a C++-Standard Boolean Constant."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::std::true_type
        >::value,
        "::std::true_type is a C++-Standard Boolean Constant."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::std::false_type
        >::value,
        "::std::false_type is a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::std::atto
        >::value,
        "::std::atto is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::std::femto
        >::value,
        "::std::femto is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::std::pico
        >::value,
        "::std::pico is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::std::nano
        >::value,
        "::std::nano is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::std::micro
        >::value,
        "::std::micro is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::std::milli
        >::value,
        "::std::milli is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::std::centi
        >::value,
        "::std::centi is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::std::deci
        >::value,
        "::std::deci is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::std::deca
        >::value,
        "::std::deca is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::std::hecto
        >::value,
        "::std::hecto is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::std::kilo
        >::value,
        "::std::kilo is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::std::mega
        >::value,
        "::std::mega is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::std::giga
        >::value,
        "::std::giga is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::std::tera
        >::value,
        "::std::tera is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::std::peta
        >::value,
        "::std::peta is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::std::exa
        >::value,
        "::std::exa is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::boost::mpl::int_<1>
        >::value,
        "::boost::mpl::integral_c<int,1> is not a C++-Standard Boolean Constant."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::boost::mpl::true_
        >::value,
        "::boost::mpl::true_ is a C++-Standard Boolean Constant."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::boost::mpl::false_
        >::value,
        "::boost::mpl::false_ is a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::boost::atto
        >::value,
        "::boost::atto is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::boost::femto
        >::value,
        "::boost::femto is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::boost::pico
        >::value,
        "::boost::pico is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::boost::nano
        >::value,
        "::boost::nano is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::boost::micro
        >::value,
        "::boost::micro is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::boost::milli
        >::value,
        "::boost::milli is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::boost::centi
        >::value,
        "::boost::centi is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::boost::deci
        >::value,
        "::boost::deci is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::boost::deca
        >::value,
        "::boost::deca is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::boost::hecto
        >::value,
        "::boost::hecto is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::boost::kilo
        >::value,
        "::boost::kilo is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::boost::mega
        >::value,
        "::boost::mega is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::boost::giga
        >::value,
        "::boost::giga is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::boost::tera
        >::value,
        "::boost::tera is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::boost::peta
        >::value,
        "::boost::peta is not a C++-Standard Boolean Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_std_boolean_constant<
            ::boost::exa
        >::value,
        "::boost::exa is not a C++-Standard Boolean Constant."
    );
}

#include <odds_and_ends/static_introspection/concept/is_mpl_static_constant.hpp>

void test_mpl_static_constants()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::std::integral_constant<int,1>
        >::value,
        "::std::integral_constant<int,1> is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::std::true_type
        >::value,
        "::std::true_type is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::std::false_type
        >::value,
        "::std::false_type is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::std::atto
        >::value,
        "::std::atto is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::std::femto
        >::value,
        "::std::femto is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::std::pico
        >::value,
        "::std::pico is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::std::nano
        >::value,
        "::std::nano is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::std::micro
        >::value,
        "::std::micro is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::std::milli
        >::value,
        "::std::milli is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::std::centi
        >::value,
        "::std::centi is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::std::deci
        >::value,
        "::std::deci is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::std::deca
        >::value,
        "::std::deca is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::std::hecto
        >::value,
        "::std::hecto is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::std::kilo
        >::value,
        "::std::kilo is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::std::mega
        >::value,
        "::std::mega is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::std::giga
        >::value,
        "::std::giga is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::std::tera
        >::value,
        "::std::tera is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::std::peta
        >::value,
        "::std::peta is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::std::exa
        >::value,
        "::std::exa is not a Boost MPL Static Constant."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::boost::mpl::int_<1>
        >::value,
        "::boost::mpl::integral_c<int,1> is a Boost MPL Static Constant."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::boost::mpl::true_
        >::value,
        "::boost::mpl::true_ is a Boost MPL Static Constant."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::boost::mpl::false_
        >::value,
        "::boost::mpl::false_ is a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::boost::atto
        >::value,
        "::boost::atto is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::boost::femto
        >::value,
        "::boost::femto is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::boost::pico
        >::value,
        "::boost::pico is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::boost::nano
        >::value,
        "::boost::nano is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::boost::micro
        >::value,
        "::boost::micro is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::boost::milli
        >::value,
        "::boost::milli is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::boost::centi
        >::value,
        "::boost::centi is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::boost::deci
        >::value,
        "::boost::deci is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::boost::deca
        >::value,
        "::boost::deca is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::boost::hecto
        >::value,
        "::boost::hecto is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::boost::kilo
        >::value,
        "::boost::kilo is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::boost::mega
        >::value,
        "::boost::mega is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::boost::giga
        >::value,
        "::boost::giga is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::boost::tera
        >::value,
        "::boost::tera is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::boost::peta
        >::value,
        "::boost::peta is not a Boost MPL Static Constant."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_static_constant<
            ::boost::exa
        >::value,
        "::boost::exa is not a Boost MPL Static Constant."
    );
}

#include <odds_and_ends/static_introspection/concept/is_mpl_integral_constant.hpp>

void test_mpl_integral_constants()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::std::integral_constant<int,1>
        >::value,
        "::std::integral_constant<int,1> is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::std::true_type
        >::value,
        "::std::true_type is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::std::false_type
        >::value,
        "::std::false_type is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::std::atto
        >::value,
        "::std::atto is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::std::femto
        >::value,
        "::std::femto is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::std::pico
        >::value,
        "::std::pico is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::std::nano
        >::value,
        "::std::nano is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::std::micro
        >::value,
        "::std::micro is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::std::milli
        >::value,
        "::std::milli is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::std::centi
        >::value,
        "::std::centi is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::std::deci
        >::value,
        "::std::deci is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::std::deca
        >::value,
        "::std::deca is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::std::hecto
        >::value,
        "::std::hecto is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::std::kilo
        >::value,
        "::std::kilo is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::std::mega
        >::value,
        "::std::mega is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::std::giga
        >::value,
        "::std::giga is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::std::tera
        >::value,
        "::std::tera is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::std::peta
        >::value,
        "::std::peta is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::std::exa
        >::value,
        "::std::exa is not a Boost MPL Integral Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::boost::mpl::int_<1>
        >::value,
        "::boost::mpl::integral_c<int,1> is a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::boost::mpl::true_
        >::value,
        "::boost::mpl::true_ is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::boost::mpl::false_
        >::value,
        "::boost::mpl::false_ is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::boost::atto
        >::value,
        "::boost::atto is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::boost::femto
        >::value,
        "::boost::femto is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::boost::pico
        >::value,
        "::boost::pico is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::boost::nano
        >::value,
        "::boost::nano is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::boost::micro
        >::value,
        "::boost::micro is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::boost::milli
        >::value,
        "::boost::milli is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::boost::centi
        >::value,
        "::boost::centi is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::boost::deci
        >::value,
        "::boost::deci is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::boost::deca
        >::value,
        "::boost::deca is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::boost::hecto
        >::value,
        "::boost::hecto is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::boost::kilo
        >::value,
        "::boost::kilo is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::boost::mega
        >::value,
        "::boost::mega is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::boost::giga
        >::value,
        "::boost::giga is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::boost::tera
        >::value,
        "::boost::tera is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::boost::peta
        >::value,
        "::boost::peta is not a Boost MPL Integral Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_integral_constant<
            ::boost::exa
        >::value,
        "::boost::exa is not a Boost MPL Integral Constant"
    );
}

#include <odds_and_ends/static_introspection/concept/is_mpl_boolean_constant.hpp>

void test_mpl_boolean_constants()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::std::integral_constant<int,1>
        >::value,
        "::std::integral_constant<int,1> is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::std::true_type
        >::value,
        "::std::true_type is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::std::false_type
        >::value,
        "::std::false_type is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::std::atto
        >::value,
        "::std::atto is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::std::femto
        >::value,
        "::std::femto is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::std::pico
        >::value,
        "::std::pico is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::std::nano
        >::value,
        "::std::nano is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::std::micro
        >::value,
        "::std::micro is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::std::milli
        >::value,
        "::std::milli is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::std::centi
        >::value,
        "::std::centi is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::std::deci
        >::value,
        "::std::deci is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::std::deca
        >::value,
        "::std::deca is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::std::hecto
        >::value,
        "::std::hecto is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::std::kilo
        >::value,
        "::std::kilo is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::std::mega
        >::value,
        "::std::mega is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::std::giga
        >::value,
        "::std::giga is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::std::tera
        >::value,
        "::std::tera is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::std::peta
        >::value,
        "::std::peta is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::std::exa
        >::value,
        "::std::exa is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::boost::mpl::int_<1>
        >::value,
        "::boost::mpl::integral_c<int,1> is not a Boost MPL Boolean Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::boost::mpl::true_
        >::value,
        "::boost::mpl::true_ is a Boost MPL Boolean Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::boost::mpl::false_
        >::value,
        "::boost::mpl::false_ is a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::boost::atto
        >::value,
        "::boost::atto is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::boost::femto
        >::value,
        "::boost::femto is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::boost::pico
        >::value,
        "::boost::pico is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::boost::nano
        >::value,
        "::boost::nano is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::boost::micro
        >::value,
        "::boost::micro is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::boost::milli
        >::value,
        "::boost::milli is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::boost::centi
        >::value,
        "::boost::centi is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::boost::deci
        >::value,
        "::boost::deci is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::boost::deca
        >::value,
        "::boost::deca is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::boost::hecto
        >::value,
        "::boost::hecto is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::boost::kilo
        >::value,
        "::boost::kilo is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::boost::mega
        >::value,
        "::boost::mega is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::boost::giga
        >::value,
        "::boost::giga is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::boost::tera
        >::value,
        "::boost::tera is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::boost::peta
        >::value,
        "::boost::peta is not a Boost MPL Boolean Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            ::boost::exa
        >::value,
        "::boost::exa is not a Boost MPL Boolean Constant"
    );
}

#include <odds_and_ends/static_introspection/concept/is_rational_constant.hpp>

void test_rational_constants()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::std::integral_constant<int,1>
        >::value,
        "::std::integral_constant<int,1> is not a Rational Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::std::true_type
        >::value,
        "::std::true_type is not a Rational Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::std::false_type
        >::value,
        "::std::false_type is not a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::std::atto
        >::value,
        "::std::atto is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::std::femto
        >::value,
        "::std::femto is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::std::pico
        >::value,
        "::std::pico is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::std::nano
        >::value,
        "::std::nano is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::std::micro
        >::value,
        "::std::micro is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::std::milli
        >::value,
        "::std::milli is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::std::centi
        >::value,
        "::std::centi is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::std::deci
        >::value,
        "::std::deci is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::std::deca
        >::value,
        "::std::deca is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::std::hecto
        >::value,
        "::std::hecto is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::std::kilo
        >::value,
        "::std::kilo is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::std::mega
        >::value,
        "::std::mega is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::std::giga
        >::value,
        "::std::giga is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::std::tera
        >::value,
        "::std::tera is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::std::peta
        >::value,
        "::std::peta is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::std::exa
        >::value,
        "::std::exa is a Rational Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::boost::mpl::int_<1>
        >::value,
        "::boost::mpl::integral_c<int,1> is not a Rational Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::boost::mpl::true_
        >::value,
        "::boost::mpl::true_ is not a Rational Constant"
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::boost::mpl::false_
        >::value,
        "::boost::mpl::false_ is not a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::boost::atto
        >::value,
        "::boost::atto is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::boost::femto
        >::value,
        "::boost::femto is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::boost::pico
        >::value,
        "::boost::pico is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::boost::nano
        >::value,
        "::boost::nano is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::boost::micro
        >::value,
        "::boost::micro is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::boost::milli
        >::value,
        "::boost::milli is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::boost::centi
        >::value,
        "::boost::centi is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::boost::deci
        >::value,
        "::boost::deci is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::boost::deca
        >::value,
        "::boost::deca is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::boost::hecto
        >::value,
        "::boost::hecto is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::boost::kilo
        >::value,
        "::boost::kilo is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::boost::mega
        >::value,
        "::boost::mega is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::boost::giga
        >::value,
        "::boost::giga is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::boost::tera
        >::value,
        "::boost::tera is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::boost::peta
        >::value,
        "::boost::peta is a Rational Constant"
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_rational_constant<
            ::boost::exa
        >::value,
        "::boost::exa is a Rational Constant"
    );
}

#include <boost/core/lightweight_test.hpp>

int main(int argc, char** argv)
{
    test_std_integral_constants();
    test_std_boolean_constants();
    test_mpl_static_constants();
    test_mpl_integral_constants();
    test_mpl_boolean_constants();
    test_rational_constants();
    return ::boost::report_errors();
}
