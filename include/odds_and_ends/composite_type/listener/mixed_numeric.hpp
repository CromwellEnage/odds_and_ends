// Copyright (C) 2012-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__COMPOSITE_TYPE__LISTENER__MIXED_NUMERIC_HPP
#define ODDS_AND_ENDS__COMPOSITE_TYPE__LISTENER__MIXED_NUMERIC_HPP

#include <type_traits>
#include <odds_and_ends/composite_type/listener_fwd.hpp>
#include <odds_and_ends/composite_type/event/addition_assignment.hpp>
#include <odds_and_ends/composite_type/event/subtraction_assignment.hpp>
#include <odds_and_ends/composite_type/event/multiplication_assignment.hpp>
#include <odds_and_ends/composite_type/event/division_assignment.hpp>
#include <odds_and_ends/composite_type/event/function_call_broadcast.hpp>
#include <odds_and_ends/composite_type/preprocessor/noncopyable_nonmovable_body.hpp>
#include <odds_and_ends/composite_type/preprocessor/stateless_body.hpp>
#include <boost/core/enable_if.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/empty_base.hpp>
#include <boost/integer/common_factor_rt.hpp>
#include <boost/assert.hpp>

namespace odds_and_ends { namespace composite_type {

    template <typename IntType>
    struct mixed_numeric_listener_generator
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

                    struct _result : _composite_parent_t
                    {
                    protected:
                        inline bool
                            listen_to(::odds_and_ends::composite_type::increment_event const& e)
                        {
                            bool result = _composite_parent_t::listen_to(e);
                            ++this->derived().integral_part_reference();
                            return result;
                        }

                        inline bool
                            listen_to(::odds_and_ends::composite_type::decrement_event const& e)
                        {
                            bool result = _composite_parent_t::listen_to(e);
                            --this->derived().integral_part_reference();
                            return result;
                        }

                        inline bool
                            listen_to(
                                ::odds_and_ends::composite_type
                                ::addition_assignment_event const& e,
                                Derived const& operand
                            )
                        {
                            bool result = _composite_parent_t::listen_to(e, operand);
                            this->_add(operand, false);
                            return result;
                        }

                        template <typename Operand>
                        inline typename ::boost::disable_if<
                            ::std::is_same<Operand,Derived>,
                            bool
                        >::type
                            listen_to(
                                ::odds_and_ends::composite_type
                                ::addition_assignment_event const& e,
                                Operand const& operand
                            )
                        {
                            bool result = _composite_parent_t::listen_to(e, operand);
                            this->_add(operand.derived(), false);
                            return result;
                        }

                        inline bool
                            listen_to(
                                ::odds_and_ends::composite_type
                                ::subtraction_assignment_event const& e,
                                Derived const& operand
                            )
                        {
                            bool result = _composite_parent_t::listen_to(e, operand);
                            this->_add(operand, true);
                            return result;
                        }

                        template <typename Operand>
                        inline typename ::boost::disable_if<
                            ::std::is_same<Operand,Derived>,
                            bool
                        >::type
                            listen_to(
                                ::odds_and_ends::composite_type
                                ::subtraction_assignment_event const& e,
                                Operand const& operand
                            )
                        {
                            bool result = _composite_parent_t::listen_to(e, operand);
                            this->_add(operand.derived(), true);
                            return result;
                        }

                        inline bool
                            listen_to(
                                ::odds_and_ends::composite_type
                                ::multiplication_assignment_event const& e,
                                Derived const& operand
                            )
                        {
                            bool result = _composite_parent_t::listen_to(e, operand);
                            this->_multiply(operand);
                            return result;
                        }

                        template <typename Operand>
                        inline typename ::boost::disable_if<
                            ::std::is_same<Operand,Derived>,
                            bool
                        >::type
                            listen_to(
                                ::odds_and_ends::composite_type
                                ::multiplication_assignment_event const& e,
                                Operand const& operand
                            )
                        {
                            bool result = _composite_parent_t::listen_to(e, operand);
                            this->_multiply(operand.derived());
                            return result;
                        }

