// Copyright (C) 2007-2026 Cromwell D. Enage

#include <boost/rational.hpp>

typedef ::boost::rational<unsigned int> R;

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>

::boost::numeric::ublas::vector<R>
    ublas_product(
        ::boost::numeric::ublas::vector<R> const& v,
        ::boost::numeric::ublas::matrix<R> const& m
    )
{
    return ::boost::numeric::ublas::prod(v, m);
}

#include <utility>
#include <vector>
#include <boost/core/lightweight_test.hpp>

template <typename MarkovChain>
void
    run(
        MarkovChain markov_chain,
        ::boost::numeric::ublas::matrix<R> const& m,
        ::std::vector< ::std::pair<R,R> > tests
    )
{
    for (::std::size_t i = 0; i < tests.size(); ++i)
    {
        markov_chain(m);
        BOOST_TEST(markov_chain.get_state()(0) == tests[i].first);
        BOOST_TEST(markov_chain.get_state()(1) == tests[i].second);
    }
}

#include <odds_and_ends/automaton/make_adaptor.hpp>

int main()
{
    ::boost::numeric::ublas::matrix<R> m(2, 2);

    m(0, 0) = R(9, 10);
    m(0, 1) = R(1, 10);
    m(1, 0) = R(1, 2);
    m(1, 1) = R(1, 2);

    ::boost::numeric::ublas::vector<R> v(2);

    v(0) = R(1, 1);
    v(1) = R(0, 1);
    run(
        ::odds_and_ends::automaton::make_adaptor(ublas_product, v),
        m,
        {
            {R(9, 10), R(1, 10)},
            {R(43, 50), R(7, 50)},
            {R(211, 250), R(39, 250)},
            {R(1047, 1250), R(203, 1250)},
            {R(5219, 6250), R(1031, 6250)},
            {R(26063, 31250), R(5187, 31250)},
            {R(130251, 156250), R(25999, 156250)},
            {R(651127, 781250), R(130123, 781250)},
            {R(3255379, 3906250), R(650871, 3906250)},
            {R(16276383, 19531250), R(3254867, 19531250)}
        }
    );
    return ::boost::report_errors();
}

