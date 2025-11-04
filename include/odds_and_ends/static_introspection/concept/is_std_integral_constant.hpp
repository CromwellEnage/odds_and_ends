// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_STD_INTEGRAL_CONSTANT_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_STD_INTEGRAL_CONSTANT_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/nested_type/is_type_of.hpp>
#include <odds_and_ends/static_introspection/member_data/has_value.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_std_integral_constant :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::nested_type::is_type_of<T,T>,
            ::odds_and_ends::static_introspection::member_data::has_value<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_STD_INTEGRAL_CONSTANT_HPP

