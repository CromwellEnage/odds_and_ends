// Copyright (C) 2025 Cromwell D. Enage

#include <complex>
#include <boost/config.hpp>
#include <boost/rational.hpp>
#include <boost/numeric/interval.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_bin_float.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_double_fp.hpp>
#include <boost/multiprecision/tommath.hpp>
#include <boost/multiprecision/gmp.hpp>
#if defined BOOST_HAS_FLOAT128
#include <boost/multiprecision/float128.hpp>
#include <boost/multiprecision/mpfi.hpp>
#include <boost/multiprecision/mpc.hpp>
#include <boost/multiprecision/complex128.hpp>
#endif
#include <boost/multiprecision/cpp_complex.hpp>
#include <odds_and_ends/static_introspection/concept/is_math_real_type.hpp>

void test_math_real_type()
{
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_math_real_type<long double>::value,
        "'long double' is a Real Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::std::complex<double> >::value,
        "::std::complex is not a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::rational<int> >::value,
        "::boost::rational is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::numeric::interval<double> >::value,
        "::boost::numeric::interval is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::cpp_int>::value,
        "::boost::multiprecision::cpp_int is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::cpp_rational>::value,
        "::boost::multiprecision::cpp_rational is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::uint128_t>::value,
        "::boost::multiprecision::uint128_t is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::uint256_t>::value,
        "::boost::multiprecision::uint256_t is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::uint512_t>::value,
        "::boost::multiprecision::uint512_t is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::uint1024_t>::value,
        "::boost::multiprecision::uint1024_t is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::int128_t>::value,
        "::boost::multiprecision::int128_t is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::int256_t>::value,
        "::boost::multiprecision::int256_t is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::int512_t>::value,
        "::boost::multiprecision::int512_t is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::int1024_t>::value,
        "::boost::multiprecision::int1024_t is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::checked_cpp_int>::value,
        "::boost::multiprecision::checked_cpp_int is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::checked_cpp_rational>::value,
        "::boost::multiprecision::checked_cpp_rational is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::checked_uint128_t>::value,
        "::boost::multiprecision::checked_uint128_t is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::checked_uint256_t>::value,
        "::boost::multiprecision::checked_uint256_t is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::checked_uint512_t>::value,
        "::boost::multiprecision::checked_uint512_t is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::checked_uint1024_t>::value,
        "::boost::multiprecision::checked_uint1024_t is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::checked_int128_t>::value,
        "::boost::multiprecision::checked_int128_t is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::checked_int256_t>::value,
        "::boost::multiprecision::checked_int256_t is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::checked_int512_t>::value,
        "::boost::multiprecision::checked_int512_t is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::checked_int1024_t>::value,
        "::boost::multiprecision::checked_int1024_t is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::cpp_rational>::value,
        "::boost::multiprecision::cpp_rational is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::cpp_bin_float_50>::value,
        "::boost::multiprecision::cpp_bin_float_50 is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::cpp_bin_float_100>::value,
        "::boost::multiprecision::cpp_bin_float_100 is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::cpp_bin_float_single>::value,
        "::boost::multiprecision::cpp_bin_float_single is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::cpp_bin_float_double>::value,
        "::boost::multiprecision::cpp_bin_float_double is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::cpp_bin_float_double_extended>::value,
        "::boost::multiprecision::cpp_bin_float_double_extended is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::cpp_bin_float_quad>::value,
        "::boost::multiprecision::cpp_bin_float_quad is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::cpp_bin_float_oct>::value,
        "::boost::multiprecision::cpp_bin_float_oct is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::cpp_dec_float_50>::value,
        "::boost::multiprecision::cpp_dec_float_50 is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::cpp_dec_float_100>::value,
        "::boost::multiprecision::cpp_dec_float_100 is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::cpp_double_float>::value,
        "::boost::multiprecision::cpp_double_float is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::cpp_double_double>::value,
        "::boost::multiprecision::cpp_double_double is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::cpp_double_long_double>::value,
        "::boost::multiprecision::cpp_double_long_double is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::tom_int>::value,
        "::boost::multiprecision::tom_int is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::tom_rational>::value,
        "::boost::multiprecision::tom_rational is a Real Type."
    );
