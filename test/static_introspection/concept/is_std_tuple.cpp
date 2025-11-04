// Copyright (C) 2025 Cromwell D. Enage

#include <tuple>
#include <utility>
#include <odds_and_ends/static_introspection/concept/is_std_tuple.hpp>

void test_std_tuple()
{
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::std::pair<char,short> >::value
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_std_tuple< ::std::tuple<char,short> >::value
    );
}

#include <boost/core/lightweight_test.hpp>

int main(int argc, char** argv)
{
    test_std_tuple();
    return ::boost::report_errors();
}