                        inline bool
                            listen_to(
                                ::odds_and_ends::composite_type
                                ::division_assignment_event const& e,
                                Derived const& operand
                            )
                        {
                            bool result = _composite_parent_t::listen_to(e, operand);
                            Derived d = Derived(operand);
                            d.reciprocate();
                            this->_multiply(d);
                            return result;
                        }

                        template <typename Operand>
                        inline typename ::boost::disable_if<
                            ::std::is_same<Operand,Derived>,
                            bool
                        >::type
                            listen_to(
                                ::odds_and_ends::composite_type
                                ::division_assignment_event const& e,
                                Operand const& operand
                            )
                        {
                            bool result = _composite_parent_t::listen_to(e, operand);
                            Derived d = Derived(operand.derived());
                            d.reciprocate();
                            this->_multiply(d);
                            return result;
                        }

                        template <typename Event, typename ...Args>
                        inline typename ::boost::enable_if<
                            ::std::is_base_of<
                                ::odds_and_ends::composite_type::function_call_broadcast_event,
                                Event
                            >,
                            bool
                        >::type
                            listen_to(Event const& e, Args&& ...args)
                        {
                            return _composite_parent_t::listen_to(
                                e,
                                ::std::forward<Args>(args)...
                            );
                        }

                        ODDS_AND_ENDS__COMPOSITE_TYPE__STATELESS_BODY(_result, _composite_parent_t)
                        ODDS_AND_ENDS__COMPOSITE_TYPE__NONCOPYABLE_NONMOVABLE_BODY(_result)

                    private:
                        static inline void _error_check(Derived const& n)
                        {
                            BOOST_ASSERT(
                                (
                                    n.integral_part() < typename Derived::traits::integral_part(0)
                                ) ? (
                                    numerator(n.fractional_part()) <=
                                    typename Derived::traits::integral_part(0)
                                ) : (
                                    typename Derived::traits::integral_part(0) <=
                                    numerator(n.fractional_part())
                                )
                            );
                            BOOST_ASSERT(
                                typename Derived::traits::integral_part(0) <
                                denominator(n.fractional_part())
                            );
                            BOOST_ASSERT(
                                (
                                    numerator(n.fractional_part()) <
                                    typename Derived::traits::integral_part(0)
                                ) ? (
                                    -numerator(n.fractional_part()) <
                                    denominator(n.fractional_part())
                                ) : (
                                    numerator(n.fractional_part()) <
                                    denominator(n.fractional_part())
                                )
                            );
                        }

