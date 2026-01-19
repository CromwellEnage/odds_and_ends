// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MERGEABLE_HEAP_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MERGEABLE_HEAP_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/is_stack_or_heap.hpp>
#include <odds_and_ends/static_introspection/member_function/has_merge.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_mergeable_heap :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::concept::is_stack_or_heap<T>,
            ::odds_and_ends::static_introspection::member_function::has_merge<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MERGEABLE_HEAP_HPP

