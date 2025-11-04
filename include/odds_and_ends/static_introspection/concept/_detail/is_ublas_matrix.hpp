// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_UBLAS_MATRIX_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_UBLAS_MATRIX_HPP

#include <odds_and_ends/static_introspection/concept/_detail/is_ublas_matrix_expression.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/has_ublas_data.hpp>
#include <odds_and_ends/static_introspection/member_function/has_insert_element.hpp>
#include <odds_and_ends/static_introspection/member_function/has_erase_element.hpp>
#include <odds_and_ends/static_introspection/member_function/has_clear.hpp>
#include <odds_and_ends/static_introspection/member_function/has_resize.hpp>
#include <odds_and_ends/static_introspection/member_function/has_data.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/less.hpp>
#include <boost/mpl/always.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename IsStrict>
    struct is_mutable_ublas_matrix_impl :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_mutable_ublas_matrix_expression<T>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::member_function::has_insert_element<
                    T,
                    ::odds_and_ends::use_default_policy,
                    ::boost::mpl::int_<2>
                >,
                ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::member_function
                    ::has_erase_element<T,::boost::mpl::int_<2> >,
                    ::boost::mpl::eval_if<
                        ::odds_and_ends::static_introspection::member_function::has_clear<T>,
                        ::boost::mpl::eval_if<
                            ::odds_and_ends::static_introspection::member_function
                            ::has_resize<T,bool,::boost::mpl::int_<2> >,
                            ::boost::mpl::eval_if<
                                IsStrict,
                                ::boost::mpl::if_<
                                    ::odds_and_ends::static_introspection
                                    ::concept::_detail::has_ublas_data<T const>,
                                    ::odds_and_ends::static_introspection
                                    ::concept::_detail::has_ublas_data<T>,
                                    ::boost::mpl::false_
                                >,
                                ::boost::mpl::if_<
                                    ::odds_and_ends::static_introspection
                                    ::member_function::has_data<
                                        T const,
                                        ::boost::mpl::always< ::boost::mpl::true_>
                                    >,
                                    ::odds_and_ends::static_introspection
                                    ::member_function::has_data<
                                        T,
                                        ::boost::mpl::always< ::boost::mpl::true_>
                                    >,
                                    ::boost::mpl::false_
                                >
                            >,
                            ::boost::mpl::false_
                        >,
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

    template <typename T>
    struct is_mutable_ublas_matrix_strict :
        ::odds_and_ends::static_introspection::concept::_detail
        ::is_mutable_ublas_matrix_impl<T,::boost::mpl::true_>
    {
    };

    template <typename T>
    struct is_mutable_ublas_matrix_non_strict :
        ::odds_and_ends::static_introspection::concept::_detail
        ::is_mutable_ublas_matrix_impl<T,::boost::mpl::false_>
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_UBLAS_MATRIX_HPP

