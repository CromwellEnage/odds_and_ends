// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__BALANCER__ADELSON_VELSKII_LANDIS_TREE_HPP
#define ODDS_AND_ENDS__NODE__BALANCER__ADELSON_VELSKII_LANDIS_TREE_HPP

#include <tuple>

namespace odds_and_ends { namespace node {

    struct adelson_velskii_landis_tree_balancer
    {
        template <typename Node>
        static void post_fill(Node& root);

        template <typename Node>
        static typename Node::traits::pointer post_insert(Node& node);

        template <typename Node>
        static ::std::tuple<
            typename Node::traits::pointer,
            typename Node::traits::pointer,
            typename Node::traits::pointer
        >
            separate(Node& node);
    };
}}  // namespace odds_and_ends::node

#include <odds_and_ends/node/iterator/breadth_first_tree.hpp>
#include <boost/assert.hpp>

namespace odds_and_ends { namespace node {

    template <typename Node>
    inline void adelson_velskii_landis_tree_balancer::post_fill(Node& root)
    {
        typename Node::traits::size_type s_l, s_r, s_r_p1;

        for (::odds_and_ends::node::breadth_first_tree_iterator<Node> itr(root); !(!itr); ++itr)
        {
            if (itr->left())
            {
                if (itr->right())
                {
                    s_l = itr->left()->size();
                    s_r = itr->right()->size();
                    BOOST_ASSERT_MSG(
                        s_r <= s_l,
                        "post_fill() assumes the input tree to be left-leaning."
                    );
                    s_r_p1 = s_r;
                    ++s_r_p1;

                    if ((s_r_p1 == (s_r_p1 & (~s_r))) && (s_r < s_l))
                    {
                        itr->balance_factor(-1);
                    }
                    else
                    {
                        itr->balance_factor(0);
                    }
                }
                else  // if (!itr->right())
                {
                    itr->balance_factor(-1);
                }
            }
            else  // if (!itr->left())
            {
                BOOST_ASSERT_MSG(
                    !itr->right(),
                    "post_fill() assumes the input tree to be left-leaning."
                );
                itr->balance_factor(0);
            }
        }
    }
}}  // namespace odds_and_ends::node

#include <memory>

namespace odds_and_ends { namespace node {

