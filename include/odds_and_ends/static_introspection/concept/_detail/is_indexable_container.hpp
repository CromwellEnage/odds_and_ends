// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_INDEXABLE_CONTAINER_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_INDEXABLE_CONTAINER_HPP

#include <odds_and_ends/static_introspection/concept/is_subscriptable.hpp>
#include <odds_and_ends/static_introspection/nested_type/size_type_of.hpp>
#include <odds_and_ends/static_introspection/nested_type/is_reference_of.hpp>
#include <boost/mpl/placeholders.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_base_indexable_container_impl_0 :
        ::odds_and_ends::static_introspection::concept::is_subscriptable<
            T,
            typename ::odds_and_ends::static_introspection::nested_type::size_type_of<T>::type,
            ::odds_and_ends::static_introspection::nested_type::is_reference_of< ::boost::mpl::_,T>
        >
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/member_function/has_at.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_base_indexable_container_impl_1 :
        ::odds_and_ends::static_introspection::member_function::has_at<
            T,
            typename ::odds_and_ends::static_introspection::nested_type::size_type_of<T>::type,
            ::odds_and_ends::static_introspection::nested_type::is_reference_of< ::boost::mpl::_,T>
        >
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/concept/_detail/is_container_impl.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_difference_type.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_mutable_indexable_container :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection
            ::concept::_detail::is_mutable_container<T>,
            ::odds_and_ends::static_introspection::nested_type::has_difference_type<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/concept/_detail/is_reversible_container.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_base_indexable_container :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_base_reversible_container<T>,
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_base_indexable_container_impl_0<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_base_indexable_container_with_at :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_base_reversible_container<T>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_base_indexable_container_impl_0<T>,
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_base_indexable_container_impl_1<T>,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_INDEXABLE_CONTAINER_HPP

