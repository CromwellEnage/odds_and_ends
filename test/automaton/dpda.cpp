// Copyright (C) 2007-2026 Cromwell D. Enage

#include <cstddef>
#include <odds_and_ends/automaton/transition_function/deque_register.hpp>

typedef ::odds_and_ends::automaton::deque_register_transition_function<char,char> DRX10Function;

#include <odds_and_ends/automaton/base.hpp>
#include <odds_and_ends/composite_type/composite_type.hpp>
#include <boost/mpl/deque.hpp>

typedef ::odds_and_ends::composite_type::composite_type<
    ::boost::mpl::deque< ::odds_and_ends::automaton::base<DRX10Function> >
> DPDA;

#include <string>

bool accept(DPDA& dpda, ::std::string const& word)
{
    dpda.reset();

    for (::std::size_t i = 0; i < word.length(); )
    {
        if (dpda(word[i]))
        {
            ++i;
        }
        else
        {
            return false;
        }
    }

    return dpda.get_state().first.empty();
}

#include <tuple>
#include <boost/core/lightweight_test.hpp>

void test_00()
{
    DRX10Function function;

    function(0, 'a') = DRX10Function::next_1_type(0, 'S', true);
    function(0, 'b', 'S', true) = 1;
    function(1, 'b', 'S', true) = 1;

    DPDA dpda(function);

    BOOST_TEST(dpda.get_state().first.empty());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('a'));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('a'));
    BOOST_TEST(2 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('b'));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(dpda('b'));
    BOOST_TEST(dpda.get_state().first.empty());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(!dpda('b'));
    dpda.reset();
    BOOST_TEST(dpda.get_state().first.empty());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('a'));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('a'));
    BOOST_TEST(2 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('a'));
    BOOST_TEST(3 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('b'));
    BOOST_TEST(2 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(dpda('b'));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(dpda('b'));
    BOOST_TEST(dpda.get_state().first.empty());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(!dpda('b'));
    BOOST_TEST(!accept(dpda, "aab"));
    BOOST_TEST(accept(dpda, "aabb"));
    BOOST_TEST(!accept(dpda, "aabbb"));
    BOOST_TEST(accept(dpda, "aaabbb"));
}

void test_01()
{
    DRX10Function function;

    function(0, '(') = DRX10Function::next_1_type(0, 'S', true);
    function(0, '(', 'A', true) = DRX10Function::next_1_type(0, 'S', true);
    function(0, 'x') = 1;
    function(0, 'x', 'A', true) = 1;
    function(0, 'y') = 1;
    function(0, 'y', 'A', true) = 1;
    function(0, 'z') = 1;
    function(0, 'z', 'A', true) = 1;
    function(1, ')', 'S', true) = 1;
    function(1, '+') = DRX10Function::next_1_type(0, 'A', true);
    function(1, '-') = DRX10Function::next_1_type(0, 'A', true);
    function(1, '*') = DRX10Function::next_1_type(0, 'A', true);
    function(1, '/') = DRX10Function::next_1_type(0, 'A', true);

    DPDA dpda(function);

    BOOST_TEST(dpda.get_state().first.empty());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('x'));
    BOOST_TEST(dpda.get_state().first.empty());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(!dpda('y'));
    BOOST_TEST(!dpda('('));
    BOOST_TEST(dpda('+'));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('A' == dpda.get_state().first.back());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('y'));
    BOOST_TEST(dpda.get_state().first.empty());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(!dpda(')'));
    dpda.reset();
    BOOST_TEST(dpda.get_state().first.empty());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('('));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('x'));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(dpda('+'));
    BOOST_TEST(2 == dpda.get_state().first.size());
    BOOST_TEST('A' == dpda.get_state().first.back());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('y'));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(dpda(')'));
    BOOST_TEST(dpda.get_state().first.empty());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(dpda('*'));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('A' == dpda.get_state().first.back());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('x'));
    BOOST_TEST(dpda.get_state().first.empty());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(dpda('-'));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('A' == dpda.get_state().first.back());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('z'));
    BOOST_TEST(dpda.get_state().first.empty());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(dpda('*'));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('A' == dpda.get_state().first.back());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('y'));
    BOOST_TEST(dpda.get_state().first.empty());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(dpda('/'));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('A' == dpda.get_state().first.back());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('('));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('x'));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(dpda('+'));
    BOOST_TEST(2 == dpda.get_state().first.size());
    BOOST_TEST('A' == dpda.get_state().first.back());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('x'));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(dpda(')'));
    BOOST_TEST(dpda.get_state().first.empty());
    BOOST_TEST(1 == dpda.get_state().second);
    dpda.reset();
    BOOST_TEST(dpda.get_state().first.empty());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('x'));
    BOOST_TEST(dpda.get_state().first.empty());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(dpda('/'));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('A' == dpda.get_state().first.back());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('('));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('y'));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(dpda('*'));
    BOOST_TEST(2 == dpda.get_state().first.size());
    BOOST_TEST('A' == dpda.get_state().first.back());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('('));
    BOOST_TEST(2 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('z'));
    BOOST_TEST(2 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(dpda('-'));
    BOOST_TEST(3 == dpda.get_state().first.size());
    BOOST_TEST('A' == dpda.get_state().first.back());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('y'));
    BOOST_TEST(2 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(dpda(')'));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(dpda('+'));
    BOOST_TEST(2 == dpda.get_state().first.size());
    BOOST_TEST('A' == dpda.get_state().first.back());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('x'));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(dpda(')'));
    BOOST_TEST(dpda.get_state().first.empty());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(!accept(dpda, "x+y)"));
    BOOST_TEST(accept(dpda, "(x+y)"));
    BOOST_TEST(!accept(dpda, "xy+z"));
    BOOST_TEST(!accept(dpda, "x(y+z)"));
    BOOST_TEST(accept(dpda, "(x+y)*x-z*y/(x+x)"));
    BOOST_TEST(accept(dpda, "x/(y*(z-y)+x)"));
}

