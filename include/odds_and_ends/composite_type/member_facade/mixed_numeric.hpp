// Copyright (C) 2012-2026 Cromwell D. Enage

#ifndef OODS_AND_ENDS__COMPOSITE_TYPE__MEMBER_FACADE__MIXED_NUMERIC_HPP
#define OODS_AND_ENDS__COMPOSITE_TYPE__MEMBER_FACADE__MIXED_NUMERIC_HPP

#include <type_traits>
#include <utility>
#include <memory>
#include <odds_and_ends/composite_type/event/default_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/default_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/allocator_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/variadic_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/variadic_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/arg_pack_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/arg_pack_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/conversion_assignment.hpp>
#include <odds_and_ends/composite_type/event/coercive_copy_constructor.hpp>
#include <odds_and_ends/composite_type/event/copy_assignment.hpp>
#include <odds_and_ends/composite_type/event/copy_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/coercive_move_constructor.hpp>
#include <odds_and_ends/composite_type/event/move_assignment.hpp>
#include <odds_and_ends/composite_type/event/move_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/swap.hpp>
#include <odds_and_ends/composite_type/parameter/integral_part.hpp>
#include <odds_and_ends/composite_type/parameter/fractional_part.hpp>
#include <odds_and_ends/composite_type/preprocessor/noncopyable_nonmovable_body.hpp>
#include <odds_and_ends/static_introspection/concept/is_math_mixed_numeric_type.hpp>
#include <odds_and_ends/static_introspection/concept/is_math_rational_type.hpp>
#include <odds_and_ends/static_introspection/free_function/has_numerator.hpp>
#include <odds_and_ends/static_introspection/free_function/has_denominator.hpp>
#include <boost/multiprecision/number.hpp>
#include <boost/multiprecision/rational_adaptor.hpp>
#include <boost/core/enable_if.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
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
                            _fractional_part(::boost::initialized_value)
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

                        template <typename Arg>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::variadic_constructor_1st_stage_event const& e,
                            Arg&& arg,
                            typename ::boost::enable_if<
                                ::std::is_convertible<Arg,typename traits::integral_part>,
                                _enabler
                            >::type = _enabler()
                        ) : _composite_parent_t(e, ::std::forward<Arg>(arg)),
                            _integral_part(::std::forward<Arg>(arg)),
                            _fractional_part(::boost::initialized_value)
                        {
                        }

                        template <typename Arg>
                        inline typename ::boost::enable_if<
                            ::std::is_convertible<Arg,typename traits::integral_part>,
                            bool
                        >::type
                            post_construct(
                                ::odds_and_ends::composite_type
                                ::conversion_assignment_event const& e,
                                Arg&& arg
                            )
                        {
                            bool const result = (
                                _composite_parent_t::post_construct(e, ::std::forward<Arg>(arg))
                            );
                            this->_integral_part = ::std::forward<Arg>(arg);
                            this->_fractional_part = ::boost::initialized_value;
                            return result;
                        }

                        template <typename Arg>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::variadic_constructor_1st_stage_event const& e,
                            Arg&& arg,
                            typename ::boost::enable_if<
                                ::odds_and_ends::static_introspection
                                ::concept::is_math_rational_type<Arg>,
                                _enabler
                            >::type = _enabler()
                        ) : _composite_parent_t(e, ::std::forward<Arg>(arg)),
                            _integral_part(arg.numerator() / arg.denominator()),
                            _fractional_part(
                                arg.numerator() % arg.denominator(),
                                arg.denominator()
                            )
                        {
                        }

                        template <typename Arg>
                        inline typename ::boost::enable_if<
                            ::odds_and_ends::static_introspection
                            ::concept::is_math_rational_type<Arg>,
                            bool
                        >::type
                            post_construct(
                                ::odds_and_ends::composite_type
                                ::conversion_assignment_event const& e,
                                Arg&& arg
                            )
                        {
                            bool const result = (
                                _composite_parent_t::post_construct(e, ::std::forward<Arg>(arg))
                            );
                            this->_integral_part = arg.numerator() / arg.denominator();
                            this->_fractional_part = typename traits::fractional_part(
                                arg.numerator() % arg.denominator(),
                                arg.denominator()
                            );
                            return result;
                        }

                        template <typename Arg>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::variadic_constructor_1st_stage_event const& e,
                            Arg&& arg,
                            typename ::boost::enable_if<
                                typename ::boost::mpl::eval_if<
                                    ::odds_and_ends::static_introspection
                                    ::concept::is_math_mixed_numeric_type<Arg>,
                                    ::boost::mpl::false_,
                                    ::boost::mpl::if_<
                                        ::odds_and_ends::static_introspection
                                        ::free_function::has_numerator<Arg>,
                                        ::odds_and_ends::static_introspection
                                        ::free_function::has_denominator<Arg>,
                                        ::boost::mpl::false_
                                    >
                                >::type,
                                _enabler
                            >::type = _enabler()
                        ) : _composite_parent_t(e, ::std::forward<Arg>(arg)),
                            _integral_part(numerator(arg) / denominator(arg)),
                            _fractional_part(numerator(arg) % denominator(arg), denominator(arg))
                        {
                        }

                        template <typename Arg>
                        inline typename ::boost::enable_if<
                            typename ::boost::mpl::eval_if<
                                ::odds_and_ends::static_introspection
                                ::concept::is_math_mixed_numeric_type<Arg>,
                                ::boost::mpl::false_,
                                ::boost::mpl::if_<
                                    ::odds_and_ends::static_introspection
                                    ::free_function::has_numerator<Arg>,
                                    ::odds_and_ends::static_introspection
                                    ::free_function::has_denominator<Arg>,
                                    ::boost::mpl::false_
                                >
                            >::type,
                            bool
                        >::type
                            post_construct(
                                ::odds_and_ends::composite_type
                                ::conversion_assignment_event const& e,
                                Arg&& arg
                            )
                        {
                            bool const result = (
                                _composite_parent_t::post_construct(e, ::std::forward<Arg>(arg))
                            );
                            this->_integral_part = numerator(arg) / denominator(arg);
                            this->_fractional_part = typename traits::fractional_part(
                                numerator(arg) % denominator(arg),
                                denominator(arg)
                            );
                            return result;
                        }

                        template <typename Arg>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::variadic_constructor_1st_stage_event const& e,
                            Arg&& arg,
                            typename ::boost::enable_if<
                                ::std::is_base_of<
                                    ::std::integral_constant<
                                        int,
                                        ::boost::multiprecision::number_kind_rational
                                    >,
                                    ::boost::multiprecision::number_category<Arg>
                                >,
                                _enabler
                            >::type = _enabler()
                        ) : _composite_parent_t(e, ::std::forward<Arg>(arg)),
                            _integral_part(numerator(arg) / denominator(arg)),
                            _fractional_part(numerator(arg) % denominator(arg), denominator(arg))
                        {
                        }

                        template <typename Arg>
                        inline typename ::boost::enable_if<
                            ::std::is_base_of<
                                ::std::integral_constant<
                                    int,
                                    ::boost::multiprecision::number_kind_rational
                                >,
                                ::boost::multiprecision::number_category<Arg>
                            >,
                            bool
                        >::type
                            post_construct(
                                ::odds_and_ends::composite_type
                                ::conversion_assignment_event const& e,
                                Arg&& arg
                            )
                        {
                            bool const result = (
                                _composite_parent_t::post_construct(e, ::std::forward<Arg>(arg))
                            );
                            typename traits::fractional_part const tmp_arg(arg);
                            this->_integral_part = numerator(tmp_arg) / denominator(tmp_arg);
                            this->_fractional_part = typename traits::fractional_part(
                                numerator(tmp_arg) % denominator(tmp_arg),
                                denominator(tmp_arg)
                            );
                            return result;
                        }

                        template <typename Arg>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::variadic_constructor_1st_stage_event const& e,
                            Arg&& arg,
                            typename ::boost::enable_if<
                                ::odds_and_ends::static_introspection
                                ::concept::is_math_mixed_numeric_type<Arg>,
                                _enabler
                            >::type = _enabler()
                        ) : _composite_parent_t(e, ::std::forward<Arg>(arg)),
                            _integral_part(arg.integral_part()),
                            _fractional_part(arg.fractional_part())
                        {
                        }

                        template <typename Arg>
                        inline typename ::boost::enable_if<
                            ::odds_and_ends::static_introspection
                            ::concept::is_math_mixed_numeric_type<Arg>,
                            bool
                        >::type
                            post_construct(
                                ::odds_and_ends::composite_type
                                ::conversion_assignment_event const& e,
                                Arg&& arg
                            )
                        {
                            bool const result = (
                                _composite_parent_t::post_construct(e, ::std::forward<Arg>(arg))
                            );
                            this->_integral_part = arg.integral_part();
                            this->_fractional_part = arg.fractional_part();
                            return result;
                        }

                        template <typename A0, typename A1, typename ...Args>
                        inline _result(
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
                            _integral_part(::std::forward<A0>(a0)),
                            _fractional_part(::std::forward<A1>(a1), ::std::forward<Args>(args)...)
                        {
                        }

                        template <typename ...Args>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type
                                ::variadic_constructor_2nd_stage_event const& e,
                                Args&&... args
                            )
                        {
                            bool const result = _composite_parent_t::post_construct(
                                e,
                                ::std::forward<Args>(args)...
                            );
                            this->normalize();
                            return result;
                        }

                        template <typename Alloc>
                        inline _result(::std::allocator_arg_t const& o, Alloc const& alloc) :
                            _composite_parent_t(o, alloc),
                            _integral_part(::boost::initialized_value),
                            _fractional_part(::boost::initialized_value)
                        {
                        }

                        template <typename A0, typename A1, typename ...Args>
                        inline _result(
                            ::std::allocator_arg_t const& o,
                            A0&& a0,
                            A1&& a1,
                            Args&& ...args
                        ) : _composite_parent_t(
                                o,
                                ::std::forward<A0>(a0),
                                ::std::forward<A1>(a1),
                                ::std::forward<Args>(args)...
                            ),
                            _integral_part(::std::forward<A1>(a1)),
                            _fractional_part(::std::forward<Args>(args)...)
                        {
                        }

                        template <typename ...Args>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type
                                ::allocator_constructor_2nd_stage_event const& e,
                                Args&&... args
                            )
                        {
                            bool const result = _composite_parent_t::post_construct(
                                e,
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

                        template <typename Copy>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::coercive_copy_constructor_event const& e,
                            Copy const& copy,
                            typename ::boost::enable_if<
                                ::odds_and_ends::static_introspection
                                ::concept::is_math_mixed_numeric_type<Copy>,
                                _enabler
                            >::type = _enabler()
                        ) : _composite_parent_t(e, copy),
                            _integral_part(copy.integral_part()),
                            _fractional_part(copy.fractional_part())
                        {
                        }

                        template <typename Copy, typename Alloc>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::coercive_copy_constructor_event const& e,
                            Copy const& copy,
                            Alloc const& alloc,
                            typename ::boost::enable_if<
                                ::odds_and_ends::static_introspection
                                ::concept::is_math_mixed_numeric_type<Copy>,
                                _enabler
                            >::type = _enabler()
                        ) : _composite_parent_t(e, copy, alloc),
                            _integral_part(copy.integral_part()),
                            _fractional_part(copy.fractional_part())
                        {
                        }

                        template <typename Copy>
                        inline typename ::boost::enable_if<
                            ::odds_and_ends::static_introspection
                            ::concept::is_math_mixed_numeric_type<Copy>,
                            bool
                        >::type
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

                        template <typename Copy, typename Alloc>
                        inline typename ::boost::enable_if<
                            ::odds_and_ends::static_introspection
                            ::concept::is_math_mixed_numeric_type<Copy>,
                            bool
                        >::type
                            post_construct(
                                ::odds_and_ends::composite_type::copy_assignment_event const& e,
                                Copy const& copy,
                                Alloc const& alloc
                            )
                        {
                            bool const result = (
                                _composite_parent_t::post_construct(e, copy, alloc)
                            );
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

                        template <typename Copy, typename Alloc>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::copy_2nd_stage_event const& e,
                                Copy const& copy,
                                Alloc const& alloc
                            )
                        {
                            bool const result = (
                                _composite_parent_t::post_construct(e, copy, alloc)
                            );
                            this->normalize();
                            return result;
                        }

                        template <typename Source>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::coercive_move_constructor_event const& e,
                            Source&& source,
                            typename ::boost::enable_if<
                                ::odds_and_ends::static_introspection
                                ::concept::is_math_mixed_numeric_type<Source>,
                                _enabler
                            >::type = _enabler()
                        ) : _composite_parent_t(e, static_cast<Source&&>(source)),
                            _integral_part(::std::move(source.integral_part_reference())),
                            _fractional_part(::std::move(source.fractional_part_reference()))
                        {
                        }

                        template <typename Source, typename Alloc>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::coercive_move_constructor_event const& e,
                            Source&& source,
                            Alloc const& alloc,
                            typename ::boost::enable_if<
                                ::odds_and_ends::static_introspection
                                ::concept::is_math_mixed_numeric_type<Source>,
                                _enabler
                            >::type = _enabler()
                        ) : _composite_parent_t(e, static_cast<Source&&>(source), alloc),
                            _integral_part(::std::move(source.integral_part_reference())),
                            _fractional_part(::std::move(source.fractional_part_reference()))
                        {
                        }

                        template <typename Source>
                        inline typename ::boost::enable_if<
                            ::odds_and_ends::static_introspection
                            ::concept::is_math_mixed_numeric_type<Source>,
                            bool
                        >::type
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

                        template <typename Source, typename Alloc>
                        inline typename ::boost::enable_if<
                            ::odds_and_ends::static_introspection
                            ::concept::is_math_mixed_numeric_type<Source>,
                            bool
                        >::type
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

                        template <typename Source, typename Alloc>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::move_2nd_stage_event const& e,
                                Source&& source,
                                Alloc const& alloc
                            )
                        {
                            bool const result = _composite_parent_t::post_construct(
                                e,
                                static_cast<Source&&>(source),
                                alloc
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

                        inline bool
                            listen_to(
                                ::odds_and_ends::composite_type::swap_event const& e,
                                Derived& other
                            )
                        {
                            bool const result = _composite_parent_t::listen_to(e, other);
                            using ::std::swap;
                            swap(this->_integral_part, other.integral_part_reference());
                            swap(this->_fractional_part, other.fractional_part_reference());
                            return result;
                        }

                        template <typename Event, typename ...Args>
                        inline typename ::boost::disable_if<
                            ::std::is_same<Event,::odds_and_ends::composite_type::swap_event>,
                            bool
                        >::type
                            listen_to(Event const& e, Args&& ...args)
                        {
                            return _composite_parent_t::listen_to(
                                e,
                                ::std::forward<Args>(args)...
                            );
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

                        friend inline typename traits::integral_part const&
                            integral_part(Derived const& operand)
                        {
                            return operand.integral_part();
                        }

                        friend inline typename traits::fractional_part const&
                            fractional_part(Derived const& operand)
                        {
                            return operand.fractional_part();
                        }

                        friend inline Derived operator+(Derived const& operand)
                        {
                            return Derived(operand);
                        }

                        friend inline Derived operator-(Derived const& operand)
                        {
                            return Derived((
                                ::odds_and_ends::composite_type::parameter
                                ::integral_part = -operand.integral_part(),
                                ::odds_and_ends::composite_type::parameter
                                ::fractional_part = -operand.fractional_part()
                            ));
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
                                denominator(n.fractional_part()) * n.integral_part() +
                                numerator(n.fractional_part())
                            );
                        }

                        friend inline typename traits::integral_part denominator(Derived const& n)
                        {
                            return denominator(n.fractional_part());
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

