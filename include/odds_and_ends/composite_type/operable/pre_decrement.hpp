// Copyright (C) 2012-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__COMPOSITE_TYPE__OPERABLE__PRE_DECREMENT_HPP
#define ODDS_AND_ENDS__COMPOSITE_TYPE__OPERABLE__PRE_DECREMENT_HPP

#include <utility>
#include <odds_and_ends/composite_type/operable_fwd.hpp>
#include <odds_and_ends/composite_type/event/decrement.hpp>
#include <odds_and_ends/composite_type/preprocessor/noncopyable_nonmovable_body.hpp>
#include <odds_and_ends/composite_type/preprocessor/stateless_body.hpp>
#include <boost/mpl/apply_wrap.hpp>

namespace odds_and_ends { namespace composite_type {

    template <typename CompositeParentGenerator>
    struct pre_decrement_operable
    {
        typedef ::odds_and_ends::composite_type
        ::pre_decrement_operable<CompositeParentGenerator> type;

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
                };

                inline Derived& operator--()
                {
                    this->handle(::odds_and_ends::composite_type::decrement_event());
                    return this->derived();
                }

                ODDS_AND_ENDS__COMPOSITE_TYPE__STATELESS_BODY(_result, _composite_parent_t)
                ODDS_AND_ENDS__COMPOSITE_TYPE__NONCOPYABLE_NONMOVABLE_BODY(_result)
            };

        public:
            typedef _result type;
        };
    };
}}  // namespace odds_and_ends::composite_type

#endif  // ODDS_AND_ENDS__COMPOSITE_TYPE__OPERABLE__PRE_DECREMENT_HPP

