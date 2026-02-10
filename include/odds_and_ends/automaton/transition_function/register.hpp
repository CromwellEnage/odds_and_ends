// Copyright (C) 2007-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__AUTOMATON__TRANSITION_FUNCTION__REGISTER_HPP
#define ODDS_AND_ENDS__AUTOMATON__TRANSITION_FUNCTION__REGISTER_HPP

#include <cstddef>
#include <type_traits>
#include <odds_and_ends/node/container/deque.hpp>
#include <odds_and_ends/node/container/map.hpp>
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
        typename Input,
        typename Register = ::std::size_t,
        typename AssociativeContainerGenerator = ::odds_and_ends::use_default_policy,
        typename DequeGenerator = ::odds_and_ends::use_default_policy
    >
    class register_transition_function
    {
        typedef typename ::boost::mpl::eval_if<
            ::std::is_same<AssociativeContainerGenerator,::odds_and_ends::use_default_policy>,
            ::boost::mpl::identity<
                ::odds_and_ends::node::container::map<
                    Input,
                    Register,
                    ::boost::mpl::false_,
                    ::boost::mpl::deque< ::odds_and_ends::node::with_balance_factor>,
                    ::odds_and_ends::node::adelson_velskii_landis_tree_balancer
                >
            >,
            ::boost::mpl::apply2<AssociativeContainerGenerator,Input,Register>
        >::type _x10_t;

    public:
        typedef ::odds_and_ends::automaton::register_transition_function<
            Input,
            Register,
            AssociativeContainerGenerator,
            DequeGenerator
        > type;
        typedef Register state_type;
        typedef Input input_type;

    private:
        class _setter_t
        {
            type& _function;
            state_type const& _current;
            input_type const& _i;

        public:
            _setter_t(type& t, state_type const& current, input_type const& i);
            void operator=(state_type const& next);
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
        register_transition_function();
        void reset();
        bool operator()(state_type& state, input_type const& i) const;
        _setter_t operator()(state_type const& current, input_type const& i);

    private:
        template <
            typename I1,
            typename R1,
            typename A1,
            typename D1,
            typename I2,
            typename R2,
            typename A2,
            typename D2
        >
        friend bool
            operator==(
                register_transition_function<I1,R1,A1,D1> const& lhs,
                register_transition_function<I2,R2,A2,D2> const& rhs
            );
    };

    template <typename I, typename R, typename A, typename D>
    inline register_transition_function<I,R,A,D>::register_transition_function() : _transitions()
    {
    }

    template <typename I, typename R, typename A, typename D>
    inline void register_transition_function<I,R,A,D>::reset()
    {
        this->_transitions.clear();
    }

    template <typename I, typename R, typename A, typename D>
    inline bool
        register_transition_function<I,R,A,D>::operator()(
            state_type& state,
            input_type const& i
        ) const
    {
        if (state < this->_transitions.size())
        {
            _x10_t const& t0_map = this->_transitions[state];
            typename _x10_t::const_iterator itr = t0_map.find(i);

            if (itr != t0_map.end())
            {
                state = itr->second;
                return true;
            }
        }

        return false;
    }

    template <typename I, typename R, typename A, typename D>
    inline register_transition_function<I,R,A,D>::_setter_t::_setter_t(
        type& t,
        state_type const& current,
        input_type const& i
    ) : _function(t), _current(current), _i(i)
    {
        state_type s = current;

        if (this->_function._transitions.size() < ++s)
        {
            this->_function._transitions.resize(s);
        }
    }

    template <typename I, typename R, typename A, typename D>
    inline void register_transition_function<I,R,A,D>::_setter_t::operator=(state_type const& n)
    {
        state_type s = n;

        if (this->_function._transitions.size() < ++s)
        {
            this->_function._transitions.resize(s);
        }

        this->_function._transitions[this->_current].insert(
            typename _x10_t::value_type(this->_i, n)
        );
    }

    template <typename I, typename R, typename A, typename D>
    inline typename register_transition_function<I,R,A,D>::_setter_t
        register_transition_function<I,R,A,D>::operator()(
            state_type const& current,
            input_type const& i
        )
    {
        return _setter_t(*this, current, i);
    }
}}  // namespace odds_and_ends::automaton

#include <algorithm>
#include <boost/utility/value_init.hpp>

namespace odds_and_ends { namespace automaton {

    template <
        typename I1,
        typename R1,
        typename A1,
        typename D1,
        typename I2,
        typename R2,
        typename A2,
        typename D2
    >
    bool
        operator==(
            register_transition_function<I1,R1,A1,D1> const& lhs,
            register_transition_function<I2,R2,A2,D2> const& rhs
        )
    {
        if (lhs._transitions.size() == rhs._transitions.size())
        {
            for (
                typename register_transition_function<I1,R1,A1,D1>::state_type s = (
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
        typename I1,
        typename R1,
        typename A1,
        typename D1,
        typename I2,
        typename R2,
        typename A2,
        typename D2
    >
    inline bool
        operator!=(
            register_transition_function<I1,R1,A1,D1> const& lhs,
            register_transition_function<I2,R2,A2,D2> const& rhs
        )
    {
        return !(lhs == rhs);
    }
}}  // namespace odds_and_ends::automaton

#endif  // ODDS_AND_ENDS__AUTOMATON__TRANSITION_FUNCTION__REGISTER_HPP

