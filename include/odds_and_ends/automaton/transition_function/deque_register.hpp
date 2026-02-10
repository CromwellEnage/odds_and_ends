// Copyright (C) 2007-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__AUTOMATON__TRANSITION_FUNCTION__DEQUE_REGISTER_HPP
#define ODDS_AND_ENDS__AUTOMATON__TRANSITION_FUNCTION__DEQUE_REGISTER_HPP

#include <cstddef>
#include <type_traits>
#include <utility>
#include <tuple>
#include <odds_and_ends/use_default_policy.hpp>
#include <boost/container/deque.hpp>
#include <boost/container/map.hpp>
#include <boost/optional/optional.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace automaton {

    template <
        typename Element,
        typename Input,
        typename AssociativeContainerGenerator = ::odds_and_ends::use_default_policy,
        typename DequeGenerator = ::odds_and_ends::use_default_policy
    >
    class deque_register_transition_function
    {
        typedef typename ::boost::mpl::eval_if<
            ::std::is_same<DequeGenerator,::odds_and_ends::use_default_policy>,
            ::boost::mpl::identity< ::boost::container::deque<Element> >,
            ::boost::mpl::apply1<DequeGenerator,Element>
        >::type _element_deque_t;

    public:
        typedef ::odds_and_ends::automaton::deque_register_transition_function<
            Element,
            Input,
            AssociativeContainerGenerator,
            DequeGenerator
        > type;
        typedef typename _element_deque_t::size_type register_type;
        typedef ::std::pair<_element_deque_t,register_type> state_type;
        typedef Input input_type;
        typedef Element element_type;

    private:
        typedef ::boost::optional<element_type> _opt_el_t;
        typedef ::std::tuple<register_type,_opt_el_t,_opt_el_t> _next_t;
        typedef typename ::boost::mpl::eval_if<
            ::std::is_same<AssociativeContainerGenerator,::odds_and_ends::use_default_policy>,
            ::boost::mpl::identity< ::boost::container::map<input_type,_next_t> >,
            ::boost::mpl::apply2<AssociativeContainerGenerator,input_type,_next_t>
        >::type _x10_0_t;
        typedef typename ::boost::mpl::eval_if<
            ::std::is_same<DequeGenerator,::odds_and_ends::use_default_policy>,
            ::boost::mpl::identity< ::boost::container::deque<_x10_0_t> >,
            ::boost::mpl::apply1<DequeGenerator,_x10_0_t>
        >::type _x10_0_deque;
        typedef ::std::tuple<input_type,element_type> _x10_1_key;
        typedef typename ::boost::mpl::eval_if<
            ::std::is_same<AssociativeContainerGenerator,::odds_and_ends::use_default_policy>,
            ::boost::mpl::identity< ::boost::container::map<_x10_1_key,_next_t> >,
            ::boost::mpl::apply2<AssociativeContainerGenerator,_x10_1_key,_next_t>
        >::type _x10_1_t;
        typedef typename ::boost::mpl::eval_if<
            ::std::is_same<DequeGenerator,::odds_and_ends::use_default_policy>,
            ::boost::mpl::identity< ::boost::container::deque<_x10_1_t> >,
            ::boost::mpl::apply1<DequeGenerator,_x10_1_t>
        >::type _x10_1_deque;
        typedef ::std::tuple<input_type,element_type,element_type> _x10_2_key;
        typedef typename ::boost::mpl::eval_if<
            ::std::is_same<AssociativeContainerGenerator,::odds_and_ends::use_default_policy>,
            ::boost::mpl::identity< ::boost::container::map<_x10_2_key,_next_t> >,
            ::boost::mpl::apply2<AssociativeContainerGenerator,_x10_2_key,_next_t>
        >::type _x10_2_t;
        typedef typename ::boost::mpl::eval_if<
            ::std::is_same<DequeGenerator,::odds_and_ends::use_default_policy>,
            ::boost::mpl::identity< ::boost::container::deque<_x10_2_t> >,
            ::boost::mpl::apply1<DequeGenerator,_x10_2_t>
        >::type _x10_2_deque;

    public:
        typedef ::std::tuple<register_type,element_type,bool> next_1_type;
        typedef ::std::tuple<register_type,element_type,element_type> next_2_type;

    private:
        class _setter_0_t
        {
            type& _function;
            register_type const& _current;
            input_type const& _i;

        public:
            _setter_0_t(type& t, register_type const& current, input_type const& i);
            void operator=(register_type const& next);
            void operator=(next_1_type const& next);
            void operator=(next_2_type const& next);
        };

        class _setter_1_t
        {
            type& _function;
            register_type const& _current;
            input_type const& _i;
            element_type const& _e;
            bool const _b;

        public:
            _setter_1_t(
                type& t,
                register_type const& current,
                input_type const& i,
                element_type const& e,
                bool b
            );

            void operator=(register_type const& next);
            void operator=(next_1_type const& next);
            void operator=(next_2_type const& next);
        };

        class _setter_2_t
        {
            type& _function;
            register_type const& _current;
            input_type const& _i;
            element_type const& _b;
            element_type const& _f;

        public:
            _setter_2_t(
                type& t,
                register_type const& current,
                input_type const& i,
                element_type const& b,
                element_type const& f
            );

            void operator=(register_type const& next);
            void operator=(next_1_type const& next);
            void operator=(next_2_type const& next);
        };

        _x10_0_deque _ro_transitions;
        _x10_1_deque _back_transitions;
        _x10_1_deque _front_transitions;
        _x10_2_deque _deque_transitions;

    public:
        deque_register_transition_function();
        void reset();
        bool operator()(state_type& state, input_type const& i) const;
        _setter_0_t operator()(register_type const& current, input_type const& i);

        _setter_1_t
            operator()(
                register_type const& current,
                input_type const& i,
                element_type const& e,
                bool b
            );

        _setter_2_t
            operator()(
                register_type const& current,
                input_type const& i,
                element_type const& b,
                element_type const& f
            );

    private:
        void _process_input(state_type& state, _next_t const& n) const;

        template <
            typename E1,
            typename I1,
            typename A1,
            typename D1,
            typename E2,
            typename I2,
            typename A2,
            typename D2
        >
        friend bool
            operator==(
                deque_register_transition_function<E1,I1,A1,D1> const& lhs,
                deque_register_transition_function<E2,I2,A2,D2> const& rhs
            );
    };

    template <typename E, typename I, typename A, typename D>
    inline deque_register_transition_function<E,I,A,D>::deque_register_transition_function() :
        _ro_transitions(), _back_transitions(), _front_transitions(), _deque_transitions()
    {
    }

    template <typename E, typename I, typename A, typename D>
    inline void deque_register_transition_function<E,I,A,D>::reset()
    {
        this->_ro_transitions.clear();
        this->_back_transitions.clear();
        this->_front_transitions.clear();
        this->_deque_transitions.clear();
    }

    template <typename E, typename I, typename A, typename D>
    inline void
        deque_register_transition_function<E,I,A,D>::_process_input(
            state_type& state,
            _next_t const& n
        ) const
    {
        state.second = ::std::get<0>(n);

        if (::std::get<1>(n))
        {
            state.first.push_back(*::std::get<1>(n));
        }

        if (::std::get<2>(n))
        {
            state.first.push_front(*::std::get<2>(n));
        }
    }

    template <typename E, typename I, typename A, typename D>
    inline bool
        deque_register_transition_function<E,I,A,D>::operator()(
            state_type& state,
            input_type const& i
        ) const
    {
        if (!state.first.empty())
        {
            if (state.second < this->_deque_transitions.size())
            {
                _x10_2_t const& t2_map = this->_deque_transitions[state.second];
                typename _x10_2_t::const_iterator itr = t2_map.find(
                    _x10_2_key(i, state.first.back(), state.first.front())
                );

                if (itr != t2_map.end())
                {
                    state.first.pop_back();
                    state.first.pop_front();
                    this->_process_input(state, itr->second);
                    return true;
                }
            }

            if (state.second < this->_back_transitions.size())
            {
                _x10_1_t const& t1_map = this->_back_transitions[state.second];
                typename _x10_1_t::const_iterator itr = t1_map.find(
                    _x10_1_key(i, state.first.back())
                );

                if (itr != t1_map.end())
                {
                    state.first.pop_back();
                    this->_process_input(state, itr->second);
                    return true;
                }
            }

            if (state.second < this->_front_transitions.size())
            {
                _x10_1_t const& t1_map = this->_front_transitions[state.second];
                typename _x10_1_t::const_iterator itr = t1_map.find(
                    _x10_1_key(i, state.first.front())
                );

                if (itr != t1_map.end())
                {
                    state.first.pop_front();
                    this->_process_input(state, itr->second);
                    return true;
                }
            }
        }

        if (state.second < this->_ro_transitions.size())
        {
            _x10_0_t const& t0_map = this->_ro_transitions[state.second];
            typename _x10_0_t::const_iterator itr = t0_map.find(i);

            if (itr != t0_map.end())
            {
                this->_process_input(state, itr->second);
                return true;
            }
        }

        return false;
    }

    template <typename E, typename I, typename A, typename D>
    deque_register_transition_function<E,I,A,D>::_setter_0_t::_setter_0_t(
        type& t,
        register_type const& current,
        input_type const& i
    ) : _function(t), _current(current), _i(i)
    {
        for (
            ;
            this->_function._ro_transitions.size() <= this->_current;
            this->_function._ro_transitions.emplace_back()
        )
        {
        }
    }

    template <typename E, typename I, typename A, typename D>
    inline typename deque_register_transition_function<E,I,A,D>::_setter_0_t
        deque_register_transition_function<E,I,A,D>::operator()(
            register_type const& current,
            input_type const& i
        )
    {
        return _setter_0_t(*this, current, i);
    }

    template <typename E, typename I, typename A, typename D>
    deque_register_transition_function<E,I,A,D>::_setter_1_t::_setter_1_t(
        type& t,
        register_type const& current,
        input_type const& i,
        element_type const& e,
        bool b
    ) : _function(t), _current(current), _i(i), _e(e), _b(b)
    {
        if (this->_b)
        {
            for (
                ;
                this->_function._back_transitions.size() <= this->_current;
                this->_function._back_transitions.emplace_back()
            )
            {
            }
        }
        else  // if (!this->_b)
        {
            for (
                ;
                this->_function._front_transitions.size() <= this->_current;
                this->_function._front_transitions.emplace_back()
            )
            {
            }
        }
    }

    template <typename E, typename I, typename A, typename D>
    inline typename deque_register_transition_function<E,I,A,D>::_setter_1_t
        deque_register_transition_function<E,I,A,D>::operator()(
            register_type const& current,
            input_type const& i,
            element_type const& e,
            bool b
        )
    {
        return _setter_1_t(*this, current, i, e, b);
    }

    template <typename E, typename I, typename A, typename D>
    deque_register_transition_function<E,I,A,D>::_setter_2_t::_setter_2_t(
        type& t,
        register_type const& current,
        input_type const& i,
        element_type const& b,
        element_type const& f
    ) : _function(t), _current(current), _i(i), _b(b), _f(f)
    {
        for (
            ;
            this->_function._deque_transitions.size() <= this->_current;
            this->_function._deque_transitions.emplace_back()
        )
        {
        }
    }

    template <typename E, typename I, typename A, typename D>
    inline typename deque_register_transition_function<E,I,A,D>::_setter_2_t
        deque_register_transition_function<E,I,A,D>::operator()(
            register_type const& current,
            input_type const& i,
            element_type const& b,
            element_type const& f
        )
    {
        return _setter_2_t(*this, current, i, b, f);
    }

    template <typename E, typename I, typename A, typename D>
    void
        deque_register_transition_function<E,I,A,D>::_setter_0_t::operator=(
            next_2_type const& next
        )
    {
        for (
            ;
            this->_function._ro_transitions.size() <= ::std::get<0>(next);
            this->_function._ro_transitions.emplace_back()
        )
        {
        }

        this->_function._ro_transitions[this->_current].insert(
            typename _x10_0_t::value_type(this->_i, next)
        );
    }

    template <typename E, typename I, typename A, typename D>
    void
        deque_register_transition_function<E,I,A,D>::_setter_1_t::operator=(
            next_2_type const& next
        )
    {
        if (this->_b)
        {
            for (
                ;
                this->_function._back_transitions.size() <= ::std::get<0>(next);
                this->_function._back_transitions.emplace_back()
            )
            {
            }

            this->_function._back_transitions[this->_current].insert(
                typename _x10_1_t::value_type(_x10_1_key(this->_i, this->_e), next)
            );
        }
        else  // if (!this->_b)
        {
            for (
                ;
                this->_function._front_transitions.size() <= ::std::get<0>(next);
                this->_function._front_transitions.emplace_back()
            )
            {
            }

            this->_function._front_transitions[this->_current].insert(
                typename _x10_1_t::value_type(_x10_1_key(this->_i, this->_e), next)
            );
        }
    }

    template <typename E, typename I, typename A, typename D>
    void
        deque_register_transition_function<E,I,A,D>::_setter_2_t::operator=(
            next_2_type const& next
        )
    {
        for (
            ;
            this->_function._deque_transitions.size() <= ::std::get<0>(next);
            this->_function._deque_transitions.emplace_back()
        )
        {
        }

        this->_function._deque_transitions[this->_current].insert(
            typename _x10_2_t::value_type(_x10_2_key(this->_i, this->_b, this->_f), next)
        );
    }
}}  // namespace odds_and_ends::automaton

