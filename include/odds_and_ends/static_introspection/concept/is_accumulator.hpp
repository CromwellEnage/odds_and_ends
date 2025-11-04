// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_ACCUMULATOR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_ACCUMULATOR_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_result_type.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <boost/accumulators/framework/accumulator_base.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_accumulator :
        ::boost::mpl::if_<
            ::std::is_base_of<
                ::boost::accumulators::accumulator_base,
                typename ::odds_and_ends::static_introspection::remove_cvref<T>::type
            >,
            ::odds_and_ends::static_introspection::nested_type::has_result_type<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_ACCUMULATOR_HPP

