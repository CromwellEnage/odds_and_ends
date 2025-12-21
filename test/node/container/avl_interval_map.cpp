// Copyright (C) 2025 Cromwell D. Enage

#include <string>
#include <odds_and_ends/node/container/interval_map.hpp>
#include <odds_and_ends/node/balancer/adelson_velskii_landis_tree.hpp>
#include <odds_and_ends/node/with_balance_factor.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/core/lightweight_test.hpp>

typedef ::odds_and_ends::node::container::interval_map<
    double,
    ::std::string,
    ::boost::mpl::deque< ::odds_and_ends::node::with_balance_factor>,
    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer
> GradeMap;

int main(int argc, char** argv)
{
    GradeMap grade_map = {0, 60, 62, 65, 68, 72, 75, 78, 82, 85, 88, 94, 100};

    BOOST_TEST(grade_map.find(-1) == grade_map.end());
    BOOST_TEST(grade_map.find(111) == grade_map.end());
    grade_map.find(53.2)->second = "F";
    grade_map.find(61)->second = "D";
    grade_map.find(64)->second = "D+";
    grade_map.find(66.6)->second = "C-";
    grade_map.find(71.4)->second = "C";
    grade_map.find(73.5)->second = "C+";
    grade_map.find(77.7)->second = "B-";
    grade_map.find(80)->second = "B";
    grade_map.find(83.3)->second = "B+";
    grade_map.find(87.5)->second = "A-";
    grade_map.find(91.9)->second = "A";
    grade_map.find(98.6)->second = "A+";

    GradeMap::const_iterator c_fwd_itr = grade_map.find(0);

    BOOST_TEST(0 == c_fwd_itr->first.lower());
    BOOST_TEST(60 == c_fwd_itr->first.upper());
    BOOST_TEST(::std::string("F") == c_fwd_itr->second);
    c_fwd_itr = grade_map.find(60);
    BOOST_TEST(60 == c_fwd_itr->first.lower());
    BOOST_TEST(62 == c_fwd_itr->first.upper());
    BOOST_TEST(::std::string("D") == c_fwd_itr->second);
    c_fwd_itr = grade_map.find(62);
    BOOST_TEST(62 == c_fwd_itr->first.lower());
    BOOST_TEST(65 == c_fwd_itr->first.upper());
    BOOST_TEST(::std::string("D+") == c_fwd_itr->second);
    c_fwd_itr = grade_map.find(65);
    BOOST_TEST(65 == c_fwd_itr->first.lower());
    BOOST_TEST(68 == c_fwd_itr->first.upper());
    BOOST_TEST(::std::string("C-") == c_fwd_itr->second);
    c_fwd_itr = grade_map.find(68);
    BOOST_TEST(68 == c_fwd_itr->first.lower());
    BOOST_TEST(72 == c_fwd_itr->first.upper());
    BOOST_TEST(::std::string("C") == c_fwd_itr->second);
    c_fwd_itr = grade_map.find(72);
    BOOST_TEST(72 == c_fwd_itr->first.lower());
    BOOST_TEST(75 == c_fwd_itr->first.upper());
    BOOST_TEST(::std::string("C+") == c_fwd_itr->second);
    c_fwd_itr = grade_map.find(75);
    BOOST_TEST(75 == c_fwd_itr->first.lower());
    BOOST_TEST(78 == c_fwd_itr->first.upper());
    BOOST_TEST(::std::string("B-") == c_fwd_itr->second);
    c_fwd_itr = grade_map.find(78);
    BOOST_TEST(78 == c_fwd_itr->first.lower());
    BOOST_TEST(82 == c_fwd_itr->first.upper());
    BOOST_TEST(::std::string("B") == c_fwd_itr->second);
    c_fwd_itr = grade_map.find(82);
    BOOST_TEST(82 == c_fwd_itr->first.lower());
    BOOST_TEST(85 == c_fwd_itr->first.upper());
    BOOST_TEST(::std::string("B+") == c_fwd_itr->second);
    c_fwd_itr = grade_map.find(85);
    BOOST_TEST(85 == c_fwd_itr->first.lower());
    BOOST_TEST(88 == c_fwd_itr->first.upper());
    BOOST_TEST(::std::string("A-") == c_fwd_itr->second);
    c_fwd_itr = grade_map.find(88);
    BOOST_TEST(88 == c_fwd_itr->first.lower());
    BOOST_TEST(94 == c_fwd_itr->first.upper());
    BOOST_TEST(::std::string("A") == c_fwd_itr->second);
    c_fwd_itr = grade_map.find(94);
    BOOST_TEST(94 == c_fwd_itr->first.lower());
    BOOST_TEST(100 == c_fwd_itr->first.upper());
    BOOST_TEST(::std::string("A+") == c_fwd_itr->second);
    c_fwd_itr = grade_map.cbegin();
    BOOST_TEST(0 == c_fwd_itr->first.lower());
    BOOST_TEST(60 == c_fwd_itr->first.upper());
    BOOST_TEST(::std::string("F") == c_fwd_itr->second);
    ++c_fwd_itr;
    BOOST_TEST(60 == c_fwd_itr->first.lower());
    BOOST_TEST(62 == c_fwd_itr->first.upper());
    BOOST_TEST(::std::string("D") == c_fwd_itr->second);
    ++c_fwd_itr;
    BOOST_TEST(62 == c_fwd_itr->first.lower());
    BOOST_TEST(65 == c_fwd_itr->first.upper());
    BOOST_TEST(::std::string("D+") == c_fwd_itr->second);
    ++c_fwd_itr;
    BOOST_TEST(65 == c_fwd_itr->first.lower());
    BOOST_TEST(68 == c_fwd_itr->first.upper());
    BOOST_TEST(::std::string("C-") == c_fwd_itr->second);
    ++c_fwd_itr;
    BOOST_TEST(68 == c_fwd_itr->first.lower());
    BOOST_TEST(72 == c_fwd_itr->first.upper());
    BOOST_TEST(::std::string("C") == c_fwd_itr->second);
    ++c_fwd_itr;
    BOOST_TEST(72 == c_fwd_itr->first.lower());
    BOOST_TEST(75 == c_fwd_itr->first.upper());
    BOOST_TEST(::std::string("C+") == c_fwd_itr->second);
    ++c_fwd_itr;
    BOOST_TEST(75 == c_fwd_itr->first.lower());
    BOOST_TEST(78 == c_fwd_itr->first.upper());
    BOOST_TEST(::std::string("B-") == c_fwd_itr->second);
    ++c_fwd_itr;
    BOOST_TEST(78 == c_fwd_itr->first.lower());
    BOOST_TEST(82 == c_fwd_itr->first.upper());
    BOOST_TEST(::std::string("B") == c_fwd_itr->second);
    ++c_fwd_itr;
    BOOST_TEST(82 == c_fwd_itr->first.lower());
    BOOST_TEST(85 == c_fwd_itr->first.upper());
    BOOST_TEST(::std::string("B+") == c_fwd_itr->second);
    ++c_fwd_itr;
    BOOST_TEST(85 == c_fwd_itr->first.lower());
    BOOST_TEST(88 == c_fwd_itr->first.upper());
    BOOST_TEST(::std::string("A-") == c_fwd_itr->second);
    ++c_fwd_itr;
    BOOST_TEST(88 == c_fwd_itr->first.lower());
    BOOST_TEST(94 == c_fwd_itr->first.upper());
    BOOST_TEST(::std::string("A") == c_fwd_itr->second);
    ++c_fwd_itr;
    BOOST_TEST(94 == c_fwd_itr->first.lower());
    BOOST_TEST(100 == c_fwd_itr->first.upper());
    BOOST_TEST(::std::string("A+") == c_fwd_itr->second);
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == grade_map.cend());

    GradeMap copy_map(grade_map);
    GradeMap::const_reverse_iterator c_rev_itr = copy_map.crbegin();

    BOOST_TEST(94 == c_rev_itr->first.lower());
    BOOST_TEST(100 == c_rev_itr->first.upper());
    BOOST_TEST(::std::string("A+") == c_rev_itr->second);
    ++c_rev_itr;
    BOOST_TEST(88 == c_rev_itr->first.lower());
    BOOST_TEST(94 == c_rev_itr->first.upper());
    BOOST_TEST(::std::string("A") == c_rev_itr->second);
    ++c_rev_itr;
    BOOST_TEST(85 == c_rev_itr->first.lower());
    BOOST_TEST(88 == c_rev_itr->first.upper());
    BOOST_TEST(::std::string("A-") == c_rev_itr->second);
    ++c_rev_itr;
    BOOST_TEST(82 == c_rev_itr->first.lower());
    BOOST_TEST(85 == c_rev_itr->first.upper());
    BOOST_TEST(::std::string("B+") == c_rev_itr->second);
    ++c_rev_itr;
    BOOST_TEST(78 == c_rev_itr->first.lower());
    BOOST_TEST(82 == c_rev_itr->first.upper());
    BOOST_TEST(::std::string("B") == c_rev_itr->second);
    ++c_rev_itr;
    BOOST_TEST(75 == c_rev_itr->first.lower());
    BOOST_TEST(78 == c_rev_itr->first.upper());
    BOOST_TEST(::std::string("B-") == c_rev_itr->second);
    ++c_rev_itr;
    BOOST_TEST(72 == c_rev_itr->first.lower());
    BOOST_TEST(75 == c_rev_itr->first.upper());
    BOOST_TEST(::std::string("C+") == c_rev_itr->second);
    ++c_rev_itr;
    BOOST_TEST(68 == c_rev_itr->first.lower());
    BOOST_TEST(72 == c_rev_itr->first.upper());
    BOOST_TEST(::std::string("C") == c_rev_itr->second);
    ++c_rev_itr;
    BOOST_TEST(65 == c_rev_itr->first.lower());
    BOOST_TEST(68 == c_rev_itr->first.upper());
    BOOST_TEST(::std::string("C-") == c_rev_itr->second);
    ++c_rev_itr;
    BOOST_TEST(62 == c_rev_itr->first.lower());
    BOOST_TEST(65 == c_rev_itr->first.upper());
    BOOST_TEST(::std::string("D+") == c_rev_itr->second);
    ++c_rev_itr;
    BOOST_TEST(60 == c_rev_itr->first.lower());
    BOOST_TEST(62 == c_rev_itr->first.upper());
    BOOST_TEST(::std::string("D") == c_rev_itr->second);
    ++c_rev_itr;
    BOOST_TEST(0 == c_rev_itr->first.lower());
    BOOST_TEST(60 == c_rev_itr->first.upper());
    BOOST_TEST(::std::string("F") == c_rev_itr->second);
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == copy_map.crend());
    return ::boost::report_errors();
}