#include <boost/none.hpp>

namespace odds_and_ends { namespace automaton {

    template <typename E, typename I, typename A, typename D>
    void
        deque_register_transition_function<E,I,A,D>::_setter_0_t::operator=(register_type const& n)
    {
        for (
            ;
            this->_function._ro_transitions.size() <= n;
            this->_function._ro_transitions.emplace_back()
        )
        {
        }

        this->_function._ro_transitions[this->_current].insert(
            typename _x10_0_t::value_type(this->_i, _next_t(n, ::boost::none, ::boost::none))
        );
    }

    template <typename E, typename I, typename A, typename D>
    void
        deque_register_transition_function<E,I,A,D>::_setter_1_t::operator=(register_type const& n)
    {
        if (this->_b)
        {
            for (
                ;
                this->_function._back_transitions.size() <= n;
                this->_function._back_transitions.emplace_back()
            )
            {
            }

            this->_function._back_transitions[this->_current].insert(
                typename _x10_1_t::value_type(
                    _x10_1_key(this->_i, this->_e),
                    _next_t(n, ::boost::none, ::boost::none)
                )
            );
        }
        else  // if (!this->_b)
        {
            for (
                ;
                this->_function._front_transitions.size() <= n;
                this->_function._front_transitions.emplace_back()
            )
            {
            }

            this->_function._front_transitions[this->_current].insert(
                typename _x10_1_t::value_type(
                    _x10_1_key(this->_i, this->_e),
                    _next_t(n, ::boost::none, ::boost::none)
                )
            );
        }
    }

