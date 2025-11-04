// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_BIDIRECTIONAL_RANGE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_BIDIRECTIONAL_RANGE_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/concept/is_forward_range.hpp>
#include <boost/range/reverse_iterator.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    struct bidirectional_traversal_policy
    {
        template <typename T>
        struct apply :
            ::boost::mpl::eval_if<
                ::std::is_convertible<
                    typename ::boost::range_reverse_iterator<T>::type,
                    typename ::boost::range_reverse_iterator<
                        typename ::std::add_const<T>::type
                    >::type
                >,
                ::boost::mpl::apply1<
                    ::odds_and_ends::static_introspection
                    ::concept::_detail::forward_traversal_policy,
                    T
                >,
                ::boost::mpl::false_
            >
        {
        };
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_BIDIRECTIONAL_RANGE_HPP

