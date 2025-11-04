// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_UBLAS_VECTOR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_UBLAS_VECTOR_HPP

#include <odds_and_ends/static_introspection/concept/_detail/is_ublas_vector_expression.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/has_ublas_data.hpp>
#include <odds_and_ends/static_introspection/member_function/has_insert_element.hpp>
#include <odds_and_ends/static_introspection/member_function/has_erase_element.hpp>
#include <odds_and_ends/static_introspection/member_function/has_clear.hpp>
#include <odds_and_ends/static_introspection/member_function/has_resize.hpp>
#include <odds_and_ends/use_default_policy.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    struct ublas_vector_policy
    {
        template <typename T>
        struct apply :
            ::boost::mpl::eval_if<
                typename ::boost::mpl::apply1<
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::ublas_vector_expression_policy,
                    T
                >::type,
                ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::member_function::has_insert_element<
                        T,
                        ::odds_and_ends::use_default_policy,
                        ::boost::mpl::int_<1>
                    >,
                    ::boost::mpl::eval_if<
                        ::odds_and_ends::static_introspection::member_function
                        ::has_erase_element<T,::boost::mpl::int_<1> >,
                        ::boost::mpl::eval_if<
                            ::odds_and_ends::static_introspection::member_function::has_clear<T>,
                            ::boost::mpl::eval_if<
                                ::odds_and_ends::static_introspection::member_function
                                ::has_resize<T,bool,::boost::mpl::int_<1> >,
                                /*::boost::mpl::if_<
                                    ::odds_and_ends::static_introspection
                                    ::concept::_detail::has_ublas_data<T const>,
                                    ::odds_and_ends::static_introspection
                                    ::concept::_detail::has_ublas_data<T>,
                                    ::boost::mpl::false_
                                >*/::boost::mpl::true_,
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

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_UBLAS_VECTOR_HPP

