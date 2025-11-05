// Copyright (C) 2025 Cromwell D. Enage

#include <boost/mpl/deque.hpp>
#include <boost/mpl/quote.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <odds_and_ends/composite_type/composite_type.hpp>
#include <odds_and_ends/composite_type/operable/addition.hpp>
#include <odds_and_ends/composite_type/operable/subtraction.hpp>
#include <odds_and_ends/composite_type/operable/multiplication.hpp>
#include <odds_and_ends/composite_type/operable/division.hpp>
#include <odds_and_ends/composite_type/operable/increment.hpp>
#include <odds_and_ends/composite_type/operable/decrement.hpp>
#include <odds_and_ends/composite_type/listener/mixed_numeric.hpp>
#include <odds_and_ends/composite_type/member_facade/mixed_numeric.hpp>

typedef ::odds_and_ends::composite_type::composite_type<
    ::boost::mpl::deque<
        ::odds_and_ends::composite_type::mixed_numeric_member_facade<
            ::boost::multiprecision::cpp_int_backend<>
        >,
        ::boost::mpl::quote1< ::odds_and_ends::composite_type::addition_operable>,
        ::boost::mpl::quote1< ::odds_and_ends::composite_type::subtraction_operable>,
        ::boost::mpl::quote1< ::odds_and_ends::composite_type::multiplication_operable>,
        ::boost::mpl::quote1< ::odds_and_ends::composite_type::division_operable>,
        ::boost::mpl::quote1< ::odds_and_ends::composite_type::increment_operable>,
        ::boost::mpl::quote1< ::odds_and_ends::composite_type::decrement_operable>,
        ::odds_and_ends::composite_type::mixed_numeric_listener_generator<
            ::boost::multiprecision::cpp_int_backend<>
        >
    >
> foo;

/*
#include <odds_and_ends/static_introspection/concept/is_math_real_type.hpp>

void test_math_real_type()
{
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_math_real_type<foo>::value
    );
}

#include <odds_and_ends/static_introspection/concept/is_math_rational_type.hpp>

void test_math_rational_type()
{
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_math_rational_type<foo>::value
    );
}

#include <odds_and_ends/static_introspection/concept/is_math_mixed_numeric_type.hpp>

void test_math_mixed_numeric_type()
{
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_math_mixed_numeric_type<foo>::value
    );
}

#include <complex>
#include <odds_and_ends/static_introspection/concept/is_math_complex_type.hpp>
#include <boost/mpl/bool.hpp>

void test_math_complex_type()
{
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_math_complex_type<foo>::value
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_math_complex_type<
            ::std::complex<foo>,
            ::boost::mpl::true_
        >::value
    );
}
*/

#include <boost/assert.hpp>
#include <boost/core/lightweight_test.hpp>

int main(int argc, char** argv)
{
    foo unit(1, 0, 1);

    BOOST_ASSERT(1 == unit.integral_part());
    BOOST_ASSERT(0 == numerator(unit.fractional_part()));
    BOOST_ASSERT(1 == denominator(unit.fractional_part()));

    foo shoe_size(4, 5, 8);

    BOOST_ASSERT(4 == shoe_size.integral_part());
    BOOST_ASSERT(5 == numerator(shoe_size.fractional_part()));
    BOOST_ASSERT(8 == denominator(shoe_size.fractional_part()));

    foo shoe_size_minus_1(3, 5, 8);

    BOOST_ASSERT(3 == shoe_size_minus_1.integral_part());
    BOOST_ASSERT(5 == numerator(shoe_size_minus_1.fractional_part()));
    BOOST_ASSERT(8 == denominator(shoe_size_minus_1.fractional_part()));

    foo m_0_8_37(0, 8, 37);

    BOOST_ASSERT(0 == m_0_8_37.integral_part());
    BOOST_ASSERT(8 == numerator(m_0_8_37.fractional_part()));
    BOOST_ASSERT(37 == denominator(m_0_8_37.fractional_part()));

    foo shoe_size_inverse = unit;

    shoe_size_inverse /= shoe_size;
    BOOST_ASSERT(0 == shoe_size_inverse.integral_part());
    BOOST_ASSERT(37 == denominator(shoe_size_inverse.fractional_part()));
    BOOST_ASSERT(8 == numerator(shoe_size_inverse.fractional_part()));
    BOOST_ASSERT(shoe_size_inverse == m_0_8_37);
    --shoe_size;
    BOOST_ASSERT(shoe_size == shoe_size_minus_1);
    ++shoe_size;
    BOOST_ASSERT(!(shoe_size == shoe_size_minus_1));
    BOOST_ASSERT(shoe_size != shoe_size_minus_1);
    BOOST_ASSERT(shoe_size == shoe_size_minus_1 + unit);
    BOOST_ASSERT(shoe_size * shoe_size_inverse == unit);
    BOOST_ASSERT(shoe_size / shoe_size == unit);

//    test_math_real_type();
//    test_math_rational_type();
//    test_math_mixed_numeric_type();
//    test_math_complex_type();
    return ::boost::report_errors();
}
