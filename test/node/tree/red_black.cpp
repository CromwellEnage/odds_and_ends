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

struct output_error
{
    template <typename Index>
    void
        operator()(
            Index const& index,
            ::odds_and_ends::node::algorithm::red_black_tree_test_bit b
        ) const
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
};

struct output_depth
{
    template <typename Index, typename Depth>
    void operator()(Index const& index, Depth const& depth) const
    {
        ::std::cout << "    Node at in-order position " << index;
        ::std::cout << " has red-black depth " << depth << '.' << ::std::endl;
    }
};

template <typename Itr>
void output_tree(Itr itr)
{
    for (; itr; ++itr)
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

typedef ::odds_and_ends::composite_type::composite_type<
    ::boost::mpl::deque<
        ::odds_and_ends::node::data<int>,
        ::odds_and_ends::node::red_black,
        ::odds_and_ends::node::tree::base<>,
        ::odds_and_ends::node::tree::binary<>,
        ::odds_and_ends::node::tree::with_size<>
    >
> binary_tree_node;

#include <memory>

void test_insert_case_0_0()
{
    binary_tree_node parent(1);
    binary_tree_node child(0);

    parent.set_left(child);

    binary_tree_node::traits::pointer result = (
        ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_insert(
            ::std::pointer_traits<binary_tree_node::traits::pointer>::pointer_to(child)
        )
    );

    ::std::cout << "Test post_insert() case 0.0" << ::std::endl;

    if (result->parent())
    {
        BOOST_TEST(
            ::odds_and_ends::node::algorithm
            ::red_black_tree_test(parent, output_error(), output_depth())
        );
    }
    else
    {
        BOOST_TEST(
            ::odds_and_ends::node::algorithm
            ::red_black_tree_test(*result, output_error(), output_depth())
        );
    }
}

void test_insert_case_0_1()
{
    binary_tree_node parent(1);
    binary_tree_node child(0);

    parent.set_right(child);

    binary_tree_node::traits::pointer result = (
        ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_insert(
            ::std::pointer_traits<binary_tree_node::traits::pointer>::pointer_to(child)
        )
    );

    ::std::cout << "Test post_insert() case 0.1" << ::std::endl;

    if (result->parent())
    {
        BOOST_TEST(
            ::odds_and_ends::node::algorithm
            ::red_black_tree_test(parent, output_error(), output_depth())
        );
    }
    else
    {
        BOOST_TEST(
            ::odds_and_ends::node::algorithm
            ::red_black_tree_test(*result, output_error(), output_depth())
        );
    }
}

void test_insert_case_1_0()
{
    binary_tree_node grandparent(2);
    binary_tree_node parent(1);
    binary_tree_node uncle(3);
    binary_tree_node child(0);

    grandparent.set_left(parent);
    grandparent.set_right(uncle);
    uncle.red(true);
    parent.red(true);
    parent.set_left(child);

    binary_tree_node::traits::pointer result = (
        ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_insert(
            ::std::pointer_traits<binary_tree_node::traits::pointer>::pointer_to(child)
        )
    );

    ::std::cout << "Test post_insert() case 1.0" << ::std::endl;

    if (result->parent())
    {
        BOOST_TEST(
            ::odds_and_ends::node::algorithm
            ::red_black_tree_test(grandparent, output_error(), output_depth())
        );
    }
    else
    {
        BOOST_TEST(
            ::odds_and_ends::node::algorithm
            ::red_black_tree_test(*result, output_error(), output_depth())
        );
    }
}

void test_insert_case_1_1()
{
    binary_tree_node grandparent(2);
    binary_tree_node parent(1);
    binary_tree_node uncle(3);
    binary_tree_node child(0);

    grandparent.set_left(parent);
    grandparent.set_right(uncle);
    uncle.red(true);
    parent.red(true);
    parent.set_right(child);

    binary_tree_node::traits::pointer result = (
        ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_insert(
            ::std::pointer_traits<binary_tree_node::traits::pointer>::pointer_to(child)
        )
    );

    ::std::cout << "Test post_insert() case 1.1" << ::std::endl;

    if (result->parent())
    {
        BOOST_TEST(
            ::odds_and_ends::node::algorithm
            ::red_black_tree_test(grandparent, output_error(), output_depth())
        );
    }
    else
    {
        BOOST_TEST(
            ::odds_and_ends::node::algorithm
            ::red_black_tree_test(*result, output_error(), output_depth())
        );
    }
}

void test_insert_case_1_2()
{
    binary_tree_node grandparent(2);
    binary_tree_node parent(1);
    binary_tree_node uncle(3);
    binary_tree_node child(0);

    grandparent.set_right(parent);
    grandparent.set_left(uncle);
    uncle.red(true);
    parent.red(true);
    parent.set_left(child);

    binary_tree_node::traits::pointer result = (
        ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_insert(
            ::std::pointer_traits<binary_tree_node::traits::pointer>::pointer_to(child)
        )
    );

    ::std::cout << "Test post_insert() case 1.2" << ::std::endl;

    if (result->parent())
    {
        BOOST_TEST(
            ::odds_and_ends::node::algorithm
            ::red_black_tree_test(grandparent, output_error(), output_depth())
        );
    }
    else
    {
        BOOST_TEST(
            ::odds_and_ends::node::algorithm
            ::red_black_tree_test(*result, output_error(), output_depth())
        );
    }
}

void test_insert_case_1_3()
{
    binary_tree_node grandparent(2);
    binary_tree_node parent(1);
    binary_tree_node uncle(3);
    binary_tree_node child(0);

    grandparent.set_right(parent);
    grandparent.set_left(uncle);
    uncle.red(true);
    parent.red(true);
    parent.set_right(child);

    binary_tree_node::traits::pointer result = (
        ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_insert(
            ::std::pointer_traits<binary_tree_node::traits::pointer>::pointer_to(child)
        )
    );

    ::std::cout << "Test post_insert() case 1.3" << ::std::endl;

    if (result->parent())
    {
        BOOST_TEST(
            ::odds_and_ends::node::algorithm
            ::red_black_tree_test(grandparent, output_error(), output_depth())
        );
    }
    else
    {
        BOOST_TEST(
            ::odds_and_ends::node::algorithm
            ::red_black_tree_test(*result, output_error(), output_depth())
        );
    }
}

#include <odds_and_ends/node/iterator/in_order_tree.hpp>

typedef ::odds_and_ends::node::in_order_tree_iterator<binary_tree_node> Itr;

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
    ::odds_and_ends::node::algorithm::red_black_tree_test(n13, output_error(), output_depth());
    n08.red(true);
    n17.red(true);
    n01.set_left(n00);

    binary_tree_node::traits::pointer result = (
        ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_insert(
            ::std::pointer_traits<binary_tree_node::traits::pointer>::pointer_to(n00)
        )
    );

    ::std::cout << "Test post_insert() case 2.0" << ::std::endl;

    if (result->parent())
    {
        output_tree(Itr(n13));
        BOOST_TEST(
            ::odds_and_ends::node::algorithm
            ::red_black_tree_test(n13, output_error(), output_depth())
        );
    }
    else
    {
        output_tree(Itr(*result));
        BOOST_TEST(
            ::odds_and_ends::node::algorithm
            ::red_black_tree_test(*result, output_error(), output_depth())
        );
    }
}

