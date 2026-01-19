// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__DETAIL__CHAR_TYPE_OF_ACTUAL_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__DETAIL__CHAR_TYPE_OF_ACTUAL_HPP

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    template <typename T>
    struct char_type_of_actual
    {
        typedef typename T::char_type type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__DETAIL__CHAR_TYPE_OF_ACTUAL_HPP

