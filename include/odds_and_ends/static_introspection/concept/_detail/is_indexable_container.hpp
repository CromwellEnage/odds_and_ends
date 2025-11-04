// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_INDEXABLE_CONTAINER_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_INDEXABLE_CONTAINER_HPP

#include <odds_and_ends/static_introspection/concept/is_subscriptable.hpp>
#include <odds_and_ends/static_introspection/nested_type/size_type_of.hpp>
#include <odds_and_ends/static_introspection/nested_type/is_reference_of.hpp>
#include <odds_and_ends/static_introspection/member_function/has_at.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_base_indexable_container_impl :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::concept::is_subscriptable<
                T,
                typename ::odds_and_ends::static_introspection::nested_type::size_type_of<T>::type,
                ::odds_and_ends::static_introspection::nested_type
                ::is_reference_of< ::boost::mpl::_,T>
            >,
            ::odds_and_ends::static_introspection::member_function::has_at<
                T,
                typename ::odds_and_ends::static_introspection::nested_type::size_type_of<T>::type,
                ::odds_and_ends::static_introspection::nested_type
                ::is_reference_of< ::boost::mpl::_,T>
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/concept/_detail/is_reversible_container.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_size_type.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_base_indexable_container :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_base_reversible_container<T>,
            ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::nested_type::has_size_type<T>,
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_base_indexable_container_impl<T>,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/nested_type/is_size_type_of.hpp>
#include <odds_and_ends/static_introspection/member_function/_detail/has_size.hpp>
#include <odds_and_ends/use_default_policy.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_const_indexable_container :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_const_reversible_container<T>,
            ::odds_and_ends::static_introspection::member_function::_detail::has_size<
                T,
                ::odds_and_ends::use_default_policy,
                ::odds_and_ends::static_introspection::nested_type
                ::is_size_type_of< ::boost::mpl::_,T>
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_INDEXABLE_CONTAINER_HPP