void test_insert_case_2_1()
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

    binary_tree_node::traits::pointer result = (
        ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_insert(
            ::std::pointer_traits<binary_tree_node::traits::pointer>::pointer_to(n20)
        )
    );

    ::std::cout << "Test post_insert() case 2.1" << ::std::endl;

    if (result->parent())
    {
        output_tree(Itr(n13));
        BOOST_TEST(
            ::odds_and_ends::node::algorithm
            ::red_black_tree_test(n13, output_error(), output_depth())
        );
    }
    else
    {
        output_tree(Itr(*result));
        BOOST_TEST(
            ::odds_and_ends::node::algorithm
            ::red_black_tree_test(*result, output_error(), output_depth())
        );
    }
}

#include <tuple>

typedef ::std::tuple<
    binary_tree_node::traits::pointer,
    binary_tree_node::traits::pointer,
    binary_tree_node::traits::pointer
> SepResult;

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

    n01.set_left(n00);
    n01.set_right(n02);
    n03.set_left(n01);
    n03.set_right(n06);
    n05.set_left(n04);
    n06.set_left(n05);
    n06.set_right(n07);
    ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_fill(n03);
    ::std::cout << "Before Test separate() case 00.00" << ::std::endl;
    output_tree(Itr(n03));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::red_black_tree_test(n03, output_error(), output_depth())
    );

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n03);

    ::std::cout << "After Test separate() case 00.00" << ::std::endl;
    BOOST_TEST(3 == **::std::get<0>(result));
    BOOST_TEST(4 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
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

    n01.set_left(n00);
    n01.set_right(n03);
    n03.set_left(n02);
    n04.set_left(n01);
    n04.set_right(n06);
    n06.set_left(n05);
    n06.set_right(n07);
    ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_fill(n04);
    ::std::cout << "Before Test separate() case 00.01" << ::std::endl;
    output_tree(Itr(n04));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::red_black_tree_test(n04, output_error(), output_depth())
    );

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n03);

    ::std::cout << "After Test separate() case 00.01" << ::std::endl;
    BOOST_TEST(3 == **::std::get<0>(result));
    BOOST_TEST(4 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
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
    n01.set_right(n02);
    n03.set_left(n01);
    n03.set_right(n05);
    n05.set_left(n04);
    n05.set_right(n07);
    n07.set_left(n06);
    ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_fill(n03);
    ::std::cout << "Before Test separate() case 00.02" << ::std::endl;
    output_tree(Itr(n03));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::red_black_tree_test(n03, output_error(), output_depth())
    );

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n07);

    ::std::cout << "After Test separate() case 00.02" << ::std::endl;
    BOOST_TEST(7 == **::std::get<0>(result));
    BOOST_TEST(!::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
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

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n04);

    ::std::cout << "Test separate() case 00.03, part 1" << ::std::endl;
    BOOST_TEST(4 == **::std::get<0>(result));
    BOOST_TEST(5 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
    );
    result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n05);
    ::std::cout << "Test separate() case 00.03, part 2" << ::std::endl;
    BOOST_TEST(5 == **::std::get<0>(result));
    BOOST_TEST(6 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
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

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n06);

    ::std::cout << "Test separate() case 00.04" << ::std::endl;
    BOOST_TEST(6 == **::std::get<0>(result));
    BOOST_TEST(7 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
    );
}

