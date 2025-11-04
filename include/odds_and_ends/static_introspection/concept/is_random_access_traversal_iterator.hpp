// Copyright (C) 2012-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_RANDOM_ACCESS_TRAVERSAL_ITERATOR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_RANDOM_ACCESS_TRAVERSAL_ITERATOR_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/is_indexable_iterator.hpp>
#include <odds_and_ends/static_introspection/is_iterator_traversal_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_random_access_traversal_iterator :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::concept::is_indexable_iterator<T>,
            ::odds_and_ends::static_introspection::is_iterator_traversal_of<
                ::boost::iterators::random_access_traversal_tag,
                T
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_RANDOM_ACCESS_TRAVERSAL_ITERATOR_HPP

