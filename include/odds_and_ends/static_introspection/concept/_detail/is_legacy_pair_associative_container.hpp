// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_LEGACY_PAIR_ASSOC_CONTAINER_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_LEGACY_PAIR_ASSOC_CONTAINER_HPP

#include <odds_and_ends/static_introspection/nested_type/key_type_of.hpp>
#include <odds_and_ends/static_introspection/is_convertible_to_cref_of.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct legacy_pair_associative_pointer_container_value_type_policy_1
    {
        template <typename U>
        struct apply :
            ::odds_and_ends::static_introspection::is_convertible_to_cref_of<
                U,
                typename ::odds_and_ends::static_introspection::nested_type::key_type_of<T>::type
            >
        {
        };
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <type_traits>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct legacy_pair_associative_container_value_type_policy_1
    {
        template <typename U>
        struct apply :
            ::boost::mpl::if_<
                ::std::is_same<
                    typename ::std::add_const<
                        typename ::odds_and_ends::static_introspection
                        ::nested_type::key_type_of<T>::type
                    >::type,
                    typename ::std::add_const<U>::type
                >,
                ::boost::mpl::true_,
                ::boost::mpl::false_
            >
        {
        };
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/nested_type/mapped_type_of.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct legacy_pair_associative_container_value_type_policy_2
    {
        template <typename U>
        struct apply :
            ::boost::mpl::if_<
                ::std::is_same<
                    U,
                    typename ::odds_and_ends::static_introspection
                    ::nested_type::mapped_type_of<T>::type
                >,
                ::boost::mpl::true_,
                ::boost::mpl::false_
            >::type
        {
        };
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct legacy_pair_associative_pointer_container_value_type_policy_2
    {
        template <typename U>
        struct apply :
            ::boost::mpl::eval_if<
                ::std::is_convertible<
                    U,
                    typename ::odds_and_ends::static_introspection
                    ::nested_type::mapped_type_of<T>::type
                >,
                ::boost::mpl::if_<
                    ::std::is_pointer<U>,
                    ::boost::mpl::true_,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >
        {
        };
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/concept/is_runtime_pair.hpp>
#include <odds_and_ends/static_introspection/nested_type/value_type_of.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_mutable_legacy_pair_associative_container_impl :
        ::odds_and_ends::static_introspection::concept::is_runtime_pair<
            typename ::odds_and_ends::static_introspection::nested_type::value_type_of<T>::type,
            ::odds_and_ends::static_introspection::concept::_detail
            ::legacy_pair_associative_container_value_type_policy_1<T>,
            ::odds_and_ends::static_introspection::concept::_detail
            ::legacy_pair_associative_container_value_type_policy_2<T>
        >
    {
    };

    template <typename T>
    struct is_mutable_legacy_pair_associative_pointer_container :
        ::odds_and_ends::static_introspection::concept::is_runtime_pair<
            typename ::odds_and_ends::static_introspection::nested_type::value_type_of<T>::type,
            ::odds_and_ends::static_introspection::concept::_detail
            ::legacy_pair_associative_pointer_container_value_type_policy_1<T>,
            ::odds_and_ends::static_introspection::concept::_detail
            ::legacy_pair_associative_pointer_container_value_type_policy_2<T>
        >
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/concept/_detail/is_legacy_associative_container.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_pointer_container.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_mapped_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_mutable_legacy_pair_associative_container :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_mutable_legacy_associative_container<T>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::nested_type::has_mapped_type<T>,
                ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::is_mutable_pointer_container<T>,
                    ::odds_and_ends::static_introspection::concept::_detail
                    ::is_mutable_legacy_pair_associative_pointer_container<T>,
                    ::odds_and_ends::static_introspection::concept::_detail
                    ::is_mutable_legacy_pair_associative_container_impl<T>
                >,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_LEGACY_PAIR_ASSOC_CONTAINER_HPP

