// Copyright (C) 2025 Cromwell D. Enage

#include <odds_and_ends/node/red_black.hpp>
#include <odds_and_ends/node/balancer/left_leaning_red_black_tree.hpp>
#include <odds_and_ends/node/container/deque.hpp>

template <typename T>
struct deque_generator
{
    typedef ::odds_and_ends::node::container::deque<
        T,
        ::boost::mpl::deque< ::odds_and_ends::node::red_black>,
        ::odds_and_ends::node::left_leaning_red_black_tree_balancer
    > type;
};

#include <odds_and_ends/node/data.hpp>
#include <odds_and_ends/node/tree/base.hpp>
#include <odds_and_ends/node/tree/nary.hpp>
#include <odds_and_ends/composite_type/composite_type.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/mpl/quote.hpp>

typedef ::odds_and_ends::composite_type::composite_type<
    ::boost::mpl::deque<
        ::odds_and_ends::node::data<int>,
        ::odds_and_ends::node::tree::base<>,
        ::odds_and_ends::node::tree::nary< ::boost::mpl::quote1< deque_generator> >
    >
> nary_tree_node;

#include <boost/core/lightweight_test.hpp>

void test_00()
{
    nary_tree_node p02(2);
    nary_tree_node p03(3);
    nary_tree_node p05(5);
    nary_tree_node p07(7);
    nary_tree_node p09(9);

    BOOST_TEST(p02.is_leaf());
    BOOST_TEST(p02.begin() == p02.end());
    BOOST_TEST(p03.is_leaf());
    BOOST_TEST(p03.begin() == p03.end());
    BOOST_TEST(p05.is_leaf());
    BOOST_TEST(p05.begin() == p05.end());
    BOOST_TEST(p07.is_leaf());
    BOOST_TEST(p07.begin() == p07.end());
    BOOST_TEST(p09.is_leaf());
    BOOST_TEST(p09.begin() == p09.end());
    p05.push_front(&p03);
    p05.push_front(&p02);
    p05.push_back(&p07);
    p05.push_back(&p09);
    BOOST_TEST(2 == **p05.begin());
    BOOST_TEST(3 == **(p05.begin() + 1));
    BOOST_TEST(7 == **(p05.begin() + 2));
    BOOST_TEST(9 == **(p05.begin() + 3));
    p05.clear();
    BOOST_TEST(p05.is_leaf());
    BOOST_TEST(p05.begin() == p05.end());
}

void test_01()
{
}

int main(int argc, char** argv)
{
    test_00();
//    test_01();
    return ::boost::report_errors();
}

