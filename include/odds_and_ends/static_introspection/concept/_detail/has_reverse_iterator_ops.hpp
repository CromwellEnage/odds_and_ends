// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__HAS_REVERSE_ITERATOR_OPS_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__HAS_REVERSE_ITERATOR_OPS_HPP

#include <odds_and_ends/static_introspection/concept/_detail/has_iterator_ops.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/has_pre_decrement_operator.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct has_reverse_iterator_ops :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::_detail::has_iterator_ops<T>,
            ::odds_and_ends::static_introspection::concept::_detail::has_pre_decrement_operator<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__HAS_REVERSE_ITERATOR_OPS_HPP

