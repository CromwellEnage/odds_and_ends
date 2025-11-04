// Copyright (C) 2016-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_SIMPLE_ASSOC_CONTAINER_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_SIMPLE_ASSOC_CONTAINER_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_container.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_legacy_simple_associative_container.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_input_iterator.hpp>
#include <boost/mpl/placeholders.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_legacy_simple_associative_container :
        ::odds_and_ends::static_introspection::concept::_detail::is_container<
            T,
            ::odds_and_ends::static_introspection::concept
            ::is_legacy_input_iterator< ::boost::mpl::_>,
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_base_legacy_associative_container,
            ::odds_and_ends::static_introspection::concept::_detail
            ::is_mutable_legacy_simple_associative_container,
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_const_legacy_associative_container,
            ::odds_and_ends::static_introspection::concept::_detail::has_container_iterator
        >
    {
    };
}}}  // namespace boost::concept::traits

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_SIMPLE_ASSOC_CONTAINER_HPP

