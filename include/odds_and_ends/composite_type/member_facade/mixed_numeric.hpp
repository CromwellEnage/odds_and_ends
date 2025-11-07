// Copyright (C) 2012-2025 Cromwell D. Enage

#ifndef OODS_AND_ENDS__COMPOSITE_TYPE__MEMBER_FACADE__MIXED_NUMERIC_HPP
#define OODS_AND_ENDS__COMPOSITE_TYPE__MEMBER_FACADE__MIXED_NUMERIC_HPP

#include <type_traits>
#include <utility>
#include <odds_and_ends/composite_type/event/default_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/variadic_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/variadic_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/arg_pack_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/arg_pack_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/conversion_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/coercive_copy_constructor.hpp>
#include <odds_and_ends/composite_type/event/copy_assignment.hpp>
#include <odds_and_ends/composite_type/event/copy_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/coercive_move_constructor.hpp>
#include <odds_and_ends/composite_type/event/move_assignment.hpp>
#include <odds_and_ends/composite_type/event/move_2nd_stage.hpp>
#include <odds_and_ends/composite_type/parameter/integral_part.hpp>
#include <odds_and_ends/composite_type/parameter/fractional_part.hpp>
#include <odds_and_ends/composite_type/preprocessor/noncopyable_nonmovable_body.hpp>
//#include <odds_and_ends/static_introspection/concept/is_math_mixed_numeric_type.hpp>
#include <boost/multiprecision/number.hpp>
#include <boost/multiprecision/rational_adaptor.hpp>
#include <boost/core/enable_if.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/utility/value_init.hpp>

namespace odds_and_ends { namespace composite_type {

    template <typename IntBackend, typename FractionalBackend = void>
    struct mixed_numeric_member_facade
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

                    class _result : public _composite_parent_t
                    {
                        struct _enabler
                        {
                        };

                    public:
                        struct traits : _composite_parent_t::traits
                        {
                            typedef typename ::boost::mpl::if_<
                                ::std::is_void<FractionalBackend>,
                                ::boost::multiprecision::number<IntBackend>,
                                IntBackend
                            >::type integral_part;
                            typedef typename ::boost::mpl::if_<
                                ::std::is_void<FractionalBackend>,
                                ::boost::multiprecision::number<
                                    ::boost::multiprecision::rational_adaptor<IntBackend>
                                >,
                                FractionalBackend
                            >::type fractional_part;
                        };

                    private:
                        typename traits::integral_part _integral_part;
                        typename traits::fractional_part _fractional_part;

                    protected:
                        inline explicit _result(
                            ::odds_and_ends::composite_type
                            ::default_constructor_1st_stage_event const& e
                        ) : _composite_parent_t(e),
                            _integral_part(::boost::initialized_value),
                            _fractional_part()
                        {
                        }

                        template <typename A0, typename ...Args>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::variadic_constructor_1st_stage_event const& e,
                            A0&& a0,
                            Args&& ...args
                        ) : _composite_parent_t(
                                e,
                                ::std::forward<A0>(a0),
                                ::std::forward<Args>(args)...
                            ),
                            _integral_part(::std::forward<A0>(a0)),
                            _fractional_part(::std::forward<Args>(args)...)
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
                            bool const result = _composite_parent_t::post_construct(
                                e,
                                ::std::forward<A0>(a0),
                                ::std::forward<Args>(args)...
                            );
                            this->normalize();
                            return result;
                        }

