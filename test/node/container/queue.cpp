// Copyright (C) 2025-2026 Cromwell D. Enage

#include <odds_and_ends/node/container/queue.hpp>
#include <odds_and_ends/static_introspection/concept/is_queue.hpp>
#include <odds_and_ends/static_introspection/member_function/has_get_allocator.hpp>
#include <boost/core/lightweight_test.hpp>

int main(int argc, char** argv)
{
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_queue<
            ::odds_and_ends::node::container::queue<int>
        >::value,
        "Self-explanatory."
    );
    static_assert(
        ::odds_and_ends::static_introspection::member_function::has_get_allocator<
            ::odds_and_ends::node::container::queue<int>
        >::value,
        "::odds_and_ends::node::container::queue is Allocator-Aware."
    );
    ::odds_and_ends::node::container::queue<short> q0;
    BOOST_TEST(q0.empty());
    BOOST_TEST(0 == q0.size());
    q0.push(0);
    BOOST_TEST_NOT(q0.empty());
    BOOST_TEST(0 == q0.front());
    BOOST_TEST(1 == q0.size());
    q0.push(1);
    BOOST_TEST_NOT(q0.empty());
    BOOST_TEST(0 == q0.front());
    BOOST_TEST(2 == q0.size());
    q0.push(2);
    BOOST_TEST_NOT(q0.empty());
    BOOST_TEST(0 == q0.front());
    BOOST_TEST(3 == q0.size());
    q0.push(3);
    BOOST_TEST_NOT(q0.empty());
    BOOST_TEST(0 == q0.front());
    BOOST_TEST(4 == q0.size());
    q0.pop();
    BOOST_TEST_NOT(q0.empty());
    BOOST_TEST(1 == q0.front());
    BOOST_TEST(3 == q0.size());
    q0.pop();
    BOOST_TEST_NOT(q0.empty());
    BOOST_TEST(2 == q0.front());
    BOOST_TEST(2 == q0.size());
    ::odds_and_ends::node::container::queue<long> q1(q0);
    BOOST_TEST_NOT(q1.empty());
    BOOST_TEST(2 == q1.front());
    BOOST_TEST(2 == q1.size());
    q1.push(4);
    BOOST_TEST_NOT(q1.empty());
    BOOST_TEST(2 == q1.front());
    BOOST_TEST(3 == q1.size());
    q1.push(5);
    BOOST_TEST_NOT(q1.empty());
    BOOST_TEST(2 == q1.front());
    BOOST_TEST(4 == q1.size());
    q0.pop();
    BOOST_TEST_NOT(q0.empty());
    BOOST_TEST(3 == q0.front());
    BOOST_TEST(1 == q0.size());
    q0.pop();
    BOOST_TEST(q0.empty());
    BOOST_TEST(0 == q0.size());
    q1.pop();
    BOOST_TEST_NOT(q1.empty());
    BOOST_TEST(3 == q1.front());
    BOOST_TEST(3 == q1.size());
    q1.pop();
    BOOST_TEST_NOT(q1.empty());
    BOOST_TEST(4 == q1.front());
    BOOST_TEST(2 == q1.size());
    q1.pop();
    BOOST_TEST_NOT(q1.empty());
    BOOST_TEST(5 == q1.front());
    BOOST_TEST(1 == q1.size());
    q1.pop();
    BOOST_TEST(q1.empty());
    BOOST_TEST(0 == q1.size());
    return ::boost::report_errors();
}

