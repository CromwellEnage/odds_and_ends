// Copyright (C) 2007-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__AUTOMATON__TRANSITION_FUNCTION__ADAPTOR_HPP
#define ODDS_AND_ENDS__AUTOMATON__TRANSITION_FUNCTION__ADAPTOR_HPP

#include <functional>
#include <odds_and_ends/static_introspection/concept/is_equality_comparable.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>

namespace odds_and_ends { namespace automaton {

    template <typename Function>
    class adaptor_transition_function;

    template <typename Result, typename Arg>
    class adaptor_transition_function<Result(Arg)>
    {
        ::std::function<Result(Arg)> _function;

    public:
        typedef typename ::std::function<Result(Arg)>::result_type state_type;
        typedef typename ::odds_and_ends::static_introspection::remove_cvref<Arg>::type input_type;

        adaptor_transition_function() : _function()
        {
        }

        template <typename Function>
        adaptor_transition_function(Function f) : _function(f)
        {
        }

        adaptor_transition_function(adaptor_transition_function const& copy) :
            _function(copy._function)
        {
        }

        inline adaptor_transition_function&
            operator=(adaptor_transition_function const& copy)
        {
            if (this != &copy)
            {
                this->_function = copy._function;
            }

            return *this;
        }

        inline bool operator()(state_type& state, input_type const& i) const
        {
            return this->_evaluate(
                state,
                i,
                ::odds_and_ends::static_introspection::concept
                ::is_equality_comparable<state_type>()
            );
        }

    private:
        inline bool
            _evaluate(
                state_type& state,
                input_type const& i,
                ::boost::mpl::true_
            ) const
        {
            state_type next = this->_function(i);
            bool result = (next == state);
            state = next;
            return result;
        }

        inline bool
            _evaluate(
                state_type& state,
                input_type const& i,
                ::boost::mpl::false_
            ) const
        {
            state = this->_function(i);
            return true;
        }

        template <typename R1, typename A1, typename R2, typename A2>
        inline friend bool
            operator==(
                adaptor_transition_function<R1(A1)> const& lhs,
                adaptor_transition_function<R2(A2)> const& rhs
            )
        {
            return lhs._function == rhs._function;
        }

        template <typename R1, typename A1, typename R2, typename A2>
        inline friend bool
            operator!=(
                adaptor_transition_function<R1(A1)> const& lhs,
                adaptor_transition_function<R2(A2)> const& rhs
            )
        {
            return lhs._function != rhs._function;
        }
    };
}}  // namespace odds_and_ends::automaton

#include <type_traits>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>

namespace odds_and_ends { namespace automaton {

    template <typename Result, typename Arg1, typename Arg2>
    class adaptor_transition_function<Result(Arg1,Arg2)>
    {
        struct error__state_must_be_convertible_to_either_argument;
        typedef typename ::odds_and_ends::static_introspection::remove_cvref<Arg1>::type _arg1_t;
        typedef typename ::odds_and_ends::static_introspection::remove_cvref<Arg2>::type _arg2_t;

    public:
        typedef typename ::std::function<Result(Arg1,Arg2)>::result_type state_type;

    private:
        typedef ::std::is_convertible<state_type,_arg1_t> _is_state_convertible_to_arg1_t;

    public:
        typedef typename ::boost::mpl::eval_if<
            _is_state_convertible_to_arg1_t,
            ::boost::mpl::identity<_arg2_t>,
            ::boost::mpl::eval_if<
                ::std::is_convertible<state_type,_arg2_t>,
                ::boost::mpl::identity<_arg1_t>,
                error__state_must_be_convertible_to_either_argument
            >
        >::type input_type;

    private:
        ::std::function<Result(Arg1,Arg2)> _function;

    public:
        adaptor_transition_function() : _function()
        {
        }

        template <typename Function>
        adaptor_transition_function(Function f) : _function(f)
        {
        }

        adaptor_transition_function(adaptor_transition_function const& copy) :
            _function(copy._function)
        {
        }

        inline adaptor_transition_function&
            operator=(adaptor_transition_function const& copy)
        {
            if (this != &copy)
            {
                this->_function = copy._function;
            }

            return *this;
        }

        inline bool operator()(state_type& state, input_type const& i) const
        {
            return this->_evaluate(
                state,
                i,
                _is_state_convertible_to_arg1_t(),
                ::odds_and_ends::static_introspection::concept
                ::is_equality_comparable<state_type>()
            );
        }

    private:
        inline bool
            _evaluate(
                state_type& state,
                input_type const& i,
                ::std::true_type,
                ::boost::mpl::true_
            ) const
        {
            state_type next = this->_function(state, i);
            bool result = (next == state);
            state = next;
            return result;
        }

        inline bool
            _evaluate(
                state_type& state,
                input_type const& i,
                ::std::true_type,
                ::boost::mpl::false_
            ) const
        {
            state = this->_function(state, i);
            return true;
        }

        inline bool
            _evaluate(
                state_type& state,
                input_type const& i,
                ::std::false_type,
                ::boost::mpl::true_
            ) const
        {
            state_type next = this->_function(i, state);
            bool result = (next == state);
            state = next;
            return result;
        }

        inline bool
            _evaluate(
                state_type& state,
                input_type const& i,
                ::std::false_type,
                ::boost::mpl::false_
            ) const
        {
            state = this->_function(i, state);
            return true;
        }

        template <
            typename R1, typename A1_1, typename A1_2,
            typename R2, typename A2_1, typename A2_2
        >
        inline friend bool
            operator==(
                adaptor_transition_function<R1(A1_1,A1_2)> const& lhs,
                adaptor_transition_function<R2(A2_1,A2_2)> const& rhs
            )
        {
            return lhs._function == rhs._function;
        }

        template <
            typename R1, typename A1_1, typename A1_2,
            typename R2, typename A2_1, typename A2_2
        >
        inline friend bool
            operator!=(
                adaptor_transition_function<R1(A1_1,A1_2)> const& lhs,
                adaptor_transition_function<R2(A2_1,A2_2)> const& rhs
            )
        {
            return lhs._function != rhs._function;
        }
    };
}}  // namespace odds_and_ends::automaton

#endif  // ODDS_AND_ENDS__AUTOMATON__TRANSITION_FUNCTION__ADAPTOR_HPP

