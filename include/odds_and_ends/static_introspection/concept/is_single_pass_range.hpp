// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_SINGLE_PASS_RANGE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_SINGLE_PASS_RANGE_HPP

#include <type_traits>
#include <boost/range/iterator.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    struct single_pass_policy
    {
        template <typename T>
        struct apply :
            ::boost::mpl::if_<
                ::std::is_convertible<
                    typename ::boost::range_iterator<T>::type,
                    typename ::boost::range_iterator<typename ::std::add_const<T>::type>::type
                >,
                ::boost::mpl::true_,
                ::boost::mpl::false_
            >
        {
        };
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_range_or_pair.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/has_minimal_range_members.hpp>
#include <odds_and_ends/static_introspection/concept/is_single_pass_iterator.hpp>
#include <boost/mpl/placeholders.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_single_pass_range :
        ::odds_and_ends::static_introspection::concept::_detail::is_range_or_pair<
            T,
            ::odds_and_ends::static_introspection::concept
            ::is_single_pass_iterator< ::boost::mpl::_>,
            ::odds_and_ends::static_introspection::concept::_detail::single_pass_policy,
            ::odds_and_ends::static_introspection::concept::_detail::has_minimal_range_members
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_SINGLE_PASS_RANGE_HPP

