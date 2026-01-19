// Copyright (C) 2011-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__HAS_ITERATOR_DIFFERENCE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__HAS_ITERATOR_DIFFERENCE_HPP

#include <utility>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_iterator_minus :
        ::boost::mpl::apply1<
            ResultPlaceholderExpr,
            decltype(::std::declval<T>() - ::std::declval<T>())
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <type_traits>
#include <odds_and_ends/use_default_policy.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct has_iterator_minus<T,::odds_and_ends::use_default_policy> :
        ::boost::mpl::if_<
            ::std::is_integral<decltype(::std::declval<T>() - ::std::declval<T>())>,
            ::boost::mpl::true_,
            ::boost::mpl::false_
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection/concept/_detail/has_minus_operator.hpp>
#include <odds_and_ends/static_introspection/nested_type/_detail/has_difference_type.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_iterator_difference :
        ::boost::mpl::eval_if<
            typename ::odds_and_ends::static_introspection
            ::concept::_detail::has_minus_operator<T,T>::type,
            ::odds_and_ends::static_introspection::_detail
            ::has_iterator_minus<T,ResultPlaceholderExpr>,
            ::boost::mpl::eval_if<
                ::std::is_pointer<T>,
                ::boost::mpl::true_,
                ::odds_and_ends::static_introspection
                ::nested_type::_detail::has_difference_type<T>
            >
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_iterator_difference :
        ::odds_and_ends::static_introspection::_detail::has_iterator_difference<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type,
            ResultPlaceholderExpr
        >::type
    {
    };
}}  // namespace odds_and_ends::static_introspection

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__HAS_ITERATOR_DIFFERENCE_HPP

