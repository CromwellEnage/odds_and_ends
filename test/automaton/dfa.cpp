// Copyright (C) 2007-2026 Cromwell D. Enage

#include <cstddef>
#include <odds_and_ends/automaton/transition_function/matrix.hpp>
#include <boost/numeric/ublas/matrix.hpp>

typedef ::odds_and_ends::automaton::matrix_transition_function<
    ::boost::numeric::ublas::matrix< ::std::size_t>
> MatrixTransitionFunction;

#include <set>
#include <iterator>
#include <algorithm>
#include <boost/core/lightweight_test.hpp>

void
    test_matrix_transition_function(
        MatrixTransitionFunction const& transition_function,
        MatrixTransitionFunction::state_type const& state,
        std::set<unsigned int> correct_inputs
    )
{
    std::set<unsigned int> inputs;
    std::insert_iterator<std::set<unsigned int> > itr(inputs, inputs.begin());

    transition_function.make_nontrivial_inputs(state, itr);
    BOOST_TEST(::std::equal(inputs.begin(), inputs.end(), correct_inputs.begin()));
    inputs.clear();
}

#include <odds_and_ends/automaton/base.hpp>
#include <odds_and_ends/composite_type/composite_type.hpp>
#include <boost/mpl/deque.hpp>

void test_00()
{
    typedef ::odds_and_ends::composite_type::composite_type<
        ::boost::mpl::deque< ::odds_and_ends::automaton::base<MatrixTransitionFunction> >
    > DFA;

    MatrixTransitionFunction transition_function(4, 4);

    transition_function(0, 0) = 1;
    transition_function(0, 1) = 1;
    transition_function(0, 2) = 2;
    transition_function(1, 1) = 2;
    transition_function(1, 2) = 0;
    transition_function(2, 3) = 3;

    DFA dfa(transition_function);

    BOOST_TEST(0 == dfa.get_state());
    test_matrix_transition_function(transition_function, dfa.get_state(), {0, 1, 2});
    BOOST_TEST(dfa(0));
    BOOST_TEST(1 == dfa.get_state());
    test_matrix_transition_function(transition_function, dfa.get_state(), {1, 2});
    BOOST_TEST(dfa(2));
    BOOST_TEST(0 == dfa.get_state());
    BOOST_TEST(dfa(1));
    BOOST_TEST(1 == dfa.get_state());
    BOOST_TEST(!dfa(3));
    BOOST_TEST(1 == dfa.get_state());
    BOOST_TEST(dfa(1));
    BOOST_TEST(2 == dfa.get_state());
    test_matrix_transition_function(transition_function, dfa.get_state(), {3});
    BOOST_TEST(dfa(3));
    BOOST_TEST(3 == dfa.get_state());
    test_matrix_transition_function(transition_function, dfa.get_state(), std::set<unsigned int>());
    dfa.reset();
    BOOST_TEST(0 == dfa.get_state());
}

#include <string>
#include <odds_and_ends/automaton/transition_function/register.hpp>

typedef ::odds_and_ends::automaton::register_transition_function<
    ::std::string
> RegisterTransitionFunction;

void test_01()
{
    typedef ::odds_and_ends::composite_type::composite_type<
        ::boost::mpl::deque< ::odds_and_ends::automaton::base<RegisterTransitionFunction> >
    > DFA;

    RegisterTransitionFunction transition_function;

    transition_function(0, "alpha") = 1;
    transition_function(0, "beta") = 1;
    transition_function(0, "gamma") = 2;
    transition_function(1, "beta") = 2;
    transition_function(1, "gamma") = 0;
    transition_function(2, "delta") = 3;

    DFA dfa(transition_function);

    BOOST_TEST(0 == dfa.get_state());
    BOOST_TEST(dfa("alpha"));
    BOOST_TEST(1 == dfa.get_state());
    BOOST_TEST(dfa("gamma"));
    BOOST_TEST(0 == dfa.get_state());
    BOOST_TEST(dfa("beta"));
    BOOST_TEST(1 == dfa.get_state());
    BOOST_TEST(!dfa("delta"));
    BOOST_TEST(1 == dfa.get_state());
    BOOST_TEST(dfa("beta"));
    BOOST_TEST(2 == dfa.get_state());
    BOOST_TEST(dfa("delta"));
    BOOST_TEST(3 == dfa.get_state());
}

#include <odds_and_ends/automaton/transition_function/next_state.hpp>

typedef ::odds_and_ends::automaton::next_state_transition_function<> NextStateTransitionFunction;

void test_02()
{
    typedef ::odds_and_ends::composite_type::composite_type<
        ::boost::mpl::deque< ::odds_and_ends::automaton::base<NextStateTransitionFunction> >
    > DFA;

    NextStateTransitionFunction transition_function;

    transition_function(0) += 1;
    transition_function(0) += 2;
    transition_function(0) += 4;
    transition_function(1) += 0;
    transition_function(1) += 2;
    transition_function(1) += 3;
    transition_function(2) += 3;
    transition_function(2) += 4;
    transition_function(3) += 0;
    transition_function(3) += 1;
    transition_function(3) += 2;
    transition_function(4) += 0;
    transition_function(4) += 3;
    transition_function(4) += 5;

    DFA dfa(transition_function);

    BOOST_TEST(0 == dfa.get_state());
    BOOST_TEST(!dfa(3));
    BOOST_TEST(0 == dfa.get_state());
    BOOST_TEST(dfa(2));
    BOOST_TEST(2 == dfa.get_state());
    BOOST_TEST(!dfa(0));
    BOOST_TEST(2 == dfa.get_state());
    BOOST_TEST(dfa(4));
    BOOST_TEST(4 == dfa.get_state());
    BOOST_TEST(!dfa(1));
    BOOST_TEST(4 == dfa.get_state());
    BOOST_TEST(dfa(0));
    BOOST_TEST(0 == dfa.get_state());
    BOOST_TEST(dfa(1));
    BOOST_TEST(1 == dfa.get_state());
    BOOST_TEST(dfa(3));
    BOOST_TEST(3 == dfa.get_state());
    BOOST_TEST(!dfa(4));
    BOOST_TEST(3 == dfa.get_state());
    BOOST_TEST(dfa(2));
    BOOST_TEST(2 == dfa.get_state());
    BOOST_TEST(!dfa(1));
    BOOST_TEST(2 == dfa.get_state());
    BOOST_TEST(dfa(4));
    BOOST_TEST(4 == dfa.get_state());
    BOOST_TEST(!dfa(2));
    BOOST_TEST(4 == dfa.get_state());
    BOOST_TEST(dfa(3));
    BOOST_TEST(3 == dfa.get_state());
    BOOST_TEST(dfa(1));
    BOOST_TEST(1 == dfa.get_state());
    BOOST_TEST(!dfa(4));
    BOOST_TEST(1 == dfa.get_state());
    BOOST_TEST(dfa(0));
    BOOST_TEST(0 == dfa.get_state());
    BOOST_TEST(dfa(4));
    BOOST_TEST(4 == dfa.get_state());
    BOOST_TEST(dfa(5));
    BOOST_TEST(5 == dfa.get_state());
}

int main(int argc, char** argv)
{
    test_00();
    test_01();
    test_02();
    return ::boost::report_errors();
}

