// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MODULUS_ASSIGNABLE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MODULUS_ASSIGNABLE_HPP

#include <utility>
#include <odds_and_ends/static_introspection/declref.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename Divisor, typename ResultPlaceholderExpr>
    struct is_modulus_assignable_impl
    {
        typedef typename ::boost::mpl::apply1<
            ResultPlaceholderExpr,
            decltype(
                ::odds_and_ends::static_introspection::declmref<T>() %= ::std::declval<Divisor>()
            )
        >::type type;
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <type_traits>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename Div>
    class has_modulus_assignable_expr
    {
        template <typename B, typename D>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(
                        ::odds_and_ends::static_introspection::declmref<B>() %= ::std::declval<D>()
                    )
                >::type
            );

        template <typename B, typename D>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::concept::_detail
                ::has_modulus_assignable_expr<T,Div>::template _check<T,Div>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/remove_vref.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <
        typename T,
        typename ResultPlaceholderExpr,
        typename Divisor = typename ::std::add_const<
            typename ::odds_and_ends::static_introspection::remove_vref<T>::type
        >::type
    >
    struct is_modulus_assignable_nvt
    {
        typedef typename ::boost::mpl::eval_if<
            typename ::odds_and_ends::static_introspection::concept
            ::_detail::has_modulus_assignable_expr<T,Divisor>::type,
            ::odds_and_ends::static_introspection::concept::_detail
            ::is_modulus_assignable_impl<T,Divisor,ResultPlaceholderExpr>,
            ::boost::mpl::false_
        >::type type;
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename Divisor, typename ResultPlaceholderExpr>
    struct is_modulus_assignable :
        ::odds_and_ends::static_introspection::concept::_detail
        ::is_modulus_assignable_nvt<T,ResultPlaceholderExpr,Divisor>::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#include <odds_and_ends/use_default_policy.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename ResultPlaceholderExpr>
    struct is_modulus_assignable<
        T,
        ::odds_and_ends::use_default_policy,
        ResultPlaceholderExpr
    > : ::odds_and_ends::static_introspection::concept::_detail
        ::is_modulus_assignable_nvt<T,ResultPlaceholderExpr>::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MODULUS_ASSIGNABLE_HPP

