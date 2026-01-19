// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_STACK_OR_HEAP_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_STACK_OR_HEAP_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/member_function/has_top.hpp>
#include <odds_and_ends/static_introspection/remove_vref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct has_stack_or_heap_top :
        ::odds_and_ends::static_introspection::member_function::has_top<
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
    struct is_stack_or_heap :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::_detail::is_std_container_adaptor<T>,
            ::odds_and_ends::static_introspection::concept::_detail::has_stack_or_heap_top<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_STACK_OR_HEAP_HPP

