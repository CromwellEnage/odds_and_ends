// Copyright (C) 2011-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__COMPOSITE_TYPE__COMPOSITE_BASE_HPP
#define ODDS_AND_ENDS__COMPOSITE_TYPE__COMPOSITE_BASE_HPP

#include <type_traits>
#include <memory>
#include <odds_and_ends/composite_type/composite_base_fwd.hpp>
#include <odds_and_ends/composite_type/event/default_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/variadic_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/arg_pack_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/conversion_assignment.hpp>
#include <odds_and_ends/composite_type/event/coercive_copy_constructor.hpp>
#include <odds_and_ends/composite_type/event/coercive_move_constructor.hpp>
#include <odds_and_ends/composite_type/event/constructor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/operator.hpp>
#include <odds_and_ends/composite_type/event/function_call_broadcast.hpp>
#include <odds_and_ends/composite_type/preprocessor/noncopyable_nonmovable_body.hpp>
#include <boost/core/enable_if.hpp>

namespace odds_and_ends { namespace composite_type {

    template <typename Derived>
    struct composite_base
    {
        typedef ::odds_and_ends::composite_type::composite_base<Derived> type;

        struct traits
        {
            typedef Derived const& const_reference;
            typedef Derived& reference;
        };

    protected:
        explicit composite_base(
            ::odds_and_ends::composite_type::default_constructor_1st_stage_event const&
        );

        template <typename ...Args>
        explicit composite_base(::std::allocator_arg_t const&, Args&& ...args);

        template <typename ...Args>
        explicit composite_base(
            ::odds_and_ends::composite_type::variadic_constructor_1st_stage_event const&,
            Args&& ...args
        );

        template <typename ArgumentPack>
        composite_base(
            ::odds_and_ends::composite_type::arg_pack_constructor_1st_stage_event const&,
            ArgumentPack const& arg_pack
        );

        template <typename Copy>
        composite_base(
            ::odds_and_ends::composite_type::coercive_copy_constructor_event const&,
            Copy const& copy
        );

        template <typename Copy, typename Alloc>
        composite_base(
            ::odds_and_ends::composite_type::coercive_copy_constructor_event const&,
            Copy const& copy,
            Alloc const& alloc
        );

        template <typename Source>
        composite_base(
            ::odds_and_ends::composite_type::coercive_move_constructor_event const&,
            Source&& source
        );

        template <typename Source, typename Alloc>
        composite_base(
            ::odds_and_ends::composite_type::coercive_move_constructor_event const&,
            Source&& source,
            Alloc const& alloc
        );

        ~composite_base();

        template <typename ...Args>
        bool
            post_construct(
                ::odds_and_ends::composite_type::conversion_assignment_event const&,
                Args&&...
            );

        template <typename ...Args>
        bool
            post_construct(
                ::odds_and_ends::composite_type::constructor_2nd_stage_event const&,
                Args&&...
            );

        template <typename ...Args>
        bool listen_to(::odds_and_ends::composite_type::operator_event const& e, Args&& ...args);

        template <typename ...Args>
        bool
            listen_to(
                ::odds_and_ends::composite_type::function_call_broadcast_event const& e,
                Args&& ...args
            );

        template <typename Event, typename ...Args>
        typename ::boost::disable_if<
            ::std::is_base_of< ::odds_and_ends::composite_type::constructor_2nd_stage_event,Event>,
            bool
        >::type
            handle(Event const& e, Args&& ...args);

    public:
        typename traits::const_reference derived() const;

        typename traits::reference derived();

        ODDS_AND_ENDS__COMPOSITE_TYPE__NONCOPYABLE_NONMOVABLE_BODY(composite_base)
    };
}}  // namespace odds_and_ends::composite_type

#include <utility>

namespace odds_and_ends { namespace composite_type {

    template <typename Derived>
    inline composite_base<Derived>::composite_base(
        ::odds_and_ends::composite_type::default_constructor_1st_stage_event const&
    )
    {
    }

    template <typename Derived>
    template <typename ...Args>
    inline composite_base<Derived>::composite_base(::std::allocator_arg_t const&, Args&& ...args)
    {
    }

    template <typename Derived>
    template <typename ...Args>
    inline composite_base<Derived>::composite_base(
        ::odds_and_ends::composite_type::variadic_constructor_1st_stage_event const&,
        Args&& ...args
    )
    {
    }

    template <typename Derived>
    template <typename ArgumentPack>
    inline composite_base<Derived>::composite_base(
        ::odds_and_ends::composite_type::arg_pack_constructor_1st_stage_event const&,
        ArgumentPack const& arg_pack
    )
    {
    }

    template <typename Derived>
    template <typename Copy>
    inline composite_base<Derived>::composite_base(
        ::odds_and_ends::composite_type::coercive_copy_constructor_event const&,
        Copy const& copy
    )
    {
    }

    template <typename Derived>
    template <typename Copy, typename Alloc>
    inline composite_base<Derived>::composite_base(
        ::odds_and_ends::composite_type::coercive_copy_constructor_event const&,
        Copy const& copy,
        Alloc const& alloc
    )
    {
    }

    template <typename Derived>
    template <typename Source>
    inline composite_base<Derived>::composite_base(
        ::odds_and_ends::composite_type::coercive_move_constructor_event const&,
        Source&& source
    )
    {
    }

    template <typename Derived>
    template <typename Source, typename Alloc>
    inline composite_base<Derived>::composite_base(
        ::odds_and_ends::composite_type::coercive_move_constructor_event const&,
        Source&& source,
        Alloc const& alloc
    )
    {
    }

    template <typename Derived>
    inline composite_base<Derived>::~composite_base()
    {
    }

    template <typename Derived>
    template <typename ...Args>
    inline bool
        composite_base<Derived>::post_construct(
            ::odds_and_ends::composite_type::conversion_assignment_event const&,
            Args&&...
        )
    {
        return true;
    }

    template <typename Derived>
    template <typename ...Args>
    inline bool
        composite_base<Derived>::post_construct(
            ::odds_and_ends::composite_type::constructor_2nd_stage_event const&,
            Args&&...
        )
    {
        return true;
    }

    template <typename Derived>
    template <typename ...Args>
    inline bool
        composite_base<Derived>::listen_to(
            ::odds_and_ends::composite_type::operator_event const&,
            Args&&...
        )
    {
        return true;
    }

    template <typename Derived>
    template <typename ...Args>
    inline bool
        composite_base<Derived>::listen_to(
            ::odds_and_ends::composite_type::function_call_broadcast_event const&,
            Args&&...
        )
    {
        return true;
    }

    template <typename Derived>
    template <typename Event, typename ...Args>
    inline typename ::boost::disable_if<
        ::std::is_base_of< ::odds_and_ends::composite_type::constructor_2nd_stage_event,Event>,
        bool
    >::type
        composite_base<Derived>::handle(Event const& e, Args&& ...args)
    {
        return this->derived().listen_to(e, ::std::forward<Args>(args)...);
    }

    template <typename Derived>
    inline typename composite_base<Derived>::traits::const_reference
        composite_base<Derived>::derived() const
    {
        return *static_cast<Derived const*>(this);
    }

    template <typename Derived>
    inline typename composite_base<Derived>::traits::reference composite_base<Derived>::derived()
    {
        return *static_cast<Derived*>(this);
    }
}}  // namespace odds_and_ends::composite_type

#endif  // ODDS_AND_ENDS__COMPOSITE_TYPE__COMPOSITE_BASE_HPP

