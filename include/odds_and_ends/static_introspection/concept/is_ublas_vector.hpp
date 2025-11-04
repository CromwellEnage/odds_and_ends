// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_UBLAS_VECTOR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_UBLAS_VECTOR_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_ublas_vector.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_minimal_range.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_bidirectional_range.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_bidirectional_iterator.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_ublas_vector :
        ::odds_and_ends::static_introspection::concept::_detail::is_minimal_range<
            T,
            ::odds_and_ends::static_introspection::concept
            ::is_legacy_bidirectional_iterator< ::boost::mpl::_>,
            ::odds_and_ends::static_introspection
            ::concept::_detail::ublas_vector_policy,
            ::odds_and_ends::static_introspection::concept
            ::_detail::has_bidirectional_range_members
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_UBLAS_VECTOR_HPP

