// Copyright (C) 2025 Cromwell D. Enage

#include <odds_and_ends/node/container/queue.hpp>
#include <odds_and_ends/static_introspection/concept/is_queue.hpp>
#include <boost/core/lightweight_test.hpp>

int main(int argc, char** argv)
{
/*
    static_assert(
        ::odds_and_ends::static_introspection::concept::is_queue<
            ::odds_and_ends::node::container::queue<int>
        >::value,
        "Self-explanatory."
    );
*/
    ::odds_and_ends::node::container::queue<int> q;
    BOOST_TEST(q.empty());
    BOOST_TEST(0 == q.size());
    q.push(0);
    BOOST_TEST_NOT(q.empty());
    BOOST_TEST(0 == q.front());
    BOOST_TEST(1 == q.size());
    q.push(1);
    BOOST_TEST_NOT(q.empty());
    BOOST_TEST(0 == q.front());
    BOOST_TEST(2 == q.size());
    q.push(2);
    BOOST_TEST_NOT(q.empty());
    BOOST_TEST(0 == q.front());
    BOOST_TEST(3 == q.size());
    q.push(3);
    BOOST_TEST_NOT(q.empty());
    BOOST_TEST(0 == q.front());
    BOOST_TEST(4 == q.size());
    q.pop();
    BOOST_TEST_NOT(q.empty());
    BOOST_TEST(1 == q.front());
    BOOST_TEST(3 == q.size());
    q.pop();
    BOOST_TEST_NOT(q.empty());
    BOOST_TEST(2 == q.front());
    BOOST_TEST(2 == q.size());
    q.pop();
    BOOST_TEST_NOT(q.empty());
    BOOST_TEST(3 == q.front());
    BOOST_TEST(1 == q.size());
    q.pop();
    BOOST_TEST(q.empty());
    BOOST_TEST(0 == q.size());
    return ::boost::report_errors();
}

