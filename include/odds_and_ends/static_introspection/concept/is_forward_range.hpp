// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_FORWARD_RANGE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_FORWARD_RANGE_HPP

#include <odds_and_ends/static_introspection/concept/is_single_pass_range.hpp>
#include <odds_and_ends/static_introspection/has_iterator_difference.hpp>
#include <boost/range/size_type.hpp>
#include <boost/mpl/aux_/has_type.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    struct forward_traversal_policy
    {
        template <typename T>
        struct apply :
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::has_iterator_difference<T>,
                ::boost::mpl::eval_if<
                    ::boost::mpl::aux::has_type< ::boost::range_size<T> >,
                    ::boost::mpl::apply1<
                        ::odds_and_ends::static_introspection
                        ::concept::_detail::single_pass_policy,
                        T
                    >,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >
        {
        };
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_range_or_pair.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/has_minimal_range_members.hpp>
#include <odds_and_ends/static_introspection/concept/is_forward_traversal_iterator.hpp>
#include <boost/mpl/placeholders.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_forward_range :
        ::odds_and_ends::static_introspection::concept::_detail::is_range_or_pair<
            T,
            ::odds_and_ends::static_introspection::concept
            ::is_forward_traversal_iterator< ::boost::mpl::_>,
            ::odds_and_ends::static_introspection::concept::_detail::forward_traversal_policy,
            ::odds_and_ends::static_introspection::concept::_detail::has_minimal_range_members
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_FORWARD_RANGE_HPP

