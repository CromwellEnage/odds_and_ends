// Copyright (C) 2007-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__AUTOMATON__TRANSITION_FUNCTION__NEXT_STATE_HPP
#define ODDS_AND_ENDS__AUTOMATON__TRANSITION_FUNCTION__NEXT_STATE_HPP

#include <cstddef>
#include <type_traits>
#include <set>
#include <odds_and_ends/node/container/deque.hpp>
#include <odds_and_ends/node/balancer/adelson_velskii_landis_tree.hpp>
#include <odds_and_ends/node/with_balance_factor.hpp>
#include <odds_and_ends/use_default_policy.hpp>
#include <boost/optional/optional.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace automaton {

    template <
        typename Register = ::std::size_t,
        typename AssociativeContainerGenerator = ::odds_and_ends::use_default_policy,
        typename DequeGenerator = ::odds_and_ends::use_default_policy
    >
    class next_state_transition_function
    {
        typedef typename ::boost::mpl::eval_if<
            ::std::is_same<AssociativeContainerGenerator,::odds_and_ends::use_default_policy>,
            ::boost::mpl::identity< ::std::set<Register> >,
            ::boost::mpl::apply1<AssociativeContainerGenerator,Register>
        >::type _x10_t;

    public:
        typedef ::odds_and_ends::automaton::next_state_transition_function<
            Register,
            AssociativeContainerGenerator,
            DequeGenerator
        > type;
        typedef Register state_type;
        typedef state_type input_type;

    private:
        class _setter_t
        {
            type& _function;
            state_type const& _current;

        public:
            _setter_t(type& t, state_type const& current);
            void operator+=(state_type const& next);
        };

        typename ::boost::mpl::eval_if<
            ::std::is_same<DequeGenerator,::odds_and_ends::use_default_policy>,
            ::boost::mpl::identity<
                ::odds_and_ends::node::container::deque<
                    _x10_t,
                    ::boost::mpl::deque< ::odds_and_ends::node::with_balance_factor>,
                    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer,
                    Register
                >
            >,
            ::boost::mpl::apply1<DequeGenerator,_x10_t>
        >::type _transitions;

    public:
        next_state_transition_function();
        void reset();
        bool operator()(state_type& state, input_type const& i) const;
        _setter_t operator()(state_type const& current);

    private:
        template <
            typename R1,
            typename A1,
            typename D1,
            typename R2,
            typename A2,
            typename D2
        >
        friend bool
            operator==(
                next_state_transition_function<R1,A1,D1> const& lhs,
                next_state_transition_function<R2,A2,D2> const& rhs
            );
    };

    template <typename R, typename A, typename D>
    inline next_state_transition_function<R,A,D>::next_state_transition_function() : _transitions()
    {
    }

    template <typename R, typename A, typename D>
    inline void next_state_transition_function<R,A,D>::reset()
    {
        this->_transitions.clear();
    }

    template <typename R, typename A, typename D>
    inline bool
        next_state_transition_function<R,A,D>::operator()(
            state_type& state,
            input_type const& i
        ) const
    {
        if (state < this->_transitions.size())
        {
            _x10_t const& t0_set = this->_transitions[state];

            if (t0_set.find(i) != t0_set.end())
            {
                state = i;
                return true;
            }
        }

        return false;
    }

    template <typename R, typename A, typename D>
    inline next_state_transition_function<R,A,D>::_setter_t::_setter_t(
        type& t,
        state_type const& current
    ) : _function(t), _current(current)
    {
        state_type s = current;

        if (this->_function._transitions.size() < ++s)
        {
            this->_function._transitions.resize(s);
        }
    }

    template <typename R, typename A, typename D>
    inline void next_state_transition_function<R,A,D>::_setter_t::operator+=(state_type const& n)
    {
        state_type s = n;

        if (this->_function._transitions.size() < ++s)
        {
            this->_function._transitions.resize(s);
        }

        this->_function._transitions[this->_current].insert(n);
    }

    template <typename R, typename A, typename D>
    inline typename next_state_transition_function<R,A,D>::_setter_t
        next_state_transition_function<R,A,D>::operator()(state_type const& current)
    {
        return _setter_t(*this, current);
    }
}}  // namespace odds_and_ends::automaton

#include <algorithm>
#include <boost/utility/value_init.hpp>

namespace odds_and_ends { namespace automaton {

    template <
        typename R1,
        typename A1,
        typename D1,
        typename R2,
        typename A2,
        typename D2
    >
    bool
        operator==(
            next_state_transition_function<R1,A1,D1> const& lhs,
            next_state_transition_function<R2,A2,D2> const& rhs
        )
    {
        if (lhs._transitions.size() == rhs._transitions.size())
        {
            for (
                typename next_state_transition_function<R1,A1,D1>::state_type s = (
                    ::boost::initialized_value
                );
                s < lhs._transitions.size();
                ++s
            )
            {
                if (
                    !::std::equal(
                        lhs._transitions[s].cbegin(),
                        lhs._transitions[s].cend(),
                        rhs._transitions[s].cbegin(),
                        rhs._transitions[s].cend()
                    )
                )
                {
                    return false;
                }
            }

            return true;
        }

        return false;
    }

    template <
        typename R1,
        typename A1,
        typename D1,
        typename R2,
        typename A2,
        typename D2
    >
    inline bool
        operator!=(
            next_state_transition_function<R1,A1,D1> const& lhs,
            next_state_transition_function<R2,A2,D2> const& rhs
        )
    {
        return !(lhs == rhs);
    }
}}  // namespace odds_and_ends::automaton

#endif  // ODDS_AND_ENDS__AUTOMATON__TRANSITION_FUNCTION__NEXT_STATE_HPP

