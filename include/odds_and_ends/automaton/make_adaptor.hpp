// Copyright (C) 2007-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__AUTOMATON__MAKE_ADAPTOR_HPP
#define ODDS_AND_ENDS__AUTOMATON__MAKE_ADAPTOR_HPP

#include <type_traits>
#include <odds_and_ends/automaton/transition_function/adaptor.hpp>
#include <odds_and_ends/automaton/base.hpp>
#include <odds_and_ends/composite_type/composite_type.hpp>
#include <boost/mpl/deque.hpp>

namespace odds_and_ends { namespace automaton {

    template <typename Function>
    inline ::odds_and_ends::composite_type::composite_type<
        ::boost::mpl::deque<
            ::odds_and_ends::automaton::base<
                ::odds_and_ends::automaton::adaptor_transition_function<
                    typename ::std::remove_reference<
                        typename ::std::remove_pointer<Function>::type
                    >::type
                >
            >
        >
    >
        make_adaptor(Function f)
    {
        return ::odds_and_ends::composite_type::composite_type<
            ::boost::mpl::deque<
                ::odds_and_ends::automaton::base<
                    ::odds_and_ends::automaton::adaptor_transition_function<
                        typename ::std::remove_reference<
                            typename ::std::remove_pointer<Function>::type
                        >::type
                    >
                >
            >
        >(f);
    }

    template <typename Function>
    inline ::odds_and_ends::composite_type::composite_type<
        ::boost::mpl::deque<
            ::odds_and_ends::automaton::base<
                ::odds_and_ends::automaton::adaptor_transition_function<
                    typename ::std::remove_reference<
                        typename ::std::remove_pointer<Function>::type
                    >::type
                >
            >
        >
    >
        make_adaptor(
            Function f,
            typename ::odds_and_ends::automaton::adaptor_transition_function<
                typename ::std::remove_reference<
                    typename ::std::remove_pointer<Function>::type
                >::type
            >::state_type const& s
        )
    {
        return ::odds_and_ends::composite_type::composite_type<
            ::boost::mpl::deque<
                ::odds_and_ends::automaton::base<
                    ::odds_and_ends::automaton::adaptor_transition_function<
                        typename ::std::remove_reference<
                            typename ::std::remove_pointer<Function>::type
                        >::type
                    >
                >
            >
        >(f, s);
    }
}}  // namespace odds_and_ends::automaton

#endif  // ODDS_AND_ENDS__AUTOMATON__MAKE_ADAPTOR_HPP

