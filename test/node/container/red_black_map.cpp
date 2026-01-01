// Copyright (C) 2025 Cromwell D. Enage

#include <utility>
#include <functional>
#include <initializer_list>
#include <string>
#include <cstring>
#include <odds_and_ends/node/container/map.hpp>
#include <odds_and_ends/node/balancer/left_leaning_red_black_tree.hpp>
#include <odds_and_ends/node/red_black.hpp>
#include <odds_and_ends/node/algorithm/red_black_tree_test.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/core/lightweight_test.hpp>

void test_map_00()
{
    typedef ::odds_and_ends::node::container::map<
        ::std::string,
        double,
        ::boost::mpl::false_,
        ::boost::mpl::deque< ::odds_and_ends::node::red_black>,
        ::odds_and_ends::node::left_leaning_red_black_tree_balancer
    > SMap;

    SMap heights;
    ::std::pair<SMap::iterator,bool> ins_result = heights.emplace("Hinata", 162.8);

    BOOST_TEST(ins_result.second);
    BOOST_TEST(162.8 == heights.find("Hinata")->second);
    ins_result = heights.insert(*ins_result.first);
    BOOST_TEST(!ins_result.second);
    BOOST_TEST(162.8 == heights.find("Hinata")->second);
    ins_result = heights.insert(::std::make_pair("Kageyama", 180.6));
    BOOST_TEST(ins_result.second);
    BOOST_TEST(162.8 == heights.find("Hinata")->second);
    BOOST_TEST(180.6 == heights.find("Kageyama")->second);
}

#include <iostream>

