// Copyright (C) 2026 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_STD_RATIO_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_STD_RATIO_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/member_data/has_num.hpp>
#include <odds_and_ends/static_introspection/member_data/has_den.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_std_ratio :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::member_data::has_num<T>,
            ::odds_and_ends::static_introspection::member_data::has_den<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_STD_RATIO_HPP

