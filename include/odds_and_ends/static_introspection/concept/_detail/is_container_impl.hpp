// Copyright (C) 2011-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_CONTAINER_IMPL_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_CONTAINER_IMPL_HPP

#include <odds_and_ends/static_introspection/nested_type/iterator_of.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename IteratorPlaceholderExpr>
    struct has_container_iterator :
        ::boost::mpl::apply1<
            IteratorPlaceholderExpr,
            typename ::odds_and_ends::static_introspection::nested_type::iterator_of<T>::type
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/nested_type/has_value_type.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_size_type.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    // MAINTAINER:
    // Not all container implementations are default-constructible or swappable.
    template <typename T>
    struct is_mutable_container :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::nested_type::has_value_type<T>,
            ::odds_and_ends::static_introspection::nested_type::has_size_type<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/nested_type/has_reference.hpp>
#include <odds_and_ends/static_introspection/member_function/has_begin.hpp>
#include <odds_and_ends/static_introspection/member_function/has_end.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_base_container :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::nested_type::has_reference<T>,
            ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::member_function::has_begin<T>,
                ::odds_and_ends::static_introspection::member_function::has_end<T>,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/concept/is_boolean_expression.hpp>
#include <odds_and_ends/static_introspection/nested_type/is_size_type_of.hpp>
#include <odds_and_ends/static_introspection/member_function/has_max_size.hpp>
#include <odds_and_ends/static_introspection/member_function/has_empty.hpp>
#include <boost/mpl/placeholders.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_immutable_container :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::member_function::has_max_size<T>,
            ::odds_and_ends::static_introspection::member_function::has_empty<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/member_function/has_cbegin.hpp>
#include <odds_and_ends/static_introspection/member_function/has_cend.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_immutable_container_with_cfunctions :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::_detail::is_immutable_container<T>,
            ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::member_function::has_cbegin<T>,
                ::odds_and_ends::static_introspection::member_function::has_cend<T>,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/member_function/has_size.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_immutable_minimal_container :
        ::odds_and_ends::static_introspection::member_function::has_size<T>
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_CONTAINER_IMPL_HPP

