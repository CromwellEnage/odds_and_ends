// Copyright (C) 2025 Cromwell D. Enage

#include <initializer_list>
#include <cstring>
#include <odds_and_ends/node/container/interval_map.hpp>
#include <boost/core/lightweight_test.hpp>
#include <iostream>

typedef ::odds_and_ends::node::container::interval_map<double,char const*> Num2String;

void test_00()
{
    Num2String score_map(
        ::std::initializer_list<unsigned int>({
            0, 60, 62, 65, 68, 72, 75, 78, 82, 85, 88, 94, 100
        }),
        ::std::initializer_list<char const*>({
            "F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A", "A+"
        })
    );

    BOOST_TEST(score_map.find(-1) == score_map.end());
    BOOST_TEST(score_map.find(111) == score_map.end());
    BOOST_TEST(!::std::strcmp("F", score_map[53.2]));
    BOOST_TEST(!::std::strcmp("D", score_map[61]));
    BOOST_TEST(!::std::strcmp("D+", score_map[64]));
    BOOST_TEST(!::std::strcmp("C-", score_map[66.6]));
    BOOST_TEST(!::std::strcmp("C", score_map[71.4]));
    BOOST_TEST(!::std::strcmp("C+", score_map[73.5]));
    BOOST_TEST(!::std::strcmp("B-", score_map[77.7]));
    BOOST_TEST(!::std::strcmp("B", score_map[80]));
    BOOST_TEST(!::std::strcmp("B+", score_map[83.3]));
    BOOST_TEST(!::std::strcmp("A-", score_map[87.5]));
    BOOST_TEST(!::std::strcmp("A", score_map[91.9]));
    BOOST_TEST(!::std::strcmp("A+", score_map[98.6]));

    Num2String::const_iterator c_fwd_itr = score_map.find(0);

    BOOST_TEST(0 == c_fwd_itr->first.lower());
    BOOST_TEST(60 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("F", c_fwd_itr->second));
    c_fwd_itr = score_map.find(60);
    BOOST_TEST(60 == c_fwd_itr->first.lower());
    BOOST_TEST(62 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("D", c_fwd_itr->second));
    c_fwd_itr = score_map.find(62);
    BOOST_TEST(62 == c_fwd_itr->first.lower());
    BOOST_TEST(65 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("D+", c_fwd_itr->second));
    c_fwd_itr = score_map.find(65);
    BOOST_TEST(65 == c_fwd_itr->first.lower());
    BOOST_TEST(68 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("C-", c_fwd_itr->second));
    c_fwd_itr = score_map.find(68);
    BOOST_TEST(68 == c_fwd_itr->first.lower());
    BOOST_TEST(72 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("C", c_fwd_itr->second));
    c_fwd_itr = score_map.find(72);
    BOOST_TEST(72 == c_fwd_itr->first.lower());
    BOOST_TEST(75 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("C+", c_fwd_itr->second));
    c_fwd_itr = score_map.find(75);
    BOOST_TEST(75 == c_fwd_itr->first.lower());
    BOOST_TEST(78 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("B-", c_fwd_itr->second));
    c_fwd_itr = score_map.find(78);
    BOOST_TEST(78 == c_fwd_itr->first.lower());
    BOOST_TEST(82 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("B", c_fwd_itr->second));
    c_fwd_itr = score_map.find(82);
    BOOST_TEST(82 == c_fwd_itr->first.lower());
    BOOST_TEST(85 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("B+", c_fwd_itr->second));
    c_fwd_itr = score_map.find(85);
    BOOST_TEST(85 == c_fwd_itr->first.lower());
    BOOST_TEST(88 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("A-", c_fwd_itr->second));
    c_fwd_itr = score_map.find(88);
    BOOST_TEST(88 == c_fwd_itr->first.lower());
    BOOST_TEST(94 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("A", c_fwd_itr->second));
    c_fwd_itr = score_map.find(94);
    BOOST_TEST(94 == c_fwd_itr->first.lower());
    BOOST_TEST(100 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("A+", c_fwd_itr->second));
    c_fwd_itr = score_map.cbegin();
    BOOST_TEST(0 == c_fwd_itr->first.lower());
    BOOST_TEST(60 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("F", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(60 == c_fwd_itr->first.lower());
    BOOST_TEST(62 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("D", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(62 == c_fwd_itr->first.lower());
    BOOST_TEST(65 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("D+", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(65 == c_fwd_itr->first.lower());
    BOOST_TEST(68 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("C-", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(68 == c_fwd_itr->first.lower());
    BOOST_TEST(72 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("C", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(72 == c_fwd_itr->first.lower());
    BOOST_TEST(75 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("C+", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(75 == c_fwd_itr->first.lower());
    BOOST_TEST(78 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("B-", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(78 == c_fwd_itr->first.lower());
    BOOST_TEST(82 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("B", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(82 == c_fwd_itr->first.lower());
    BOOST_TEST(85 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("B+", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(85 == c_fwd_itr->first.lower());
    BOOST_TEST(88 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("A-", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(88 == c_fwd_itr->first.lower());
    BOOST_TEST(94 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("A", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(94 == c_fwd_itr->first.lower());
    BOOST_TEST(100 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("A+", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == score_map.cend());

    Num2String copy_map(score_map);
    Num2String::const_reverse_iterator c_rev_itr = copy_map.crbegin();

    BOOST_TEST(94 == c_rev_itr->first.lower());
    BOOST_TEST(100 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("A+", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(88 == c_rev_itr->first.lower());
    BOOST_TEST(94 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("A", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(85 == c_rev_itr->first.lower());
    BOOST_TEST(88 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("A-", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(82 == c_rev_itr->first.lower());
    BOOST_TEST(85 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("B+", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(78 == c_rev_itr->first.lower());
    BOOST_TEST(82 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("B", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(75 == c_rev_itr->first.lower());
    BOOST_TEST(78 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("B-", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(72 == c_rev_itr->first.lower());
    BOOST_TEST(75 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("C+", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(68 == c_rev_itr->first.lower());
    BOOST_TEST(72 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("C", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(65 == c_rev_itr->first.lower());
    BOOST_TEST(68 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("C-", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(62 == c_rev_itr->first.lower());
    BOOST_TEST(65 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("D+", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(60 == c_rev_itr->first.lower());
    BOOST_TEST(62 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("D", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(0 == c_rev_itr->first.lower());
    BOOST_TEST(60 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("F", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == copy_map.crend());
}

void test_01()
{
    Num2String compass(
        ::std::initializer_list<double>({
            0, 11.25, 33.75, 56.25, 78.75, 101.25, 123.75, 146.25, 168.75,
            191.25, 213.75, 236.25, 258.75, 281.25, 303.75, 326.25, 348.75, 360
        }),
        ::std::initializer_list<char const*>({
            "N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE",
            "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW", "N"
        })
    );

    BOOST_TEST(compass.find(-20) == compass.end());
    BOOST_TEST(compass.find(360) == compass.end());
    BOOST_TEST(!::std::strcmp("N", compass[5]));
    BOOST_TEST(!::std::strcmp("NNE", compass[22.5]));
    BOOST_TEST(!::std::strcmp("NE", compass[45]));
    BOOST_TEST(!::std::strcmp("ENE", compass[67.5]));
    BOOST_TEST(!::std::strcmp("E", compass[90]));
    BOOST_TEST(!::std::strcmp("ESE", compass[112.5]));
    BOOST_TEST(!::std::strcmp("SE", compass[135]));
    BOOST_TEST(!::std::strcmp("SSE", compass[157.5]));
    BOOST_TEST(!::std::strcmp("S", compass[180]));
    BOOST_TEST(!::std::strcmp("SSW", compass[202.5]));
    BOOST_TEST(!::std::strcmp("SW", compass[225]));
    BOOST_TEST(!::std::strcmp("WSW", compass[247.5]));
    BOOST_TEST(!::std::strcmp("W", compass[270]));
    BOOST_TEST(!::std::strcmp("WNW", compass[292.5]));
    BOOST_TEST(!::std::strcmp("NW", compass[315]));
    BOOST_TEST(!::std::strcmp("NNW", compass[337.5]));
    BOOST_TEST(!::std::strcmp("N", compass[357]));

    Num2String::const_iterator c_fwd_itr = compass.cbegin();

    BOOST_TEST(0 == c_fwd_itr->first.lower());
    BOOST_TEST(11.25 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("N", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(11.25 == c_fwd_itr->first.lower());
    BOOST_TEST(33.75 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("NNE", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(33.75 == c_fwd_itr->first.lower());
    BOOST_TEST(56.25 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("NE", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(56.25 == c_fwd_itr->first.lower());
    BOOST_TEST(78.75 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("ENE", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(78.75 == c_fwd_itr->first.lower());
    BOOST_TEST(101.25 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("E", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(101.25 == c_fwd_itr->first.lower());
    BOOST_TEST(123.75 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("ESE", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(123.75 == c_fwd_itr->first.lower());
    BOOST_TEST(146.25 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("SE", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(146.25 == c_fwd_itr->first.lower());
    BOOST_TEST(168.75 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("SSE", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(168.75 == c_fwd_itr->first.lower());
    BOOST_TEST(191.25 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("S", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(191.25 == c_fwd_itr->first.lower());
    BOOST_TEST(213.75 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("SSW", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(213.75 == c_fwd_itr->first.lower());
    BOOST_TEST(236.25 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("SW", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(236.25 == c_fwd_itr->first.lower());
    BOOST_TEST(258.75 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("WSW", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(258.75 == c_fwd_itr->first.lower());
    BOOST_TEST(281.25 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("W", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(281.25 == c_fwd_itr->first.lower());
    BOOST_TEST(303.75 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("WNW", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(303.75 == c_fwd_itr->first.lower());
    BOOST_TEST(326.25 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("NW", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(326.25 == c_fwd_itr->first.lower());
    BOOST_TEST(348.75 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("NNW", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(348.75 == c_fwd_itr->first.lower());
    BOOST_TEST(360 == c_fwd_itr->first.upper());
    BOOST_TEST(!::std::strcmp("N", c_fwd_itr->second));
    ++c_fwd_itr;
    BOOST_TEST(c_fwd_itr == compass.cend());

    Num2String copy_map(compass);
    Num2String::const_reverse_iterator c_rev_itr = copy_map.crbegin();

    BOOST_TEST(348.75 == c_rev_itr->first.lower());
    BOOST_TEST(360 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("N", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(326.25 == c_rev_itr->first.lower());
    BOOST_TEST(348.75 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("NNW", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(303.75 == c_rev_itr->first.lower());
    BOOST_TEST(326.25 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("NW", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(281.25 == c_rev_itr->first.lower());
    BOOST_TEST(303.75 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("WNW", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(258.75 == c_rev_itr->first.lower());
    BOOST_TEST(281.25 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("W", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(236.25 == c_rev_itr->first.lower());
    BOOST_TEST(258.75 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("WSW", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(213.75 == c_rev_itr->first.lower());
    BOOST_TEST(236.25 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("SW", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(191.25 == c_rev_itr->first.lower());
    BOOST_TEST(213.75 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("SSW", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(168.75 == c_rev_itr->first.lower());
    BOOST_TEST(191.25 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("S", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(146.25 == c_rev_itr->first.lower());
    BOOST_TEST(168.75 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("SSE", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(123.75 == c_rev_itr->first.lower());
    BOOST_TEST(146.25 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("SE", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(101.25 == c_rev_itr->first.lower());
    BOOST_TEST(123.75 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("ESE", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(78.75 == c_rev_itr->first.lower());
    BOOST_TEST(101.25 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("E", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(56.25 == c_rev_itr->first.lower());
    BOOST_TEST(78.75 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("ENE", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(33.75 == c_rev_itr->first.lower());
    BOOST_TEST(56.25 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("NE", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(11.25 == c_rev_itr->first.lower());
    BOOST_TEST(33.75 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("NNE", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(0 == c_rev_itr->first.lower());
    BOOST_TEST(11.25 == c_rev_itr->first.upper());
    BOOST_TEST(!::std::strcmp("N", c_rev_itr->second));
    ++c_rev_itr;
    BOOST_TEST(c_rev_itr == copy_map.crend());
}

int main(int argc, char** argv)
{
    test_00();
    test_01();
    return ::boost::report_errors();
}

