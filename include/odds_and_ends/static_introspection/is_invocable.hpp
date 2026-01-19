// Copyright (C) 2011-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__IS_INVOCABLE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__IS_INVOCABLE_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/invoke_result.hpp>
#include <boost/mpl/aux_/has_type.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename F, typename ...Args>
    struct is_invocable :
        ::boost::mpl::aux::has_type<
            ::odds_and_ends::static_introspection::invoke_result<F,Args...>
        >
    {
    };
}}  // namespace odds_and_ends::static_introspection

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__IS_INVOCABLE_HPP

