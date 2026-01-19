// Copyright (C) 2012-2026 Cromwell D. Enage

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
#include <odds_and_ends/composite_type/composite_base.hpp>
#include <odds_and_ends/static_introspection/concept/is_allocator.hpp>
#include <boost/core/enable_if.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/quote.hpp>
#include <boost/parameter.hpp>

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

        template <typename ArgPack>
        explicit composite_type(
            ArgPack const& arg_pack,
            typename ::boost::enable_if<
                ::boost::parameter::is_argument_pack<ArgPack>,
                _enabler
            >::type = _enabler()
        );

        template <typename Alloc>
        explicit composite_type(
            Alloc const& alloc,
            typename ::boost::enable_if<
                typename ::boost::mpl::if_<
                    ::boost::parameter::is_argument_pack<Alloc>,
                    ::boost::mpl::false_,
                    ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename Arg>
        explicit composite_type(
            Arg&& arg,
            typename ::boost::disable_if<
                typename ::boost::mpl::if_<
                    ::boost::parameter::is_argument_pack<Arg>,
                    ::boost::mpl::true_,
                    ::odds_and_ends::static_introspection::concept::is_allocator<Arg>
                >::type,
                _enabler
            >::type = _enabler()
        );

        template <typename Arg0, typename Arg1, typename ...Args>
        composite_type(Arg0&& arg0, Arg1&& arg1, Args&& ...args);

        template <typename Alloc>
        composite_type(composite_type const& copy, Alloc const& alloc);

        template <typename Alloc>
        composite_type(composite_type&& source, Alloc const& alloc);

        composite_type(composite_type const& copy);
        composite_type(composite_type&& source);
        composite_type();
        ~composite_type();
        composite_type& operator=(composite_type const& copy);
        composite_type& operator=(composite_type&& source);
        void swap(composite_type& other);

        template <typename Arg>
        typename ::boost::disable_if< ::std::is_same<Arg,composite_type>,composite_type&>::type
            operator=(Arg&& arg);

    private:
        void _assign(composite_type const& copy, ::boost::mpl::true_);
        void _assign(composite_type const& copy, ::boost::mpl::false_);
        void _assign(composite_type&& source, ::boost::mpl::true_);
        void _assign(composite_type&& source, ::boost::mpl::false_);

        friend struct ::odds_and_ends::composite_type::composite_base<
            ::odds_and_ends::composite_type::composite_type<CompositeParentGeneratorList>
        >;
    };
}}  // namespace odds_and_ends::composite_type

#include <utility>
#include <memory>
#include <odds_and_ends/composite_type/event/default_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/default_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/allocator_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/arg_pack_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/arg_pack_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/variadic_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/variadic_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/conversion_assignment.hpp>
#include <odds_and_ends/composite_type/event/coercive_copy_constructor.hpp>
#include <odds_and_ends/composite_type/event/copy_assignment.hpp>
#include <odds_and_ends/composite_type/event/copy_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/coercive_move_constructor.hpp>
#include <odds_and_ends/composite_type/event/move_assignment.hpp>
#include <odds_and_ends/composite_type/event/move_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/swap.hpp>
#include <odds_and_ends/static_introspection/member_function/has_get_allocator.hpp>

