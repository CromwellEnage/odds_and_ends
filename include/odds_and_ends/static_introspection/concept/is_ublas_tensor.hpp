// Copyright (C) 2025-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_UBLAS_TENSOR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_UBLAS_TENSOR_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/concept/is_ublas_storage.hpp>
#include <odds_and_ends/static_introspection/nested_type/array_type_of.hpp>
#include <odds_and_ends/static_introspection/nested_type/expression_type_of.hpp>
#include <odds_and_ends/static_introspection/member_function/has_data.hpp>
#include <odds_and_ends/static_introspection/remove_vref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <
        typename T,
        typename _q_T = typename ::odds_and_ends::static_introspection::remove_vref<T>::type,
        typename _T_arr = typename ::odds_and_ends
        ::static_introspection::nested_type::array_type_of<T>::type,
        typename _T_exp = typename ::odds_and_ends
        ::static_introspection::nested_type::expression_type_of<T>::type
    >
    struct is_ublas_tensor :
        ::boost::mpl::eval_if<
            ::std::is_base_of<_T_exp,T>,
            ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::concept::is_ublas_storage<_T_arr>,
                ::odds_and_ends::static_introspection::member_function::has_data<_q_T>,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_array_type.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_expression_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_ublas_tensor :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::nested_type::has_array_type<T>,
            ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::nested_type::has_expression_type<T>,
                ::odds_and_ends::static_introspection::concept::_detail::is_ublas_tensor<T>,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace boost::concept::traits

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_UBLAS_TENSOR_HPP

