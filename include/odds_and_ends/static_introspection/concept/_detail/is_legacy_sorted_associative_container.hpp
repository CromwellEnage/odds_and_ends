// Copyright (C) 2012-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_LEGACY_SORTED_ASSOC_CONTAINER_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_LEGACY_SORTED_ASSOC_CONTAINER_HPP

#include <odds_and_ends/static_introspection/concept/_detail/is_legacy_associative_container.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_reversible_container.hpp>
#include <odds_and_ends/static_introspection/member_function/has_lower_bound.hpp>
#include <odds_and_ends/static_introspection/member_function/has_upper_bound.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_base_legacy_sorted_associative_container :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_base_legacy_associative_container<T>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_base_reversible_container<T>,
                ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection::member_function::has_lower_bound<T>,
                    ::odds_and_ends::static_introspection::member_function::has_upper_bound<T>,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/member_function/has_key_comp.hpp>
#include <odds_and_ends/static_introspection/member_function/has_value_comp.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_immutable_legacy_sorted_associative_container :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_immutable_legacy_associative_container<T>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_immutable_reversible_container<T>,
                ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::member_function::has_key_comp<T>,
                    ::odds_and_ends::static_introspection::member_function::has_value_comp<T>,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif
// ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_LEGACY_SORTED_ASSOC_CONTAINER_HPP