                        template <typename Operand>
                        inline void _add(Operand const& operand, bool negate_operand)
                        {
                            bool const is_negative_integral_part_0 = (
                                this->derived().integral_part() <
                                typename Derived::traits::integral_part(0)
                            );
                            bool const is_negative_integral_part_1 = (
                                operand.integral_part() <
                                typename Derived::traits::integral_part(0)
                            );
                            typename Derived::traits::integral_part const frac_numer_0 = numerator(
                                this->derived().fractional_part()
                            );
                            typename Derived::traits::integral_part const frac_numer_1 = numerator(
                                operand.fractional_part()
                            );
                            bool const is_negative_frac_numer_0 = (frac_numer_0 < 0);
                            bool const is_negative_frac_numer_1 = (frac_numer_1 < 0);
                            typename Derived::traits::integral_part const frac_denom_0 = (
                                denominator(this->derived().fractional_part())
                            );
                            typename Derived::traits::integral_part const frac_denom_1 = (
                                denominator(operand.fractional_part())
                            );
                            bool const is_negative_0 = (
                                is_negative_integral_part_0 || (
                                    (
                                        this->derived().integral_part() ==
                                        typename Derived::traits::integral_part(0)
                                    ) && is_negative_frac_numer_0
                                )
                            );
                            bool const is_negative_1 = (
                                is_negative_integral_part_1 || (
                                    (
                                        operand.integral_part() ==
                                        typename Derived::traits::integral_part(0)
                                    ) && is_negative_frac_numer_1
                                )
                            ) != negate_operand;
                            typename Derived::traits::integral_part const denominator_s = (
                                ::boost::integer::lcm(frac_denom_0, frac_denom_1)
                            );
                            typename Derived::traits::integral_part const abs_integral_part_0 = (
                                is_negative_integral_part_0
                            ) ? -this->derived().integral_part() : this->derived().integral_part();
                            typename Derived::traits::integral_part const abs_integral_part_1 = (
                                is_negative_integral_part_1
                            ) ? -operand.integral_part() : operand.integral_part();

                            if (is_negative_0 == is_negative_1)
                            {
                                // Step 1: Take the sum of the fractional parts.
                                typename Derived::traits::integral_part const numerator_s = (
                                    (
                                        denominator_s / frac_denom_0 * (
                                            is_negative_frac_numer_0 ? -frac_numer_0 : frac_numer_0
                                        )
                                    ) + (
                                        denominator_s / frac_denom_1 * (
                                            is_negative_frac_numer_1 ? -frac_numer_1 : frac_numer_1
                                        )
                                    )
                                );

                                // Step 2: Add the whole parts together.
                                // If the fractional sum is not proper,
                                // carry 1 over to the whole-part sum.
                                this->derived().integral_part_reference() = (
                                    (numerator_s < denominator_s) ?
                                    (abs_integral_part_0 + abs_integral_part_1) : (
                                        abs_integral_part_0 + abs_integral_part_1 +
                                        typename Derived::traits::integral_part(1)
                                    )
                                ) * typename Derived::traits::integral_part(
                                    is_negative_0 ? -1 : 1
                                );

                                // Step 3: Reduce the fractional sum.
                                // If it is not proper, subtract 1 to make it proper.
                                typename Derived::traits::integral_part const diff = (
                                    numerator_s < denominator_s
                                ) ? numerator_s : (numerator_s - denominator_s);

                                this->derived().fractional_part_reference() = (
                                    typename Derived::traits::fractional_part(
                                        (
                                            is_negative_0 ? -diff : diff
                                        ) / ::boost::integer::gcd(diff, denominator_s),
                                        denominator_s / ::boost::integer::gcd(diff, denominator_s)
                                    )
                                );
                            }
                            else if (abs_integral_part_0 == abs_integral_part_1)
                            {
                                this->derived().integral_part_reference() = (
                                    typename Derived::traits::integral_part(0)
                                );

                                typename Derived::traits::integral_part const
                                    frac_numer_1_actual = (
                                        negate_operand
                                    ) ? -frac_numer_1 : frac_numer_1;

                                if (
                                    frac_numer_1_actual * frac_denom_0 ==
                                    frac_numer_0 * frac_denom_1
                                )
                                {
                                    this->derived().fractional_part_reference() = (
                                        typename Derived::traits::fractional_part(0, 1)
                                    );
                                }
                                else
                                {
                                    this->derived().fractional_part_reference() = (
                                        typename Derived::traits::fractional_part(
                                            (denominator_s / frac_denom_1 * frac_numer_1_actual) +
                                            (denominator_s / frac_denom_0 * frac_numer_0),
                                            denominator_s
                                        )
                                    );
                                }
                            }
                            else
                            {
                                typename Derived::traits::integral_part const abs_frac_numer_0 = (
                                    is_negative_frac_numer_0
                                ) ? -frac_numer_0 : frac_numer_0;
                                typename Derived::traits::integral_part const abs_frac_numer_1 = (
                                    is_negative_frac_numer_1
                                ) ? -frac_numer_1 : frac_numer_1;

                                if (abs_integral_part_0 < abs_integral_part_1)
                                {
                                    if (
                                        abs_frac_numer_1 * frac_denom_0 <
                                        abs_frac_numer_0 * frac_denom_1
                                    )
                                    {
                                        this->derived().integral_part_reference() = (
                                            is_negative_1 ?
                                            (abs_integral_part_1 - abs_integral_part_0 - 1) :
                                            (abs_integral_part_0 - abs_integral_part_1 - 1)
                                        );
                                        this->derived().fractional_part_reference() = (
                                            is_negative_1 ?
                                            typename Derived::traits::fractional_part(
                                                (denominator_s / frac_denom_0 * abs_frac_numer_0) -
                                                (denominator_s / frac_denom_1 * abs_frac_numer_1),
                                                denominator_s
                                            ) : typename Derived::traits::fractional_part(
                                                (denominator_s / frac_denom_1 * abs_frac_numer_1) -
                                                (denominator_s / frac_denom_0 * abs_frac_numer_0),
                                                denominator_s
                                            )
                                        );
                                    }
                                    else
                                    {
                                        this->derived().integral_part_reference() = (
                                            is_negative_1 ?
                                            (abs_integral_part_1 - abs_integral_part_0) :
                                            (abs_integral_part_0 - abs_integral_part_1)
                                        );
                                        this->derived().fractional_part_reference() = (
                                            is_negative_1 ?
                                            typename Derived::traits::fractional_part(
                                                (denominator_s / frac_denom_1 * abs_frac_numer_1) -
                                                (denominator_s / frac_denom_0 * abs_frac_numer_0),
                                                denominator_s
                                            ) : typename Derived::traits::fractional_part(
                                                (denominator_s / frac_denom_0 * abs_frac_numer_0) -
                                                (denominator_s / frac_denom_1 * abs_frac_numer_1),
                                                denominator_s
                                            )
                                        );
                                    }
                                }
                                else
                                {
                                    if (
                                        abs_frac_numer_0 * frac_denom_1 <
                                        abs_frac_numer_1 * frac_denom_0
                                    )
                                    {
                                        this->derived().integral_part_reference() = (
                                            is_negative_0 ?
                                            (abs_integral_part_0 - abs_integral_part_1 - 1) :
                                            (abs_integral_part_1 - abs_integral_part_0 - 1)
                                        );
                                        this->derived().fractional_part_reference() = (
                                            is_negative_0 ?
                                            typename Derived::traits::fractional_part(
                                                (denominator_s / frac_denom_1 * abs_frac_numer_1) -
                                                (denominator_s / frac_denom_0 * abs_frac_numer_0),
                                                denominator_s
                                            ) : typename Derived::traits::fractional_part(
                                                (denominator_s / frac_denom_0 * abs_frac_numer_0) -
                                                (denominator_s / frac_denom_1 * abs_frac_numer_1),
                                                denominator_s
                                            )
                                        );
                                    }
                                    else
                                    {
                                        this->derived().integral_part_reference() = (
                                            is_negative_0 ?
                                            (abs_integral_part_0 - abs_integral_part_1) :
                                            (abs_integral_part_1 - abs_integral_part_0)
                                        );
                                        this->derived().fractional_part_reference() = (
                                            is_negative_0 ?
                                            typename Derived::traits::fractional_part(
                                                (denominator_s / frac_denom_0 * abs_frac_numer_0) -
                                                (denominator_s / frac_denom_1 * abs_frac_numer_1),
                                                denominator_s
                                            ) : typename Derived::traits::fractional_part(
                                                (denominator_s / frac_denom_1 * abs_frac_numer_1) -
                                                (denominator_s / frac_denom_0 * abs_frac_numer_0),
                                                denominator_s
                                            )
                                        );
                                    }
                                }
                            }
                        }

                        template <typename Operand>
                        inline void _multiply(Operand const& operand)
                        {
                            typename Derived::traits::fractional_part p_i0_f1(
                                numerator(operand.fractional_part()) *
                                this->derived().integral_part(),
                                denominator(operand.fractional_part())
                            );
                            typename Derived::traits::fractional_part p_i1_f0(
                                numerator(this->derived().fractional_part()) *
                                operand.integral_part(),
                                denominator(this->derived().fractional_part())
                            );
                            this->derived().integral_part_reference() *= operand.integral_part();
                            this->derived().fractional_part_reference() *= operand.fractional_part();
                            this->derived().fractional_part_reference() += p_i0_f1;
                            this->derived().fractional_part_reference() += p_i1_f0;
                            this->derived().normalize();
                        }
                    };

                public:
                    typedef _result type;
                };
            };
        };
    };
}}  // namespace odds_and_ends::composite_type

#endif  // ODDS_AND_ENDS__COMPOSITE_TYPE__LISTENER__MIXED_NUMERIC_HPP

