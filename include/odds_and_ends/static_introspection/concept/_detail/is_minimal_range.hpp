// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_MINIMAL_RANGE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_MINIMAL_RANGE_HPP

#include <odds_and_ends/static_introspection/_detail/apply1_remove_cvref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <
        typename T,
        typename IteratorPlaceholderExpr,
        typename MFC,
        template <typename, typename> class BPred
    >
    struct is_minimal_range :
        ::boost::mpl::eval_if<
            typename BPred<T,IteratorPlaceholderExpr>::type,
            ::odds_and_ends::static_introspection::_detail::apply1_remove_cvref<MFC,T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_MINIMAL_RANGE_HPP

