// Copyright (C) 2026 Cromwell D. Enage

#include <odds_and_ends/node/data.hpp>
#include <odds_and_ends/node/tree/base.hpp>
#include <odds_and_ends/node/tree/associative.hpp>
#include <odds_and_ends/node/tree/with_size.hpp>
#include <odds_and_ends/composite_type/composite_type.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/mpl/quote.hpp>
#include <boost/core/lightweight_test.hpp>

void test_00()
{
    typedef ::odds_and_ends::composite_type::composite_type<
        ::boost::mpl::deque<
            ::odds_and_ends::node::data<int const>,
            ::odds_and_ends::node::tree::base<>,
            ::odds_and_ends::node::tree::associative<char>,
            ::odds_and_ends::node::tree::with_size<>
        >
    > associative_tree_node;

    associative_tree_node atn_n03(-3);
    associative_tree_node atn_n02(-2);
    associative_tree_node atn_n01(-1);
    associative_tree_node atn_o00(0);
    associative_tree_node atn_p01(1);
    associative_tree_node atn_p02(2);
    associative_tree_node atn_p03(3);
    associative_tree_node atn_p04(4);
    associative_tree_node atn_p05(5);
    associative_tree_node atn_p06(6);
    associative_tree_node atn_p07(7);
    associative_tree_node atn_p08(8);
    associative_tree_node atn_p09(9);
    associative_tree_node atn_p10(10);
    associative_tree_node atn_p11(11);
    associative_tree_node atn_p12(12);
    associative_tree_node atn_p13(13);

    BOOST_TEST(-3 == *atn_n03);
    BOOST_TEST(!atn_n03.parent());
    BOOST_TEST(atn_n03.cbegin() == atn_n03.cend());
    BOOST_TEST(1 == atn_n03.size());
    BOOST_TEST(-2 == *atn_n02);
    BOOST_TEST(!atn_n02.parent());
    BOOST_TEST(atn_n02.cbegin() == atn_n02.cend());
    BOOST_TEST(1 == atn_n02.size());
    BOOST_TEST(-1 == *atn_n01);
    BOOST_TEST(!atn_n01.parent());
    BOOST_TEST(atn_n01.cbegin() == atn_n01.cend());
    BOOST_TEST(1 == atn_n01.size());
    BOOST_TEST(0 == *atn_o00);
    BOOST_TEST(!atn_o00.parent());
    BOOST_TEST(atn_o00.cbegin() == atn_o00.cend());
    BOOST_TEST(1 == atn_o00.size());
    BOOST_TEST(1 == *atn_p01);
    BOOST_TEST(!atn_p01.parent());
    BOOST_TEST(atn_p01.cbegin() == atn_p01.cend());
    BOOST_TEST(1 == atn_p01.size());
    BOOST_TEST(2 == *atn_p02);
    BOOST_TEST(!atn_p02.parent());
    BOOST_TEST(atn_p02.cbegin() == atn_p02.cend());
    BOOST_TEST(1 == atn_p02.size());
    BOOST_TEST(3 == *atn_p03);
    BOOST_TEST(!atn_p03.parent());
    BOOST_TEST(atn_p03.cbegin() == atn_p03.cend());
    BOOST_TEST(1 == atn_p03.size());
    BOOST_TEST(4 == *atn_p04);
    BOOST_TEST(!atn_p04.parent());
    BOOST_TEST(atn_p04.cbegin() == atn_p04.cend());
    BOOST_TEST(1 == atn_p04.size());
    BOOST_TEST(5 == *atn_p05);
    BOOST_TEST(!atn_p05.parent());
    BOOST_TEST(atn_p05.cbegin() == atn_p05.cend());
    BOOST_TEST(1 == atn_p05.size());
    BOOST_TEST(6 == *atn_p06);
    BOOST_TEST(!atn_p06.parent());
    BOOST_TEST(atn_p06.cbegin() == atn_p06.cend());
    BOOST_TEST(1 == atn_p06.size());
    BOOST_TEST(7 == *atn_p07);
    BOOST_TEST(!atn_p07.parent());
    BOOST_TEST(atn_p07.cbegin() == atn_p07.cend());
    BOOST_TEST(1 == atn_p07.size());
    BOOST_TEST(8 == *atn_p08);
    BOOST_TEST(!atn_p08.parent());
    BOOST_TEST(atn_p08.cbegin() == atn_p08.cend());
    BOOST_TEST(1 == atn_p08.size());
    BOOST_TEST(9 == *atn_p09);
    BOOST_TEST(!atn_p09.parent());
    BOOST_TEST(atn_p09.cbegin() == atn_p09.cend());
    BOOST_TEST(1 == atn_p09.size());
    BOOST_TEST(10 == *atn_p10);
    BOOST_TEST(!atn_p10.parent());
    BOOST_TEST(atn_p10.cbegin() == atn_p10.cend());
    BOOST_TEST(1 == atn_p10.size());
    BOOST_TEST(11 == *atn_p11);
    BOOST_TEST(!atn_p11.parent());
    BOOST_TEST(atn_p11.cbegin() == atn_p11.cend());
    BOOST_TEST(1 == atn_p11.size());
    BOOST_TEST(12 == *atn_p12);
    BOOST_TEST(!atn_p12.parent());
    BOOST_TEST(atn_p12.cbegin() == atn_p12.cend());
    BOOST_TEST(1 == atn_p12.size());
    BOOST_TEST(13 == *atn_p13);
    BOOST_TEST(!atn_p13.parent());
    BOOST_TEST(atn_p13.cbegin() == atn_p13.cend());
    BOOST_TEST(1 == atn_p13.size());
    atn_o00.set('i', atn_n03);
    BOOST_TEST('i' == atn_o00.get('i')->key());
    BOOST_TEST(-3 == **atn_o00.get('i'));
    BOOST_TEST(0 == **atn_o00.get('i')->parent());
    BOOST_TEST(0 == **atn_n03.parent());

    associative_tree_node::traits::child_const_iterator c_fwd_itr = atn_o00.cbegin();

    BOOST_TEST('i' == c_fwd_itr->first);
    BOOST_TEST('i' == c_fwd_itr->second->key());
    BOOST_TEST(-3 == **c_fwd_itr->second);
    BOOST_TEST(0 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == atn_o00.cend());

    associative_tree_node::traits::child_const_reverse_iterator c_rev_itr = atn_o00.crbegin();

    BOOST_TEST('i' == c_rev_itr->first);
    BOOST_TEST('i' == c_rev_itr->second->key());
    BOOST_TEST(-3 == **c_rev_itr->second);
    BOOST_TEST(0 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == atn_o00.crend());
    BOOST_TEST(2 == atn_o00.size());
    atn_n03.set('n', atn_p07);
    BOOST_TEST('n' == atn_n03.get('n')->key());
    BOOST_TEST(7 == **atn_n03.get('n'));
    BOOST_TEST(-3 == **atn_n03.get('n')->parent());
    BOOST_TEST(-3 == **atn_p07.parent());
    c_fwd_itr = atn_n03.cbegin();
    BOOST_TEST('n' == c_fwd_itr->first);
    BOOST_TEST('n' == c_fwd_itr->second->key());
    BOOST_TEST(7 == **c_fwd_itr->second);
    BOOST_TEST(-3 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == atn_n03.cend());
    c_rev_itr = atn_n03.crbegin();
    BOOST_TEST('n' == c_rev_itr->first);
    BOOST_TEST('n' == c_rev_itr->second->key());
    BOOST_TEST(7 == **c_rev_itr->second);
    BOOST_TEST(-3 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == atn_n03.crend());
    BOOST_TEST(3 == atn_o00.size());
    BOOST_TEST(2 == atn_n03.size());
    atn_p07.set('k', atn_p09);
    BOOST_TEST('k' == atn_p07.get('k')->key());
    BOOST_TEST(9 == **atn_p07.get('k'));
    BOOST_TEST(7 == **atn_p07.get('k')->parent());
    BOOST_TEST(7 == **atn_p09.parent());
    c_fwd_itr = atn_p07.cbegin();
    BOOST_TEST('k' == c_fwd_itr->first);
    BOOST_TEST('k' == c_fwd_itr->second->key());
    BOOST_TEST(9 == **c_fwd_itr->second);
    BOOST_TEST(7 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == atn_p07.cend());
    c_rev_itr = atn_p07.crbegin();
    BOOST_TEST('k' == c_rev_itr->first);
    BOOST_TEST('k' == c_rev_itr->second->key());
    BOOST_TEST(9 == **c_rev_itr->second);
    BOOST_TEST(7 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == atn_p07.crend());
    BOOST_TEST(4 == atn_o00.size());
    BOOST_TEST(3 == atn_n03.size());
    BOOST_TEST(2 == atn_p07.size());
    atn_p07.set('n', atn_p10);
    BOOST_TEST('n' == atn_p07.get('n')->key());
    BOOST_TEST(10 == **atn_p07.get('n'));
    BOOST_TEST(7 == **atn_p07.get('n')->parent());
    BOOST_TEST(7 == **atn_p10.parent());
    c_fwd_itr = atn_p07.cbegin();
    BOOST_TEST('k' == c_fwd_itr->first);
    BOOST_TEST('k' == c_fwd_itr->second->key());
    BOOST_TEST(9 == **c_fwd_itr->second);
    BOOST_TEST(7 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST('n' == c_fwd_itr->first);
    BOOST_TEST('n' == c_fwd_itr->second->key());
    BOOST_TEST(10 == **c_fwd_itr->second);
    BOOST_TEST(7 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == atn_p07.cend());
    c_rev_itr = atn_p07.crbegin();
    BOOST_TEST('n' == c_rev_itr->first);
    BOOST_TEST('n' == c_rev_itr->second->key());
    BOOST_TEST(10 == **c_rev_itr->second);
    BOOST_TEST(7 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST('k' == c_rev_itr->first);
    BOOST_TEST('k' == c_rev_itr->second->key());
    BOOST_TEST(9 == **c_rev_itr->second);
    BOOST_TEST(7 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == atn_p07.crend());
    BOOST_TEST(5 == atn_o00.size());
    BOOST_TEST(4 == atn_n03.size());
    BOOST_TEST(3 == atn_p07.size());
    atn_n03.set('s', atn_p11);
    BOOST_TEST('s' == atn_n03.get('s')->key());
    BOOST_TEST(11 == **atn_n03.get('s'));
    BOOST_TEST(-3 == **atn_n03.get('s')->parent());
    BOOST_TEST(-3 == **atn_p11.parent());
    c_fwd_itr = atn_n03.cbegin();
    BOOST_TEST('n' == c_fwd_itr->first);
    BOOST_TEST('n' == c_fwd_itr->second->key());
    BOOST_TEST(7 == **c_fwd_itr->second);
    BOOST_TEST(-3 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST('s' == c_fwd_itr->first);
    BOOST_TEST('s' == c_fwd_itr->second->key());
    BOOST_TEST(11 == **c_fwd_itr->second);
    BOOST_TEST(-3 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == atn_n03.cend());
    c_rev_itr = atn_n03.crbegin();
    BOOST_TEST('s' == c_rev_itr->first);
    BOOST_TEST('s' == c_rev_itr->second->key());
    BOOST_TEST(11 == **c_rev_itr->second);
    BOOST_TEST(-3 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST('n' == c_rev_itr->first);
    BOOST_TEST('n' == c_rev_itr->second->key());
    BOOST_TEST(7 == **c_rev_itr->second);
    BOOST_TEST(-3 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == atn_n03.crend());
    BOOST_TEST(6 == atn_o00.size());
    BOOST_TEST(5 == atn_n03.size());
    atn_n03.set('t', atn_p12);
    BOOST_TEST('t' == atn_n03.get('t')->key());
    BOOST_TEST(12 == **atn_n03.get('t'));
    BOOST_TEST(-3 == **atn_n03.get('t')->parent());
    BOOST_TEST(-3 == **atn_p12.parent());
    c_fwd_itr = atn_n03.cbegin();
    BOOST_TEST('n' == c_fwd_itr->first);
    BOOST_TEST('n' == c_fwd_itr->second->key());
    BOOST_TEST(7 == **c_fwd_itr->second);
    BOOST_TEST(-3 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST('s' == c_fwd_itr->first);
    BOOST_TEST('s' == c_fwd_itr->second->key());
    BOOST_TEST(11 == **c_fwd_itr->second);
    BOOST_TEST(-3 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST('t' == c_fwd_itr->first);
    BOOST_TEST('t' == c_fwd_itr->second->key());
    BOOST_TEST(12 == **c_fwd_itr->second);
    BOOST_TEST(-3 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == atn_n03.cend());
    c_rev_itr = atn_n03.crbegin();
    BOOST_TEST('t' == c_rev_itr->first);
    BOOST_TEST('t' == c_rev_itr->second->key());
    BOOST_TEST(12 == **c_rev_itr->second);
    BOOST_TEST(-3 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST('s' == c_rev_itr->first);
    BOOST_TEST('s' == c_rev_itr->second->key());
    BOOST_TEST(11 == **c_rev_itr->second);
    BOOST_TEST(-3 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST('n' == c_rev_itr->first);
    BOOST_TEST('n' == c_rev_itr->second->key());
    BOOST_TEST(7 == **c_rev_itr->second);
    BOOST_TEST(-3 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == atn_n03.crend());
    BOOST_TEST(7 == atn_o00.size());
    BOOST_TEST(6 == atn_n03.size());
    atn_o00.set('t', atn_n01);
    BOOST_TEST('t' == atn_o00.get('t')->key());
    BOOST_TEST(-1 == **atn_o00.get('t'));
    BOOST_TEST(0 == **atn_o00.get('t')->parent());
    BOOST_TEST(0 == **atn_n01.parent());
    c_fwd_itr = atn_o00.cbegin();
    BOOST_TEST('i' == c_fwd_itr->first);
    BOOST_TEST('i' == c_fwd_itr->second->key());
    BOOST_TEST(-3 == **c_fwd_itr->second);
    BOOST_TEST(0 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST('t' == c_fwd_itr->first);
    BOOST_TEST('t' == c_fwd_itr->second->key());
    BOOST_TEST(-1 == **c_fwd_itr->second);
    BOOST_TEST(0 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == atn_o00.cend());
    c_rev_itr = atn_o00.crbegin();
    BOOST_TEST('t' == c_rev_itr->first);
    BOOST_TEST('t' == c_rev_itr->second->key());
    BOOST_TEST(-1 == **c_rev_itr->second);
    BOOST_TEST(0 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST('i' == c_rev_itr->first);
    BOOST_TEST('i' == c_rev_itr->second->key());
    BOOST_TEST(-3 == **c_rev_itr->second);
    BOOST_TEST(0 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == atn_o00.crend());
    BOOST_TEST(8 == atn_o00.size());
    atn_n01.set('o', atn_p08);
    BOOST_TEST('o' == atn_n01.get('o')->key());
    BOOST_TEST(8 == **atn_n01.get('o'));
    BOOST_TEST(-1 == **atn_n01.get('o')->parent());
    BOOST_TEST(-1 == **atn_p08.parent());
    c_fwd_itr = atn_n01.cbegin();
    BOOST_TEST('o' == c_fwd_itr->first);
    BOOST_TEST('o' == c_fwd_itr->second->key());
    BOOST_TEST(8 == **c_fwd_itr->second);
    BOOST_TEST(-1 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == atn_n01.cend());
    c_rev_itr = atn_n01.crbegin();
    BOOST_TEST('o' == c_rev_itr->first);
    BOOST_TEST('o' == c_rev_itr->second->key());
    BOOST_TEST(8 == **c_rev_itr->second);
    BOOST_TEST(-1 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == atn_n01.crend());
    BOOST_TEST(9 == atn_o00.size());
    BOOST_TEST(2 == atn_n01.size());
    atn_n01.set('e', atn_n02);
    BOOST_TEST('e' == atn_n01.get('e')->key());
    BOOST_TEST(-2 == **atn_n01.get('e'));
    BOOST_TEST(-1 == **atn_n01.get('e')->parent());
    BOOST_TEST(-1 == **atn_n02.parent());
    c_fwd_itr = atn_n01.cbegin();
    BOOST_TEST('e' == c_fwd_itr->first);
    BOOST_TEST('e' == c_fwd_itr->second->key());
    BOOST_TEST(-2 == **c_fwd_itr->second);
    BOOST_TEST(-1 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST('o' == c_fwd_itr->first);
    BOOST_TEST('o' == c_fwd_itr->second->key());
    BOOST_TEST(8 == **c_fwd_itr->second);
    BOOST_TEST(-1 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == atn_n01.cend());
    c_rev_itr = atn_n01.crbegin();
    BOOST_TEST('o' == c_rev_itr->first);
    BOOST_TEST('o' == c_rev_itr->second->key());
    BOOST_TEST(8 == **c_rev_itr->second);
    BOOST_TEST(-1 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST('e' == c_rev_itr->first);
    BOOST_TEST('e' == c_rev_itr->second->key());
    BOOST_TEST(-2 == **c_rev_itr->second);
    BOOST_TEST(-1 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == atn_n01.crend());
    BOOST_TEST(10 == atn_o00.size());
    BOOST_TEST(3 == atn_n01.size());
    atn_n02.set('d', atn_p05);
    BOOST_TEST('d' == atn_n02.get('d')->key());
    BOOST_TEST(5 == **atn_n02.get('d'));
    BOOST_TEST(-2 == **atn_n02.get('d')->parent());
    BOOST_TEST(-2 == **atn_p05.parent());
    c_fwd_itr = atn_n02.cbegin();
    BOOST_TEST('d' == c_fwd_itr->first);
    BOOST_TEST('d' == c_fwd_itr->second->key());
    BOOST_TEST(5 == **c_fwd_itr->second);
    BOOST_TEST(-2 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == atn_n02.cend());
    c_rev_itr = atn_n02.crbegin();
    BOOST_TEST('d' == c_rev_itr->first);
    BOOST_TEST('d' == c_rev_itr->second->key());
    BOOST_TEST(5 == **c_rev_itr->second);
    BOOST_TEST(-2 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == atn_n02.crend());
    BOOST_TEST(11 == atn_o00.size());
    BOOST_TEST(4 == atn_n01.size());
    BOOST_TEST(2 == atn_n02.size());
    atn_n02.set('n', atn_p06);
    BOOST_TEST('n' == atn_n02.get('n')->key());
    BOOST_TEST(6 == **atn_n02.get('n'));
    BOOST_TEST(-2 == **atn_n02.get('n')->parent());
    BOOST_TEST(-2 == **atn_p06.parent());
    c_fwd_itr = atn_n02.cbegin();
    BOOST_TEST('d' == c_fwd_itr->first);
    BOOST_TEST('d' == c_fwd_itr->second->key());
    BOOST_TEST(5 == **c_fwd_itr->second);
    BOOST_TEST(-2 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST('n' == c_fwd_itr->first);
    BOOST_TEST('n' == c_fwd_itr->second->key());
    BOOST_TEST(6 == **c_fwd_itr->second);
    BOOST_TEST(-2 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == atn_n02.cend());
    c_rev_itr = atn_n02.crbegin();
    BOOST_TEST('n' == c_rev_itr->first);
    BOOST_TEST('n' == c_rev_itr->second->key());
    BOOST_TEST(6 == **c_rev_itr->second);
    BOOST_TEST(-2 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST('d' == c_rev_itr->first);
    BOOST_TEST('d' == c_rev_itr->second->key());
    BOOST_TEST(5 == **c_rev_itr->second);
    BOOST_TEST(-2 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == atn_n02.crend());
    BOOST_TEST(12 == atn_o00.size());
    BOOST_TEST(5 == atn_n01.size());
    BOOST_TEST(3 == atn_n02.size());
    atn_n02.set('a', atn_p01);
    BOOST_TEST('a' == atn_n02.get('a')->key());
    BOOST_TEST(1 == **atn_n02.get('a'));
    BOOST_TEST(-2 == **atn_n02.get('a')->parent());
    BOOST_TEST(-2 == **atn_p01.parent());
    c_fwd_itr = atn_n02.cbegin();
    BOOST_TEST('a' == c_fwd_itr->first);
    BOOST_TEST('a' == c_fwd_itr->second->key());
    BOOST_TEST(1 == **c_fwd_itr->second);
    BOOST_TEST(-2 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST('d' == c_fwd_itr->first);
    BOOST_TEST('d' == c_fwd_itr->second->key());
    BOOST_TEST(5 == **c_fwd_itr->second);
    BOOST_TEST(-2 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST('n' == c_fwd_itr->first);
    BOOST_TEST('n' == c_fwd_itr->second->key());
    BOOST_TEST(6 == **c_fwd_itr->second);
    BOOST_TEST(-2 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == atn_n02.cend());
    c_rev_itr = atn_n02.crbegin();
    BOOST_TEST('n' == c_rev_itr->first);
    BOOST_TEST('n' == c_rev_itr->second->key());
    BOOST_TEST(6 == **c_rev_itr->second);
    BOOST_TEST(-2 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST('d' == c_rev_itr->first);
    BOOST_TEST('d' == c_rev_itr->second->key());
    BOOST_TEST(5 == **c_rev_itr->second);
    BOOST_TEST(-2 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST('a' == c_rev_itr->first);
    BOOST_TEST('a' == c_rev_itr->second->key());
    BOOST_TEST(1 == **c_rev_itr->second);
    BOOST_TEST(-2 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == atn_n02.crend());
    BOOST_TEST(13 == atn_o00.size());
    BOOST_TEST(6 == atn_n01.size());
    BOOST_TEST(4 == atn_n02.size());
    atn_p01.set('l', atn_p02);
    BOOST_TEST('l' == atn_p01.get('l')->key());
    BOOST_TEST(2 == **atn_p01.get('l'));
    BOOST_TEST(1 == **atn_p01.get('l')->parent());
    BOOST_TEST(1 == **atn_p02.parent());
    c_fwd_itr = atn_p01.cbegin();
    BOOST_TEST('l' == c_fwd_itr->first);
    BOOST_TEST('l' == c_fwd_itr->second->key());
    BOOST_TEST(2 == **c_fwd_itr->second);
    BOOST_TEST(1 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == atn_p01.cend());
    c_rev_itr = atn_p01.crbegin();
    BOOST_TEST('l' == c_rev_itr->first);
    BOOST_TEST('l' == c_rev_itr->second->key());
    BOOST_TEST(2 == **c_rev_itr->second);
    BOOST_TEST(1 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == atn_p01.crend());
    BOOST_TEST(14 == atn_o00.size());
    BOOST_TEST(7 == atn_n01.size());
    BOOST_TEST(5 == atn_n02.size());
    BOOST_TEST(2 == atn_p01.size());
    atn_p01.set('m', atn_p03);
    BOOST_TEST('m' == atn_p01.get('m')->key());
    BOOST_TEST(3 == **atn_p01.get('m'));
    BOOST_TEST(1 == **atn_p01.get('m')->parent());
    BOOST_TEST(1 == **atn_p03.parent());
    c_fwd_itr = atn_p01.cbegin();
    BOOST_TEST('l' == c_fwd_itr->first);
    BOOST_TEST('l' == c_fwd_itr->second->key());
    BOOST_TEST(2 == **c_fwd_itr->second);
    BOOST_TEST(1 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST('m' == c_fwd_itr->first);
    BOOST_TEST('m' == c_fwd_itr->second->key());
    BOOST_TEST(3 == **c_fwd_itr->second);
    BOOST_TEST(1 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == atn_p01.cend());
    c_rev_itr = atn_p01.crbegin();
    BOOST_TEST('m' == c_rev_itr->first);
    BOOST_TEST('m' == c_rev_itr->second->key());
    BOOST_TEST(3 == **c_rev_itr->second);
    BOOST_TEST(1 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST('l' == c_rev_itr->first);
    BOOST_TEST('l' == c_rev_itr->second->key());
    BOOST_TEST(2 == **c_rev_itr->second);
    BOOST_TEST(1 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == atn_p01.crend());
    BOOST_TEST(15 == atn_o00.size());
    BOOST_TEST(8 == atn_n01.size());
    BOOST_TEST(6 == atn_n02.size());
    BOOST_TEST(3 == atn_p01.size());
    atn_p01.set('r', atn_p04);
    BOOST_TEST('r' == atn_p01.get('r')->key());
    BOOST_TEST(4 == **atn_p01.get('r'));
    BOOST_TEST(1 == **atn_p01.get('r')->parent());
    BOOST_TEST(1 == **atn_p04.parent());
    c_fwd_itr = atn_p01.cbegin();
    BOOST_TEST('l' == c_fwd_itr->first);
    BOOST_TEST('l' == c_fwd_itr->second->key());
    BOOST_TEST(2 == **c_fwd_itr->second);
    BOOST_TEST(1 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST('m' == c_fwd_itr->first);
    BOOST_TEST('m' == c_fwd_itr->second->key());
    BOOST_TEST(3 == **c_fwd_itr->second);
    BOOST_TEST(1 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST('r' == c_fwd_itr->first);
    BOOST_TEST('r' == c_fwd_itr->second->key());
    BOOST_TEST(4 == **c_fwd_itr->second);
    BOOST_TEST(1 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == atn_p01.cend());
    c_rev_itr = atn_p01.crbegin();
    BOOST_TEST('r' == c_rev_itr->first);
    BOOST_TEST('r' == c_rev_itr->second->key());
    BOOST_TEST(4 == **c_rev_itr->second);
    BOOST_TEST(1 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST('m' == c_rev_itr->first);
    BOOST_TEST('m' == c_rev_itr->second->key());
    BOOST_TEST(3 == **c_rev_itr->second);
    BOOST_TEST(1 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST('l' == c_rev_itr->first);
    BOOST_TEST('l' == c_rev_itr->second->key());
    BOOST_TEST(2 == **c_rev_itr->second);
    BOOST_TEST(1 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == atn_p01.crend());
    BOOST_TEST(16 == atn_o00.size());
    BOOST_TEST(9 == atn_n01.size());
    BOOST_TEST(7 == atn_n02.size());
    BOOST_TEST(4 == atn_p01.size());
    atn_o00.set('A', atn_p13);
    BOOST_TEST('A' == atn_o00.get('A')->key());
    BOOST_TEST(13 == **atn_o00.get('A'));
    BOOST_TEST(0 == **atn_o00.get('A')->parent());
    BOOST_TEST(0 == **atn_p13.parent());
    c_fwd_itr = atn_o00.cbegin();
    BOOST_TEST('A' == c_fwd_itr->first);
    BOOST_TEST('A' == c_fwd_itr->second->key());
    BOOST_TEST(13 == **c_fwd_itr->second);
    BOOST_TEST(0 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST('i' == c_fwd_itr->first);
    BOOST_TEST('i' == c_fwd_itr->second->key());
    BOOST_TEST(-3 == **c_fwd_itr->second);
    BOOST_TEST(0 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST('t' == c_fwd_itr->first);
    BOOST_TEST('t' == c_fwd_itr->second->key());
    BOOST_TEST(-1 == **c_fwd_itr->second);
    BOOST_TEST(0 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == atn_o00.cend());
    c_rev_itr = atn_o00.crbegin();
    BOOST_TEST('t' == c_rev_itr->first);
    BOOST_TEST('t' == c_rev_itr->second->key());
    BOOST_TEST(-1 == **c_rev_itr->second);
    BOOST_TEST(0 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST('i' == c_rev_itr->first);
    BOOST_TEST('i' == c_rev_itr->second->key());
    BOOST_TEST(-3 == **c_rev_itr->second);
    BOOST_TEST(0 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST('A' == c_rev_itr->first);
    BOOST_TEST('A' == c_rev_itr->second->key());
    BOOST_TEST(13 == **c_rev_itr->second);
    BOOST_TEST(0 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == atn_o00.crend());
    BOOST_TEST(17 == atn_o00.size());
    atn_n03.swap(atn_p07);
    BOOST_TEST(7 == **atn_n03.parent());
    BOOST_TEST(0 == **atn_p07.parent());
    BOOST_TEST(7 == **atn_o00.get('i'));
    c_fwd_itr = atn_n03.cbegin();
    BOOST_TEST('k' == c_fwd_itr->first);
    BOOST_TEST('k' == c_fwd_itr->second->key());
    BOOST_TEST(9 == **c_fwd_itr->second);
    BOOST_TEST(-3 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST('n' == c_fwd_itr->first);
    BOOST_TEST('n' == c_fwd_itr->second->key());
    BOOST_TEST(10 == **c_fwd_itr->second);
    BOOST_TEST(-3 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == atn_n03.cend());
    c_rev_itr = atn_n03.crbegin();
    BOOST_TEST('n' == c_rev_itr->first);
    BOOST_TEST('n' == c_rev_itr->second->key());
    BOOST_TEST(10 == **c_rev_itr->second);
    BOOST_TEST(-3 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST('k' == c_rev_itr->first);
    BOOST_TEST('k' == c_rev_itr->second->key());
    BOOST_TEST(9 == **c_rev_itr->second);
    BOOST_TEST(-3 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == atn_n03.crend());
    c_fwd_itr = atn_p07.cbegin();
    BOOST_TEST('n' == c_fwd_itr->first);
    BOOST_TEST('n' == c_fwd_itr->second->key());
    BOOST_TEST(-3 == **c_fwd_itr->second);
    BOOST_TEST(7 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST('s' == c_fwd_itr->first);
    BOOST_TEST('s' == c_fwd_itr->second->key());
    BOOST_TEST(11 == **c_fwd_itr->second);
    BOOST_TEST(7 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST('t' == c_fwd_itr->first);
    BOOST_TEST('t' == c_fwd_itr->second->key());
    BOOST_TEST(12 == **c_fwd_itr->second);
    BOOST_TEST(7 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == atn_p07.cend());
    c_rev_itr = atn_p07.crbegin();
    BOOST_TEST('t' == c_rev_itr->first);
    BOOST_TEST('t' == c_rev_itr->second->key());
    BOOST_TEST(12 == **c_rev_itr->second);
    BOOST_TEST(7 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST('s' == c_rev_itr->first);
    BOOST_TEST('s' == c_rev_itr->second->key());
    BOOST_TEST(11 == **c_rev_itr->second);
    BOOST_TEST(7 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST('n' == c_rev_itr->first);
    BOOST_TEST('n' == c_rev_itr->second->key());
    BOOST_TEST(-3 == **c_rev_itr->second);
    BOOST_TEST(7 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == atn_p07.crend());
    BOOST_TEST(17 == atn_o00.size());
    BOOST_TEST(3 == atn_n03.size());
    BOOST_TEST(6 == atn_p07.size());
    atn_p01.swap(atn_n02);
    BOOST_TEST(-1 == **atn_p01.parent());
    BOOST_TEST(1 == **atn_n02.parent());
    BOOST_TEST(1 == **atn_n01.get('e'));
    c_fwd_itr = atn_n02.cbegin();
    BOOST_TEST('l' == c_fwd_itr->first);
    BOOST_TEST('l' == c_fwd_itr->second->key());
    BOOST_TEST(2 == **c_fwd_itr->second);
    BOOST_TEST(-2 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST('m' == c_fwd_itr->first);
    BOOST_TEST('m' == c_fwd_itr->second->key());
    BOOST_TEST(3 == **c_fwd_itr->second);
    BOOST_TEST(-2 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST('r' == c_fwd_itr->first);
    BOOST_TEST('r' == c_fwd_itr->second->key());
    BOOST_TEST(4 == **c_fwd_itr->second);
    BOOST_TEST(-2 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == atn_n02.cend());
    c_rev_itr = atn_n02.crbegin();
    BOOST_TEST('r' == c_rev_itr->first);
    BOOST_TEST('r' == c_rev_itr->second->key());
    BOOST_TEST(4 == **c_rev_itr->second);
    BOOST_TEST(-2 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST('m' == c_rev_itr->first);
    BOOST_TEST('m' == c_rev_itr->second->key());
    BOOST_TEST(3 == **c_rev_itr->second);
    BOOST_TEST(-2 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST('l' == c_rev_itr->first);
    BOOST_TEST('l' == c_rev_itr->second->key());
    BOOST_TEST(2 == **c_rev_itr->second);
    BOOST_TEST(-2 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == atn_n02.crend());
    c_fwd_itr = atn_p01.cbegin();
    BOOST_TEST('a' == c_fwd_itr->first);
    BOOST_TEST('a' == c_fwd_itr->second->key());
    BOOST_TEST(-2 == **c_fwd_itr->second);
    BOOST_TEST(1 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST('d' == c_fwd_itr->first);
    BOOST_TEST('d' == c_fwd_itr->second->key());
    BOOST_TEST(5 == **c_fwd_itr->second);
    BOOST_TEST(1 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST('n' == c_fwd_itr->first);
    BOOST_TEST('n' == c_fwd_itr->second->key());
    BOOST_TEST(6 == **c_fwd_itr->second);
    BOOST_TEST(1 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == atn_p01.cend());
    c_rev_itr = atn_p01.crbegin();
    BOOST_TEST('n' == c_rev_itr->first);
    BOOST_TEST('n' == c_rev_itr->second->key());
    BOOST_TEST(6 == **c_rev_itr->second);
    BOOST_TEST(1 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST('d' == c_rev_itr->first);
    BOOST_TEST('d' == c_rev_itr->second->key());
    BOOST_TEST(5 == **c_rev_itr->second);
    BOOST_TEST(1 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST('a' == c_rev_itr->first);
    BOOST_TEST('a' == c_rev_itr->second->key());
    BOOST_TEST(-2 == **c_rev_itr->second);
    BOOST_TEST(1 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == atn_p01.crend());
    BOOST_TEST(17 == atn_o00.size());
    BOOST_TEST(9 == atn_n01.size());
    BOOST_TEST(4 == atn_n02.size());
    BOOST_TEST(7 == atn_p01.size());
    atn_n01.swap(atn_p07);
    BOOST_TEST(0 == **atn_n01.parent());
    BOOST_TEST(0 == **atn_p07.parent());
    BOOST_TEST(-1 == **atn_o00.get('i'));
    BOOST_TEST(7 == **atn_o00.get('t'));
    c_fwd_itr = atn_n01.cbegin();
    BOOST_TEST('n' == c_fwd_itr->first);
    BOOST_TEST('n' == c_fwd_itr->second->key());
    BOOST_TEST(-3 == **c_fwd_itr->second);
    BOOST_TEST(-1 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST('s' == c_fwd_itr->first);
    BOOST_TEST('s' == c_fwd_itr->second->key());
    BOOST_TEST(11 == **c_fwd_itr->second);
    BOOST_TEST(-1 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST('t' == c_fwd_itr->first);
    BOOST_TEST('t' == c_fwd_itr->second->key());
    BOOST_TEST(12 == **c_fwd_itr->second);
    BOOST_TEST(-1 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == atn_n01.cend());
    c_rev_itr = atn_n01.crbegin();
    BOOST_TEST('t' == c_rev_itr->first);
    BOOST_TEST('t' == c_rev_itr->second->key());
    BOOST_TEST(12 == **c_rev_itr->second);
    BOOST_TEST(-1 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST('s' == c_rev_itr->first);
    BOOST_TEST('s' == c_rev_itr->second->key());
    BOOST_TEST(11 == **c_rev_itr->second);
    BOOST_TEST(-1 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST('n' == c_rev_itr->first);
    BOOST_TEST('n' == c_rev_itr->second->key());
    BOOST_TEST(-3 == **c_rev_itr->second);
    BOOST_TEST(-1 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == atn_n01.crend());
    c_fwd_itr = atn_p07.cbegin();
    BOOST_TEST('e' == c_fwd_itr->first);
    BOOST_TEST('e' == c_fwd_itr->second->key());
    BOOST_TEST(1 == **c_fwd_itr->second);
    BOOST_TEST(7 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST('o' == c_fwd_itr->first);
    BOOST_TEST('o' == c_fwd_itr->second->key());
    BOOST_TEST(8 == **c_fwd_itr->second);
    BOOST_TEST(7 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == atn_p07.cend());
    c_rev_itr = atn_p07.crbegin();
    BOOST_TEST('o' == c_rev_itr->first);
    BOOST_TEST('o' == c_rev_itr->second->key());
    BOOST_TEST(8 == **c_rev_itr->second);
    BOOST_TEST(7 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST('e' == c_rev_itr->first);
    BOOST_TEST('e' == c_rev_itr->second->key());
    BOOST_TEST(1 == **c_rev_itr->second);
    BOOST_TEST(7 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == atn_p07.crend());
    BOOST_TEST(17 == atn_o00.size());
    BOOST_TEST(3 == atn_n03.size());
    BOOST_TEST(6 == atn_n01.size());
    BOOST_TEST(9 == atn_p07.size());
    atn_o00.unset('t');
    c_fwd_itr = atn_o00.cbegin();
    BOOST_TEST('A' == c_fwd_itr->first);
    BOOST_TEST('A' == c_fwd_itr->second->key());
    BOOST_TEST(13 == **c_fwd_itr->second);
    BOOST_TEST(0 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST('i' == c_fwd_itr->first);
    BOOST_TEST('i' == c_fwd_itr->second->key());
    BOOST_TEST(-1 == **c_fwd_itr->second);
    BOOST_TEST(0 == **c_fwd_itr->second->parent());
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == atn_o00.cend());
    c_rev_itr = atn_o00.crbegin();
    BOOST_TEST('i' == c_rev_itr->first);
    BOOST_TEST('i' == c_rev_itr->second->key());
    BOOST_TEST(-1 == **c_rev_itr->second);
    BOOST_TEST(0 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST('A' == c_rev_itr->first);
    BOOST_TEST('A' == c_rev_itr->second->key());
    BOOST_TEST(13 == **c_rev_itr->second);
    BOOST_TEST(0 == **c_rev_itr->second->parent());
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == atn_o00.crend());
    BOOST_TEST(8 == atn_o00.size());
}

#include <cstring>
#include <algorithm>
#include <boost/unordered/unordered_map.hpp>
#include <boost/mpl/placeholders.hpp>

void test_01()
{
    typedef ::odds_and_ends::composite_type::composite_type<
        ::boost::mpl::deque<
            ::odds_and_ends::node::data<int const>,
            ::odds_and_ends::node::tree::base<>,
            ::odds_and_ends::node::tree::associative<
                char const*,
                ::boost::unordered::unordered_map< ::boost::mpl::_1,::boost::mpl::_2>
            >,
            ::odds_and_ends::node::tree::with_size<>
        >
    > associative_tree_node;

    associative_tree_node atn_n09(-9);
    associative_tree_node atn_n08(-8);
    associative_tree_node atn_n07(-7);
    associative_tree_node atn_n06(-6);
    associative_tree_node atn_n05(-5);
    associative_tree_node atn_n04(-4);
    associative_tree_node atn_n03(-3);
    associative_tree_node atn_n02(-2);
    associative_tree_node atn_n01(-1);
    associative_tree_node atn_o00(0);
    associative_tree_node atn_p01(1);
    associative_tree_node atn_p02(2);
    associative_tree_node atn_p03(3);
    associative_tree_node atn_p04(4);
    associative_tree_node atn_p05(5);
    associative_tree_node atn_p06(6);
    associative_tree_node atn_p07(7);
    associative_tree_node atn_p08(8);
    associative_tree_node atn_p09(9);
    associative_tree_node atn_p10(10);
    associative_tree_node atn_p11(11);
    associative_tree_node atn_p12(12);
    associative_tree_node atn_p13(13);
    associative_tree_node atn_p14(14);
    associative_tree_node atn_p15(15);
    associative_tree_node atn_p16(16);

    BOOST_TEST(-9 == *atn_n09);
    BOOST_TEST(!atn_n09.parent());
    BOOST_TEST(atn_n09.cbegin() == atn_n09.cend());
    BOOST_TEST(1 == atn_n09.size());
    BOOST_TEST(-8 == *atn_n08);
    BOOST_TEST(!atn_n08.parent());
    BOOST_TEST(atn_n08.cbegin() == atn_n08.cend());
    BOOST_TEST(1 == atn_n08.size());
    BOOST_TEST(-7 == *atn_n07);
    BOOST_TEST(!atn_n07.parent());
    BOOST_TEST(atn_n07.cbegin() == atn_n07.cend());
    BOOST_TEST(1 == atn_n07.size());
    BOOST_TEST(-6 == *atn_n06);
    BOOST_TEST(!atn_n06.parent());
    BOOST_TEST(atn_n06.cbegin() == atn_n06.cend());
    BOOST_TEST(1 == atn_n06.size());
    BOOST_TEST(-5 == *atn_n05);
    BOOST_TEST(!atn_n05.parent());
    BOOST_TEST(atn_n05.cbegin() == atn_n05.cend());
    BOOST_TEST(1 == atn_n05.size());
    BOOST_TEST(-4 == *atn_n04);
    BOOST_TEST(!atn_n04.parent());
    BOOST_TEST(atn_n04.cbegin() == atn_n04.cend());
    BOOST_TEST(1 == atn_n04.size());
    BOOST_TEST(-3 == *atn_n03);
    BOOST_TEST(!atn_n03.parent());
    BOOST_TEST(atn_n03.cbegin() == atn_n03.cend());
    BOOST_TEST(1 == atn_n03.size());
    BOOST_TEST(-2 == *atn_n02);
    BOOST_TEST(!atn_n02.parent());
    BOOST_TEST(atn_n02.cbegin() == atn_n02.cend());
    BOOST_TEST(1 == atn_n02.size());
    BOOST_TEST(-1 == *atn_n01);
    BOOST_TEST(!atn_n01.parent());
    BOOST_TEST(atn_n01.cbegin() == atn_n01.cend());
    BOOST_TEST(1 == atn_n01.size());
    BOOST_TEST(0 == *atn_o00);
    BOOST_TEST(!atn_o00.parent());
    BOOST_TEST(atn_o00.cbegin() == atn_o00.cend());
    BOOST_TEST(1 == atn_o00.size());
    BOOST_TEST(1 == *atn_p01);
    BOOST_TEST(!atn_p01.parent());
    BOOST_TEST(atn_p01.cbegin() == atn_p01.cend());
    BOOST_TEST(1 == atn_p01.size());
    BOOST_TEST(2 == *atn_p02);
    BOOST_TEST(!atn_p02.parent());
    BOOST_TEST(atn_p02.cbegin() == atn_p02.cend());
    BOOST_TEST(1 == atn_p02.size());
    BOOST_TEST(3 == *atn_p03);
    BOOST_TEST(!atn_p03.parent());
    BOOST_TEST(atn_p03.cbegin() == atn_p03.cend());
    BOOST_TEST(1 == atn_p03.size());
    BOOST_TEST(4 == *atn_p04);
    BOOST_TEST(!atn_p04.parent());
    BOOST_TEST(atn_p04.cbegin() == atn_p04.cend());
    BOOST_TEST(1 == atn_p04.size());
    BOOST_TEST(5 == *atn_p05);
    BOOST_TEST(!atn_p05.parent());
    BOOST_TEST(atn_p05.cbegin() == atn_p05.cend());
    BOOST_TEST(1 == atn_p05.size());
    BOOST_TEST(6 == *atn_p06);
    BOOST_TEST(!atn_p06.parent());
    BOOST_TEST(atn_p06.cbegin() == atn_p06.cend());
    BOOST_TEST(1 == atn_p06.size());
    BOOST_TEST(7 == *atn_p07);
    BOOST_TEST(!atn_p07.parent());
    BOOST_TEST(atn_p07.cbegin() == atn_p07.cend());
    BOOST_TEST(1 == atn_p07.size());
    BOOST_TEST(8 == *atn_p08);
    BOOST_TEST(!atn_p08.parent());
    BOOST_TEST(atn_p08.cbegin() == atn_p08.cend());
    BOOST_TEST(1 == atn_p08.size());
    BOOST_TEST(9 == *atn_p09);
    BOOST_TEST(!atn_p09.parent());
    BOOST_TEST(atn_p09.cbegin() == atn_p09.cend());
    BOOST_TEST(1 == atn_p09.size());
    BOOST_TEST(10 == *atn_p10);
    BOOST_TEST(!atn_p10.parent());
    BOOST_TEST(atn_p10.cbegin() == atn_p10.cend());
    BOOST_TEST(1 == atn_p10.size());
    BOOST_TEST(11 == *atn_p11);
    BOOST_TEST(!atn_p11.parent());
    BOOST_TEST(atn_p11.cbegin() == atn_p11.cend());
    BOOST_TEST(1 == atn_p11.size());
    BOOST_TEST(12 == *atn_p12);
    BOOST_TEST(!atn_p12.parent());
    BOOST_TEST(atn_p12.cbegin() == atn_p12.cend());
    BOOST_TEST(1 == atn_p12.size());
    BOOST_TEST(13 == *atn_p13);
    BOOST_TEST(!atn_p13.parent());
    BOOST_TEST(atn_p13.cbegin() == atn_p13.cend());
    BOOST_TEST(1 == atn_p13.size());
    BOOST_TEST(14 == *atn_p14);
    BOOST_TEST(!atn_p14.parent());
    BOOST_TEST(atn_p14.cbegin() == atn_p14.cend());
    BOOST_TEST(1 == atn_p14.size());
    BOOST_TEST(15 == *atn_p15);
    BOOST_TEST(!atn_p15.parent());
    BOOST_TEST(atn_p15.cbegin() == atn_p15.cend());
    BOOST_TEST(1 == atn_p15.size());
    BOOST_TEST(16 == *atn_p16);
    BOOST_TEST(!atn_p16.parent());
    BOOST_TEST(atn_p16.cbegin() == atn_p16.cend());
    BOOST_TEST(1 == atn_p16.size());
    atn_o00.set("P", atn_n01);
    BOOST_TEST(-1 == **atn_o00.get("P"));
    BOOST_TEST(0 == **atn_n01.parent());
    BOOST_TEST(!::std::strcmp("P", atn_n01.key()));
    BOOST_TEST(
        !::std::strcmp(
            "P",
            ::std::find_if(
                atn_o00.cbegin(),
                atn_o00.cend(),
                [](auto p){return !::std::strcmp("P", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        -1 == **::std::find_if(
            atn_o00.cbegin(),
            atn_o00.cend(),
            [](auto p){return !::std::strcmp("P", p.first);}
        )->second
    );
    BOOST_TEST(2 == atn_o00.size());
    atn_o00.set("T", atn_n04);
    BOOST_TEST(-4 == **atn_o00.get("T"));
    BOOST_TEST(0 == **atn_n04.parent());
    BOOST_TEST(!::std::strcmp("T", atn_n04.key()));
    BOOST_TEST(
        !::std::strcmp(
            "T",
            ::std::find_if(
                atn_o00.cbegin(),
                atn_o00.cend(),
                [](auto p){return !::std::strcmp("T", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        -4 == **::std::find_if(
            atn_o00.cbegin(),
            atn_o00.cend(),
            [](auto p){return !::std::strcmp("T", p.first);}
        )->second
    );
    BOOST_TEST(3 == atn_o00.size());
    atn_o00.set("s", atn_n07);
    BOOST_TEST(-7 == **atn_o00.get("s"));
    BOOST_TEST(0 == **atn_n07.parent());
    BOOST_TEST(!::std::strcmp("s", atn_n07.key()));
    BOOST_TEST(
        !::std::strcmp(
            "s",
            ::std::find_if(
                atn_o00.cbegin(),
                atn_o00.cend(),
                [](auto p){return !::std::strcmp("s", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        -7 == **::std::find_if(
            atn_o00.cbegin(),
            atn_o00.cend(),
            [](auto p){return !::std::strcmp("s", p.first);}
        )->second
    );
    BOOST_TEST(4 == atn_o00.size());
    atn_n01.set("e", atn_n02);
    BOOST_TEST(-2 == **atn_n01.get("e"));
    BOOST_TEST(-1 == **atn_n02.parent());
    BOOST_TEST(!::std::strcmp("e", atn_n02.key()));
    BOOST_TEST(
        !::std::strcmp(
            "e",
            ::std::find_if(
                atn_n01.cbegin(),
                atn_n01.cend(),
                [](auto p){return !::std::strcmp("e", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        -2 == **::std::find_if(
            atn_n01.cbegin(),
            atn_n01.cend(),
            [](auto p){return !::std::strcmp("e", p.first);}
        )->second
    );
    BOOST_TEST(5 == atn_o00.size());
    BOOST_TEST(2 == atn_n01.size());
    atn_n01.set("i", atn_n03);
    BOOST_TEST(-3 == **atn_n01.get("i"));
    BOOST_TEST(-1 == **atn_n03.parent());
    BOOST_TEST(!::std::strcmp("i", atn_n03.key()));
    BOOST_TEST(
        !::std::strcmp(
            "i",
            ::std::find_if(
                atn_n01.cbegin(),
                atn_n01.cend(),
                [](auto p){return !::std::strcmp("i", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        -3 == **::std::find_if(
            atn_n01.cbegin(),
            atn_n01.cend(),
            [](auto p){return !::std::strcmp("i", p.first);}
        )->second
    );
    BOOST_TEST(6 == atn_o00.size());
    BOOST_TEST(3 == atn_n01.size());
    atn_n02.set("ter", atn_p01);
    BOOST_TEST(1 == **atn_n02.get("ter"));
    BOOST_TEST(-2 == **atn_p01.parent());
    BOOST_TEST(!::std::strcmp("ter", atn_p01.key()));
    BOOST_TEST(
        !::std::strcmp(
            "ter",
            ::std::find_if(
                atn_n02.cbegin(),
                atn_n02.cend(),
                [](auto p){return !::std::strcmp("ter", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        1 == **::std::find_if(
            atn_n02.cbegin(),
            atn_n02.cend(),
            [](auto p){return !::std::strcmp("ter", p.first);}
        )->second
    );
    BOOST_TEST(7 == atn_o00.size());
    BOOST_TEST(4 == atn_n01.size());
    BOOST_TEST(2 == atn_n02.size());
    atn_n02.set("ck", atn_p02);
    BOOST_TEST(2 == **atn_n02.get("ck"));
    BOOST_TEST(-2 == **atn_p02.parent());
    BOOST_TEST(!::std::strcmp("ck", atn_p02.key()));
    BOOST_TEST(
        !::std::strcmp(
            "ck",
            ::std::find_if(
                atn_n02.cbegin(),
                atn_n02.cend(),
                [](auto p){return !::std::strcmp("ck", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        2 == **::std::find_if(
            atn_n02.cbegin(),
            atn_n02.cend(),
            [](auto p){return !::std::strcmp("ck", p.first);}
        )->second
    );
    BOOST_TEST(8 == atn_o00.size());
    BOOST_TEST(5 == atn_n01.size());
    BOOST_TEST(3 == atn_n02.size());
    atn_n02.set("ppers", atn_p03);
    BOOST_TEST(3 == **atn_n02.get("ppers"));
    BOOST_TEST(-2 == **atn_p03.parent());
    BOOST_TEST(!::std::strcmp("ppers", atn_p03.key()));
    BOOST_TEST(
        !::std::strcmp(
            "ppers",
            ::std::find_if(
                atn_n02.cbegin(),
                atn_n02.cend(),
                [](auto p){return !::std::strcmp("ppers", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        3 == **::std::find_if(
            atn_n02.cbegin(),
            atn_n02.cend(),
            [](auto p){return !::std::strcmp("ppers", p.first);}
        )->second
    );
    BOOST_TEST(9 == atn_o00.size());
    BOOST_TEST(6 == atn_n01.size());
    BOOST_TEST(4 == atn_n02.size());
    atn_n03.set("per", atn_p04);
    BOOST_TEST(4 == **atn_n03.get("per"));
    BOOST_TEST(-3 == **atn_p04.parent());
    BOOST_TEST(!::std::strcmp("per", atn_p04.key()));
    BOOST_TEST(
        !::std::strcmp(
            "per",
            ::std::find_if(
                atn_n03.cbegin(),
                atn_n03.cend(),
                [](auto p){return !::std::strcmp("per", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        4 == **::std::find_if(
            atn_n03.cbegin(),
            atn_n03.cend(),
            [](auto p){return !::std::strcmp("per", p.first);}
        )->second
    );
    BOOST_TEST(10 == atn_o00.size());
    BOOST_TEST(7 == atn_n01.size());
    BOOST_TEST(2 == atn_n03.size());
    atn_n03.set("ck", atn_p07);
    BOOST_TEST(7 == **atn_n03.get("ck"));
    BOOST_TEST(-3 == **atn_p07.parent());
    BOOST_TEST(!::std::strcmp("ck", atn_p07.key()));
    BOOST_TEST(
        !::std::strcmp(
            "ck",
            ::std::find_if(
                atn_n03.cbegin(),
                atn_n03.cend(),
                [](auto p){return !::std::strcmp("ck", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        7 == **::std::find_if(
            atn_n03.cbegin(),
            atn_n03.cend(),
            [](auto p){return !::std::strcmp("ck", p.first);}
        )->second
    );
    BOOST_TEST(11 == atn_o00.size());
    BOOST_TEST(8 == atn_n01.size());
    BOOST_TEST(3 == atn_n03.size());
    atn_n04.set("h", atn_n05);
    BOOST_TEST(-5 == **atn_n04.get("h"));
    BOOST_TEST(-4 == **atn_n05.parent());
    BOOST_TEST(!::std::strcmp("h", atn_n05.key()));
    BOOST_TEST(
        !::std::strcmp(
            "h",
            ::std::find_if(
                atn_n04.cbegin(),
                atn_n04.cend(),
                [](auto p){return !::std::strcmp("h", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        -5 == **::std::find_if(
            atn_n04.cbegin(),
            atn_n04.cend(),
            [](auto p){return !::std::strcmp("h", p.first);}
        )->second
    );
    BOOST_TEST(12 == atn_o00.size());
    BOOST_TEST(2 == atn_n04.size());
    atn_n04.set("'is", atn_p08);
    BOOST_TEST(8 == **atn_n04.get("'is"));
    BOOST_TEST(-4 == **atn_p08.parent());
    BOOST_TEST(!::std::strcmp("'is", atn_p08.key()));
    BOOST_TEST(
        !::std::strcmp(
            "'is",
            ::std::find_if(
                atn_n04.cbegin(),
                atn_n04.cend(),
                [](auto p){return !::std::strcmp("'is", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        8 == **::std::find_if(
            atn_n04.cbegin(),
            atn_n04.cend(),
            [](auto p){return !::std::strcmp("'is", p.first);}
        )->second
    );
    BOOST_TEST(13 == atn_o00.size());
    BOOST_TEST(3 == atn_n04.size());
    atn_n04.set("rumps", atn_p12);
    BOOST_TEST(12 == **atn_n04.get("rumps"));
    BOOST_TEST(-4 == **atn_p12.parent());
    BOOST_TEST(!::std::strcmp("rumps", atn_p12.key()));
    BOOST_TEST(
        !::std::strcmp(
            "rumps",
            ::std::find_if(
                atn_n04.cbegin(),
                atn_n04.cend(),
                [](auto p){return !::std::strcmp("rumps", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        12 == **::std::find_if(
            atn_n04.cbegin(),
            atn_n04.cend(),
            [](auto p){return !::std::strcmp("rumps", p.first);}
        )->second
    );
    BOOST_TEST(14 == atn_o00.size());
    BOOST_TEST(4 == atn_n04.size());
    atn_n05.set("e", atn_p09);
    BOOST_TEST(9 == **atn_n05.get("e"));
    BOOST_TEST(-5 == **atn_p09.parent());
    BOOST_TEST(!::std::strcmp("e", atn_p09.key()));
    BOOST_TEST(
        !::std::strcmp(
            "e",
            ::std::find_if(
                atn_n05.cbegin(),
                atn_n05.cend(),
                [](auto p){return !::std::strcmp("e", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        9 == **::std::find_if(
            atn_n05.cbegin(),
            atn_n05.cend(),
            [](auto p){return !::std::strcmp("e", p.first);}
        )->second
    );
    BOOST_TEST(15 == atn_o00.size());
    BOOST_TEST(5 == atn_n04.size());
    BOOST_TEST(2 == atn_n05.size());
    atn_n05.set("ought", atn_p10);
    BOOST_TEST(10 == **atn_n05.get("ought"));
    BOOST_TEST(-5 == **atn_p10.parent());
    BOOST_TEST(!::std::strcmp("ought", atn_p10.key()));
    BOOST_TEST(
        !::std::strcmp(
            "ought",
            ::std::find_if(
                atn_n05.cbegin(),
                atn_n05.cend(),
                [](auto p){return !::std::strcmp("ought", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        10 == **::std::find_if(
            atn_n05.cbegin(),
            atn_n05.cend(),
            [](auto p){return !::std::strcmp("ought", p.first);}
        )->second
    );
    BOOST_TEST(16 == atn_o00.size());
    BOOST_TEST(6 == atn_n04.size());
    BOOST_TEST(3 == atn_n05.size());
    atn_n05.set("at", atn_p11);
    BOOST_TEST(11 == **atn_n05.get("at"));
    BOOST_TEST(-5 == **atn_p11.parent());
    BOOST_TEST(!::std::strcmp("at", atn_p11.key()));
    BOOST_TEST(
        !::std::strcmp(
            "at",
            ::std::find_if(
                atn_n05.cbegin(),
                atn_n05.cend(),
                [](auto p){return !::std::strcmp("at", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        11 == **::std::find_if(
            atn_n05.cbegin(),
            atn_n05.cend(),
            [](auto p){return !::std::strcmp("at", p.first);}
        )->second
    );
    BOOST_TEST(17 == atn_o00.size());
    BOOST_TEST(7 == atn_n04.size());
    BOOST_TEST(4 == atn_n05.size());
    atn_n07.set("he", atn_n08);
    BOOST_TEST(-8 == **atn_n07.get("he"));
    BOOST_TEST(-7 == **atn_n08.parent());
    BOOST_TEST(!::std::strcmp("he", atn_n08.key()));
    BOOST_TEST(
        !::std::strcmp(
            "he",
            ::std::find_if(
                atn_n07.cbegin(),
                atn_n07.cend(),
                [](auto p){return !::std::strcmp("he", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        -8 == **::std::find_if(
            atn_n07.cbegin(),
            atn_n07.cend(),
            [](auto p){return !::std::strcmp("he", p.first);}
        )->second
    );
    BOOST_TEST(18 == atn_o00.size());
    BOOST_TEST(2 == atn_n07.size());
    atn_n07.set("i", atn_n09);
    BOOST_TEST(-9 == **atn_n07.get("i"));
    BOOST_TEST(-7 == **atn_n09.parent());
    BOOST_TEST(!::std::strcmp("i", atn_n09.key()));
    BOOST_TEST(
        !::std::strcmp(
            "i",
            ::std::find_if(
                atn_n07.cbegin(),
                atn_n07.cend(),
                [](auto p){return !::std::strcmp("i", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        -9 == **::std::find_if(
            atn_n07.cbegin(),
            atn_n07.cend(),
            [](auto p){return !::std::strcmp("i", p.first);}
        )->second
    );
    BOOST_TEST(19 == atn_o00.size());
    BOOST_TEST(3 == atn_n07.size());
    atn_n08.set("ep's", atn_p13);
    BOOST_TEST(13 == **atn_n08.get("ep's"));
    BOOST_TEST(-8 == **atn_p13.parent());
    BOOST_TEST(!::std::strcmp("ep's", atn_p13.key()));
    BOOST_TEST(
        !::std::strcmp(
            "ep's",
            ::std::find_if(
                atn_n08.cbegin(),
                atn_n08.cend(),
                [](auto p){return !::std::strcmp("ep's", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        13 == **::std::find_if(
            atn_n08.cbegin(),
            atn_n08.cend(),
            [](auto p){return !::std::strcmp("ep's", p.first);}
        )->second
    );
    BOOST_TEST(20 == atn_o00.size());
    BOOST_TEST(4 == atn_n07.size());
    BOOST_TEST(2 == atn_n08.size());
    atn_n08.set("ik's", atn_p14);
    BOOST_TEST(14 == **atn_n08.get("ik's"));
    BOOST_TEST(-8 == **atn_p14.parent());
    BOOST_TEST(!::std::strcmp("ik's", atn_p14.key()));
    BOOST_TEST(
        !::std::strcmp(
            "ik's",
            ::std::find_if(
                atn_n08.cbegin(),
                atn_n08.cend(),
                [](auto p){return !::std::strcmp("ik's", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        14 == **::std::find_if(
            atn_n08.cbegin(),
            atn_n08.cend(),
            [](auto p){return !::std::strcmp("ik's", p.first);}
        )->second
    );
    BOOST_TEST(21 == atn_o00.size());
    BOOST_TEST(5 == atn_n07.size());
    BOOST_TEST(3 == atn_n08.size());
    atn_n09.set("xth", atn_p15);
    BOOST_TEST(15 == **atn_n09.get("xth"));
    BOOST_TEST(-9 == **atn_p15.parent());
    BOOST_TEST(!::std::strcmp("xth", atn_p15.key()));
    BOOST_TEST(
        !::std::strcmp(
            "xth",
            ::std::find_if(
                atn_n09.cbegin(),
                atn_n09.cend(),
                [](auto p){return !::std::strcmp("xth", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        15 == **::std::find_if(
            atn_n09.cbegin(),
            atn_n09.cend(),
            [](auto p){return !::std::strcmp("xth", p.first);}
        )->second
    );
    BOOST_TEST(22 == atn_o00.size());
    BOOST_TEST(6 == atn_n07.size());
    BOOST_TEST(2 == atn_n09.size());
    atn_n09.set("ck", atn_p16);
    BOOST_TEST(16 == **atn_n09.get("ck"));
    BOOST_TEST(-9 == **atn_p16.parent());
    BOOST_TEST(!::std::strcmp("ck", atn_p16.key()));
    BOOST_TEST(
        !::std::strcmp(
            "ck",
            ::std::find_if(
                atn_n09.cbegin(),
                atn_n09.cend(),
                [](auto p){return !::std::strcmp("ck", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        16 == **::std::find_if(
            atn_n09.cbegin(),
            atn_n09.cend(),
            [](auto p){return !::std::strcmp("ck", p.first);}
        )->second
    );
    BOOST_TEST(23 == atn_o00.size());
    BOOST_TEST(7 == atn_n07.size());
    BOOST_TEST(3 == atn_n09.size());
    atn_p07.set("ed", atn_p05);
    BOOST_TEST(5 == **atn_p07.get("ed"));
    BOOST_TEST(7 == **atn_p05.parent());
    BOOST_TEST(!::std::strcmp("ed", atn_p05.key()));
    BOOST_TEST(
        !::std::strcmp(
            "ed",
            ::std::find_if(
                atn_p07.cbegin(),
                atn_p07.cend(),
                [](auto p){return !::std::strcmp("ed", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        5 == **::std::find_if(
            atn_p07.cbegin(),
            atn_p07.cend(),
            [](auto p){return !::std::strcmp("ed", p.first);}
        )->second
    );
    BOOST_TEST(24 == atn_o00.size());
    BOOST_TEST(9 == atn_n01.size());
    BOOST_TEST(4 == atn_n03.size());
    BOOST_TEST(2 == atn_p07.size());
    atn_p07.set("led", atn_p06);
    BOOST_TEST(6 == **atn_p07.get("led"));
    BOOST_TEST(7 == **atn_p06.parent());
    BOOST_TEST(!::std::strcmp("led", atn_p06.key()));
    BOOST_TEST(
        !::std::strcmp(
            "led",
            ::std::find_if(
                atn_p07.cbegin(),
                atn_p07.cend(),
                [](auto p){return !::std::strcmp("led", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        6 == **::std::find_if(
            atn_p07.cbegin(),
            atn_p07.cend(),
            [](auto p){return !::std::strcmp("led", p.first);}
        )->second
    );
    BOOST_TEST(25 == atn_o00.size());
    BOOST_TEST(10 == atn_n01.size());
    BOOST_TEST(5 == atn_n03.size());
    BOOST_TEST(3 == atn_p07.size());
    atn_n01.swap(atn_n02);
    BOOST_TEST(-2 == **atn_o00.get("P"));
    BOOST_TEST(0 == **atn_n02.parent());
    BOOST_TEST(!::std::strcmp("P", atn_n02.key()));
    BOOST_TEST(
        !::std::strcmp(
            "P",
            ::std::find_if(
                atn_o00.cbegin(),
                atn_o00.cend(),
                [](auto p){return !::std::strcmp("P", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        -2 == **::std::find_if(
            atn_o00.cbegin(),
            atn_o00.cend(),
            [](auto p){return !::std::strcmp("P", p.first);}
        )->second
    );
    BOOST_TEST(-1 == **atn_n02.get("e"));
    BOOST_TEST(-2 == **atn_n01.parent());
    BOOST_TEST(!::std::strcmp("e", atn_n01.key()));
    BOOST_TEST(
        !::std::strcmp(
            "e",
            ::std::find_if(
                atn_n02.cbegin(),
                atn_n02.cend(),
                [](auto p){return !::std::strcmp("e", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        -1 == **::std::find_if(
            atn_n02.cbegin(),
            atn_n02.cend(),
            [](auto p){return !::std::strcmp("e", p.first);}
        )->second
    );
    BOOST_TEST(-3 == **atn_n02.get("i"));
    BOOST_TEST(-2 == **atn_n03.parent());
    BOOST_TEST(!::std::strcmp("i", atn_n03.key()));
    BOOST_TEST(
        !::std::strcmp(
            "i",
            ::std::find_if(
                atn_n02.cbegin(),
                atn_n02.cend(),
                [](auto p){return !::std::strcmp("i", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        -3 == **::std::find_if(
            atn_n02.cbegin(),
            atn_n02.cend(),
            [](auto p){return !::std::strcmp("i", p.first);}
        )->second
    );
    BOOST_TEST(1 == **atn_n01.get("ter"));
    BOOST_TEST(-1 == **atn_p01.parent());
    BOOST_TEST(!::std::strcmp("ter", atn_p01.key()));
    BOOST_TEST(
        !::std::strcmp(
            "ter",
            ::std::find_if(
                atn_n01.cbegin(),
                atn_n01.cend(),
                [](auto p){return !::std::strcmp("ter", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        1 == **::std::find_if(
            atn_n01.cbegin(),
            atn_n01.cend(),
            [](auto p){return !::std::strcmp("ter", p.first);}
        )->second
    );
    BOOST_TEST(2 == **atn_n01.get("ck"));
    BOOST_TEST(-1 == **atn_p02.parent());
    BOOST_TEST(!::std::strcmp("ck", atn_p02.key()));
    BOOST_TEST(
        !::std::strcmp(
            "ck",
            ::std::find_if(
                atn_n01.cbegin(),
                atn_n01.cend(),
                [](auto p){return !::std::strcmp("ck", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        2 == **::std::find_if(
            atn_n01.cbegin(),
            atn_n01.cend(),
            [](auto p){return !::std::strcmp("ck", p.first);}
        )->second
    );
    BOOST_TEST(3 == **atn_n01.get("ppers"));
    BOOST_TEST(-1 == **atn_p03.parent());
    BOOST_TEST(!::std::strcmp("ppers", atn_p03.key()));
    BOOST_TEST(
        !::std::strcmp(
            "ppers",
            ::std::find_if(
                atn_n01.cbegin(),
                atn_n01.cend(),
                [](auto p){return !::std::strcmp("ppers", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        3 == **::std::find_if(
            atn_n01.cbegin(),
            atn_n01.cend(),
            [](auto p){return !::std::strcmp("ppers", p.first);}
        )->second
    );
    BOOST_TEST(25 == atn_o00.size());
    BOOST_TEST(4 == atn_n01.size());
    BOOST_TEST(10 == atn_n02.size());
    atn_n01.swap(atn_n02);
    BOOST_TEST(-1 == **atn_o00.get("P"));
    BOOST_TEST(0 == **atn_n01.parent());
    BOOST_TEST(!::std::strcmp("P", atn_n01.key()));
    BOOST_TEST(
        !::std::strcmp(
            "P",
            ::std::find_if(
                atn_o00.cbegin(),
                atn_o00.cend(),
                [](auto p){return !::std::strcmp("P", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        -1 == **::std::find_if(
            atn_o00.cbegin(),
            atn_o00.cend(),
            [](auto p){return !::std::strcmp("P", p.first);}
        )->second
    );
    BOOST_TEST(-2 == **atn_n01.get("e"));
    BOOST_TEST(-1 == **atn_n02.parent());
    BOOST_TEST(!::std::strcmp("e", atn_n02.key()));
    BOOST_TEST(
        !::std::strcmp(
            "e",
            ::std::find_if(
                atn_n01.cbegin(),
                atn_n01.cend(),
                [](auto p){return !::std::strcmp("e", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        -2 == **::std::find_if(
            atn_n01.cbegin(),
            atn_n01.cend(),
            [](auto p){return !::std::strcmp("e", p.first);}
        )->second
    );
    BOOST_TEST(-3 == **atn_n01.get("i"));
    BOOST_TEST(-1 == **atn_n03.parent());
    BOOST_TEST(!::std::strcmp("i", atn_n03.key()));
    BOOST_TEST(
        !::std::strcmp(
            "i",
            ::std::find_if(
                atn_n01.cbegin(),
                atn_n01.cend(),
                [](auto p){return !::std::strcmp("i", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        -3 == **::std::find_if(
            atn_n01.cbegin(),
            atn_n01.cend(),
            [](auto p){return !::std::strcmp("i", p.first);}
        )->second
    );
    BOOST_TEST(1 == **atn_n02.get("ter"));
    BOOST_TEST(-2 == **atn_p01.parent());
    BOOST_TEST(!::std::strcmp("ter", atn_p01.key()));
    BOOST_TEST(
        !::std::strcmp(
            "ter",
            ::std::find_if(
                atn_n02.cbegin(),
                atn_n02.cend(),
                [](auto p){return !::std::strcmp("ter", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        1 == **::std::find_if(
            atn_n02.cbegin(),
            atn_n02.cend(),
            [](auto p){return !::std::strcmp("ter", p.first);}
        )->second
    );
    BOOST_TEST(2 == **atn_n02.get("ck"));
    BOOST_TEST(-2 == **atn_p02.parent());
    BOOST_TEST(!::std::strcmp("ck", atn_p02.key()));
    BOOST_TEST(
        !::std::strcmp(
            "ck",
            ::std::find_if(
                atn_n02.cbegin(),
                atn_n02.cend(),
                [](auto p){return !::std::strcmp("ck", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        2 == **::std::find_if(
            atn_n02.cbegin(),
            atn_n02.cend(),
            [](auto p){return !::std::strcmp("ck", p.first);}
        )->second
    );
    BOOST_TEST(3 == **atn_n02.get("ppers"));
    BOOST_TEST(-2 == **atn_p03.parent());
    BOOST_TEST(!::std::strcmp("ppers", atn_p03.key()));
    BOOST_TEST(
        !::std::strcmp(
            "ppers",
            ::std::find_if(
                atn_n02.cbegin(),
                atn_n02.cend(),
                [](auto p){return !::std::strcmp("ppers", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        3 == **::std::find_if(
            atn_n02.cbegin(),
            atn_n02.cend(),
            [](auto p){return !::std::strcmp("ppers", p.first);}
        )->second
    );
    BOOST_TEST(25 == atn_o00.size());
    BOOST_TEST(10 == atn_n01.size());
    BOOST_TEST(4 == atn_n02.size());
    atn_n02.swap(atn_n05);
    BOOST_TEST(-5 == **atn_n01.get("e"));
    BOOST_TEST(-1 == **atn_n05.parent());
    BOOST_TEST(!::std::strcmp("e", atn_n05.key()));
    BOOST_TEST(
        !::std::strcmp(
            "e",
            ::std::find_if(
                atn_n01.cbegin(),
                atn_n01.cend(),
                [](auto p){return !::std::strcmp("e", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        -5 == **::std::find_if(
            atn_n01.cbegin(),
            atn_n01.cend(),
            [](auto p){return !::std::strcmp("e", p.first);}
        )->second
    );
    BOOST_TEST(1 == **atn_n05.get("ter"));
    BOOST_TEST(-5 == **atn_p01.parent());
    BOOST_TEST(!::std::strcmp("ter", atn_p01.key()));
    BOOST_TEST(
        !::std::strcmp(
            "ter",
            ::std::find_if(
                atn_n05.cbegin(),
                atn_n05.cend(),
                [](auto p){return !::std::strcmp("ter", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        1 == **::std::find_if(
            atn_n05.cbegin(),
            atn_n05.cend(),
            [](auto p){return !::std::strcmp("ter", p.first);}
        )->second
    );
    BOOST_TEST(2 == **atn_n05.get("ck"));
    BOOST_TEST(-5 == **atn_p02.parent());
    BOOST_TEST(!::std::strcmp("ck", atn_p02.key()));
    BOOST_TEST(
        !::std::strcmp(
            "ck",
            ::std::find_if(
                atn_n05.cbegin(),
                atn_n05.cend(),
                [](auto p){return !::std::strcmp("ck", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        2 == **::std::find_if(
            atn_n05.cbegin(),
            atn_n05.cend(),
            [](auto p){return !::std::strcmp("ck", p.first);}
        )->second
    );
    BOOST_TEST(3 == **atn_n05.get("ppers"));
    BOOST_TEST(-5 == **atn_p03.parent());
    BOOST_TEST(!::std::strcmp("ppers", atn_p03.key()));
    BOOST_TEST(
        !::std::strcmp(
            "ppers",
            ::std::find_if(
                atn_n05.cbegin(),
                atn_n05.cend(),
                [](auto p){return !::std::strcmp("ppers", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        3 == **::std::find_if(
            atn_n05.cbegin(),
            atn_n05.cend(),
            [](auto p){return !::std::strcmp("ppers", p.first);}
        )->second
    );
    BOOST_TEST(-2 == **atn_n04.get("h"));
    BOOST_TEST(-4 == **atn_n02.parent());
    BOOST_TEST(!::std::strcmp("h", atn_n02.key()));
    BOOST_TEST(
        !::std::strcmp(
            "h",
            ::std::find_if(
                atn_n04.cbegin(),
                atn_n04.cend(),
                [](auto p){return !::std::strcmp("h", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        -2 == **::std::find_if(
            atn_n04.cbegin(),
            atn_n04.cend(),
            [](auto p){return !::std::strcmp("h", p.first);}
        )->second
    );
    BOOST_TEST(9 == **atn_n02.get("e"));
    BOOST_TEST(-2 == **atn_p09.parent());
    BOOST_TEST(!::std::strcmp("e", atn_p09.key()));
    BOOST_TEST(
        !::std::strcmp(
            "e",
            ::std::find_if(
                atn_n02.cbegin(),
                atn_n02.cend(),
                [](auto p){return !::std::strcmp("e", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        9 == **::std::find_if(
            atn_n02.cbegin(),
            atn_n02.cend(),
            [](auto p){return !::std::strcmp("e", p.first);}
        )->second
    );
    BOOST_TEST(10 == **atn_n02.get("ought"));
    BOOST_TEST(-2 == **atn_p10.parent());
    BOOST_TEST(!::std::strcmp("ought", atn_p10.key()));
    BOOST_TEST(
        !::std::strcmp(
            "ought",
            ::std::find_if(
                atn_n02.cbegin(),
                atn_n02.cend(),
                [](auto p){return !::std::strcmp("ought", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        10 == **::std::find_if(
            atn_n02.cbegin(),
            atn_n02.cend(),
            [](auto p){return !::std::strcmp("ought", p.first);}
        )->second
    );
    BOOST_TEST(11 == **atn_n02.get("at"));
    BOOST_TEST(-2 == **atn_p11.parent());
    BOOST_TEST(!::std::strcmp("at", atn_p11.key()));
    BOOST_TEST(
        !::std::strcmp(
            "at",
            ::std::find_if(
                atn_n02.cbegin(),
                atn_n02.cend(),
                [](auto p){return !::std::strcmp("at", p.first);}
            )->first
        )
    );
    BOOST_TEST(
        11 == **::std::find_if(
            atn_n02.cbegin(),
            atn_n02.cend(),
            [](auto p){return !::std::strcmp("at", p.first);}
        )->second
    );
    BOOST_TEST(25 == atn_o00.size());
    BOOST_TEST(10 == atn_n01.size());
    BOOST_TEST(4 == atn_n02.size());
    BOOST_TEST(7 == atn_n04.size());
    BOOST_TEST(4 == atn_n05.size());
}

int main(int argc, char** argv)
{
    test_00();
    test_01();
    return ::boost::report_errors();
}

