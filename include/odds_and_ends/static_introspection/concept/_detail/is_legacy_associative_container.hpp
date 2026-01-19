// Copyright (C) 2012-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_LEGACY_ASSOCIATIVE_CONTAINER_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_LEGACY_ASSOCIATIVE_CONTAINER_HPP

#include <odds_and_ends/static_introspection/concept/_detail/is_container_impl.hpp>
#include <odds_and_ends/static_introspection/member_function/has_clear.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_mutable_legacy_associative_container :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::concept::_detail::is_mutable_container<T>,
            ::odds_and_ends::static_introspection::member_function::has_clear<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/member_function/has_count.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_immutable_legacy_associative_container :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::concept::_detail::is_immutable_container<T>,
            ::odds_and_ends::static_introspection::member_function::has_count<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/nested_type/has_key_type.hpp>
#include <odds_and_ends/static_introspection/member_function/has_equal_range.hpp>
#include <odds_and_ends/static_introspection/member_function/has_find.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_base_legacy_associative_container :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::_detail::is_base_container<T>,
            ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::member_function::has_equal_range<T>,
                ::odds_and_ends::static_introspection::member_function::has_find<T>,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif
// ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_LEGACY_ASSOCIATIVE_CONTAINER_HPP

