// Copyright (C) 2026 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef ODDS_AND_ENDS__COMPOSITE_TYPE__EVENT__SWAP_HPP
#define ODDS_AND_ENDS__COMPOSITE_TYPE__EVENT__SWAP_HPP

#include <odds_and_ends/composite_type/event_fwd.hpp>
#include <odds_and_ends/composite_type/event/function_call_broadcast.hpp>

namespace odds_and_ends { namespace composite_type {

    struct swap_event : ::odds_and_ends::composite_type::function_call_broadcast_event
    {
    };
}}  // namespace odds_and_ends::composite_type

#endif  // ODDS_AND_ENDS__COMPOSITE_TYPE__EVENT__SWAP_HPP

