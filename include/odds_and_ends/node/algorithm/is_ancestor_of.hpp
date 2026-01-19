// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__ALGORITHM__IS_ANCESTOR_OF_HPP
#define ODDS_AND_ENDS__NODE__ALGORITHM__IS_ANCESTOR_OF_HPP

namespace odds_and_ends { namespace node { namespace algorithm {

    template <typename NodePointer>
    bool is_ancestor_of(NodePointer anc_ptr, NodePointer node_ptr)
    {
        for (; node_ptr; node_ptr = node_ptr->parent())
        {
            if (node_ptr == anc_ptr)
            {
                return true;
            }
        }

        return false;
    }
}}}  // namespace odds_and_ends::node::algorithm

#endif  // ODDS_AND_ENDS__NODE__ALGORITHM__IS_ANCESTOR_OF_HPP