void
    output_error(
        ::std::size_t const& index,
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

void output_depth(::std::size_t const& index, ::std::size_t const& depth)
{
    ::std::cout << "    Node at in-order position " << index;
    ::std::cout << " has red-black depth " << depth << '.' << ::std::endl;
}

#include <odds_and_ends/node/iterator/in_order_tree.hpp>

typedef ::odds_and_ends::node::container::map<
    int,
    ::std::string,
    ::boost::mpl::true_,
    ::boost::mpl::deque< ::odds_and_ends::node::red_black>,
    ::odds_and_ends::node::left_leaning_red_black_tree_balancer,
    ::std::greater<int>
> MMap;
typedef ::odds_and_ends::node::in_order_tree_iterator<MMap::node_type const> node_itr;

::std::ostream& operator<<(::std::ostream& os, MMap::node_type const& n)
{
    return os << "<" << (*n).first << ", " << (*n).second << ">";
}

void output_tree(node_itr itr)
{
    for (; !(!itr); ++itr)
    {
        ::std::cout << "    Node " << *itr << " is " << (itr->red() ? "red" : "black");

        if (itr->parent())
        {
            ::std::cout << ", has parent " << *itr->parent();
        }
        else
        {
            ::std::cout << ", has no parent";
        }

        if (itr->left())
        {
            ::std::cout << ", has left child " << *itr->left();
        }
        else
        {
            ::std::cout << ", has no left child";
        }

        if (itr->right())
        {
            ::std::cout << ", has right child " << *itr->right();
        }
        else
        {
            ::std::cout << ", has no right child";
        }

        ::std::cout << ", and has size " << itr->size() << '.' << ::std::endl;
    }
}

bool your_str_equal(char const* lhs, ::std::string const& rhs)
{
    return !::std::strcmp(lhs, rhs.c_str());
}

void test_multimap_00()
{
    MMap mmap = {{2, "foo"}, {2, "bar"}, {3, "baz"}, {1, "abc"}, {5, "def"}};

    ::std::cout << ::std::endl << "After construction:" << ::std::endl;
    output_tree(node_itr(*mmap.data(), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*mmap.data(), output_error, output_depth)
    );
    BOOST_TEST(your_str_equal("abc", mmap.find(1)->second));
    BOOST_TEST(your_str_equal("foo", mmap.lower_bound(2)->second));
    BOOST_TEST(your_str_equal("bar", (mmap.lower_bound(2) + 1)->second));
    BOOST_TEST(mmap.lower_bound(2) + 2 == mmap.upper_bound(2));
    BOOST_TEST(your_str_equal("baz", mmap.find(3)->second));
    BOOST_TEST(your_str_equal("def", mmap.find(5)->second));

    MMap::const_iterator c_fwd_itr = mmap.cbegin();

    BOOST_TEST(5 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("def", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(3 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("baz", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(2 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("foo", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(2 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("bar", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(1 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("abc", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == mmap.cend());

    MMap::const_reverse_iterator c_rev_itr = mmap.crbegin();

    BOOST_TEST(1 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("abc", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(2 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("bar", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(2 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("foo", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(3 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("baz", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(5 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("def", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == mmap.crend());

    MMap::iterator mod_res = mmap.insert(MMap::value_type(5, "pqr"));

    ::std::cout << ::std::endl << "After insert value_type:" << ::std::endl;
    output_tree(node_itr(*mmap.data(), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*mmap.data(), output_error, output_depth)
    );
    BOOST_TEST(5 == mod_res->first);
    BOOST_TEST(your_str_equal("pqr", mod_res->second));
    BOOST_TEST(your_str_equal("abc", mmap.find(1)->second));
    BOOST_TEST(your_str_equal("foo", mmap.lower_bound(2)->second));
    BOOST_TEST(your_str_equal("bar", (mmap.lower_bound(2) + 1)->second));
    BOOST_TEST(mmap.lower_bound(2) + 2 == mmap.upper_bound(2));
    BOOST_TEST(your_str_equal("baz", mmap.find(3)->second));
    BOOST_TEST(your_str_equal("def", mmap.lower_bound(5)->second));
    BOOST_TEST(your_str_equal("pqr", (mmap.lower_bound(5) + 1)->second));
    BOOST_TEST(mmap.lower_bound(5) + 2 == mmap.upper_bound(5));
    c_fwd_itr = mmap.cbegin();
    BOOST_TEST(5 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("def", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(5 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("pqr", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(3 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("baz", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(2 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("foo", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(2 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("bar", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(1 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("abc", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == mmap.cend());
    c_rev_itr = mmap.crbegin();
    BOOST_TEST(1 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("abc", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(2 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("bar", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(2 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("foo", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(3 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("baz", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(5 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("pqr", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(5 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("def", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == mmap.crend());
    mod_res = mmap.insert(::std::make_pair(6, "uvw"));
    ::std::cout << ::std::endl << "After insert make_pair:" << ::std::endl;
    output_tree(node_itr(*mmap.data(), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*mmap.data(), output_error, output_depth)
    );
    BOOST_TEST(6 == mod_res->first);
    BOOST_TEST(your_str_equal("uvw", mod_res->second));
    BOOST_TEST(your_str_equal("abc", mmap.find(1)->second));
    BOOST_TEST(your_str_equal("foo", mmap.lower_bound(2)->second));
    BOOST_TEST(your_str_equal("bar", (mmap.lower_bound(2) + 1)->second));
    BOOST_TEST(mmap.lower_bound(2) + 2 == mmap.upper_bound(2));
    BOOST_TEST(your_str_equal("baz", mmap.find(3)->second));
    BOOST_TEST(your_str_equal("def", mmap.lower_bound(5)->second));
    BOOST_TEST(your_str_equal("pqr", (mmap.lower_bound(5) + 1)->second));
    BOOST_TEST(mmap.lower_bound(5) + 2 == mmap.upper_bound(5));
    BOOST_TEST(your_str_equal("uvw", mmap.find(6)->second));
    c_fwd_itr = mmap.cbegin();
    BOOST_TEST(6 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("uvw", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(5 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("def", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(5 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("pqr", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(3 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("baz", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(2 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("foo", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(2 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("bar", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(1 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("abc", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == mmap.cend());
    c_rev_itr = mmap.crbegin();
    BOOST_TEST(1 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("abc", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(2 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("bar", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(2 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("foo", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(3 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("baz", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(5 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("pqr", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(5 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("def", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(6 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("uvw", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == mmap.crend());
    mod_res = mmap.emplace(7, "xyz");
    ::std::cout << ::std::endl << "After emplace:" << ::std::endl;
    output_tree(node_itr(*mmap.data(), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*mmap.data(), output_error, output_depth)
    );
    BOOST_TEST(7 == mod_res->first);
    BOOST_TEST(your_str_equal("xyz", mod_res->second));
    BOOST_TEST(your_str_equal("abc", mmap.find(1)->second));
    BOOST_TEST(your_str_equal("foo", mmap.lower_bound(2)->second));
    BOOST_TEST(your_str_equal("bar", (mmap.lower_bound(2) + 1)->second));
    BOOST_TEST(mmap.lower_bound(2) + 2 == mmap.upper_bound(2));
    BOOST_TEST(your_str_equal("baz", mmap.find(3)->second));
    BOOST_TEST(your_str_equal("def", mmap.lower_bound(5)->second));
    BOOST_TEST(your_str_equal("pqr", (mmap.lower_bound(5) + 1)->second));
    BOOST_TEST(mmap.lower_bound(5) + 2 == mmap.upper_bound(5));
    BOOST_TEST(your_str_equal("uvw", mmap.find(6)->second));
    BOOST_TEST(your_str_equal("xyz", mmap.find(7)->second));
    c_fwd_itr = mmap.cbegin();
    BOOST_TEST(7 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("xyz", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(6 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("uvw", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(5 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("def", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(5 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("pqr", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(3 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("baz", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(2 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("foo", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(2 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("bar", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(1 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("abc", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == mmap.cend());
    c_rev_itr = mmap.crbegin();
    BOOST_TEST(1 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("abc", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(2 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("bar", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(2 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("foo", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(3 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("baz", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(5 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("pqr", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(5 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("def", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(6 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("uvw", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(7 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("xyz", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == mmap.crend());
    mmap.insert({{5, "one"}, {5, "two"}});
    ::std::cout << ::std::endl << "After insert initializer_list:" << ::std::endl;
    output_tree(node_itr(*mmap.data(), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*mmap.data(), output_error, output_depth)
    );
    BOOST_TEST(your_str_equal("abc", mmap.find(1)->second));
    BOOST_TEST(your_str_equal("foo", mmap.lower_bound(2)->second));
    BOOST_TEST(your_str_equal("bar", (mmap.lower_bound(2) + 1)->second));
    BOOST_TEST(mmap.lower_bound(2) + 2 == mmap.upper_bound(2));
    BOOST_TEST(your_str_equal("baz", mmap.find(3)->second));
    BOOST_TEST(your_str_equal("def", mmap.lower_bound(5)->second));
    BOOST_TEST(your_str_equal("pqr", (mmap.lower_bound(5) + 1)->second));
    BOOST_TEST(your_str_equal("one", (mmap.lower_bound(5) + 2)->second));
    BOOST_TEST(your_str_equal("two", (mmap.lower_bound(5) + 3)->second));
    BOOST_TEST(mmap.lower_bound(5) + 4 == mmap.upper_bound(5));
    BOOST_TEST(your_str_equal("uvw", mmap.find(6)->second));
    BOOST_TEST(your_str_equal("xyz", mmap.find(7)->second));
    c_fwd_itr = mmap.cbegin();
    BOOST_TEST(7 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("xyz", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(6 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("uvw", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(5 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("def", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(5 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("pqr", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(5 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("one", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(5 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("two", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(3 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("baz", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(2 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("foo", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(2 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("bar", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(1 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("abc", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == mmap.cend());
    c_rev_itr = mmap.crbegin();
    BOOST_TEST(1 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("abc", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(2 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("bar", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(2 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("foo", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(3 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("baz", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(5 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("two", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(5 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("one", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(5 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("pqr", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(5 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("def", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(6 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("uvw", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(7 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("xyz", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == mmap.crend());
    mod_res = mmap.erase(mmap.find(3));
    ::std::cout << ::std::endl << "After erase find:" << ::std::endl;
    output_tree(node_itr(*mmap.data(), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*mmap.data(), output_error, output_depth)
    );
    BOOST_TEST(mod_res == mmap.upper_bound(3));
    BOOST_TEST(your_str_equal("abc", mmap.find(1)->second));
    BOOST_TEST(your_str_equal("foo", mmap.lower_bound(2)->second));
    BOOST_TEST(your_str_equal("bar", (mmap.lower_bound(2) + 1)->second));
    BOOST_TEST(mmap.lower_bound(2) + 2 == mmap.upper_bound(2));
    BOOST_TEST(mmap.find(3) == mmap.end());
    BOOST_TEST(your_str_equal("def", mmap.lower_bound(5)->second));
    BOOST_TEST(your_str_equal("pqr", (mmap.lower_bound(5) + 1)->second));
    BOOST_TEST(your_str_equal("one", (mmap.lower_bound(5) + 2)->second));
    BOOST_TEST(your_str_equal("two", (mmap.lower_bound(5) + 3)->second));
    BOOST_TEST(mmap.lower_bound(5) + 4 == mmap.upper_bound(5));
    BOOST_TEST(your_str_equal("uvw", mmap.find(6)->second));
    BOOST_TEST(your_str_equal("xyz", mmap.find(7)->second));
    c_fwd_itr = mmap.cbegin();
    BOOST_TEST(7 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("xyz", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(6 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("uvw", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(5 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("def", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(5 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("pqr", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(5 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("one", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(5 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("two", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(2 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("foo", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(2 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("bar", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(1 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("abc", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == mmap.cend());
    c_rev_itr = mmap.crbegin();
    BOOST_TEST(1 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("abc", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(2 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("bar", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(2 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("foo", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(5 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("two", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(5 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("one", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(5 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("pqr", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(5 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("def", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(6 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("uvw", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(7 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("xyz", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == mmap.crend());

    MMap::size_type count = mmap.erase(5);

    ::std::cout << ::std::endl << "After erase key:" << ::std::endl;
    output_tree(node_itr(*mmap.data(), false));
    BOOST_TEST(
        ::odds_and_ends::node::algorithm
        ::red_black_tree_test(*mmap.data(), output_error, output_depth)
    );
    BOOST_TEST(4 == count);
    BOOST_TEST(your_str_equal("abc", mmap.find(1)->second));
    BOOST_TEST(your_str_equal("foo", mmap.lower_bound(2)->second));
    BOOST_TEST(your_str_equal("bar", (mmap.lower_bound(2) + 1)->second));
    BOOST_TEST(mmap.lower_bound(2) + 2 == mmap.upper_bound(2));
    BOOST_TEST(mmap.find(3) == mmap.end());
    BOOST_TEST(mmap.lower_bound(5) == mmap.upper_bound(5));
    BOOST_TEST(your_str_equal("uvw", mmap.find(6)->second));
    BOOST_TEST(your_str_equal("xyz", mmap.find(7)->second));
    c_fwd_itr = mmap.cbegin();
    BOOST_TEST(7 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("xyz", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(6 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("uvw", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(2 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("foo", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(2 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("bar", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(1 == c_fwd_itr->first);
    BOOST_TEST(your_str_equal("abc", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == mmap.cend());
    c_rev_itr = mmap.crbegin();
    BOOST_TEST(1 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("abc", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(2 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("bar", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(2 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("foo", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(6 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("uvw", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(7 == c_rev_itr->first);
    BOOST_TEST(your_str_equal("xyz", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == mmap.crend());
}

int main(int argc, char** argv)
{
    test_map_00();
    test_multimap_00();
    return ::boost::report_errors();
}

