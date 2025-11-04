// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__DETAIL__APPLY1_REMOVE_VREF_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__DETAIL__APPLY1_REMOVE_VREF_HPP

#include <odds_and_ends/static_introspection/remove_vref.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename PlaceholderExpr, typename T>
    struct apply1_remove_vref :
        ::boost::mpl::apply1<
            PlaceholderExpr,
            typename ::odds_and_ends::static_introspection::remove_vref<T>::type
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__DETAIL__APPLY1_REMOVE_VREF_HPP

