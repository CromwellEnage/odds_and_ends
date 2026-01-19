// Copyright (C) 2011-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__HAS_PTR_CONTAINER_NESTED_TYPES_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__HAS_PTR_CONTAINER_NESTED_TYPES_HPP

#include <odds_and_ends/static_introspection/nested_type/has_object_type.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_auto_type.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct has_pointer_container_nested_types :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::nested_type::has_object_type<T>,
            ::odds_and_ends::static_introspection::nested_type::has_auto_type<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__HAS_PTR_CONTAINER_NESTED_TYPES_HPP