void test_separate_case_00_05()
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

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n27);

    ::std::cout << "Test separate() case 00.05" << ::std::endl;
    BOOST_TEST(27 == **::std::get<0>(result));
    BOOST_TEST(!::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
    );
}

void test_separate_case_00_06()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);

    n01.set_left(n00);
    n00.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(n01));

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n00);

    ::std::cout << "Test separate() case 00.06" << ::std::endl;
    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
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

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n00);

    ::std::cout << "Test separate() case 00.07" << ::std::endl;
    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
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

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n00);

    ::std::cout << "Test separate() case 00.08" << ::std::endl;
    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
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

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n00);

    ::std::cout << "Test separate() case 00.09" << ::std::endl;
    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
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

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n00);

    ::std::cout << "Test separate() case 00.10" << ::std::endl;
    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
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

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n00);

    ::std::cout << "Test separate() case 00.11" << ::std::endl;
    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
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

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n00);

    ::std::cout << "Test separate() case 00.12" << ::std::endl;
    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
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

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n00);

    ::std::cout << "Test separate() case 00.13" << ::std::endl;
    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
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

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n02);

    ::std::cout << "Test separate() case 01.00" << ::std::endl;
    BOOST_TEST(2 == **::std::get<0>(result));
    BOOST_TEST(3 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
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

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n03);

    ::std::cout << "Test separate() case 01.01" << ::std::endl;
    BOOST_TEST(3 == **::std::get<0>(result));
    BOOST_TEST(4 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
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

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n04);

    ::std::cout << "Test separate() case 01.02" << ::std::endl;
    BOOST_TEST(4 == **::std::get<0>(result));
    BOOST_TEST(5 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
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

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n00);

    ::std::cout << "Test separate() case 01.03" << ::std::endl;
    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
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

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n00);

    ::std::cout << "Test separate() case 01.04" << ::std::endl;
    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
    );
}

void test_separate_case_02_00()
{
    binary_tree_node n00(0);
    binary_tree_node n01(1);
    binary_tree_node n02(2);

    n01.set_left(n00);
    n01.set_right(n02);

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n02);

    ::std::cout << "Test separate() case 02.00" << ::std::endl;
    BOOST_TEST(2 == **::std::get<0>(result));
    BOOST_TEST(!::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
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

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n03);

    ::std::cout << "Test separate() case 02.01" << ::std::endl;
    BOOST_TEST(3 == **::std::get<0>(result));
    BOOST_TEST(4 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
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
    output_tree(Itr(n05));

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n04);

    ::std::cout << "After Test separate() case 02.02" << ::std::endl;
    BOOST_TEST(4 == **::std::get<0>(result));
    BOOST_TEST(5 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
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
    output_tree(Itr(n07));

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n06);

    ::std::cout << "After Test separate() case 02.03" << ::std::endl;
    BOOST_TEST(6 == **::std::get<0>(result));
    BOOST_TEST(7 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
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
    output_tree(Itr(n04));

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n00);

    ::std::cout << "After Test separate() case 02.04" << ::std::endl;
    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
    );
}

