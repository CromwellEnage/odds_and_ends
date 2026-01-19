// Copyright (C) 2011-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__ALGORITHM__INCREMENT_IN_BINARY_TREE_HPP
#define ODDS_AND_ENDS__NODE__ALGORITHM__INCREMENT_IN_BINARY_TREE_HPP

namespace odds_and_ends { namespace node { namespace algorithm {

    template <typename NodePointer>
    NodePointer increment_in_binary_tree(NodePointer node_ptr, NodePointer const& root_ptr)
    {
        if (node_ptr)
        {
            NodePointer other_ptr = node_ptr->right();

            if (other_ptr)
            {
                for (; other_ptr->left(); other_ptr = other_ptr->left())
                {
                }

                return other_ptr;
            }

            other_ptr = root_ptr->parent();

            for (
                NodePointer next_ptr = node_ptr->parent();
                next_ptr != other_ptr;
                next_ptr = next_ptr->parent()
            )
            {
                if (node_ptr == next_ptr->left())
                {
                    return next_ptr;
                }

                node_ptr = next_ptr;
            }

            return nullptr;
        }
        else  // if (!node_ptr)
        {
            for (node_ptr = root_ptr; node_ptr->left(); node_ptr = node_ptr->left())
            {
            }

            return node_ptr;
        }
    }

    template <typename NodePointer>
    NodePointer decrement_in_binary_tree(NodePointer node_ptr, NodePointer const& root_ptr)
    {
        if (node_ptr)
        {
            NodePointer other_ptr = node_ptr->left();

            if (other_ptr)
            {
                for (; other_ptr->right(); other_ptr = other_ptr->right())
                {
                }

                return other_ptr;
            }

            other_ptr = root_ptr->parent();

            for (
                NodePointer next_ptr = node_ptr->parent();
                next_ptr != other_ptr;
                next_ptr = next_ptr->parent()
            )
            {
                if (node_ptr == next_ptr->right())
                {
                    return next_ptr;
                }

                node_ptr = next_ptr;
            }

            return nullptr;
        }
        else  // if (!node_ptr)
        {
            for (node_ptr = root_ptr; node_ptr->right(); node_ptr = node_ptr->right())
            {
            }

            return node_ptr;
        }
    }
}}}  // namespace odds_and_ends::node::algorithm

#endif  // ODDS_AND_ENDS__NODE__ALGORITHM__INCREMENT_IN_BINARY_TREE_HPP

