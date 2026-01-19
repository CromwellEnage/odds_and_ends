// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_QUEUE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_QUEUE_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/member_function/has_front.hpp>
#include <odds_and_ends/static_introspection/remove_vref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct has_queue_front :
        ::odds_and_ends::static_introspection::member_function::has_front<
            typename ::std::add_const<
                typename ::odds_and_ends::static_introspection::remove_vref<T>::type
            >::type
        >
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/concept/_detail/is_std_container_adaptor.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_queue :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::_detail::is_std_container_adaptor<T>,
            ::odds_and_ends::static_introspection::concept::_detail::has_queue_front<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_QUEUE_HPP

