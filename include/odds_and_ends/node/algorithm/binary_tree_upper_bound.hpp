// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__ALGORITHM__BINARY_TREE_UPPER_BOUND_HPP
#define ODDS_AND_ENDS__NODE__ALGORITHM__BINARY_TREE_UPPER_BOUND_HPP

namespace odds_and_ends { namespace node { namespace algorithm {

    template <typename NodePointer, typename Value, typename Compare>
    NodePointer
        binary_tree_upper_bound(
            NodePointer node_ptr,
            Value const& value,
            Compare const& compare
        )
    {
        NodePointer result = nullptr;

        for (; node_ptr; )
        {
            if (compare(value, **node_ptr))
            {
                result = node_ptr;
                node_ptr = node_ptr->left();
            }
            else
            {
                node_ptr = node_ptr->right();
            }
        }

        return result;
    }
}}}  // namespace odds_and_ends::node::algorithm

#endif  // ODDS_AND_ENDS__NODE__ALGORITHM__BINARY_TREE_UPPER_BOUND_HPP

