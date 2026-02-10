// Copyright (C) 2007-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__AUTOMATON__BASE_HPP
#define ODDS_AND_ENDS__AUTOMATON__BASE_HPP

#include <type_traits>
#include <utility>
#include <memory>
#include <odds_and_ends/automaton/parameter/name.hpp>
#include <odds_and_ends/composite_type/event/default_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/default_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/allocator_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/variadic_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/variadic_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/arg_pack_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/arg_pack_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/conversion_assignment.hpp>
#include <odds_and_ends/composite_type/event/copy_assignment.hpp>
#include <odds_and_ends/composite_type/event/copy_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/coercive_move_constructor.hpp>
#include <odds_and_ends/composite_type/event/move_assignment.hpp>
#include <odds_and_ends/composite_type/event/move_2nd_stage.hpp>
#include <odds_and_ends/composite_type/preprocessor/noncopyable_nonmovable_body.hpp>
#include <odds_and_ends/static_introspection/member_function/has_clear.hpp>
#include <boost/utility/value_init.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/apply_wrap.hpp>

namespace odds_and_ends { namespace automaton {

    template <typename TransitionFunction>
    struct base
    {
        template <typename CompositeParentGenerator>
        struct apply
        {
            struct type
            {
                template <typename Derived>
                class apply
                {
                    typedef typename ::boost::mpl::apply_wrap1<
                        CompositeParentGenerator,
                        Derived
                    >::type _composite_parent_t;

                    class _result_with_start : public _composite_parent_t
                    {
                        TransitionFunction _transition_function;
                        typename TransitionFunction::state_type _start;
                        typename TransitionFunction::state_type _state;

                    protected:
                        inline explicit _result_with_start(
                            ::odds_and_ends::composite_type
                            ::default_constructor_1st_stage_event const& e
                        ) : _composite_parent_t(e),
                            _transition_function(),
                            _start(::boost::initialized_value),
                            _state(_start)
                        {
                        }

                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type
                                ::default_constructor_2nd_stage_event const& e
                            )
                        {
                            return _composite_parent_t::post_construct(e);
                        }

                        template <typename Alloc>
                        inline _result_with_start(
                            ::std::allocator_arg_t const& o,
                            Alloc const& alloc
                        ) : _composite_parent_t(o, alloc),
                            _transition_function(),
                            _start(::boost::initialized_value),
                            _state(_start)
                        {
                        }

                        template <typename Alloc, typename A0>
                        inline _result_with_start(
                            ::std::allocator_arg_t const& o,
                            Alloc const& alloc,
                            A0&& a0
                        ) : _composite_parent_t(o, alloc, ::std::forward<A0>(a0)),
                            _transition_function(::std::forward<A0>(a0)),
                            _start(::boost::initialized_value),
                            _state(_start)
                        {
                        }

                        template <typename Alloc, typename A0, typename ...Args>
                        inline _result_with_start(
                            ::std::allocator_arg_t const& o,
                            Alloc const& alloc,
                            A0&& a0,
                            Args&& ...args
                        ) : _composite_parent_t(
                                o,
                                alloc,
                                ::std::forward<A0>(a0),
                                ::std::forward<Args>(args)...
                            ),
                            _transition_function(::std::forward<A0>(a0)),
                            _start(::std::forward<Args>(args)...),
                            _state(_start)
                        {
                        }

                        template <typename Alloc, typename ...Args>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type
                                ::allocator_constructor_2nd_stage_event const& e,
                                Alloc const& alloc,
                                Args&& ...args
                            )
                        {
                            return _composite_parent_t::post_construct(
                                e,
                                alloc,
                                ::std::forward<Args>(args)...
                            );
                        }

                        template <typename A0>
                        inline _result_with_start(
                            ::odds_and_ends::composite_type
                            ::variadic_constructor_1st_stage_event const& e,
                            A0&& a0
                        ) : _composite_parent_t(e, ::std::forward<A0>(a0)),
                            _transition_function(::std::forward<A0>(a0)),
                            _start(::boost::initialized_value),
                            _state(_start)
                        {
                        }

                        template <typename Arg>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type
                                ::conversion_assignment_event const& e,
                                Arg&& arg
                            )
                        {
                            bool result = (
                                _composite_parent_t::post_construct(e, ::std::forward<Arg>(arg))
                            );
                            this->_transition_function = ::std::forward<Arg>(arg);
                            return result;
                        }

