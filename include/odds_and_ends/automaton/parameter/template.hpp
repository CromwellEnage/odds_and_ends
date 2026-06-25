// Copyright (C) 2007-2026 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef ODDS_AND_ENDS__AUTOMATON__PARAMETER__TEMPLATE_HPP
#define ODDS_AND_ENDS__AUTOMATON__PARAMETER__TEMPLATE_HPP

#include <boost/parameter/template_keyword.hpp>

namespace odds_and_ends { namespace automaton { namespace parameter {
    namespace tag {

        struct _probability;
        struct _entropy_addend;
    }  // namespace tag

    template <typename T>
    struct _probability :
        ::boost::parameter::template_keyword<
            ::odds_and_ends::automaton::parameter::tag::_probability,
            T
        >
    {
    };

    template <typename T>
    struct _entropy_addend :
        ::boost::parameter::template_keyword<
            ::odds_and_ends::automaton::parameter::tag::_entropy_addend,
            T
        >
    {
    };
}}}  // namespace odds_and_ends::automaton::parameter

#endif  // ODDS_AND_ENDS__AUTOMATON__PARAMETER__TEMPLATE_HPP

