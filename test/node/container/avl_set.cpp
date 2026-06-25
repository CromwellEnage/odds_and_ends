// Copyright (C) 2026 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <utility>
#include <initializer_list>
#include <string>
#include <odds_and_ends/node/container/set.hpp>
#include <odds_and_ends/node/balancer/adelson_velskii_landis_tree.hpp>
#include <odds_and_ends/node/with_balance_factor.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_sorted_associative_container.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_simple_associative_container.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_pair_associative_container.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/core/lightweight_test.hpp>

void test_set_00()
{
    typedef ::odds_and_ends::node::container::set<
        int,
        ::boost::mpl::false_,
        ::boost::mpl::deque< ::odds_and_ends::node::with_balance_factor>,
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer
    > SSet;

    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container<SSet>::value,
        "::odds_and_ends::node::container::set is a Legacy Sorted Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container<SSet>::value,
        "::odds_and_ends::node::container::set is a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container<SSet>::value,
        "::odds_and_ends::node::container::set is not a Legacy Pair Associative Container."
    );

    SSet sset{1, 5, 3};
    SSet::const_iterator c_fwd_itr = sset.cbegin();

    BOOST_TEST(c_fwd_itr == sset.find(1));
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == sset.find(3));
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == sset.find(5));
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == sset.cend());

    SSet::const_reverse_iterator c_rev_itr = sset.crbegin();

    BOOST_TEST(5 == *c_rev_itr);
    ++c_rev_itr;
    BOOST_TEST(3 == *c_rev_itr);
    ++c_rev_itr;
    BOOST_TEST(1 == *c_rev_itr);
    ++c_rev_itr;
    BOOST_TEST(sset.crend() == c_rev_itr);

    ::std::pair<SSet::iterator,bool> ins_result = sset.insert(2);

    BOOST_TEST(ins_result.second);
    BOOST_TEST(sset.end() != ins_result.first);
    c_fwd_itr = sset.cbegin();
    BOOST_TEST(c_fwd_itr == sset.find(1));
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == sset.find(2));
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == sset.find(3));
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == sset.find(5));
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == sset.cend());
    c_rev_itr = sset.crbegin();
    BOOST_TEST(5 == *c_rev_itr);
    ++c_rev_itr;
    BOOST_TEST(3 == *c_rev_itr);
    ++c_rev_itr;
    BOOST_TEST(2 == *c_rev_itr);
    ++c_rev_itr;
    BOOST_TEST(1 == *c_rev_itr);
    ++c_rev_itr;
    BOOST_TEST(sset.crend() == c_rev_itr);

    ::std::size_t erase_result = sset.erase(1);

    BOOST_TEST(1 == erase_result);
    c_fwd_itr = sset.cbegin();
    BOOST_TEST(c_fwd_itr == sset.find(2));
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == sset.find(3));
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == sset.find(5));
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == sset.cend());
    c_rev_itr = sset.crbegin();
    BOOST_TEST(5 == *c_rev_itr);
    ++c_rev_itr;
    BOOST_TEST(3 == *c_rev_itr);
    ++c_rev_itr;
    BOOST_TEST(2 == *c_rev_itr);
    ++c_rev_itr;
    BOOST_TEST(sset.crend() == c_rev_itr);
}

#include <string_view>

