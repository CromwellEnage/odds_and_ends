// Copyright (C) 2016-2026 Cromwell D. Enage

#ifndef \
ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_LEGACY_SIMPLE_ASSOCIATIVE_CONTAINER_HPP
#define \
ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_LEGACY_SIMPLE_ASSOCIATIVE_CONTAINER_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/nested_type/key_type_of.hpp>
#include <odds_and_ends/static_introspection/nested_type/value_type_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_mutable_legacy_simple_associative_container_impl :
        ::boost::mpl::if_<
            ::std::is_same<
                typename ::odds_and_ends::static_introspection::nested_type::key_type_of<T>::type,
                typename ::odds_and_ends::static_introspection::nested_type::value_type_of<T>::type
            >,
            ::boost::mpl::true_,
            ::boost::mpl::false_
        >::type
    {
    };

    template <typename T>
    struct is_mutable_legacy_simple_associative_pointer_container :
        ::boost::mpl::if_<
            ::std::is_same<
                typename ::std::add_pointer<
                    typename ::odds_and_ends::static_introspection
                    ::nested_type::key_type_of<T>::type
                >::type,
                typename ::odds_and_ends::static_introspection::nested_type::value_type_of<T>::type
            >,
            ::boost::mpl::true_,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/concept/_detail/is_legacy_associative_container.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_pointer_container.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_mutable_legacy_simple_associative_container :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_mutable_legacy_associative_container<T>,
            ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_mutable_pointer_container<T>,
                ::odds_and_ends::static_introspection::concept::_detail
                ::is_mutable_legacy_simple_associative_pointer_container<T>,
                ::odds_and_ends::static_introspection::concept::_detail
                ::is_mutable_legacy_simple_associative_container_impl<T>
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif
// ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_LEGACY_SIMPLE_ASSOCIATIVE_CONTAINER_HPP

