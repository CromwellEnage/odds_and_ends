// Copyright (C) 2025-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__COMPOSITE_TYPE__PP__STATELESS_BODY_HPP
#define ODDS_AND_ENDS__COMPOSITE_TYPE__PP__STATELESS_BODY_HPP

#include <memory>
#include <odds_and_ends/composite_type/event/default_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/variadic_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/arg_pack_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/coercive_copy_constructor.hpp>
#include <odds_and_ends/composite_type/event/coercive_move_constructor.hpp>

#define ODDS_AND_ENDS__COMPOSITE_TYPE__STATELESS_BODY(Type, Base)                                \
    protected:                                                                                   \
    inline explicit Type(                                                                        \
        ::odds_and_ends::composite_type::default_constructor_1st_stage_event const& e            \
    ) : Base(e)                                                                                  \
    {                                                                                            \
    }                                                                                            \
    template <typename A0, typename ...Args>                                                     \
    inline Type(::std::allocator_arg_t const& o, A0&& a0, Args&& ...args) :                      \
        Base(o, ::std::forward<A0>(a0), ::std::forward<Args>(args)...)                           \
    {                                                                                            \
    }                                                                                            \
    template <typename A0, typename ...Args>                                                     \
    inline Type(                                                                                 \
        ::odds_and_ends::composite_type::variadic_constructor_1st_stage_event const& e,          \
        A0&& a0,                                                                                 \
        Args&& ...args                                                                           \
    ) : Base(e, ::std::forward<A0>(a0), ::std::forward<Args>(args)...)                           \
    {                                                                                            \
    }                                                                                            \
    template <typename ArgumentPack>                                                             \
    inline Type(                                                                                 \
        ::odds_and_ends::composite_type::arg_pack_constructor_1st_stage_event const& e,          \
        ArgumentPack const& arg_pack                                                             \
    ) : Base(e, arg_pack)                                                                        \
    {                                                                                            \
    }                                                                                            \
    template <typename Copy>                                                                     \
    inline Type(                                                                                 \
        ::odds_and_ends::composite_type::coercive_copy_constructor_event const& e,               \
        Copy const& copy                                                                         \
    ) : Base(e, copy)                                                                            \
    {                                                                                            \
    }                                                                                            \
    template <typename Copy, typename Alloc>                                                     \
    inline Type(                                                                                 \
        ::odds_and_ends::composite_type::coercive_copy_constructor_event const& e,               \
        Copy const& copy,                                                                        \
        Alloc& alloc                                                                             \
    ) : Base(e, copy, alloc)                                                                     \
    {                                                                                            \
    }                                                                                            \
    template <typename Source>                                                                   \
    inline Type(                                                                                 \
        ::odds_and_ends::composite_type::coercive_move_constructor_event const& e,               \
        Source&& source                                                                          \
    ) : Base(e, static_cast<Source&&>(source))                                                   \
    {                                                                                            \
    }                                                                                            \
    template <typename Source, typename Alloc>                                                   \
    inline Type(                                                                                 \
        ::odds_and_ends::composite_type::coercive_move_constructor_event const& e,               \
        Source&& source,                                                                         \
        Alloc const& alloc                                                                       \
    ) : Base(e, static_cast<Source&&>(source), alloc)                                            \
    {                                                                                            \
    }                                                                                            \
    public:                                                                                      \
    inline ~Type()                                                                               \
    {                                                                                            \
    }                                                                                            \
    // ODDS_AND_ENDS__COMPOSITE_TYPE__STATELESS_BODY

#endif  // ODDS_AND_ENDS__COMPOSITE_TYPE__PP__STATELESS_BODY_HPP

