// Copyright (C) 2025 Cromwell D. Enage

#include <odds_and_ends/static_introspection/invoke_result.hpp>
#include <type_traits>
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
        ::std::is_same<
            ::odds_and_ends::static_introspection
            ::invoke_result<foo,int&,char*>::type,
            bool
        >::value,
        "bool is the return type of foo"
    );
    return ::boost::report_errors();
}
