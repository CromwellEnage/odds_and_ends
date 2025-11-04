// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_UBLAS_EXPRESSION_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_UBLAS_EXPRESSION_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/nested_type/expression_type_of.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_ublas_expression_impl :
        ::boost::mpl::if_<
            ::std::is_base_of<
                typename ::odds_and_ends::static_introspection::remove_cvref<T>::type,
                typename ::odds_and_ends::static_introspection
                ::nested_type::expression_type_of<T>::type
            >,
            ::boost::mpl::true_,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/nested_type/has_expression_type.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_value_type.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_ublas_expression :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::nested_type::has_expression_type<T>,
            ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::nested_type::has_value_type<T>,
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_ublas_expression_impl<T>,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_UBLAS_EXPRESSION_HPP

