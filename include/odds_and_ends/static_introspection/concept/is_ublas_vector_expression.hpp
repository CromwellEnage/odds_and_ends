// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_UBLAS_VECTOR_EXPRESSION_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_UBLAS_VECTOR_EXPRESSION_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_minimal_range.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_ublas_vector_expression.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/has_bidirectional_range_members.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_bidirectional_iterator.hpp>
#include <boost/mpl/placeholders.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_ublas_vector_expression :
        ::odds_and_ends::static_introspection::concept::_detail::is_minimal_range<
            T,
            ::odds_and_ends::static_introspection::concept
            ::is_legacy_bidirectional_iterator< ::boost::mpl::_>,
            ::odds_and_ends::static_introspection::concept
            ::_detail::ublas_vector_expression_policy,
            ::odds_and_ends::static_introspection::concept
            ::_detail::has_bidirectional_range_members
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_UBLAS_VECTOR_EXPRESSION_HPP

