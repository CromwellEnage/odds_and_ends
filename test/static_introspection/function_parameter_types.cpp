// Copyright (C) 2025 Cromwell D. Enage

#include <odds_and_ends/static_introspection/function_parameter_types.hpp>
#include <type_traits>
#include <boost/mpl/at.hpp>
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
        ::std::is_same<
            ::boost::mpl::at_c<
                ::odds_and_ends::static_introspection
                ::function_parameter_types<
                    foo(int&, char*)
                >::type,
                0
            >::type,
            int&
        >::value,
        "int& is the first parameter type of foo"
    );
    static_assert(
        ::std::is_same<
            ::boost::mpl::at_c<
                ::odds_and_ends::static_introspection
                ::function_parameter_types<
                    foo(int&, char*)
                >::type,
                1
            >::type,
            char*
        >::value,
        "char* is the second parameter type of foo"
    );
    return ::boost::report_errors();
}