void test_set_01()
{
    typedef ::odds_and_ends::node::container::set<
        char,
        ::boost::mpl::false_,
        ::boost::mpl::deque< ::odds_and_ends::node::with_balance_factor>,
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer
    > SSet;

    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container<SSet>::value,
        "::odds_and_ends::node::container::set is a Legacy Sorted Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container<SSet>::value,
        "::odds_and_ends::node::container::set is a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container<SSet>::value,
        "::odds_and_ends::node::container::set is not a Legacy Pair Associative Container."
    );

    ::std::string_view str_v = "element";
    SSet sset(str_v.begin(), str_v.end());

    BOOST_TEST(5 == sset.size());
    SSet::const_iterator c_itr = sset.cbegin();

    BOOST_TEST(c_itr == sset.find('e'));
    ++c_itr;
    BOOST_TEST(c_itr == sset.find('l'));
    ++c_itr;
    BOOST_TEST(c_itr == sset.find('m'));
    ++c_itr;
    BOOST_TEST(c_itr == sset.find('n'));
    ++c_itr;
    BOOST_TEST(c_itr == sset.find('t'));
    ++c_itr;
    BOOST_TEST(c_itr == sset.cend());

    SSet::const_reverse_iterator c_rev_itr = sset.crbegin();

    BOOST_TEST('t' == *c_rev_itr);
    ++c_rev_itr;
    BOOST_TEST('n' == *c_rev_itr);
    ++c_rev_itr;
    BOOST_TEST('m' == *c_rev_itr);
    ++c_rev_itr;
    BOOST_TEST('l' == *c_rev_itr);
    ++c_rev_itr;
    BOOST_TEST('e' == *c_rev_itr);
    ++c_rev_itr;
    BOOST_TEST(sset.crend() == c_rev_itr);
}

#include <functional>
#include <boost/mpl/quote.hpp>

