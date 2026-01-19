// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_UBLAS_VECTOR_EXPRESSION_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_UBLAS_VECTOR_EXPRESSION_HPP

#include <odds_and_ends/static_introspection/concept/_detail/is_ublas_vector_minimal_expression.hpp>
#include <odds_and_ends/static_introspection/nested_type/reverse_iterator_of.hpp>
#include <odds_and_ends/static_introspection/nested_type/is_size_type_of.hpp>
#include <odds_and_ends/static_introspection/member_function/has_index.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct has_ublas_vector_expression_iterator :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::member_function::has_index<
                typename ::odds_and_ends::static_introspection
                ::nested_type::reverse_iterator_of<T>::type,
                ::odds_and_ends::static_introspection::nested_type
                ::is_size_type_of< ::boost::mpl::_,T>
            >,
            ::odds_and_ends::static_introspection::concept::_detail
            ::has_ublas_vector_minimal_expression_iterator<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/concept/_detail/has_computed_assignment_operators.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    struct ublas_vector_expression_policy
    {
        template <typename T>
        struct apply :
            ::boost::mpl::eval_if<
                typename ::boost::mpl::apply1<
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::ublas_vector_minimal_expression_policy,
                    T
                >::type,
                ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::has_computed_assignment_operators<T>,
                    ::boost::mpl::if_<
                        ::odds_and_ends::static_introspection::concept::_detail
                        ::has_ublas_vector_expression_element_operator<T>,
                        ::odds_and_ends::static_introspection::concept
                        ::_detail::has_ublas_vector_expression_iterator<T>,
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

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_UBLAS_VECTOR_EXPRESSION_HPP

