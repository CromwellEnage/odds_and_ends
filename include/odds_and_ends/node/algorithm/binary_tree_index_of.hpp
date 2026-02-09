// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__ALGORITHM__BINARY_TREE_INDEX_OF_HPP
#define ODDS_AND_ENDS__NODE__ALGORITHM__BINARY_TREE_INDEX_OF_HPP

namespace odds_and_ends { namespace node { namespace algorithm {

    template <typename NodePointer, typename Value>
    Value binary_tree_index_of(NodePointer node_ptr, Value offset, NodePointer root_ptr, bool is_r)
    {
        NodePointer child_ptr = is_r ? node_ptr->right() : node_ptr->left();

        if (child_ptr)
        {
            offset += child_ptr->size();
        }

        if (root_ptr)
        {
            for (; node_ptr != root_ptr; )
            {
                child_ptr = node_ptr;
                node_ptr = node_ptr->parent();

                if (child_ptr == (is_r ? node_ptr->left() : node_ptr->right()))
                {
                    ++offset;

                    if ((child_ptr = (is_r ? node_ptr->right() : node_ptr->left())))
                    {
                        offset += child_ptr->size();
                    }
                }
            }
        }
        else  // if (!root_ptr)
        {
            for (child_ptr = node_ptr; (node_ptr = node_ptr->parent()); child_ptr = node_ptr)
            {
                if (child_ptr == (is_r ? node_ptr->left() : node_ptr->right()))
                {
                    ++offset;

                    if ((child_ptr = (is_r ? node_ptr->right() : node_ptr->left())))
                    {
                        offset += child_ptr->size();
                    }
                }
            }
        }

        return offset;
    }
}}}  // namespace odds_and_ends::node::algorithm

#endif  // ODDS_AND_ENDS__NODE__ALGORITHM__BINARY_TREE_INDEX_OF_HPP