    template <typename Node>
    typename Node::traits::pointer adelson_velskii_landis_tree_balancer::post_insert(Node& node)
    {
        typedef typename Node::traits::pointer NodePointer;

        BOOST_ASSERT_MSG(!node.left(), "The input node must be a leaf node.");
        BOOST_ASSERT_MSG(!node.right(), "The input node must be a leaf node.");

        NodePointer node_ptr = ::std::pointer_traits<NodePointer>::pointer_to(node);
        NodePointer parent_ptr = node_ptr->parent();

        if (!parent_ptr)
        {
            return node_ptr;
        }

        if (node_ptr == parent_ptr->left())
        {
            if (parent_ptr->right())
            {
                BOOST_ASSERT_MSG(
                    !parent_ptr->right()->left(),
                    "node.parent()->right() must be a leaf node."
                );
                BOOST_ASSERT_MSG(
                    !parent_ptr->right()->right(),
                    "node.parent()->right() must be a leaf node."
                );
                parent_ptr->balance_factor(0);
                return parent_ptr;
            }
            else
            {
                parent_ptr->balance_factor(-1);
            }
        }
        else
        {
            BOOST_ASSERT(node_ptr == parent_ptr->right());

            if (parent_ptr->left())
            {
                BOOST_ASSERT_MSG(
                    !parent_ptr->left()->left(),
                    "node.parent()->left() must be a leaf node."
                );
                BOOST_ASSERT_MSG(
                    !parent_ptr->left()->right(),
                    "node.parent()->left() must be a leaf node."
                );
                parent_ptr->balance_factor(0);
                return parent_ptr;
            }
            else
            {
                parent_ptr->balance_factor(1);
            }
        }

        NodePointer grand_parent_ptr = parent_ptr->parent();

        if (grand_parent_ptr)
        {
            if (parent_ptr == grand_parent_ptr->left())
            {
                if (grand_parent_ptr->right())
                {
                    switch (grand_parent_ptr->balance_factor())
                    {
                        case 1:
                        {
                            grand_parent_ptr->balance_factor(0);
                            return grand_parent_ptr;
                        }

                        case 0:
                        {
                            grand_parent_ptr->balance_factor(-1);
                            break;
                        }

                        case -1:
                        {
                            BOOST_ASSERT_MSG(
                                false,
                                "*parent_ptr was not higher than its right sibling beforehand."
                            );
                        }

                        default:
                        {
                            BOOST_ASSERT_MSG(
                                false,
                                "grand_parent_ptr->balance_factor() is out of range."
                            );
                        }
                    }
                }
                else if (node_ptr == parent_ptr->left())
                {
                    grand_parent_ptr->rotate_right();
                    BOOST_ASSERT_MSG(
                        node_ptr == parent_ptr->left(),
                        "rotate_right() did not work correctly."
                    );
                    BOOST_ASSERT_MSG(
                        grand_parent_ptr == parent_ptr->right(),
                        "rotate_right() did not work correctly."
                    );
                    grand_parent_ptr->balance_factor(0);
                    parent_ptr->balance_factor(0);
                    return parent_ptr;
                }
                else
                {
                    BOOST_ASSERT(node_ptr == parent_ptr->right());
                    parent_ptr->rotate_left();
                    BOOST_ASSERT_MSG(
                        parent_ptr == node_ptr->left(),
                        "rotate_left() did not work correctly."
                    );
                    grand_parent_ptr->rotate_right();
                    BOOST_ASSERT_MSG(
                        parent_ptr == node_ptr->left(),
                        "rotate_right() did not work correctly."
                    );
                    BOOST_ASSERT_MSG(
                        grand_parent_ptr == node_ptr->right(),
                        "rotate_right() did not work correctly."
                    );
                    grand_parent_ptr->balance_factor(0);
                    parent_ptr->balance_factor(0);
                    return node_ptr;
                }
            }
            else
            {
                BOOST_ASSERT(parent_ptr == grand_parent_ptr->right());

                if (grand_parent_ptr->left())
                {
                    switch (grand_parent_ptr->balance_factor())
                    {
                        case -1:
                        {
                            grand_parent_ptr->balance_factor(0);
                            return grand_parent_ptr;
                        }

                        case 0:
                        {
                            grand_parent_ptr->balance_factor(1);
                            break;
                        }

                        case 1:
                        {
                            BOOST_ASSERT_MSG(
                                false,
                                "*parent_ptr was not higher than its left sibling beforehand."
                            );
                        }

                        default:
                        {
                            BOOST_ASSERT_MSG(
                                false,
                                "grand_parent_ptr->balance_factor() is out of range."
                            );
                        }
                    }
                }
                else if (node_ptr == parent_ptr->right())
                {
                    grand_parent_ptr->rotate_left();
                    BOOST_ASSERT_MSG(
                        node_ptr == parent_ptr->right(),
                        "rotate_left() did not work correctly."
                    );
                    BOOST_ASSERT_MSG(
                        grand_parent_ptr == parent_ptr->left(),
                        "rotate_left() did not work correctly."
                    );
                    grand_parent_ptr->balance_factor(0);
                    parent_ptr->balance_factor(0);
                    return parent_ptr;
                }
                else
                {
                    BOOST_ASSERT(node_ptr == parent_ptr->left());
                    parent_ptr->rotate_right();
                    BOOST_ASSERT_MSG(
                        parent_ptr == node_ptr->right(),
                        "rotate_right() did not work correctly."
                    );
                    grand_parent_ptr->rotate_left();
                    BOOST_ASSERT_MSG(
                        parent_ptr == node_ptr->right(),
                        "rotate_left() did not work correctly."
                    );
                    BOOST_ASSERT_MSG(
                        grand_parent_ptr == node_ptr->left(),
                        "rotate_left() did not work correctly."
                    );
                    grand_parent_ptr->balance_factor(0);
                    parent_ptr->balance_factor(0);
                    return node_ptr;
                }
            }
        }
        else
        {
            return parent_ptr;
        }

        node_ptr = parent_ptr;

        for (
            parent_ptr = grand_parent_ptr;
            (grand_parent_ptr = parent_ptr->parent());
            parent_ptr = grand_parent_ptr
        )
        {
            if (parent_ptr == grand_parent_ptr->left())
            {
                BOOST_ASSERT_MSG(
                    grand_parent_ptr->right(),
                    "*grand_parent_ptr is too high not to have two children."
                );

                switch (grand_parent_ptr->balance_factor())
                {
                    case 1:
                    {
                        grand_parent_ptr->balance_factor(0);
                        return grand_parent_ptr;
                    }

                    case 0:
                    {
                        grand_parent_ptr->balance_factor(-1);
                        break;
                    }

                    case -1:
                    {
                        if (node_ptr == parent_ptr->left())
                        {
                            grand_parent_ptr->rotate_right();
                            BOOST_ASSERT_MSG(
                                node_ptr == parent_ptr->left(),
                                "rotate_right() did not work correctly."
                            );
                            BOOST_ASSERT_MSG(
                                grand_parent_ptr == parent_ptr->right(),
                                "rotate_right() did not work correctly."
                            );
                            parent_ptr->balance_factor(0);
                            grand_parent_ptr->balance_factor(0);
                            return parent_ptr;
                        }
                        else
                        {
                            BOOST_ASSERT(node_ptr == parent_ptr->right());
                            parent_ptr->rotate_left();
                            grand_parent_ptr->rotate_right();
                            BOOST_ASSERT_MSG(
                                parent_ptr == node_ptr->left(),
                                "rotate_right() did not work correctly."
                            );
                            BOOST_ASSERT_MSG(
                                grand_parent_ptr == node_ptr->right(),
                                "rotate_right() did not work correctly."
                            );

                            if (1 == node_ptr->balance_factor())
                            {
                                parent_ptr->balance_factor(-1);
                                grand_parent_ptr->balance_factor(0);
                            }
                            else
                            {
                                BOOST_ASSERT(-1 == node_ptr->balance_factor());
                                parent_ptr->balance_factor(0);
                                grand_parent_ptr->balance_factor(1);
                            }

                            node_ptr->balance_factor(0);
                            return node_ptr;
                        }
                    }

                    default:
                    {
                        BOOST_ASSERT_MSG(
                            false,
                            "grand_parent_ptr->balance_factor() is out of range."
                        );
                    }
                }
            }
            else
            {
                BOOST_ASSERT(parent_ptr == grand_parent_ptr->right());
                BOOST_ASSERT_MSG(
                    grand_parent_ptr->left(),
                    "*grand_parent_ptr is too high not to have two children."
                );

                switch (grand_parent_ptr->balance_factor())
                {
                    case -1:
                    {
                        grand_parent_ptr->balance_factor(0);
                        return grand_parent_ptr;
                    }

                    case 0:
                    {
                        grand_parent_ptr->balance_factor(1);
                        break;
                    }

                    case 1:
                    {
                        if (node_ptr == parent_ptr->right())
                        {
                            grand_parent_ptr->rotate_left();
                            BOOST_ASSERT_MSG(
                                node_ptr == parent_ptr->right(),
                                "rotate_left() did not work correctly."
                            );
                            BOOST_ASSERT_MSG(
                                grand_parent_ptr == parent_ptr->left(),
                                "rotate_left() did not work correctly."
                            );
                            parent_ptr->balance_factor(0);
                            grand_parent_ptr->balance_factor(0);
                            return parent_ptr;
                        }
                        else
                        {
                            BOOST_ASSERT(node_ptr == parent_ptr->left());
                            parent_ptr->rotate_right();
                            grand_parent_ptr->rotate_left();
                            BOOST_ASSERT_MSG(
                                parent_ptr == node_ptr->right(),
                                "rotate_left() did not work correctly."
                            );
                            BOOST_ASSERT_MSG(
                                grand_parent_ptr == node_ptr->left(),
                                "rotate_left() did not work correctly."
                            );

                            if (-1 == node_ptr->balance_factor())
                            {
                                parent_ptr->balance_factor(1);
                                grand_parent_ptr->balance_factor(0);
                            }
                            else
                            {
                                BOOST_ASSERT(1 == node_ptr->balance_factor());
                                parent_ptr->balance_factor(0);
                                grand_parent_ptr->balance_factor(-1);
                            }

                            node_ptr->balance_factor(0);
                            return node_ptr;
                        }
                    }

                    default:
                    {
                        BOOST_ASSERT_MSG(
                            false,
                            "grand_parent_ptr->balance_factor() is out of range."
                        );
                    }
                }
            }

            node_ptr = parent_ptr;
        }

        return parent_ptr;
    }
}}  // namespace odds_and_ends::node

