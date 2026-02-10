// Copyright (C) 2007-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__AUTOMATON__TRANSITION_FUNCTION__MATRIX_HPP
#define ODDS_AND_ENDS__AUTOMATON__TRANSITION_FUNCTION__MATRIX_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/concept/is_ublas_matrix.hpp>
#include <boost/mpl/assert.hpp>

namespace odds_and_ends { namespace automaton {

    template <typename StateInputMatrix>
    class matrix_transition_function
    {
        BOOST_MPL_ASSERT((
            ::odds_and_ends::static_introspection::concept::is_ublas_matrix<StateInputMatrix>
        ));

    public:
        typedef typename StateInputMatrix::value_type state_type;
        typedef typename StateInputMatrix::size_type  input_type;

    private:
        static_assert(
            ::std::is_same<state_type,input_type>::value,
            "The state and input types must match."
        );

        class _setter
        {
            matrix_transition_function& _function;
            state_type const& _current_state;
            input_type const& _i;

        public:
            _setter(
                matrix_transition_function& f,
                state_type const& current_state,
                input_type const& i
            );

            void operator=(state_type const& next_state);
        };

        StateInputMatrix _transition_matrix;

    public:
        matrix_transition_function();
        matrix_transition_function(state_type const& state_count, input_type const& input_count);
        matrix_transition_function(matrix_transition_function const& copy);
        matrix_transition_function& operator=(matrix_transition_function const& copy);
        bool operator()(state_type& current_state, input_type const& i) const;
        _setter operator()(state_type const& current_state, input_type const& i);
        void reset(state_type const& state_count, input_type const& input_count);
        state_type get_state_count() const;
        bool recognizes_state(state_type const& s) const;
        bool recognizes_input(input_type const& i) const;

        template <typename Iterator>
        void make_nontrivial_inputs(state_type const& current_state, Iterator itr) const;

    private:
        template <typename SIM0, typename SIM1>
        friend bool
            operator==(
                matrix_transition_function<SIM0> const& lhs,
                matrix_transition_function<SIM1> const& rhs
            );
    };
}}  // namespace odds_and_ends::automaton

#include <boost/assert.hpp>

namespace odds_and_ends { namespace automaton {

    template <typename StateInputMatrix>
    matrix_transition_function<StateInputMatrix>::_setter::_setter(
        matrix_transition_function& f,
        state_type const& current_state,
        input_type const& i
    ) : _function(f), _current_state(current_state), _i(i)
    {
        BOOST_ASSERT(f.recognizes_state(current_state));
        BOOST_ASSERT(f.recognizes_input(i));
    }

    template <typename SIM>
    inline void matrix_transition_function<SIM>::_setter::operator=(state_type const& next_state)
    {
        BOOST_ASSERT(this->_function.recognizes_state(next_state));
        this->_function._transition_matrix(this->_current_state, this->_i) = next_state;
    }

    template <typename StateInputMatrix>
    matrix_transition_function<StateInputMatrix>::matrix_transition_function() :
        _transition_matrix()
    {
    }
}}  // namespace odds_and_ends::automaton

#include <boost/utility/value_init.hpp>

namespace odds_and_ends { namespace automaton {

    template <typename StateInputMatrix>
    matrix_transition_function<StateInputMatrix>::matrix_transition_function(
        state_type const& state_count,
        input_type const& input_count
    ) : _transition_matrix(state_count, input_count)
    {
        state_type s = ::boost::initialized_value;
        input_type i;

        for (; s < state_count; ++s)
        {
            for (i = ::boost::initialized_value; i < input_count; ++i)
            {
                this->_transition_matrix(s, i) = s;
            }
        }
    }

    template <typename StateInputMatrix>
    matrix_transition_function<StateInputMatrix>::matrix_transition_function(
        matrix_transition_function const& copy
    ) : _transition_matrix(copy._transition_matrix.size1(), copy._transition_matrix.size2())
    {
        input_type i;

        for (state_type s = this->_transition_matrix.size1(); s; )
        {
            --s;

            for (i = this->_transition_matrix.size2(); i; )
            {
                --i;
                this->_transition_matrix(s, i) = copy._transition_matrix(s, i);
            }
        }
    }

