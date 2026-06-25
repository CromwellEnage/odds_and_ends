// Copyright (C) 2013-2026 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef ODDS_AND_ENDS__NODE__ALGORITHM__BINARY_TREE_DESCENDANT_HPP
#define ODDS_AND_ENDS__NODE__ALGORITHM__BINARY_TREE_DESCENDANT_HPP

namespace odds_and_ends { namespace node { namespace algorithm {

    template <typename NodePtr, typename Value, typename Compare>
    NodePtr binary_tree_descendant(NodePtr node_ptr, Value const& value, Compare const& compare)
    {
        for (; node_ptr; )
        {
            if (compare(value, **node_ptr))
            {
                node_ptr = node_ptr->left();
            }
            else if (compare(**node_ptr, value))
            {
                node_ptr = node_ptr->right();
            }
            else
            {
                return node_ptr;
            }
        }

        return node_ptr;
    }
}}}  // namespace odds_and_ends::node::algorithm

#endif  // ODDS_AND_ENDS__NODE__ALGORITHM__BINARY_TREE_DESCENDANT_HPP