    template <typename E, typename I, typename A, typename D>
    void
        deque_register_transition_function<E,I,A,D>::_setter_2_t::operator=(register_type const& n)
    {
        for (
            ;
            this->_function._deque_transitions.size() <= n;
            this->_function._deque_transitions.emplace_back()
        )
        {
        }

        this->_function._deque_transitions[this->_current].insert(
            typename _x10_2_t::value_type(
                _x10_2_key(this->_i, this->_b, this->_f),
                _next_t(n, ::boost::none, ::boost::none)
            )
        );
    }

    template <typename E, typename I, typename A, typename D>
    void
        deque_register_transition_function<E,I,A,D>::_setter_0_t::operator=(
            next_1_type const& next
        )
    {
        for (
            ;
            this->_function._ro_transitions.size() <= ::std::get<0>(next);
            this->_function._ro_transitions.emplace_back()
        )
        {
        }

        if (::std::get<2>(next))
        {
            this->_function._ro_transitions[this->_current].insert(
                typename _x10_0_t::value_type(
                    this->_i,
                    _next_t(::std::get<0>(next), ::std::get<1>(next), ::boost::none)
                )
            );
        }
        else
        {
            this->_function._ro_transitions[this->_current].insert(
                typename _x10_0_t::value_type(
                    this->_i,
                    _next_t(::std::get<0>(next), ::boost::none, ::std::get<1>(next))
                )
            );
        }
    }

