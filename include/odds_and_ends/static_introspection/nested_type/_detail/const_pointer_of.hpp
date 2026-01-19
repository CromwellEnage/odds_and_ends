// Copyright (C) 2011-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__DETAIL__CONST_POINTER_OF_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__DETAIL__CONST_POINTER_OF_HPP

#include <type_traits>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    template <typename T>
    struct const_pointer_of
    {
        typedef typename ::std::remove_const<T>::type::const_pointer type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__DETAIL__CONST_POINTER_OF_HPP

