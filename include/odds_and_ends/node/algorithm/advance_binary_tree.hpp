// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__ALGORITHM__ADVANCE_BINARY_TREE_HPP
#define ODDS_AND_ENDS__NODE__ALGORITHM__ADVANCE_BINARY_TREE_HPP

#include <boost/utility/value_init.hpp>
#include <boost/assert.hpp>

namespace odds_and_ends { namespace node { namespace algorithm {

    template <typename NodePointer, typename Difference>
    NodePointer
        advance_binary_tree(
            NodePointer node_ptr,
            Difference difference,
            NodePointer const& root_ptr
        )
    {
        static Difference const zero_difference = ::boost::initialized_value;

        for (NodePointer child_ptr = nullptr; zero_difference != difference; child_ptr = nullptr)
        {
            if (difference < zero_difference)
            {
                if ((child_ptr = node_ptr->left()))
                {
                    if (-(++difference) < child_ptr->size())
                    {
                        node_ptr = child_ptr;

                        if ((child_ptr = node_ptr->right()))
                        {
                            difference += child_ptr->size();
                        }

                        continue;
                    }

                    if (node_ptr == root_ptr)
                    {
                        BOOST_ASSERT_MSG(
                            -difference == child_ptr->size(),
                            "Result out of bounds."
                        );
                        node_ptr = nullptr;
                        break;
                    }

                    child_ptr = node_ptr;

                    if (!(node_ptr = node_ptr->parent()))
                    {
                        BOOST_ASSERT_MSG(
                            -difference == child_ptr->size(),
                            "Result out of bounds."
                        );
                        break;
                    }

                    --difference;
                }
                else  // if (!node_ptr->left())
                {
                    if (node_ptr == root_ptr)
                    {
                        BOOST_ASSERT_MSG(!++difference, "Result out of bounds.");
                        node_ptr = nullptr;
                        break;
                    }

                    child_ptr = node_ptr;

                    if (!(node_ptr = node_ptr->parent()))
                    {
                        BOOST_ASSERT_MSG(!++difference, "Result out of bounds.");
                        break;
                    }
                }
            }
            else  // if (zero_difference < difference)
            {
                if ((child_ptr = node_ptr->right()))
                {
                    if (--difference < child_ptr->size())
                    {
                        node_ptr = child_ptr;

                        if ((child_ptr = node_ptr->left()))
                        {
                            difference -= child_ptr->size();
                        }

                        continue;
                    }

                    if (node_ptr == root_ptr)
                    {
                        BOOST_ASSERT_MSG(
                            difference == child_ptr->size(),
                            "Result out of bounds."
                        );
                        node_ptr = nullptr;
                        break;
                    }

                    child_ptr = node_ptr;

                    if (!(node_ptr = node_ptr->parent()))
                    {
                        BOOST_ASSERT_MSG(
                            difference == child_ptr->size(),
                            "Result out of bounds."
                        );
                        break;
                    }

                    ++difference;
                }
                else  // if (!node_ptr->right())
                {
                    if (node_ptr == root_ptr)
                    {
                        BOOST_ASSERT_MSG(!--difference, "Result out of bounds.");
                        node_ptr = nullptr;
                        break;
                    }

                    child_ptr = node_ptr;

                    if (!(node_ptr = node_ptr->parent()))
                    {
                        BOOST_ASSERT_MSG(!--difference, "Result out of bounds.");
                        break;
                    }
                }
            }

            if (child_ptr == node_ptr->left())
            {
                --difference;

                if (child_ptr->right())
                {
                    difference -= child_ptr->right()->size();
                }
            }
            else  // if (child_ptr == node_ptr->right())
            {
                ++difference;

                if (child_ptr->left())
                {
                    difference += child_ptr->left()->size();
                }
            }
        }

        return node_ptr;
    }
}}}  // namespace odds_and_ends::node::algorithm

#endif  // ODDS_AND_ENDS__NODE__ALGORITHM__ADVANCE_BINARY_TREE_HPP

