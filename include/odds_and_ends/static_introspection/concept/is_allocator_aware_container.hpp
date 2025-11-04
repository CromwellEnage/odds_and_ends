// Copyright (C) 2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_ALLOCATOR_AWARE_CONTAINER_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_ALLOCATOR_AWARE_CONTAINER_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_container.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_allocator_aware_container.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_forward_iterator.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_input_iterator.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename IsStrict>
    struct is_allocator_aware_container :
        ::odds_and_ends::static_introspection::concept::_detail::is_container<
            T,
            typename ::boost::mpl::if_<
                IsStrict,
                ::odds_and_ends::static_introspection::concept
                ::is_legacy_forward_iterator< ::boost::mpl::_>,
                ::odds_and_ends::static_introspection::concept
                ::is_legacy_input_iterator< ::boost::mpl::_>
            >::type,
            ::odds_and_ends::static_introspection::concept::_detail::is_base_container,
            ::odds_and_ends::static_introspection::concept::_detail::is_mutable_container,
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_const_allocator_aware_container,
            ::odds_and_ends::static_introspection::concept::_detail::has_container_iterator
        >
    {
    };
}}}  // namespace boost::concept::traits

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_ALLOCATOR_AWARE_CONTAINER_HPP

