// Copyright (C) 2007-2026 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <cstddef>
#include <odds_and_ends/automaton/transition_function/deque_register.hpp>

typedef ::odds_and_ends::automaton::deque_register_transition_function<char,char> DRX10Function;

#include <odds_and_ends/automaton/base.hpp>
#include <odds_and_ends/composite_type/composite_type.hpp>
#include <boost/mpl/deque.hpp>

typedef ::odds_and_ends::composite_type::composite_type<
    ::boost::mpl::deque< ::odds_and_ends::automaton::base<DRX10Function> >
> QueueAutomaton;

#include <string>

bool accept(QueueAutomaton& queue_automaton, ::std::string const& word)
{
    queue_automaton.reset();

    for (::std::size_t i = 0; i < word.length(); )
    {
        if (queue_automaton(word[i]))
        {
            ++i;
        }
        else
        {
            return false;
        }
    }

    return queue_automaton.get_state().first.empty();
}

#include <boost/core/lightweight_test.hpp>

void test_00()
{
    DRX10Function function;

    function(0, 'a') = DRX10Function::next_1_type(1, 'x', false);
    function(1, 'a') = DRX10Function::next_1_type(1, 'x', false);
    function(1, 'b', 'x', true) = DRX10Function::next_1_type(2, 'y', false);
    function(2, 'b', 'x', true) = DRX10Function::next_1_type(2, 'y', false);
    function(2, 'c', 'y', true) = 3;
    function(3, 'c', 'y', true) = 3;

    QueueAutomaton queue_automaton(function);

    BOOST_TEST(queue_automaton.get_state().first.empty());
    BOOST_TEST(0 == queue_automaton.get_state().second);
    BOOST_TEST(queue_automaton('a'));
    BOOST_TEST(1 == queue_automaton.get_state().first.size());
    BOOST_TEST('x' == queue_automaton.get_state().first.front());
    BOOST_TEST('x' == queue_automaton.get_state().first.back());
    BOOST_TEST(1 == queue_automaton.get_state().second);
    BOOST_TEST(queue_automaton('a'));
    BOOST_TEST(2 == queue_automaton.get_state().first.size());
    BOOST_TEST('x' == queue_automaton.get_state().first.front());
    BOOST_TEST('x' == queue_automaton.get_state().first.back());
    BOOST_TEST(1 == queue_automaton.get_state().second);
    BOOST_TEST(queue_automaton('a'));
    BOOST_TEST(3 == queue_automaton.get_state().first.size());
    BOOST_TEST('x' == queue_automaton.get_state().first.front());
    BOOST_TEST('x' == queue_automaton.get_state().first.back());
    BOOST_TEST(1 == queue_automaton.get_state().second);
    BOOST_TEST(!queue_automaton('c'));
    BOOST_TEST(queue_automaton('b'));
    BOOST_TEST(3 == queue_automaton.get_state().first.size());
    BOOST_TEST('y' == queue_automaton.get_state().first.front());
    BOOST_TEST('x' == queue_automaton.get_state().first.back());
    BOOST_TEST(2 == queue_automaton.get_state().second);
    BOOST_TEST(!queue_automaton('a'));
    BOOST_TEST(queue_automaton('b'));
    BOOST_TEST(3 == queue_automaton.get_state().first.size());
    BOOST_TEST('y' == queue_automaton.get_state().first.front());
    BOOST_TEST('x' == queue_automaton.get_state().first.back());
    BOOST_TEST(2 == queue_automaton.get_state().second);
    BOOST_TEST(queue_automaton('b'));
    BOOST_TEST(3 == queue_automaton.get_state().first.size());
    BOOST_TEST('y' == queue_automaton.get_state().first.front());
    BOOST_TEST('y' == queue_automaton.get_state().first.back());
    BOOST_TEST(2 == queue_automaton.get_state().second);
    BOOST_TEST(queue_automaton('c'));
    BOOST_TEST(2 == queue_automaton.get_state().first.size());
    BOOST_TEST('y' == queue_automaton.get_state().first.front());
    BOOST_TEST('y' == queue_automaton.get_state().first.back());
    BOOST_TEST(3 == queue_automaton.get_state().second);
    BOOST_TEST(queue_automaton('c'));
    BOOST_TEST(1 == queue_automaton.get_state().first.size());
    BOOST_TEST('y' == queue_automaton.get_state().first.front());
    BOOST_TEST('y' == queue_automaton.get_state().first.back());
    BOOST_TEST(3 == queue_automaton.get_state().second);
    BOOST_TEST(queue_automaton('c'));
    BOOST_TEST(queue_automaton.get_state().first.empty());
    BOOST_TEST(3 == queue_automaton.get_state().second);
    queue_automaton.reset();
    BOOST_TEST(!accept(queue_automaton, "aab"));
    BOOST_TEST(accept(queue_automaton, "abc"));
    BOOST_TEST(!accept(queue_automaton, "aabcc"));
    BOOST_TEST(accept(queue_automaton, "aabbcc"));
}

int main(int argc, char** argv)
{
    test_00();
    return ::boost::report_errors();
}

