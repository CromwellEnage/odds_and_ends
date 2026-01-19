// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_ADDITIVE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_ADDITIVE_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/is_addable.hpp>
#include <odds_and_ends/static_introspection/concept/is_subtractable.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename Difference>
    struct is_additive :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::is_addable<T,Difference>,
            ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::concept::is_subtractable<T,Difference>,
                ::odds_and_ends::static_introspection::concept::is_subtractable<T,T,Difference>,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_ADDITIVE_HPP

