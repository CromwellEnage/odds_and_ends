// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_UBLAS_VECTOR_MIN_EXPR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_UBLAS_VECTOR_MIN_EXPR_HPP

#include <odds_and_ends/static_introspection/invoke_result.hpp>
#include <odds_and_ends/static_introspection/nested_type/is_reference_of.hpp>
#include <odds_and_ends/static_introspection/nested_type/size_type_of.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct has_ublas_vector_expression_element_operator_impl :
        ::odds_and_ends::static_introspection::nested_type::is_reference_of<
            typename ::odds_and_ends::static_introspection::invoke_result<
                T,
                typename ::odds_and_ends::static_introspection::nested_type::size_type_of<T>::type
            >::type,
            T
        >
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/is_invocable.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct has_ublas_vector_expression_element_operator :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::is_invocable<
                T,
                typename ::odds_and_ends::static_introspection
                ::nested_type::size_type_of<T>::type
            >,
            ::odds_and_ends::static_introspection::concept::_detail
            ::has_ublas_vector_expression_element_operator_impl<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/nested_type/iterator_of.hpp>
#include <odds_and_ends/static_introspection/nested_type/is_size_type_of.hpp>
#include <odds_and_ends/static_introspection/member_function/has_index.hpp>
#include <boost/mpl/placeholders.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct has_ublas_vector_minimal_expression_iterator :
        ::odds_and_ends::static_introspection::member_function::has_index<
             typename ::odds_and_ends::static_introspection::nested_type::iterator_of<T>::type,
            ::odds_and_ends::static_introspection::nested_type
            ::is_size_type_of< ::boost::mpl::_,T>
        >
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <type_traits>
#include <odds_and_ends/static_introspection/concept/_detail/has_computed_assignment_ops.hpp>
#include <odds_and_ends/static_introspection/nested_type/is_type_category_of.hpp>
#include <odds_and_ends/static_introspection/member_function/has_size.hpp>
#include <odds_and_ends/static_introspection/member_function/has_swap.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/numeric/ublas/fwd.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    struct ublas_vector_minimal_expression_policy
    {
        template <typename T>
        struct apply :
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::nested_type
                ::is_type_category_of< ::boost::numeric::ublas::vector_tag,T>,
                ::boost::mpl::eval_if<
                    ::std::is_default_constructible<T>,
                    ::boost::mpl::eval_if<
                        ::odds_and_ends::static_introspection::member_function::has_size<T>,
                        ::boost::mpl::eval_if<
                            ::odds_and_ends::static_introspection::member_function::has_swap<T>,
                            ::boost::mpl::if_<
                                ::odds_and_ends::static_introspection::concept::_detail
                                ::has_ublas_vector_expression_element_operator<T const>,
                                ::odds_and_ends::static_introspection::concept::_detail
                                ::has_ublas_vector_minimal_expression_iterator<T const>,
                                ::boost::mpl::false_
                            >,
                            ::boost::mpl::false_
                        >,
                        ::boost::mpl::false_
                    >,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >
        {
        };
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_UBLAS_VECTOR_MIN_EXPR_HPP

