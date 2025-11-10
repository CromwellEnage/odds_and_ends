// Copyright (C) 2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_ALLOCATOR_AWARE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_ALLOCATOR_AWARE_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/nested_type/allocator_type_of.hpp>
#include <odds_and_ends/static_introspection/nested_type/value_type_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <
        typename T,
        typename _T_alloc = typename ::odds_and_ends
        ::static_introspection::nested_type::allocator_type_of<T>::type,
        typename _T_value = typename ::odds_and_ends
        ::static_introspection::nested_type::value_type_of<T>::type
    >
    struct is_const_allocator_aware_impl :
        ::boost::mpl::eval_if<
            ::std::is_same<
                typename ::odds_and_ends::static_introspection
                ::nested_type::value_type_of<_T_alloc>::type,
                _T_value
            >,
            ::boost::mpl::if_<
                ::std::is_default_constructible<_T_alloc>,
                ::boost::mpl::true_,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/concept/_detail/is_container_impl.hpp>
#include <odds_and_ends/static_introspection/member_function/has_get_allocator.hpp>
#include <odds_and_ends/static_introspection/member_function/has_crend.hpp>
#include <boost/mpl/always.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_const_allocator_aware :
/*
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::_detail::is_const_container<T>,
            ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::member_function::has_get_allocator<T>,
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_const_allocator_aware_impl<T>,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
*/
        ::odds_and_ends::static_introspection::member_function
        ::has_get_allocator<T,::boost::mpl::always< ::boost::mpl::true_> >
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_ALLOCATOR_AWARE_HPP

