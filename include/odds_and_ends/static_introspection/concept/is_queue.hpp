// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_QUEUE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_QUEUE_HPP

#include <odds_and_ends/static_introspection/concept/_detail/is_std_container_adaptor.hpp>
#include <odds_and_ends/static_introspection/member_function/has_front.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_queue :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::concept::_detail::is_std_container_adaptor<T>,
            ::odds_and_ends::static_introspection::member_function::has_front<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_QUEUE_HPP

