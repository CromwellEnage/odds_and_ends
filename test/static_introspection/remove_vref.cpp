// Copyright (C) 2025-2026 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <odds_and_ends/static_introspection/remove_vref.hpp>
#include <type_traits>
#include <functional>
#include <boost/core/ref.hpp>
#include <boost/core/lightweight_test.hpp>

int main(int argc, char** argv)
{
    static_assert(
        ::std::is_same<
            ::odds_and_ends::static_introspection::remove_vref<
                int const volatile&
            >::type,
            int const
        >::value,
        "remove_vref must convert int const volatile& to int const"
    );
    static_assert(
        ::std::is_same<
            ::odds_and_ends::static_introspection::remove_vref<
                ::std::reference_wrapper<int const volatile>
            >::type,
            int const
        >::value,
        "remove_vref must convert ref(int const volatile) to int const"
    );
    static_assert(
        ::std::is_same<
            ::odds_and_ends::static_introspection::remove_vref<
                ::boost::reference_wrapper<int const volatile>
            >::type,
            int const
        >::value,
        "remove_vref must convert ref(int const volatile) to int const"
    );
    return ::boost::report_errors();
}
