// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_UBLAS_MATRIX_MINIMAL_EXPRESSION_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_UBLAS_MATRIX_MINIMAL_EXPRESSION_HPP

#include <odds_and_ends/static_introspection/concept/_detail/is_ublas_matrix_minimal_expression.hpp>
#include <odds_and_ends/static_introspection/member_function/has_rbegin1.hpp>
#include <odds_and_ends/static_introspection/member_function/has_rbegin2.hpp>
#include <odds_and_ends/static_introspection/member_function/has_rend1.hpp>
#include <odds_and_ends/static_introspection/member_function/has_rend2.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/always.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_base_ublas_matrix_minimal_expression :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::member_function
            ::has_rbegin1<T,::boost::mpl::always< ::boost::mpl::true_> >,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::member_function
                ::has_rbegin2<T,::boost::mpl::always< ::boost::mpl::true_> >,
                ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::member_function
                    ::has_rend1<T,::boost::mpl::always< ::boost::mpl::true_> >,
                    ::boost::mpl::eval_if<
                        ::odds_and_ends::static_introspection::member_function
                        ::has_rend2<T,::boost::mpl::always< ::boost::mpl::true_> >,
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

#include <type_traits>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <
        typename T,
        typename IteratorPlaceholderExpr,
        typename _T_c = typename ::std::add_const<T>::type
    >
    struct is_ublas_matrix_minimal_expression :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::_detail
            ::is_base_ublas_matrix_minimal_expression<_T_c>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_mutable_ublas_matrix_minimal_expression<T>,
                ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::is_const_ublas_matrix_expression<_T_c>,
                    ::odds_and_ends::static_introspection::concept::_detail
                    ::has_ublas_matrix_expression_iterators<_T_c,IteratorPlaceholderExpr>,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_bidirectional_iterator.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <boost/mpl/placeholders.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_ublas_matrix_minimal_expression :
        ::odds_and_ends::static_introspection::concept
        ::_detail::is_ublas_matrix_minimal_expression<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type,
            ::odds_and_ends::static_introspection::concept
            ::is_legacy_bidirectional_iterator< ::boost::mpl::_>
        >
    {
    };
}}}  // namespace boost::concept::traits

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_UBLAS_MATRIX_MINIMAL_EXPRESSION_HPP

