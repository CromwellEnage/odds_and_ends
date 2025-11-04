// Copyright (C) 2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_RESIZABLE_CONTAINER_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_RESIZABLE_CONTAINER_HPP

#include <odds_and_ends/static_introspection/concept/_detail/is_reversible_container.hpp>
#include <odds_and_ends/static_introspection/member_function/has_resize.hpp>
#include <odds_and_ends/use_default_policy.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_mutable_resizable_container :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::concept::_detail::is_mutable_container<T>,
            ::odds_and_ends::static_introspection::member_function
            ::has_resize<T,::odds_and_ends::use_default_policy,::boost::mpl::int_<1> >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_RESIZABLE_CONTAINER_HPP

