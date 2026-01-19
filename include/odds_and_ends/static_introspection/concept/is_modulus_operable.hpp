// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MODULUS_OPERABLE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MODULUS_OPERABLE_HPP

#include <type_traits>
#include <utility>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename Divisor, typename Quotient>
    struct is_modulus_operable_impl
    {
        typedef typename ::boost::mpl::if_<
            ::std::is_convertible<
                decltype(::std::declval<T>() % ::std::declval<Divisor>()),
                typename ::odds_and_ends::static_introspection::remove_cvref<Quotient>::type
            >,
            ::boost::mpl::true_,
            ::boost::mpl::false_
        >::type type;
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename Divisor>
    class has_modulus_operator
    {
        template <typename B, typename D>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(::std::declval<B>() % ::std::declval<D>())
                >::type
            );

        template <typename B, typename D>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::concept::_detail
                ::has_modulus_operator<T,Divisor>::template _check<T,Divisor>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename Divisor, typename Quotient>
    struct is_modulus_operable
    {
        typedef typename ::boost::mpl::eval_if<
            typename ::odds_and_ends::static_introspection::concept
            ::_detail::has_modulus_operator<T,Divisor>::type,
            ::odds_and_ends::static_introspection::concept::_detail
            ::is_modulus_operable_impl<T,Divisor,Quotient>,
            ::boost::mpl::false_
        >::type type;
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/concept/is_modulus_assignable.hpp>
#include <odds_and_ends/use_default_policy.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename Divisor>
    struct is_modulus_operable<T,Divisor,::odds_and_ends::use_default_policy> :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::is_modulus_operable<T,Divisor,T>,
            ::boost::mpl::if_<
                ::std::is_const<T>,
                ::boost::mpl::true_,
                ::odds_and_ends::static_introspection::concept::is_modulus_assignable<T,Divisor>
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/remove_vref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename Divisor, typename Quotient>
    struct is_modulus_operable :
        ::odds_and_ends::static_introspection::concept::_detail::is_modulus_operable<
            typename ::odds_and_ends::static_introspection::remove_vref<T>::type,
            Divisor,
            Quotient
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MODULUS_OPERABLE_HPP

