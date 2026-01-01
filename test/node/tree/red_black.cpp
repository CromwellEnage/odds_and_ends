// Copyright (C) 2025 Cromwell D. Enage

#include <iostream>
#include <odds_and_ends/node/data.hpp>
#include <odds_and_ends/node/red_black.hpp>
#include <odds_and_ends/node/tree/base.hpp>
#include <odds_and_ends/node/tree/binary.hpp>
#include <odds_and_ends/node/tree/with_size.hpp>
#include <odds_and_ends/node/balancer/left_leaning_red_black_tree.hpp>
#include <odds_and_ends/node/algorithm/red_black_tree_test.hpp>
#include <odds_and_ends/composite_type/composite_type.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/core/lightweight_test.hpp>

typedef ::odds_and_ends::composite_type::composite_type<
    ::boost::mpl::deque<
        ::odds_and_ends::node::data<int>,
        ::odds_and_ends::node::red_black,
        ::odds_and_ends::node::tree::base<>,
        ::odds_and_ends::node::tree::binary<>,
        ::odds_and_ends::node::tree::with_size<>
    >
> binary_tree_node;

void
    output_error(
        binary_tree_node::traits::size_type const& index,
        ::odds_and_ends::node::algorithm::red_black_tree_test_bit b
    )
{
    switch (b)
    {
        case ::odds_and_ends::node::algorithm
        ::red_black_tree_test_bit_for_red_node_with_red_parent:
        {
            ::std::cout << "    Node at in-order position " << index;
            ::std::cout << " is a red node with a red parent." << std::endl;
            break;
        }

        case ::odds_and_ends::node::algorithm
        ::red_black_tree_test_bit_for_black_node_with_single_left_black_child:
        {
            ::std::cout << "    Node at in-order position " << index;
            ::std::cout << " is a black node with only a left child, which is black.";
            ::std::cout << std::endl;
            break;
        }

        case ::odds_and_ends::node::algorithm
        ::red_black_tree_test_bit_for_black_node_with_single_right_black_child:
        {
            ::std::cout << "    Node at in-order position " << index;
            ::std::cout << " is a black node with only a right child, which is black.";
            ::std::cout << std::endl;
            break;
        }

        default:
        {
            break;
        }
    }
}

void output_depth(::std::size_t const& index, binary_tree_node::traits::size_type const& depth)
{
    ::std::cout << "    Node at in-order position " << index;
    ::std::cout << " has red-black depth " << depth << '.' << ::std::endl;
}

#include <odds_and_ends/node/iterator/in_order_tree.hpp>

typedef ::odds_and_ends::node::in_order_tree_iterator<binary_tree_node const> node_itr;

void output_tree(node_itr itr)
{
    for (; !(!itr); ++itr)
    {
        ::std::cout << "    Node " << **itr << " is " << (itr->red() ? "red" : "black");

        if (itr->parent())
        {
            ::std::cout << ", has parent " << **itr->parent();
        }
        else
        {
            ::std::cout << ", has no parent";
        }

        if (itr->left())
        {
            ::std::cout << ", has left child " << **itr->left();
        }
        else
        {
            ::std::cout << ", has no left child";
        }

        if (itr->right())
        {
            ::std::cout << ", has right child " << **itr->right();
        }
        else
        {
            ::std::cout << ", has no right child";
        }

        ::std::cout << ", and has size " << itr->size() << '.' << ::std::endl;
    }
}

void test_insert_case_00_00()
{
    binary_tree_node parent(1);
    binary_tree_node child(0);

    parent.set_left(child);
    ::std::cout << "Test post_insert() case 00.00" << ::std::endl;

    binary_tree_node::traits::pointer result = (
        ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_insert(child)
    );

    output_tree(node_itr(parent, false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::red_black_tree_test(parent, output_error, output_depth)
    );

    binary_tree_node sibling(-1);

    child.set_left(sibling);
    ::std::cout << "Test post_insert() case 00.03" << ::std::endl;
    result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_insert(sibling);
    BOOST_TEST(!result->parent());
    output_tree(node_itr(*result, false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::red_black_tree_test(*result, output_error, output_depth)
    );
}

void test_insert_case_00_01()
{
    binary_tree_node parent(0);
    binary_tree_node child(1);

    parent.set_right(child);
    ::std::cout << "Test post_insert() case 00.01" << ::std::endl;

    binary_tree_node::traits::pointer result = (
        ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_insert(child)
    );

    BOOST_TEST(!result->parent());
    output_tree(node_itr(*result, false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::red_black_tree_test(*result, output_error, output_depth)
    );

    binary_tree_node sibling(2);

    child.set_right(sibling);
    ::std::cout << "Test post_insert() case 00.02" << ::std::endl;
    result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_insert(sibling);
    output_tree(node_itr(child, false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::red_black_tree_test(child, output_error, output_depth)
    );
}

void test_insert_case_00_02()
{
    binary_tree_node grandparent(2);
    binary_tree_node parent(0);

    grandparent.set_left(parent);

    binary_tree_node::traits::pointer result = (
        ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_insert(parent)
    );
    binary_tree_node child(1);

    parent.set_right(child);
    ::std::cout << "Test post_insert() case 00.04" << ::std::endl;
    result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_insert(child);
    BOOST_TEST(!result->parent());
    output_tree(node_itr(*result, false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::red_black_tree_test(*result, output_error, output_depth)
    );
}

void test_insert_case_01_00()
{
    binary_tree_node grandparent(2);
    binary_tree_node parent(1);
    binary_tree_node uncle(3);
    binary_tree_node child(0);

    grandparent.set_left(parent);
    grandparent.set_right(uncle);
    uncle.red(true);
    parent.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(grandparent));
    parent.set_left(child);
    ::std::cout << "Test post_insert() case 01.00" << ::std::endl;

    binary_tree_node::traits::pointer result = (
        ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_insert(child)
    );

    if (result->parent())
    {
        output_tree(node_itr(grandparent, false));
        BOOST_TEST(
            ::odds_and_ends::node::algorithm
            ::red_black_tree_test(grandparent, output_error, output_depth)
        );
    }
    else
    {
        output_tree(node_itr(*result, false));
        BOOST_TEST(
            ::odds_and_ends::node::algorithm
            ::red_black_tree_test(*result, output_error, output_depth)
        );
    }
}

void test_insert_case_01_01()
{
    binary_tree_node grandparent(2);
    binary_tree_node parent(0);
    binary_tree_node uncle(3);
    binary_tree_node child(1);

    grandparent.set_left(parent);
    grandparent.set_right(uncle);
    uncle.red(true);
    parent.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(grandparent));
    parent.set_right(child);
    ::std::cout << "Test post_insert() case 01.01" << ::std::endl;

    binary_tree_node::traits::pointer result = (
        ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_insert(child)
    );

    if (result->parent())
    {
        output_tree(node_itr(grandparent, false));
        BOOST_TEST(
            ::odds_and_ends::node::algorithm
            ::red_black_tree_test(grandparent, output_error, output_depth)
        );
    }
    else
    {
        output_tree(node_itr(*result, false));
        BOOST_TEST(
            ::odds_and_ends::node::algorithm
            ::red_black_tree_test(*result, output_error, output_depth)
        );
    }
}

void test_insert_case_01_02()
{
    binary_tree_node grandparent(2);
    binary_tree_node parent(0);
    binary_tree_node uncle(3);
    binary_tree_node child(1);

    grandparent.set_right(parent);
    grandparent.set_left(uncle);
    uncle.red(true);
    parent.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(grandparent));
    parent.set_left(child);
    ::std::cout << "Test post_insert() case 01.02" << ::std::endl;

    binary_tree_node::traits::pointer result = (
        ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_insert(child)
    );

    if (result->parent())
    {
        output_tree(node_itr(grandparent, false));
        BOOST_TEST(
            ::odds_and_ends::node::algorithm
            ::red_black_tree_test(grandparent, output_error, output_depth)
        );
    }
    else
    {
        output_tree(node_itr(*result, false));
        BOOST_TEST(
            ::odds_and_ends::node::algorithm
            ::red_black_tree_test(*result, output_error, output_depth)
        );
    }
}

void test_insert_case_01_03()
{
    binary_tree_node grandparent(2);
    binary_tree_node parent(1);
    binary_tree_node uncle(3);
    binary_tree_node child(0);

    grandparent.set_right(parent);
    grandparent.set_left(uncle);
    uncle.red(true);
    parent.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(grandparent));
    parent.set_right(child);
    ::std::cout << "Test post_insert() case 01.03" << ::std::endl;

    binary_tree_node::traits::pointer result = (
        ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_insert(child)
    );

    if (result->parent())
    {
        output_tree(node_itr(grandparent, false));
        BOOST_TEST(
            ::odds_and_ends::node::algorithm
            ::red_black_tree_test(grandparent, output_error, output_depth)
        );
    }
    else
    {
        output_tree(node_itr(*result, false));
        BOOST_TEST(
            ::odds_and_ends::node::algorithm
            ::red_black_tree_test(*result, output_error, output_depth)
        );
    }
}

void test_post_fill_and_insert()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);
    binary_tree_node n06(6);
    binary_tree_node n08(8);
    binary_tree_node n11(11);
    binary_tree_node n13(13);
    binary_tree_node n15(15);
    binary_tree_node n17(17);
    binary_tree_node n22(22);
    binary_tree_node n25(25);
    binary_tree_node n27(27);

    n06.set_left(n01);
    n08.set_left(n06);
    n08.set_right(n11);
    n13.set_left(n08);
    n13.set_right(n17);
    n17.set_left(n15);
    n17.set_right(n25);
    n25.set_left(n22);
    n25.set_right(n27);
    ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_fill(n13);
    ::std::cout << "Test post_fill()" << ::std::endl;
    ::odds_and_ends::node::algorithm::red_black_tree_test(n13, output_error, output_depth);
    n08.red(true);
    n17.red(true);
    n01.set_left(n00);
    ::std::cout << "Test post_insert() case 2.0" << ::std::endl;

    binary_tree_node::traits::pointer result = (
        ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_insert(n00)
    );

    if (result->parent())
    {
        output_tree(node_itr(n13, false));
        BOOST_TEST(
            ::odds_and_ends::node::algorithm
            ::red_black_tree_test(n13, output_error, output_depth)
        );
    }
    else
    {
        output_tree(node_itr(*result, false));
        BOOST_TEST(
            ::odds_and_ends::node::algorithm
            ::red_black_tree_test(*result, output_error, output_depth)
        );
    }
}

