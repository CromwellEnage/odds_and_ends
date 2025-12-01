// Copyright (C) 2025 Cromwell D. Enage

#include <odds_and_ends/node/data.hpp>
#include <odds_and_ends/node/tree/base.hpp>
#include <odds_and_ends/node/tree/binary.hpp>
#include <odds_and_ends/composite_type/composite_type.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/core/lightweight_test.hpp>

int main(int argc, char** argv)
{
    typedef ::odds_and_ends::composite_type::composite_type<
        ::boost::mpl::deque<
            ::odds_and_ends::node::data<int>,
            ::odds_and_ends::node::tree::base<>,
            ::odds_and_ends::node::tree::binary<>
        >
    > binary_tree_node;

    binary_tree_node n09(9);
    binary_tree_node n17(17);
    binary_tree_node n23(23);
    binary_tree_node n50(50);
    binary_tree_node n76(76);

    BOOST_TEST(9 == *n09);
    BOOST_TEST(17 == *n17);
    BOOST_TEST(23 == *n23);
    BOOST_TEST(50 == *n50);
    BOOST_TEST(76 == *n76);
    n50.set_left(n17);
    n50.set_right(n76);
    n17.set_left(n09);
    n17.set_right(n23);
    BOOST_TEST(!n50.parent());
    BOOST_TEST(50 == **n17.parent());
    BOOST_TEST(17 == **n50.left());
    BOOST_TEST(50 == **n76.parent());
    BOOST_TEST(76 == **n50.right());
    BOOST_TEST(17 == **n09.parent());
    BOOST_TEST(9 == **n17.left());
    BOOST_TEST(17 == **n23.parent());
    BOOST_TEST(23 == **n17.right());
    BOOST_TEST(!n09.left());
    BOOST_TEST(!n09.right());
    BOOST_TEST(!n23.left());
    BOOST_TEST(!n23.right());
    BOOST_TEST(!n76.left());
    BOOST_TEST(!n76.right());

    binary_tree_node::traits::child_const_iterator fwd_itr = n50.begin();

    BOOST_TEST(17 == **fwd_itr);
    ++fwd_itr;
    BOOST_TEST(76 == **fwd_itr);
    ++fwd_itr;
    BOOST_TEST(fwd_itr == n50.end());
    fwd_itr = n17.begin();
    BOOST_TEST(9 == **fwd_itr);
    ++fwd_itr;
    BOOST_TEST(23 == **fwd_itr);
    ++fwd_itr;
    BOOST_TEST(fwd_itr == n17.end());

    binary_tree_node::traits::child_const_reverse_iterator rev_itr = n50.rbegin();

    BOOST_TEST(76 == **rev_itr);
    ++rev_itr;
    BOOST_TEST(17 == **rev_itr);
    ++rev_itr;
    BOOST_TEST(rev_itr == n50.rend());
    rev_itr = n17.rbegin();
    BOOST_TEST(23 == **rev_itr);
    ++rev_itr;
    BOOST_TEST(9 == **rev_itr);
    ++rev_itr;
    BOOST_TEST(rev_itr == n17.rend());

    binary_tree_node::traits::pointer rotate_result = n50.rotate_right();

    BOOST_TEST(17 == **rotate_result);
    BOOST_TEST(!n17.parent());
    BOOST_TEST(17 == **n09.parent());
    BOOST_TEST(9 == **n17.left());
    BOOST_TEST(17 == **n50.parent());
    BOOST_TEST(50 == **n17.right());
    BOOST_TEST(50 == **n23.parent());
    BOOST_TEST(23 == **n50.left());
    BOOST_TEST(50 == **n76.parent());
    BOOST_TEST(76 == **n50.right());
    BOOST_TEST(!n09.left());
    BOOST_TEST(!n09.right());
    BOOST_TEST(!n23.left());
    BOOST_TEST(!n23.right());
    BOOST_TEST(!n76.left());
    BOOST_TEST(!n76.right());
    fwd_itr = n17.begin();
    BOOST_TEST(9 == **fwd_itr);
    ++fwd_itr;
    BOOST_TEST(50 == **fwd_itr);
    ++fwd_itr;
    BOOST_TEST(fwd_itr == n17.end());
    fwd_itr = n50.begin();
    BOOST_TEST(23 == **fwd_itr);
    ++fwd_itr;
    BOOST_TEST(76 == **fwd_itr);
    ++fwd_itr;
    BOOST_TEST(fwd_itr == n50.end());
    rev_itr = n17.rbegin();
    BOOST_TEST(50 == **rev_itr);
    ++rev_itr;
    BOOST_TEST(9 == **rev_itr);
    ++rev_itr;
    BOOST_TEST(rev_itr == n17.rend());
    rev_itr = n50.rbegin();
    BOOST_TEST(76 == **rev_itr);
    ++rev_itr;
    BOOST_TEST(23 == **rev_itr);
    ++rev_itr;
    BOOST_TEST(rev_itr == n50.rend());
    rotate_result = n17.rotate_left();
    BOOST_TEST(50 == **rotate_result);
    BOOST_TEST(!n50.parent());
    BOOST_TEST(50 == **n17.parent());
    BOOST_TEST(17 == **n50.left());
    BOOST_TEST(50 == **n76.parent());
    BOOST_TEST(76 == **n50.right());
    BOOST_TEST(17 == **n09.parent());
    BOOST_TEST(9 == **n17.left());
    BOOST_TEST(17 == **n23.parent());
    BOOST_TEST(23 == **n17.right());
    BOOST_TEST(!n09.left());
    BOOST_TEST(!n09.right());
    BOOST_TEST(!n23.left());
    BOOST_TEST(!n23.right());
    BOOST_TEST(!n76.left());
    BOOST_TEST(!n76.right());
    fwd_itr = n50.begin();
    BOOST_TEST(17 == **fwd_itr);
    ++fwd_itr;
    BOOST_TEST(76 == **fwd_itr);
    ++fwd_itr;
    BOOST_TEST(fwd_itr == n50.end());
    fwd_itr = n17.begin();
    BOOST_TEST(9 == **fwd_itr);
    ++fwd_itr;
    BOOST_TEST(23 == **fwd_itr);
    ++fwd_itr;
    BOOST_TEST(fwd_itr == n17.end());
    rev_itr = n50.rbegin();
    BOOST_TEST(76 == **rev_itr);
    ++rev_itr;
    BOOST_TEST(17 == **rev_itr);
    ++rev_itr;
    BOOST_TEST(rev_itr == n50.rend());
    rev_itr = n17.rbegin();
    BOOST_TEST(23 == **rev_itr);
    ++rev_itr;
    BOOST_TEST(9 == **rev_itr);
    ++rev_itr;
    BOOST_TEST(rev_itr == n17.rend());
    return ::boost::report_errors();
}

