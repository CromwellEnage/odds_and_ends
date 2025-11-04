// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_UBLAS_MATRIX_EXPRESSION_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_UBLAS_MATRIX_EXPRESSION_HPP

#include <odds_and_ends/static_introspection/concept/_detail/is_ublas_matrix_minimal_expression.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/has_computed_assignment_ops.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_mutable_ublas_matrix_expression :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::concept::_detail
            ::is_mutable_ublas_matrix_minimal_expression<T>,
            ::odds_and_ends::static_introspection::concept
            ::_detail::has_computed_assignment_ops<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/member_function/has_rbegin1.hpp>
#include <odds_and_ends/static_introspection/member_function/has_rbegin2.hpp>
#include <odds_and_ends/static_introspection/member_function/has_rend1.hpp>
#include <odds_and_ends/static_introspection/member_function/has_rend2.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_base_ublas_matrix_expression :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::member_function::has_rbegin1<T>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::member_function::has_rbegin2<T>,
                ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::member_function::has_rend1<T>,
                    ::boost::mpl::eval_if<
                        ::odds_and_ends::static_introspection::member_function::has_rend2<T>,
                        ::odds_and_ends::static_introspection::concept
                        ::_detail::is_base_ublas_matrix_expression_impl10<T>,
                        ::boost::mpl::false_
                    >,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_UBLAS_MATRIX_EXPRESSION_HPP