                        template <typename A0, typename A1, typename ...Args>
                        inline _result_with_start(
                            ::odds_and_ends::composite_type
                            ::variadic_constructor_1st_stage_event const& e,
                            A0&& a0,
                            A1&& a1,
                            Args&& ...args
                        ) : _composite_parent_t(
                                e,
                                ::std::forward<A0>(a0),
                                ::std::forward<A1>(a1),
                                ::std::forward<Args>(args)...
                            ),
                            _transition_function(::std::forward<A0>(a0)),
                            _start(::std::forward<A1>(a1), ::std::forward<Args>(args)...),
                            _state(_start)
                        {
                        }

                        template <typename A0, typename ...Args>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type
                                ::variadic_constructor_2nd_stage_event const& e,
                                A0&& a0,
                                Args&&... args
                            )
                        {
                            return _composite_parent_t::post_construct(
                                e,
                                ::std::forward<A0>(a0),
                                ::std::forward<Args>(args)...
                            );
                        }

                        template <typename ArgumentPack>
                        inline _result_with_start(
                            ::odds_and_ends::composite_type
                            ::arg_pack_constructor_1st_stage_event const& e,
                            ArgumentPack const& arg_pack
                        ) : _composite_parent_t(e, arg_pack),
                            _transition_function(
                                arg_pack[::odds_and_ends::automaton::parameter::_function]
                            ),
                            _start(arg_pack[::odds_and_ends::automaton::parameter::_source_state]),
                            _state(_start)
                        {
                        }

                        template <typename ArgumentPack>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type
                                ::arg_pack_constructor_2nd_stage_event const& e,
                                ArgumentPack const& arg_pack
                            )
                        {
                            return _composite_parent_t::post_construct(e, arg_pack);
                        }

                        template <typename Copy>
                        inline _result_with_start(
                            ::odds_and_ends::composite_type
                            ::coercive_copy_constructor_event const& e,
                            Copy const& copy
                        ) : _composite_parent_t(e, copy),
                            _transition_function(copy._transition_function),
                            _start(copy._start),
                            _state(copy._state)
                        {
                        }

                        template <typename Copy, typename Alloc>
                        inline _result_with_start(
                            ::odds_and_ends::composite_type
                            ::coercive_copy_constructor_event const& e,
                            Copy const& copy,
                            Alloc const& alloc
                        ) : _composite_parent_t(e, copy, alloc),
                            _transition_function(copy._transition_function),
                            _start(copy._start),
                            _state(copy._state)
                        {
                        }

                        template <typename Copy>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::copy_assignment_event const& e,
                                Copy const& copy
                            )
                        {
                            bool const result = _composite_parent_t::post_construct(e, copy);
                            this->_transition_function = copy._transition_function;
                            this->_start = copy._start;
                            this->_state = copy._state;
                            return result;
                        }

