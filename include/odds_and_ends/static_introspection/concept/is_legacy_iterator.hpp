// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_LEGACY_ITERATOR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_LEGACY_ITERATOR_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_legacy_iterator.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_legacy_iterator :
        ::odds_and_ends::static_introspection::concept::_detail::is_legacy_iterator<
            T,
            ::odds_and_ends::static_introspection::concept::_detail::is_legacy_iterator_q,
            ::odds_and_ends::static_introspection::concept::_detail::is_legacy_iterator_uq
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_LEGACY_ITERATOR_HPP

