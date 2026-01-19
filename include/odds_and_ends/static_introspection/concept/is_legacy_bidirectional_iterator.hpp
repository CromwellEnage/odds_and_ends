// Copyright (C) 2012-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_LEGACY_BIDIRECTIONAL_ITERATOR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_LEGACY_BIDIRECTIONAL_ITERATOR_HPP

#include <iterator>
#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_legacy_bidirectional_iterator.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_legacy_bidirectional_iterator :
        ::odds_and_ends::static_introspection::concept::_detail::is_legacy_input_iterator<
            T,
            ::std::bidirectional_iterator_tag,
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_legacy_bidirectional_iterator_q,
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_legacy_bidirectional_iterator_uq
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_LEGACY_BIDIRECTIONAL_ITERATOR_HPP

