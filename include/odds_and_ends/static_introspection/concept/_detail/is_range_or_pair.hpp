// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_RANGE_OR_PAIR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_RANGE_OR_PAIR_HPP

#include <odds_and_ends/static_introspection/concept/is_runtime_pair.hpp>
#include <odds_and_ends/static_introspection/_detail/apply1_remove_cvref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <
        typename T,
        typename IteratorPlaceholderExpr,
        typename MFC,
        template <typename, typename> class BPred
    >
    struct is_range_or_pair :
        ::boost::mpl::eval_if<
            typename ::boost::mpl::if_<
                typename BPred<T,IteratorPlaceholderExpr>::type,
                ::boost::mpl::true_,
                ::odds_and_ends::static_introspection::concept
                ::is_runtime_pair<T,IteratorPlaceholderExpr,IteratorPlaceholderExpr>
            >::type,
            ::odds_and_ends::static_introspection::_detail::apply1_remove_cvref<MFC,T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_RANGE_OR_PAIR_HPP

