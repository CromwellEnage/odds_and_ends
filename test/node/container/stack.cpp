// Copyright (C) 2025-2026 Cromwell D. Enage

#include <odds_and_ends/node/container/stack.hpp>
#include <odds_and_ends/static_introspection/concept/is_stack_or_heap.hpp>
#include <odds_and_ends/static_introspection/member_function/has_get_allocator.hpp>
#include <boost/core/lightweight_test.hpp>

int main(int argc, char** argv)
{
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_stack_or_heap<
            ::odds_and_ends::node::container::stack<int>
        >::value,
        "Self-explanatory."
    );
    static_assert(
        ::odds_and_ends::static_introspection::member_function::has_get_allocator<
            ::odds_and_ends::node::container::stack<int>
        >::value,
        "::odds_and_ends::node::container::stack is Allocator-Aware."
    );
    ::odds_and_ends::node::container::stack<short> s0;
    BOOST_TEST(s0.empty());
    BOOST_TEST(0 == s0.size());
    s0.push(0);
    BOOST_TEST_NOT(s0.empty());
    BOOST_TEST(0 == s0.top());
    BOOST_TEST(1 == s0.size());
    s0.push(1);
    BOOST_TEST_NOT(s0.empty());
    BOOST_TEST(1 == s0.top());
    BOOST_TEST(2 == s0.size());
    s0.push(2);
    BOOST_TEST_NOT(s0.empty());
    BOOST_TEST(2 == s0.top());
    BOOST_TEST(3 == s0.size());
    s0.push(3);
    BOOST_TEST_NOT(s0.empty());
    BOOST_TEST(3 == s0.top());
    BOOST_TEST(4 == s0.size());
    s0.pop();
    BOOST_TEST_NOT(s0.empty());
    BOOST_TEST(2 == s0.top());
    BOOST_TEST(3 == s0.size());
    s0.pop();
    BOOST_TEST_NOT(s0.empty());
    BOOST_TEST(1 == s0.top());
    BOOST_TEST(2 == s0.size());
    ::odds_and_ends::node::container::stack<long> s1(s0);
    BOOST_TEST_NOT(s1.empty());
    BOOST_TEST(1 == s1.top());
    BOOST_TEST(2 == s1.size());
    s1.push(4);
    BOOST_TEST_NOT(s1.empty());
    BOOST_TEST(4 == s1.top());
    BOOST_TEST(3 == s1.size());
    s1.push(5);
    BOOST_TEST_NOT(s1.empty());
    BOOST_TEST(5 == s1.top());
    BOOST_TEST(4 == s1.size());
    s0.pop();
    BOOST_TEST_NOT(s0.empty());
    BOOST_TEST(0 == s0.top());
    BOOST_TEST(1 == s0.size());
    s0.pop();
    BOOST_TEST(s0.empty());
    BOOST_TEST(0 == s0.size());
    s1.pop();
    BOOST_TEST_NOT(s1.empty());
    BOOST_TEST(4 == s1.top());
    BOOST_TEST(3 == s1.size());
    s1.pop();
    BOOST_TEST_NOT(s1.empty());
    BOOST_TEST(1 == s1.top());
    BOOST_TEST(2 == s1.size());
    s1.pop();
    BOOST_TEST_NOT(s1.empty());
    BOOST_TEST(0 == s1.top());
    BOOST_TEST(1 == s1.size());
    s1.pop();
    BOOST_TEST(s1.empty());
    BOOST_TEST(0 == s1.size());
    return ::boost::report_errors();
}

