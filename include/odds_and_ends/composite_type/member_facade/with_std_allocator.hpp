// Copyright (C) 2012-2025 Cromwell D. Enage

#ifndef OODS_AND_ENDS__COMPOSITE_TYPE__MEMBER_FACADE__WITH_STD_ALLOCATOR_HPP
#define OODS_AND_ENDS__COMPOSITE_TYPE__MEMBER_FACADE__WITH_STD_ALLOCATOR_HPP

#include <type_traits>
#include <utility>
#include <memory>
#include <odds_and_ends/composite_type/operable_fwd.hpp>
#include <odds_and_ends/composite_type/preprocessor/noncopyable_nonmovable_body.hpp>
#include <odds_and_ends/composite_type/preprocessor/stateless_body.hpp>
#include <boost/mpl/apply_wrap.hpp>

namespace odds_and_ends { namespace composite_type {

    template <typename CompositeParentGenerator>
    struct with_std_allocator
    {
        typedef ::odds_and_ends::composite_type::with_std_allocator<CompositeParentGenerator> type;

        template <typename Derived>
        class apply
        {
            typedef typename ::boost::mpl::apply_wrap1<
                CompositeParentGenerator,
                Derived
            >::type _composite_parent_t;

            struct _result : _composite_parent_t
            {
                struct traits : _composite_parent_t::traits
                {
                    typedef ::std::allocator<Derived> allocator_type;
                    typedef allocator_type allocator_reference;
                };

                inline typename traits::allocator_type get_allocator() const
                {
                    return typename traits::allocator_type();
                }

                ODDS_AND_ENDS__COMPOSITE_TYPE__STATELESS_BODY(_result, _composite_parent_t)
                ODDS_AND_ENDS__COMPOSITE_TYPE__NONCOPYABLE_NONMOVABLE_BODY(_result)
            };

        public:
            typedef _result type;
        };
    };
}}  // namespace odds_and_ends::composite_type

#endif  // OODS_AND_ENDS__COMPOSITE_TYPE__MEMBER_FACADE__WITH_STD_ALLOCATOR_HPP

