// Copyright (C) 2025 Cromwell D. Enage

#include <iostream>
#include <odds_and_ends/node/algorithm/avl_tree_test.hpp>

struct output_error_t
{
    inline operator bool() const
    {
        return true;
    }

    template <typename T>
    void operator()(T const& value, ::odds_and_ends::node::algorithm::avl_tree_test_bit b) const
    {
        switch (b)
        {
            case ::odds_and_ends::node::algorithm::avl_tree_test_bit_is_left_heavy:
            {
                ::std::cout << "    Node " << value << " is too left-heavy." << std::endl;
                break;
            }

            case ::odds_and_ends::node::algorithm::avl_tree_test_bit_is_right_heavy:
            {
                ::std::cout << "    Node " << value << " is too right-heavy." << std::endl;
                break;
            }

            case ::odds_and_ends::node::algorithm::avl_tree_test_bit_has_incorrect_balance_factor:
            {
                ::std::cout << "    Node " << value << " has a wrong balance factor." << std::endl;
                break;
            }

            default:
            {
                break;
            }
        }
    }
};

template <typename Itr>
void output_tree(Itr itr)
{
    for (; !(!itr); ++itr)
    {
        ::std::cout << "    Node " << **itr << " has height " << itr->height();
        ::std::cout << ", has balance_factor " << static_cast<int>(itr->balance_factor());

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

#include <odds_and_ends/node/data.hpp>
#include <odds_and_ends/node/with_balance_factor.hpp>
#include <odds_and_ends/node/tree/base.hpp>
#include <odds_and_ends/node/tree/binary.hpp>
#include <odds_and_ends/node/tree/with_height.hpp>
#include <odds_and_ends/node/tree/with_size.hpp>
#include <odds_and_ends/node/balancer/adelson_velskii_landis_tree.hpp>
#include <odds_and_ends/composite_type/composite_type.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/core/lightweight_test.hpp>

typedef ::odds_and_ends::composite_type::composite_type<
    ::boost::mpl::deque<
        ::odds_and_ends::node::data<char>,
        ::odds_and_ends::node::with_balance_factor,
        ::odds_and_ends::node::tree::base<>,
        ::odds_and_ends::node::tree::binary<>,
        ::odds_and_ends::node::tree::with_height<>,
        ::odds_and_ends::node::tree::with_size<>
    >
> char_tree_node;

#include <odds_and_ends/node/iterator/in_order_tree.hpp>

typedef ::odds_and_ends::node::in_order_tree_iterator<char_tree_node const> char_itr;

#include <tuple>

typedef ::std::tuple<
    char_tree_node::traits::pointer,
    char_tree_node::traits::pointer,
    char_tree_node::traits::pointer
> char_sep_res;

void test_char_00()
{
    output_error_t output_error;
    char_tree_node letter_a('a');
    char_tree_node letter_f('f');
    char_tree_node letter_i('i');
    char_tree_node letter_l('l');
    char_tree_node letter_m('m');
    char_tree_node letter_o('o');
    char_tree_node letter_r('r');
    char_tree_node letter_u('u');
    char_tree_node letter_w('w');
    char_tree_node letter_x('x');
    char_tree_node letter_y('y');
    char_tree_node letter_z('z');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_r)
    );
    char_tree_node::traits::pointer root = in_res;

    ::std::cout << "Added letter r: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_r.set_right(letter_w);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_w);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter w: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_w.set_right(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter x: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_r.set_left(letter_o);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_o);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter o: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_o.set_left(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter l: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_x.set_right(letter_z);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_z);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter z: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_z.set_left(letter_y);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_y);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter y: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_l.set_left(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter f: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_f.set_right(letter_i);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_i);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter i: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_f.set_left(letter_a);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_a);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter a: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_r.set_right(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter u: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_l.set_right(letter_m);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_m);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter m: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_a
    );

    ::std::cout << "Removed letter a" << ::std::endl;
    BOOST_TEST('a' == **::std::get<0>(sp_res));
    BOOST_TEST('f' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_01()
{
    output_error_t output_error;
    char_tree_node letter_a('a');
    char_tree_node letter_f('f');
    char_tree_node letter_i('i');
    char_tree_node letter_l('l');
    char_tree_node letter_m('m');
    char_tree_node letter_o('o');
    char_tree_node letter_r('r');
    char_tree_node letter_u('u');
    char_tree_node letter_w('w');
    char_tree_node letter_x('x');
    char_tree_node letter_y('y');
    char_tree_node letter_z('z');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_r)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_r.set_right(letter_w);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_w);
    if (!in_res->parent()) root = in_res;
    letter_w.set_right(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_r.set_left(letter_o);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_o);
    if (!in_res->parent()) root = in_res;
    letter_o.set_left(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_x.set_right(letter_z);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_z);
    if (!in_res->parent()) root = in_res;
    letter_z.set_left(letter_y);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_y);
    if (!in_res->parent()) root = in_res;
    letter_l.set_left(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_i);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_i);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_a);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_a);
    if (!in_res->parent()) root = in_res;
    letter_r.set_right(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    letter_l.set_right(letter_m);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_m);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_f
    );

    ::std::cout << "Removed letter f" << ::std::endl;
    BOOST_TEST('f' == **::std::get<0>(sp_res));
    BOOST_TEST('i' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_02()
{
    output_error_t output_error;
    char_tree_node letter_a('a');
    char_tree_node letter_f('f');
    char_tree_node letter_i('i');
    char_tree_node letter_l('l');
    char_tree_node letter_m('m');
    char_tree_node letter_o('o');
    char_tree_node letter_r('r');
    char_tree_node letter_u('u');
    char_tree_node letter_w('w');
    char_tree_node letter_x('x');
    char_tree_node letter_y('y');
    char_tree_node letter_z('z');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_r)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_r.set_right(letter_w);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_w);
    if (!in_res->parent()) root = in_res;
    letter_w.set_right(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_r.set_left(letter_o);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_o);
    if (!in_res->parent()) root = in_res;
    letter_o.set_left(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_x.set_right(letter_z);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_z);
    if (!in_res->parent()) root = in_res;
    letter_z.set_left(letter_y);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_y);
    if (!in_res->parent()) root = in_res;
    letter_l.set_left(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_i);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_i);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_a);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_a);
    if (!in_res->parent()) root = in_res;
    letter_r.set_right(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    letter_l.set_right(letter_m);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_m);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_i
    );

    ::std::cout << "Removed letter i" << ::std::endl;
    BOOST_TEST('i' == **::std::get<0>(sp_res));
    BOOST_TEST('l' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_03()
{
    output_error_t output_error;
    char_tree_node letter_a('a');
    char_tree_node letter_f('f');
    char_tree_node letter_i('i');
    char_tree_node letter_l('l');
    char_tree_node letter_m('m');
    char_tree_node letter_o('o');
    char_tree_node letter_r('r');
    char_tree_node letter_u('u');
    char_tree_node letter_w('w');
    char_tree_node letter_x('x');
    char_tree_node letter_y('y');
    char_tree_node letter_z('z');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_r)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_r.set_right(letter_w);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_w);
    if (!in_res->parent()) root = in_res;
    letter_w.set_right(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_r.set_left(letter_o);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_o);
    if (!in_res->parent()) root = in_res;
    letter_o.set_left(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_x.set_right(letter_z);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_z);
    if (!in_res->parent()) root = in_res;
    letter_z.set_left(letter_y);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_y);
    if (!in_res->parent()) root = in_res;
    letter_l.set_left(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_i);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_i);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_a);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_a);
    if (!in_res->parent()) root = in_res;
    letter_r.set_right(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    letter_l.set_right(letter_m);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_m);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_l
    );

    ::std::cout << "Removed letter l" << ::std::endl;
    BOOST_TEST('l' == **::std::get<0>(sp_res));
    BOOST_TEST('m' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_04()
{
    output_error_t output_error;
    char_tree_node letter_a('a');
    char_tree_node letter_f('f');
    char_tree_node letter_i('i');
    char_tree_node letter_l('l');
    char_tree_node letter_m('m');
    char_tree_node letter_o('o');
    char_tree_node letter_r('r');
    char_tree_node letter_u('u');
    char_tree_node letter_w('w');
    char_tree_node letter_x('x');
    char_tree_node letter_y('y');
    char_tree_node letter_z('z');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_r)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_r.set_right(letter_w);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_w);
    if (!in_res->parent()) root = in_res;
    letter_w.set_right(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_r.set_left(letter_o);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_o);
    if (!in_res->parent()) root = in_res;
    letter_o.set_left(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_x.set_right(letter_z);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_z);
    if (!in_res->parent()) root = in_res;
    letter_z.set_left(letter_y);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_y);
    if (!in_res->parent()) root = in_res;
    letter_l.set_left(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_i);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_i);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_a);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_a);
    if (!in_res->parent()) root = in_res;
    letter_r.set_right(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    letter_l.set_right(letter_m);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_m);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_m
    );

    ::std::cout << "Removed letter m" << ::std::endl;
    BOOST_TEST('m' == **::std::get<0>(sp_res));
    BOOST_TEST('o' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_05()
{
    output_error_t output_error;
    char_tree_node letter_a('a');
    char_tree_node letter_f('f');
    char_tree_node letter_i('i');
    char_tree_node letter_l('l');
    char_tree_node letter_m('m');
    char_tree_node letter_o('o');
    char_tree_node letter_r('r');
    char_tree_node letter_u('u');
    char_tree_node letter_w('w');
    char_tree_node letter_x('x');
    char_tree_node letter_y('y');
    char_tree_node letter_z('z');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_r)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_r.set_right(letter_w);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_w);
    if (!in_res->parent()) root = in_res;
    letter_w.set_right(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_r.set_left(letter_o);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_o);
    if (!in_res->parent()) root = in_res;
    letter_o.set_left(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_x.set_right(letter_z);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_z);
    if (!in_res->parent()) root = in_res;
    letter_z.set_left(letter_y);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_y);
    if (!in_res->parent()) root = in_res;
    letter_l.set_left(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_i);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_i);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_a);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_a);
    if (!in_res->parent()) root = in_res;
    letter_r.set_right(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    letter_l.set_right(letter_m);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_m);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_o
    );

    ::std::cout << "Removed letter o" << ::std::endl;
    BOOST_TEST('o' == **::std::get<0>(sp_res));
    BOOST_TEST('r' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_06()
{
    output_error_t output_error;
    char_tree_node letter_a('a');
    char_tree_node letter_f('f');
    char_tree_node letter_i('i');
    char_tree_node letter_l('l');
    char_tree_node letter_m('m');
    char_tree_node letter_o('o');
    char_tree_node letter_r('r');
    char_tree_node letter_u('u');
    char_tree_node letter_w('w');
    char_tree_node letter_x('x');
    char_tree_node letter_y('y');
    char_tree_node letter_z('z');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_r)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_r.set_right(letter_w);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_w);
    if (!in_res->parent()) root = in_res;
    letter_w.set_right(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_r.set_left(letter_o);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_o);
    if (!in_res->parent()) root = in_res;
    letter_o.set_left(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_x.set_right(letter_z);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_z);
    if (!in_res->parent()) root = in_res;
    letter_z.set_left(letter_y);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_y);
    if (!in_res->parent()) root = in_res;
    letter_l.set_left(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_i);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_i);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_a);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_a);
    if (!in_res->parent()) root = in_res;
    letter_r.set_right(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    letter_l.set_right(letter_m);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_m);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_r
    );

    ::std::cout << "Removed letter r" << ::std::endl;
    BOOST_TEST('r' == **::std::get<0>(sp_res));
    BOOST_TEST('u' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_07()
{
    output_error_t output_error;
    char_tree_node letter_a('a');
    char_tree_node letter_f('f');
    char_tree_node letter_i('i');
    char_tree_node letter_l('l');
    char_tree_node letter_m('m');
    char_tree_node letter_o('o');
    char_tree_node letter_r('r');
    char_tree_node letter_u('u');
    char_tree_node letter_w('w');
    char_tree_node letter_x('x');
    char_tree_node letter_y('y');
    char_tree_node letter_z('z');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_r)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_r.set_right(letter_w);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_w);
    if (!in_res->parent()) root = in_res;
    letter_w.set_right(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_r.set_left(letter_o);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_o);
    if (!in_res->parent()) root = in_res;
    letter_o.set_left(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_x.set_right(letter_z);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_z);
    if (!in_res->parent()) root = in_res;
    letter_z.set_left(letter_y);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_y);
    if (!in_res->parent()) root = in_res;
    letter_l.set_left(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_i);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_i);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_a);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_a);
    if (!in_res->parent()) root = in_res;
    letter_r.set_right(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    letter_l.set_right(letter_m);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_m);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_u
    );

    ::std::cout << "Removed letter u" << ::std::endl;
    BOOST_TEST('u' == **::std::get<0>(sp_res));
    BOOST_TEST('w' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_08()
{
    output_error_t output_error;
    char_tree_node letter_a('a');
    char_tree_node letter_f('f');
    char_tree_node letter_i('i');
    char_tree_node letter_l('l');
    char_tree_node letter_m('m');
    char_tree_node letter_o('o');
    char_tree_node letter_r('r');
    char_tree_node letter_u('u');
    char_tree_node letter_w('w');
    char_tree_node letter_x('x');
    char_tree_node letter_y('y');
    char_tree_node letter_z('z');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_r)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_r.set_right(letter_w);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_w);
    if (!in_res->parent()) root = in_res;
    letter_w.set_right(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_r.set_left(letter_o);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_o);
    if (!in_res->parent()) root = in_res;
    letter_o.set_left(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_x.set_right(letter_z);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_z);
    if (!in_res->parent()) root = in_res;
    letter_z.set_left(letter_y);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_y);
    if (!in_res->parent()) root = in_res;
    letter_l.set_left(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_i);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_i);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_a);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_a);
    if (!in_res->parent()) root = in_res;
    letter_r.set_right(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    letter_l.set_right(letter_m);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_m);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_w
    );

    ::std::cout << "Removed letter w" << ::std::endl;
    BOOST_TEST('w' == **::std::get<0>(sp_res));
    BOOST_TEST('x' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_09()
{
    output_error_t output_error;
    char_tree_node letter_a('a');
    char_tree_node letter_f('f');
    char_tree_node letter_i('i');
    char_tree_node letter_l('l');
    char_tree_node letter_m('m');
    char_tree_node letter_o('o');
    char_tree_node letter_r('r');
    char_tree_node letter_u('u');
    char_tree_node letter_w('w');
    char_tree_node letter_x('x');
    char_tree_node letter_y('y');
    char_tree_node letter_z('z');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_r)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_r.set_right(letter_w);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_w);
    if (!in_res->parent()) root = in_res;
    letter_w.set_right(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_r.set_left(letter_o);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_o);
    if (!in_res->parent()) root = in_res;
    letter_o.set_left(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_x.set_right(letter_z);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_z);
    if (!in_res->parent()) root = in_res;
    letter_z.set_left(letter_y);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_y);
    if (!in_res->parent()) root = in_res;
    letter_l.set_left(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_i);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_i);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_a);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_a);
    if (!in_res->parent()) root = in_res;
    letter_r.set_right(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    letter_l.set_right(letter_m);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_m);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_x
    );

    ::std::cout << "Removed letter x" << ::std::endl;
    BOOST_TEST('x' == **::std::get<0>(sp_res));
    BOOST_TEST('y' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_0A()
{
    output_error_t output_error;
    char_tree_node letter_a('a');
    char_tree_node letter_f('f');
    char_tree_node letter_i('i');
    char_tree_node letter_l('l');
    char_tree_node letter_m('m');
    char_tree_node letter_o('o');
    char_tree_node letter_r('r');
    char_tree_node letter_u('u');
    char_tree_node letter_w('w');
    char_tree_node letter_x('x');
    char_tree_node letter_y('y');
    char_tree_node letter_z('z');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_r)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_r.set_right(letter_w);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_w);
    if (!in_res->parent()) root = in_res;
    letter_w.set_right(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_r.set_left(letter_o);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_o);
    if (!in_res->parent()) root = in_res;
    letter_o.set_left(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_x.set_right(letter_z);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_z);
    if (!in_res->parent()) root = in_res;
    letter_z.set_left(letter_y);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_y);
    if (!in_res->parent()) root = in_res;
    letter_l.set_left(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_i);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_i);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_a);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_a);
    if (!in_res->parent()) root = in_res;
    letter_r.set_right(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    letter_l.set_right(letter_m);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_m);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_y
    );

    ::std::cout << "Removed letter y" << ::std::endl;
    BOOST_TEST('y' == **::std::get<0>(sp_res));
    BOOST_TEST('z' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_0B()
{
    output_error_t output_error;
    char_tree_node letter_a('a');
    char_tree_node letter_f('f');
    char_tree_node letter_i('i');
    char_tree_node letter_l('l');
    char_tree_node letter_m('m');
    char_tree_node letter_o('o');
    char_tree_node letter_r('r');
    char_tree_node letter_u('u');
    char_tree_node letter_w('w');
    char_tree_node letter_x('x');
    char_tree_node letter_y('y');
    char_tree_node letter_z('z');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_r)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_r.set_right(letter_w);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_w);
    if (!in_res->parent()) root = in_res;
    letter_w.set_right(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_r.set_left(letter_o);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_o);
    if (!in_res->parent()) root = in_res;
    letter_o.set_left(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_x.set_right(letter_z);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_z);
    if (!in_res->parent()) root = in_res;
    letter_z.set_left(letter_y);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_y);
    if (!in_res->parent()) root = in_res;
    letter_l.set_left(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_i);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_i);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_a);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_a);
    if (!in_res->parent()) root = in_res;
    letter_r.set_right(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    letter_l.set_right(letter_m);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_m);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_z
    );

    ::std::cout << "Removed letter z" << ::std::endl;
    BOOST_TEST('z' == **::std::get<0>(sp_res));
    BOOST_TEST(!::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_0C()
{
    output_error_t output_error;
    char_tree_node letter_a('a');
    char_tree_node letter_f('f');
    char_tree_node letter_i('i');
    char_tree_node letter_l('l');
    char_tree_node letter_m('m');
    char_tree_node letter_o('o');
    char_tree_node letter_r('r');
    char_tree_node letter_u('u');
    char_tree_node letter_w('w');
    char_tree_node letter_x('x');
    char_tree_node letter_y('y');
    char_tree_node letter_z('z');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_r)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_r.set_right(letter_w);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_w);
    if (!in_res->parent()) root = in_res;
    letter_w.set_right(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_r.set_left(letter_o);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_o);
    if (!in_res->parent()) root = in_res;
    letter_o.set_left(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_x.set_right(letter_z);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_z);
    if (!in_res->parent()) root = in_res;
    letter_z.set_left(letter_y);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_y);
    if (!in_res->parent()) root = in_res;
    letter_l.set_left(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_i);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_i);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_a);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_a);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_z
    );

    ::std::cout << "Removed letter z" << ::std::endl;
    BOOST_TEST('z' == **::std::get<0>(sp_res));
    BOOST_TEST(!::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
    sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(letter_x);
    ::std::cout << "Removed letter x" << ::std::endl;
    BOOST_TEST('x' == **::std::get<0>(sp_res));
    BOOST_TEST('y' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_10()
{
    output_error_t output_error;
    char_tree_node letter_c('c');
    char_tree_node letter_d('d');
    char_tree_node letter_f('f');
    char_tree_node letter_g('g');
    char_tree_node letter_j('j');
    char_tree_node letter_l('l');
    char_tree_node letter_n('n');
    char_tree_node letter_p('p');
    char_tree_node letter_q('q');
    char_tree_node letter_s('s');
    char_tree_node letter_u('u');
    char_tree_node letter_v('v');
    char_tree_node letter_x('x');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_j)
    );
    char_tree_node::traits::pointer root = in_res;

    ::std::cout << "Added letter j: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_j.set_left(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter f: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_j.set_right(letter_p);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_p);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter p: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_f.set_left(letter_d);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_d);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter d: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_f.set_right(letter_g);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_g);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter g: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_p.set_left(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter l: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_p.set_right(letter_v);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_v);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter v: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_d.set_left(letter_c);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_c);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter c: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_l.set_right(letter_n);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_n);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter n: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_v.set_left(letter_s);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_s);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter s: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_v.set_right(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter x: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_s.set_left(letter_q);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_q);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter q: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_s.set_right(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter u: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_c
    );

    ::std::cout << "Removed letter c" << ::std::endl;
    BOOST_TEST('c' == **::std::get<0>(sp_res));
    BOOST_TEST('d' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_11()
{
    output_error_t output_error;
    char_tree_node letter_c('c');
    char_tree_node letter_d('d');
    char_tree_node letter_f('f');
    char_tree_node letter_g('g');
    char_tree_node letter_j('j');
    char_tree_node letter_l('l');
    char_tree_node letter_n('n');
    char_tree_node letter_p('p');
    char_tree_node letter_q('q');
    char_tree_node letter_s('s');
    char_tree_node letter_u('u');
    char_tree_node letter_v('v');
    char_tree_node letter_x('x');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_j)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_j.set_left(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_j.set_right(letter_p);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_p);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_d);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_d);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_g);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_g);
    if (!in_res->parent()) root = in_res;
    letter_p.set_left(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_p.set_right(letter_v);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_v);
    if (!in_res->parent()) root = in_res;
    letter_d.set_left(letter_c);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_c);
    if (!in_res->parent()) root = in_res;
    letter_l.set_right(letter_n);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_n);
    if (!in_res->parent()) root = in_res;
    letter_v.set_left(letter_s);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_s);
    if (!in_res->parent()) root = in_res;
    letter_v.set_right(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_s.set_left(letter_q);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_q);
    if (!in_res->parent()) root = in_res;
    letter_s.set_right(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_d
    );

    ::std::cout << "Removed letter d" << ::std::endl;
    BOOST_TEST('d' == **::std::get<0>(sp_res));
    BOOST_TEST('f' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_12()
{
    output_error_t output_error;
    char_tree_node letter_c('c');
    char_tree_node letter_d('d');
    char_tree_node letter_f('f');
    char_tree_node letter_g('g');
    char_tree_node letter_j('j');
    char_tree_node letter_l('l');
    char_tree_node letter_n('n');
    char_tree_node letter_p('p');
    char_tree_node letter_q('q');
    char_tree_node letter_s('s');
    char_tree_node letter_u('u');
    char_tree_node letter_v('v');
    char_tree_node letter_x('x');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_j)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_j.set_left(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_j.set_right(letter_p);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_p);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_d);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_d);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_g);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_g);
    if (!in_res->parent()) root = in_res;
    letter_p.set_left(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_p.set_right(letter_v);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_v);
    if (!in_res->parent()) root = in_res;
    letter_d.set_left(letter_c);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_c);
    if (!in_res->parent()) root = in_res;
    letter_l.set_right(letter_n);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_n);
    if (!in_res->parent()) root = in_res;
    letter_v.set_left(letter_s);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_s);
    if (!in_res->parent()) root = in_res;
    letter_v.set_right(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_s.set_left(letter_q);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_q);
    if (!in_res->parent()) root = in_res;
    letter_s.set_right(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_f
    );

    ::std::cout << "Removed letter f" << ::std::endl;
    BOOST_TEST('f' == **::std::get<0>(sp_res));
    BOOST_TEST('g' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_13()
{
    output_error_t output_error;
    char_tree_node letter_c('c');
    char_tree_node letter_d('d');
    char_tree_node letter_f('f');
    char_tree_node letter_g('g');
    char_tree_node letter_j('j');
    char_tree_node letter_l('l');
    char_tree_node letter_n('n');
    char_tree_node letter_p('p');
    char_tree_node letter_q('q');
    char_tree_node letter_s('s');
    char_tree_node letter_u('u');
    char_tree_node letter_v('v');
    char_tree_node letter_x('x');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_j)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_j.set_left(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_j.set_right(letter_p);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_p);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_d);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_d);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_g);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_g);
    if (!in_res->parent()) root = in_res;
    letter_p.set_left(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_p.set_right(letter_v);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_v);
    if (!in_res->parent()) root = in_res;
    letter_d.set_left(letter_c);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_c);
    if (!in_res->parent()) root = in_res;
    letter_l.set_right(letter_n);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_n);
    if (!in_res->parent()) root = in_res;
    letter_v.set_left(letter_s);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_s);
    if (!in_res->parent()) root = in_res;
    letter_v.set_right(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_s.set_left(letter_q);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_q);
    if (!in_res->parent()) root = in_res;
    letter_s.set_right(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_g
    );

    ::std::cout << "Removed letter g" << ::std::endl;
    BOOST_TEST('g' == **::std::get<0>(sp_res));
    BOOST_TEST('j' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_14()
{
    output_error_t output_error;
    char_tree_node letter_c('c');
    char_tree_node letter_d('d');
    char_tree_node letter_f('f');
    char_tree_node letter_g('g');
    char_tree_node letter_j('j');
    char_tree_node letter_l('l');
    char_tree_node letter_n('n');
    char_tree_node letter_p('p');
    char_tree_node letter_q('q');
    char_tree_node letter_s('s');
    char_tree_node letter_u('u');
    char_tree_node letter_v('v');
    char_tree_node letter_x('x');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_j)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_j.set_left(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_j.set_right(letter_p);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_p);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_d);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_d);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_g);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_g);
    if (!in_res->parent()) root = in_res;
    letter_p.set_left(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_p.set_right(letter_v);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_v);
    if (!in_res->parent()) root = in_res;
    letter_d.set_left(letter_c);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_c);
    if (!in_res->parent()) root = in_res;
    letter_l.set_right(letter_n);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_n);
    if (!in_res->parent()) root = in_res;
    letter_v.set_left(letter_s);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_s);
    if (!in_res->parent()) root = in_res;
    letter_v.set_right(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_s.set_left(letter_q);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_q);
    if (!in_res->parent()) root = in_res;
    letter_s.set_right(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_j
    );

    ::std::cout << "Removed letter j" << ::std::endl;
    BOOST_TEST('j' == **::std::get<0>(sp_res));
    BOOST_TEST('l' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_15()
{
    output_error_t output_error;
    char_tree_node letter_c('c');
    char_tree_node letter_d('d');
    char_tree_node letter_f('f');
    char_tree_node letter_g('g');
    char_tree_node letter_j('j');
    char_tree_node letter_l('l');
    char_tree_node letter_n('n');
    char_tree_node letter_p('p');
    char_tree_node letter_q('q');
    char_tree_node letter_s('s');
    char_tree_node letter_u('u');
    char_tree_node letter_v('v');
    char_tree_node letter_x('x');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_j)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_j.set_left(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_j.set_right(letter_p);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_p);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_d);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_d);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_g);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_g);
    if (!in_res->parent()) root = in_res;
    letter_p.set_left(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_p.set_right(letter_v);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_v);
    if (!in_res->parent()) root = in_res;
    letter_d.set_left(letter_c);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_c);
    if (!in_res->parent()) root = in_res;
    letter_l.set_right(letter_n);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_n);
    if (!in_res->parent()) root = in_res;
    letter_v.set_left(letter_s);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_s);
    if (!in_res->parent()) root = in_res;
    letter_v.set_right(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_s.set_left(letter_q);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_q);
    if (!in_res->parent()) root = in_res;
    letter_s.set_right(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_l
    );

    ::std::cout << "Removed letter l" << ::std::endl;
    BOOST_TEST('l' == **::std::get<0>(sp_res));
    BOOST_TEST('n' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_16()
{
    output_error_t output_error;
    char_tree_node letter_c('c');
    char_tree_node letter_d('d');
    char_tree_node letter_f('f');
    char_tree_node letter_g('g');
    char_tree_node letter_j('j');
    char_tree_node letter_l('l');
    char_tree_node letter_n('n');
    char_tree_node letter_p('p');
    char_tree_node letter_q('q');
    char_tree_node letter_s('s');
    char_tree_node letter_u('u');
    char_tree_node letter_v('v');
    char_tree_node letter_x('x');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_j)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_j.set_left(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_j.set_right(letter_p);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_p);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_d);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_d);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_g);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_g);
    if (!in_res->parent()) root = in_res;
    letter_p.set_left(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_p.set_right(letter_v);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_v);
    if (!in_res->parent()) root = in_res;
    letter_d.set_left(letter_c);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_c);
    if (!in_res->parent()) root = in_res;
    letter_l.set_right(letter_n);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_n);
    if (!in_res->parent()) root = in_res;
    letter_v.set_left(letter_s);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_s);
    if (!in_res->parent()) root = in_res;
    letter_v.set_right(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_s.set_left(letter_q);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_q);
    if (!in_res->parent()) root = in_res;
    letter_s.set_right(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_n
    );

    ::std::cout << "Removed letter n" << ::std::endl;
    BOOST_TEST('n' == **::std::get<0>(sp_res));
    BOOST_TEST('p' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_17()
{
    output_error_t output_error;
    char_tree_node letter_c('c');
    char_tree_node letter_d('d');
    char_tree_node letter_f('f');
    char_tree_node letter_g('g');
    char_tree_node letter_j('j');
    char_tree_node letter_l('l');
    char_tree_node letter_n('n');
    char_tree_node letter_p('p');
    char_tree_node letter_q('q');
    char_tree_node letter_s('s');
    char_tree_node letter_u('u');
    char_tree_node letter_v('v');
    char_tree_node letter_x('x');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_j)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_j.set_left(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_j.set_right(letter_p);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_p);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_d);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_d);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_g);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_g);
    if (!in_res->parent()) root = in_res;
    letter_p.set_left(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_p.set_right(letter_v);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_v);
    if (!in_res->parent()) root = in_res;
    letter_d.set_left(letter_c);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_c);
    if (!in_res->parent()) root = in_res;
    letter_l.set_right(letter_n);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_n);
    if (!in_res->parent()) root = in_res;
    letter_v.set_left(letter_s);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_s);
    if (!in_res->parent()) root = in_res;
    letter_v.set_right(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_s.set_left(letter_q);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_q);
    if (!in_res->parent()) root = in_res;
    letter_s.set_right(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_p
    );

    ::std::cout << "Removed letter p" << ::std::endl;
    BOOST_TEST('p' == **::std::get<0>(sp_res));
    BOOST_TEST('q' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_18()
{
    output_error_t output_error;
    char_tree_node letter_c('c');
    char_tree_node letter_d('d');
    char_tree_node letter_f('f');
    char_tree_node letter_g('g');
    char_tree_node letter_j('j');
    char_tree_node letter_l('l');
    char_tree_node letter_n('n');
    char_tree_node letter_p('p');
    char_tree_node letter_q('q');
    char_tree_node letter_s('s');
    char_tree_node letter_u('u');
    char_tree_node letter_v('v');
    char_tree_node letter_x('x');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_j)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_j.set_left(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_j.set_right(letter_p);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_p);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_d);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_d);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_g);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_g);
    if (!in_res->parent()) root = in_res;
    letter_p.set_left(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_p.set_right(letter_v);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_v);
    if (!in_res->parent()) root = in_res;
    letter_d.set_left(letter_c);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_c);
    if (!in_res->parent()) root = in_res;
    letter_l.set_right(letter_n);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_n);
    if (!in_res->parent()) root = in_res;
    letter_v.set_left(letter_s);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_s);
    if (!in_res->parent()) root = in_res;
    letter_v.set_right(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_s.set_left(letter_q);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_q);
    if (!in_res->parent()) root = in_res;
    letter_s.set_right(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_q
    );

    ::std::cout << "Removed letter q" << ::std::endl;
    BOOST_TEST('q' == **::std::get<0>(sp_res));
    BOOST_TEST('s' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_19()
{
    output_error_t output_error;
    char_tree_node letter_c('c');
    char_tree_node letter_d('d');
    char_tree_node letter_f('f');
    char_tree_node letter_g('g');
    char_tree_node letter_j('j');
    char_tree_node letter_l('l');
    char_tree_node letter_n('n');
    char_tree_node letter_p('p');
    char_tree_node letter_q('q');
    char_tree_node letter_s('s');
    char_tree_node letter_u('u');
    char_tree_node letter_v('v');
    char_tree_node letter_x('x');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_j)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_j.set_left(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_j.set_right(letter_p);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_p);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_d);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_d);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_g);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_g);
    if (!in_res->parent()) root = in_res;
    letter_p.set_left(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_p.set_right(letter_v);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_v);
    if (!in_res->parent()) root = in_res;
    letter_d.set_left(letter_c);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_c);
    if (!in_res->parent()) root = in_res;
    letter_l.set_right(letter_n);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_n);
    if (!in_res->parent()) root = in_res;
    letter_v.set_left(letter_s);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_s);
    if (!in_res->parent()) root = in_res;
    letter_v.set_right(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_s.set_left(letter_q);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_q);
    if (!in_res->parent()) root = in_res;
    letter_s.set_right(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_s
    );

    ::std::cout << "Removed letter s" << ::std::endl;
    BOOST_TEST('s' == **::std::get<0>(sp_res));
    BOOST_TEST('u' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_1A()
{
    output_error_t output_error;
    char_tree_node letter_c('c');
    char_tree_node letter_d('d');
    char_tree_node letter_f('f');
    char_tree_node letter_g('g');
    char_tree_node letter_j('j');
    char_tree_node letter_l('l');
    char_tree_node letter_n('n');
    char_tree_node letter_p('p');
    char_tree_node letter_q('q');
    char_tree_node letter_s('s');
    char_tree_node letter_u('u');
    char_tree_node letter_v('v');
    char_tree_node letter_x('x');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_j)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_j.set_left(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_j.set_right(letter_p);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_p);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_d);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_d);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_g);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_g);
    if (!in_res->parent()) root = in_res;
    letter_p.set_left(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_p.set_right(letter_v);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_v);
    if (!in_res->parent()) root = in_res;
    letter_d.set_left(letter_c);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_c);
    if (!in_res->parent()) root = in_res;
    letter_l.set_right(letter_n);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_n);
    if (!in_res->parent()) root = in_res;
    letter_v.set_left(letter_s);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_s);
    if (!in_res->parent()) root = in_res;
    letter_v.set_right(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_s.set_left(letter_q);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_q);
    if (!in_res->parent()) root = in_res;
    letter_s.set_right(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_u
    );

    ::std::cout << "Removed letter u" << ::std::endl;
    BOOST_TEST('u' == **::std::get<0>(sp_res));
    BOOST_TEST('v' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_1B()
{
    output_error_t output_error;
    char_tree_node letter_c('c');
    char_tree_node letter_d('d');
    char_tree_node letter_f('f');
    char_tree_node letter_g('g');
    char_tree_node letter_j('j');
    char_tree_node letter_l('l');
    char_tree_node letter_n('n');
    char_tree_node letter_p('p');
    char_tree_node letter_q('q');
    char_tree_node letter_s('s');
    char_tree_node letter_u('u');
    char_tree_node letter_v('v');
    char_tree_node letter_x('x');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_j)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_j.set_left(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_j.set_right(letter_p);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_p);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_d);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_d);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_g);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_g);
    if (!in_res->parent()) root = in_res;
    letter_p.set_left(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_p.set_right(letter_v);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_v);
    if (!in_res->parent()) root = in_res;
    letter_d.set_left(letter_c);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_c);
    if (!in_res->parent()) root = in_res;
    letter_l.set_right(letter_n);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_n);
    if (!in_res->parent()) root = in_res;
    letter_v.set_left(letter_s);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_s);
    if (!in_res->parent()) root = in_res;
    letter_v.set_right(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_s.set_left(letter_q);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_q);
    if (!in_res->parent()) root = in_res;
    letter_s.set_right(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_v
    );

    ::std::cout << "Removed letter v" << ::std::endl;
    BOOST_TEST('v' == **::std::get<0>(sp_res));
    BOOST_TEST('x' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_1C()
{
    output_error_t output_error;
    char_tree_node letter_c('c');
    char_tree_node letter_d('d');
    char_tree_node letter_f('f');
    char_tree_node letter_g('g');
    char_tree_node letter_j('j');
    char_tree_node letter_l('l');
    char_tree_node letter_n('n');
    char_tree_node letter_p('p');
    char_tree_node letter_q('q');
    char_tree_node letter_s('s');
    char_tree_node letter_u('u');
    char_tree_node letter_v('v');
    char_tree_node letter_x('x');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_j)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_j.set_left(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_j.set_right(letter_p);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_p);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_d);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_d);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_g);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_g);
    if (!in_res->parent()) root = in_res;
    letter_p.set_left(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_p.set_right(letter_v);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_v);
    if (!in_res->parent()) root = in_res;
    letter_d.set_left(letter_c);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_c);
    if (!in_res->parent()) root = in_res;
    letter_l.set_right(letter_n);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_n);
    if (!in_res->parent()) root = in_res;
    letter_v.set_left(letter_s);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_s);
    if (!in_res->parent()) root = in_res;
    letter_v.set_right(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_s.set_left(letter_q);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_q);
    if (!in_res->parent()) root = in_res;
    letter_s.set_right(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_x
    );

    ::std::cout << "Removed letter x" << ::std::endl;
    BOOST_TEST('x' == **::std::get<0>(sp_res));
    BOOST_TEST(!::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_20()
{
    output_error_t output_error;
    char_tree_node letter_c('c');
    char_tree_node letter_d('d');
    char_tree_node letter_f('f');
    char_tree_node letter_g('g');
    char_tree_node letter_j('j');
    char_tree_node letter_l('l');
    char_tree_node letter_n('n');
    char_tree_node letter_p('p');
    char_tree_node letter_q('q');
    char_tree_node letter_s('s');
    char_tree_node letter_u('u');
    char_tree_node letter_v('v');
    char_tree_node letter_x('x');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_j)
    );
    char_tree_node::traits::pointer root = in_res;

    ::std::cout << "Added letter j: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_j.set_right(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter f: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_j.set_left(letter_p);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_p);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter p: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_f.set_right(letter_d);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_d);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter d: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_f.set_left(letter_g);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_g);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter g: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_p.set_right(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter l: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_p.set_left(letter_v);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_v);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter v: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_d.set_right(letter_c);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_c);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter c: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_l.set_left(letter_n);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_n);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter n: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_v.set_right(letter_s);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_s);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter s: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_v.set_left(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter x: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_s.set_right(letter_q);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_q);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter q: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    letter_s.set_left(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added letter u: root = " << **root << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_c
    );

    ::std::cout << "Removed letter c" << ::std::endl;
    BOOST_TEST('c' == **::std::get<0>(sp_res));
    BOOST_TEST(!::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_21()
{
    output_error_t output_error;
    char_tree_node letter_c('c');
    char_tree_node letter_d('d');
    char_tree_node letter_f('f');
    char_tree_node letter_g('g');
    char_tree_node letter_j('j');
    char_tree_node letter_l('l');
    char_tree_node letter_n('n');
    char_tree_node letter_p('p');
    char_tree_node letter_q('q');
    char_tree_node letter_s('s');
    char_tree_node letter_u('u');
    char_tree_node letter_v('v');
    char_tree_node letter_x('x');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_j)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_j.set_right(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_j.set_left(letter_p);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_p);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_d);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_d);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_g);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_g);
    if (!in_res->parent()) root = in_res;
    letter_p.set_right(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_p.set_left(letter_v);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_v);
    if (!in_res->parent()) root = in_res;
    letter_d.set_right(letter_c);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_c);
    if (!in_res->parent()) root = in_res;
    letter_l.set_left(letter_n);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_n);
    if (!in_res->parent()) root = in_res;
    letter_v.set_right(letter_s);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_s);
    if (!in_res->parent()) root = in_res;
    letter_v.set_left(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_s.set_right(letter_q);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_q);
    if (!in_res->parent()) root = in_res;
    letter_s.set_left(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_d
    );

    ::std::cout << "Removed letter d" << ::std::endl;
    BOOST_TEST('d' == **::std::get<0>(sp_res));
    BOOST_TEST('c' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_22()
{
    output_error_t output_error;
    char_tree_node letter_c('c');
    char_tree_node letter_d('d');
    char_tree_node letter_f('f');
    char_tree_node letter_g('g');
    char_tree_node letter_j('j');
    char_tree_node letter_l('l');
    char_tree_node letter_n('n');
    char_tree_node letter_p('p');
    char_tree_node letter_q('q');
    char_tree_node letter_s('s');
    char_tree_node letter_u('u');
    char_tree_node letter_v('v');
    char_tree_node letter_x('x');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_j)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_j.set_right(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_j.set_left(letter_p);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_p);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_d);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_d);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_g);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_g);
    if (!in_res->parent()) root = in_res;
    letter_p.set_right(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_p.set_left(letter_v);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_v);
    if (!in_res->parent()) root = in_res;
    letter_d.set_right(letter_c);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_c);
    if (!in_res->parent()) root = in_res;
    letter_l.set_left(letter_n);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_n);
    if (!in_res->parent()) root = in_res;
    letter_v.set_right(letter_s);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_s);
    if (!in_res->parent()) root = in_res;
    letter_v.set_left(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_s.set_right(letter_q);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_q);
    if (!in_res->parent()) root = in_res;
    letter_s.set_left(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_f
    );

    ::std::cout << "Removed letter f" << ::std::endl;
    BOOST_TEST('f' == **::std::get<0>(sp_res));
    BOOST_TEST('d' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_23()
{
    output_error_t output_error;
    char_tree_node letter_c('c');
    char_tree_node letter_d('d');
    char_tree_node letter_f('f');
    char_tree_node letter_g('g');
    char_tree_node letter_j('j');
    char_tree_node letter_l('l');
    char_tree_node letter_n('n');
    char_tree_node letter_p('p');
    char_tree_node letter_q('q');
    char_tree_node letter_s('s');
    char_tree_node letter_u('u');
    char_tree_node letter_v('v');
    char_tree_node letter_x('x');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_j)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_j.set_right(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_j.set_left(letter_p);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_p);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_d);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_d);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_g);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_g);
    if (!in_res->parent()) root = in_res;
    letter_p.set_right(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_p.set_left(letter_v);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_v);
    if (!in_res->parent()) root = in_res;
    letter_d.set_right(letter_c);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_c);
    if (!in_res->parent()) root = in_res;
    letter_l.set_left(letter_n);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_n);
    if (!in_res->parent()) root = in_res;
    letter_v.set_right(letter_s);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_s);
    if (!in_res->parent()) root = in_res;
    letter_v.set_left(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_s.set_right(letter_q);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_q);
    if (!in_res->parent()) root = in_res;
    letter_s.set_left(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_g
    );

    ::std::cout << "Removed letter g" << ::std::endl;
    BOOST_TEST('g' == **::std::get<0>(sp_res));
    BOOST_TEST('f' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_24()
{
    output_error_t output_error;
    char_tree_node letter_c('c');
    char_tree_node letter_d('d');
    char_tree_node letter_f('f');
    char_tree_node letter_g('g');
    char_tree_node letter_j('j');
    char_tree_node letter_l('l');
    char_tree_node letter_n('n');
    char_tree_node letter_p('p');
    char_tree_node letter_q('q');
    char_tree_node letter_s('s');
    char_tree_node letter_u('u');
    char_tree_node letter_v('v');
    char_tree_node letter_x('x');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_j)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_j.set_right(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_j.set_left(letter_p);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_p);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_d);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_d);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_g);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_g);
    if (!in_res->parent()) root = in_res;
    letter_p.set_right(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_p.set_left(letter_v);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_v);
    if (!in_res->parent()) root = in_res;
    letter_d.set_right(letter_c);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_c);
    if (!in_res->parent()) root = in_res;
    letter_l.set_left(letter_n);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_n);
    if (!in_res->parent()) root = in_res;
    letter_v.set_right(letter_s);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_s);
    if (!in_res->parent()) root = in_res;
    letter_v.set_left(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_s.set_right(letter_q);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_q);
    if (!in_res->parent()) root = in_res;
    letter_s.set_left(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_j
    );

    ::std::cout << "Removed letter j" << ::std::endl;
    BOOST_TEST('j' == **::std::get<0>(sp_res));
    BOOST_TEST('g' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_25()
{
    output_error_t output_error;
    char_tree_node letter_c('c');
    char_tree_node letter_d('d');
    char_tree_node letter_f('f');
    char_tree_node letter_g('g');
    char_tree_node letter_j('j');
    char_tree_node letter_l('l');
    char_tree_node letter_n('n');
    char_tree_node letter_p('p');
    char_tree_node letter_q('q');
    char_tree_node letter_s('s');
    char_tree_node letter_u('u');
    char_tree_node letter_v('v');
    char_tree_node letter_x('x');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_j)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_j.set_right(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_j.set_left(letter_p);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_p);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_d);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_d);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_g);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_g);
    if (!in_res->parent()) root = in_res;
    letter_p.set_right(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_p.set_left(letter_v);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_v);
    if (!in_res->parent()) root = in_res;
    letter_d.set_right(letter_c);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_c);
    if (!in_res->parent()) root = in_res;
    letter_l.set_left(letter_n);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_n);
    if (!in_res->parent()) root = in_res;
    letter_v.set_right(letter_s);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_s);
    if (!in_res->parent()) root = in_res;
    letter_v.set_left(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_s.set_right(letter_q);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_q);
    if (!in_res->parent()) root = in_res;
    letter_s.set_left(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_l
    );

    ::std::cout << "Removed letter l" << ::std::endl;
    BOOST_TEST('l' == **::std::get<0>(sp_res));
    BOOST_TEST('j' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_26()
{
    output_error_t output_error;
    char_tree_node letter_c('c');
    char_tree_node letter_d('d');
    char_tree_node letter_f('f');
    char_tree_node letter_g('g');
    char_tree_node letter_j('j');
    char_tree_node letter_l('l');
    char_tree_node letter_n('n');
    char_tree_node letter_p('p');
    char_tree_node letter_q('q');
    char_tree_node letter_s('s');
    char_tree_node letter_u('u');
    char_tree_node letter_v('v');
    char_tree_node letter_x('x');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_j)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_j.set_right(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_j.set_left(letter_p);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_p);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_d);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_d);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_g);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_g);
    if (!in_res->parent()) root = in_res;
    letter_p.set_right(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_p.set_left(letter_v);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_v);
    if (!in_res->parent()) root = in_res;
    letter_d.set_right(letter_c);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_c);
    if (!in_res->parent()) root = in_res;
    letter_l.set_left(letter_n);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_n);
    if (!in_res->parent()) root = in_res;
    letter_v.set_right(letter_s);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_s);
    if (!in_res->parent()) root = in_res;
    letter_v.set_left(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_s.set_right(letter_q);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_q);
    if (!in_res->parent()) root = in_res;
    letter_s.set_left(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_n
    );

    ::std::cout << "Removed letter n" << ::std::endl;
    BOOST_TEST('n' == **::std::get<0>(sp_res));
    BOOST_TEST('l' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_27()
{
    output_error_t output_error;
    char_tree_node letter_c('c');
    char_tree_node letter_d('d');
    char_tree_node letter_f('f');
    char_tree_node letter_g('g');
    char_tree_node letter_j('j');
    char_tree_node letter_l('l');
    char_tree_node letter_n('n');
    char_tree_node letter_p('p');
    char_tree_node letter_q('q');
    char_tree_node letter_s('s');
    char_tree_node letter_u('u');
    char_tree_node letter_v('v');
    char_tree_node letter_x('x');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_j)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_j.set_right(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_j.set_left(letter_p);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_p);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_d);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_d);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_g);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_g);
    if (!in_res->parent()) root = in_res;
    letter_p.set_right(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_p.set_left(letter_v);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_v);
    if (!in_res->parent()) root = in_res;
    letter_d.set_right(letter_c);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_c);
    if (!in_res->parent()) root = in_res;
    letter_l.set_left(letter_n);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_n);
    if (!in_res->parent()) root = in_res;
    letter_v.set_right(letter_s);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_s);
    if (!in_res->parent()) root = in_res;
    letter_v.set_left(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_s.set_right(letter_q);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_q);
    if (!in_res->parent()) root = in_res;
    letter_s.set_left(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_p
    );

    ::std::cout << "Removed letter p" << ::std::endl;
    BOOST_TEST('p' == **::std::get<0>(sp_res));
    BOOST_TEST('n' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_28()
{
    output_error_t output_error;
    char_tree_node letter_c('c');
    char_tree_node letter_d('d');
    char_tree_node letter_f('f');
    char_tree_node letter_g('g');
    char_tree_node letter_j('j');
    char_tree_node letter_l('l');
    char_tree_node letter_n('n');
    char_tree_node letter_p('p');
    char_tree_node letter_q('q');
    char_tree_node letter_s('s');
    char_tree_node letter_u('u');
    char_tree_node letter_v('v');
    char_tree_node letter_x('x');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_j)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_j.set_right(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_j.set_left(letter_p);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_p);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_d);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_d);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_g);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_g);
    if (!in_res->parent()) root = in_res;
    letter_p.set_right(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_p.set_left(letter_v);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_v);
    if (!in_res->parent()) root = in_res;
    letter_d.set_right(letter_c);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_c);
    if (!in_res->parent()) root = in_res;
    letter_l.set_left(letter_n);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_n);
    if (!in_res->parent()) root = in_res;
    letter_v.set_right(letter_s);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_s);
    if (!in_res->parent()) root = in_res;
    letter_v.set_left(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_s.set_right(letter_q);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_q);
    if (!in_res->parent()) root = in_res;
    letter_s.set_left(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_q
    );

    ::std::cout << "Removed letter q" << ::std::endl;
    BOOST_TEST('q' == **::std::get<0>(sp_res));
    BOOST_TEST('p' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_29()
{
    output_error_t output_error;
    char_tree_node letter_c('c');
    char_tree_node letter_d('d');
    char_tree_node letter_f('f');
    char_tree_node letter_g('g');
    char_tree_node letter_j('j');
    char_tree_node letter_l('l');
    char_tree_node letter_n('n');
    char_tree_node letter_p('p');
    char_tree_node letter_q('q');
    char_tree_node letter_s('s');
    char_tree_node letter_u('u');
    char_tree_node letter_v('v');
    char_tree_node letter_x('x');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_j)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_j.set_right(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_j.set_left(letter_p);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_p);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_d);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_d);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_g);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_g);
    if (!in_res->parent()) root = in_res;
    letter_p.set_right(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_p.set_left(letter_v);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_v);
    if (!in_res->parent()) root = in_res;
    letter_d.set_right(letter_c);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_c);
    if (!in_res->parent()) root = in_res;
    letter_l.set_left(letter_n);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_n);
    if (!in_res->parent()) root = in_res;
    letter_v.set_right(letter_s);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_s);
    if (!in_res->parent()) root = in_res;
    letter_v.set_left(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_s.set_right(letter_q);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_q);
    if (!in_res->parent()) root = in_res;
    letter_s.set_left(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_s
    );

    ::std::cout << "Removed letter s" << ::std::endl;
    BOOST_TEST('s' == **::std::get<0>(sp_res));
    BOOST_TEST('q' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_2A()
{
    output_error_t output_error;
    char_tree_node letter_c('c');
    char_tree_node letter_d('d');
    char_tree_node letter_f('f');
    char_tree_node letter_g('g');
    char_tree_node letter_j('j');
    char_tree_node letter_l('l');
    char_tree_node letter_n('n');
    char_tree_node letter_p('p');
    char_tree_node letter_q('q');
    char_tree_node letter_s('s');
    char_tree_node letter_u('u');
    char_tree_node letter_v('v');
    char_tree_node letter_x('x');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_j)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_j.set_right(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_j.set_left(letter_p);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_p);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_d);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_d);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_g);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_g);
    if (!in_res->parent()) root = in_res;
    letter_p.set_right(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_p.set_left(letter_v);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_v);
    if (!in_res->parent()) root = in_res;
    letter_d.set_right(letter_c);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_c);
    if (!in_res->parent()) root = in_res;
    letter_l.set_left(letter_n);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_n);
    if (!in_res->parent()) root = in_res;
    letter_v.set_right(letter_s);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_s);
    if (!in_res->parent()) root = in_res;
    letter_v.set_left(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_s.set_right(letter_q);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_q);
    if (!in_res->parent()) root = in_res;
    letter_s.set_left(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_u
    );

    ::std::cout << "Removed letter u" << ::std::endl;
    BOOST_TEST('u' == **::std::get<0>(sp_res));
    BOOST_TEST('s' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_2B()
{
    output_error_t output_error;
    char_tree_node letter_c('c');
    char_tree_node letter_d('d');
    char_tree_node letter_f('f');
    char_tree_node letter_g('g');
    char_tree_node letter_j('j');
    char_tree_node letter_l('l');
    char_tree_node letter_n('n');
    char_tree_node letter_p('p');
    char_tree_node letter_q('q');
    char_tree_node letter_s('s');
    char_tree_node letter_u('u');
    char_tree_node letter_v('v');
    char_tree_node letter_x('x');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_j)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_j.set_right(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_j.set_left(letter_p);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_p);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_d);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_d);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_g);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_g);
    if (!in_res->parent()) root = in_res;
    letter_p.set_right(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_p.set_left(letter_v);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_v);
    if (!in_res->parent()) root = in_res;
    letter_d.set_right(letter_c);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_c);
    if (!in_res->parent()) root = in_res;
    letter_l.set_left(letter_n);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_n);
    if (!in_res->parent()) root = in_res;
    letter_v.set_right(letter_s);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_s);
    if (!in_res->parent()) root = in_res;
    letter_v.set_left(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_s.set_right(letter_q);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_q);
    if (!in_res->parent()) root = in_res;
    letter_s.set_left(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_v
    );

    ::std::cout << "Removed letter v" << ::std::endl;
    BOOST_TEST('v' == **::std::get<0>(sp_res));
    BOOST_TEST('u' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_char_2C()
{
    output_error_t output_error;
    char_tree_node letter_c('c');
    char_tree_node letter_d('d');
    char_tree_node letter_f('f');
    char_tree_node letter_g('g');
    char_tree_node letter_j('j');
    char_tree_node letter_l('l');
    char_tree_node letter_n('n');
    char_tree_node letter_p('p');
    char_tree_node letter_q('q');
    char_tree_node letter_s('s');
    char_tree_node letter_u('u');
    char_tree_node letter_v('v');
    char_tree_node letter_x('x');
    char_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_j)
    );
    char_tree_node::traits::pointer root = in_res;

    letter_j.set_right(letter_f);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_f);
    if (!in_res->parent()) root = in_res;
    letter_j.set_left(letter_p);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_p);
    if (!in_res->parent()) root = in_res;
    letter_f.set_right(letter_d);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_d);
    if (!in_res->parent()) root = in_res;
    letter_f.set_left(letter_g);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_g);
    if (!in_res->parent()) root = in_res;
    letter_p.set_right(letter_l);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_l);
    if (!in_res->parent()) root = in_res;
    letter_p.set_left(letter_v);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_v);
    if (!in_res->parent()) root = in_res;
    letter_d.set_right(letter_c);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_c);
    if (!in_res->parent()) root = in_res;
    letter_l.set_left(letter_n);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_n);
    if (!in_res->parent()) root = in_res;
    letter_v.set_right(letter_s);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_s);
    if (!in_res->parent()) root = in_res;
    letter_v.set_left(letter_x);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_x);
    if (!in_res->parent()) root = in_res;
    letter_s.set_right(letter_q);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_q);
    if (!in_res->parent()) root = in_res;
    letter_s.set_left(letter_u);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(letter_u);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Tree before:" << ::std::endl;
    output_tree(char_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root));

    char_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        letter_x
    );

    ::std::cout << "Removed letter x" << ::std::endl;
    BOOST_TEST('x' == **::std::get<0>(sp_res));
    BOOST_TEST('v' == **::std::get<1>(sp_res));
    output_tree(char_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

typedef ::odds_and_ends::composite_type::composite_type<
    ::boost::mpl::deque<
        ::odds_and_ends::node::data<int>,
        ::odds_and_ends::node::with_balance_factor,
        ::odds_and_ends::node::tree::base<>,
        ::odds_and_ends::node::tree::binary<>,
        ::odds_and_ends::node::tree::with_height<>,
        ::odds_and_ends::node::tree::with_size<>
    >
> int_tree_node;
typedef ::odds_and_ends::node::in_order_tree_iterator<int_tree_node const> int_itr;
typedef ::std::tuple<
    int_tree_node::traits::pointer,
    int_tree_node::traits::pointer,
    int_tree_node::traits::pointer
> int_sep_res;

void test_int_00()
{
    output_error_t output_error;
    int_tree_node o0000(0);
    int_tree_node n0050(-50);
    int_tree_node n0100(-100);
    int_tree_node n0150(-150);
    int_tree_node n0200(-200);
    int_tree_node n0250(-250);
    int_tree_node n0300(-300);
    int_tree_node n0350(-350);
    int_tree_node n0400(-400);
    int_tree_node n0450(-450);
    int_tree_node n0500(-500);
    int_tree_node n0550(-550);
    int_tree_node n0600(-600);
    int_tree_node n0650(-650);
    int_tree_node n0700(-700);
    int_tree_node n0750(-750);
    int_tree_node n0800(-800);
    int_tree_node n0850(-850);
    int_tree_node n0900(-900);
    int_tree_node n0950(-950);
    int_tree_node n1000(-1000);
    int_tree_node n1050(-1050);
    int_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(o0000)
    );
    int_tree_node::traits::pointer root = in_res;

    ::std::cout << "Added o0000: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    o0000.set_left(n0050);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0050);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0050: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0050.set_left(n0100);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0100);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0100: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0100.set_left(n0150);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0150);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0150: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0150.set_left(n0200);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0200);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0200: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0200.set_left(n0250);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0250);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0250: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0250.set_left(n0300);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0300);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0300: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0300.set_left(n0350);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0350);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0350: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0350.set_left(n0400);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0400);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0400: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0400.set_left(n0450);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0450);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0450: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0450.set_left(n0500);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0500);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0500: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0500.set_left(n0550);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0550);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0550: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0550.set_left(n0600);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0600);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0600: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0600.set_left(n0650);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0650);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0650: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0650.set_left(n0700);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0700);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0700: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0700.set_left(n0750);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0750);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0750: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0750.set_left(n0800);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0800);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0800: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0800.set_left(n0850);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0850);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0850: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0850.set_left(n0900);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0900);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0900: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0900.set_left(n0950);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0950);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0950: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0950.set_left(n1000);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n1000);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n1000: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n1000.set_left(n1050);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n1050);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n1050: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));

    int_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        o0000
    );

    ::std::cout << "Removed o0000" << ::std::endl;
    BOOST_TEST(0 == **::std::get<0>(sp_res));
    BOOST_TEST(!::std::get<1>(sp_res));
    output_tree(int_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
    sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(n0100);
    ::std::cout << "Removed n0100" << ::std::endl;
    BOOST_TEST(-100 == **::std::get<0>(sp_res));
    BOOST_TEST(-50 == **::std::get<1>(sp_res));
    output_tree(int_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
    sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(n0050);
    ::std::cout << "Removed n0050" << ::std::endl;
    BOOST_TEST(-50 == **::std::get<0>(sp_res));
    BOOST_TEST(!::std::get<1>(sp_res));
    output_tree(int_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
    sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(n0300);
    ::std::cout << "Removed n0300" << ::std::endl;
    BOOST_TEST(-300 == **::std::get<0>(sp_res));
    BOOST_TEST(-250 == **::std::get<1>(sp_res));
    output_tree(int_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_int_01()
{
    output_error_t output_error;
    int_tree_node o0000(0);
    int_tree_node n0050(-50);
    int_tree_node n0100(-100);
    int_tree_node n0150(-150);
    int_tree_node n0200(-200);
    int_tree_node n0250(-250);
    int_tree_node n0300(-300);
    int_tree_node n0350(-350);
    int_tree_node n0400(-400);
    int_tree_node n0450(-450);
    int_tree_node n0500(-500);
    int_tree_node n0550(-550);
    int_tree_node n0600(-600);
    int_tree_node n0650(-650);
    int_tree_node n0700(-700);
    int_tree_node n0750(-750);
    int_tree_node n0800(-800);
    int_tree_node n0850(-850);
    int_tree_node n0900(-900);
    int_tree_node n0950(-950);
    int_tree_node n1000(-1000);
    int_tree_node n1050(-1050);
    int_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(o0000)
    );
    int_tree_node::traits::pointer root = in_res;

    ::std::cout << "Added o0000: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    o0000.set_left(n0050);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0050);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0050: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0050.set_left(n0100);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0100);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0100: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0100.set_left(n0150);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0150);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0150: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0150.set_left(n0200);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0200);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0200: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0200.set_left(n0250);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0250);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0250: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0250.set_left(n0300);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0300);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0300: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0300.set_left(n0350);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0350);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0350: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0350.set_left(n0400);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0400);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0400: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0400.set_left(n0450);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0450);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0450: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0450.set_left(n0500);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0500);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0500: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0500.set_left(n0550);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0550);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0550: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0550.set_left(n0600);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0600);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0600: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0600.set_left(n0650);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0650);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0650: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0650.set_left(n0700);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0700);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0700: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0700.set_left(n0750);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0750);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0750: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0750.set_left(n0800);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0800);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0800: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0800.set_left(n0850);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0850);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0850: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0850.set_left(n0900);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0900);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0900: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0900.set_left(n0950);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n0950);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n0950: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n0950.set_left(n1000);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n1000);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n1000: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    n1000.set_left(n1050);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(n1050);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added n1050: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));

    int_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        o0000
    );

    ::std::cout << "Removed o0000" << ::std::endl;
    BOOST_TEST(0 == **::std::get<0>(sp_res));
    BOOST_TEST(!::std::get<1>(sp_res));
    output_tree(int_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
    sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(n0100);
    ::std::cout << "Removed n0100" << ::std::endl;
    BOOST_TEST(-100 == **::std::get<0>(sp_res));
    BOOST_TEST(-50 == **::std::get<1>(sp_res));
    output_tree(int_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
    sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(n0050);
    ::std::cout << "Removed n0050" << ::std::endl;
    BOOST_TEST(-50 == **::std::get<0>(sp_res));
    BOOST_TEST(!::std::get<1>(sp_res));
    output_tree(int_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
    sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(n1050);
    ::std::cout << "Removed n1050" << ::std::endl;
    BOOST_TEST(-1050 == **::std::get<0>(sp_res));
    BOOST_TEST(-1000 == **::std::get<1>(sp_res));
    output_tree(int_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
    sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(n1000);
    ::std::cout << "Removed n1000" << ::std::endl;
    BOOST_TEST(-1000 == **::std::get<0>(sp_res));
    BOOST_TEST(-950 == **::std::get<1>(sp_res));
    output_tree(int_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
    sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(n0800);
    ::std::cout << "Removed n0800" << ::std::endl;
    BOOST_TEST(-800 == **::std::get<0>(sp_res));
    BOOST_TEST(-750 == **::std::get<1>(sp_res));
    output_tree(int_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
    sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(n0300);
    ::std::cout << "Removed n0300" << ::std::endl;
    BOOST_TEST(-300 == **::std::get<0>(sp_res));
    BOOST_TEST(-250 == **::std::get<1>(sp_res));
    output_tree(int_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_int_10()
{
    output_error_t output_error;
    int_tree_node o0000(0);
    int_tree_node p0050(50);
    int_tree_node p0100(100);
    int_tree_node p0150(150);
    int_tree_node p0200(200);
    int_tree_node p0250(250);
    int_tree_node p0300(300);
    int_tree_node p0350(350);
    int_tree_node p0400(400);
    int_tree_node p0450(450);
    int_tree_node p0500(500);
    int_tree_node p0550(550);
    int_tree_node p0600(600);
    int_tree_node p0650(650);
    int_tree_node p0700(700);
    int_tree_node p0750(750);
    int_tree_node p0800(800);
    int_tree_node p0850(850);
    int_tree_node p0900(900);
    int_tree_node p0950(950);
    int_tree_node p1000(1000);
    int_tree_node p1050(1050);
    int_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(o0000)
    );
    int_tree_node::traits::pointer root = in_res;

    ::std::cout << "Added o0000: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    o0000.set_right(p0050);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0050);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0050: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0050.set_right(p0100);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0100);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0100: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0100.set_right(p0150);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0150);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0150: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0150.set_right(p0200);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0200);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0200: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0200.set_right(p0250);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0250);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0250: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0250.set_right(p0300);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0300);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0300: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0300.set_right(p0350);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0350);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0350: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0350.set_right(p0400);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0400);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0400: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0400.set_right(p0450);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0450);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0450: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0450.set_right(p0500);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0500);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0500: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0500.set_right(p0550);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0550);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0550: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0550.set_right(p0600);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0600);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0600: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0600.set_right(p0650);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0650);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0650: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0650.set_right(p0700);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0700);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0700: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0700.set_right(p0750);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0750);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0750: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0750.set_right(p0800);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0800);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0800: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0800.set_right(p0850);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0850);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0850: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0850.set_right(p0900);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0900);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0900: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0900.set_right(p0950);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0950);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0950: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0950.set_right(p1000);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p1000);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p1000: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p1000.set_right(p1050);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p1050);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p1050: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));

    int_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        o0000
    );

    ::std::cout << "Removed o0000" << ::std::endl;
    BOOST_TEST(0 == **::std::get<0>(sp_res));
    BOOST_TEST(50 == **::std::get<1>(sp_res));
    output_tree(int_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
    sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(p0100);
    ::std::cout << "Removed p0100" << ::std::endl;
    BOOST_TEST(100 == **::std::get<0>(sp_res));
    BOOST_TEST(150 == **::std::get<1>(sp_res));
    output_tree(int_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
    sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(p0050);
    ::std::cout << "Removed p0050" << ::std::endl;
    BOOST_TEST(50 == **::std::get<0>(sp_res));
    BOOST_TEST(150 == **::std::get<1>(sp_res));
    output_tree(int_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
    sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(p0300);
    ::std::cout << "Removed p0300" << ::std::endl;
    BOOST_TEST(300 == **::std::get<0>(sp_res));
    BOOST_TEST(350 == **::std::get<1>(sp_res));
    output_tree(int_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

void test_int_11()
{
    output_error_t output_error;
    int_tree_node o0000(0);
    int_tree_node p0050(50);
    int_tree_node p0100(100);
    int_tree_node p0150(150);
    int_tree_node p0200(200);
    int_tree_node p0250(250);
    int_tree_node p0300(300);
    int_tree_node p0350(350);
    int_tree_node p0400(400);
    int_tree_node p0450(450);
    int_tree_node p0500(500);
    int_tree_node p0550(550);
    int_tree_node p0600(600);
    int_tree_node p0650(650);
    int_tree_node p0700(700);
    int_tree_node p0750(750);
    int_tree_node p0800(800);
    int_tree_node p0850(850);
    int_tree_node p0900(900);
    int_tree_node p0950(950);
    int_tree_node p1000(1000);
    int_tree_node p1050(1050);
    int_tree_node::traits::pointer in_res = (
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(o0000)
    );
    int_tree_node::traits::pointer root = in_res;

    ::std::cout << "Added o0000: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    o0000.set_right(p0050);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0050);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0050: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0050.set_right(p0100);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0100);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0100: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0100.set_right(p0150);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0150);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0150: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0150.set_right(p0200);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0200);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0200: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0200.set_right(p0250);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0250);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0250: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0250.set_right(p0300);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0300);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0300: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0300.set_right(p0350);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0350);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0350: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0350.set_right(p0400);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0400);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0400: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0400.set_right(p0450);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0450);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0450: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0450.set_right(p0500);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0500);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0500: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0500.set_right(p0550);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0550);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0550: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0550.set_right(p0600);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0600);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0600: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0600.set_right(p0650);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0650);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0650: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0650.set_right(p0700);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0700);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0700: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0700.set_right(p0750);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0750);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0750: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0750.set_right(p0800);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0800);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0800: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0800.set_right(p0850);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0850);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0850: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0850.set_right(p0900);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0900);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0900: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0900.set_right(p0950);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p0950);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p0950: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p0950.set_right(p1000);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p1000);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p1000: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));
    p1000.set_right(p1050);
    in_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_insert(p1050);
    if (!in_res->parent()) root = in_res;
    ::std::cout << "Added p1050: root = " << **root << ::std::endl;
    output_tree(int_itr(*root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(*root, output_error));

    int_sep_res sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(
        o0000
    );

    ::std::cout << "Removed o0000" << ::std::endl;
    BOOST_TEST(0 == **::std::get<0>(sp_res));
    BOOST_TEST(50 == **::std::get<1>(sp_res));
    output_tree(int_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
    sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(p0100);
    ::std::cout << "Removed p0100" << ::std::endl;
    BOOST_TEST(100 == **::std::get<0>(sp_res));
    BOOST_TEST(150 == **::std::get<1>(sp_res));
    output_tree(int_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
    sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(p0050);
    ::std::cout << "Removed p0050" << ::std::endl;
    BOOST_TEST(50 == **::std::get<0>(sp_res));
    BOOST_TEST(150 == **::std::get<1>(sp_res));
    output_tree(int_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
    sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(p1050);
    ::std::cout << "Removed p1050" << ::std::endl;
    BOOST_TEST(1050 == **::std::get<0>(sp_res));
    BOOST_TEST(!::std::get<1>(sp_res));
    output_tree(int_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
    sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(p1000);
    ::std::cout << "Removed p1000" << ::std::endl;
    BOOST_TEST(1000 == **::std::get<0>(sp_res));
    BOOST_TEST(!::std::get<1>(sp_res));
    output_tree(int_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
    sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(p0800);
    ::std::cout << "Removed p0800" << ::std::endl;
    BOOST_TEST(800 == **::std::get<0>(sp_res));
    BOOST_TEST(850 == **::std::get<1>(sp_res));
    output_tree(int_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
    sp_res = ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::separate(p0300);
    ::std::cout << "Removed p0300" << ::std::endl;
    BOOST_TEST(300 == **::std::get<0>(sp_res));
    BOOST_TEST(350 == **::std::get<1>(sp_res));
    output_tree(int_itr(*::std::get<2>(sp_res), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm::avl_tree_test(*::std::get<2>(sp_res), output_error)
    );
}

#include <string>

typedef ::odds_and_ends::composite_type::composite_type<
    ::boost::mpl::deque<
        ::odds_and_ends::node::data< ::std::string>,
        ::odds_and_ends::node::with_balance_factor,
        ::odds_and_ends::node::tree::base<>,
        ::odds_and_ends::node::tree::binary<>,
        ::odds_and_ends::node::tree::with_height<>,
        ::odds_and_ends::node::tree::with_size<>
    >
> str_tree_node;
typedef ::odds_and_ends::node::in_order_tree_iterator<str_tree_node const> str_itr;
typedef ::std::tuple<
    str_tree_node::traits::pointer,
    str_tree_node::traits::pointer,
    str_tree_node::traits::pointer
> str_sep_res;

void test_post_fill_Z()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_00()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_01()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_02()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_03()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_04()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");
    str_tree_node n_llrll("LLRLL");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    n_llrl.set_left(n_llrll);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_05()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");
    str_tree_node n_llrll("LLRLL");
    str_tree_node n_llrlr("LLRLR");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    n_llrl.set_left(n_llrll);
    n_llrl.set_right(n_llrlr);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_06()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");
    str_tree_node n_llrll("LLRLL");
    str_tree_node n_llrlr("LLRLR");
    str_tree_node n_llrrl("LLRRL");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    n_llrl.set_left(n_llrll);
    n_llrl.set_right(n_llrlr);
    n_llrr.set_left(n_llrrl);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_07()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");
    str_tree_node n_llrll("LLRLL");
    str_tree_node n_llrlr("LLRLR");
    str_tree_node n_llrrl("LLRRL");
    str_tree_node n_llrrr("LLRRR");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    n_llrl.set_left(n_llrll);
    n_llrl.set_right(n_llrlr);
    n_llrr.set_left(n_llrrl);
    n_llrr.set_right(n_llrrr);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_08()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");
    str_tree_node n_llrll("LLRLL");
    str_tree_node n_llrlr("LLRLR");
    str_tree_node n_llrrl("LLRRL");
    str_tree_node n_llrrr("LLRRR");
    str_tree_node n_lrlll("LRLLL");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    n_llrl.set_left(n_llrll);
    n_llrl.set_right(n_llrlr);
    n_llrr.set_left(n_llrrl);
    n_llrr.set_right(n_llrrr);
    n_lrll.set_left(n_lrlll);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_09()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");
    str_tree_node n_llrll("LLRLL");
    str_tree_node n_llrlr("LLRLR");
    str_tree_node n_llrrl("LLRRL");
    str_tree_node n_llrrr("LLRRR");
    str_tree_node n_lrlll("LRLLL");
    str_tree_node n_lrllr("LRLLR");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    n_llrl.set_left(n_llrll);
    n_llrl.set_right(n_llrlr);
    n_llrr.set_left(n_llrrl);
    n_llrr.set_right(n_llrrr);
    n_lrll.set_left(n_lrlll);
    n_lrll.set_right(n_lrllr);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_0A()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");
    str_tree_node n_llrll("LLRLL");
    str_tree_node n_llrlr("LLRLR");
    str_tree_node n_llrrl("LLRRL");
    str_tree_node n_llrrr("LLRRR");
    str_tree_node n_lrlll("LRLLL");
    str_tree_node n_lrllr("LRLLR");
    str_tree_node n_lrlrl("LRLRL");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    n_llrl.set_left(n_llrll);
    n_llrl.set_right(n_llrlr);
    n_llrr.set_left(n_llrrl);
    n_llrr.set_right(n_llrrr);
    n_lrll.set_left(n_lrlll);
    n_lrll.set_right(n_lrllr);
    n_lrlr.set_left(n_lrlrl);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_0B()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");
    str_tree_node n_llrll("LLRLL");
    str_tree_node n_llrlr("LLRLR");
    str_tree_node n_llrrl("LLRRL");
    str_tree_node n_llrrr("LLRRR");
    str_tree_node n_lrlll("LRLLL");
    str_tree_node n_lrllr("LRLLR");
    str_tree_node n_lrlrl("LRLRL");
    str_tree_node n_lrlrr("LRLRR");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    n_llrl.set_left(n_llrll);
    n_llrl.set_right(n_llrlr);
    n_llrr.set_left(n_llrrl);
    n_llrr.set_right(n_llrrr);
    n_lrll.set_left(n_lrlll);
    n_lrll.set_right(n_lrllr);
    n_lrlr.set_left(n_lrlrl);
    n_lrlr.set_right(n_lrlrr);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_0C()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");
    str_tree_node n_llrll("LLRLL");
    str_tree_node n_llrlr("LLRLR");
    str_tree_node n_llrrl("LLRRL");
    str_tree_node n_llrrr("LLRRR");
    str_tree_node n_lrlll("LRLLL");
    str_tree_node n_lrllr("LRLLR");
    str_tree_node n_lrlrl("LRLRL");
    str_tree_node n_lrlrr("LRLRR");
    str_tree_node n_lrrll("LRRLL");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    n_llrl.set_left(n_llrll);
    n_llrl.set_right(n_llrlr);
    n_llrr.set_left(n_llrrl);
    n_llrr.set_right(n_llrrr);
    n_lrll.set_left(n_lrlll);
    n_lrll.set_right(n_lrllr);
    n_lrlr.set_left(n_lrlrl);
    n_lrlr.set_right(n_lrlrr);
    n_lrrl.set_left(n_lrrll);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_0D()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");
    str_tree_node n_llrll("LLRLL");
    str_tree_node n_llrlr("LLRLR");
    str_tree_node n_llrrl("LLRRL");
    str_tree_node n_llrrr("LLRRR");
    str_tree_node n_lrlll("LRLLL");
    str_tree_node n_lrllr("LRLLR");
    str_tree_node n_lrlrl("LRLRL");
    str_tree_node n_lrlrr("LRLRR");
    str_tree_node n_lrrll("LRRLL");
    str_tree_node n_lrrlr("LRRLR");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    n_llrl.set_left(n_llrll);
    n_llrl.set_right(n_llrlr);
    n_llrr.set_left(n_llrrl);
    n_llrr.set_right(n_llrrr);
    n_lrll.set_left(n_lrlll);
    n_lrll.set_right(n_lrllr);
    n_lrlr.set_left(n_lrlrl);
    n_lrlr.set_right(n_lrlrr);
    n_lrrl.set_left(n_lrrll);
    n_lrrl.set_right(n_lrrlr);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_0E()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");
    str_tree_node n_llrll("LLRLL");
    str_tree_node n_llrlr("LLRLR");
    str_tree_node n_llrrl("LLRRL");
    str_tree_node n_llrrr("LLRRR");
    str_tree_node n_lrlll("LRLLL");
    str_tree_node n_lrllr("LRLLR");
    str_tree_node n_lrlrl("LRLRL");
    str_tree_node n_lrlrr("LRLRR");
    str_tree_node n_lrrll("LRRLL");
    str_tree_node n_lrrlr("LRRLR");
    str_tree_node n_lrrrl("LRRRL");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    n_llrl.set_left(n_llrll);
    n_llrl.set_right(n_llrlr);
    n_llrr.set_left(n_llrrl);
    n_llrr.set_right(n_llrrr);
    n_lrll.set_left(n_lrlll);
    n_lrll.set_right(n_lrllr);
    n_lrlr.set_left(n_lrlrl);
    n_lrlr.set_right(n_lrlrr);
    n_lrrl.set_left(n_lrrll);
    n_lrrl.set_right(n_lrrlr);
    n_lrrr.set_left(n_lrrrl);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_0F()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");
    str_tree_node n_llrll("LLRLL");
    str_tree_node n_llrlr("LLRLR");
    str_tree_node n_llrrl("LLRRL");
    str_tree_node n_llrrr("LLRRR");
    str_tree_node n_lrlll("LRLLL");
    str_tree_node n_lrllr("LRLLR");
    str_tree_node n_lrlrl("LRLRL");
    str_tree_node n_lrlrr("LRLRR");
    str_tree_node n_lrrll("LRRLL");
    str_tree_node n_lrrlr("LRRLR");
    str_tree_node n_lrrrl("LRRRL");
    str_tree_node n_lrrrr("LRRRR");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    n_llrl.set_left(n_llrll);
    n_llrl.set_right(n_llrlr);
    n_llrr.set_left(n_llrrl);
    n_llrr.set_right(n_llrrr);
    n_lrll.set_left(n_lrlll);
    n_lrll.set_right(n_lrllr);
    n_lrlr.set_left(n_lrlrl);
    n_lrlr.set_right(n_lrlrr);
    n_lrrl.set_left(n_lrrll);
    n_lrrl.set_right(n_lrrlr);
    n_lrrr.set_left(n_lrrrl);
    n_lrrr.set_right(n_lrrrr);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_10()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");
    str_tree_node n_llrll("LLRLL");
    str_tree_node n_llrlr("LLRLR");
    str_tree_node n_llrrl("LLRRL");
    str_tree_node n_llrrr("LLRRR");
    str_tree_node n_lrlll("LRLLL");
    str_tree_node n_lrllr("LRLLR");
    str_tree_node n_lrlrl("LRLRL");
    str_tree_node n_lrlrr("LRLRR");
    str_tree_node n_lrrll("LRRLL");
    str_tree_node n_lrrlr("LRRLR");
    str_tree_node n_lrrrl("LRRRL");
    str_tree_node n_lrrrr("LRRRR");
    str_tree_node n_rllll("RLLLL");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    n_llrl.set_left(n_llrll);
    n_llrl.set_right(n_llrlr);
    n_llrr.set_left(n_llrrl);
    n_llrr.set_right(n_llrrr);
    n_lrll.set_left(n_lrlll);
    n_lrll.set_right(n_lrllr);
    n_lrlr.set_left(n_lrlrl);
    n_lrlr.set_right(n_lrlrr);
    n_lrrl.set_left(n_lrrll);
    n_lrrl.set_right(n_lrrlr);
    n_lrrr.set_left(n_lrrrl);
    n_lrrr.set_right(n_lrrrr);
    n_rlll.set_left(n_rllll);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_11()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");
    str_tree_node n_llrll("LLRLL");
    str_tree_node n_llrlr("LLRLR");
    str_tree_node n_llrrl("LLRRL");
    str_tree_node n_llrrr("LLRRR");
    str_tree_node n_lrlll("LRLLL");
    str_tree_node n_lrllr("LRLLR");
    str_tree_node n_lrlrl("LRLRL");
    str_tree_node n_lrlrr("LRLRR");
    str_tree_node n_lrrll("LRRLL");
    str_tree_node n_lrrlr("LRRLR");
    str_tree_node n_lrrrl("LRRRL");
    str_tree_node n_lrrrr("LRRRR");
    str_tree_node n_rllll("RLLLL");
    str_tree_node n_rlllr("RLLLR");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    n_llrl.set_left(n_llrll);
    n_llrl.set_right(n_llrlr);
    n_llrr.set_left(n_llrrl);
    n_llrr.set_right(n_llrrr);
    n_lrll.set_left(n_lrlll);
    n_lrll.set_right(n_lrllr);
    n_lrlr.set_left(n_lrlrl);
    n_lrlr.set_right(n_lrlrr);
    n_lrrl.set_left(n_lrrll);
    n_lrrl.set_right(n_lrrlr);
    n_lrrr.set_left(n_lrrrl);
    n_lrrr.set_right(n_lrrrr);
    n_rlll.set_left(n_rllll);
    n_rlll.set_right(n_rlllr);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_12()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");
    str_tree_node n_llrll("LLRLL");
    str_tree_node n_llrlr("LLRLR");
    str_tree_node n_llrrl("LLRRL");
    str_tree_node n_llrrr("LLRRR");
    str_tree_node n_lrlll("LRLLL");
    str_tree_node n_lrllr("LRLLR");
    str_tree_node n_lrlrl("LRLRL");
    str_tree_node n_lrlrr("LRLRR");
    str_tree_node n_lrrll("LRRLL");
    str_tree_node n_lrrlr("LRRLR");
    str_tree_node n_lrrrl("LRRRL");
    str_tree_node n_lrrrr("LRRRR");
    str_tree_node n_rllll("RLLLL");
    str_tree_node n_rlllr("RLLLR");
    str_tree_node n_rllrl("RLLRL");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    n_llrl.set_left(n_llrll);
    n_llrl.set_right(n_llrlr);
    n_llrr.set_left(n_llrrl);
    n_llrr.set_right(n_llrrr);
    n_lrll.set_left(n_lrlll);
    n_lrll.set_right(n_lrllr);
    n_lrlr.set_left(n_lrlrl);
    n_lrlr.set_right(n_lrlrr);
    n_lrrl.set_left(n_lrrll);
    n_lrrl.set_right(n_lrrlr);
    n_lrrr.set_left(n_lrrrl);
    n_lrrr.set_right(n_lrrrr);
    n_rlll.set_left(n_rllll);
    n_rlll.set_right(n_rlllr);
    n_rllr.set_left(n_rllrl);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_13()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");
    str_tree_node n_llrll("LLRLL");
    str_tree_node n_llrlr("LLRLR");
    str_tree_node n_llrrl("LLRRL");
    str_tree_node n_llrrr("LLRRR");
    str_tree_node n_lrlll("LRLLL");
    str_tree_node n_lrllr("LRLLR");
    str_tree_node n_lrlrl("LRLRL");
    str_tree_node n_lrlrr("LRLRR");
    str_tree_node n_lrrll("LRRLL");
    str_tree_node n_lrrlr("LRRLR");
    str_tree_node n_lrrrl("LRRRL");
    str_tree_node n_lrrrr("LRRRR");
    str_tree_node n_rllll("RLLLL");
    str_tree_node n_rlllr("RLLLR");
    str_tree_node n_rllrl("RLLRL");
    str_tree_node n_rllrr("RLLRR");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    n_llrl.set_left(n_llrll);
    n_llrl.set_right(n_llrlr);
    n_llrr.set_left(n_llrrl);
    n_llrr.set_right(n_llrrr);
    n_lrll.set_left(n_lrlll);
    n_lrll.set_right(n_lrllr);
    n_lrlr.set_left(n_lrlrl);
    n_lrlr.set_right(n_lrlrr);
    n_lrrl.set_left(n_lrrll);
    n_lrrl.set_right(n_lrrlr);
    n_lrrr.set_left(n_lrrrl);
    n_lrrr.set_right(n_lrrrr);
    n_rlll.set_left(n_rllll);
    n_rlll.set_right(n_rlllr);
    n_rllr.set_left(n_rllrl);
    n_rllr.set_right(n_rllrr);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_14()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");
    str_tree_node n_llrll("LLRLL");
    str_tree_node n_llrlr("LLRLR");
    str_tree_node n_llrrl("LLRRL");
    str_tree_node n_llrrr("LLRRR");
    str_tree_node n_lrlll("LRLLL");
    str_tree_node n_lrllr("LRLLR");
    str_tree_node n_lrlrl("LRLRL");
    str_tree_node n_lrlrr("LRLRR");
    str_tree_node n_lrrll("LRRLL");
    str_tree_node n_lrrlr("LRRLR");
    str_tree_node n_lrrrl("LRRRL");
    str_tree_node n_lrrrr("LRRRR");
    str_tree_node n_rllll("RLLLL");
    str_tree_node n_rlllr("RLLLR");
    str_tree_node n_rllrl("RLLRL");
    str_tree_node n_rllrr("RLLRR");
    str_tree_node n_rlrll("RLRLL");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    n_llrl.set_left(n_llrll);
    n_llrl.set_right(n_llrlr);
    n_llrr.set_left(n_llrrl);
    n_llrr.set_right(n_llrrr);
    n_lrll.set_left(n_lrlll);
    n_lrll.set_right(n_lrllr);
    n_lrlr.set_left(n_lrlrl);
    n_lrlr.set_right(n_lrlrr);
    n_lrrl.set_left(n_lrrll);
    n_lrrl.set_right(n_lrrlr);
    n_lrrr.set_left(n_lrrrl);
    n_lrrr.set_right(n_lrrrr);
    n_rlll.set_left(n_rllll);
    n_rlll.set_right(n_rlllr);
    n_rllr.set_left(n_rllrl);
    n_rllr.set_right(n_rllrr);
    n_rlrl.set_left(n_rlrll);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_15()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");
    str_tree_node n_llrll("LLRLL");
    str_tree_node n_llrlr("LLRLR");
    str_tree_node n_llrrl("LLRRL");
    str_tree_node n_llrrr("LLRRR");
    str_tree_node n_lrlll("LRLLL");
    str_tree_node n_lrllr("LRLLR");
    str_tree_node n_lrlrl("LRLRL");
    str_tree_node n_lrlrr("LRLRR");
    str_tree_node n_lrrll("LRRLL");
    str_tree_node n_lrrlr("LRRLR");
    str_tree_node n_lrrrl("LRRRL");
    str_tree_node n_lrrrr("LRRRR");
    str_tree_node n_rllll("RLLLL");
    str_tree_node n_rlllr("RLLLR");
    str_tree_node n_rllrl("RLLRL");
    str_tree_node n_rllrr("RLLRR");
    str_tree_node n_rlrll("RLRLL");
    str_tree_node n_rlrlr("RLRLR");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    n_llrl.set_left(n_llrll);
    n_llrl.set_right(n_llrlr);
    n_llrr.set_left(n_llrrl);
    n_llrr.set_right(n_llrrr);
    n_lrll.set_left(n_lrlll);
    n_lrll.set_right(n_lrllr);
    n_lrlr.set_left(n_lrlrl);
    n_lrlr.set_right(n_lrlrr);
    n_lrrl.set_left(n_lrrll);
    n_lrrl.set_right(n_lrrlr);
    n_lrrr.set_left(n_lrrrl);
    n_lrrr.set_right(n_lrrrr);
    n_rlll.set_left(n_rllll);
    n_rlll.set_right(n_rlllr);
    n_rllr.set_left(n_rllrl);
    n_rllr.set_right(n_rllrr);
    n_rlrl.set_left(n_rlrll);
    n_rlrl.set_right(n_rlrlr);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_16()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");
    str_tree_node n_llrll("LLRLL");
    str_tree_node n_llrlr("LLRLR");
    str_tree_node n_llrrl("LLRRL");
    str_tree_node n_llrrr("LLRRR");
    str_tree_node n_lrlll("LRLLL");
    str_tree_node n_lrllr("LRLLR");
    str_tree_node n_lrlrl("LRLRL");
    str_tree_node n_lrlrr("LRLRR");
    str_tree_node n_lrrll("LRRLL");
    str_tree_node n_lrrlr("LRRLR");
    str_tree_node n_lrrrl("LRRRL");
    str_tree_node n_lrrrr("LRRRR");
    str_tree_node n_rllll("RLLLL");
    str_tree_node n_rlllr("RLLLR");
    str_tree_node n_rllrl("RLLRL");
    str_tree_node n_rllrr("RLLRR");
    str_tree_node n_rlrll("RLRLL");
    str_tree_node n_rlrlr("RLRLR");
    str_tree_node n_rlrrl("RLRRL");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    n_llrl.set_left(n_llrll);
    n_llrl.set_right(n_llrlr);
    n_llrr.set_left(n_llrrl);
    n_llrr.set_right(n_llrrr);
    n_lrll.set_left(n_lrlll);
    n_lrll.set_right(n_lrllr);
    n_lrlr.set_left(n_lrlrl);
    n_lrlr.set_right(n_lrlrr);
    n_lrrl.set_left(n_lrrll);
    n_lrrl.set_right(n_lrrlr);
    n_lrrr.set_left(n_lrrrl);
    n_lrrr.set_right(n_lrrrr);
    n_rlll.set_left(n_rllll);
    n_rlll.set_right(n_rlllr);
    n_rllr.set_left(n_rllrl);
    n_rllr.set_right(n_rllrr);
    n_rlrl.set_left(n_rlrll);
    n_rlrl.set_right(n_rlrlr);
    n_rlrr.set_left(n_rlrrl);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_17()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");
    str_tree_node n_llrll("LLRLL");
    str_tree_node n_llrlr("LLRLR");
    str_tree_node n_llrrl("LLRRL");
    str_tree_node n_llrrr("LLRRR");
    str_tree_node n_lrlll("LRLLL");
    str_tree_node n_lrllr("LRLLR");
    str_tree_node n_lrlrl("LRLRL");
    str_tree_node n_lrlrr("LRLRR");
    str_tree_node n_lrrll("LRRLL");
    str_tree_node n_lrrlr("LRRLR");
    str_tree_node n_lrrrl("LRRRL");
    str_tree_node n_lrrrr("LRRRR");
    str_tree_node n_rllll("RLLLL");
    str_tree_node n_rlllr("RLLLR");
    str_tree_node n_rllrl("RLLRL");
    str_tree_node n_rllrr("RLLRR");
    str_tree_node n_rlrll("RLRLL");
    str_tree_node n_rlrlr("RLRLR");
    str_tree_node n_rlrrl("RLRRL");
    str_tree_node n_rlrrr("RLRRR");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    n_llrl.set_left(n_llrll);
    n_llrl.set_right(n_llrlr);
    n_llrr.set_left(n_llrrl);
    n_llrr.set_right(n_llrrr);
    n_lrll.set_left(n_lrlll);
    n_lrll.set_right(n_lrllr);
    n_lrlr.set_left(n_lrlrl);
    n_lrlr.set_right(n_lrlrr);
    n_lrrl.set_left(n_lrrll);
    n_lrrl.set_right(n_lrrlr);
    n_lrrr.set_left(n_lrrrl);
    n_lrrr.set_right(n_lrrrr);
    n_rlll.set_left(n_rllll);
    n_rlll.set_right(n_rlllr);
    n_rllr.set_left(n_rllrl);
    n_rllr.set_right(n_rllrr);
    n_rlrl.set_left(n_rlrll);
    n_rlrl.set_right(n_rlrlr);
    n_rlrr.set_left(n_rlrrl);
    n_rlrr.set_right(n_rlrrr);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_18()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");
    str_tree_node n_llrll("LLRLL");
    str_tree_node n_llrlr("LLRLR");
    str_tree_node n_llrrl("LLRRL");
    str_tree_node n_llrrr("LLRRR");
    str_tree_node n_lrlll("LRLLL");
    str_tree_node n_lrllr("LRLLR");
    str_tree_node n_lrlrl("LRLRL");
    str_tree_node n_lrlrr("LRLRR");
    str_tree_node n_lrrll("LRRLL");
    str_tree_node n_lrrlr("LRRLR");
    str_tree_node n_lrrrl("LRRRL");
    str_tree_node n_lrrrr("LRRRR");
    str_tree_node n_rllll("RLLLL");
    str_tree_node n_rlllr("RLLLR");
    str_tree_node n_rllrl("RLLRL");
    str_tree_node n_rllrr("RLLRR");
    str_tree_node n_rlrll("RLRLL");
    str_tree_node n_rlrlr("RLRLR");
    str_tree_node n_rlrrl("RLRRL");
    str_tree_node n_rlrrr("RLRRR");
    str_tree_node n_rrlll("RRLLL");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    n_llrl.set_left(n_llrll);
    n_llrl.set_right(n_llrlr);
    n_llrr.set_left(n_llrrl);
    n_llrr.set_right(n_llrrr);
    n_lrll.set_left(n_lrlll);
    n_lrll.set_right(n_lrllr);
    n_lrlr.set_left(n_lrlrl);
    n_lrlr.set_right(n_lrlrr);
    n_lrrl.set_left(n_lrrll);
    n_lrrl.set_right(n_lrrlr);
    n_lrrr.set_left(n_lrrrl);
    n_lrrr.set_right(n_lrrrr);
    n_rlll.set_left(n_rllll);
    n_rlll.set_right(n_rlllr);
    n_rllr.set_left(n_rllrl);
    n_rllr.set_right(n_rllrr);
    n_rlrl.set_left(n_rlrll);
    n_rlrl.set_right(n_rlrlr);
    n_rlrr.set_left(n_rlrrl);
    n_rlrr.set_right(n_rlrrr);
    n_rrll.set_left(n_rrlll);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_19()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");
    str_tree_node n_llrll("LLRLL");
    str_tree_node n_llrlr("LLRLR");
    str_tree_node n_llrrl("LLRRL");
    str_tree_node n_llrrr("LLRRR");
    str_tree_node n_lrlll("LRLLL");
    str_tree_node n_lrllr("LRLLR");
    str_tree_node n_lrlrl("LRLRL");
    str_tree_node n_lrlrr("LRLRR");
    str_tree_node n_lrrll("LRRLL");
    str_tree_node n_lrrlr("LRRLR");
    str_tree_node n_lrrrl("LRRRL");
    str_tree_node n_lrrrr("LRRRR");
    str_tree_node n_rllll("RLLLL");
    str_tree_node n_rlllr("RLLLR");
    str_tree_node n_rllrl("RLLRL");
    str_tree_node n_rllrr("RLLRR");
    str_tree_node n_rlrll("RLRLL");
    str_tree_node n_rlrlr("RLRLR");
    str_tree_node n_rlrrl("RLRRL");
    str_tree_node n_rlrrr("RLRRR");
    str_tree_node n_rrlll("RRLLL");
    str_tree_node n_rrllr("RRLLR");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    n_llrl.set_left(n_llrll);
    n_llrl.set_right(n_llrlr);
    n_llrr.set_left(n_llrrl);
    n_llrr.set_right(n_llrrr);
    n_lrll.set_left(n_lrlll);
    n_lrll.set_right(n_lrllr);
    n_lrlr.set_left(n_lrlrl);
    n_lrlr.set_right(n_lrlrr);
    n_lrrl.set_left(n_lrrll);
    n_lrrl.set_right(n_lrrlr);
    n_lrrr.set_left(n_lrrrl);
    n_lrrr.set_right(n_lrrrr);
    n_rlll.set_left(n_rllll);
    n_rlll.set_right(n_rlllr);
    n_rllr.set_left(n_rllrl);
    n_rllr.set_right(n_rllrr);
    n_rlrl.set_left(n_rlrll);
    n_rlrl.set_right(n_rlrlr);
    n_rlrr.set_left(n_rlrrl);
    n_rlrr.set_right(n_rlrrr);
    n_rrll.set_left(n_rrlll);
    n_rrll.set_right(n_rrllr);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_1A()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");
    str_tree_node n_llrll("LLRLL");
    str_tree_node n_llrlr("LLRLR");
    str_tree_node n_llrrl("LLRRL");
    str_tree_node n_llrrr("LLRRR");
    str_tree_node n_lrlll("LRLLL");
    str_tree_node n_lrllr("LRLLR");
    str_tree_node n_lrlrl("LRLRL");
    str_tree_node n_lrlrr("LRLRR");
    str_tree_node n_lrrll("LRRLL");
    str_tree_node n_lrrlr("LRRLR");
    str_tree_node n_lrrrl("LRRRL");
    str_tree_node n_lrrrr("LRRRR");
    str_tree_node n_rllll("RLLLL");
    str_tree_node n_rlllr("RLLLR");
    str_tree_node n_rllrl("RLLRL");
    str_tree_node n_rllrr("RLLRR");
    str_tree_node n_rlrll("RLRLL");
    str_tree_node n_rlrlr("RLRLR");
    str_tree_node n_rlrrl("RLRRL");
    str_tree_node n_rlrrr("RLRRR");
    str_tree_node n_rrlll("RRLLL");
    str_tree_node n_rrllr("RRLLR");
    str_tree_node n_rrlrl("RRLRL");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    n_llrl.set_left(n_llrll);
    n_llrl.set_right(n_llrlr);
    n_llrr.set_left(n_llrrl);
    n_llrr.set_right(n_llrrr);
    n_lrll.set_left(n_lrlll);
    n_lrll.set_right(n_lrllr);
    n_lrlr.set_left(n_lrlrl);
    n_lrlr.set_right(n_lrlrr);
    n_lrrl.set_left(n_lrrll);
    n_lrrl.set_right(n_lrrlr);
    n_lrrr.set_left(n_lrrrl);
    n_lrrr.set_right(n_lrrrr);
    n_rlll.set_left(n_rllll);
    n_rlll.set_right(n_rlllr);
    n_rllr.set_left(n_rllrl);
    n_rllr.set_right(n_rllrr);
    n_rlrl.set_left(n_rlrll);
    n_rlrl.set_right(n_rlrlr);
    n_rlrr.set_left(n_rlrrl);
    n_rlrr.set_right(n_rlrrr);
    n_rrll.set_left(n_rrlll);
    n_rrll.set_right(n_rrllr);
    n_rrlr.set_left(n_rrlrl);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_1B()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");
    str_tree_node n_llrll("LLRLL");
    str_tree_node n_llrlr("LLRLR");
    str_tree_node n_llrrl("LLRRL");
    str_tree_node n_llrrr("LLRRR");
    str_tree_node n_lrlll("LRLLL");
    str_tree_node n_lrllr("LRLLR");
    str_tree_node n_lrlrl("LRLRL");
    str_tree_node n_lrlrr("LRLRR");
    str_tree_node n_lrrll("LRRLL");
    str_tree_node n_lrrlr("LRRLR");
    str_tree_node n_lrrrl("LRRRL");
    str_tree_node n_lrrrr("LRRRR");
    str_tree_node n_rllll("RLLLL");
    str_tree_node n_rlllr("RLLLR");
    str_tree_node n_rllrl("RLLRL");
    str_tree_node n_rllrr("RLLRR");
    str_tree_node n_rlrll("RLRLL");
    str_tree_node n_rlrlr("RLRLR");
    str_tree_node n_rlrrl("RLRRL");
    str_tree_node n_rlrrr("RLRRR");
    str_tree_node n_rrlll("RRLLL");
    str_tree_node n_rrllr("RRLLR");
    str_tree_node n_rrlrl("RRLRL");
    str_tree_node n_rrlrr("RRLRR");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    n_llrl.set_left(n_llrll);
    n_llrl.set_right(n_llrlr);
    n_llrr.set_left(n_llrrl);
    n_llrr.set_right(n_llrrr);
    n_lrll.set_left(n_lrlll);
    n_lrll.set_right(n_lrllr);
    n_lrlr.set_left(n_lrlrl);
    n_lrlr.set_right(n_lrlrr);
    n_lrrl.set_left(n_lrrll);
    n_lrrl.set_right(n_lrrlr);
    n_lrrr.set_left(n_lrrrl);
    n_lrrr.set_right(n_lrrrr);
    n_rlll.set_left(n_rllll);
    n_rlll.set_right(n_rlllr);
    n_rllr.set_left(n_rllrl);
    n_rllr.set_right(n_rllrr);
    n_rlrl.set_left(n_rlrll);
    n_rlrl.set_right(n_rlrlr);
    n_rlrr.set_left(n_rlrrl);
    n_rlrr.set_right(n_rlrrr);
    n_rrll.set_left(n_rrlll);
    n_rrll.set_right(n_rrllr);
    n_rrlr.set_left(n_rrlrl);
    n_rrlr.set_right(n_rrlrr);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_1C()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");
    str_tree_node n_llrll("LLRLL");
    str_tree_node n_llrlr("LLRLR");
    str_tree_node n_llrrl("LLRRL");
    str_tree_node n_llrrr("LLRRR");
    str_tree_node n_lrlll("LRLLL");
    str_tree_node n_lrllr("LRLLR");
    str_tree_node n_lrlrl("LRLRL");
    str_tree_node n_lrlrr("LRLRR");
    str_tree_node n_lrrll("LRRLL");
    str_tree_node n_lrrlr("LRRLR");
    str_tree_node n_lrrrl("LRRRL");
    str_tree_node n_lrrrr("LRRRR");
    str_tree_node n_rllll("RLLLL");
    str_tree_node n_rlllr("RLLLR");
    str_tree_node n_rllrl("RLLRL");
    str_tree_node n_rllrr("RLLRR");
    str_tree_node n_rlrll("RLRLL");
    str_tree_node n_rlrlr("RLRLR");
    str_tree_node n_rlrrl("RLRRL");
    str_tree_node n_rlrrr("RLRRR");
    str_tree_node n_rrlll("RRLLL");
    str_tree_node n_rrllr("RRLLR");
    str_tree_node n_rrlrl("RRLRL");
    str_tree_node n_rrlrr("RRLRR");
    str_tree_node n_rrrll("RRRLL");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    n_llrl.set_left(n_llrll);
    n_llrl.set_right(n_llrlr);
    n_llrr.set_left(n_llrrl);
    n_llrr.set_right(n_llrrr);
    n_lrll.set_left(n_lrlll);
    n_lrll.set_right(n_lrllr);
    n_lrlr.set_left(n_lrlrl);
    n_lrlr.set_right(n_lrlrr);
    n_lrrl.set_left(n_lrrll);
    n_lrrl.set_right(n_lrrlr);
    n_lrrr.set_left(n_lrrrl);
    n_lrrr.set_right(n_lrrrr);
    n_rlll.set_left(n_rllll);
    n_rlll.set_right(n_rlllr);
    n_rllr.set_left(n_rllrl);
    n_rllr.set_right(n_rllrr);
    n_rlrl.set_left(n_rlrll);
    n_rlrl.set_right(n_rlrlr);
    n_rlrr.set_left(n_rlrrl);
    n_rlrr.set_right(n_rlrrr);
    n_rrll.set_left(n_rrlll);
    n_rrll.set_right(n_rrllr);
    n_rrlr.set_left(n_rrlrl);
    n_rrlr.set_right(n_rrlrr);
    n_rrrl.set_left(n_rrrll);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_1D()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");
    str_tree_node n_llrll("LLRLL");
    str_tree_node n_llrlr("LLRLR");
    str_tree_node n_llrrl("LLRRL");
    str_tree_node n_llrrr("LLRRR");
    str_tree_node n_lrlll("LRLLL");
    str_tree_node n_lrllr("LRLLR");
    str_tree_node n_lrlrl("LRLRL");
    str_tree_node n_lrlrr("LRLRR");
    str_tree_node n_lrrll("LRRLL");
    str_tree_node n_lrrlr("LRRLR");
    str_tree_node n_lrrrl("LRRRL");
    str_tree_node n_lrrrr("LRRRR");
    str_tree_node n_rllll("RLLLL");
    str_tree_node n_rlllr("RLLLR");
    str_tree_node n_rllrl("RLLRL");
    str_tree_node n_rllrr("RLLRR");
    str_tree_node n_rlrll("RLRLL");
    str_tree_node n_rlrlr("RLRLR");
    str_tree_node n_rlrrl("RLRRL");
    str_tree_node n_rlrrr("RLRRR");
    str_tree_node n_rrlll("RRLLL");
    str_tree_node n_rrllr("RRLLR");
    str_tree_node n_rrlrl("RRLRL");
    str_tree_node n_rrlrr("RRLRR");
    str_tree_node n_rrrll("RRRLL");
    str_tree_node n_rrrlr("RRRLR");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    n_llrl.set_left(n_llrll);
    n_llrl.set_right(n_llrlr);
    n_llrr.set_left(n_llrrl);
    n_llrr.set_right(n_llrrr);
    n_lrll.set_left(n_lrlll);
    n_lrll.set_right(n_lrllr);
    n_lrlr.set_left(n_lrlrl);
    n_lrlr.set_right(n_lrlrr);
    n_lrrl.set_left(n_lrrll);
    n_lrrl.set_right(n_lrrlr);
    n_lrrr.set_left(n_lrrrl);
    n_lrrr.set_right(n_lrrrr);
    n_rlll.set_left(n_rllll);
    n_rlll.set_right(n_rlllr);
    n_rllr.set_left(n_rllrl);
    n_rllr.set_right(n_rllrr);
    n_rlrl.set_left(n_rlrll);
    n_rlrl.set_right(n_rlrlr);
    n_rlrr.set_left(n_rlrrl);
    n_rlrr.set_right(n_rlrrr);
    n_rrll.set_left(n_rrlll);
    n_rrll.set_right(n_rrllr);
    n_rrlr.set_left(n_rrlrl);
    n_rrlr.set_right(n_rrlrr);
    n_rrrl.set_left(n_rrrll);
    n_rrrl.set_right(n_rrrlr);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_1E()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");
    str_tree_node n_llrll("LLRLL");
    str_tree_node n_llrlr("LLRLR");
    str_tree_node n_llrrl("LLRRL");
    str_tree_node n_llrrr("LLRRR");
    str_tree_node n_lrlll("LRLLL");
    str_tree_node n_lrllr("LRLLR");
    str_tree_node n_lrlrl("LRLRL");
    str_tree_node n_lrlrr("LRLRR");
    str_tree_node n_lrrll("LRRLL");
    str_tree_node n_lrrlr("LRRLR");
    str_tree_node n_lrrrl("LRRRL");
    str_tree_node n_lrrrr("LRRRR");
    str_tree_node n_rllll("RLLLL");
    str_tree_node n_rlllr("RLLLR");
    str_tree_node n_rllrl("RLLRL");
    str_tree_node n_rllrr("RLLRR");
    str_tree_node n_rlrll("RLRLL");
    str_tree_node n_rlrlr("RLRLR");
    str_tree_node n_rlrrl("RLRRL");
    str_tree_node n_rlrrr("RLRRR");
    str_tree_node n_rrlll("RRLLL");
    str_tree_node n_rrllr("RRLLR");
    str_tree_node n_rrlrl("RRLRL");
    str_tree_node n_rrlrr("RRLRR");
    str_tree_node n_rrrll("RRRLL");
    str_tree_node n_rrrlr("RRRLR");
    str_tree_node n_rrrrl("RRRRL");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    n_llrl.set_left(n_llrll);
    n_llrl.set_right(n_llrlr);
    n_llrr.set_left(n_llrrl);
    n_llrr.set_right(n_llrrr);
    n_lrll.set_left(n_lrlll);
    n_lrll.set_right(n_lrllr);
    n_lrlr.set_left(n_lrlrl);
    n_lrlr.set_right(n_lrlrr);
    n_lrrl.set_left(n_lrrll);
    n_lrrl.set_right(n_lrrlr);
    n_lrrr.set_left(n_lrrrl);
    n_lrrr.set_right(n_lrrrr);
    n_rlll.set_left(n_rllll);
    n_rlll.set_right(n_rlllr);
    n_rllr.set_left(n_rllrl);
    n_rllr.set_right(n_rllrr);
    n_rlrl.set_left(n_rlrll);
    n_rlrl.set_right(n_rlrlr);
    n_rlrr.set_left(n_rlrrl);
    n_rlrr.set_right(n_rlrrr);
    n_rrll.set_left(n_rrlll);
    n_rrll.set_right(n_rrllr);
    n_rrlr.set_left(n_rrlrl);
    n_rrlr.set_right(n_rrlrr);
    n_rrrl.set_left(n_rrrll);
    n_rrrl.set_right(n_rrrlr);
    n_rrrr.set_left(n_rrrrl);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

void test_post_fill_1F()
{
    output_error_t output_error;
    str_tree_node n_root("0");
    str_tree_node n_l("L");
    str_tree_node n_r("R");
    str_tree_node n_ll("LL");
    str_tree_node n_lr("LR");
    str_tree_node n_rl("RL");
    str_tree_node n_rr("RR");
    str_tree_node n_lll("LLL");
    str_tree_node n_llr("LLR");
    str_tree_node n_lrl("LRL");
    str_tree_node n_lrr("LRR");
    str_tree_node n_rll("RLL");
    str_tree_node n_rlr("RLR");
    str_tree_node n_rrl("RRL");
    str_tree_node n_rrr("RRR");
    str_tree_node n_llll("LLLL");
    str_tree_node n_lllr("LLLR");
    str_tree_node n_llrl("LLRL");
    str_tree_node n_llrr("LLRR");
    str_tree_node n_lrll("LRLL");
    str_tree_node n_lrlr("LRLR");
    str_tree_node n_lrrl("LRRL");
    str_tree_node n_lrrr("LRRR");
    str_tree_node n_rlll("RLLL");
    str_tree_node n_rllr("RLLR");
    str_tree_node n_rlrl("RLRL");
    str_tree_node n_rlrr("RLRR");
    str_tree_node n_rrll("RRLL");
    str_tree_node n_rrlr("RRLR");
    str_tree_node n_rrrl("RRRL");
    str_tree_node n_rrrr("RRRR");
    str_tree_node n_lllll("LLLLL");
    str_tree_node n_llllr("LLLLR");
    str_tree_node n_lllrl("LLLRL");
    str_tree_node n_lllrr("LLLRR");
    str_tree_node n_llrll("LLRLL");
    str_tree_node n_llrlr("LLRLR");
    str_tree_node n_llrrl("LLRRL");
    str_tree_node n_llrrr("LLRRR");
    str_tree_node n_lrlll("LRLLL");
    str_tree_node n_lrllr("LRLLR");
    str_tree_node n_lrlrl("LRLRL");
    str_tree_node n_lrlrr("LRLRR");
    str_tree_node n_lrrll("LRRLL");
    str_tree_node n_lrrlr("LRRLR");
    str_tree_node n_lrrrl("LRRRL");
    str_tree_node n_lrrrr("LRRRR");
    str_tree_node n_rllll("RLLLL");
    str_tree_node n_rlllr("RLLLR");
    str_tree_node n_rllrl("RLLRL");
    str_tree_node n_rllrr("RLLRR");
    str_tree_node n_rlrll("RLRLL");
    str_tree_node n_rlrlr("RLRLR");
    str_tree_node n_rlrrl("RLRRL");
    str_tree_node n_rlrrr("RLRRR");
    str_tree_node n_rrlll("RRLLL");
    str_tree_node n_rrllr("RRLLR");
    str_tree_node n_rrlrl("RRLRL");
    str_tree_node n_rrlrr("RRLRR");
    str_tree_node n_rrrll("RRRLL");
    str_tree_node n_rrrlr("RRRLR");
    str_tree_node n_rrrrl("RRRRL");
    str_tree_node n_rrrrr("RRRRR");

    n_root.set_left(n_l);
    n_root.set_right(n_r);
    n_l.set_left(n_ll);
    n_l.set_right(n_lr);
    n_r.set_left(n_rl);
    n_r.set_right(n_rr);
    n_ll.set_left(n_lll);
    n_ll.set_right(n_llr);
    n_lr.set_left(n_lrl);
    n_lr.set_right(n_lrr);
    n_rl.set_left(n_rll);
    n_rl.set_right(n_rlr);
    n_rr.set_left(n_rrl);
    n_rr.set_right(n_rrr);
    n_lll.set_left(n_llll);
    n_lll.set_right(n_lllr);
    n_llr.set_left(n_llrl);
    n_llr.set_right(n_llrr);
    n_lrl.set_left(n_lrll);
    n_lrl.set_right(n_lrlr);
    n_lrr.set_left(n_lrrl);
    n_lrr.set_right(n_lrrr);
    n_rll.set_left(n_rlll);
    n_rll.set_right(n_rllr);
    n_rlr.set_left(n_rlrl);
    n_rlr.set_right(n_rlrr);
    n_rrl.set_left(n_rrll);
    n_rrl.set_right(n_rrlr);
    n_rrr.set_left(n_rrrl);
    n_rrr.set_right(n_rrrr);
    n_llll.set_left(n_lllll);
    n_llll.set_right(n_llllr);
    n_lllr.set_left(n_lllrl);
    n_lllr.set_right(n_lllrr);
    n_llrl.set_left(n_llrll);
    n_llrl.set_right(n_llrlr);
    n_llrr.set_left(n_llrrl);
    n_llrr.set_right(n_llrrr);
    n_lrll.set_left(n_lrlll);
    n_lrll.set_right(n_lrllr);
    n_lrlr.set_left(n_lrlrl);
    n_lrlr.set_right(n_lrlrr);
    n_lrrl.set_left(n_lrrll);
    n_lrrl.set_right(n_lrrlr);
    n_lrrr.set_left(n_lrrrl);
    n_lrrr.set_right(n_lrrrr);
    n_rlll.set_left(n_rllll);
    n_rlll.set_right(n_rlllr);
    n_rllr.set_left(n_rllrl);
    n_rllr.set_right(n_rllrr);
    n_rlrl.set_left(n_rlrll);
    n_rlrl.set_right(n_rlrlr);
    n_rlrr.set_left(n_rlrrl);
    n_rlrr.set_right(n_rlrrr);
    n_rrll.set_left(n_rrlll);
    n_rrll.set_right(n_rrllr);
    n_rrlr.set_left(n_rrlrl);
    n_rrlr.set_right(n_rrlrr);
    n_rrrl.set_left(n_rrrll);
    n_rrrl.set_right(n_rrrlr);
    n_rrrr.set_left(n_rrrrl);
    n_rrrr.set_right(n_rrrrr);
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer::post_fill(n_root);
    output_tree(str_itr(n_root, false));
    BOOST_TEST(::odds_and_ends::node::algorithm::avl_tree_test(n_root, output_error));
}

int main(int argc, char** argv)
{
    test_char_00();
    ::std::cout << ::std::endl;
    test_char_01();
    ::std::cout << ::std::endl;
    test_char_02();
    ::std::cout << ::std::endl;
    test_char_03();
    ::std::cout << ::std::endl;
    test_char_04();
    ::std::cout << ::std::endl;
    test_char_05();
    ::std::cout << ::std::endl;
    test_char_06();
    ::std::cout << ::std::endl;
    test_char_07();
    ::std::cout << ::std::endl;
    test_char_08();
    ::std::cout << ::std::endl;
    test_char_09();
    ::std::cout << ::std::endl;
    test_char_0A();
    ::std::cout << ::std::endl;
    test_char_0B();
    ::std::cout << ::std::endl;
    test_char_0C();
    ::std::cout << ::std::endl;
    test_char_10();
    ::std::cout << ::std::endl;
    test_char_11();
    ::std::cout << ::std::endl;
    test_char_12();
    ::std::cout << ::std::endl;
    test_char_13();
    ::std::cout << ::std::endl;
    test_char_14();
    ::std::cout << ::std::endl;
    test_char_15();
    ::std::cout << ::std::endl;
    test_char_16();
    ::std::cout << ::std::endl;
    test_char_17();
    ::std::cout << ::std::endl;
    test_char_18();
    ::std::cout << ::std::endl;
    test_char_19();
    ::std::cout << ::std::endl;
    test_char_1A();
    ::std::cout << ::std::endl;
    test_char_1B();
    ::std::cout << ::std::endl;
    test_char_1C();
    ::std::cout << ::std::endl;
    test_char_20();
    ::std::cout << ::std::endl;
    test_char_21();
    ::std::cout << ::std::endl;
    test_char_22();
    ::std::cout << ::std::endl;
    test_char_23();
    ::std::cout << ::std::endl;
    test_char_24();
    ::std::cout << ::std::endl;
    test_char_25();
    ::std::cout << ::std::endl;
    test_char_26();
    ::std::cout << ::std::endl;
    test_char_27();
    ::std::cout << ::std::endl;
    test_char_28();
    ::std::cout << ::std::endl;
    test_char_29();
    ::std::cout << ::std::endl;
    test_char_2A();
    ::std::cout << ::std::endl;
    test_char_2B();
    ::std::cout << ::std::endl;
    test_char_2C();
    ::std::cout << ::std::endl;
    test_int_00();
    ::std::cout << ::std::endl;
    test_int_01();
    ::std::cout << ::std::endl;
    test_int_10();
    ::std::cout << ::std::endl;
    test_int_11();
    ::std::cout << ::std::endl;
    test_post_fill_Z();
    ::std::cout << ::std::endl;
    test_post_fill_00();
    ::std::cout << ::std::endl;
    test_post_fill_01();
    ::std::cout << ::std::endl;
    test_post_fill_02();
    ::std::cout << ::std::endl;
    test_post_fill_03();
    ::std::cout << ::std::endl;
    test_post_fill_04();
    ::std::cout << ::std::endl;
    test_post_fill_05();
    ::std::cout << ::std::endl;
    test_post_fill_06();
    ::std::cout << ::std::endl;
    test_post_fill_07();
    ::std::cout << ::std::endl;
    test_post_fill_08();
    ::std::cout << ::std::endl;
    test_post_fill_09();
    ::std::cout << ::std::endl;
    test_post_fill_0A();
    ::std::cout << ::std::endl;
    test_post_fill_0B();
    ::std::cout << ::std::endl;
    test_post_fill_0C();
    ::std::cout << ::std::endl;
    test_post_fill_0D();
    ::std::cout << ::std::endl;
    test_post_fill_0E();
    ::std::cout << ::std::endl;
    test_post_fill_0F();
    ::std::cout << ::std::endl;
    test_post_fill_10();
    ::std::cout << ::std::endl;
    test_post_fill_11();
    ::std::cout << ::std::endl;
    test_post_fill_12();
    ::std::cout << ::std::endl;
    test_post_fill_13();
    ::std::cout << ::std::endl;
    test_post_fill_14();
    ::std::cout << ::std::endl;
    test_post_fill_15();
    ::std::cout << ::std::endl;
    test_post_fill_16();
    ::std::cout << ::std::endl;
    test_post_fill_17();
    ::std::cout << ::std::endl;
    test_post_fill_18();
    ::std::cout << ::std::endl;
    test_post_fill_19();
    ::std::cout << ::std::endl;
    test_post_fill_1A();
    ::std::cout << ::std::endl;
    test_post_fill_1B();
    ::std::cout << ::std::endl;
    test_post_fill_1C();
    ::std::cout << ::std::endl;
    test_post_fill_1D();
    ::std::cout << ::std::endl;
    test_post_fill_1E();
    ::std::cout << ::std::endl;
    test_post_fill_1F();
    ::std::cout << ::std::endl;
    return ::boost::report_errors();
}

