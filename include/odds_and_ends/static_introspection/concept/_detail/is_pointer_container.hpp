// Copyright (C) 2011-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_POINTER_CONTAINER_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_POINTER_CONTAINER_HPP

#include <odds_and_ends/static_introspection/concept/is_container.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/has_pointer_container_nested_types.hpp>
#include <odds_and_ends/static_introspection/member_function/has_base.hpp>
#include <odds_and_ends/static_introspection/member_function/has_clear.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_mutable_pointer_container :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::_detail::is_mutable_container<T>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::member_function::has_base<
                    T,
                    ::odds_and_ends::static_introspection
                    ::concept::is_container< ::boost::mpl::_>,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::has_pointer_container_nested_types<T>,
                    ::odds_and_ends::static_introspection::member_function::has_clear<T>,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_POINTER_CONTAINER_HPP

