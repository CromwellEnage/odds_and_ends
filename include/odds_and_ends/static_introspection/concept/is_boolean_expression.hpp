// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_BOOLEAN_EXPRESSION_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_BOOLEAN_EXPRESSION_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/is_logically_negatable.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_boolean_expression :
        ::boost::mpl::if_<
            ::std::is_convertible<
                typename ::odds_and_ends::static_introspection::remove_cvref<T>::type,
                bool
            >,
            ::boost::mpl::true_,
            ::odds_and_ends::static_introspection::concept::is_logically_negatable<T>
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_BOOLEAN_EXPRESSION_HPP

