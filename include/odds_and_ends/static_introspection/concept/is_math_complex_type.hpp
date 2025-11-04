// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MATH_COMPLEX_TYPE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MATH_COMPLEX_TYPE_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/concept/is_lvalue_assignable.hpp>
#include <odds_and_ends/static_introspection/concept/is_addable.hpp>
#include <odds_and_ends/static_introspection/concept/is_subtractable.hpp>
#include <odds_and_ends/static_introspection/concept/is_multipliable.hpp>
#include <odds_and_ends/static_introspection/concept/is_dividable.hpp>
#include <odds_and_ends/static_introspection/nested_type/value_type_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename _c_T, typename _m_T, typename IsStrict>
    class has_math_complex_type_ops
    {
        typedef typename ::std::add_const<
            typename ::odds_and_ends::static_introspection::nested_type::value_type_of<T>::type
        >::type _c_V;

    public:
        typedef typename ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::is_lvalue_assignable<_m_T>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept::is_multipliable<T,_c_V>,
                ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::concept::is_subtractable<T,_c_V>,
                    ::boost::mpl::eval_if<
                        ::odds_and_ends::static_introspection::concept::is_dividable<T,_c_V>,
                        ::boost::mpl::eval_if<
                            ::odds_and_ends::static_introspection::concept::is_addable<T,_c_V>,
                            ::boost::mpl::eval_if<
                                IsStrict,
                                ::boost::mpl::eval_if<
                                    ::odds_and_ends::static_introspection
                                    ::concept::is_multipliable<_c_V,_c_T,_m_T>,
                                    ::boost::mpl::eval_if<
                                        ::odds_and_ends::static_introspection
                                        ::concept::is_subtractable<_c_V,_c_T,_m_T>,
                                        ::boost::mpl::if_<
                                            ::odds_and_ends::static_introspection
                                            ::concept::is_dividable<_c_V,_c_T,_m_T>,
                                            ::odds_and_ends::static_introspection
                                            ::concept::is_addable<_c_V,_c_T,_m_T>,
                                            ::boost::mpl::false_
                                        >,
                                        ::boost::mpl::false_
                                    >,
                                    ::boost::mpl::false_
                                >,
                                ::boost::mpl::true_
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
        >::type type;
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/member_function/has_real.hpp>
#include <odds_and_ends/static_introspection/member_function/has_imag.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <odds_and_ends/static_introspection/remove_vref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename IsStrict>
    class is_math_complex_type
    {
        typedef typename ::std::add_const<
            typename ::odds_and_ends::static_introspection::remove_vref<T>::type
        >::type _c_T;
        typedef typename ::odds_and_ends::static_introspection::remove_cvref<T>::type _m_T;

    public:
        typedef typename ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::member_function::has_real<_m_T>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::member_function::has_imag<_m_T>,
                ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::member_function::has_real<_c_T>,
                    ::boost::mpl::eval_if<
                        ::odds_and_ends::static_introspection::member_function::has_imag<_c_T>,
                        ::odds_and_ends::static_introspection::concept::_detail
                        ::has_math_complex_type_ops<T,_c_T,_m_T,IsStrict>,
                        ::boost::mpl::false_
                    >,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type type;
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/is_equality_comparable.hpp>
#include <odds_and_ends/static_introspection/concept/is_identity_operable.hpp>
#include <odds_and_ends/static_introspection/concept/is_negatable.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename IsStrict>
    struct is_math_complex_type :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::is_equality_comparable<T>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept::is_identity_operable<T>,
                ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::concept::is_negatable<T>,
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::is_math_complex_type<T,IsStrict>,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MATH_COMPLEX_TYPE_HPP

