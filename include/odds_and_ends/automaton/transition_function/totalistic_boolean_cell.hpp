// Copyright (C) 2011-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__AUTOMATON__TRANSITION_FUNCTION__TOTALISTIC_BOOLEAN_CELL_HPP
#define ODDS_AND_ENDS__AUTOMATON__TRANSITION_FUNCTION__TOTALISTIC_BOOLEAN_CELL_HPP

#include <cstddef>
#include <type_traits>
#include <set>
#include <odds_and_ends/static_introspection/concept/is_single_pass_range.hpp>
#include <odds_and_ends/use_default_policy.hpp>
#include <boost/core/enable_if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/apply_wrap.hpp>

namespace odds_and_ends { namespace automaton {

    template <
        typename Size = ::std::size_t,
        typename ContainerGen = ::odds_and_ends::use_default_policy
    >
    class totalistic_boolean_cell_transition_function
    {
        typedef typename ::boost::mpl::eval_if<
            ::std::is_same<ContainerGen,::odds_and_ends::use_default_policy>,
            ::boost::mpl::identity< ::std::set<Size> >,
            ::boost::mpl::apply_wrap1<ContainerGen,Size>
        >::type _count_set_t;

    public:
        typedef Size size_type;

    private:
        class _inserter_t
        {
            _count_set_t& _set;

        public:
            explicit _inserter_t(_count_set_t& s);
            _inserter_t& operator,(size_type count);
        };

        _count_set_t _birth_set;
        _count_set_t _stay_alive_set;

    public:
        typedef bool state_type;

        template <typename InputRange>
        typename ::boost::enable_if<
            ::odds_and_ends::static_introspection::concept::is_single_pass_range<InputRange>,
            bool
        >::type
            operator()(state_type& state, InputRange const& i) const;

        bool operator()(state_type& state, bool b) const;
        _inserter_t operator|=(size_type count);
        _inserter_t operator&=(size_type count);
        void reset();
    };

    template <typename Size, typename ContainerGen>
    totalistic_boolean_cell_transition_function<Size,ContainerGen>::_inserter_t::_inserter_t(
        _count_set_t& s
    ) : _set(s)
    {
    }

    template <typename Size, typename ContainerGen>
    inline typename totalistic_boolean_cell_transition_function<Size,ContainerGen>::_inserter_t&
        totalistic_boolean_cell_transition_function<Size,ContainerGen>::_inserter_t::operator,(
            size_type count
        )
    {
        this->_set.insert(count);
        return *this;
    }

    template <typename Size, typename ContainerGen>
    inline typename totalistic_boolean_cell_transition_function<Size,ContainerGen>::_inserter_t
        totalistic_boolean_cell_transition_function<Size,ContainerGen>::operator|=(size_type count)
    {
        this->_birth_set.insert(count);
        return _inserter_t(this->_birth_set);
    }

    template <typename Size, typename ContainerGen>
    inline typename totalistic_boolean_cell_transition_function<Size,ContainerGen>::_inserter_t
        totalistic_boolean_cell_transition_function<Size,ContainerGen>::operator&=(size_type count)
    {
        this->_stay_alive_set.insert(count);
        return _inserter_t(this->_stay_alive_set);
    }

    template <typename Size, typename ContainerGen>
    inline void totalistic_boolean_cell_transition_function<Size,ContainerGen>::reset()
    {
        this->_birth_set.clear();
        this->_stay_alive_set.clear();
    }

    template <typename Size, typename ContainerGen>
    inline bool
        totalistic_boolean_cell_transition_function<Size,ContainerGen>::operator()(
            state_type& state,
            bool b
        ) const
    {
        if (state)
        {
            if (b)
            {
                return false;
            }
            else
            {
                state = false;
                return true;
            }
        }
        else
        {
            if (b)
            {
                state = true;
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}}  // namespace odds_and_ends::automaton

#include <boost/range/algorithm/count.hpp>

namespace odds_and_ends { namespace automaton {

    template <typename Size, typename ContainerGen>
    template <typename InputRange>
    inline typename ::boost::enable_if<
        ::odds_and_ends::static_introspection::concept::is_single_pass_range<InputRange>,
        bool
    >::type
        totalistic_boolean_cell_transition_function<Size,ContainerGen>::operator()(
            state_type& state,
            InputRange const& i
        ) const
    {
        if (state)
        {
            if (
                this->_stay_alive_set.find(::boost::range::count(i, true)) ==
                this->_stay_alive_set.end()
            )
            {
                state = false;
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (this->_birth_set.find(::boost::range::count(i, true)) == this->_birth_set.end())
            {
                return false;
            }
            else
            {
                state = true;
                return true;
            }
        }
    }
}}  // namespace odds_and_ends::automaton

#endif  // ODDS_AND_ENDS__AUTOMATON__TRANSITION_FUNCTION__TOTALISTIC_BOOLEAN_CELL_HPP

