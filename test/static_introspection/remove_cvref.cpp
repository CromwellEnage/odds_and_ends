// Copyright (C) 2025-2026 Cromwell D. Enage

#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <type_traits>
#include <functional>
#include <boost/core/ref.hpp>
#include <boost/core/lightweight_test.hpp>

int main(int argc, char** argv)
{
    static_assert(
        ::std::is_same<
            ::odds_and_ends::static_introspection::remove_cvref<
                int const volatile&
            >::type,
            int
        >::value,
        "remove_cvref must convert int const volatile& to int"
    );
    static_assert(
        ::std::is_same<
            ::odds_and_ends::static_introspection::remove_cvref<
                ::std::reference_wrapper<int const volatile>
            >::type,
            int
        >::value,
        "remove_cvref must convert ref(int const volatile) to int"
    );
    static_assert(
        ::std::is_same<
            ::odds_and_ends::static_introspection::remove_cvref<
                ::boost::reference_wrapper<int const volatile>
            >::type,
            int
        >::value,
        "remove_cvref must convert ref(int const volatile) to int"
    );
    return ::boost::report_errors();
}