void test_multiset_00()
{
    typedef ::odds_and_ends::node::container::set<
        short,
        ::boost::mpl::true_,
        ::boost::mpl::deque< ::odds_and_ends::node::with_balance_factor>,
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer,
        ::boost::mpl::quote1< ::std::greater>
    > MiniMSet;

    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container<MiniMSet>::value,
        "::odds_and_ends::node::container::set is a Legacy Sorted Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container<MiniMSet>::value,
        "::odds_and_ends::node::container::set is a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container<MiniMSet>::value,
        "::odds_and_ends::node::container::set is not a Legacy Pair Associative Container."
    );

    MiniMSet mset_a{1, 2, 3, 4};
    MiniMSet::const_iterator c_fwd_itr_0 = mset_a.cbegin();

    BOOST_TEST(c_fwd_itr_0 == mset_a.find(4));
    ++c_fwd_itr_0;
    BOOST_TEST(c_fwd_itr_0 == mset_a.find(3));
    ++c_fwd_itr_0;
    BOOST_TEST(c_fwd_itr_0 == mset_a.find(2));
    ++c_fwd_itr_0;
    BOOST_TEST(c_fwd_itr_0 == mset_a.find(1));
    ++c_fwd_itr_0;
    BOOST_TEST(c_fwd_itr_0 == mset_a.cend());

    MiniMSet::const_reverse_iterator c_rev_itr_0 = mset_a.crbegin();

    BOOST_TEST(1 == *c_rev_itr_0);
    ++c_rev_itr_0;
    BOOST_TEST(2 == *c_rev_itr_0);
    ++c_rev_itr_0;
    BOOST_TEST(3 == *c_rev_itr_0);
    ++c_rev_itr_0;
    BOOST_TEST(4 == *c_rev_itr_0);
    ++c_rev_itr_0;
    BOOST_TEST(c_rev_itr_0 == mset_a.crend());

    MiniMSet mset_b(mset_a.begin(), mset_a.find(2));

    c_fwd_itr_0 = mset_b.cbegin();
    BOOST_TEST(c_fwd_itr_0 == mset_b.find(4));
    ++c_fwd_itr_0;
    BOOST_TEST(c_fwd_itr_0 == mset_b.find(3));
    ++c_fwd_itr_0;
    BOOST_TEST(c_fwd_itr_0 == mset_b.cend());
    c_rev_itr_0 = mset_b.crbegin();
    BOOST_TEST(3 == *c_rev_itr_0);
    ++c_rev_itr_0;
    BOOST_TEST(4 == *c_rev_itr_0);
    ++c_rev_itr_0;
    BOOST_TEST(c_rev_itr_0 == mset_b.crend());

    MiniMSet mset_c(mset_a);

    c_fwd_itr_0 = mset_c.cbegin();
    BOOST_TEST(c_fwd_itr_0 == mset_c.find(4));
    ++c_fwd_itr_0;
    BOOST_TEST(c_fwd_itr_0 == mset_c.find(3));
    ++c_fwd_itr_0;
    BOOST_TEST(c_fwd_itr_0 == mset_c.find(2));
    ++c_fwd_itr_0;
    BOOST_TEST(c_fwd_itr_0 == mset_c.find(1));
    ++c_fwd_itr_0;
    BOOST_TEST(c_fwd_itr_0 == mset_c.cend());
    c_rev_itr_0 = mset_c.crbegin();
    BOOST_TEST(1 == *c_rev_itr_0);
    ++c_rev_itr_0;
    BOOST_TEST(2 == *c_rev_itr_0);
    ++c_rev_itr_0;
    BOOST_TEST(3 == *c_rev_itr_0);
    ++c_rev_itr_0;
    BOOST_TEST(4 == *c_rev_itr_0);
    ++c_rev_itr_0;
    BOOST_TEST(c_rev_itr_0 == mset_c.crend());

    MiniMSet mset_d(::std::move(mset_a));

    c_fwd_itr_0 = mset_d.cbegin();
    BOOST_TEST(c_fwd_itr_0 == mset_d.find(4));
    ++c_fwd_itr_0;
    BOOST_TEST(c_fwd_itr_0 == mset_d.find(3));
    ++c_fwd_itr_0;
    BOOST_TEST(c_fwd_itr_0 == mset_d.find(2));
    ++c_fwd_itr_0;
    BOOST_TEST(c_fwd_itr_0 == mset_d.find(1));
    ++c_fwd_itr_0;
    BOOST_TEST(c_fwd_itr_0 == mset_d.cend());
    c_rev_itr_0 = mset_d.crbegin();
    BOOST_TEST(1 == *c_rev_itr_0);
    ++c_rev_itr_0;
    BOOST_TEST(2 == *c_rev_itr_0);
    ++c_rev_itr_0;
    BOOST_TEST(3 == *c_rev_itr_0);
    ++c_rev_itr_0;
    BOOST_TEST(4 == *c_rev_itr_0);
    ++c_rev_itr_0;
    BOOST_TEST(c_rev_itr_0 == mset_d.crend());

    MiniMSet mset_e{3, 2, 1, 2, 4, 7, 3};
    ::std::pair<MiniMSet::const_iterator,MiniMSet::const_iterator> eq_res_0 = mset_e.equal_range(
        3
    );

    c_fwd_itr_0 = mset_e.cbegin();
    BOOST_TEST(c_fwd_itr_0 == mset_e.find(7));
    ++c_fwd_itr_0;
    BOOST_TEST(c_fwd_itr_0 == mset_e.find(4));
    ++c_fwd_itr_0;
    BOOST_TEST(c_fwd_itr_0 == eq_res_0.first);
    ++eq_res_0.first;
    ++c_fwd_itr_0;
    BOOST_TEST(c_fwd_itr_0 == eq_res_0.first);
    ++eq_res_0.first;
    BOOST_TEST(eq_res_0.first == eq_res_0.second);
    eq_res_0 = mset_e.equal_range(2);
    ++c_fwd_itr_0;
    BOOST_TEST(c_fwd_itr_0 == eq_res_0.first);
    ++eq_res_0.first;
    ++c_fwd_itr_0;
    BOOST_TEST(c_fwd_itr_0 == eq_res_0.first);
    ++eq_res_0.first;
    BOOST_TEST(eq_res_0.first == eq_res_0.second);
    ++c_fwd_itr_0;
    BOOST_TEST(c_fwd_itr_0 == mset_e.find(1));
    ++c_fwd_itr_0;
    BOOST_TEST(c_fwd_itr_0 == mset_e.cend());
    c_rev_itr_0 = mset_e.crbegin();
    BOOST_TEST(1 == *c_rev_itr_0);
    ++c_rev_itr_0;
    BOOST_TEST(2 == *c_rev_itr_0);
    ++c_rev_itr_0;
    BOOST_TEST(2 == *c_rev_itr_0);
    ++c_rev_itr_0;
    BOOST_TEST(3 == *c_rev_itr_0);
    ++c_rev_itr_0;
    BOOST_TEST(3 == *c_rev_itr_0);
    ++c_rev_itr_0;
    BOOST_TEST(4 == *c_rev_itr_0);
    ++c_rev_itr_0;
    BOOST_TEST(7 == *c_rev_itr_0);
    ++c_rev_itr_0;
    BOOST_TEST(c_rev_itr_0 == mset_e.crend());

    typedef ::odds_and_ends::node::container::set<
        long,
        ::boost::mpl::true_,
        ::boost::mpl::deque< ::odds_and_ends::node::with_balance_factor>,
        ::odds_and_ends::node::adelson_velskii_landis_tree_balancer
    > MegaMSet;

    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_sorted_associative_container<MegaMSet>::value,
        "::odds_and_ends::node::container::set is a Legacy Sorted Associative Container."
    );
    static_assert(
        ::odds_and_ends::static_introspection::concept
        ::is_legacy_simple_associative_container<MegaMSet>::value,
        "::odds_and_ends::node::container::set is a Legacy Simple Associative Container."
    );
    static_assert(
        !::odds_and_ends::static_introspection::concept
        ::is_legacy_pair_associative_container<MegaMSet>::value,
        "::odds_and_ends::node::container::set is not a Legacy Pair Associative Container."
    );

    MegaMSet mset_g(mset_e);
    ::std::pair<MegaMSet::const_iterator,MegaMSet::const_iterator> eq_res_1 = mset_g.equal_range(
        2
    );
    MegaMSet::const_iterator c_fwd_itr_1 = mset_g.cbegin();

    BOOST_TEST(c_fwd_itr_1 == mset_g.find(1));
    ++c_fwd_itr_1;
    BOOST_TEST(c_fwd_itr_1 == eq_res_1.first);
    ++eq_res_1.first;
    ++c_fwd_itr_1;
    BOOST_TEST(c_fwd_itr_1 == eq_res_1.first);
    ++eq_res_1.first;
    BOOST_TEST(eq_res_1.first == eq_res_1.second);
    eq_res_1 = mset_g.equal_range(3);
    ++c_fwd_itr_1;
    BOOST_TEST(c_fwd_itr_1 == eq_res_1.first);
    ++eq_res_1.first;
    ++c_fwd_itr_1;
    BOOST_TEST(c_fwd_itr_1 == eq_res_1.first);
    ++eq_res_1.first;
    BOOST_TEST(eq_res_1.first == eq_res_1.second);
    ++c_fwd_itr_1;
    BOOST_TEST(c_fwd_itr_1 == mset_g.find(4));
    ++c_fwd_itr_1;
    BOOST_TEST(c_fwd_itr_1 == mset_g.find(7));
    ++c_fwd_itr_1;
    BOOST_TEST(c_fwd_itr_1 == mset_g.cend());

    MegaMSet::const_reverse_iterator c_rev_itr_1 = mset_g.crbegin();

    BOOST_TEST(7 == *c_rev_itr_1);
    ++c_rev_itr_1;
    BOOST_TEST(4 == *c_rev_itr_1);
    ++c_rev_itr_1;
    BOOST_TEST(3 == *c_rev_itr_1);
    ++c_rev_itr_1;
    BOOST_TEST(3 == *c_rev_itr_1);
    ++c_rev_itr_1;
    BOOST_TEST(2 == *c_rev_itr_1);
    ++c_rev_itr_1;
    BOOST_TEST(2 == *c_rev_itr_1);
    ++c_rev_itr_1;
    BOOST_TEST(1 == *c_rev_itr_1);
    ++c_rev_itr_1;
    BOOST_TEST(c_rev_itr_1 == mset_g.crend());
}

int main(int argc, char** argv)
{
    test_set_00();
    test_set_01();
    test_multiset_00();
    return ::boost::report_errors();
}

