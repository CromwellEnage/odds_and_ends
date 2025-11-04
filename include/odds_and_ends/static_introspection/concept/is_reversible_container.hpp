// Copyright (C) 2012-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_REVERSIBLE_CONTAINER_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_REVERSIBLE_CONTAINER_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_container.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_reversible_container.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_bidirectional_iterator.hpp>
#include <odds_and_ends/static_introspection/concept/is_bidirectional_traversal_iterator.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename IsStrict>
    struct is_reversible_container :
        ::odds_and_ends::static_introspection::concept::_detail::is_container<
            T,
            typename ::boost::mpl::if_<
                IsStrict,
                ::odds_and_ends::static_introspection::concept
                ::is_legacy_bidirectional_iterator< ::boost::mpl::_>,
                ::odds_and_ends::static_introspection::concept
                ::is_bidirectional_traversal_iterator< ::boost::mpl::_>
            >::type,
            ::odds_and_ends::static_introspection::concept::_detail::is_base_reversible_container,
            ::odds_and_ends::static_introspection::concept::_detail::is_mutable_container,
            ::odds_and_ends::static_introspection::concept::_detail::is_const_reversible_container,
            ::odds_and_ends::static_introspection::concept::_detail::has_container_reverse_iterator
        >
    {
    };
}}}  // namespace boost::concept::traits

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_REVERSIBLE_CONTAINER_HPP