    template <typename E, typename I, typename A, typename D>
    void
        deque_register_transition_function<E,I,A,D>::_setter_1_t::operator=(
            next_1_type const& next
        )
    {
        if (this->_b)
        {
            for (
                ;
                this->_function._back_transitions.size() <= ::std::get<0>(next);
                this->_function._back_transitions.emplace_back()
            )
            {
            }

            if (::std::get<2>(next))
            {
                this->_function._back_transitions[this->_current].insert(
                    typename _x10_1_t::value_type(
                        _x10_1_key(this->_i, this->_e),
                        _next_t(::std::get<0>(next), ::std::get<1>(next), ::boost::none)
                    )
                );
            }
            else
            {
                this->_function._back_transitions[this->_current].insert(
                    typename _x10_1_t::value_type(
                        _x10_1_key(this->_i, this->_e),
                        _next_t(::std::get<0>(next), ::boost::none, ::std::get<1>(next))
                    )
                );
            }
        }
        else  // if (!this->_b)
        {
            for (
                ;
                this->_function._front_transitions.size() <= ::std::get<0>(next);
                this->_function._front_transitions.emplace_back()
            )
            {
            }

            if (::std::get<2>(next))
            {
                this->_function._front_transitions[this->_current].insert(
                    typename _x10_1_t::value_type(
                        _x10_1_key(this->_i, this->_e),
                        _next_t(::std::get<0>(next), ::std::get<1>(next), ::boost::none)
                    )
                );
            }
            else
            {
                this->_function._front_transitions[this->_current].insert(
                    typename _x10_1_t::value_type(
                        _x10_1_key(this->_i, this->_e),
                        _next_t(::std::get<0>(next), ::boost::none, ::std::get<1>(next))
                    )
                );
            }
        }
    }

