// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_LVALUE_ASSIGNABLE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_LVALUE_ASSIGNABLE_HPP

#include <odds_and_ends/static_introspection/declref.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename Value, typename ResultPlaceholderExpr>
    struct is_lvalue_assignable_impl :
        ::boost::mpl::apply1<
            ResultPlaceholderExpr,
            decltype(
                ::odds_and_ends::static_introspection::declmref<T>() =
                ::odds_and_ends::static_introspection::declref<Value>()
            )
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/use_default_policy.hpp>
#include <odds_and_ends/static_introspection/remove_vref.hpp>
#include <type_traits>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename ResultPlaceholderExpr>
    struct is_lvalue_assignable_impl<
        T,
        ::odds_and_ends::use_default_policy,
        ResultPlaceholderExpr
    > : ::odds_and_ends::static_introspection::concept::_detail::is_lvalue_assignable_impl<
            T,
            typename ::std::add_const<
                typename ::odds_and_ends::static_introspection::remove_vref<T>::type
            >::type,
            ResultPlaceholderExpr
        >
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <boost/mpl/bool.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename Value>
    class has_lvalue_assignment_operator
    {
        template <typename B, typename V>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(
                        ::odds_and_ends::static_introspection::declmref<B>() =
                        ::odds_and_ends::static_introspection::declref<V>()
                    )
                >::type
            );

        template <typename B, typename V>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::concept::_detail
                ::has_lvalue_assignment_operator<T,Value>::template _check<T,Value>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };

    template <typename T>
    class has_lvalue_assignment_operator<T,::odds_and_ends::use_default_policy> :
        public ::odds_and_ends::static_introspection
        ::concept::_detail::has_lvalue_assignment_operator<
            T,
            typename ::std::add_const<
                typename ::odds_and_ends::static_introspection::remove_vref<T>::type
            >::type
        >
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/is_convertible_to_cref_of.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename Value, typename ResultPlaceholderExpr>
    struct is_lvalue_assignable :
        ::boost::mpl::if_<
            typename ::odds_and_ends::static_introspection::concept
            ::_detail::has_lvalue_assignment_operator<T,Value>::type,
            ::odds_and_ends::static_introspection::concept::_detail
            ::is_lvalue_assignable_impl<T,Value,ResultPlaceholderExpr>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_LVALUE_ASSIGNABLE_HPP

