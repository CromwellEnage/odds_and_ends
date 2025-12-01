// Copyright (C) 2011-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__TRAVERSAL_STATE_HPP
#define ODDS_AND_ENDS__NODE__TRAVERSAL_STATE_HPP

namespace odds_and_ends { namespace node {

    enum traversal_state
    {
        no_traversal,
        pre_order_traversal,
        post_order_traversal,
        breadth_first_traversal,
        in_order_traversal
    };
}}  // namespace odds_and_ends::node

#endif  // ODDS_AND_ENDS__NODE__TRAVERSAL_STATE_HPP

