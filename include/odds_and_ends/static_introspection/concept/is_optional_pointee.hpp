// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_OPTIONAL_POINTEE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_OPTIONAL_POINTEE_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/is_logically_negatable.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/has_dereference_operator.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_optional_pointee :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::concept::_detail::has_dereference_operator<T>,
            ::odds_and_ends::static_introspection::concept::is_logically_negatable<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_OPTIONAL_POINTEE_HPP

