// Copyright (C) 2025 Cromwell D. Enage

#include <odds_and_ends/static_introspection/is_invoke_result_of.hpp>
#include <boost/core/lightweight_test.hpp>

struct foo
{
    bool operator()(int&, char*)
    {
        return true;
    }
};

struct bar
{
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
