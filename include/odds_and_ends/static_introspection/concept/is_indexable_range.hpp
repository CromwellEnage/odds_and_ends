// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_INDEXABLE_RANGE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_INDEXABLE_RANGE_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_range_or_pair.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_bidirectional_range.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/has_bidirectional_range_members.hpp>
#include <odds_and_ends/static_introspection/concept/is_indexable_iterator.hpp>
#include <boost/mpl/placeholders.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_indexable_range :
        ::odds_and_ends::static_introspection::concept::_detail::is_range_or_pair<
            T,
            ::odds_and_ends::static_introspection::concept
            ::is_indexable_iterator< ::boost::mpl::_>,
            ::odds_and_ends::static_introspection::concept
            ::_detail::bidirectional_traversal_policy,
            ::odds_and_ends::static_introspection::concept
            ::_detail::has_bidirectional_range_members
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_INDEXABLE_RANGE_HPP

