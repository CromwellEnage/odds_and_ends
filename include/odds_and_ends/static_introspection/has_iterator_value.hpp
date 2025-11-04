// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__HAS_ITERATOR_VALUE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__HAS_ITERATOR_VALUE_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/iterator_value_of.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <boost/mpl/aux_/has_type.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T>
    struct has_iterator_value :
        ::boost::mpl::aux::has_type<
            ::odds_and_ends::static_introspection::iterator_value_of<T>
        >::type
    {
    };
}}  // namespace odds_and_ends::static_introspection

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__HAS_ITERATOR_VALUE_HPP

