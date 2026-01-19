// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_PRE_DECREMENTABLE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_PRE_DECREMENTABLE_HPP

#include <odds_and_ends/static_introspection/declref.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename ResultPlaceholderExpr>
    struct is_pre_decrementable_impl :
        ::boost::mpl::apply1<
            ResultPlaceholderExpr,
            decltype(--::odds_and_ends::static_introspection::declmref<T>())
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/concept/_detail/has_pre_decrement_operator.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename ResultPlaceholderExpr>
    struct is_pre_decrementable :
        ::boost::mpl::if_<
            typename ::odds_and_ends::static_introspection::concept
            ::_detail::has_pre_decrement_operator<T>::type,
            ::odds_and_ends::static_introspection::concept::_detail
            ::is_pre_decrementable_impl<T,ResultPlaceholderExpr>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/is_lvalue_reference_of.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename ResultPlaceholderExpr>
    struct is_pre_decrementable :
        ::odds_and_ends::static_introspection::concept::_detail::is_pre_decrementable<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type,
            ResultPlaceholderExpr
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_PRE_DECREMENTABLE_HPP

