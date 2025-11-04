// Copyright (C) 2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__MAYBE_CONTIGUOUS_CONTAINER_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__MAYBE_CONTIGUOUS_CONTAINER_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_container.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/maybe_contiguous_container.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_random_access_iterator.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/placeholders.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct maybe_contiguous_container :
        ::odds_and_ends::static_introspection::concept::_detail::is_container<
            T,
            ::odds_and_ends::static_introspection::concept
            ::is_legacy_random_access_iterator< ::boost::mpl::_>,
            ::odds_and_ends::static_introspection::concept
            ::_detail::maybe_base_contiguous_container,
            ::odds_and_ends::static_introspection::concept::_detail::is_mutable_container,
            ::odds_and_ends::static_introspection::concept::_detail::is_const_indexable_container,
            ::odds_and_ends::static_introspection::concept::_detail::has_container_reverse_iterator
        >
    {
    };
}}}  // namespace boost::concept::traits

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__MAYBE_CONTIGUOUS_CONTAINER_HPP