void test_02()
{
    DRX10Function function;

    function(0, 'a') = DRX10Function::next_1_type(0, 'S', true);
    function(0, 'b') = DRX10Function::next_1_type(1, 'B', true);
    function(0, 'c', 'S', true) = 2;
    function(1, 'b') = DRX10Function::next_1_type(1, 'B', true);
    function(1, 'c', 'B', true) = 2;
    function(2, 'c', 'S', true) = 2;
    function(2, 'c', 'B', true) = 2;

    DPDA dpda(function);

    BOOST_TEST(dpda.get_state().first.empty());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('a'));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('a'));
    BOOST_TEST(2 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('c'));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(2 == dpda.get_state().second);
    BOOST_TEST(dpda('c'));
    BOOST_TEST(dpda.get_state().first.empty());
    BOOST_TEST(2 == dpda.get_state().second);
    dpda.reset();
    BOOST_TEST(dpda.get_state().first.empty());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('a'));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('b'));
    BOOST_TEST(2 == dpda.get_state().first.size());
    BOOST_TEST('B' == dpda.get_state().first.back());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(dpda('c'));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(2 == dpda.get_state().second);
    BOOST_TEST(dpda('c'));
    BOOST_TEST(dpda.get_state().first.empty());
    BOOST_TEST(2 == dpda.get_state().second);
    dpda.reset();
    BOOST_TEST(dpda.get_state().first.empty());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('a'));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('a'));
    BOOST_TEST(2 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('b'));
    BOOST_TEST(3 == dpda.get_state().first.size());
    BOOST_TEST('B' == dpda.get_state().first.back());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(dpda('c'));
    BOOST_TEST(2 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(2 == dpda.get_state().second);
    BOOST_TEST(dpda('c'));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(2 == dpda.get_state().second);
    BOOST_TEST(dpda('c'));
    BOOST_TEST(dpda.get_state().first.empty());
    BOOST_TEST(2 == dpda.get_state().second);
    dpda.reset();
    BOOST_TEST(dpda.get_state().first.empty());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('a'));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('b'));
    BOOST_TEST(2 == dpda.get_state().first.size());
    BOOST_TEST('B' == dpda.get_state().first.back());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(dpda('b'));
    BOOST_TEST(3 == dpda.get_state().first.size());
    BOOST_TEST('B' == dpda.get_state().first.back());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(dpda('c'));
    BOOST_TEST(2 == dpda.get_state().first.size());
    BOOST_TEST('B' == dpda.get_state().first.back());
    BOOST_TEST(2 == dpda.get_state().second);
    BOOST_TEST(dpda('c'));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('S' == dpda.get_state().first.back());
    BOOST_TEST(2 == dpda.get_state().second);
    BOOST_TEST(dpda('c'));
    BOOST_TEST(dpda.get_state().first.empty());
    BOOST_TEST(2 == dpda.get_state().second);
    BOOST_TEST(!dpda('c'));
    dpda.reset();
    BOOST_TEST(dpda.get_state().first.empty());
    BOOST_TEST(0 == dpda.get_state().second);
    BOOST_TEST(dpda('b'));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('B' == dpda.get_state().first.back());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(dpda('b'));
    BOOST_TEST(2 == dpda.get_state().first.size());
    BOOST_TEST('B' == dpda.get_state().first.back());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(dpda('b'));
    BOOST_TEST(3 == dpda.get_state().first.size());
    BOOST_TEST('B' == dpda.get_state().first.back());
    BOOST_TEST(1 == dpda.get_state().second);
    BOOST_TEST(dpda('c'));
    BOOST_TEST(2 == dpda.get_state().first.size());
    BOOST_TEST('B' == dpda.get_state().first.back());
    BOOST_TEST(2 == dpda.get_state().second);
    BOOST_TEST(dpda('c'));
    BOOST_TEST(1 == dpda.get_state().first.size());
    BOOST_TEST('B' == dpda.get_state().first.back());
    BOOST_TEST(2 == dpda.get_state().second);
    BOOST_TEST(dpda('c'));
    BOOST_TEST(dpda.get_state().first.empty());
    BOOST_TEST(2 == dpda.get_state().second);
    BOOST_TEST(accept(dpda, "aacc"));
    BOOST_TEST(!accept(dpda, "abc"));
    BOOST_TEST(accept(dpda, "aabccc"));
    BOOST_TEST(accept(dpda, "abbccc"));
    BOOST_TEST(!accept(dpda, "abbcccc"));
    BOOST_TEST(accept(dpda, "bbbccc"));
}

int main(int argc, char** argv)
{
    test_00();
    test_01();
    test_02();
    return ::boost::report_errors();
}

