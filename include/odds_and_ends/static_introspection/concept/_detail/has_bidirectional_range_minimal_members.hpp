// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__HAS_BIDIRECTIONAL_RANGE_MIN_MEM_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__HAS_BIDIRECTIONAL_RANGE_MIN_MEM_HPP

#include <odds_and_ends/static_introspection/concept/_detail/has_minimal_range_members.hpp>
#include <odds_and_ends/static_introspection/member_function/has_rbegin.hpp>
#include <odds_and_ends/static_introspection/member_function/has_rend.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/always.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename IteratorPlaceholderExpr>
    struct has_bidirectional_range_minimal_members :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::_detail
            ::has_minimal_range_members<T,IteratorPlaceholderExpr>,
            ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::member_function
                ::has_rbegin<T,::boost::mpl::always< ::boost::mpl::true_> >,
                ::odds_and_ends::static_introspection::member_function
                ::has_rend<T,::boost::mpl::always< ::boost::mpl::true_> >,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif
// ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__HAS_BIDIRECTIONAL_RANGE_MIN_MEM_HPP

