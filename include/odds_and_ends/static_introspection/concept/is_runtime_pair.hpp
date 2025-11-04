// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_RUNTIME_PAIR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_RUNTIME_PAIR_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/member_data/has_first.hpp>
#include <odds_and_ends/static_introspection/member_data/has_second.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <
        typename T,
        typename FirstPlaceholderExpr,
        typename SecondPlaceholderExpr
    >
    struct is_runtime_pair :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection
            ::member_data::has_first<T,FirstPlaceholderExpr>,
            ::odds_and_ends::static_introspection
            ::member_data::has_second<T,SecondPlaceholderExpr>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_RUNTIME_PAIR_HPP

