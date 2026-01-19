// Copyright (C) 2007-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__REMOVE_CVREF_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__REMOVE_CVREF_HPP

#include <type_traits>

namespace odds_and_ends { namespace static_introspection {

    template <typename T>
    struct remove_cvref : ::std::remove_cv<typename ::std::remove_reference<T>::type>
    {
    };
}}  // namespace odds_and_ends::static_introspection

#include <functional>

namespace odds_and_ends { namespace static_introspection {

    template <typename T>
    struct remove_cvref< ::std::reference_wrapper<T> > : ::std::remove_cv<T>
    {
    };
}}  // namespace odds_and_ends::static_introspection

#include <boost/core/ref.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T>
    struct remove_cvref< ::boost::reference_wrapper<T> > : ::std::remove_cv<T>
    {
    };
}}  // namespace odds_and_ends::static_introspection

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__REMOVE_CVREF_HPP

