// Copyright (C) 2011-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__DECLREF_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__DECLREF_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/remove_vref.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T>
    typename ::std::add_lvalue_reference<
        typename ::odds_and_ends::static_introspection::remove_vref<T>::type
    >::type declref() noexcept;

    template <typename T>
    typename ::std::add_lvalue_reference<
        typename ::std::add_const<
            typename ::odds_and_ends::static_introspection::remove_vref<T>::type
        >::type
    >::type declcref() noexcept;
}}  // namespace odds_and_ends::static_introspection

#include <odds_and_ends/static_introspection/remove_cvref.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T>
    typename ::std::add_lvalue_reference<
        typename ::odds_and_ends::static_introspection::remove_cvref<T>::type
    >::type declmref() noexcept;
}}  // namespace odds_and_ends::static_introspection

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__DECLREF_HPP

