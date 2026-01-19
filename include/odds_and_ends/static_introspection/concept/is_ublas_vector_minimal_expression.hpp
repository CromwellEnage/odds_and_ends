// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_UBLAS_VECTOR_MINIMAL_EXPRESSION_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_UBLAS_VECTOR_MINIMAL_EXPRESSION_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/concept/_detail/has_bidirectional_range_minimal_members.hpp>
#include <odds_and_ends/static_introspection/remove_vref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename IteratorPlaceholderExpr>
    struct has_ublas_vector_minimal_expression_members :
        ::odds_and_ends::static_introspection::concept
        ::_detail::has_bidirectional_range_minimal_members<
            typename ::std::add_const<
                typename ::odds_and_ends::static_introspection::remove_vref<T>::type
            >::type,
            IteratorPlaceholderExpr
        >
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_minimal_range.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_ublas_vector_minimal_expression.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_bidirectional_iterator.hpp>
#include <boost/mpl/placeholders.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_ublas_vector_minimal_expression :
        ::odds_and_ends::static_introspection::concept::_detail::is_minimal_range<
            T,
            ::odds_and_ends::static_introspection::concept
            ::is_legacy_bidirectional_iterator< ::boost::mpl::_>,
            ::odds_and_ends::static_introspection::concept
            ::_detail::ublas_vector_minimal_expression_policy,
            ::odds_and_ends::static_introspection::concept
            ::_detail::has_ublas_vector_minimal_expression_members
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_UBLAS_VECTOR_MINIMAL_EXPRESSION_HPP