#if defined BOOST_HAS_FLOAT128
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::float128>::value,
        "::boost::multiprecision::float128 is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::mpz_int>::value,
        "::boost::multiprecision::mpz_int is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::mpq_rational>::value,
        "::boost::multiprecision::mpq_rational is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::mpf_float>::value,
        "::boost::multiprecision::mpf_float is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::mpf_float_50>::value,
        "::boost::multiprecision::mpf_float_50 is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::mpf_float_100>::value,
        "::boost::multiprecision::mpf_float_100 is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::mpf_float_500>::value,
        "::boost::multiprecision::mpf_float_500 is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::mpf_float_1000>::value,
        "::boost::multiprecision::mpf_float_1000 is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::mpfi_float>::value,
        "::boost::multiprecision::mpfi_float is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::mpfi_float_50>::value,
        "::boost::multiprecision::mpfi_float_50 is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::mpfi_float_100>::value,
        "::boost::multiprecision::mpfi_float_100 is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::mpfi_float_500>::value,
        "::boost::multiprecision::mpfi_float_500 is a Real Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::mpfi_float_1000>::value,
        "::boost::multiprecision::mpfi_float_1000 is a Real Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::mpc_complex>::value,
        "::boost::multiprecision::mpc_complex is not a Real Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::mpc_complex_50>::value,
        "::boost::multiprecision::mpc_complex_50 is not a Real Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::mpc_complex_100>::value,
        "::boost::multiprecision::mpc_complex_100 is not a Real Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::mpc_complex_500>::value,
        "::boost::multiprecision::mpc_complex_500 is not a Real Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::mpc_complex_1000>::value,
        "::boost::multiprecision::mpc_complex_1000 is not a Real Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::complex128>::value,
        "::boost::multiprecision::complex128 is not a Real Type."
    );
#endif  // defined BOOST_HAS_FLOAT128
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::cpp_complex_50>::value,
        "::boost::multiprecision::cpp_complex_50 is not a Real Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::cpp_complex_100>::value,
        "::boost::multiprecision::cpp_complex_100 is not a Real Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::cpp_complex_single>::value,
        "::boost::multiprecision::cpp_complex_single is not a Real Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::cpp_complex_double>::value,
        "::boost::multiprecision::cpp_complex_double is not a Real Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::cpp_complex_extended>::value,
        "::boost::multiprecision::cpp_complex_extended is not a Real Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::cpp_complex_quad>::value,
        "::boost::multiprecision::cpp_complex_quad is not a Real Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_real_type< ::boost::multiprecision::cpp_complex_oct>::value,
        "::boost::multiprecision::cpp_complex_oct is not a Real Type."
    );
}

#include <odds_and_ends/static_introspection/concept/is_math_rational_type.hpp>

