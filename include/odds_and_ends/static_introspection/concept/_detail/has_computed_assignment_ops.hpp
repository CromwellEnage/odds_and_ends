// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__HAS_COMPUTED_ASSIGNMENT_OPS_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__HAS_COMPUTED_ASSIGNMENT_OPS_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/concept/is_addition_assignable.hpp>
#include <odds_and_ends/static_introspection/concept/is_subtraction_assignable.hpp>
#include <odds_and_ends/static_introspection/concept/is_multiplication_assignable.hpp>
#include <odds_and_ends/static_introspection/member_function/has_assign.hpp>
#include <odds_and_ends/static_introspection/member_function/has_plus_assign.hpp>
#include <odds_and_ends/static_introspection/member_function/has_minus_assign.hpp>
#include <odds_and_ends/static_introspection/is_convertible_to_cref_of.hpp>
#include <odds_and_ends/static_introspection/nested_type/value_type_of.hpp>
#include <odds_and_ends/use_default_policy.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct has_computed_assignment_ops :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::is_multiplication_assignable<
                T,
                typename ::std::add_const<
                    typename ::odds_and_ends::static_introspection
                    ::nested_type::value_type_of<T>::type
                >::type,
                ::odds_and_ends::static_introspection
                ::is_convertible_to_cref_of< ::boost::mpl::_,T>
            >,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::member_function::has_assign<
                    T,
                    ::odds_and_ends::use_default_policy,
                    ::odds_and_ends::static_introspection
                    ::is_convertible_to_cref_of< ::boost::mpl::_,T>
                >,
                ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::concept::is_subtraction_assignable<
                        T,
                        ::odds_and_ends::use_default_policy,
                        ::odds_and_ends::static_introspection
                        ::is_convertible_to_cref_of< ::boost::mpl::_,T>
                    >,
                    ::boost::mpl::eval_if<
                        ::odds_and_ends::static_introspection::concept::is_addition_assignable<
                            T,
                            ::odds_and_ends::use_default_policy,
                            ::odds_and_ends::static_introspection
                            ::is_convertible_to_cref_of< ::boost::mpl::_,T>
                        >,
                        ::boost::mpl::eval_if<
                            ::std::is_copy_assignable<T>,
                            ::boost::mpl::eval_if<
                                ::odds_and_ends::static_introspection
                                ::member_function::has_plus_assign<
                                    T,
                                    ::odds_and_ends::use_default_policy,
                                    ::odds_and_ends::static_introspection
                                    ::is_convertible_to_cref_of< ::boost::mpl::_,T>
                                >,
                                ::odds_and_ends::static_introspection
                                ::member_function::has_minus_assign<
                                    T,
                                    ::odds_and_ends::use_default_policy,
                                    ::odds_and_ends::static_introspection
                                    ::is_convertible_to_cref_of< ::boost::mpl::_,T>
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
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__HAS_COMPUTED_ASSIGNMENT_OPS_HPP

