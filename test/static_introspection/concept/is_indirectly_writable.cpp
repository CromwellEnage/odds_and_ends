// Copyright (C) 2025-2026 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

struct foo
{
    int x;
    foo& operator=(foo const&) = default;
};

struct bar
{
    foo* b;
    bar& operator=(bar const&) = default;
    bar const& operator=(foo const& f) const
    {
        *b = f;
        return *this;
    }
};

struct s1 { foo& operator*(); };
struct s2 { foo operator*(); };
struct s3 { bar operator*(); };

#include <odds_and_ends/static_introspection/concept/is_indirectly_writable.hpp>
#include <boost/core/lightweight_test.hpp>

int main(int argc, char** argv)
{
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_indirectly_writable<s1,foo>::value,
        "The expression '*declmref<s1>() = forward<foo>(declval<foo>())' is valid."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_indirectly_writable<s2,foo>::value,
        "The expression '*declmref<s2>() = forward<foo>(declval<foo>())' is invalid."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_indirectly_writable<s3,foo>::value,
        "The expression '*declmref<s3>() = forward<foo>(declval<foo>())' is valid."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept::is_indirectly_writable<s3,bar>::value,
        "The expression '*declmref<s3>() = forward<foo>(declval<bar>())' is invalid."
    );
    return ::boost::report_errors();
}