void test_math_rational_type()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_math_rational_type<long double>::value,
        "'long double' is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::std::complex<double> >::value,
        "::std::complex is not a Rational Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::rational<int> >::value,
        "::boost::rational is a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::numeric::interval<double> >::value,
        "::boost::numeric::interval is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::cpp_int>::value,
        "::boost::multiprecision::cpp_int is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::cpp_rational>::value,
        "::boost::multiprecision::cpp_rational is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::uint128_t>::value,
        "::boost::multiprecision::uint128_t is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::uint256_t>::value,
        "::boost::multiprecision::uint256_t is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::uint512_t>::value,
        "::boost::multiprecision::uint512_t is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::uint1024_t>::value,
        "::boost::multiprecision::uint1024_t is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::int128_t>::value,
        "::boost::multiprecision::int128_t is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::int256_t>::value,
        "::boost::multiprecision::int256_t is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::int512_t>::value,
        "::boost::multiprecision::int512_t is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::int1024_t>::value,
        "::boost::multiprecision::int1024_t is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::checked_cpp_int>::value,
        "::boost::multiprecision::checked_cpp_int is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::checked_cpp_rational>::value,
        "::boost::multiprecision::checked_cpp_rational is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::checked_uint128_t>::value,
        "::boost::multiprecision::checked_uint128_t is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::checked_uint256_t>::value,
        "::boost::multiprecision::checked_uint256_t is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::checked_uint512_t>::value,
        "::boost::multiprecision::checked_uint512_t is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::checked_uint1024_t>::value,
        "::boost::multiprecision::checked_uint1024_t is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::checked_int128_t>::value,
        "::boost::multiprecision::checked_int128_t is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::checked_int256_t>::value,
        "::boost::multiprecision::checked_int256_t is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::checked_int512_t>::value,
        "::boost::multiprecision::checked_int512_t is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::checked_int1024_t>::value,
        "::boost::multiprecision::checked_int1024_t is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::cpp_rational>::value,
        "::boost::multiprecision::cpp_rational is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::cpp_bin_float_50>::value,
        "::boost::multiprecision::cpp_bin_float_50 is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::cpp_bin_float_100>::value,
        "::boost::multiprecision::cpp_bin_float_100 is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::cpp_bin_float_single>::value,
        "::boost::multiprecision::cpp_bin_float_single is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::cpp_bin_float_double>::value,
        "::boost::multiprecision::cpp_bin_float_double is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::cpp_bin_float_double_extended>::value,
        "::boost::multiprecision::cpp_bin_float_double_extended is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::cpp_bin_float_quad>::value,
        "::boost::multiprecision::cpp_bin_float_quad is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::cpp_bin_float_oct>::value,
        "::boost::multiprecision::cpp_bin_float_oct is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::cpp_dec_float_50>::value,
        "::boost::multiprecision::cpp_dec_float_50 is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::cpp_dec_float_100>::value,
        "::boost::multiprecision::cpp_dec_float_100 is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::cpp_double_float>::value,
        "::boost::multiprecision::cpp_double_float is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::cpp_double_double>::value,
        "::boost::multiprecision::cpp_double_double is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::cpp_double_long_double>::value,
        "::boost::multiprecision::cpp_double_long_double is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::tom_int>::value,
        "::boost::multiprecision::tom_int is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::tom_rational>::value,
        "::boost::multiprecision::tom_rational is not a Rational Type."
    );
#if defined BOOST_HAS_FLOAT128
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::float128>::value,
        "::boost::multiprecision::float128 is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::mpz_int>::value,
        "::boost::multiprecision::mpz_int is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::mpq_rational>::value,
        "::boost::multiprecision::mpq_rational is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::mpf_float>::value,
        "::boost::multiprecision::mpf_float is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::mpf_float_50>::value,
        "::boost::multiprecision::mpf_float_50 is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::mpf_float_100>::value,
        "::boost::multiprecision::mpf_float_100 is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::mpf_float_500>::value,
        "::boost::multiprecision::mpf_float_500 is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::mpf_float_1000>::value,
        "::boost::multiprecision::mpf_float_1000 is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::mpfi_float>::value,
        "::boost::multiprecision::mpfi_float is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::mpfi_float_50>::value,
        "::boost::multiprecision::mpfi_float_50 is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::mpfi_float_100>::value,
        "::boost::multiprecision::mpfi_float_100 is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::mpfi_float_500>::value,
        "::boost::multiprecision::mpfi_float_500 is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::mpfi_float_1000>::value,
        "::boost::multiprecision::mpfi_float_1000 is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::mpc_complex>::value,
        "::boost::multiprecision::mpc_complex is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::mpc_complex_50>::value,
        "::boost::multiprecision::mpc_complex_50 is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::mpc_complex_100>::value,
        "::boost::multiprecision::mpc_complex_100 is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::mpc_complex_500>::value,
        "::boost::multiprecision::mpc_complex_500 is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::mpc_complex_1000>::value,
        "::boost::multiprecision::mpc_complex_1000 is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::complex128>::value,
        "::boost::multiprecision::complex128 is not a Rational Type."
    );