void test_insert_case_02_00()
{
    binary_tree_node n01(1);
    binary_tree_node n06(6);
    binary_tree_node n08(8);
    binary_tree_node n11(11);
    binary_tree_node n13(13);
    binary_tree_node n15(15);
    binary_tree_node n17(17);
    binary_tree_node n20(20);
    binary_tree_node n22(22);
    binary_tree_node n25(25);
    binary_tree_node n27(27);

    n06.set_left(n01);
    n08.set_left(n06);
    n08.set_right(n11);
    n13.set_left(n08);
    n13.set_right(n17);
    n17.set_left(n15);
    n17.set_right(n25);
    n25.set_left(n22);
    n25.set_right(n27);
    ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_fill(n13);
    n08.red(true);
    n17.red(true);
    n22.set_left(n20);
    ::std::cout << "Test post_insert() case 02.00" << ::std::endl;

    binary_tree_node::traits::pointer result = (
        ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_insert(n20)
    );

    if (result->parent())
    {
        output_tree(node_itr(n13, false));
        BOOST_TEST(
            ::odds_and_ends::node::algorithm
            ::red_black_tree_test(n13, output_error, output_depth)
        );
    }
    else
    {
        output_tree(node_itr(*result, false));
        BOOST_TEST(
            ::odds_and_ends::node::algorithm
            ::red_black_tree_test(*result, output_error, output_depth)
        );
    }
}

