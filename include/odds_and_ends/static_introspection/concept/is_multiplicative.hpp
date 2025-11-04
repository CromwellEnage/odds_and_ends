// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MULTIPLICATIVE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MULTIPLICATIVE_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/is_multipliable.hpp>
#include <odds_and_ends/static_introspection/concept/is_dividable.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename Dividend>
    struct is_multiplicative :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::is_multipliable<T,Dividend>,
            ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::concept::is_dividable<T,Dividend>,
                ::odds_and_ends::static_introspection::concept::is_dividable<T,T,Dividend>,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MULTIPLICATIVE_HPP