#endif  // defined BOOST_HAS_FLOAT128
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::cpp_complex_50>::value,
        "::boost::multiprecision::cpp_complex_50 is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::cpp_complex_100>::value,
        "::boost::multiprecision::cpp_complex_100 is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::cpp_complex_single>::value,
        "::boost::multiprecision::cpp_complex_single is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::cpp_complex_double>::value,
        "::boost::multiprecision::cpp_complex_double is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::cpp_complex_extended>::value,
        "::boost::multiprecision::cpp_complex_extended is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::cpp_complex_quad>::value,
        "::boost::multiprecision::cpp_complex_quad is not a Rational Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_rational_type< ::boost::multiprecision::cpp_complex_oct>::value,
        "::boost::multiprecision::cpp_complex_oct is not a Rational Type."
    );
}

#include <odds_and_ends/static_introspection/concept/is_math_complex_type.hpp>
#include <boost/mpl/bool.hpp>

void test_math_complex_type()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_math_complex_type<long double>::value,
        "'long double' is not a Complex Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::std::complex<double>,::boost::mpl::true_>::value,
        "::std::complex is a strict Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::rational<int> >::value,
        "::boost::rational is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::numeric::interval<double> >::value,
        "::boost::numeric::interval is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::cpp_int>::value,
        "::boost::multiprecision::cpp_int is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::cpp_rational>::value,
        "::boost::multiprecision::cpp_rational is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::uint128_t>::value,
        "::boost::multiprecision::uint128_t is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::uint256_t>::value,
        "::boost::multiprecision::uint256_t is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::uint512_t>::value,
        "::boost::multiprecision::uint512_t is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::uint1024_t>::value,
        "::boost::multiprecision::uint1024_t is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::int128_t>::value,
        "::boost::multiprecision::int128_t is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::int256_t>::value,
        "::boost::multiprecision::int256_t is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::int512_t>::value,
        "::boost::multiprecision::int512_t is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::int1024_t>::value,
        "::boost::multiprecision::int1024_t is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::checked_cpp_int>::value,
        "::boost::multiprecision::checked_cpp_int is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::checked_cpp_rational>::value,
        "::boost::multiprecision::checked_cpp_rational is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::checked_uint128_t>::value,
        "::boost::multiprecision::checked_uint128_t is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::checked_uint256_t>::value,
        "::boost::multiprecision::checked_uint256_t is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::checked_uint512_t>::value,
        "::boost::multiprecision::checked_uint512_t is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::checked_uint1024_t>::value,
        "::boost::multiprecision::checked_uint1024_t is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::checked_int128_t>::value,
        "::boost::multiprecision::checked_int128_t is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::checked_int256_t>::value,
        "::boost::multiprecision::checked_int256_t is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::checked_int512_t>::value,
        "::boost::multiprecision::checked_int512_t is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::checked_int1024_t>::value,
        "::boost::multiprecision::checked_int1024_t is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::cpp_rational>::value,
        "::boost::multiprecision::cpp_rational is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::cpp_bin_float_50>::value,
        "::boost::multiprecision::cpp_bin_float_50 is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::cpp_bin_float_100>::value,
        "::boost::multiprecision::cpp_bin_float_100 is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::cpp_bin_float_single>::value,
        "::boost::multiprecision::cpp_bin_float_single is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::cpp_bin_float_double>::value,
        "::boost::multiprecision::cpp_bin_float_double is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::cpp_bin_float_double_extended>::value,
        "::boost::multiprecision::cpp_bin_float_double_extended is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::cpp_bin_float_quad>::value,
        "::boost::multiprecision::cpp_bin_float_quad is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::cpp_bin_float_oct>::value,
        "::boost::multiprecision::cpp_bin_float_oct is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::cpp_dec_float_50>::value,
        "::boost::multiprecision::cpp_dec_float_50 is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::cpp_dec_float_100>::value,
        "::boost::multiprecision::cpp_dec_float_100 is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::cpp_double_float>::value,
        "::boost::multiprecision::cpp_double_float is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::cpp_double_double>::value,
        "::boost::multiprecision::cpp_double_double is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::cpp_double_long_double>::value,
        "::boost::multiprecision::cpp_double_long_double is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::tom_int>::value,
        "::boost::multiprecision::tom_int is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::tom_rational>::value,
        "::boost::multiprecision::tom_rational is not a Complex Type."
    );
