// Copyright (C) 2011-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__AUTOMATON__INPUT_RULE__WOLFRAM_CODE_HPP
#define ODDS_AND_ENDS__AUTOMATON__INPUT_RULE__WOLFRAM_CODE_HPP

#include <type_traits>
#include <tuple>
#include <odds_and_ends/node/container/map.hpp>
#include <odds_and_ends/node/balancer/adelson_velskii_landis_tree.hpp>
#include <odds_and_ends/node/with_balance_factor.hpp>
#include <odds_and_ends/use_default_policy.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/assert.hpp>
#include <boost/concept/assert.hpp>
#include <boost/concept_check.hpp>

namespace odds_and_ends { namespace automaton {

    template <typename StateElement, typename ACG = ::odds_and_ends::use_default_policy>
    class wolfram_code_input_rule
    {
        typedef StateElement _state_element_t;
        typedef ::std::tuple<_state_element_t,_state_element_t,_state_element_t> _neighborhood_t;
        typedef typename ::boost::mpl::eval_if<
            ::std::is_same<ACG,::odds_and_ends::use_default_policy>,
            ::boost::mpl::identity<
                ::odds_and_ends::node::container::map<
                    _neighborhood_t,
                    _state_element_t,
                    ::boost::mpl::false_,
                    ::boost::mpl::deque< ::odds_and_ends::node::with_balance_factor>,
                    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer
                >
            >,
            ::boost::mpl::apply2<ACG,_neighborhood_t,_state_element_t>
        >::type _code_t;

    public:
        typedef ::odds_and_ends::automaton::wolfram_code_input_rule<StateElement,ACG> type;

    private:
        class _setter_t
        {
            type& _rule;
            _neighborhood_t _key;

        public:
            _setter_t(
                type& rule,
                _state_element_t const& prior_old_value,
                _state_element_t const& old_value,
                _state_element_t const& next_old_value
            );

            void operator=(_state_element_t const& new_value);
        };

        _code_t _code;
        _state_element_t _blank;

    public:
        wolfram_code_input_rule();
        explicit wolfram_code_input_rule(_state_element_t const& blank);
        void reset();
        void reset(_state_element_t const& blank);

        _setter_t
            operator()(
                _state_element_t const& prior_old_value,
                _state_element_t const& old_value,
                _state_element_t const& next_old_value
            );

        template <typename StateSequence>
        StateSequence operator()(StateSequence const& current_state) const;

    private:
        _state_element_t const&
            _find_element(
                _state_element_t const& e1,
                _state_element_t const& e2,
                _state_element_t const& e3
            ) const;

        template <typename StateSequence>
        void _normalize(StateSequence& next_state) const;
    };

    template <typename StateElement, typename AssocContainerGen>
    inline wolfram_code_input_rule<StateElement,AssocContainerGen>::_setter_t::_setter_t(
        type& rule,
        _state_element_t const& prior_old_value,
        _state_element_t const& old_value,
        _state_element_t const& next_old_value
    ) : _rule(rule), _key(prior_old_value, old_value, next_old_value)
    {
    }

    template <typename StateElement, typename AssocContainerGen>
    inline void
        wolfram_code_input_rule<StateElement,AssocContainerGen>::_setter_t::operator=(
            _state_element_t const& new_value
        )
    {
        this->_rule._code.insert(typename _code_t::value_type(this->_key, new_value));
    }

    template <typename StateElement, typename AssocContainerGen>
    inline wolfram_code_input_rule<StateElement,AssocContainerGen>::wolfram_code_input_rule() :
        _code(), _blank()
    {
    }

    template <typename StateElement, typename AssocContainerGen>
    inline wolfram_code_input_rule<StateElement,AssocContainerGen>::wolfram_code_input_rule(
        _state_element_t const& blank
    ) : _code(), _blank(blank)
    {
    }

    template <typename StateElement, typename AssocContainerGen>
    inline void wolfram_code_input_rule<StateElement,AssocContainerGen>::reset()
    {
        this->_code.clear();
    }

    template <typename StateElement, typename ACG>
    inline void wolfram_code_input_rule<StateElement,ACG>::reset(_state_element_t const& blank)
    {
        this->_code.clear();
        this->_blank = blank;
    }

