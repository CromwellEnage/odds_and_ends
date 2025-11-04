// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_DIVIDABLE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_DIVIDABLE_HPP

#include <type_traits>
#include <utility>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename Divisor, typename Quotient>
    struct is_dividable_impl :
        ::boost::mpl::if_<
            ::std::is_convertible<
                decltype(::std::declval<T>() / ::std::declval<Divisor>()),
                typename ::odds_and_ends::static_introspection::remove_cvref<Quotient>::type
            >,
            ::boost::mpl::true_,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename Divisor>
    class has_division_op
    {
        template <typename B, typename D>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(::std::declval<B>() / ::std::declval<D>())
                >::type
            );

        template <typename B, typename D>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::concept::_detail
                ::has_division_op<T,Divisor>::template _check<T,Divisor>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };

    template <typename T, typename Divisor, typename Quotient>
    struct is_dividable :
        ::boost::mpl::if_<
            typename ::odds_and_ends::static_introspection
            ::concept::_detail::has_division_op<T,Divisor>::type,
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_dividable_impl<T,Divisor,Quotient>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/concept/is_division_assignable.hpp>
#include <odds_and_ends/use_default_policy.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename Divisor>
    struct is_dividable<T,Divisor,::odds_and_ends::use_default_policy> :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::is_dividable<T,Divisor,T>,
            ::boost::mpl::if_<
                ::std::is_const<T>,
                ::boost::mpl::true_,
                ::odds_and_ends::static_introspection::concept::is_division_assignable<T,Divisor>
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
    struct is_dividable :
        ::odds_and_ends::static_introspection::concept::_detail::is_dividable<
            typename ::odds_and_ends::static_introspection::remove_vref<T>::type,
            Divisor,
            Quotient
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_DIVIDABLE_HPP

