// Copyright (C) 2025-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__IS_REFERENCE_WRAPPER_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__IS_REFERENCE_WRAPPER_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <type_traits>

namespace odds_and_ends { namespace static_introspection {

    template <typename T>
    struct is_reference_wrapper : ::std::false_type
    {
    };
}}  // namespace odds_and_ends::static_introspection

#include <functional>

namespace odds_and_ends { namespace static_introspection {

    template <typename T>
    struct is_reference_wrapper< ::std::reference_wrapper<T> > : ::std::true_type
    {
    };
}}  // namespace odds_and_ends::static_introspection

#include <boost/ref.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T>
    struct is_reference_wrapper< ::boost::reference_wrapper<T> > : ::std::true_type
    {
    };
}}  // namespace odds_and_ends::static_introspection

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__IS_REFERENCE_WRAPPER_HPP

