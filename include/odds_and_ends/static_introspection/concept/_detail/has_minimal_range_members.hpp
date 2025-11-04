// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__HAS_MINIMAL_RANGE_MEMBERS_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__HAS_MINIMAL_RANGE_MEMBERS_HPP

#include <odds_and_ends/static_introspection/nested_type/iterator_of.hpp>
#include <odds_and_ends/static_introspection/remove_vref.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename IteratorPlaceholderExpr>
    struct has_miminal_range_iterator :
        ::boost::mpl::apply1<
            IteratorPlaceholderExpr,
            typename ::odds_and_ends::static_introspection::nested_type::iterator_of<
                typename ::odds_and_ends::static_introspection::remove_vref<T>::type
            >::type
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/member_function/has_begin.hpp>
#include <odds_and_ends/static_introspection/member_function/has_end.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename IteratorPlaceholderExpr>
    struct has_minimal_range_members :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::member_function::has_begin<T>,
            ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::member_function::has_end<T>,
                ::odds_and_ends::static_introspection::concept::_detail
                ::has_miminal_range_iterator<T,IteratorPlaceholderExpr>,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__HAS_MINIMAL_RANGE_MEMBERS_HPP

