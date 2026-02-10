// Copyright (C) 2011-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__AUTOMATON__TRANSITION_FUNCTION__INPUT_RULE_HPP
#define ODDS_AND_ENDS__AUTOMATON__TRANSITION_FUNCTION__INPUT_RULE_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/declref.hpp>
#include <boost/core/enable_if.hpp>

namespace odds_and_ends { namespace automaton {

    template <typename State>
    struct input_rule_transition_function
    {
        typedef State state_type;

        template <typename InputRule>
        typename ::boost::enable_if<
            ::std::is_same<
                decltype(
                    ::odds_and_ends::static_introspection::declcref<InputRule>()(
                        ::odds_and_ends::static_introspection::declref<state_type>()
                    )
                ),
                state_type
            >,
            bool
        >::type
            operator()(state_type& state, InputRule const& input_rule) const;

        template <typename InputRule>
        typename ::boost::disable_if<
            ::std::is_same<
                decltype(
                    ::odds_and_ends::static_introspection::declcref<InputRule>()(
                        ::odds_and_ends::static_introspection::declref<state_type>()
                    )
                ),
                state_type
            >,
            bool
        >::type
            operator()(state_type& state, InputRule const& input_rule) const;
    };

    template <typename State>
    template <typename InputRule>
    inline typename ::boost::enable_if<
        ::std::is_same<
            decltype(
                ::odds_and_ends::static_introspection::declcref<InputRule>()(
                    ::odds_and_ends::static_introspection::declref<
                        typename input_rule_transition_function<State>::state_type
                    >()
                )
            ),
            typename input_rule_transition_function<State>::state_type
        >,
        bool
    >::type
        input_rule_transition_function<State>::operator()(
            state_type& state,
            InputRule const& input_rule
        ) const
    {
        state = input_rule(state);
        return true;
    }

    template <typename State>
    template <typename InputRule>
    inline typename ::boost::disable_if<
        ::std::is_same<
            decltype(
                ::odds_and_ends::static_introspection::declcref<InputRule>()(
                    ::odds_and_ends::static_introspection::declref<
                        typename input_rule_transition_function<State>::state_type
                    >()
                )
            ),
            typename input_rule_transition_function<State>::state_type
        >,
        bool
    >::type
        input_rule_transition_function<State>::operator()(
            state_type& state,
            InputRule const& input_rule
        ) const
    {
        return input_rule(state);
    }
}}  // namespace odds_and_ends::automaton

#endif  // ODDS_AND_ENDS__AUTOMATON__TRANSITION_FUNCTION__INPUT_RULE_HPP

