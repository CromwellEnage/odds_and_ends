// Copyright (C) 2007-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__REMOVE_VREF_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__REMOVE_VREF_HPP

#include <type_traits>

namespace odds_and_ends { namespace static_introspection {

    template <typename T>
    struct remove_vref : ::std::remove_volatile<typename ::std::remove_reference<T>::type>
    {
    };
}}  // namespace odds_and_ends::static_introspection

#include <functional>

namespace odds_and_ends { namespace static_introspection {

    template <typename T>
    struct remove_vref< ::std::reference_wrapper<T> > : ::std::remove_volatile<T>
    {
    };
}}  // namespace odds_and_ends::static_introspection

#include <boost/core/ref.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T>
    struct remove_vref< ::boost::reference_wrapper<T> > : ::std::remove_volatile<T>
    {
    };
}}  // namespace odds_and_ends::static_introspection

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__REMOVE_VREF_HPP

