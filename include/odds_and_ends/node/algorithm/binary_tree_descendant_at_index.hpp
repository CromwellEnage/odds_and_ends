// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__ALGORITHM__BINARY_TREE_DESCENDANT_AT_INDEX_HPP
#define ODDS_AND_ENDS__NODE__ALGORITHM__BINARY_TREE_DESCENDANT_AT_INDEX_HPP

#include <boost/assert.hpp>

namespace odds_and_ends { namespace node { namespace algorithm {

    template <typename NodePointer, typename Index>
    NodePointer binary_tree_descendant_at_index(NodePointer node_ptr, Index index)
    {
        for (NodePointer child_ptr;;)
        {
            if ((child_ptr = node_ptr->left()))
            {
                Index const count = child_ptr->size();

                if (index < count)
                {
                    node_ptr = child_ptr;
                }
                else if (count < index)
                {
                    BOOST_ASSERT_MSG(
                        node_ptr->right(),
                        "Check modifier methods or with_size adaptor."
                    );
                    --(index -= count);
                    node_ptr = node_ptr->right();
                }
                else
                {
                    break;
                }
            }
            else if ((child_ptr = node_ptr->right()))
            {
                if (index)
                {
                    --index;
                    node_ptr = child_ptr;
                }
                else
                {
                    break;
                }
            }
            else
            {
                BOOST_ASSERT_MSG(!index, "Check modifier methods or with_size adaptor.");
                break;
            }
        }

        return node_ptr;
    }
}}}  // namespace odds_and_ends::node::algorithm

#endif  // ODDS_AND_ENDS__NODE__ALGORITHM__BINARY_TREE_DESCENDANT_AT_INDEX_HPP

