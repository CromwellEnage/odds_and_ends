// Copyright (C) 2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_STD_TUPLE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_STD_TUPLE_HPP

#include <cstddef>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, ::std::size_t I>
    struct has_std_tuple_get;

    template <typename T, ::std::size_t I>
    struct is_std_tuple_impl;
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <boost/mpl/bool.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct has_std_tuple_get<T,0>
    {
        typedef ::boost::mpl::true_ type;
    };

    template <typename T>
    struct is_std_tuple_impl<T,0>
    {
        typedef ::boost::mpl::false_ type;
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/free_function/has_std_get.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, ::std::size_t I>
    struct has_std_tuple_get :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::free_function::has_std_get<T,I>,
            ::odds_and_ends::static_introspection::concept::_detail::has_std_tuple_get<T,I-1>,
            ::boost::mpl::false_
        >
    {
    };

    template <typename T, ::std::size_t I>
    struct is_std_tuple_impl :
        ::odds_and_ends::static_introspection::concept::_detail::has_std_tuple_get<T,I-1>
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <utility>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_std_tuple :
        ::odds_and_ends::static_introspection::concept::_detail::is_std_tuple_impl<
            T,
            ::std::tuple_size<
                typename ::odds_and_ends::static_introspection::remove_cvref<T>::type
            >::value
        >
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_std_tuple_size.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_std_tuple :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::nested_type::has_std_tuple_size<T>,
            ::odds_and_ends::static_introspection::concept::_detail::is_std_tuple<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_STD_TUPLE_HPP