    template <typename StateInputMatrix>
    matrix_transition_function<StateInputMatrix>&
        matrix_transition_function<StateInputMatrix>::operator=(
            matrix_transition_function const& copy
        )
    {
        if (this != &copy)
        {
            this->_transition_matrix.resize(
                copy._transition_matrix.size1(),
                copy._transition_matrix.size2()
            );

            input_type i;

            for (state_type s = this->_transition_matrix.size1(); s; )
            {
                --s;

                for (i = this->_transition_matrix.size2(); i; )
                {
                    --i;
                    this->_transition_matrix(s, i) = copy._transition_matrix(s, i);
                }
            }
        }

        return *this;
    }

    template <typename SIM>
    inline bool matrix_transition_function<SIM>::recognizes_input(input_type const& i) const
    {
        return i < this->_transition_matrix.size2();
    }

    template <typename SIM>
    inline bool matrix_transition_function<SIM>::recognizes_state(state_type const& s) const
    {
        return s < this->_transition_matrix.size1();
    }

    template <typename StateInputMatrix>
    inline typename matrix_transition_function<StateInputMatrix>::state_type
        matrix_transition_function<StateInputMatrix>::get_state_count() const
    {
        return this->_transition_matrix.size1();
    }

    template <typename SIM>
    inline bool
        matrix_transition_function<SIM>::operator()(
            state_type& current_state,
            input_type const& i
        ) const
    {
        BOOST_ASSERT(this->recognizes_state(current_state));
        BOOST_ASSERT(this->recognizes_input(i));

        state_type const& result_state = this->_transition_matrix(current_state, i);
    
        if (result_state == current_state)
        {
            return false;
        }
        else
        {
            current_state = result_state;
            return true;
        }
    }

    template <typename StateInputMatrix>
    template <typename Iterator>
    void
        matrix_transition_function<StateInputMatrix>::make_nontrivial_inputs(
            state_type const& current_state,
            Iterator itr
        ) const
    {
        BOOST_ASSERT(this->recognizes_state(current_state));

        for (input_type i = ::boost::initialized_value; i < this->_transition_matrix.size2(); ++i)
        {
            if (current_state != this->_transition_matrix(current_state, i))
            {
                *itr = i;
                ++itr;
            }
        }
    }

    template <typename StateInputMatrix>
    typename matrix_transition_function<StateInputMatrix>::_setter
        matrix_transition_function<StateInputMatrix>::operator()(
            state_type const& s,
            input_type const& i
        )
    {
        return _setter(*this, s, i);
    }

    template <typename StateInputMatrix>
    void
        matrix_transition_function<StateInputMatrix>::reset(
            state_type const& state_count,
            input_type const& input_count
        )
    {
        state_type s = ::boost::initialized_value;
        input_type i;

        for (this->_transition_matrix.resize(state_count, input_count); s < state_count; ++s)
        {
            for (i = ::boost::initialized_value; i < input_count; ++i)
            {
                this->_transition_matrix(s, i) = s;
            }
        }
    }

    template <typename M0, typename M1>
    bool
        operator==(
            matrix_transition_function<M0> const& lhs,
            matrix_transition_function<M1> const& rhs
        )
    {
        if (
            !(lhs._transition_matrix.size1() == rhs._transition_matrix.size1()) ||
            !(lhs._transition_matrix.size2() == rhs._transition_matrix.size2())
        )
        {
            return false;
        }

        typename matrix_transition_function<M0>::input_type i;

        for (
            typename matrix_transition_function<M0>::state_type s = lhs._transition_matrix.size1();
            s;
        )
        {
            --s;

            for (i = lhs._transition_matrix.size2(); i; )
            {
                --i;

                if (lhs._transition_matrix(s, i) != rhs._transition_matrix(s, i))
                {
                    return false;
                }
            }
        }

        return true;
    }

    template <typename M0, typename M1>
    inline bool
        operator!=(
            matrix_transition_function<M0> const& lhs,
            matrix_transition_function<M1> const& rhs
        )
    {
        return !(lhs == rhs);
    }
}}  // namespace odds_and_ends::automaton

#endif  // ODDS_AND_ENDS__AUTOMATON__TRANSITION_FUNCTION__MATRIX_HPP

