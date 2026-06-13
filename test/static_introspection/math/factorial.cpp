// Copyright (C) 2005-2026 Cromwell D. Enage

#include <type_traits>
#include <odds_and_ends/static_introspection/math/factorial.hpp>
#include <boost/mpl/aux_/test.hpp>

MPL_TEST_CASE()
{
    static_assert(
        1 == ::odds_and_ends::static_introspection::math::factorial<
            ::std::integral_constant<int,0>
        >::value,
        ""
    );
    static_assert(
        1 == ::odds_and_ends::static_introspection::math::factorial<
            ::std::integral_constant<int,1>
        >::value,
        ""
    );
    static_assert(
        2 == ::odds_and_ends::static_introspection::math::factorial<
            ::std::integral_constant<int,2>
        >::value,
        ""
    );
    static_assert(
        6 == ::odds_and_ends::static_introspection::math::factorial<
            ::std::integral_constant<int,3>
        >::value,
        ""
    );
    static_assert(
        24 == ::odds_and_ends::static_introspection::math::factorial<
            ::std::integral_constant<int,4>
        >::value,
        ""
    );
    static_assert(
        120 == ::odds_and_ends::static_introspection::math::factorial<
            ::std::integral_constant<int,5>
        >::value,
        ""
    );
    static_assert(
        720 == ::odds_and_ends::static_introspection::math::factorial<
            ::std::integral_constant<int,6>
        >::value,
        ""
    );
    static_assert(
        5040 == ::odds_and_ends::static_introspection::math::factorial<
            ::std::integral_constant<int,7>
        >::value,
        ""
    );
    static_assert(
        40320 == ::odds_and_ends::static_introspection::math::factorial<
            ::std::integral_constant<int,8>
        >::value,
        ""
    );
    static_assert(
        362880 == ::odds_and_ends::static_introspection::math::factorial<
            ::std::integral_constant<int,9>
        >::value,
        ""
    );
    static_assert(
        3628800 == ::odds_and_ends::static_introspection::math::factorial<
            ::std::integral_constant<int,10>
        >::value,
        ""
    );
}

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>

MPL_TEST_CASE()
{
    MPL_ASSERT((
        ::boost::mpl::equal_to<
            ::odds_and_ends::static_introspection::math::factorial< ::boost::mpl::int_<0> >,
            ::boost::mpl::int_<1>
        >
    ));
    MPL_ASSERT((
        ::boost::mpl::equal_to<
            ::odds_and_ends::static_introspection::math::factorial< ::boost::mpl::int_<1> >,
            ::boost::mpl::int_<1>
        >
    ));
    MPL_ASSERT((
        ::boost::mpl::equal_to<
            ::odds_and_ends::static_introspection::math::factorial< ::boost::mpl::int_<2> >,
            ::boost::mpl::int_<2>
        >
    ));
    MPL_ASSERT((
        ::boost::mpl::equal_to<
            ::odds_and_ends::static_introspection::math::factorial< ::boost::mpl::int_<3> >,
            ::boost::mpl::int_<6>
        >
    ));
    MPL_ASSERT((
        ::boost::mpl::equal_to<
            ::odds_and_ends::static_introspection::math::factorial< ::boost::mpl::int_<4> >,
            ::boost::mpl::int_<24>
        >
    ));
    MPL_ASSERT((
        ::boost::mpl::equal_to<
            ::odds_and_ends::static_introspection::math::factorial< ::boost::mpl::int_<5> >,
            ::boost::mpl::int_<120>
        >
    ));
    MPL_ASSERT((
        ::boost::mpl::equal_to<
            ::odds_and_ends::static_introspection::math::factorial< ::boost::mpl::int_<6> >,
            ::boost::mpl::int_<720>
        >
    ));
    MPL_ASSERT((
        ::boost::mpl::equal_to<
            ::odds_and_ends::static_introspection::math::factorial< ::boost::mpl::int_<7> >,
            ::boost::mpl::int_<5040>
        >
    ));
    MPL_ASSERT((
        ::boost::mpl::equal_to<
            ::odds_and_ends::static_introspection::math::factorial< ::boost::mpl::int_<8> >,
            ::boost::mpl::int_<40320>
        >
    ));
    MPL_ASSERT((
        ::boost::mpl::equal_to<
            ::odds_and_ends::static_introspection::math::factorial< ::boost::mpl::int_<9> >,
            ::boost::mpl::int_<362880>
        >
    ));
    MPL_ASSERT((
        ::boost::mpl::equal_to<
            ::odds_and_ends::static_introspection::math::factorial< ::boost::mpl::int_<10> >,
            ::boost::mpl::int_<3628800>
        >
    ));
}

