// Copyright (C) 2012-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__COMPOSITE_TYPE__OPERABLE__MULTIPLICATION_HPP
#define ODDS_AND_ENDS__COMPOSITE_TYPE__OPERABLE__MULTIPLICATION_HPP

#include <utility>
#include <odds_and_ends/composite_type/operable_fwd.hpp>
#include <odds_and_ends/composite_type/event/default_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/variadic_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/arg_pack_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/conversion_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/coercive_copy_constructor.hpp>
#include <odds_and_ends/composite_type/event/coercive_move_constructor.hpp>
#include <odds_and_ends/composite_type/event/multiplication_assignment.hpp>
#include <odds_and_ends/composite_type/preprocessor/noncopyable_nonmovable_body.hpp>
#include <odds_and_ends/composite_type/preprocessor/stateless_body.hpp>
#include <boost/mpl/apply_wrap.hpp>

namespace odds_and_ends { namespace composite_type {

    template <typename CompositeParentGenerator>
    struct multiplication_operable
    {
        typedef ::odds_and_ends::composite_type
        ::multiplication_operable<CompositeParentGenerator> type;

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

                template <typename Operand>
                inline Derived& operator*=(Operand const& operand)
                {
                    this->handle(
                        ::odds_and_ends::composite_type::multiplication_assignment_event(),
                        operand
                    );
                    return this->derived();
                }

                template <typename Operand>
                inline Derived operator*(Operand const& operand) const
                {
                    Derived result(this->derived());
                    result *= operand;
                    return result;
                }

                ODDS_AND_ENDS__COMPOSITE_TYPE__STATELESS_BODY(_result, _composite_parent_t)
                ODDS_AND_ENDS__COMPOSITE_TYPE__NONCOPYABLE_NONMOVABLE_BODY(_result)
            };

        public:
            typedef _result type;
        };
    };
}}  // namespace odds_and_ends::composite_type

#endif  // ODDS_AND_ENDS__COMPOSITE_TYPE__OPERABLE__MULTIPLICATION_HPP