void test_insert_case_02_01()
{
    binary_tree_node n08(-8);
    binary_tree_node n07(-7);
    binary_tree_node n06(-6);
    binary_tree_node n05(-5);
    binary_tree_node n04(-4);
    binary_tree_node n03(-3);
    binary_tree_node n02(-2);
    binary_tree_node n01(-1);
    binary_tree_node o00(0);
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);
    binary_tree_node p08(8);

    n06.set_left(n07);
    n06.set_right(n05);
    n04.set_left(n06);
    n04.set_right(n03);
    n02.set_left(n04);
    n02.set_right(n01);
    o00.set_left(n02);
    o00.set_right(p02);
    p02.set_left(p01);
    p02.set_right(p04);
    p04.set_left(p03);
    p04.set_right(p06);
    p06.set_left(p05);
    p06.set_right(p07);
    n07.red(true);
    n05.red(true);
    n04.red(true);
    p04.red(true);
    p05.red(true);
    p07.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(o00));
    n07.set_left(n08);
    ::std::cout << "Test post_insert() case 02.01" << ::std::endl;

    binary_tree_node::traits::pointer result = (
        ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_insert(n08)
    );

    output_tree(node_itr(o00, false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(o00, output_error, output_depth)
    );
    p07.set_right(p08);
    ::std::cout << "Test post_insert() case 02.02" << ::std::endl;
    result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_insert(p08);
    output_tree(node_itr(o00, false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(o00, output_error, output_depth)
    );
}

void test_insert_case_02_02()
{
    binary_tree_node n08(-8);
    binary_tree_node n07(-7);
    binary_tree_node n06(-6);
    binary_tree_node n05(-5);
    binary_tree_node n04(-4);
    binary_tree_node n03(-3);
    binary_tree_node n02(-2);
    binary_tree_node n01(-1);
    binary_tree_node o00(0);
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);
    binary_tree_node p08(8);

    n07.set_left(n08);
    n07.set_right(n05);
    n05.set_left(n06);
    n05.set_right(n03);
    n02.set_left(n07);
    n02.set_right(n01);
    o00.set_left(n02);
    o00.set_right(p02);
    p02.set_left(p01);
    p02.set_right(p07);
    p05.set_left(p03);
    p05.set_right(p06);
    p07.set_left(p05);
    p07.set_right(p08);
    n07.red(true);
    n06.red(true);
    n03.red(true);
    p03.red(true);
    p06.red(true);
    p07.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(o00));
    n03.set_left(n04);
    ::std::cout << "Test post_insert() case 02.03" << ::std::endl;

    binary_tree_node::traits::pointer result = (
        ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_insert(n04)
    );

    output_tree(node_itr(o00, false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(o00, output_error, output_depth)
    );
    p03.set_right(p04);
    ::std::cout << "Test post_insert() case 02.04" << ::std::endl;
    result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_insert(p04);
    output_tree(node_itr(o00, false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(o00, output_error, output_depth)
    );
}

void test_insert_case_02_03()
{
    binary_tree_node n26(-26);
    binary_tree_node n25(-25);
    binary_tree_node n24(-24);
    binary_tree_node n23(-23);
    binary_tree_node n22(-22);
    binary_tree_node n21(-21);
    binary_tree_node n20(-20);
    binary_tree_node n19(-19);
    binary_tree_node n18(-18);
    binary_tree_node n17(-17);
    binary_tree_node n16(-16);
    binary_tree_node n15(-15);
    binary_tree_node n14(-14);
    binary_tree_node n13(-13);
    binary_tree_node n12(-12);
    binary_tree_node n11(-11);
    binary_tree_node n10(-10);
    binary_tree_node n09(-9);
    binary_tree_node n08(-8);
    binary_tree_node n07(-7);
    binary_tree_node n06(-6);
    binary_tree_node n05(-5);
    binary_tree_node n04(-4);
    binary_tree_node n03(-3);
    binary_tree_node n02(-2);
    binary_tree_node n01(-1);
    binary_tree_node o00(0);
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);
    binary_tree_node p08(8);
    binary_tree_node p09(9);
    binary_tree_node p10(10);
    binary_tree_node p11(11);
    binary_tree_node p12(12);
    binary_tree_node p13(13);
    binary_tree_node p14(14);
    binary_tree_node p15(15);
    binary_tree_node p16(16);
    binary_tree_node p17(17);
    binary_tree_node p18(18);
    binary_tree_node p19(19);
    binary_tree_node p20(20);
    binary_tree_node p21(21);
    binary_tree_node p22(22);
    binary_tree_node p23(23);
    binary_tree_node p24(24);
    binary_tree_node p25(25);
    binary_tree_node p26(26);

    n24.set_left(n25);
    n24.set_right(n23);
    n22.set_left(n24);
    n22.set_right(n21);
    n20.set_left(n22);
    n20.set_right(n18);
    n18.set_left(n19);
    n18.set_right(n17);
    n16.set_left(n20);
    n16.set_right(n12);
    n14.set_left(n15);
    n14.set_right(n13);
    n12.set_left(n14);
    n12.set_right(n10);
    n10.set_left(n11);
    n10.set_right(n09);
    n08.set_left(n16);
    n08.set_right(n04);
    n06.set_left(n07);
    n06.set_right(n05);
    n04.set_left(n06);
    n04.set_right(n02);
    n02.set_left(n03);
    n02.set_right(n01);
    o00.set_left(n08);
    o00.set_right(p08);
    p02.set_left(p01);
    p02.set_right(p03);
    p04.set_left(p02);
    p04.set_right(p06);
    p06.set_left(p05);
    p06.set_right(p07);
    p08.set_left(p04);
    p08.set_right(p16);
    p10.set_left(p09);
    p10.set_right(p11);
    p12.set_left(p10);
    p12.set_right(p14);
    p14.set_left(p13);
    p14.set_right(p15);
    p16.set_left(p12);
    p16.set_right(p20);
    p18.set_left(p17);
    p18.set_right(p19);
    p20.set_left(p18);
    p20.set_right(p22);
    p22.set_left(p21);
    p22.set_right(p24);
    p24.set_left(p23);
    p24.set_right(p25);
    n25.red(true);
    n23.red(true);
    n22.red(true);
    n18.red(true);
    n16.red(true);
    n14.red(true);
    n10.red(true);
    n06.red(true);
    n02.red(true);
    p02.red(true);
    p06.red(true);
    p10.red(true);
    p14.red(true);
    p16.red(true);
    p18.red(true);
    p22.red(true);
    p23.red(true);
    p25.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(o00));
    n25.set_left(n26);
    ::std::cout << "Test post_insert() case 02.05" << ::std::endl;

    binary_tree_node::traits::pointer result = (
        ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_insert(n26)
    );

    output_tree(node_itr(o00, false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(o00, output_error, output_depth)
    );
    p25.set_right(p26);
    ::std::cout << "Test post_insert() case 02.06" << ::std::endl;
    result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_insert(p26);
    output_tree(node_itr(o00, false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(o00, output_error, output_depth)
    );
}

void test_insert_case_02_04()
{
    binary_tree_node n26(-26);
    binary_tree_node n25(-25);
    binary_tree_node n24(-24);
    binary_tree_node n23(-23);
    binary_tree_node n22(-22);
    binary_tree_node n21(-21);
    binary_tree_node n20(-20);
    binary_tree_node n19(-19);
    binary_tree_node n18(-18);
    binary_tree_node n17(-17);
    binary_tree_node n16(-16);
    binary_tree_node n15(-15);
    binary_tree_node n14(-14);
    binary_tree_node n13(-13);
    binary_tree_node n12(-12);
    binary_tree_node n11(-11);
    binary_tree_node n10(-10);
    binary_tree_node n09(-9);
    binary_tree_node n08(-8);
    binary_tree_node n07(-7);
    binary_tree_node n06(-6);
    binary_tree_node n05(-5);
    binary_tree_node n04(-4);
    binary_tree_node n03(-3);
    binary_tree_node n02(-2);
    binary_tree_node n01(-1);
    binary_tree_node o00(0);
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);
    binary_tree_node p08(8);
    binary_tree_node p09(9);
    binary_tree_node p10(10);
    binary_tree_node p11(11);
    binary_tree_node p12(12);
    binary_tree_node p13(13);
    binary_tree_node p14(14);
    binary_tree_node p15(15);
    binary_tree_node p16(16);
    binary_tree_node p17(17);
    binary_tree_node p18(18);
    binary_tree_node p19(19);
    binary_tree_node p20(20);
    binary_tree_node p21(21);
    binary_tree_node p22(22);
    binary_tree_node p23(23);
    binary_tree_node p24(24);
    binary_tree_node p25(25);
    binary_tree_node p26(26);

    n25.set_left(n26);
    n25.set_right(n24);
    n23.set_left(n25);
    n23.set_right(n21);
    n21.set_left(n22);
    n21.set_right(n20);
    n19.set_left(n23);
    n19.set_right(n08);
    n17.set_left(n18);
    n17.set_right(n16);
    n15.set_left(n17);
    n15.set_right(n10);
    n13.set_left(n14);
    n13.set_right(n11);
    n10.set_left(n13);
    n10.set_right(n09);
    n08.set_left(n15);
    n08.set_right(n04);
    n06.set_left(n07);
    n06.set_right(n05);
    n04.set_left(n06);
    n04.set_right(n02);
    n02.set_left(n03);
    n02.set_right(n01);
    o00.set_left(n19);
    o00.set_right(p19);
    p02.set_left(p01);
    p02.set_right(p03);
    p04.set_left(p02);
    p04.set_right(p06);
    p06.set_left(p05);
    p06.set_right(p07);
    p08.set_left(p04);
    p08.set_right(p15);
    p10.set_left(p09);
    p10.set_right(p13);
    p13.set_left(p11);
    p13.set_right(p14);
    p15.set_left(p10);
    p15.set_right(p17);
    p17.set_left(p16);
    p17.set_right(p18);
    p19.set_left(p08);
    p19.set_right(p23);
    p21.set_left(p20);
    p21.set_right(p22);
    p23.set_left(p21);
    p23.set_right(p25);
    p25.set_left(p24);
    p25.set_right(p26);
    n25.red(true);
    n21.red(true);
    n17.red(true);
    n14.red(true);
    n11.red(true);
    n10.red(true);
    n08.red(true);
    n06.red(true);
    n02.red(true);
    p02.red(true);
    p06.red(true);
    p08.red(true);
    p10.red(true);
    p11.red(true);
    p14.red(true);
    p17.red(true);
    p21.red(true);
    p25.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(o00));
    n11.set_left(n12);
    ::std::cout << "Test post_insert() case 02.07" << ::std::endl;

    binary_tree_node::traits::pointer result = (
        ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_insert(n12)
    );

    output_tree(node_itr(o00, false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(o00, output_error, output_depth)
    );
    p11.set_right(p12);
    ::std::cout << "Test post_insert() case 02.08" << ::std::endl;
    result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_insert(p12);
    output_tree(node_itr(o00, false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(o00, output_error, output_depth)
    );
}

#include <tuple>

typedef ::std::tuple<
    binary_tree_node::traits::pointer,
    binary_tree_node::traits::pointer,
    binary_tree_node::traits::pointer
> sep_result;

void test_separate_case_00_00()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);
    binary_tree_node n02(2);
    binary_tree_node n03(3);
    binary_tree_node n04(4);
    binary_tree_node n05(5);
    binary_tree_node n06(6);
    binary_tree_node n07(7);
    binary_tree_node n08(8);

    n01.set_left(n00);
    n01.set_right(n02);
    n03.set_left(n01);
    n03.set_right(n07);
    n05.set_left(n04);
    n05.set_right(n06);
    n07.set_left(n05);
    n07.set_right(n08);
    ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_fill(n03);
    ::std::cout << "Before Test separate() case 00.00" << ::std::endl;
    output_tree(node_itr(n03, false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::red_black_tree_test(n03, output_error, output_depth)
    );

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n05);

    ::std::cout << "After Test separate() case 00.00" << ::std::endl;
    BOOST_TEST(5 == **::std::get<0>(result));
    BOOST_TEST(6 == **::std::get<1>(result));
    BOOST_TEST(3 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_00_01()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);
    binary_tree_node n02(2);
    binary_tree_node n03(3);
    binary_tree_node n04(4);
    binary_tree_node n05(5);
    binary_tree_node n06(6);
    binary_tree_node n07(7);
    binary_tree_node n08(8);

    n01.set_left(n00);
    n01.set_right(n02);
    n03.set_left(n01);
    n03.set_right(n07);
    n05.set_left(n04);
    n05.set_right(n06);
    n07.set_left(n05);
    n07.set_right(n08);
    ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_fill(n03);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(n03));
    ::std::cout << "Test separate() case 00.01, part 1" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n03);
    binary_tree_node::traits::pointer p = ::std::get<1>(result);

    BOOST_TEST(3 == **::std::get<0>(result));
    BOOST_TEST(4 == **p);
    BOOST_TEST(4 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
    ::std::cout << "Test separate() case 00.01, part 2" << ::std::endl;
    result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(*p);
    BOOST_TEST(4 == **::std::get<0>(result));
    BOOST_TEST(5 == **::std::get<1>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_00_02()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);
    binary_tree_node n02(2);
    binary_tree_node n03(3);
    binary_tree_node n04(4);
    binary_tree_node n05(5);
    binary_tree_node n06(6);
    binary_tree_node n07(7);

    n01.set_left(n00);
    n01.set_right(n03);
    n03.set_left(n02);
    n04.set_left(n01);
    n04.set_right(n06);
    n06.set_left(n05);
    n06.set_right(n07);
    ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_fill(n04);
    ::std::cout << "Before Test separate() case 00.02" << ::std::endl;
    output_tree(node_itr(n04, false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::red_black_tree_test(n04, output_error, output_depth)
    );

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n03);

    ::std::cout << "After Test separate() case 00.02" << ::std::endl;
    BOOST_TEST(3 == **::std::get<0>(result));
    BOOST_TEST(4 == **::std::get<1>(result));
    BOOST_TEST(4 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_00_03()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);
    binary_tree_node n02(2);
    binary_tree_node n03(3);
    binary_tree_node n04(4);
    binary_tree_node n05(5);
    binary_tree_node n06(6);
    binary_tree_node n07(7);

    n01.set_left(n00);
    n01.set_right(n02);
    n03.set_left(n01);
    n03.set_right(n05);
    n05.set_left(n04);
    n05.set_right(n07);
    n07.set_left(n06);
    ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_fill(n03);
    ::std::cout << "Before Test separate() case 00.03" << ::std::endl;
    output_tree(node_itr(n03, false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::red_black_tree_test(n03, output_error, output_depth)
    );

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n07);

    ::std::cout << "After Test separate() case 00.03" << ::std::endl;
    BOOST_TEST(7 == **::std::get<0>(result));
    BOOST_TEST(!::std::get<1>(result));
    BOOST_TEST(3 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_00_04()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);
    binary_tree_node n02(2);
    binary_tree_node n03(3);
    binary_tree_node n04(4);
    binary_tree_node n05(5);
    binary_tree_node n06(6);
    binary_tree_node n07(7);
    binary_tree_node n08(8);

    n01.set_left(n00);
    n01.set_right(n02);
    n03.set_left(n01);
    n03.set_right(n07);
    n05.set_left(n04);
    n05.set_right(n06);
    n07.set_left(n05);
    n07.set_right(n08);
    ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_fill(n03);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(n03));
    ::std::cout << "Test separate() case 00.04, part 1" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n04);
    binary_tree_node::traits::pointer p = ::std::get<1>(result);

    BOOST_TEST(4 == **::std::get<0>(result));
    BOOST_TEST(5 == **p);
    BOOST_TEST(3 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
    ::std::cout << "Test separate() case 00.04, part 2" << ::std::endl;
    result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(*p);
    BOOST_TEST(5 == **::std::get<0>(result));
    BOOST_TEST(6 == **::std::get<1>(result));
    BOOST_TEST(3 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_00_05()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);
    binary_tree_node n02(2);
    binary_tree_node n03(3);
    binary_tree_node n04(4);
    binary_tree_node n05(5);
    binary_tree_node n06(6);
    binary_tree_node n07(7);
    binary_tree_node n08(8);

    n01.set_left(n00);
    n01.set_right(n02);
    n03.set_left(n01);
    n03.set_right(n07);
    n05.set_left(n04);
    n05.set_right(n06);
    n07.set_left(n05);
    n07.set_right(n08);
    ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_fill(n03);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(n03));
    ::std::cout << "Test separate() case 00.05" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n06);

    BOOST_TEST(6 == **::std::get<0>(result));
    BOOST_TEST(7 == **::std::get<1>(result));
    BOOST_TEST(3 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_00_06()
{
    binary_tree_node n01(1);
    binary_tree_node n06(6);
    binary_tree_node n08(8);
    binary_tree_node n11(11);
    binary_tree_node n13(13);
    binary_tree_node n15(15);
    binary_tree_node n17(17);
    binary_tree_node n22(22);
    binary_tree_node n25(25);
    binary_tree_node n27(27);

    n08.set_left(n06);
    n08.set_right(n11);
    n13.set_left(n08);
    n13.set_right(n17);
    n17.set_left(n15);
    n17.set_right(n25);
    n25.set_left(n22);
    n25.set_right(n27);
    ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_fill(n13);
    n08.red(true);
    n17.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(n13));
    ::std::cout << "Test separate() case 00.06" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n27);

    BOOST_TEST(27 == **::std::get<0>(result));
    BOOST_TEST(!::std::get<1>(result));
    BOOST_TEST(13 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_00_07()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);
    binary_tree_node n02(2);

    n01.set_left(n00);
    n01.set_right(n02);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(n01));
    ::std::cout << "Test separate() case 00.07" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n00);

    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    BOOST_TEST(2 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_00_08()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);
    binary_tree_node n02(2);
    binary_tree_node n03(3);

    n01.set_left(n00);
    n01.set_right(n03);
    n03.set_left(n02);
    n02.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(n01));
    ::std::cout << "Test separate() case 00.08" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n00);

    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    BOOST_TEST(2 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_00_09()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);
    binary_tree_node n02(2);
    binary_tree_node n03(3);
    binary_tree_node n04(4);
    binary_tree_node n05(5);

    n01.set_left(n00);
    n01.set_right(n04);
    n03.set_left(n02);
    n04.set_left(n03);
    n04.set_right(n05);
    n02.red(true);
    n04.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(n01));
    ::std::cout << "Test separate() case 00.09" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n00);

    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    BOOST_TEST(2 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_00_10()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);
    binary_tree_node n02(2);
    binary_tree_node n03(3);
    binary_tree_node n04(4);
    binary_tree_node n05(5);
    binary_tree_node n06(6);

    n01.set_left(n00);
    n01.set_right(n05);
    n03.set_left(n02);
    n03.set_right(n04);
    n05.set_left(n03);
    n05.set_right(n06);
    n02.red(true);
    n04.red(true);
    n05.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(n01));
    ::std::cout << "Test separate() case 00.10" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n00);

    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    BOOST_TEST(2 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_00_11()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);
    binary_tree_node n02(2);
    binary_tree_node n03(3);
    binary_tree_node n04(4);

    n01.set_left(n00);
    n01.set_right(n03);
    n03.set_left(n02);
    n03.set_right(n04);
    n03.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(n01));
    ::std::cout << "Test separate() case 00.11" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n00);

    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    BOOST_TEST(2 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_00_12()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);
    binary_tree_node n02(2);
    binary_tree_node n03(3);
    binary_tree_node n04(4);
    binary_tree_node n05(5);

    n01.set_left(n00);
    n01.set_right(n03);
    n03.set_left(n02);
    n03.set_right(n05);
    n05.set_left(n04);
    n03.red(true);
    n04.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(n01));
    ::std::cout << "Test separate() case 00.12" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n00);

    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    BOOST_TEST(2 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_00_13()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);
    binary_tree_node n02(2);
    binary_tree_node n03(3);
    binary_tree_node n04(4);
    binary_tree_node n05(5);
    binary_tree_node n06(6);

    n01.set_left(n00);
    n01.set_right(n03);
    n03.set_left(n02);
    n03.set_right(n05);
    n05.set_left(n04);
    n05.set_right(n06);
    n03.red(true);
    n04.red(true);
    n06.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(n01));
    ::std::cout << "Test separate() case 00.13" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n00);

    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    BOOST_TEST(2 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_01_00()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);
    binary_tree_node n02(2);
    binary_tree_node n03(3);
    binary_tree_node n04(4);

    n01.set_left(n00);
    n01.set_right(n02);
    n03.set_left(n01);
    n03.set_right(n04);
    n01.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(n03));
    ::std::cout << "Test separate() case 01.00" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n02);

    BOOST_TEST(2 == **::std::get<0>(result));
    BOOST_TEST(3 == **::std::get<1>(result));
    BOOST_TEST(3 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_01_01()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);
    binary_tree_node n02(2);
    binary_tree_node n03(3);
    binary_tree_node n04(4);
    binary_tree_node n05(5);

    n01.set_left(n00);
    n02.set_left(n01);
    n02.set_right(n03);
    n04.set_left(n02);
    n04.set_right(n05);
    n00.red(true);
    n02.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(n04));
    ::std::cout << "Test separate() case 01.01" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n03);

    BOOST_TEST(3 == **::std::get<0>(result));
    BOOST_TEST(4 == **::std::get<1>(result));
    BOOST_TEST(4 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_01_02()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);
    binary_tree_node n02(2);
    binary_tree_node n03(3);
    binary_tree_node n04(4);
    binary_tree_node n05(5);
    binary_tree_node n06(6);

    n01.set_left(n00);
    n01.set_right(n02);
    n03.set_left(n01);
    n03.set_right(n04);
    n05.set_left(n03);
    n05.set_right(n06);
    n00.red(true);
    n02.red(true);
    n03.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(n05));
    ::std::cout << "Test separate() case 01.02" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n04);

    BOOST_TEST(4 == **::std::get<0>(result));
    BOOST_TEST(5 == **::std::get<1>(result));
    BOOST_TEST(5 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_01_03()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);
    binary_tree_node n02(2);
    binary_tree_node n03(3);
    binary_tree_node n04(4);

    n01.set_left(n00);
    n01.set_right(n02);
    n03.set_left(n01);
    n03.set_right(n04);
    n01.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(n03));
    ::std::cout << "Test separate() case 01.03" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n00);

    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    BOOST_TEST(3 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_01_04()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);
    binary_tree_node n02(2);
    binary_tree_node n03(3);
    binary_tree_node n04(4);
    binary_tree_node n05(5);
    binary_tree_node n06(6);

    n01.set_left(n00);
    n01.set_right(n03);
    n03.set_left(n02);
    n03.set_right(n04);
    n05.set_left(n01);
    n05.set_right(n06);
    n01.red(true);
    n02.red(true);
    n04.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(n05));
    ::std::cout << "Test separate() case 01.04" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n00);

    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    BOOST_TEST(5 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_01_05()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);
    binary_tree_node n02(2);
    binary_tree_node n03(3);
    binary_tree_node n04(4);
    binary_tree_node n05(5);
    binary_tree_node n06(6);
    binary_tree_node n07(7);
    binary_tree_node n08(8);

    n01.set_left(n00);
    n01.set_right(n02);
    n03.set_left(n01);
    n03.set_right(n07);
    n05.set_left(n04);
    n05.set_right(n06);
    n07.set_left(n05);
    n07.set_right(n08);
    n05.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(n03));
    ::std::cout << "Test separate() case 01.05" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n03);

    BOOST_TEST(3 == **::std::get<0>(result));
    BOOST_TEST(4 == **::std::get<1>(result));
    BOOST_TEST(4 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_01_06()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);
    binary_tree_node n02(2);
    binary_tree_node n03(3);
    binary_tree_node n04(4);
    binary_tree_node n05(5);
    binary_tree_node n06(6);
    binary_tree_node n07(7);
    binary_tree_node n08(8);
    binary_tree_node n09(9);

    n01.set_left(n00);
    n01.set_right(n02);
    n03.set_left(n01);
    n03.set_right(n08);
    n05.set_left(n04);
    n05.set_right(n07);
    n07.set_left(n06);
    n08.set_left(n05);
    n08.set_right(n09);
    n05.red(true);
    n06.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(n03));
    ::std::cout << "Test separate() case 01.06" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n03);

    BOOST_TEST(3 == **::std::get<0>(result));
    BOOST_TEST(4 == **::std::get<1>(result));
    BOOST_TEST(4 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_01_07()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);
    binary_tree_node n02(2);
    binary_tree_node n03(3);
    binary_tree_node n04(4);
    binary_tree_node n05(5);
    binary_tree_node n06(6);
    binary_tree_node n07(7);
    binary_tree_node n08(8);
    binary_tree_node n09(9);
    binary_tree_node n10(10);

    n01.set_left(n00);
    n01.set_right(n02);
    n03.set_left(n01);
    n03.set_right(n09);
    n05.set_left(n04);
    n05.set_right(n07);
    n07.set_left(n06);
    n07.set_right(n08);
    n09.set_left(n05);
    n09.set_right(n10);
    n05.red(true);
    n06.red(true);
    n08.red(true);
    ::std::cout << "Before Test separate() case 01.07" << ::std::endl;
    output_tree(node_itr(n03, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(n03));
    ::std::cout << "After Test separate() case 01.07" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n03);

    BOOST_TEST(3 == **::std::get<0>(result));
    BOOST_TEST(4 == **::std::get<1>(result));
    BOOST_TEST(4 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_02_00()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);
    binary_tree_node n02(2);

    n01.set_left(n00);
    n01.set_right(n02);
    ::std::cout << "Test separate() case 02.00" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n02);

    BOOST_TEST(2 == **::std::get<0>(result));
    BOOST_TEST(!::std::get<1>(result));
    BOOST_TEST(1 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_02_01()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);
    binary_tree_node n02(2);
    binary_tree_node n03(3);
    binary_tree_node n04(4);
    binary_tree_node n05(5);
    binary_tree_node n06(6);
    binary_tree_node n07(7);

    n01.set_left(n00);
    n02.set_left(n01);
    n02.set_right(n03);
    n04.set_left(n02);
    n04.set_right(n06);
    n06.set_left(n05);
    n06.set_right(n07);
    ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_fill(n04);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(n04));
    ::std::cout << "Test separate() case 02.01" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n03);

    BOOST_TEST(3 == **::std::get<0>(result));
    BOOST_TEST(4 == **::std::get<1>(result));
    BOOST_TEST(4 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_02_02()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);
    binary_tree_node n02(2);
    binary_tree_node n03(3);
    binary_tree_node n04(4);
    binary_tree_node n05(5);
    binary_tree_node n06(6);
    binary_tree_node n07(7);
    binary_tree_node n08(8);

    n01.set_left(n00);
    n01.set_right(n02);
    n03.set_left(n01);
    n03.set_right(n04);
    n05.set_left(n03);
    n05.set_right(n07);
    n07.set_left(n06);
    n07.set_right(n08);
    n01.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(n05));
    ::std::cout << "Before Test separate() case 02.02" << ::std::endl;
    output_tree(node_itr(n05, false));

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n04);

    ::std::cout << "After Test separate() case 02.02" << ::std::endl;
    BOOST_TEST(4 == **::std::get<0>(result));
    BOOST_TEST(5 == **::std::get<1>(result));
    BOOST_TEST(5 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_02_03()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);
    binary_tree_node n02(2);
    binary_tree_node n03(3);
    binary_tree_node n04(4);
    binary_tree_node n05(5);
    binary_tree_node n06(6);
    binary_tree_node n07(7);
    binary_tree_node n08(8);
    binary_tree_node n09(9);
    binary_tree_node n10(10);

    n01.set_left(n00);
    n01.set_right(n03);
    n03.set_left(n02);
    n03.set_right(n04);
    n05.set_left(n01);
    n05.set_right(n06);
    n07.set_left(n05);
    n07.set_right(n09);
    n09.set_left(n08);
    n09.set_right(n10);
    n01.red(true);
    n02.red(true);
    n04.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(n07));
    ::std::cout << "Before Test separate() case 02.03" << ::std::endl;
    output_tree(node_itr(n07, false));

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n06);

    ::std::cout << "After Test separate() case 02.03" << ::std::endl;
    BOOST_TEST(6 == **::std::get<0>(result));
    BOOST_TEST(7 == **::std::get<1>(result));
    BOOST_TEST(7 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_02_04()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);
    binary_tree_node n02(2);
    binary_tree_node n03(3);
    binary_tree_node n04(4);
    binary_tree_node n05(5);
    binary_tree_node n06(6);
    binary_tree_node n07(7);

    n01.set_left(n00);
    n01.set_right(n03);
    n03.set_left(n02);
    n04.set_left(n01);
    n04.set_right(n06);
    n06.set_left(n05);
    n06.set_right(n07);
    n02.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(n04));
    ::std::cout << "Before Test separate() case 02.04" << ::std::endl;
    output_tree(node_itr(n04, false));

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n00);

    ::std::cout << "After Test separate() case 02.04" << ::std::endl;
    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    BOOST_TEST(4 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_02_05_p1()
{
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);
    binary_tree_node p08(8);
    binary_tree_node p09(9);

    p02.set_left(p01);
    p02.set_right(p04);
    p04.set_left(p03);
    p04.set_right(p05);
    p06.set_left(p02);
    p06.set_right(p08);
    p08.set_left(p07);
    p08.set_right(p09);
    ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_fill(p06);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(p06));
    ::std::cout << "Test separate() case 02.05, remove 1" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(p01);

    BOOST_TEST(1 == **::std::get<0>(result));
    BOOST_TEST(2 == **::std::get<1>(result));
    BOOST_TEST(6 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_02_05_o0()
{
    binary_tree_node n07(-7);
    binary_tree_node n06(-6);
    binary_tree_node n05(-5);
    binary_tree_node n04(-4);
    binary_tree_node n03(-3);
    binary_tree_node n02(-2);
    binary_tree_node n01(-1);
    binary_tree_node o00(0);
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);
    binary_tree_node p08(8);
    binary_tree_node p09(9);

    n06.set_left(n07);
    n06.set_right(n05);
    n04.set_left(n06);
    n04.set_right(n02);
    n02.set_left(n03);
    n02.set_right(n01);
    o00.set_left(n04);
    o00.set_right(p06);
    p02.set_left(p01);
    p02.set_right(p04);
    p04.set_left(p03);
    p04.set_right(p05);
    p06.set_left(p02);
    p06.set_right(p08);
    p08.set_left(p07);
    p08.set_right(p09);
    ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_fill(o00);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(o00));
    ::std::cout << "Test separate() case 02.05, remove 0" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(o00);

    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    BOOST_TEST(1 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_02_06_p1()
{
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);
    binary_tree_node p08(8);
    binary_tree_node p09(9);

    p02.set_left(p01);
    p02.set_right(p04);
    p04.set_left(p03);
    p04.set_right(p05);
    p06.set_left(p02);
    p06.set_right(p08);
    p08.set_left(p07);
    p08.set_right(p09);
    p04.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(p06));
    ::std::cout << "Test separate() case 02.06, remove 1" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(p01);

    BOOST_TEST(1 == **::std::get<0>(result));
    BOOST_TEST(2 == **::std::get<1>(result));
    BOOST_TEST(6 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_02_06_o0()
{
    binary_tree_node n07(-7);
    binary_tree_node n06(-6);
    binary_tree_node n05(-5);
    binary_tree_node n04(-4);
    binary_tree_node n03(-3);
    binary_tree_node n02(-2);
    binary_tree_node n01(-1);
    binary_tree_node o00(0);
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);
    binary_tree_node p08(8);
    binary_tree_node p09(9);

    n06.set_left(n07);
    n06.set_right(n05);
    n04.set_left(n06);
    n04.set_right(n02);
    n02.set_left(n03);
    n02.set_right(n01);
    o00.set_left(n04);
    o00.set_right(p06);
    p02.set_left(p01);
    p02.set_right(p04);
    p04.set_left(p03);
    p04.set_right(p05);
    p06.set_left(p02);
    p06.set_right(p08);
    p08.set_left(p07);
    p08.set_right(p09);
    p04.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(o00));
    ::std::cout << "Test separate() case 02.06, remove 0" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(o00);

    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    BOOST_TEST(1 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_02_07_p1()
{
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);
    binary_tree_node p08(8);
    binary_tree_node p09(9);
    binary_tree_node p10(10);

    p02.set_left(p01);
    p02.set_right(p05);
    p04.set_left(p03);
    p05.set_left(p04);
    p05.set_right(p06);
    p07.set_left(p02);
    p07.set_right(p09);
    p09.set_left(p08);
    p09.set_right(p10);
    p03.red(true);
    p05.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(p07));
    ::std::cout << "Test separate() case 02.07, remove 1" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(p01);

    BOOST_TEST(1 == **::std::get<0>(result));
    BOOST_TEST(2 == **::std::get<1>(result));
    BOOST_TEST(7 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_02_07_o0()
{
    binary_tree_node n07(-7);
    binary_tree_node n06(-6);
    binary_tree_node n05(-5);
    binary_tree_node n04(-4);
    binary_tree_node n03(-3);
    binary_tree_node n02(-2);
    binary_tree_node n01(-1);
    binary_tree_node o00(0);
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);
    binary_tree_node p08(8);
    binary_tree_node p09(9);
    binary_tree_node p10(10);

    n06.set_left(n07);
    n06.set_right(n05);
    n04.set_left(n06);
    n04.set_right(n02);
    n02.set_left(n03);
    n02.set_right(n01);
    o00.set_left(n04);
    o00.set_right(p07);
    p02.set_left(p01);
    p02.set_right(p05);
    p04.set_left(p03);
    p05.set_left(p04);
    p05.set_right(p06);
    p07.set_left(p02);
    p07.set_right(p09);
    p09.set_left(p08);
    p09.set_right(p10);
    p03.red(true);
    p05.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(o00));
    ::std::cout << "Test separate() case 02.07, remove 0" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(o00);

    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    BOOST_TEST(1 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_02_08_p1()
{
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);
    binary_tree_node p08(8);
    binary_tree_node p09(9);
    binary_tree_node p10(10);
    binary_tree_node p11(11);

    p02.set_left(p01);
    p02.set_right(p06);
    p04.set_left(p03);
    p04.set_right(p05);
    p06.set_left(p04);
    p06.set_right(p07);
    p08.set_left(p02);
    p08.set_right(p10);
    p10.set_left(p09);
    p10.set_right(p11);
    p03.red(true);
    p05.red(true);
    p06.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(p08));
    ::std::cout << "Test separate() case 02.08, remove 1" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(p01);

    BOOST_TEST(1 == **::std::get<0>(result));
    BOOST_TEST(2 == **::std::get<1>(result));
    BOOST_TEST(8 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_02_08_o0()
{
    binary_tree_node n07(-7);
    binary_tree_node n06(-6);
    binary_tree_node n05(-5);
    binary_tree_node n04(-4);
    binary_tree_node n03(-3);
    binary_tree_node n02(-2);
    binary_tree_node n01(-1);
    binary_tree_node o00(0);
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);
    binary_tree_node p08(8);
    binary_tree_node p09(9);
    binary_tree_node p10(10);
    binary_tree_node p11(11);

    n06.set_left(n07);
    n06.set_right(n05);
    n04.set_left(n06);
    n04.set_right(n02);
    n02.set_left(n03);
    n02.set_right(n01);
    o00.set_left(n04);
    o00.set_right(p08);
    p02.set_left(p01);
    p02.set_right(p06);
    p04.set_left(p03);
    p04.set_right(p05);
    p06.set_left(p04);
    p06.set_right(p07);
    p08.set_left(p02);
    p08.set_right(p10);
    p10.set_left(p09);
    p10.set_right(p11);
    p03.red(true);
    p05.red(true);
    p06.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(o00));
    ::std::cout << "Test separate() case 02.08, remove 0" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(o00);

    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    BOOST_TEST(1 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_03_00()
{
    binary_tree_node n07(-7);
    binary_tree_node n06(-6);
    binary_tree_node n05(-5);
    binary_tree_node n04(-4);
    binary_tree_node n03(-3);
    binary_tree_node n02(-2);
    binary_tree_node n01(-1);
    binary_tree_node o00(0);
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);

    n06.set_left(n07);
    n06.set_right(n05);
    n04.set_left(n06);
    n04.set_right(n02);
    n02.set_left(n03);
    n02.set_right(n01);
    o00.set_left(n04);
    o00.set_right(p04);
    p02.set_left(p01);
    p02.set_right(p03);
    p04.set_left(p02);
    p04.set_right(p06);
    p06.set_left(p05);
    p06.set_right(p07);
    n04.red(true);
    p04.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(o00));
    ::std::cout << "Test separate() case 03.00, part 1" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n03);

    BOOST_TEST(-3 == **::std::get<0>(result));
    BOOST_TEST(-2 == **::std::get<1>(result));
    BOOST_TEST(0 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
    ::std::cout << "Test separate() case 03.00, part 2" << ::std::endl;
    result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(p03);
    BOOST_TEST(3 == **::std::get<0>(result));
    BOOST_TEST(4 == **::std::get<1>(result));
    BOOST_TEST(0 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_03_01()
{
    binary_tree_node n11(-11);
    binary_tree_node n10(-10);
    binary_tree_node n09(-9);
    binary_tree_node n08(-8);
    binary_tree_node n07(-7);
    binary_tree_node n06(-6);
    binary_tree_node n05(-5);
    binary_tree_node n04(-4);
    binary_tree_node n03(-3);
    binary_tree_node n02(-2);
    binary_tree_node n01(-1);
    binary_tree_node o00(0);
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);
    binary_tree_node p08(8);
    binary_tree_node p09(9);
    binary_tree_node p10(10);
    binary_tree_node p11(11);

    n10.set_left(n11);
    n10.set_right(n09);
    n08.set_left(n10);
    n08.set_right(n06);
    n06.set_left(n07);
    n06.set_right(n05);
    n04.set_left(n08);
    n04.set_right(n02);
    n02.set_left(n03);
    n02.set_right(n01);
    o00.set_left(n04);
    o00.set_right(p04);
    p02.set_left(p01);
    p02.set_right(p03);
    p04.set_left(p02);
    p04.set_right(p08);
    p06.set_left(p05);
    p06.set_right(p07);
    p08.set_left(p06);
    p08.set_right(p10);
    p10.set_left(p09);
    p10.set_right(p11);
    n08.red(true);
    p08.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(o00));
    ::std::cout << "Test separate() case 03.01, part 1" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n03);

    BOOST_TEST(-3 == **::std::get<0>(result));
    BOOST_TEST(-2 == **::std::get<1>(result));
    BOOST_TEST(0 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
    ::std::cout << "Test separate() case 03.01, part 2" << ::std::endl;
    result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(p03);
    BOOST_TEST(3 == **::std::get<0>(result));
    BOOST_TEST(4 == **::std::get<1>(result));
    BOOST_TEST(0 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_03_02()
{
    binary_tree_node n09(-9);
    binary_tree_node n08(-8);
    binary_tree_node n07(-7);
    binary_tree_node n06(-6);
    binary_tree_node n05(-5);
    binary_tree_node n04(-4);
    binary_tree_node n03(-3);
    binary_tree_node n02(-2);
    binary_tree_node n01(-1);
    binary_tree_node o00(0);
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);
    binary_tree_node p08(8);
    binary_tree_node p09(9);

    n08.set_left(n09);
    n08.set_right(n07);
    n06.set_left(n08);
    n06.set_right(n05);
    n04.set_left(n06);
    n04.set_right(n02);
    n02.set_left(n03);
    n02.set_right(n01);
    o00.set_left(n04);
    o00.set_right(p04);
    p02.set_left(p01);
    p02.set_right(p03);
    p04.set_left(p02);
    p04.set_right(p06);
    p06.set_left(p05);
    p06.set_right(p08);
    p08.set_left(p07);
    p08.set_right(p09);
    n08.red(true);
    p08.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(o00));
    ::std::cout << "Test separate() case 03.02: remove -3" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n03);

    BOOST_TEST(-3 == **::std::get<0>(result));
    BOOST_TEST(-2 == **::std::get<1>(result));
    BOOST_TEST(0 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
    ::std::cout << "Test separate() case 03.02: remove 3" << ::std::endl;
    result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(p03);
    BOOST_TEST(3 == **::std::get<0>(result));
    BOOST_TEST(4 == **::std::get<1>(result));
    BOOST_TEST(0 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_03_03()
{
    binary_tree_node n09(-9);
    binary_tree_node n08(-8);
    binary_tree_node n07(-7);
    binary_tree_node n06(-6);
    binary_tree_node n05(-5);
    binary_tree_node n04(-4);
    binary_tree_node n03(-3);
    binary_tree_node n02(-2);
    binary_tree_node n01(-1);
    binary_tree_node o00(0);
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);
    binary_tree_node p08(8);
    binary_tree_node p09(9);

    n08.set_left(n09);
    n08.set_right(n06);
    n06.set_left(n07);
    n06.set_right(n05);
    n04.set_left(n08);
    n04.set_right(n02);
    n02.set_left(n03);
    n02.set_right(n01);
    o00.set_left(n04);
    o00.set_right(p04);
    p02.set_left(p01);
    p02.set_right(p03);
    p04.set_left(p02);
    p04.set_right(p08);
    p06.set_left(p05);
    p06.set_right(p07);
    p08.set_left(p06);
    p08.set_right(p09);
    n06.red(true);
    n04.red(true);
    p04.red(true);
    p06.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(o00));
    ::std::cout << "Test separate() case 03.03, part 1" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n03);

    BOOST_TEST(-3 == **::std::get<0>(result));
    BOOST_TEST(-2 == **::std::get<1>(result));
    BOOST_TEST(0 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
    ::std::cout << "Test separate() case 03.03, part 2" << ::std::endl;
    result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(p03);
    BOOST_TEST(3 == **::std::get<0>(result));
    BOOST_TEST(4 == **::std::get<1>(result));
    BOOST_TEST(0 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_03_04_n7()
{
    binary_tree_node n07(-7);
    binary_tree_node n06(-6);
    binary_tree_node n05(-5);
    binary_tree_node n04(-4);
    binary_tree_node n03(-3);
    binary_tree_node n02(-2);
    binary_tree_node n01(-1);
    binary_tree_node o00(0);
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);

    n06.set_left(n07);
    n06.set_right(n05);
    n04.set_left(n06);
    n04.set_right(n02);
    n02.set_left(n03);
    n02.set_right(n01);
    o00.set_left(n04);
    o00.set_right(p04);
    p02.set_left(p01);
    p02.set_right(p03);
    p04.set_left(p02);
    p04.set_right(p06);
    p06.set_left(p05);
    p06.set_right(p07);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(o00));
    ::std::cout << "Test separate() case 03.04, remove -7" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n07);

    BOOST_TEST(-7 == **::std::get<0>(result));
    BOOST_TEST(-6 == **::std::get<1>(result));
    BOOST_TEST(0 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_03_04_n6()
{
    binary_tree_node n07(-7);
    binary_tree_node n06(-6);
    binary_tree_node n05(-5);
    binary_tree_node n04(-4);
    binary_tree_node n03(-3);
    binary_tree_node n02(-2);
    binary_tree_node n01(-1);
    binary_tree_node o00(0);
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);

    n06.set_left(n07);
    n06.set_right(n05);
    n04.set_left(n06);
    n04.set_right(n02);
    n02.set_left(n03);
    n02.set_right(n01);
    o00.set_left(n04);
    o00.set_right(p04);
    p02.set_left(p01);
    p02.set_right(p03);
    p04.set_left(p02);
    p04.set_right(p06);
    p06.set_left(p05);
    p06.set_right(p07);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(o00));
    ::std::cout << "Test separate() case 03.04, remove -6" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n06);

    BOOST_TEST(-6 == **::std::get<0>(result));
    BOOST_TEST(-5 == **::std::get<1>(result));
    BOOST_TEST(0 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_03_04_n5()
{
    binary_tree_node n07(-7);
    binary_tree_node n06(-6);
    binary_tree_node n05(-5);
    binary_tree_node n04(-4);
    binary_tree_node n03(-3);
    binary_tree_node n02(-2);
    binary_tree_node n01(-1);
    binary_tree_node o00(0);
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);

    n06.set_left(n07);
    n06.set_right(n05);
    n04.set_left(n06);
    n04.set_right(n02);
    n02.set_left(n03);
    n02.set_right(n01);
    o00.set_left(n04);
    o00.set_right(p04);
    p02.set_left(p01);
    p02.set_right(p03);
    p04.set_left(p02);
    p04.set_right(p06);
    p06.set_left(p05);
    p06.set_right(p07);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(o00));
    ::std::cout << "Test separate() case 03.04, remove -5" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n05);

    BOOST_TEST(-5 == **::std::get<0>(result));
    BOOST_TEST(-4 == **::std::get<1>(result));
    BOOST_TEST(0 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_03_04_n4()
{
    binary_tree_node n07(-7);
    binary_tree_node n06(-6);
    binary_tree_node n05(-5);
    binary_tree_node n04(-4);
    binary_tree_node n03(-3);
    binary_tree_node n02(-2);
    binary_tree_node n01(-1);
    binary_tree_node o00(0);
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);

    n06.set_left(n07);
    n06.set_right(n05);
    n04.set_left(n06);
    n04.set_right(n02);
    n02.set_left(n03);
    n02.set_right(n01);
    o00.set_left(n04);
    o00.set_right(p04);
    p02.set_left(p01);
    p02.set_right(p03);
    p04.set_left(p02);
    p04.set_right(p06);
    p06.set_left(p05);
    p06.set_right(p07);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(o00));
    ::std::cout << "Test separate() case 03.04, remove -4" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n04);

    BOOST_TEST(-4 == **::std::get<0>(result));
    BOOST_TEST(-3 == **::std::get<1>(result));
    BOOST_TEST(0 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_03_04_n3()
{
    binary_tree_node n07(-7);
    binary_tree_node n06(-6);
    binary_tree_node n05(-5);
    binary_tree_node n04(-4);
    binary_tree_node n03(-3);
    binary_tree_node n02(-2);
    binary_tree_node n01(-1);
    binary_tree_node o00(0);
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);

    n06.set_left(n07);
    n06.set_right(n05);
    n04.set_left(n06);
    n04.set_right(n02);
    n02.set_left(n03);
    n02.set_right(n01);
    o00.set_left(n04);
    o00.set_right(p04);
    p02.set_left(p01);
    p02.set_right(p03);
    p04.set_left(p02);
    p04.set_right(p06);
    p06.set_left(p05);
    p06.set_right(p07);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(o00));
    ::std::cout << "Test separate() case 03.04, remove -3" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n03);

    BOOST_TEST(-3 == **::std::get<0>(result));
    BOOST_TEST(-2 == **::std::get<1>(result));
    BOOST_TEST(0 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_03_04_n2()
{
    binary_tree_node n07(-7);
    binary_tree_node n06(-6);
    binary_tree_node n05(-5);
    binary_tree_node n04(-4);
    binary_tree_node n03(-3);
    binary_tree_node n02(-2);
    binary_tree_node n01(-1);
    binary_tree_node o00(0);
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);

    n06.set_left(n07);
    n06.set_right(n05);
    n04.set_left(n06);
    n04.set_right(n02);
    n02.set_left(n03);
    n02.set_right(n01);
    o00.set_left(n04);
    o00.set_right(p04);
    p02.set_left(p01);
    p02.set_right(p03);
    p04.set_left(p02);
    p04.set_right(p06);
    p06.set_left(p05);
    p06.set_right(p07);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(o00));
    ::std::cout << "Test separate() case 03.04, remove -2" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n02);

    BOOST_TEST(-2 == **::std::get<0>(result));
    BOOST_TEST(-1 == **::std::get<1>(result));
    BOOST_TEST(0 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_03_04_n1()
{
    binary_tree_node n07(-7);
    binary_tree_node n06(-6);
    binary_tree_node n05(-5);
    binary_tree_node n04(-4);
    binary_tree_node n03(-3);
    binary_tree_node n02(-2);
    binary_tree_node n01(-1);
    binary_tree_node o00(0);
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);

    n06.set_left(n07);
    n06.set_right(n05);
    n04.set_left(n06);
    n04.set_right(n02);
    n02.set_left(n03);
    n02.set_right(n01);
    o00.set_left(n04);
    o00.set_right(p04);
    p02.set_left(p01);
    p02.set_right(p03);
    p04.set_left(p02);
    p04.set_right(p06);
    p06.set_left(p05);
    p06.set_right(p07);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(o00));
    ::std::cout << "Test separate() case 03.04, remove -1" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n01);

    BOOST_TEST(-1 == **::std::get<0>(result));
    BOOST_TEST(0 == **::std::get<1>(result));
    BOOST_TEST(0 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_03_04_o0()
{
    binary_tree_node n07(-7);
    binary_tree_node n06(-6);
    binary_tree_node n05(-5);
    binary_tree_node n04(-4);
    binary_tree_node n03(-3);
    binary_tree_node n02(-2);
    binary_tree_node n01(-1);
    binary_tree_node o00(0);
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);

    n06.set_left(n07);
    n06.set_right(n05);
    n04.set_left(n06);
    n04.set_right(n02);
    n02.set_left(n03);
    n02.set_right(n01);
    o00.set_left(n04);
    o00.set_right(p04);
    p02.set_left(p01);
    p02.set_right(p03);
    p04.set_left(p02);
    p04.set_right(p06);
    p06.set_left(p05);
    p06.set_right(p07);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(o00));
    ::std::cout << "Test separate() case 03.04, remove 0" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(o00);

    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    BOOST_TEST(1 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_03_04_p1()
{
    binary_tree_node n07(-7);
    binary_tree_node n06(-6);
    binary_tree_node n05(-5);
    binary_tree_node n04(-4);
    binary_tree_node n03(-3);
    binary_tree_node n02(-2);
    binary_tree_node n01(-1);
    binary_tree_node o00(0);
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);

    n06.set_left(n07);
    n06.set_right(n05);
    n04.set_left(n06);
    n04.set_right(n02);
    n02.set_left(n03);
    n02.set_right(n01);
    o00.set_left(n04);
    o00.set_right(p04);
    p02.set_left(p01);
    p02.set_right(p03);
    p04.set_left(p02);
    p04.set_right(p06);
    p06.set_left(p05);
    p06.set_right(p07);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(o00));
    ::std::cout << "Test separate() case 03.04, remove 1" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(p01);

    BOOST_TEST(1 == **::std::get<0>(result));
    BOOST_TEST(2 == **::std::get<1>(result));
    BOOST_TEST(0 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_03_04_p2()
{
    binary_tree_node n07(-7);
    binary_tree_node n06(-6);
    binary_tree_node n05(-5);
    binary_tree_node n04(-4);
    binary_tree_node n03(-3);
    binary_tree_node n02(-2);
    binary_tree_node n01(-1);
    binary_tree_node o00(0);
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);

    n06.set_left(n07);
    n06.set_right(n05);
    n04.set_left(n06);
    n04.set_right(n02);
    n02.set_left(n03);
    n02.set_right(n01);
    o00.set_left(n04);
    o00.set_right(p04);
    p02.set_left(p01);
    p02.set_right(p03);
    p04.set_left(p02);
    p04.set_right(p06);
    p06.set_left(p05);
    p06.set_right(p07);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(o00));
    ::std::cout << "Test separate() case 03.04, remove 2" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(p02);

    BOOST_TEST(2 == **::std::get<0>(result));
    BOOST_TEST(3 == **::std::get<1>(result));
    BOOST_TEST(0 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_03_04_p3()
{
    binary_tree_node n07(-7);
    binary_tree_node n06(-6);
    binary_tree_node n05(-5);
    binary_tree_node n04(-4);
    binary_tree_node n03(-3);
    binary_tree_node n02(-2);
    binary_tree_node n01(-1);
    binary_tree_node o00(0);
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);

    n06.set_left(n07);
    n06.set_right(n05);
    n04.set_left(n06);
    n04.set_right(n02);
    n02.set_left(n03);
    n02.set_right(n01);
    o00.set_left(n04);
    o00.set_right(p04);
    p02.set_left(p01);
    p02.set_right(p03);
    p04.set_left(p02);
    p04.set_right(p06);
    p06.set_left(p05);
    p06.set_right(p07);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(o00));
    ::std::cout << "Test separate() case 03.04, remove 3" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(p03);

    BOOST_TEST(3 == **::std::get<0>(result));
    BOOST_TEST(4 == **::std::get<1>(result));
    BOOST_TEST(0 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_03_04_p4()
{
    binary_tree_node n07(-7);
    binary_tree_node n06(-6);
    binary_tree_node n05(-5);
    binary_tree_node n04(-4);
    binary_tree_node n03(-3);
    binary_tree_node n02(-2);
    binary_tree_node n01(-1);
    binary_tree_node o00(0);
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);

    n06.set_left(n07);
    n06.set_right(n05);
    n04.set_left(n06);
    n04.set_right(n02);
    n02.set_left(n03);
    n02.set_right(n01);
    o00.set_left(n04);
    o00.set_right(p04);
    p02.set_left(p01);
    p02.set_right(p03);
    p04.set_left(p02);
    p04.set_right(p06);
    p06.set_left(p05);
    p06.set_right(p07);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(o00));
    ::std::cout << "Test separate() case 03.04, remove 4" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(p04);

    BOOST_TEST(4 == **::std::get<0>(result));
    BOOST_TEST(5 == **::std::get<1>(result));
    BOOST_TEST(0 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_03_04_p5()
{
    binary_tree_node n07(-7);
    binary_tree_node n06(-6);
    binary_tree_node n05(-5);
    binary_tree_node n04(-4);
    binary_tree_node n03(-3);
    binary_tree_node n02(-2);
    binary_tree_node n01(-1);
    binary_tree_node o00(0);
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);

    n06.set_left(n07);
    n06.set_right(n05);
    n04.set_left(n06);
    n04.set_right(n02);
    n02.set_left(n03);
    n02.set_right(n01);
    o00.set_left(n04);
    o00.set_right(p04);
    p02.set_left(p01);
    p02.set_right(p03);
    p04.set_left(p02);
    p04.set_right(p06);
    p06.set_left(p05);
    p06.set_right(p07);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(o00));
    ::std::cout << "Test separate() case 03.04, remove 5" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(p05);

    BOOST_TEST(5 == **::std::get<0>(result));
    BOOST_TEST(6 == **::std::get<1>(result));
    BOOST_TEST(0 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_03_04_p6()
{
    binary_tree_node n07(-7);
    binary_tree_node n06(-6);
    binary_tree_node n05(-5);
    binary_tree_node n04(-4);
    binary_tree_node n03(-3);
    binary_tree_node n02(-2);
    binary_tree_node n01(-1);
    binary_tree_node o00(0);
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);

    n06.set_left(n07);
    n06.set_right(n05);
    n04.set_left(n06);
    n04.set_right(n02);
    n02.set_left(n03);
    n02.set_right(n01);
    o00.set_left(n04);
    o00.set_right(p04);
    p02.set_left(p01);
    p02.set_right(p03);
    p04.set_left(p02);
    p04.set_right(p06);
    p06.set_left(p05);
    p06.set_right(p07);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(o00));
    ::std::cout << "Test separate() case 03.04, remove 6" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(p06);

    BOOST_TEST(6 == **::std::get<0>(result));
    BOOST_TEST(7 == **::std::get<1>(result));
    BOOST_TEST(0 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_03_04_p7()
{
    binary_tree_node n07(-7);
    binary_tree_node n06(-6);
    binary_tree_node n05(-5);
    binary_tree_node n04(-4);
    binary_tree_node n03(-3);
    binary_tree_node n02(-2);
    binary_tree_node n01(-1);
    binary_tree_node o00(0);
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);

    n06.set_left(n07);
    n06.set_right(n05);
    n04.set_left(n06);
    n04.set_right(n02);
    n02.set_left(n03);
    n02.set_right(n01);
    o00.set_left(n04);
    o00.set_right(p04);
    p02.set_left(p01);
    p02.set_right(p03);
    p04.set_left(p02);
    p04.set_right(p06);
    p06.set_left(p05);
    p06.set_right(p07);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(o00));
    ::std::cout << "Test separate() case 03.04, remove 7" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(p07);

    BOOST_TEST(7 == **::std::get<0>(result));
    BOOST_TEST(!::std::get<1>(result));
    BOOST_TEST(0 == **::std::get<2>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_case_03_0x()
{
    binary_tree_node n35(-35);
    binary_tree_node n34(-34);
    binary_tree_node n33(-33);
    binary_tree_node n32(-32);
    binary_tree_node n31(-31);
    binary_tree_node n30(-30);
    binary_tree_node n29(-29);
    binary_tree_node n28(-28);
    binary_tree_node n27(-27);
    binary_tree_node n26(-26);
    binary_tree_node n25(-25);
    binary_tree_node n24(-24);
    binary_tree_node n23(-23);
    binary_tree_node n22(-22);
    binary_tree_node n21(-21);
    binary_tree_node n20(-20);
    binary_tree_node n19(-19);
    binary_tree_node n18(-18);
    binary_tree_node n17(-17);
    binary_tree_node n16(-16);
    binary_tree_node n15(-15);
    binary_tree_node n14(-14);
    binary_tree_node n13(-13);
    binary_tree_node n12(-12);
    binary_tree_node n11(-11);
    binary_tree_node n10(-10);
    binary_tree_node n09(-9);
    binary_tree_node n08(-8);
    binary_tree_node n07(-7);
    binary_tree_node n06(-6);
    binary_tree_node n05(-5);
    binary_tree_node n04(-4);
    binary_tree_node n03(-3);
    binary_tree_node n02(-2);
    binary_tree_node n01(-1);
    binary_tree_node o00(0);
    binary_tree_node p01(1);
    binary_tree_node p02(2);
    binary_tree_node p03(3);
    binary_tree_node p04(4);
    binary_tree_node p05(5);
    binary_tree_node p06(6);
    binary_tree_node p07(7);
    binary_tree_node p08(8);
    binary_tree_node p09(9);
    binary_tree_node p10(10);
    binary_tree_node p11(11);
    binary_tree_node p12(12);
    binary_tree_node p13(13);
    binary_tree_node p14(14);
    binary_tree_node p15(15);
    binary_tree_node p16(16);
    binary_tree_node p17(17);
    binary_tree_node p18(18);
    binary_tree_node p19(19);

    n34.set_left(n35);
    n34.set_right(n33);
    n32.set_left(n34);
    n32.set_right(n30);
    n30.set_left(n31);
    n30.set_right(n29);
    n28.set_left(n32);
    n28.set_right(n24);
    n26.set_left(n27);
    n26.set_right(n25);
    n24.set_left(n26);
    n24.set_right(n22);
    n22.set_left(n23);
    n22.set_right(n21);
    n20.set_left(n28);
    n20.set_right(n12);
    n18.set_left(n19);
    n18.set_right(n17);
    n16.set_left(n18);
    n16.set_right(n14);
    n14.set_left(n15);
    n14.set_right(n13);
    n12.set_left(n16);
    n12.set_right(n08);
    n10.set_left(n11);
    n10.set_right(n09);
    n08.set_left(n10);
    n08.set_right(n06);
    n06.set_left(n07);
    n06.set_right(n05);
    n04.set_left(n20);
    n04.set_right(n02);
    n02.set_left(n03);
    n02.set_right(n01);
    o00.set_left(n04);
    o00.set_right(p04);
    p02.set_left(p01);
    p02.set_right(p03);
    p04.set_left(p02);
    p04.set_right(p12);
    p06.set_left(p05);
    p06.set_right(p07);
    p08.set_left(p06);
    p08.set_right(p10);
    p10.set_left(p09);
    p10.set_right(p11);
    p12.set_left(p08);
    p12.set_right(p16);
    p14.set_left(p13);
    p14.set_right(p15);
    p16.set_left(p14);
    p16.set_right(p18);
    p18.set_left(p17);
    p18.set_right(p19);
    n35.red(true);
    n33.red(true);
    n32.red(true);
    n31.red(true);
    n29.red(true);
    n27.red(true);
    n25.red(true);
    n24.red(true);
    n23.red(true);
    n21.red(true);
    n20.red(true);
    n19.red(true);
    n17.red(true);
    n16.red(true);
    n15.red(true);
    n13.red(true);
    n11.red(true);
    n09.red(true);
    n08.red(true);
    n07.red(true);
    n05.red(true);
    p05.red(true);
    p07.red(true);
    p08.red(true);
    p09.red(true);
    p11.red(true);
    p13.red(true);
    p15.red(true);
    p16.red(true);
    p17.red(true);
    p19.red(true);
    ::std::cout << "Before Test separate() case 03.0x" << ::std::endl;
    output_tree(node_itr(o00, false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(o00, output_error, output_depth)
    );
    ::std::cout << "After Test separate() case 03.0x: remove 3" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(p03);

    BOOST_TEST(3 == **::std::get<0>(result));
    BOOST_TEST(4 == **::std::get<1>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
    ::std::cout << "After Test separate() case 03.0x: remove -3" << ::std::endl;
    result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n03);
    BOOST_TEST(-3 == **::std::get<0>(result));
    BOOST_TEST(-2 == **::std::get<1>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

void test_separate_chain_case_00()
{
    binary_tree_node p70(70);
    binary_tree_node p60(60);
    binary_tree_node p57(57);
    binary_tree_node p56(56);
    binary_tree_node p55(55);
    binary_tree_node p54(54);
    binary_tree_node p29(29);
    binary_tree_node p28(28);
    binary_tree_node p10(10);

    p60.set_left(p70);
    p57.set_left(p60);
    p57.set_right(p55);
    p55.set_left(p56);
    p55.set_right(p54);
    p29.set_left(p57);
    p29.set_right(p10);
    p10.set_left(p28);
    p70.red(true);
    p57.red(true);
    p56.red(true);
    p54.red(true);
    p28.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(p29));
    ::std::cout << "Test separate() chain case 00: remove 57" << ::std::endl;

    sep_result result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(p57);

    BOOST_TEST(57 == **::std::get<0>(result));
    BOOST_TEST(56 == **::std::get<1>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
    ::std::cout << "Test separate() chain case 00: remove 56" << ::std::endl;
    result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(
        *::std::get<1>(result)
    );
    BOOST_TEST(56 == **::std::get<0>(result));
    BOOST_TEST(55 == **::std::get<1>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
    ::std::cout << "Test separate() chain case 00: remove 55" << ::std::endl;
    result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(
        *::std::get<1>(result)
    );
    BOOST_TEST(55 == **::std::get<0>(result));
    BOOST_TEST(54 == **::std::get<1>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
    ::std::cout << "Test separate() chain case 00: remove 54" << ::std::endl;
    result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(
        *::std::get<1>(result)
    );
    BOOST_TEST(54 == **::std::get<0>(result));
    BOOST_TEST(29 == **::std::get<1>(result));
    output_tree(node_itr(*::std::get<2>(result), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error, output_depth)
    );
}

int main(int argc, char** argv)
{
    test_insert_case_00_00();
    test_insert_case_00_01();
    test_insert_case_00_02();
    test_insert_case_01_00();
    test_insert_case_01_01();
    test_insert_case_01_02();
    test_insert_case_01_03();
    test_post_fill_and_insert();
    test_insert_case_02_00();
    test_insert_case_02_01();
    test_insert_case_02_02();
    test_insert_case_02_03();
    test_insert_case_02_04();
    test_separate_case_00_00();
    test_separate_case_00_01();
    test_separate_case_00_02();
    test_separate_case_00_03();
    test_separate_case_00_04();
    test_separate_case_00_05();
    test_separate_case_00_06();
    test_separate_case_00_07();
    test_separate_case_00_08();
    test_separate_case_00_09();
    test_separate_case_00_10();
    test_separate_case_00_11();
    test_separate_case_00_12();
    test_separate_case_00_13();
    test_separate_case_01_00();
    test_separate_case_01_01();
    test_separate_case_01_02();
    test_separate_case_01_03();
    test_separate_case_01_04();
    test_separate_case_01_05();
    test_separate_case_01_06();
    test_separate_case_01_07();
    test_separate_case_02_00();
    test_separate_case_02_01();
    test_separate_case_02_02();
    test_separate_case_02_03();
    test_separate_case_02_04();
    test_separate_case_02_05_p1();
    test_separate_case_02_05_o0();
    test_separate_case_02_06_p1();
    test_separate_case_02_06_o0();
    test_separate_case_02_07_p1();
    test_separate_case_02_07_o0();
    test_separate_case_02_08_p1();
    test_separate_case_02_08_o0();
    test_separate_case_03_00();
    test_separate_case_03_01();
    test_separate_case_03_02();
    test_separate_case_03_03();
    test_separate_case_03_04_n7();
    test_separate_case_03_04_n6();
    test_separate_case_03_04_n5();
    test_separate_case_03_04_n4();
    test_separate_case_03_04_n3();
    test_separate_case_03_04_n2();
    test_separate_case_03_04_n1();
    test_separate_case_03_04_o0();
    test_separate_case_03_04_p1();
    test_separate_case_03_04_p2();
    test_separate_case_03_04_p3();
    test_separate_case_03_04_p4();
    test_separate_case_03_04_p5();
    test_separate_case_03_04_p6();
    test_separate_case_03_04_p7();
    test_separate_case_03_0x();
    test_separate_chain_case_00();
    return ::boost::report_errors();
}