                        template <typename ArgumentPack>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::arg_pack_constructor_1st_stage_event const& e,
                            ArgumentPack const& arg_pack
                        ) : _composite_parent_t(e, arg_pack),
                            _integral_part(
                                arg_pack[
                                    ::odds_and_ends::composite_type::parameter::integral_part
                                ]
                            ),
                            _fractional_part(
                                arg_pack[
                                    ::odds_and_ends::composite_type::parameter::fractional_part
                                ]
                            )
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
                            bool const result = _composite_parent_t::post_construct(e, arg_pack);
                            this->normalize();
                            return result;
                        }

                        template <typename Arg>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::conversion_constructor_1st_stage_event const& e,
                            Arg const& arg,
                            typename ::boost::enable_if<
                                ::std::is_convertible<Arg,typename traits::integral_part>,
                                _enabler
                            >::type = _enabler()
                        ) : _composite_parent_t(e, arg), _integral_part(arg), _fractional_part()
                        {
                        }

                        template <typename Copy>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::coercive_copy_constructor_event const& e,
                            Copy const& copy/*,
                            typename ::boost::enable_if<
                                ::odds_and_ends::static_introspection
                                ::concept::is_math_mixed_numeric_type<Copy>,
                                _enabler
                            >::type = _enabler()*/
                        ) : _composite_parent_t(e, copy),
                            _integral_part(copy.integral_part()),
                            _fractional_part(copy.fractional_part())
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
                            this->_integral_part = copy.integral_part();
                            this->_fractional_part = copy.fractional_part();
                            return result;
                        }

                        template <typename Copy>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::copy_2nd_stage_event const& e,
                                Copy const& copy
                            )
                        {
                            bool const result = _composite_parent_t::post_construct(e, copy);
                            this->normalize();
                            return result;
                        }

                        template <typename Source>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::coercive_move_constructor_event const& e,
                            Source&& source/*,
                            typename ::boost::enable_if<
                                ::odds_and_ends::static_introspection
                                ::concept::is_math_mixed_numeric_type<Source>,
                                _enabler
                            >::type = _enabler()*/
                        ) : _composite_parent_t(e, static_cast<Source&&>(source)),
                            _integral_part(::std::move(source.integral_part_reference())),
                            _fractional_part(::std::move(source.fractional_part_reference()))
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
                            this->_integral_part = ::std::move(source.integral_part_reference());
                            this->_fractional_part = ::std::move(
                                source.fractional_part_reference()
                            );
                            return result;
                        }

                        template <typename Source>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::move_2nd_stage_event const& e,
                                Source&& source
                            )
                        {
                            bool const result = _composite_parent_t::post_construct(
                                e,
                                static_cast<Source&&>(source)
                            );
                            this->normalize();
                            return result;
                        }

                        inline typename traits::integral_part const&
                            integral_part_reference() const
                        {
                            return this->_integral_part;
                        }

                        inline typename traits::integral_part&
                            integral_part_reference()
                        {
                            return this->_integral_part;
                        }

                        inline typename traits::fractional_part const&
                            fractional_part_reference() const
                        {
                            return this->_fractional_part;
                        }

                        inline typename traits::fractional_part&
                            fractional_part_reference()
                        {
                            return this->_fractional_part;
                        }

                        inline void normalize()
                        {
                            if (
                                numerator(this->_fractional_part) <
                                typename traits::integral_part(0)
                            )
                            {
                                if (!(
                                    -numerator(this->_fractional_part) <
                                    denominator(this->_fractional_part)
                                ))
                                {
                                    // Make _fractional_part a proper fraction
                                    // by giving _integral_part the excess.
                                    typename traits::integral_part const d = (
                                        -numerator(this->_fractional_part) /
                                        denominator(this->_fractional_part)
                                    );

                                    this->_integral_part -= d;
                                    this->_fractional_part += d;
                                }

                                if (typename traits::integral_part(0) < this->_integral_part)
                                {
                                    // Make _fractional_part and _integral_part both positive.
                                    --this->_integral_part;
                                    this->_fractional_part = (
                                        typename traits::fractional_part(1) -
                                        this->_fractional_part
                                    );
                                }
                            }
                            else if (
                                typename traits::integral_part(0) <
                                numerator(this->_fractional_part)
                            )
                            {
                                if (!(
                                    numerator(this->_fractional_part) <
                                    denominator(this->_fractional_part)
                                ))
                                {
                                    // Make _fractional_part a proper fraction
                                    // by giving _integral_part the excess.
                                    typename traits::integral_part const d = (
                                        numerator(this->_fractional_part) /
                                        denominator(this->_fractional_part)
                                    );

                                    this->_integral_part += d;
                                    this->_fractional_part -= d;
                                }

                                if (this->_integral_part < (typename traits::integral_part(0)))
                                {
                                    // Make _fractional_part and _integral_part both negative.
                                    ++this->_integral_part;
                                    this->_fractional_part = (
                                        typename traits::fractional_part(1) -
                                        this->_fractional_part
                                    );
                                }
                            }
                        }

                        inline void reciprocate()
                        {
                            typename traits::integral_part const frac_numer = numerator(
                                this->_fractional_part
                            );
                            typename traits::integral_part const frac_denom = denominator(
                                this->_fractional_part
                            );
                            bool const is_negative = (
                                this->_integral_part < typename traits::integral_part(0)
                            ) || (
                                (typename traits::integral_part(0) == this->_integral_part) &&
                                (frac_numer < 0)
                            );
                            typename traits::integral_part const abs_integral_part = (
                                this->_integral_part < typename traits::integral_part(0)
                            ) ? -this->_integral_part : this->_integral_part;
                            typename traits::integral_part const abs_frac_numer = (
                                frac_numer < 0
                            ) ? -frac_numer : frac_numer;

                            if (0 == abs_integral_part)
                            {
                                this->_integral_part = typename traits::integral_part(
                                    (is_negative ? -frac_denom : frac_denom) / abs_frac_numer
                                );
                                this->_fractional_part = typename traits::fractional_part(
                                    (is_negative ? -frac_denom : frac_denom) % abs_frac_numer,
                                    abs_frac_numer
                                );
                            }
                            else
                            {
                                this->_integral_part = typename traits::integral_part(0);
                                this->_fractional_part = typename traits::fractional_part(
                                    (is_negative ? -frac_denom : frac_denom),
                                    abs_integral_part * frac_denom + abs_frac_numer
                                );
                            }
                        }

                    public:
                        inline ~_result()
                        {
                        }

                        inline typename traits::integral_part const& integral_part() const
                        {
                            return this->_integral_part;
                        }

                        inline typename traits::fractional_part const& fractional_part() const
                        {
                            return this->_fractional_part;
                        }

                        inline Derived operator+() const
                        {
                            return Derived(this->derived());
                        }

                        inline Derived operator-() const
                        {
                            return Derived(
                                ::odds_and_ends::composite_type::parameter
                                ::integral_part = -this->integral_part(),
                                ::odds_and_ends::composite_type::parameter
                                ::fractional_part = -this->fractional_part()
                            );
                        }

                        friend inline bool operator==(Derived const& lhs, Derived const& rhs)
                        {
                            return (
                                (lhs.integral_part() == rhs.integral_part()) &&
                                (lhs.fractional_part() == rhs.fractional_part())
                            );
                        }

                        friend inline bool operator!=(Derived const& lhs, Derived const& rhs)
                        {
                            return !(lhs == rhs);
                        }

                        friend inline bool operator<(Derived const& lhs, Derived const& rhs)
                        {
                            return (
                                (lhs.integral_part() < rhs.integral_part()) || (
                                    !(lhs.integral_part() == rhs.integral_part()) &&
                                    (lhs.fractional_part() < rhs.fractional_part())
                                )
                            );
                        }

                        friend inline bool operator>(Derived const& lhs, Derived const& rhs)
                        {
                            return (
                                (rhs.integral_part() < lhs.integral_part()) || (
                                    !(rhs.integral_part() == lhs.integral_part()) &&
                                    (rhs.fractional_part() < lhs.fractional_part())
                                )
                            );
                        }

                        friend inline bool operator<=(Derived const& lhs, Derived const& rhs)
                        {
                            return !(lhs > rhs);
                        }

                        friend inline bool operator>=(Derived const& lhs, Derived const& rhs)
                        {
                            return !(lhs < rhs);
                        }

                        friend inline Derived abs(Derived const& n)
                        {
                            return (n < Derived(0)) ? -n : +n;
                        }

                        friend inline typename traits::integral_part numerator(Derived const& n)
                        {
                            return (
                                denominator(n._fractional_part) * n._integral_part +
                                numerator(n._fractional_part)
                            );
                        }

                        friend inline typename traits::integral_part denominator(Derived const& n)
                        {
                            return denominator(n._fractional_part);
                        }

                        ODDS_AND_ENDS__COMPOSITE_TYPE__NONCOPYABLE_NONMOVABLE_BODY(_result)
                    };

                public:
                    typedef _result type;
                };
            };
        };
    };
}}  // namespace odds_and_ends::composite_type

#endif  // OODS_AND_ENDS__COMPOSITE_TYPE__MEMBER_FACADE__MIXED_NUMERIC_HPP

