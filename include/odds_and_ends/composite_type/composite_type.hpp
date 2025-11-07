// Copyright (C) 2012-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__COMPOSITE_TYPE__COMPOSITE_TYPE_HPP
#define ODDS_AND_ENDS__COMPOSITE_TYPE__COMPOSITE_TYPE_HPP

#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/bind.hpp>

namespace odds_and_ends { namespace composite_type { namespace _detail {

    template <typename Derived, typename Base, typename GeneratorList>
    struct composite_type_base_gen :
        ::boost::mpl::apply_wrap1<
            typename ::boost::mpl::fold<
                GeneratorList,
                Base,
                ::boost::mpl::apply_wrap1<
                    ::boost::mpl::_2,
                    ::boost::mpl::_1
                >
            >::type,
            Derived
        >
    {
    };
}}}  // namespace odds_and_ends::composite_type::_detail

#include <type_traits>
#include <utility>
#include <odds_and_ends/composite_type/composite_base.hpp>
#include <odds_and_ends/composite_type/event/default_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/default_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/conversion_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/conversion_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/arg_pack_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/arg_pack_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/variadic_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/variadic_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/coercive_copy_constructor.hpp>
#include <odds_and_ends/composite_type/event/copy_assignment.hpp>
#include <odds_and_ends/composite_type/event/copy_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/coercive_move_constructor.hpp>
#include <odds_and_ends/composite_type/event/move_assignment.hpp>
#include <odds_and_ends/composite_type/event/move_2nd_stage.hpp>
#include <odds_and_ends/static_introspection/is_invocable.hpp>
#include <boost/parameter.hpp>
#include <boost/core/enable_if.hpp>

namespace odds_and_ends { namespace composite_type {

    template <typename CompositeParentGeneratorList>
    class composite_type :
        public ::odds_and_ends::composite_type::_detail::composite_type_base_gen<
            ::odds_and_ends::composite_type::composite_type<CompositeParentGeneratorList>,
            ::boost::mpl::quote1< ::odds_and_ends::composite_type::composite_base>,
            CompositeParentGeneratorList
        >::type
    {
        typedef typename ::odds_and_ends::composite_type::_detail::composite_type_base_gen<
            ::odds_and_ends::composite_type::composite_type<CompositeParentGeneratorList>,
            ::boost::mpl::quote1< ::odds_and_ends::composite_type::composite_base>,
            CompositeParentGeneratorList
        >::type _composite_parent_t;

        struct _enabler
        {
        };

    public:
        struct traits : _composite_parent_t::traits
        {
        };

        composite_type();

        template <typename ArgPack>
        inline composite_type(
            ArgPack const& arg_pack,
            typename ::boost::enable_if<
                ::boost::parameter::is_argument_pack<ArgPack>,
                _enabler
            >::type = _enabler()
        ) : _composite_parent_t(
                ::odds_and_ends::composite_type::arg_pack_constructor_1st_stage_event(),
                arg_pack
            )
        {
            _composite_parent_t::post_construct(
                ::odds_and_ends::composite_type::arg_pack_constructor_2nd_stage_event(),
                arg_pack
            );
        }

        template <typename Arg1>
        inline composite_type(
            Arg1 const& arg1,
            typename ::boost::disable_if<
                ::std::is_same<
                    ::odds_and_ends::composite_type::composite_type<CompositeParentGeneratorList>,
                    Arg1
                >,
                _enabler
            >::type = _enabler()
        ) : _composite_parent_t(
                ::odds_and_ends::composite_type::conversion_constructor_1st_stage_event(),
                arg1
            )
        {
            _composite_parent_t::post_construct(
                ::odds_and_ends::composite_type::conversion_constructor_2nd_stage_event(),
                arg1
            );
        }

        template <typename Arg1, typename Arg2, typename ...Args>
        composite_type(Arg1&& arg1, Arg2&& arg2, Args&& ...args);

        composite_type(composite_type const& copy);

        composite_type(composite_type&& source);

        ~composite_type();

        composite_type& operator=(composite_type const& copy);

        composite_type& operator=(composite_type&& source);

        friend struct ::odds_and_ends::composite_type::composite_base<
            ::odds_and_ends::composite_type::composite_type<CompositeParentGeneratorList>
        >;
    };

