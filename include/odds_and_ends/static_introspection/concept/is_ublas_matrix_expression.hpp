// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_UBLAS_MATRIX_EXPRESSION_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_UBLAS_MATRIX_EXPRESSION_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_ublas_matrix_expression.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_container.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_bidirectional_iterator.hpp>
#include <boost/mpl/placeholders.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_ublas_matrix_expression :
        ::odds_and_ends::static_introspection::concept::_detail::is_container<
            T,
            ::odds_and_ends::static_introspection::concept
            ::is_legacy_bidirectional_iterator< ::boost::mpl::_>,
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_base_ublas_matrix_expression,
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_mutable_ublas_matrix_expression,
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_const_ublas_matrix_expression,
            ::odds_and_ends::static_introspection::concept
            ::_detail::has_ublas_matrix_expression_iterators
        >
    {
    };
}}}  // namespace boost::concept::traits

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_UBLAS_MATRIX_EXPRESSION_HPP

