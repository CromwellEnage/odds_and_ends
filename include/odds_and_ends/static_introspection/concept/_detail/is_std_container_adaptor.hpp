// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_STD_CONTAINER_ADAPTOR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_STD_CONTAINER_ADAPTOR_HPP

#include <odds_and_ends/static_introspection/member_function/has_push.hpp>
#include <odds_and_ends/static_introspection/member_function/has_pop.hpp>
#include <odds_and_ends/static_introspection/member_function/has_size.hpp>
#include <odds_and_ends/static_introspection/member_function/has_empty.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_std_container_adaptor :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::member_function::has_push<T>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::member_function::has_pop<T>,
                ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection::member_function::has_size<T>,
                    ::odds_and_ends::static_introspection::member_function::has_empty<T>,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_STD_CONTAINER_ADAPTOR_HPP

