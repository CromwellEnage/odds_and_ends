// Copyright (C) 2012-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_BIDIRECTIONAL_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_BIDIRECTIONAL_HPP

#include <odds_and_ends/static_introspection/is_convertible_to_cref_of.hpp>
#include <odds_and_ends/static_introspection/declref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_post_decrement_convertible_to_cref_of :
        ::odds_and_ends::static_introspection::is_convertible_to_cref_of<
            decltype(::odds_and_ends::static_introspection::declref<T>()--),
            T
        >
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/concept/is_pre_decrementable.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/has_post_decrement_operator.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_bidirectional :
        ::boost::mpl::eval_if<
            typename ::odds_and_ends::static_introspection::concept
            ::_detail::has_post_decrement_operator<T>::type,
            ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::concept::is_pre_decrementable<T>,
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_post_decrement_convertible_to_cref_of<T>,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_BIDIRECTIONAL_HPP

