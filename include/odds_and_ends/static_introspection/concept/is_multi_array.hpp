// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MULTI_ARRAY_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MULTI_ARRAY_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_container.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_multi_array.hpp>
#include <odds_and_ends/static_introspection/concept/is_random_access_traversal_iterator.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename IsStrict>
    struct is_multi_array :
        ::boost::mpl::if_<
            IsStrict,
            ::odds_and_ends::static_introspection::concept::_detail::is_container<
                T,
                ::odds_and_ends::static_introspection::concept
                ::is_random_access_traversal_iterator< ::boost::mpl::_>,
                ::odds_and_ends::static_introspection::concept::_detail::is_base_multi_array,
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_mutable_indexable_container,
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_strict_immutable_multi_array,
                ::odds_and_ends::static_introspection::concept
                ::_detail::has_container_reverse_iterator
            >,
            ::odds_and_ends::static_introspection::concept::_detail::is_container<
                T,
                ::odds_and_ends::static_introspection::concept
                ::is_random_access_traversal_iterator< ::boost::mpl::_>,
                ::odds_and_ends::static_introspection::concept::_detail::is_base_multi_array,
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_mutable_indexable_container,
                ::odds_and_ends::static_introspection::concept::_detail::is_immutable_multi_array,
                ::odds_and_ends::static_introspection::concept
                ::_detail::has_container_reverse_iterator
            >
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MULTI_ARRAY_HPP

