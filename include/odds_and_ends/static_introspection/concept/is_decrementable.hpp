// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_DECREMENTABLE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_DECREMENTABLE_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/is_pre_decrementable.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/has_post_decrement_operator.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_decrementable :
        ::boost::mpl::if_<
            typename ::odds_and_ends::static_introspection::concept
            ::_detail::has_post_decrement_operator<T>::type,
            ::odds_and_ends::static_introspection::concept::is_pre_decrementable<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_DECREMENTABLE_HPP