void test_separate_case_02_05()
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
    n01.set_right(n03);
    n03.set_left(n02);
    n03.set_right(n04);
    n05.set_left(n01);
    n05.set_right(n07);
    n07.set_left(n06);
    n07.set_right(n08);
    ::odds_and_ends::node::left_leaning_red_black_tree_balancer::post_fill(n05);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(n05));

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n00);

    ::std::cout << "Test separate() case 02.05" << ::std::endl;
    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
    );
}

void test_separate_case_02_06()
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
    n01.set_right(n03);
    n03.set_left(n02);
    n03.set_right(n04);
    n05.set_left(n01);
    n05.set_right(n07);
    n07.set_left(n06);
    n07.set_right(n08);
    n03.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(n05));

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n00);

    ::std::cout << "Test separate() case 02.06" << ::std::endl;
    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
    );
}

void test_separate_case_02_07()
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
    n01.set_right(n04);
    n03.set_left(n02);
    n04.set_left(n03);
    n04.set_right(n05);
    n06.set_left(n01);
    n06.set_right(n08);
    n08.set_left(n07);
    n08.set_right(n09);
    n02.red(true);
    n04.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(n06));

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n00);

    ::std::cout << "Test separate() case 02.07" << ::std::endl;
    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
    );
}

void test_separate_case_02_08()
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
    n01.set_right(n05);
    n03.set_left(n02);
    n03.set_right(n04);
    n05.set_left(n03);
    n05.set_right(n06);
    n07.set_left(n01);
    n07.set_right(n09);
    n09.set_left(n08);
    n09.set_right(n10);
    n02.red(true);
    n04.red(true);
    n05.red(true);
    BOOST_TEST(::odds_and_ends::node::algorithm::red_black_tree_test(n07));

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n00);

    ::std::cout << "Test separate() case 02.08" << ::std::endl;
    BOOST_TEST(0 == **::std::get<0>(result));
    BOOST_TEST(1 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
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

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n03);

    ::std::cout << "Test separate() case 03.00, part 1" << ::std::endl;
    BOOST_TEST(-3 == **::std::get<0>(result));
    BOOST_TEST(-2 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
    );
    result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(p03);
    ::std::cout << "Test separate() case 03.00, part 2" << ::std::endl;
    BOOST_TEST(3 == **::std::get<0>(result));
    BOOST_TEST(4 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
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

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n03);

    ::std::cout << "Test separate() case 03.01, part 1" << ::std::endl;
    BOOST_TEST(-3 == **::std::get<0>(result));
    BOOST_TEST(-2 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
    );
    result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(p03);
    ::std::cout << "Test separate() case 03.01, part 2" << ::std::endl;
    BOOST_TEST(3 == **::std::get<0>(result));
    BOOST_TEST(4 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
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

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n03);

    ::std::cout << "Test separate() case 03.02, part 1" << ::std::endl;
    BOOST_TEST(-3 == **::std::get<0>(result));
    BOOST_TEST(-2 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
    );
    result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(p03);
    ::std::cout << "Test separate() case 03.02, part 2" << ::std::endl;
    BOOST_TEST(3 == **::std::get<0>(result));
    BOOST_TEST(4 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
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

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n03);

    ::std::cout << "Test separate() case 03.03, part 1" << ::std::endl;
    BOOST_TEST(-3 == **::std::get<0>(result));
    BOOST_TEST(-2 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
    );
    result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(p03);
    ::std::cout << "Test separate() case 03.03, part 2" << ::std::endl;
    BOOST_TEST(3 == **::std::get<0>(result));
    BOOST_TEST(4 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
    );
}

void test_separate_case_03_04()
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

    SepResult result = ::odds_and_ends::node::left_leaning_red_black_tree_balancer::separate(n03);

    ::std::cout << "Test separate() case 03.04" << ::std::endl;
    BOOST_TEST(-3 == **::std::get<0>(result));
    BOOST_TEST(-2 == **::std::get<1>(result));
    output_tree(Itr(*::std::get<2>(result)));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*::std::get<2>(result), output_error(), output_depth())
    );
}

int main(int argc, char** argv)
{
    test_insert_case_0_0();
    test_insert_case_0_1();
    test_insert_case_1_0();
    test_insert_case_1_1();
    test_insert_case_1_2();
    test_insert_case_1_3();
    test_post_fill_and_insert();
    test_insert_case_2_1();
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
    test_separate_case_02_00();
    test_separate_case_02_01();
    test_separate_case_02_02();
    test_separate_case_02_03();
    test_separate_case_02_04();
    test_separate_case_02_05();
    test_separate_case_02_06();
    test_separate_case_02_07();
    test_separate_case_02_08();
    test_separate_case_03_00();
    test_separate_case_03_01();
    test_separate_case_03_02();
    test_separate_case_03_03();
    test_separate_case_03_04();
    return ::boost::report_errors();
}

