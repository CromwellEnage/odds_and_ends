// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_DIVISION_ASSIGNABLE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_DIVISION_ASSIGNABLE_HPP

#include <utility>
#include <odds_and_ends/static_introspection/declref.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename Divisor, typename ResultPlaceholderExpr>
    struct is_division_assignable_impl :
        ::boost::mpl::apply1<
            ResultPlaceholderExpr,
            decltype(
                ::odds_and_ends::static_introspection::declmref<T>() /= ::std::declval<Divisor>()
            )
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <type_traits>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename Div>
    class has_division_assignable_expr
    {
        template <typename B, typename D>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(
                        ::odds_and_ends::static_introspection::declmref<B>() /= ::std::declval<D>()
                    )
                >::type
            );

        template <typename B, typename D>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::concept::_detail
                ::has_division_assignable_expr<T,Div>::template _check<T,Div>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/remove_vref.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <
        typename T,
        typename ResultPlaceholderExpr,
        typename Divisor = typename ::std::add_const<
            typename ::odds_and_ends::static_introspection::remove_vref<T>::type
        >::type
    >
    struct is_division_assignable_nvt :
        ::boost::mpl::if_<
            typename ::odds_and_ends::static_introspection::concept
            ::_detail::has_division_assignable_expr<T,Divisor>::type,
            ::odds_and_ends::static_introspection::concept::_detail
            ::is_division_assignable_impl<T,Divisor,ResultPlaceholderExpr>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/nested_type/value_type_of.hpp>
#include <odds_and_ends/static_introspection/is_lvalue_reference_of.hpp>
#include <boost/mpl/placeholders.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <
        typename T,
        typename ResultPlaceholderExpr,
        typename Divisor = typename ::std::add_const<
            typename ::odds_and_ends::static_introspection::remove_vref<T>::type
        >::type
    >
    struct is_division_assignable_wvt :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::concept::_detail::is_division_assignable_nvt<
                typename ::odds_and_ends::static_introspection
                ::nested_type::value_type_of<T>::type,
                ::odds_and_ends::static_introspection::is_lvalue_reference_of<
                    ::boost::mpl::_,
                    typename ::odds_and_ends::static_introspection
                    ::nested_type::value_type_of<T>::type
                >,
                Divisor
            >,
            ::odds_and_ends::static_introspection::concept::_detail
            ::is_division_assignable_nvt<T,ResultPlaceholderExpr,Divisor>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_ublas_expression.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename Divisor, typename ResultPlaceholderExpr>
    struct is_division_assignable :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection
            ::concept::_detail::is_ublas_expression<T>,
            ::odds_and_ends::static_introspection::concept::_detail
            ::is_division_assignable_wvt<T,ResultPlaceholderExpr,Divisor>,
            ::odds_and_ends::static_introspection::concept::_detail
            ::is_division_assignable_nvt<T,ResultPlaceholderExpr,Divisor>
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#include <odds_and_ends/use_default_policy.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename ResultPlaceholderExpr>
    struct is_division_assignable<
        T,
        ::odds_and_ends::use_default_policy,
        ResultPlaceholderExpr
    > : ::boost::mpl::if_<
            ::odds_and_ends::static_introspection
            ::concept::_detail::is_ublas_expression<T>,
            ::odds_and_ends::static_introspection::concept::_detail
            ::is_division_assignable_wvt<T,ResultPlaceholderExpr>,
            ::odds_and_ends::static_introspection::concept::_detail
            ::is_division_assignable_nvt<T,ResultPlaceholderExpr>
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_DIVISION_ASSIGNABLE_HPP