namespace odds_and_ends { namespace composite_type {

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
    template <typename ArgPack>
    inline composite_type<CompositeParentGeneratorList>::composite_type(
        ArgPack const& arg_pack,
        typename ::boost::enable_if< ::boost::parameter::is_argument_pack<ArgPack>,_enabler>::type
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

    template <typename CompositeParentGeneratorList>
    template <typename Alloc>
    inline composite_type<CompositeParentGeneratorList>::composite_type(
        Alloc const& alloc,
        typename ::boost::enable_if<
            typename ::boost::mpl::if_<
                ::boost::parameter::is_argument_pack<Alloc>,
                ::boost::mpl::false_,
                ::odds_and_ends::static_introspection::concept::is_allocator<Alloc>
            >::type,
            _enabler
        >::type
    ) : _composite_parent_t(::std::allocator_arg, alloc)
    {
        _composite_parent_t::post_construct(
            ::odds_and_ends::composite_type::allocator_constructor_2nd_stage_event(),
            alloc
        );
    }

    template <typename CompositeParentGeneratorList>
    template <typename Arg>
    inline composite_type<CompositeParentGeneratorList>::composite_type(
        Arg&& arg,
        typename ::boost::disable_if<
            typename ::boost::mpl::if_<
                ::boost::parameter::is_argument_pack<Arg>,
                ::boost::mpl::true_,
                ::odds_and_ends::static_introspection::concept::is_allocator<Arg>
            >::type,
            _enabler
        >::type
    ) : _composite_parent_t(
            ::odds_and_ends::composite_type::variadic_constructor_1st_stage_event(),
            ::std::forward<Arg>(arg)
        )
    {
        _composite_parent_t::post_construct(
            ::odds_and_ends::composite_type::variadic_constructor_2nd_stage_event(),
            ::std::forward<Arg>(arg)
        );
    }

    template <typename CompositeParentGeneratorList>
    template <typename Arg0, typename Arg1, typename ...Args>
    inline composite_type<CompositeParentGeneratorList>::composite_type(
        Arg0&& arg0,
        Arg1&& arg1,
        Args&& ...args
    ) : _composite_parent_t(
            typename ::boost::mpl::if_<
                typename ::boost::mpl::if_<
                    ::boost::parameter::is_argument_pack<Arg0>,
                    ::boost::mpl::false_,
                    ::odds_and_ends::static_introspection::concept::is_allocator<Arg0>
                >::type,
                ::std::allocator_arg_t,
                ::odds_and_ends::composite_type::variadic_constructor_1st_stage_event
            >::type(),
            ::std::forward<Arg0>(arg0),
            ::std::forward<Arg1>(arg1),
            ::std::forward<Args>(args)...
        )
    {
        _composite_parent_t::post_construct(
            typename ::boost::mpl::if_<
                typename ::boost::mpl::if_<
                    ::boost::parameter::is_argument_pack<Arg0>,
                    ::boost::mpl::false_,
                    ::odds_and_ends::static_introspection::concept::is_allocator<Arg0>
                >::type,
                ::odds_and_ends::composite_type::allocator_constructor_2nd_stage_event,
                ::odds_and_ends::composite_type::variadic_constructor_2nd_stage_event
            >::type(),
            ::std::forward<Arg0>(arg0),
            ::std::forward<Arg1>(arg1),
            ::std::forward<Args>(args)...
        );
    }

    template <typename CPGL>
    inline composite_type<CPGL>::composite_type(composite_type const& copy) :
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

    template <typename CPGL>
    template <typename Alloc>
    inline composite_type<CPGL>::composite_type(composite_type const& copy, Alloc const& alloc) :
        _composite_parent_t(
            ::odds_and_ends::composite_type::coercive_copy_constructor_event(),
            copy,
            alloc
        )
    {
        _composite_parent_t::post_construct(
            ::odds_and_ends::composite_type::copy_2nd_stage_event(),
            copy,
            alloc
        );
    }

    template <typename CompositeParentGeneratorList>
    inline composite_type<CompositeParentGeneratorList>::composite_type(composite_type&& source) :
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

    template <typename CPGL>
    template <typename Alloc>
    inline composite_type<CPGL>::composite_type(composite_type&& source, Alloc const& alloc) :
        _composite_parent_t(
            ::odds_and_ends::composite_type::coercive_move_constructor_event(),
            static_cast<composite_type&&>(source),
            alloc
        )
    {
        _composite_parent_t::post_construct(
            ::odds_and_ends::composite_type::move_2nd_stage_event(),
            static_cast<composite_type&&>(source),
            alloc
        );
    }

    template <typename CompositeParentGeneratorList>
    inline composite_type<CompositeParentGeneratorList>::~composite_type()
    {
    }

    template <typename CompositeParentGeneratorList>
    template <typename Arg>
    inline typename ::boost::disable_if<
        ::std::is_same<Arg,composite_type<CompositeParentGeneratorList> >,
        composite_type<CompositeParentGeneratorList>&
    >::type
        composite_type<CompositeParentGeneratorList>::operator=(Arg&& arg)
    {
        _composite_parent_t::post_construct(
            ::odds_and_ends::composite_type::conversion_assignment_event(),
            ::std::forward<Arg>(arg)
        );
        _composite_parent_t::post_construct(
            ::odds_and_ends::composite_type::variadic_constructor_2nd_stage_event(),
            ::std::forward<Arg>(arg)
        );
        return *this;
    }

    template <typename CompositeParentGeneratorList>
    inline void
        composite_type<CompositeParentGeneratorList>::_assign(
            composite_type const& copy,
            ::boost::mpl::true_
        )
    {
        _composite_parent_t::post_construct(
            ::odds_and_ends::composite_type::copy_assignment_event(),
            copy,
            copy.get_allocator()
        );
        _composite_parent_t::post_construct(
            ::odds_and_ends::composite_type::copy_2nd_stage_event(),
            copy,
            copy.get_allocator()
        );
    }

    template <typename CompositeParentGeneratorList>
    inline void
        composite_type<CompositeParentGeneratorList>::_assign(
            composite_type const& copy,
            ::boost::mpl::false_
        )
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

    template <typename CompositeParentGeneratorList>
    inline composite_type<CompositeParentGeneratorList>&
        composite_type<CompositeParentGeneratorList>::operator=(composite_type const& copy)
    {
        if (this != &copy)
        {
            this->_assign(
                copy,
                ::odds_and_ends::static_introspection
                ::member_function::has_get_allocator<composite_type>()
            );
        }

        return *this;
    }

    template <typename CompositeParentGeneratorList>
    inline void
        composite_type<CompositeParentGeneratorList>::_assign(
            composite_type&& source,
            ::boost::mpl::true_
        )
    {
        _composite_parent_t::post_construct(
            ::odds_and_ends::composite_type::move_assignment_event(),
            static_cast<composite_type&&>(source),
            source.get_allocator()
        );
        _composite_parent_t::post_construct(
            ::odds_and_ends::composite_type::move_2nd_stage_event(),
            static_cast<composite_type&&>(source),
            source.get_allocator()
        );
    }

    template <typename CompositeParentGeneratorList>
    inline void
        composite_type<CompositeParentGeneratorList>::_assign(
            composite_type&& source,
            ::boost::mpl::false_
        )
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

    template <typename CompositeParentGeneratorList>
    inline composite_type<CompositeParentGeneratorList>&
        composite_type<CompositeParentGeneratorList>::operator=(composite_type&& source)
    {
        if (this != &static_cast<composite_type&>(source))
        {
            this->_assign(
                static_cast<composite_type&&>(source),
                ::odds_and_ends::static_introspection
                ::member_function::has_get_allocator<composite_type>()
            );
        }

        return *this;
    }

    template <typename CompositeParentGeneratorList>
    inline void composite_type<CompositeParentGeneratorList>::swap(composite_type& other)
    {
        if (this != &other)
        {
            this->handle(
                ::odds_and_ends::composite_type::swap_event(),
                other
            );
        }
    }

    template <typename CompositeParentGeneratorList>
    inline void
        swap(
            composite_type<CompositeParentGeneratorList>& lhs,
            composite_type<CompositeParentGeneratorList>& rhs
        )
    {
        lhs.swap(rhs);
    }
}}  // namespace odds_and_ends::composite_type

#endif  // ODDS_AND_ENDS__COMPOSITE_TYPE__COMPOSITE_TYPE_HPP

