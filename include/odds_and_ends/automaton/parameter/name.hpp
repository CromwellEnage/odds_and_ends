// Copyright (C) 2007-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__AUTOMATON__PARAMETER__NAME_HPP
#define ODDS_AND_ENDS__AUTOMATON__PARAMETER__NAME_HPP

#include <boost/parameter/name.hpp>

namespace odds_and_ends { namespace automaton { namespace parameter {

    BOOST_PARAMETER_NAME(source_state)
    BOOST_PARAMETER_NAME(graph)
    BOOST_PARAMETER_NAME(vertex_state_map)
    BOOST_PARAMETER_NAME(edge_input_map)
    BOOST_PARAMETER_NAME(target)
    BOOST_PARAMETER_NAME(function)
    BOOST_PARAMETER_NAME(input_recognizer)
    BOOST_PARAMETER_NAME(state_recognizer)
    BOOST_PARAMETER_NAME(builder)
    BOOST_PARAMETER_NAME(policies)
    BOOST_PARAMETER_NAME(input_validation_policy)
    BOOST_PARAMETER_NAME(undo_limit)

}}}  // namespace odds_and_ends::automaton::parameter

#endif  // ODDS_AND_ENDS__AUTOMATON__PARAMETER__NAME_HPP

