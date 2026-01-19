// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_SUBTRACTION_ASSIGNABLE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_SUBTRACTION_ASSIGNABLE_HPP

#include <utility>
#include <odds_and_ends/static_introspection/declref.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename Subtrahend, typename ResultPlaceholderExpr>
    struct is_subtraction_assignable :
        ::boost::mpl::apply1<
            ResultPlaceholderExpr,
            decltype(
                ::odds_and_ends::static_introspection::declmref<T>() -=
                ::std::declval<Subtrahend>()
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
    struct is_subtraction_assignable<
        T,
        ::odds_and_ends::use_default_policy,
        ResultPlaceholderExpr
    > : ::odds_and_ends::static_introspection::concept::_detail::is_subtraction_assignable<
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

    template <typename T, typename Su>
    class has_subtraction_assignment_operator
    {
        template <typename B, typename D>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(
                        ::odds_and_ends::static_introspection::declmref<B>() -=
                        ::std::declval<D>()
                    )
                >::type
            );

        template <typename B, typename D>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::concept::_detail
                ::has_subtraction_assignment_operator<T,Su>::template _check<T,Su>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };

    template <typename T>
    class has_subtraction_assignment_operator<T,::odds_and_ends::use_default_policy> :
        public ::odds_and_ends::static_introspection::concept
        ::_detail::has_subtraction_assignment_operator<
            T,
            typename ::std::add_const<
                typename ::odds_and_ends::static_introspection::remove_vref<T>::type
            >::type
        >
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/is_lvalue_reference_of.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename Subtrahend, typename ResultPlaceholderExpr>
    struct is_subtraction_assignable :
        ::boost::mpl::if_<
            typename ::odds_and_ends::static_introspection::concept::_detail
            ::has_subtraction_assignment_operator<T,Subtrahend>::type,
            ::odds_and_ends::static_introspection::concept::_detail
            ::is_subtraction_assignable<T,Subtrahend,ResultPlaceholderExpr>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_SUBTRACTION_ASSIGNABLE_HPP