#if defined BOOST_HAS_FLOAT128
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::float128>::value,
        "::boost::multiprecision::float128 is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::mpz_int>::value,
        "::boost::multiprecision::mpz_int is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::mpq_rational>::value,
        "::boost::multiprecision::mpq_rational is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::mpf_float>::value,
        "::boost::multiprecision::mpf_float is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::mpf_float_50>::value,
        "::boost::multiprecision::mpf_float_50 is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::mpf_float_100>::value,
        "::boost::multiprecision::mpf_float_100 is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::mpf_float_500>::value,
        "::boost::multiprecision::mpf_float_500 is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::mpf_float_1000>::value,
        "::boost::multiprecision::mpf_float_1000 is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::mpfi_float>::value,
        "::boost::multiprecision::mpfi_float is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::mpfi_float_50>::value,
        "::boost::multiprecision::mpfi_float_50 is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::mpfi_float_100>::value,
        "::boost::multiprecision::mpfi_float_100 is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::mpfi_float_500>::value,
        "::boost::multiprecision::mpfi_float_500 is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_math_complex_type< ::boost::multiprecision::mpfi_float_1000>::value,
        "::boost::multiprecision::mpfi_float_1000 is not a Complex Type."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_math_complex_type<
            ::boost::multiprecision::mpc_complex,
            ::boost::mpl::true_
        >::value,
        "::boost::multiprecision::mpc_complex is not a strict Complex Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_math_complex_type<
            ::boost::multiprecision::mpc_complex
        >::value,
        "::boost::multiprecision::mpc_complex is a minimal Complex Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_math_complex_type<
            ::boost::multiprecision::mpc_complex_50,
            ::boost::mpl::true_
        >::value,
        "::boost::multiprecision::mpc_complex_50 is a strict Complex Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_math_complex_type<
            ::boost::multiprecision::mpc_complex_100,
            ::boost::mpl::true_
        >::value,
        "::boost::multiprecision::mpc_complex_100 is a strict Complex Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_math_complex_type<
            ::boost::multiprecision::mpc_complex_500,
            ::boost::mpl::true_
        >::value,
        "::boost::multiprecision::mpc_complex_500 is a strict Complex Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_math_complex_type<
            ::boost::multiprecision::mpc_complex_1000,
            ::boost::mpl::true_
        >::value,
        "::boost::multiprecision::mpc_complex_1000 is a strict Complex Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_math_complex_type<
            ::boost::multiprecision::complex128,
            ::boost::mpl::true_
        >::value,
        "::boost::multiprecision::complex128 is a strict Complex Type."
    );
#endif  // defined BOOST_HAS_FLOAT128
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_math_complex_type<
            ::boost::multiprecision::cpp_complex_50,
            ::boost::mpl::true_
        >::value,
        "::boost::multiprecision::cpp_complex_50 is a strict Complex Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_math_complex_type<
            ::boost::multiprecision::cpp_complex_100,
            ::boost::mpl::true_
        >::value,
        "::boost::multiprecision::cpp_complex_100 is a strict Complex Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_math_complex_type<
            ::boost::multiprecision::cpp_complex_single,
            ::boost::mpl::true_
        >::value,
        "::boost::multiprecision::cpp_complex_single is a strict Complex Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_math_complex_type<
            ::boost::multiprecision::cpp_complex_double,
            ::boost::mpl::true_
        >::value,
        "::boost::multiprecision::cpp_complex_double is a strict Complex Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_math_complex_type<
            ::boost::multiprecision::cpp_complex_extended,
            ::boost::mpl::true_
        >::value,
        "::boost::multiprecision::cpp_complex_extended is a strict Complex Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_math_complex_type<
            ::boost::multiprecision::cpp_complex_quad,
            ::boost::mpl::true_
        >::value,
        "::boost::multiprecision::cpp_complex_quad is a strict Complex Type."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_math_complex_type<
            ::boost::multiprecision::cpp_complex_oct,
            ::boost::mpl::true_
        >::value,
        "::boost::multiprecision::cpp_complex_oct is a strict Complex Type."
    );
}

#include <boost/core/lightweight_test.hpp>

int main(int argc, char** argv)
{
    test_math_real_type();
    test_math_rational_type();
    test_math_complex_type();
    return ::boost::report_errors();
}
