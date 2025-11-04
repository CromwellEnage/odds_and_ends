// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_UBLAS_MATRIX_MINIMAL_EXPR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_UBLAS_MATRIX_MINIMAL_EXPR_HPP

#include <odds_and_ends/static_introspection/nested_type/iterator1_of.hpp>
#include <odds_and_ends/static_introspection/nested_type/iterator2_of.hpp>
#include <odds_and_ends/static_introspection/nested_type/reverse_iterator1_of.hpp>
#include <odds_and_ends/static_introspection/nested_type/reverse_iterator2_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename IteratorPlaceholderExpr>
    struct has_ublas_matrix_expression_iterators :
        ::boost::mpl::eval_if<
            typename ::boost::mpl::apply1<
                IteratorPlaceholderExpr,
                typename ::odds_and_ends::static_introspection::nested_type::iterator1_of<T>::type
            >::type,
            ::boost::mpl::eval_if<
                typename ::boost::mpl::apply1<
                    IteratorPlaceholderExpr,
                    typename ::odds_and_ends::static_introspection
                    ::nested_type::iterator2_of<T>::type
                >::type,
                ::boost::mpl::eval_if<
                    typename ::boost::mpl::apply1<
                        IteratorPlaceholderExpr,
                        typename ::odds_and_ends::static_introspection
                        ::nested_type::reverse_iterator1_of<T>::type
                    >::type,
                    ::boost::mpl::apply1<
                        IteratorPlaceholderExpr,
                        typename ::odds_and_ends::static_introspection
                        ::nested_type::reverse_iterator2_of<T>::type
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

#include <odds_and_ends/static_introspection/member_function/has_size1.hpp>
#include <odds_and_ends/static_introspection/member_function/has_size2.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_const_ublas_matrix_expression :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::member_function::has_size1<T>,
            ::odds_and_ends::static_introspection::member_function::has_size2<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/nested_type/is_type_category_of.hpp>
#include <odds_and_ends/static_introspection/member_function/has_swap.hpp>
#include <boost/numeric/ublas/fwd.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_mutable_ublas_matrix_minimal_expression :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::nested_type
            ::is_type_category_of< ::boost::numeric::ublas::matrix_tag,T>,
            ::odds_and_ends::static_introspection::member_function::has_swap<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/is_invoke_result_of.hpp>
#include <odds_and_ends/static_introspection/nested_type/reference_of.hpp>
#include <odds_and_ends/static_introspection/nested_type/size_type_of.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_base_ublas_matrix_expression_impl1 :
        ::odds_and_ends::static_introspection::is_invoke_result_of<
            typename ::odds_and_ends::static_introspection::nested_type::reference_of<T>::type,
            T,
            typename ::odds_and_ends::static_introspection::nested_type::size_type_of<T>::type,
            typename ::odds_and_ends::static_introspection::nested_type::size_type_of<T>::type
        >
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/member_function/has_begin1.hpp>
#include <odds_and_ends/static_introspection/member_function/has_begin2.hpp>
#include <odds_and_ends/static_introspection/member_function/has_end1.hpp>
#include <odds_and_ends/static_introspection/member_function/has_end2.hpp>
#include <boost/mpl/always.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_base_ublas_matrix_expression_impl10 :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::member_function
            ::has_begin1<T,::boost::mpl::always< ::boost::mpl::true_> >,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::member_function
                ::has_begin2<T,::boost::mpl::always< ::boost::mpl::true_> >,
                ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::member_function
                    ::has_end1<T,::boost::mpl::always< ::boost::mpl::true_> >,
                    ::boost::mpl::if_<
                        ::odds_and_ends::static_introspection::member_function
                        ::has_end2<T,::boost::mpl::always< ::boost::mpl::true_> >,
                        ::odds_and_ends::static_introspection::concept
                        ::_detail::is_base_ublas_matrix_expression_impl1<T>,
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

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_UBLAS_MATRIX_MINIMAL_EXPR_HPP