    template <typename CompositeParentGeneratorList>
    inline composite_type<CompositeParentGeneratorList>::composite_type() :
        _composite_parent_t(
            ::odds_and_ends::composite_type::default_constructor_1st_stage_event()
        )
    {
        _composite_parent_t::post_construct(
            ::odds_and_ends::composite_type::default_constructor_2nd_stage_event()
        );
    }

    template <typename CompositeParentGeneratorList>
    template <typename Arg1, typename Arg2, typename ...Args>
    inline composite_type<
        CompositeParentGeneratorList
    >::composite_type(Arg1&& arg1, Arg2&& arg2, Args&& ...args) :
        _composite_parent_t(
            ::odds_and_ends::composite_type::variadic_constructor_1st_stage_event(),
            ::std::forward<Arg1>(arg1),
            ::std::forward<Arg2>(arg2),
            ::std::forward<Args>(args)...
        )
    {
        _composite_parent_t::post_construct(
            ::odds_and_ends::composite_type::variadic_constructor_2nd_stage_event(),
            ::std::forward<Arg1>(arg1),
            ::std::forward<Arg2>(arg2),
            ::std::forward<Args>(args)...
        );
    }

    template <typename CompositeParentGeneratorList>
    inline composite_type<
        CompositeParentGeneratorList
    >::composite_type(composite_type const& copy) :
        _composite_parent_t(
            ::odds_and_ends::composite_type::coercive_copy_constructor_event(),
            copy
        )
    {
        _composite_parent_t::post_construct(
            ::odds_and_ends::composite_type::copy_2nd_stage_event(),
            copy
        );
    }

    template <typename CompositeParentGeneratorList>
    inline composite_type<
        CompositeParentGeneratorList
    >::composite_type(composite_type&& source) :
        _composite_parent_t(
            ::odds_and_ends::composite_type::coercive_move_constructor_event(),
            static_cast<composite_type&&>(source)
        )
    {
        _composite_parent_t::post_construct(
            ::odds_and_ends::composite_type::move_2nd_stage_event(),
            static_cast<composite_type&&>(source)
        );
    }

    template <typename CompositeParentGeneratorList>
    inline composite_type<CompositeParentGeneratorList>::~composite_type()
    {
    }

    template <typename CompositeParentGeneratorList>
    inline composite_type<CompositeParentGeneratorList>&
        composite_type<CompositeParentGeneratorList>::operator=(
            composite_type const& copy
        )
    {
        if (this != &copy)
        {
            _composite_parent_t::post_construct(
                ::odds_and_ends::composite_type::copy_assignment_event(),
                copy
            );
            _composite_parent_t::post_construct(
                ::odds_and_ends::composite_type::copy_2nd_stage_event(),
                copy
            );
        }

        return *this;
    }

    template <typename CompositeParentGeneratorList>
    inline composite_type<CompositeParentGeneratorList>&
        composite_type<CompositeParentGeneratorList>::operator=(
            composite_type&& source
        )
    {
        if (this != static_cast<composite_type&&>(source))
        {
            _composite_parent_t::post_construct(
                ::odds_and_ends::composite_type::move_assignment_event(),
                static_cast<composite_type&&>(source)
            );
            _composite_parent_t::post_construct(
                ::odds_and_ends::composite_type::move_2nd_stage_event(),
                static_cast<composite_type&&>(source)
            );
        }

        return *this;
    }
}}  // namespace odds_and_ends::composite_type

#endif  // ODDS_AND_ENDS__COMPOSITE_TYPE__COMPOSITE_TYPE_HPP

