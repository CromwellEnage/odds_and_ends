// Copyright (C) 2025 Cromwell D. Enage

#include <odds_and_ends/node/container/stack.hpp>
#include <odds_and_ends/static_introspection/concept/is_stack_or_heap.hpp>
#include <boost/core/lightweight_test.hpp>

int main(int argc, char** argv)
{
/*
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_stack_or_heap<
            ::odds_and_ends::node::container::stack<int>
        >::value,
        "Self-explanatory."
    );
*/
    ::odds_and_ends::node::container::stack<int> s;
    BOOST_TEST(s.empty());
    BOOST_TEST(0 == s.size());
    s.push(0);
    BOOST_TEST_NOT(s.empty());
    BOOST_TEST(0 == s.top());
    BOOST_TEST(1 == s.size());
    s.push(1);
    BOOST_TEST_NOT(s.empty());
    BOOST_TEST(1 == s.top());
    BOOST_TEST(2 == s.size());
    s.push(2);
    BOOST_TEST_NOT(s.empty());
    BOOST_TEST(2 == s.top());
    BOOST_TEST(3 == s.size());
    s.push(3);
    BOOST_TEST_NOT(s.empty());
    BOOST_TEST(3 == s.top());
    BOOST_TEST(4 == s.size());
    s.pop();
    BOOST_TEST_NOT(s.empty());
    BOOST_TEST(2 == s.top());
    BOOST_TEST(3 == s.size());
    s.pop();
    BOOST_TEST_NOT(s.empty());
    BOOST_TEST(1 == s.top());
    BOOST_TEST(2 == s.size());
    s.pop();
    BOOST_TEST_NOT(s.empty());
    BOOST_TEST(0 == s.top());
    BOOST_TEST(1 == s.size());
    s.pop();
    BOOST_TEST(s.empty());
    BOOST_TEST(0 == s.size());
    return ::boost::report_errors();
}

