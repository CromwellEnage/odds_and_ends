// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_INDIRECTLY_READABLE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_INDIRECTLY_READABLE_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/has_dereference_operator.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_indirectly_readable :
        ::odds_and_ends::static_introspection::concept::_detail::has_dereference_operator<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_INDIRECTLY_READABLE_HPP

