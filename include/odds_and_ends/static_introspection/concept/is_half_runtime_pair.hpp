// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_HALF_RUNTIME_PAIR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_HALF_RUNTIME_PAIR_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_first_type.hpp>
#include <odds_and_ends/static_introspection/member_data/has_first.hpp>
#include <odds_and_ends/static_introspection/member_data/has_second.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_half_runtime_pair :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::member_data::has_first<T>,
            ::boost::mpl::false_,
            ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::nested_type::has_first_type<T>,
                ::odds_and_ends::static_introspection::member_data::has_second<T>,
                ::boost::mpl::false_
            >
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_HALF_RUNTIME_PAIR_HPP