                        template <typename Copy, typename Alloc>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::copy_assignment_event const& e,
                                Copy const& copy,
                                Alloc const& alloc
                            )
                        {
                            bool const result = (
                                _composite_parent_t::post_construct(e, copy, alloc)
                            );
                            this->_transition_function = copy._transition_function;
                            this->_start = copy._start;
                            this->_state = copy._state;
                            return result;
                        }

                        template <typename Copy>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::copy_2nd_stage_event const& e,
                                Copy const& copy
                            )
                        {
                            return _composite_parent_t::post_construct(e, copy);
                        }

                        template <typename Copy, typename Alloc>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::copy_2nd_stage_event const& e,
                                Copy const& copy,
                                Alloc const& alloc
                            )
                        {
                            return _composite_parent_t::post_construct(e, copy, alloc);
                        }

                        template <typename Source>
                        inline _result_with_start(
                            ::odds_and_ends::composite_type
                            ::coercive_move_constructor_event const& e,
                            Source&& source
                        ) : _composite_parent_t(e, static_cast<Source&&>(source)),
                            _transition_function(::std::move(source._transition_function)),
                            _start(::std::move(source._start)),
                            _state(::std::move(source._state))
                        {
                        }

                        template <typename Source, typename Alloc>
                        inline _result_with_start(
                            ::odds_and_ends::composite_type
                            ::coercive_move_constructor_event const& e,
                            Source&& source,
                            Alloc const& alloc
                        ) : _composite_parent_t(e, static_cast<Source&&>(source), alloc),
                            _transition_function(::std::move(source._transition_function)),
                            _start(::std::move(source._start)),
                            _state(::std::move(source._state))
                        {
                        }

                        template <typename Source>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::move_assignment_event const& e,
                                Source&& source
                            )
                        {
                            bool const result = _composite_parent_t::post_construct(
                                e,
                                static_cast<Source&&>(source)
                            );
                            this->_transition_function = ::std::move(source._transition_function);
                            this->_start = ::std::move(source._start);
                            this->_state = ::std::move(source._state);
                            return result;
                        }

                        template <typename Source, typename Alloc>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::move_assignment_event const& e,
                                Source&& source,
                                Alloc const& alloc
                            )
                        {
                            bool const result = _composite_parent_t::post_construct(
                                e,
                                static_cast<Source&&>(source),
                                alloc
                            );
                            this->_transition_function = ::std::move(source._transition_function);
                            this->_start = ::std::move(source._start);
                            this->_state = ::std::move(source._state);
                            return result;
                        }

                        template <typename Source>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::move_2nd_stage_event const& e,
                                Source&& source
                            )
                        {
                            return _composite_parent_t::post_construct(
                                e,
                                static_cast<Source&&>(source)
                            );
                        }

                        template <typename Source, typename Alloc>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::move_2nd_stage_event const& e,
                                Source&& source,
                                Alloc const& alloc
                            )
                        {
                            return _composite_parent_t::post_construct(
                                e,
                                static_cast<Source&&>(source),
                                alloc
                            );
                        }

                    public:
                        inline ~_result_with_start()
                        {
                        }

                        struct traits : _composite_parent_t::traits
                        {
                            typedef TransitionFunction transition_function;
                            typedef typename TransitionFunction::state_type state_type;
                        };

                        inline TransitionFunction const& get_transition_function() const
                        {
                            return this->_transition_function;
                        }

                        inline TransitionFunction& get_transition_function()
                        {
                            return this->_transition_function;
                        }

                        inline typename TransitionFunction::state_type const& get_state() const
                        {
                            return this->_state;
                        }

                        inline void reset()
                        {
                            this->_state = this->_start;
                        }

                        template <typename ...Args>
                        inline bool operator()(Args&&... args)
                        {
                            bool result = const_cast<_result_with_start const*>(
                                this
                            )->_transition_function(this->_state, ::std::forward<Args>(args)...);
                            return result;
                        }

                        ODDS_AND_ENDS__COMPOSITE_TYPE__NONCOPYABLE_NONMOVABLE_BODY(
                            _result_with_start
                        )
                    };

                    class _result_with_clear : public _composite_parent_t
                    {
                        TransitionFunction _transition_function;
                        typename TransitionFunction::state_type _state;

                    protected:
                        inline explicit _result_with_clear(
                            ::odds_and_ends::composite_type
                            ::default_constructor_1st_stage_event const& e
                        ) : _composite_parent_t(e), _transition_function(), _state()
                        {
                        }

                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type
                                ::default_constructor_2nd_stage_event const& e
                            )
                        {
                            return _composite_parent_t::post_construct(e);
                        }

                        template <typename Alloc>
                        inline _result_with_clear(
                            ::std::allocator_arg_t const& o,
                            Alloc const& alloc
                        ) : _composite_parent_t(o, alloc), _transition_function(), _state()
                        {
                        }

                        template <typename Alloc, typename A0>
                        inline _result_with_clear(
                            ::std::allocator_arg_t const& o,
                            Alloc const& alloc,
                            A0&& a0
                        ) : _composite_parent_t(o, alloc, ::std::forward<A0>(a0)),
                            _transition_function(::std::forward<A0>(a0)),
                            _state()
                        {
                        }

                        template <typename Alloc, typename A0, typename ...Args>
                        inline _result_with_clear(
                            ::std::allocator_arg_t const& o,
                            Alloc const& alloc,
                            A0&& a0,
                            Args&& ...args
                        ) : _composite_parent_t(
                                o,
                                alloc,
                                ::std::forward<A0>(a0),
                                ::std::forward<Args>(args)...
                            ),
                            _transition_function(::std::forward<A0>(a0)),
                            _state(::std::forward<Args>(args)...)
                        {
                        }

                        template <typename Alloc, typename ...Args>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type
                                ::allocator_constructor_2nd_stage_event const& e,
                                Alloc const& alloc,
                                Args&& ...args
                            )
                        {
                            return _composite_parent_t::post_construct(
                                e,
                                alloc,
                                ::std::forward<Args>(args)...
                            );
                        }

                        template <typename A0>
                        inline _result_with_clear(
                            ::odds_and_ends::composite_type
                            ::variadic_constructor_1st_stage_event const& e,
                            A0&& a0
                        ) : _composite_parent_t(e, ::std::forward<A0>(a0)),
                            _transition_function(::std::forward<A0>(a0)),
                            _state()
                        {
                        }

                        template <typename Arg>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type
                                ::conversion_assignment_event const& e,
                                Arg&& arg
                            )
                        {
                            bool result = (
                                _composite_parent_t::post_construct(e, ::std::forward<Arg>(arg))
                            );
                            this->_transition_function = ::std::forward<Arg>(arg);
                            return result;
                        }

                        template <typename A0, typename A1, typename ...Args>
                        inline _result_with_clear(
                            ::odds_and_ends::composite_type
                            ::variadic_constructor_1st_stage_event const& e,
                            A0&& a0,
                            A1&& a1,
                            Args&& ...args
                        ) : _composite_parent_t(
                                e,
                                ::std::forward<A0>(a0),
                                ::std::forward<A1>(a1),
                                ::std::forward<Args>(args)...
                            ),
                            _transition_function(::std::forward<A0>(a0)),
                            _state(::std::forward<A1>(a1), ::std::forward<Args>(args)...)
                        {
                        }

                        template <typename A0, typename ...Args>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type
                                ::variadic_constructor_2nd_stage_event const& e,
                                A0&& a0,
                                Args&&... args
                            )
                        {
                            return _composite_parent_t::post_construct(
                                e,
                                ::std::forward<A0>(a0),
                                ::std::forward<Args>(args)...
                            );
                        }

                        template <typename ArgumentPack>
                        inline _result_with_clear(
                            ::odds_and_ends::composite_type
                            ::arg_pack_constructor_1st_stage_event const& e,
                            ArgumentPack const& arg_pack
                        ) : _composite_parent_t(e, arg_pack),
                            _transition_function(
                                arg_pack[::odds_and_ends::automaton::parameter::_function]
                            ),
                            _state(arg_pack[::odds_and_ends::automaton::parameter::_source_state])
                        {
                        }

                        template <typename ArgumentPack>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type
                                ::arg_pack_constructor_2nd_stage_event const& e,
                                ArgumentPack const& arg_pack
                            )
                        {
                            return _composite_parent_t::post_construct(e, arg_pack);
                        }

                        template <typename Copy>
                        inline _result_with_clear(
                            ::odds_and_ends::composite_type
                            ::coercive_copy_constructor_event const& e,
                            Copy const& copy
                        ) : _composite_parent_t(e, copy),
                            _transition_function(copy._transition_function),
                            _state(copy._state)
                        {
                        }

                        template <typename Copy, typename Alloc>
                        inline _result_with_clear(
                            ::odds_and_ends::composite_type
                            ::coercive_copy_constructor_event const& e,
                            Copy const& copy,
                            Alloc const& alloc
                        ) : _composite_parent_t(e, copy, alloc),
                            _transition_function(copy._transition_function),
                            _state(copy._state)
                        {
                        }

                        template <typename Copy>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::copy_assignment_event const& e,
                                Copy const& copy
                            )
                        {
                            bool const result = _composite_parent_t::post_construct(e, copy);
                            this->_transition_function = copy._transition_function;
                            this->_state = copy._state;
                            return result;
                        }

                        template <typename Copy, typename Alloc>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::copy_assignment_event const& e,
                                Copy const& copy,
                                Alloc const& alloc
                            )
                        {
                            bool const result = (
                                _composite_parent_t::post_construct(e, copy, alloc)
                            );
                            this->_transition_function = copy._transition_function;
                            this->_state = copy._state;
                            return result;
                        }

                        template <typename Copy>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::copy_2nd_stage_event const& e,
                                Copy const& copy
                            )
                        {
                            return _composite_parent_t::post_construct(e, copy);
                        }

                        template <typename Copy, typename Alloc>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::copy_2nd_stage_event const& e,
                                Copy const& copy,
                                Alloc const& alloc
                            )
                        {
                            return _composite_parent_t::post_construct(e, copy, alloc);
                        }

                        template <typename Source>
                        inline _result_with_clear(
                            ::odds_and_ends::composite_type
                            ::coercive_move_constructor_event const& e,
                            Source&& source
                        ) : _composite_parent_t(e, static_cast<Source&&>(source)),
                            _transition_function(::std::move(source._transition_function)),
                            _state(::std::move(source._state))
                        {
                        }

                        template <typename Source, typename Alloc>
                        inline _result_with_clear(
                            ::odds_and_ends::composite_type
                            ::coercive_move_constructor_event const& e,
                            Source&& source,
                            Alloc const& alloc
                        ) : _composite_parent_t(e, static_cast<Source&&>(source), alloc),
                            _transition_function(::std::move(source._transition_function)),
                            _state(::std::move(source._state))
                        {
                        }

                        template <typename Source>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::move_assignment_event const& e,
                                Source&& source
                            )
                        {
                            bool const result = _composite_parent_t::post_construct(
                                e,
                                static_cast<Source&&>(source)
                            );
                            this->_transition_function = ::std::move(source._transition_function);
                            this->_state = ::std::move(source._state);
                            return result;
                        }

                        template <typename Source, typename Alloc>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::move_assignment_event const& e,
                                Source&& source,
                                Alloc const& alloc
                            )
                        {
                            bool const result = _composite_parent_t::post_construct(
                                e,
                                static_cast<Source&&>(source),
                                alloc
                            );
                            this->_transition_function = ::std::move(source._transition_function);
                            this->_state = ::std::move(source._state);
                            return result;
                        }

                        template <typename Source>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::move_2nd_stage_event const& e,
                                Source&& source
                            )
                        {
                            return _composite_parent_t::post_construct(
                                e,
                                static_cast<Source&&>(source)
                            );
                        }

                        template <typename Source, typename Alloc>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::move_2nd_stage_event const& e,
                                Source&& source,
                                Alloc const& alloc
                            )
                        {
                            return _composite_parent_t::post_construct(
                                e,
                                static_cast<Source&&>(source),
                                alloc
                            );
                        }

                    public:
                        inline ~_result_with_clear()
                        {
                        }

                        struct traits : _composite_parent_t::traits
                        {
                            typedef TransitionFunction transition_function;
                            typedef typename TransitionFunction::state_type state_type;
                        };

                        inline TransitionFunction const& get_transition_function() const
                        {
                            return this->_transition_function;
                        }

                        inline TransitionFunction& get_transition_function()
                        {
                            return this->_transition_function;
                        }

                        inline typename TransitionFunction::state_type const& get_state() const
                        {
                            return this->_state;
                        }

                        inline void reset()
                        {
                            this->_state.clear();
                        }

                        template <typename ...Args>
                        inline bool operator()(Args&&... args)
                        {
                            bool result = const_cast<_result_with_clear const*>(
                                this
                            )->_transition_function(this->_state, ::std::forward<Args>(args)...);
                            return result;
                        }

                        ODDS_AND_ENDS__COMPOSITE_TYPE__NONCOPYABLE_NONMOVABLE_BODY(
                            _result_with_clear
                        )
                    };

                public:
                    typedef typename ::boost::mpl::if_<
                        typename ::boost::mpl::if_<
                            ::std::is_default_constructible<
                                typename TransitionFunction::state_type
                            >,
                            ::odds_and_ends::static_introspection::member_function
                            ::has_clear<typename TransitionFunction::state_type>,
                            ::boost::mpl::false_
                        >::type,
                        _result_with_clear,
                        _result_with_start
                    >::type type;
                };
            };
        };
    };
}}  // namespace odds_and_ends::automaton

#endif  // ODDS_AND_ENDS__AUTOMATON__BASE_HPP

