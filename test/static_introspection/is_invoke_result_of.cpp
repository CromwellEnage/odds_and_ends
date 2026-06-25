// Copyright (C) 2025-2026 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <odds_and_ends/static_introspection/is_invoke_result_of.hpp>
#include <boost/core/lightweight_test.hpp>

struct foo
{
    bool operator()(int&, char*)
    {
        return true;
    }
};

int main(int argc, char** argv)
{
    static_assert(
        ::odds_and_ends::static_introspection
        ::is_invoke_result_of<bool,foo,int&,char*>::value,
        "bool is the result of invoking foo(int&, char*)"
    );
    return ::boost::report_errors();
}
