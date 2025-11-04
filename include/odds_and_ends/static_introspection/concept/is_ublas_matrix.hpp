// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_UBLAS_MATRIX_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_UBLAS_MATRIX_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_container.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_ublas_matrix.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_bidirectional_iterator.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename IsStrict>
    struct is_ublas_matrix :
        ::boost::mpl::if_<
            IsStrict,
            ::odds_and_ends::static_introspection::concept::_detail::is_container<
                T,
                ::odds_and_ends::static_introspection::concept
                ::is_legacy_bidirectional_iterator< ::boost::mpl::_>,
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_base_ublas_matrix_expression,
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_mutable_ublas_matrix_strict,
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_const_ublas_matrix_expression,
                ::odds_and_ends::static_introspection::concept
                ::_detail::has_ublas_matrix_expression_iterators
            >,
            ::odds_and_ends::static_introspection::concept::_detail::is_container<
                T,
                ::odds_and_ends::static_introspection::concept
                ::is_legacy_bidirectional_iterator< ::boost::mpl::_>,
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_base_ublas_matrix_expression,
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_mutable_ublas_matrix_non_strict,
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_const_ublas_matrix_expression,
                ::odds_and_ends::static_introspection::concept
                ::_detail::has_ublas_matrix_expression_iterators
            >
        >::type
    {
    };
}}}  // namespace boost::concept::traits

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_UBLAS_MATRIX_HPP

