// Copyright (C) 2025-2026 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <utility>
#include <string>
#include <odds_and_ends/node/container/map.hpp>
#include <odds_and_ends/node/balancer/adelson_velskii_landis_tree.hpp>
#include <odds_and_ends/node/with_balance_factor.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_sorted_associative_container.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_simple_associative_container.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_pair_associative_container.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/core/lightweight_test.hpp>

void test_map_00()
{
    typedef ::odds_and_ends::node::container::map<
        ::std::string,
        double,
        ::boost::mpl::false_,
        ::boost::mpl::deque< ::odds_and_ends::node::with_balance_factor>,
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer
    > SMap;

    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container<SMap>::value,
        "::odds_and_ends::node::container::map is a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container<SMap>::value,
        "::odds_and_ends::node::container::map is not a Legacy Simple Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container<SMap>::value,
        "::odds_and_ends::node::container::map is a Legacy Pair Associative Container."
    );

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

#include <cstring>

bool your_str_equal(char const* lhs, ::std::string const& rhs)
{
    return !::std::strcmp(lhs, rhs.c_str());
}

#include <functional>
#include <boost/mpl/quote.hpp>

void test_multimap_00()
{
    typedef ::odds_and_ends::node::container::map<
        short,
        ::std::string,
        ::boost::mpl::true_,
        ::boost::mpl::deque< ::odds_and_ends::node::with_balance_factor>,
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer,
        ::boost::mpl::quote1< ::std::greater>
    > MiniMMap;

    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container<MiniMMap>::value,
        "::odds_and_ends::node::container::map is a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container<MiniMMap>::value,
        "::odds_and_ends::node::container::map is not a Legacy Simple Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container<MiniMMap>::value,
        "::odds_and_ends::node::container::map is a Legacy Pair Associative Container."
    );

    MiniMMap mini_mmap = {{2, "foo"}, {2, "bar"}, {3, "baz"}, {1, "abc"}, {5, "def"}};

    BOOST_TEST(your_str_equal("abc", mini_mmap.find(1)->second));
    BOOST_TEST(your_str_equal("foo", mini_mmap.lower_bound(2)->second));
    BOOST_TEST(your_str_equal("bar", (mini_mmap.lower_bound(2) + 1)->second));
    BOOST_TEST(mini_mmap.lower_bound(2) + 2 == mini_mmap.upper_bound(2));
    BOOST_TEST(your_str_equal("baz", mini_mmap.find(3)->second));
    BOOST_TEST(your_str_equal("def", mini_mmap.find(5)->second));

    MiniMMap::const_iterator c_fwd_itr_0 = mini_mmap.cbegin();

    BOOST_TEST(5 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("def", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(3 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("baz", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(2 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("foo", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(2 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("bar", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(1 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("abc", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(c_fwd_itr_0 == mini_mmap.cend());

    MiniMMap::const_reverse_iterator c_rev_itr_0 = mini_mmap.crbegin();

    BOOST_TEST(1 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("abc", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(2 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("bar", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(2 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("foo", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(3 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("baz", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(5 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("def", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(c_rev_itr_0 == mini_mmap.crend());

    MiniMMap::iterator mod_res = mini_mmap.insert(MiniMMap::value_type(5, "pqr"));

    BOOST_TEST(5 == mod_res->first);
    BOOST_TEST(your_str_equal("pqr", mod_res->second));
    BOOST_TEST(your_str_equal("abc", mini_mmap.find(1)->second));
    BOOST_TEST(your_str_equal("foo", mini_mmap.lower_bound(2)->second));
    BOOST_TEST(your_str_equal("bar", (mini_mmap.lower_bound(2) + 1)->second));
    BOOST_TEST(mini_mmap.lower_bound(2) + 2 == mini_mmap.upper_bound(2));
    BOOST_TEST(your_str_equal("baz", mini_mmap.find(3)->second));
    BOOST_TEST(your_str_equal("def", mini_mmap.lower_bound(5)->second));
    BOOST_TEST(your_str_equal("pqr", (mini_mmap.lower_bound(5) + 1)->second));
    BOOST_TEST(mini_mmap.lower_bound(5) + 2 == mini_mmap.upper_bound(5));
    c_fwd_itr_0 = mini_mmap.cbegin();
    BOOST_TEST(5 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("def", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(5 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("pqr", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(3 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("baz", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(2 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("foo", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(2 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("bar", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(1 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("abc", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(c_fwd_itr_0 == mini_mmap.cend());
    c_rev_itr_0 = mini_mmap.crbegin();
    BOOST_TEST(1 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("abc", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(2 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("bar", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(2 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("foo", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(3 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("baz", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(5 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("pqr", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(5 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("def", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(c_rev_itr_0 == mini_mmap.crend());
    mod_res = mini_mmap.insert(::std::make_pair(6, "uvw"));
    BOOST_TEST(6 == mod_res->first);
    BOOST_TEST(your_str_equal("uvw", mod_res->second));
    BOOST_TEST(your_str_equal("abc", mini_mmap.find(1)->second));
    BOOST_TEST(your_str_equal("foo", mini_mmap.lower_bound(2)->second));
    BOOST_TEST(your_str_equal("bar", (mini_mmap.lower_bound(2) + 1)->second));
    BOOST_TEST(mini_mmap.lower_bound(2) + 2 == mini_mmap.upper_bound(2));
    BOOST_TEST(your_str_equal("baz", mini_mmap.find(3)->second));
    BOOST_TEST(your_str_equal("def", mini_mmap.lower_bound(5)->second));
    BOOST_TEST(your_str_equal("pqr", (mini_mmap.lower_bound(5) + 1)->second));
    BOOST_TEST(mini_mmap.lower_bound(5) + 2 == mini_mmap.upper_bound(5));
    BOOST_TEST(your_str_equal("uvw", mini_mmap.find(6)->second));
    c_fwd_itr_0 = mini_mmap.cbegin();
    BOOST_TEST(6 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("uvw", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(5 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("def", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(5 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("pqr", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(3 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("baz", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(2 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("foo", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(2 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("bar", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(1 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("abc", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(c_fwd_itr_0 == mini_mmap.cend());
    c_rev_itr_0 = mini_mmap.crbegin();
    BOOST_TEST(1 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("abc", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(2 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("bar", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(2 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("foo", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(3 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("baz", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(5 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("pqr", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(5 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("def", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(6 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("uvw", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(c_rev_itr_0 == mini_mmap.crend());
    mod_res = mini_mmap.emplace(7, "xyz");
    BOOST_TEST(7 == mod_res->first);
    BOOST_TEST(your_str_equal("xyz", mod_res->second));
    BOOST_TEST(your_str_equal("abc", mini_mmap.find(1)->second));
    BOOST_TEST(your_str_equal("foo", mini_mmap.lower_bound(2)->second));
    BOOST_TEST(your_str_equal("bar", (mini_mmap.lower_bound(2) + 1)->second));
    BOOST_TEST(mini_mmap.lower_bound(2) + 2 == mini_mmap.upper_bound(2));
    BOOST_TEST(your_str_equal("baz", mini_mmap.find(3)->second));
    BOOST_TEST(your_str_equal("def", mini_mmap.lower_bound(5)->second));
    BOOST_TEST(your_str_equal("pqr", (mini_mmap.lower_bound(5) + 1)->second));
    BOOST_TEST(mini_mmap.lower_bound(5) + 2 == mini_mmap.upper_bound(5));
    BOOST_TEST(your_str_equal("uvw", mini_mmap.find(6)->second));
    BOOST_TEST(your_str_equal("xyz", mini_mmap.find(7)->second));
    c_fwd_itr_0 = mini_mmap.cbegin();
    BOOST_TEST(7 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("xyz", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(6 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("uvw", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(5 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("def", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(5 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("pqr", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(3 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("baz", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(2 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("foo", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(2 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("bar", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(1 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("abc", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(c_fwd_itr_0 == mini_mmap.cend());
    c_rev_itr_0 = mini_mmap.crbegin();
    BOOST_TEST(1 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("abc", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(2 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("bar", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(2 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("foo", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(3 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("baz", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(5 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("pqr", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(5 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("def", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(6 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("uvw", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(7 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("xyz", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(c_rev_itr_0 == mini_mmap.crend());
    mini_mmap.insert({{5, "one"}, {5, "two"}});
    BOOST_TEST(your_str_equal("abc", mini_mmap.find(1)->second));
    BOOST_TEST(your_str_equal("foo", mini_mmap.lower_bound(2)->second));
    BOOST_TEST(your_str_equal("bar", (mini_mmap.lower_bound(2) + 1)->second));
    BOOST_TEST(mini_mmap.lower_bound(2) + 2 == mini_mmap.upper_bound(2));
    BOOST_TEST(your_str_equal("baz", mini_mmap.find(3)->second));
    BOOST_TEST(your_str_equal("def", mini_mmap.lower_bound(5)->second));
    BOOST_TEST(your_str_equal("pqr", (mini_mmap.lower_bound(5) + 1)->second));
    BOOST_TEST(your_str_equal("one", (mini_mmap.lower_bound(5) + 2)->second));
    BOOST_TEST(your_str_equal("two", (mini_mmap.lower_bound(5) + 3)->second));
    BOOST_TEST(mini_mmap.lower_bound(5) + 4 == mini_mmap.upper_bound(5));
    BOOST_TEST(your_str_equal("uvw", mini_mmap.find(6)->second));
    BOOST_TEST(your_str_equal("xyz", mini_mmap.find(7)->second));
    c_fwd_itr_0 = mini_mmap.cbegin();
    BOOST_TEST(7 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("xyz", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(6 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("uvw", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(5 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("def", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(5 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("pqr", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(5 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("one", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(5 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("two", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(3 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("baz", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(2 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("foo", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(2 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("bar", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(1 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("abc", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(c_fwd_itr_0 == mini_mmap.cend());
    c_rev_itr_0 = mini_mmap.crbegin();
    BOOST_TEST(1 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("abc", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(2 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("bar", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(2 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("foo", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(3 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("baz", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(5 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("two", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(5 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("one", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(5 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("pqr", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(5 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("def", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(6 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("uvw", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(7 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("xyz", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(c_rev_itr_0 == mini_mmap.crend());
    mod_res = mini_mmap.erase(mini_mmap.find(3));
    BOOST_TEST(mod_res == mini_mmap.upper_bound(3));
    BOOST_TEST(your_str_equal("abc", mini_mmap.find(1)->second));
    BOOST_TEST(your_str_equal("foo", mini_mmap.lower_bound(2)->second));
    BOOST_TEST(your_str_equal("bar", (mini_mmap.lower_bound(2) + 1)->second));
    BOOST_TEST(mini_mmap.lower_bound(2) + 2 == mini_mmap.upper_bound(2));
    BOOST_TEST(mini_mmap.find(3) == mini_mmap.end());
    BOOST_TEST(your_str_equal("def", mini_mmap.lower_bound(5)->second));
    BOOST_TEST(your_str_equal("pqr", (mini_mmap.lower_bound(5) + 1)->second));
    BOOST_TEST(your_str_equal("one", (mini_mmap.lower_bound(5) + 2)->second));
    BOOST_TEST(your_str_equal("two", (mini_mmap.lower_bound(5) + 3)->second));
    BOOST_TEST(mini_mmap.lower_bound(5) + 4 == mini_mmap.upper_bound(5));
    BOOST_TEST(your_str_equal("uvw", mini_mmap.find(6)->second));
    BOOST_TEST(your_str_equal("xyz", mini_mmap.find(7)->second));
    c_fwd_itr_0 = mini_mmap.cbegin();
    BOOST_TEST(7 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("xyz", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(6 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("uvw", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(5 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("def", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(5 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("pqr", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(5 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("one", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(5 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("two", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(2 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("foo", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(2 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("bar", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(1 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("abc", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(c_fwd_itr_0 == mini_mmap.cend());
    c_rev_itr_0 = mini_mmap.crbegin();
    BOOST_TEST(1 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("abc", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(2 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("bar", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(2 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("foo", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(5 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("two", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(5 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("one", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(5 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("pqr", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(5 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("def", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(6 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("uvw", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(7 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("xyz", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(c_rev_itr_0 == mini_mmap.crend());

    MiniMMap::size_type count = mini_mmap.erase(5);

    BOOST_TEST(4 == count);
    BOOST_TEST(your_str_equal("abc", mini_mmap.find(1)->second));
    BOOST_TEST(your_str_equal("foo", mini_mmap.lower_bound(2)->second));
    BOOST_TEST(your_str_equal("bar", (mini_mmap.lower_bound(2) + 1)->second));
    BOOST_TEST(mini_mmap.lower_bound(2) + 2 == mini_mmap.upper_bound(2));
    BOOST_TEST(mini_mmap.find(3) == mini_mmap.end());
    BOOST_TEST(mini_mmap.lower_bound(5) == mini_mmap.upper_bound(5));
    BOOST_TEST(your_str_equal("uvw", mini_mmap.find(6)->second));
    BOOST_TEST(your_str_equal("xyz", mini_mmap.find(7)->second));
    c_fwd_itr_0 = mini_mmap.cbegin();
    BOOST_TEST(7 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("xyz", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(6 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("uvw", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(2 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("foo", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(2 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("bar", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(1 == c_fwd_itr_0->first);
    BOOST_TEST(your_str_equal("abc", c_fwd_itr_0->second));
    ++c_fwd_itr_0;
    BOOST_TEST(c_fwd_itr_0 == mini_mmap.cend());
    c_rev_itr_0 = mini_mmap.crbegin();
    BOOST_TEST(1 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("abc", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(2 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("bar", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(2 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("foo", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(6 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("uvw", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(7 == c_rev_itr_0->first);
    BOOST_TEST(your_str_equal("xyz", c_rev_itr_0->second));
    ++c_rev_itr_0;
    BOOST_TEST(c_rev_itr_0 == mini_mmap.crend());

    typedef ::odds_and_ends::node::container::map<
        long,
        ::std::string,
        ::boost::mpl::true_,
        ::boost::mpl::deque< ::odds_and_ends::node::with_balance_factor>,
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer
    > MegaMMap;

    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container<MegaMMap>::value,
        "::odds_and_ends::node::container::map is a Legacy Sorted Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container<MegaMMap>::value,
        "::odds_and_ends::node::container::map is not a Legacy Simple Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container<MegaMMap>::value,
        "::odds_and_ends::node::container::map is a Legacy Pair Associative Container."
    );

    MegaMMap mega_mmap(mini_mmap);
    MegaMMap::const_iterator c_fwd_itr_1 = mega_mmap.cbegin();

    BOOST_TEST(1 == c_fwd_itr_1->first);
    BOOST_TEST(your_str_equal("abc", c_fwd_itr_1->second));
    ++c_fwd_itr_1;
    BOOST_TEST(2 == c_fwd_itr_1->first);
    BOOST_TEST(your_str_equal("foo", c_fwd_itr_1->second));
    ++c_fwd_itr_1;
    BOOST_TEST(2 == c_fwd_itr_1->first);
    BOOST_TEST(your_str_equal("bar", c_fwd_itr_1->second));
    ++c_fwd_itr_1;
    BOOST_TEST(6 == c_fwd_itr_1->first);
    BOOST_TEST(your_str_equal("uvw", c_fwd_itr_1->second));
    ++c_fwd_itr_1;
    BOOST_TEST(7 == c_fwd_itr_1->first);
    BOOST_TEST(your_str_equal("xyz", c_fwd_itr_1->second));
    ++c_fwd_itr_1;
    BOOST_TEST(c_fwd_itr_1 == mega_mmap.cend());

    MegaMMap::const_reverse_iterator c_rev_itr_1 = mega_mmap.crbegin();

    BOOST_TEST(7 == c_rev_itr_1->first);
    BOOST_TEST(your_str_equal("xyz", c_rev_itr_1->second));
    ++c_rev_itr_1;
    BOOST_TEST(6 == c_rev_itr_1->first);
    BOOST_TEST(your_str_equal("uvw", c_rev_itr_1->second));
    ++c_rev_itr_1;
    BOOST_TEST(2 == c_rev_itr_1->first);
    BOOST_TEST(your_str_equal("bar", c_rev_itr_1->second));
    ++c_rev_itr_1;
    BOOST_TEST(2 == c_rev_itr_1->first);
    BOOST_TEST(your_str_equal("foo", c_rev_itr_1->second));
    ++c_rev_itr_1;
    BOOST_TEST(1 == c_rev_itr_1->first);
    BOOST_TEST(your_str_equal("abc", c_rev_itr_1->second));
    ++c_rev_itr_1;
    BOOST_TEST(c_rev_itr_1 == mega_mmap.crend());
}

int main(int argc, char** argv)
{
    test_map_00();
    test_multimap_00();
    return ::boost::report_errors();
}