    template <typename E, typename I, typename A, typename D>
    void
        deque_register_transition_function<E,I,A,D>::_setter_2_t::operator=(
            next_1_type const& next
        )
    {
        for (
            ;
            this->_function._deque_transitions.size() <= ::std::get<0>(next);
            this->_function._deque_transitions.emplace_back()
        )
        {
        }

        if (::std::get<2>(next))
        {
            this->_function._deque_transitions[this->_current].insert(
                typename _x10_2_t::value_type(
                    _x10_2_key(this->_i, this->_b, this->_f),
                    _next_t(::std::get<0>(next), ::std::get<1>(next), ::boost::none)
                )
            );
        }
        else
        {
            this->_function._deque_transitions[this->_current].insert(
                typename _x10_2_t::value_type(
                    _x10_2_key(this->_i, this->_b, this->_f),
                    _next_t(::std::get<0>(next), ::boost::none, ::std::get<1>(next))
                )
            );
        }
    }
}}  // namespace odds_and_ends::automaton

#include <algorithm>
#include <boost/utility/value_init.hpp>

namespace odds_and_ends { namespace automaton {

    template <
        typename E1,
        typename I1,
        typename A1,
        typename D1,
        typename E2,
        typename I2,
        typename A2,
        typename D2
    >
    bool
        operator==(
            deque_register_transition_function<E1,I1,A1,D1> const& lhs,
            deque_register_transition_function<E2,I2,A2,D2> const& rhs
        )
    {
        if (
            (lhs._ro_transitions.size() == rhs._ro_transitions.size()) &&
            (lhs._back_transitions.size() == rhs._back_transitions.size()) &&
            (lhs._front_transitions.size() == rhs._front_transitions.size()) &&
            (lhs._deque_transitions.size() == rhs._deque_transitions.size())
        )
        {
            for (
                typename deque_register_transition_function<E1,I1,A1,D1>::register_type s = (
                    ::boost::initialized_value
                );
                s < lhs._ro_transitions.size();
                ++s
            )
            {
                if (
                    !::std::equal(
                        lhs._ro_transitions[s].cbegin(),
                        lhs._ro_transitions[s].cend(),
                        rhs._ro_transitions[s].cbegin(),
                        rhs._ro_transitions[s].cend()
                    )
                )
                {
                    return false;
                }
            }

            for (
                typename deque_register_transition_function<E1,I1,A1,D1>::register_type s = (
                    ::boost::initialized_value
                );
                s < lhs._back_transitions.size();
                ++s
            )
            {
                if (
                    !::std::equal(
                        lhs._back_transitions[s].cbegin(),
                        lhs._back_transitions[s].cend(),
                        rhs._back_transitions[s].cbegin(),
                        rhs._back_transitions[s].cend()
                    )
                )
                {
                    return false;
                }
            }

            for (
                typename deque_register_transition_function<E1,I1,A1,D1>::register_type s = (
                    ::boost::initialized_value
                );
                s < lhs._front_transitions.size();
                ++s
            )
            {
                if (
                    !::std::equal(
                        lhs._front_transitions[s].cbegin(),
                        lhs._front_transitions[s].cend(),
                        rhs._front_transitions[s].cbegin(),
                        rhs._front_transitions[s].cend()
                    )
                )
                {
                    return false;
                }
            }

            for (
                typename deque_register_transition_function<E1,I1,A1,D1>::register_type s = (
                    ::boost::initialized_value
                );
                s < lhs._deque_transitions.size();
                ++s
            )
            {
                if (
                    !::std::equal(
                        lhs._deque_transitions[s].cbegin(),
                        lhs._deque_transitions[s].cend(),
                        rhs._deque_transitions[s].cbegin(),
                        rhs._deque_transitions[s].cend()
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
        typename E1,
        typename I1,
        typename A1,
        typename D1,
        typename E2,
        typename I2,
        typename A2,
        typename D2
    >
    inline bool
        operator!=(
            deque_register_transition_function<E1,I1,A1,D1> const& lhs,
            deque_register_transition_function<E2,I2,A2,D2> const& rhs
        )
    {
        return !(lhs == rhs);
    }
}}  // namespace odds_and_ends::automaton

#endif  // ODDS_AND_ENDS__AUTOMATON__TRANSITION_FUNCTION__DEQUE_REGISTER_HPP