    template <typename StateElement, typename AssociativeContainerGenerator>
    inline typename wolfram_code_input_rule<StateElement,AssociativeContainerGenerator>::_setter_t
        wolfram_code_input_rule<StateElement,AssociativeContainerGenerator>::operator()(
            _state_element_t const& prior_old_value,
            _state_element_t const& old_value,
            _state_element_t const& next_old_value
        )
    {
        return _setter_t(*this, prior_old_value, old_value, next_old_value);
    }

    template <typename StateElement, typename ACG>
    inline typename wolfram_code_input_rule<StateElement,ACG>::_state_element_t const&
        wolfram_code_input_rule<StateElement,ACG>::_find_element(
            _state_element_t const& e1,
            _state_element_t const& e2,
            _state_element_t const& e3
        ) const
    {
        typename _code_t::const_iterator itr = this->_code.find(_neighborhood_t(e1, e2, e3));

        return (itr == this->_code.end()) ? this->_blank : itr->second;
    }

    template <typename StateElement, typename AssociativeContainerGenerator>
    template <typename StateSequence>
    void
        wolfram_code_input_rule<StateElement,AssociativeContainerGenerator>::_normalize(
            StateSequence& next_state
        ) const
    {
        for (; !next_state.empty() && (next_state.back() == this->_blank); next_state.pop_back())
        {
        }

        for (; !next_state.empty() && (next_state.front() == this->_blank); next_state.pop_front())
        {
        }
    }

    template <typename StateElement, typename AssociativeContainerGenerator>
    template <typename StateSequence>
    StateSequence
        wolfram_code_input_rule<StateElement,AssociativeContainerGenerator>::operator()(
            StateSequence const& current_state
        ) const
    {
//        BOOST_CONCEPT_ASSERT((::boost::FrontInsertionSequence<StateSequence>));
//        BOOST_CONCEPT_ASSERT((::boost::BackInsertionSequence<StateSequence>));
        BOOST_MPL_ASSERT((
            ::std::is_same<
                typename StateSequence::value_type,
                StateElement
            >
        ));

        typename StateSequence::const_iterator itr_0 = current_state.begin();
        typename StateSequence::const_iterator itr_begin = itr_0;
        typename StateSequence::const_iterator itr_end = current_state.end();
        StateSequence next_state(current_state);

        if (itr_0 == itr_end)
        {
            next_state.push_back(this->_find_element(this->_blank, this->_blank, this->_blank));
            this->_normalize(next_state);
            return next_state;
        }

        typename StateSequence::const_iterator itr_1 = itr_0;

        if (++itr_1 == itr_end)
        {
            next_state.push_front(this->_find_element(this->_blank, this->_blank, *itr_0));
            next_state.back() = this->_find_element(this->_blank, *itr_0, this->_blank);
            next_state.push_back(this->_find_element(*itr_0, this->_blank, this->_blank));
            this->_normalize(next_state);
            return next_state;
        }

        typename StateSequence::const_iterator itr_2 = itr_1;

        next_state.front() = this->_find_element(this->_blank, *itr_0, *itr_1);
        next_state.push_front(this->_find_element(this->_blank, this->_blank, *itr_0));

        if (++itr_2 == itr_end)
        {
            next_state.back() = this->_find_element(*itr_0, *itr_1, this->_blank);
            next_state.push_back(this->_find_element(*itr_1, this->_blank, this->_blank));
            this->_normalize(next_state);
            return next_state;
        }

        typename StateSequence::iterator n_itr = next_state.begin();

        ++n_itr;

        do
        {
            *(++n_itr) = this->_find_element(*itr_0, *itr_1, *itr_2);
            ++itr_0;
            ++itr_1;
        }
        while (++itr_2 != itr_end);

        *(++n_itr) = this->_find_element(*itr_0, *itr_1, this->_blank);
        next_state.push_back(this->_find_element(*itr_1, this->_blank, this->_blank));
        this->_normalize(next_state);
        return next_state;
    }
}}  // namespace odds_and_ends::automaton

#endif  // ODDS_AND_ENDS__AUTOMATON__INPUT_RULE__WOLFRAM_CODE_HPP

