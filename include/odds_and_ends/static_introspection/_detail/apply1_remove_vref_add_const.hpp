// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__DETAIL__APPLY1_REMOVE_VREF_ADD_CONST_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__DETAIL__APPLY1_REMOVE_VREF_ADD_CONST_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/remove_vref.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename PlaceholderExpr, typename T>
    struct apply1_remove_vref_add_const :
        ::boost::mpl::apply1<
            PlaceholderExpr,
            typename ::std::add_const<
                typename ::odds_and_ends::static_introspection::remove_vref<T>::type
            >::type
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__DETAIL__APPLY1_REMOVE_VREF_ADD_CONST_HPP