#include <utility>
#include <odds_and_ends/node/algorithm/increment_in_binary_tree.hpp>

namespace odds_and_ends { namespace node {

    template <typename Node>
    ::std::tuple<
        typename Node::traits::pointer,
        typename Node::traits::pointer,
        typename Node::traits::pointer
    >
        adelson_velskii_landis_tree_balancer::separate(Node& node)
    {
        using ::std::swap;
        typedef typename Node::traits::pointer NodePointer;
        typedef ::std::tuple<NodePointer,NodePointer,NodePointer> Result;

        NodePointer pred_ptr = ::std::pointer_traits<NodePointer>::pointer_to(node);
        NodePointer root_ptr = pred_ptr;

        for (; root_ptr->parent(); root_ptr = root_ptr->parent())
        {
        }

        NodePointer succ_ptr = nullptr;

        if (pred_ptr->left())
        {
            succ_ptr = pred_ptr;
            pred_ptr = ::odds_and_ends::node::algorithm::decrement_in_binary_tree(
                pred_ptr,
                root_ptr
            );
            swap(*pred_ptr, *succ_ptr);
            swap(pred_ptr, succ_ptr);

            if (pred_ptr->left())
            {
                pred_ptr->swap(*pred_ptr->left());
            }
            else  // if (!pred_ptr->left())
            {
                BOOST_ASSERT_MSG(
                    !pred_ptr->right(),
                    "decrement_in_binary_tree() did not work correctly."
                );
            }

            succ_ptr = ::odds_and_ends::node::algorithm::increment_in_binary_tree(
                succ_ptr,
                root_ptr
            );
        }
        else if (pred_ptr->right())
        {
            succ_ptr = pred_ptr;
            pred_ptr = ::odds_and_ends::node::algorithm::increment_in_binary_tree(
                pred_ptr,
                root_ptr
            );
            swap(*pred_ptr, *succ_ptr);
            swap(pred_ptr, succ_ptr);

            if (pred_ptr->right())
            {
                NodePointer other_ptr = pred_ptr;

                pred_ptr = pred_ptr->right();
                BOOST_ASSERT_MSG(
                    !pred_ptr->left(),
                    "The tree is unbalanced to the right at this point."
                );
                BOOST_ASSERT_MSG(
                    !pred_ptr->right(),
                    "The tree is unbalanced to the right at this point."
                );
                swap(*pred_ptr, *other_ptr);
            }
        }
        else if (pred_ptr == root_ptr)
        {
            // The node to be removed is the only node in the tree.
            return Result(pred_ptr, succ_ptr, nullptr);
        }
        else  // if *pred_ptr is a leaf node
        {
            succ_ptr = ::odds_and_ends::node::algorithm::increment_in_binary_tree(
                pred_ptr,
                root_ptr
            );
        }

        NodePointer parent_ptr = pred_ptr->parent();
        NodePointer node_ptr;

        if (pred_ptr == parent_ptr->left())
        {
            parent_ptr->unset_left();
            node_ptr = parent_ptr->right();

            if (node_ptr)
            {
                if (node_ptr->left())
                {
                    BOOST_ASSERT_MSG(
                        !node_ptr->left()->left(),
                        "*node_ptr->left() must be a leaf node."
                    );
                    BOOST_ASSERT_MSG(
                        !node_ptr->left()->right(),
                        "*node_ptr->left() must be a leaf node."
                    );

                    if (node_ptr->right())
                    {
                        BOOST_ASSERT_MSG(
                            !node_ptr->right()->left(),
                            "*node_ptr->right() must be a leaf node."
                        );
                        BOOST_ASSERT_MSG(
                            !node_ptr->right()->right(),
                            "*node_ptr->right() must be a leaf node."
                        );
                        parent_ptr->balance_factor(1);
                        parent_ptr->rotate_left();
                        BOOST_ASSERT_MSG(
                            !parent_ptr->left(),
                            "rotate_left() did not work correctly."
                        );
                        BOOST_ASSERT_MSG(
                            parent_ptr->right(),
                            "rotate_left() did not work correctly."
                        );
                        BOOST_ASSERT_MSG(
                            parent_ptr == node_ptr->left(),
                            "rotate_left() did not work correctly."
                        );
                        BOOST_ASSERT_MSG(
                            node_ptr->right(),
                            "rotate_left() did not work correctly."
                        );
                        node_ptr->balance_factor(-1);
                        return Result(pred_ptr, succ_ptr, root_ptr);
                    }
                    else  // if (!node_ptr->right())
                    {
                        node_ptr->balance_factor(0);
                        node_ptr->rotate_right();
                        parent_ptr->balance_factor(0);
                        parent_ptr = parent_ptr->rotate_left();
                        BOOST_ASSERT_MSG(
                            node_ptr == parent_ptr->right(),
                            "The double rotation did not work correctly."
                        );
                        parent_ptr->balance_factor(0);
                        // parent_ptr->height() reduced by one.
                    }
                }
                else if (node_ptr->right())
                {
                    BOOST_ASSERT_MSG(
                        !node_ptr->right()->left(),
                        "*node_ptr->right() must be a leaf node."
                    );
                    BOOST_ASSERT_MSG(
                        !node_ptr->right()->right(),
                        "*node_ptr->right() must be a leaf node."
                    );
                    parent_ptr->balance_factor(0);
                    parent_ptr = parent_ptr->rotate_left();
                    node_ptr->balance_factor(0);
                    // parent_ptr->height() reduced by one.
                }
                else  // if *node_ptr is a leaf node
                {
                    parent_ptr->balance_factor(1);
                    return Result(pred_ptr, succ_ptr, root_ptr);
                }
            }
            else  // if *parent_ptr is a leaf node
            {
                parent_ptr->balance_factor(0);
                // parent_ptr->height() reduced by one.
            }
        }
        else
        {
            BOOST_ASSERT(pred_ptr == parent_ptr->right());
            parent_ptr->unset_right();
            node_ptr = parent_ptr->left();

            if (node_ptr)
            {
                if (node_ptr->right())
                {
                    BOOST_ASSERT_MSG(
                        !node_ptr->right()->left(),
                        "*node_ptr->right() must be a leaf node."
                    );
                    BOOST_ASSERT_MSG(
                        !node_ptr->right()->right(),
                        "*node_ptr->right() must be a leaf node."
                    );

                    if (node_ptr->left())
                    {
                        BOOST_ASSERT_MSG(
                            !node_ptr->left()->left(),
                            "*node_ptr->left() must be a leaf node."
                        );
                        BOOST_ASSERT_MSG(
                            !node_ptr->left()->right(),
                            "*node_ptr->left() must be a leaf node."
                        );
                        parent_ptr->balance_factor(-1);
                        parent_ptr->rotate_right();
                        BOOST_ASSERT_MSG(
                            parent_ptr->left(),
                            "rotate_right() did not work correctly."
                        );
                        BOOST_ASSERT_MSG(
                            !parent_ptr->right(),
                            "rotate_right() did not work correctly."
                        );
                        BOOST_ASSERT_MSG(
                            parent_ptr == node_ptr->right(),
                            "rotate_right() did not work correctly."
                        );
                        BOOST_ASSERT_MSG(
                            node_ptr->left(),
                            "rotate_right() did not work correctly."
                        );
                        node_ptr->balance_factor(1);
                        return Result(pred_ptr, succ_ptr, root_ptr);
                    }
                    else  // if (!node_ptr->left())
                    {
                        node_ptr->balance_factor(0);
                        node_ptr->rotate_left();
                        parent_ptr->balance_factor(0);
                        parent_ptr = parent_ptr->rotate_right();
                        BOOST_ASSERT_MSG(
                            node_ptr == parent_ptr->left(),
                            "The double rotation did not work correctly."
                        );
                        parent_ptr->balance_factor(0);
                        // parent_ptr->height() reduced by one.
                    }
                }
                else if (node_ptr->left())
                {
                    BOOST_ASSERT_MSG(
                        !node_ptr->left()->left(),
                        "*node_ptr->left() must be a leaf node."
                    );
                    BOOST_ASSERT_MSG(
                        !node_ptr->left()->right(),
                        "*node_ptr->left() must be a leaf node."
                    );
                    parent_ptr->balance_factor(0);
                    parent_ptr = parent_ptr->rotate_right();
                    node_ptr->balance_factor(0);
                    // parent_ptr->height() reduced by one.
                }
                else  // if *node_ptr is a leaf node
                {
                    parent_ptr->balance_factor(-1);
                    return Result(pred_ptr, succ_ptr, root_ptr);
                }
            }
            else  // if *parent_ptr is a leaf node
            {
                parent_ptr->balance_factor(0);
                // parent_ptr->height() reduced by one.
            }
        }

        node_ptr = parent_ptr;

        for (NodePointer sibling_ptr; (parent_ptr = node_ptr->parent()); )
        {
            if (node_ptr == parent_ptr->left())
            {
                sibling_ptr = parent_ptr->right();
                BOOST_ASSERT_MSG(sibling_ptr, "*parent_ptr was too left-heavy before this op.");

                switch (parent_ptr->balance_factor())
                {
                    case 1:
                    {
                        BOOST_ASSERT_MSG(
                            sibling_ptr->left(),
                            "*sibling_ptr must have two children to remain balanced."
                        );
                        BOOST_ASSERT_MSG(
                            sibling_ptr->right(),
                            "*sibling_ptr must have two children to remain balanced."
                        );

                        switch (sibling_ptr->balance_factor())
                        {
                            case 1:
                            {
                                parent_ptr->rotate_left();
                                BOOST_ASSERT_MSG(
                                    parent_ptr == sibling_ptr->left(),
                                    "rotate_left() did not work correctly."
                                );
                                BOOST_ASSERT_MSG(
                                    parent_ptr->right(),
                                    "rotate_left() did not work correctly."
                                );
                                parent_ptr->balance_factor(0);
                                sibling_ptr->balance_factor(0);

                                if (!sibling_ptr->parent())
                                {
                                    root_ptr = sibling_ptr;
                                }

                                return Result(pred_ptr, succ_ptr, root_ptr);
                            }

                            case 0:
                            {
                                parent_ptr->rotate_left();
                                BOOST_ASSERT_MSG(
                                    parent_ptr == sibling_ptr->left(),
                                    "rotate_left() did not work correctly."
                                );
                                BOOST_ASSERT_MSG(
                                    parent_ptr->right(),
                                    "rotate_left() did not work correctly."
                                );
                                sibling_ptr->balance_factor(-1);

                                if (!sibling_ptr->parent())
                                {
                                    root_ptr = sibling_ptr;
                                }

                                return Result(pred_ptr, succ_ptr, root_ptr);
                            }

                            case -1:
                            {
                                node_ptr = sibling_ptr->rotate_right();
                                BOOST_ASSERT_MSG(
                                    sibling_ptr == node_ptr->right(),
                                    "rotate_right() did not work correctly."
                                );
                                parent_ptr->rotate_left();
                                BOOST_ASSERT_MSG(
                                    parent_ptr == node_ptr->left(),
                                    "rotate_left() did not work correctly."
                                );
                                BOOST_ASSERT_MSG(
                                    sibling_ptr == node_ptr->right(),
                                    "rotate_left() did not work correctly."
                                );
                                node_ptr->balance_factor(0);
                                parent_ptr->balance_factor(parent_ptr->right() ? 0 : -1);
                                sibling_ptr->balance_factor(sibling_ptr->left() ? 0 : 1);
                                // node_ptr->height() reduced by one.
                                break;
                            }

                            default:
                            {
                                BOOST_ASSERT_MSG(
                                    false,
                                    "sibling_ptr->balance_factor() out of range."
                                );
                            }
                        }

                        break;
                    }

                    case 0:
                    {
                        parent_ptr->balance_factor(1);
                        return Result(pred_ptr, succ_ptr, root_ptr);
                    }

                    case -1:
                    {
                        parent_ptr->balance_factor(0);
                        node_ptr = parent_ptr;
                        break;
                    }

                    default:
                    {
                        BOOST_ASSERT_MSG(false, "parent_ptr->balance_factor() out of range.");
                    }
                }
            }
            else
            {
                BOOST_ASSERT(node_ptr == parent_ptr->right());
                sibling_ptr = parent_ptr->left();
                BOOST_ASSERT_MSG(sibling_ptr, "*parent_ptr was too right-heavy before this op.");

                switch (parent_ptr->balance_factor())
                {
                    case -1:
                    {
                        BOOST_ASSERT_MSG(
                            sibling_ptr->left(),
                            "*sibling_ptr must have two children to remain balanced."
                        );
                        BOOST_ASSERT_MSG(
                            sibling_ptr->right(),
                            "*sibling_ptr must have two children to remain balanced."
                        );

                        switch (sibling_ptr->balance_factor())
                        {
                            case -1:
                            {
                                parent_ptr->rotate_right();
                                BOOST_ASSERT_MSG(
                                    parent_ptr == sibling_ptr->right(),
                                    "rotate_right() did not work correctly."
                                );
                                BOOST_ASSERT_MSG(
                                    parent_ptr->right(),
                                    "rotate_right() did not work correctly."
                                );
                                parent_ptr->balance_factor(0);
                                sibling_ptr->balance_factor(0);

                                if (!sibling_ptr->parent())
                                {
                                    root_ptr = sibling_ptr;
                                }

                                return Result(pred_ptr, succ_ptr, root_ptr);
                            }

                            case 0:
                            {
                                parent_ptr->rotate_right();
                                BOOST_ASSERT_MSG(
                                    parent_ptr == sibling_ptr->right(),
                                    "rotate_right() did not work correctly."
                                );
                                BOOST_ASSERT_MSG(
                                    parent_ptr->left(),
                                    "rotate_right() did not work correctly."
                                );
                                sibling_ptr->balance_factor(1);

                                if (!sibling_ptr->parent())
                                {
                                    root_ptr = sibling_ptr;
                                }

                                return Result(pred_ptr, succ_ptr, root_ptr);
                            }

                            case 1:
                            {
                                node_ptr = sibling_ptr->rotate_left();
                                BOOST_ASSERT_MSG(
                                    sibling_ptr == node_ptr->left(),
                                    "rotate_left() did not work correctly."
                                );
                                parent_ptr->rotate_right();
                                BOOST_ASSERT_MSG(
                                    parent_ptr == node_ptr->right(),
                                    "rotate_right() did not work correctly."
                                );
                                BOOST_ASSERT_MSG(
                                    sibling_ptr == node_ptr->left(),
                                    "rotate_right() did not work correctly."
                                );
                                node_ptr->balance_factor(0);
                                parent_ptr->balance_factor(parent_ptr->left() ? 0 : -1);
                                sibling_ptr->balance_factor(sibling_ptr->right() ? 0 : 1);
                                // node_ptr->height() reduced by one.
                                break;
                            }

                            default:
                            {
                                BOOST_ASSERT_MSG(
                                    false,
                                    "sibling_ptr->balance_factor() out of range."
                                );
                            }
                        }

                        break;
                    }

                    case 0:
                    {
                        parent_ptr->balance_factor(-1);
                        return Result(pred_ptr, succ_ptr, root_ptr);
                    }

                    case 1:
                    {
                        parent_ptr->balance_factor(0);
                        node_ptr = parent_ptr;
                        break;
                    }

                    default:
                    {
                        BOOST_ASSERT_MSG(false, "parent_ptr->balance_factor() out of range.");
                    }
                }
            }
        }

        root_ptr = node_ptr;
        return Result(pred_ptr, succ_ptr, root_ptr);
    }
}}  // namespace odds_and_ends::node

#endif  // ODDS_AND_ENDS__NODE__BALANCER__ADELSON_VELSKII_LANDIS_TREE_HPP

