// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__BALANCER__LEFT_LEANING_RED_BLACK_TREE_HPP
#define ODDS_AND_ENDS__NODE__BALANCER__LEFT_LEANING_RED_BLACK_TREE_HPP

#include <tuple>

namespace odds_and_ends { namespace node {

    struct left_leaning_red_black_tree_balancer
    {
        template <typename Node, typename Size>
        static void post_fill(Node& root, Size n);

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

#include <memory>
#include <boost/assert.hpp>

namespace odds_and_ends { namespace node {

    template <typename Node>
    typename Node::traits::pointer left_leaning_red_black_tree_balancer::post_insert(Node& node)
    {
        typedef typename Node::traits::pointer NodePointer;

        NodePointer node_ptr = ::std::pointer_traits<NodePointer>::pointer_to(node);
        NodePointer parent_ptr;
        NodePointer grandparent_ptr;
        NodePointer uncle_ptr;

        for (node_ptr->red(true); (parent_ptr = node_ptr->parent()); )
        {
            if (parent_ptr->black())
            {
                if (!parent_ptr->left())
                {
                    BOOST_ASSERT(node_ptr == parent_ptr->right());
                    node_ptr = parent_ptr->rotate_left();
                    parent_ptr->red(true);
                    node_ptr->black(true);
                }

                return node_ptr;
            }

            grandparent_ptr = parent_ptr->parent();

            if (!grandparent_ptr)
            {
                if (parent_ptr->left())
                {
                    parent_ptr->black(true);
                }
                else
                {
                    BOOST_ASSERT(node_ptr == parent_ptr->right());
                    node_ptr = parent_ptr->rotate_left();
                    node_ptr->black(true);
                }

                return node_ptr;
            }

            if (
                (
                    uncle_ptr = (
                        (parent_ptr == grandparent_ptr->left()) ?
                        grandparent_ptr->right() :
                        grandparent_ptr->left()
                    )
                ) && uncle_ptr->red()
            )
            {
                parent_ptr->black(true);
                uncle_ptr->black(true);
                grandparent_ptr->red(true);
                node_ptr = grandparent_ptr;
                continue;
            }

            if ((node_ptr == parent_ptr->right()) && (parent_ptr == grandparent_ptr->left()))
            {
                parent_ptr = parent_ptr->rotate_left();
                node_ptr = node_ptr->left();
            }
            else if ((node_ptr == parent_ptr->left()) && (parent_ptr == grandparent_ptr->right()))
            {
                parent_ptr = parent_ptr->rotate_right();
                node_ptr = node_ptr->right();
            }

            parent_ptr->black(true);
            grandparent_ptr->red(true);
            node_ptr = (
                node_ptr == parent_ptr->left()
            ) ? grandparent_ptr->rotate_right() : grandparent_ptr->rotate_left();
//            break;
        }

        if (
            node_ptr->left() && node_ptr->left()->red() &&
            node_ptr->right() && node_ptr->right()->red()
        )
        {
            node_ptr->red(true);
            node_ptr->left()->black(true);
            node_ptr->right()->black(true);
        }
        else
        {
            if (!node_ptr->left())
            {
                parent_ptr = node_ptr->parent();
                BOOST_ASSERT(node_ptr == parent_ptr->right());
                node_ptr = parent_ptr->rotate_left();
                parent_ptr->red(true);
            }

            node_ptr->black(true);
        }

        return node_ptr;
    }
}}  // namespace odds_and_ends::node

#include <odds_and_ends/node/iterator/breadth_first_tree.hpp>
#include <boost/utility/value_init.hpp>

namespace odds_and_ends { namespace node {

    template <typename Node, typename Size>
    void left_leaning_red_black_tree_balancer::post_fill(Node& root, Size n)
    {
        Size counter = ::boost::initialized_value;

        if (n - ++counter)
        {
            Size black_count = counter;

            for (; black_count < n; black_count <<= counter)
            {
            }

            if (black_count == n + counter)
            {
/*
                for (
                    ::odds_and_ends::node::breadth_first_tree_iterator<Node> itr(root);
                    itr;
                    ++itr
                )
                {
                    itr->black(true);
                }
*/
            }
            else
            {
                if (n < black_count)
                {
                    black_count >>= counter;
                }

                ::odds_and_ends::node::breadth_first_tree_iterator<Node> itr(root);

                for (; counter < black_count; ++counter)
                {
                    ++itr;
                }

                for (; itr; ++itr)
                {
                    itr->red(true);
                }
            }
        }
    }

    template <typename Node>
    inline void left_leaning_red_black_tree_balancer::post_fill(Node& root)
    {
        left_leaning_red_black_tree_balancer::post_fill(root, root.size());
    }
}}  // namespace odds_and_ends::node

#include <utility>

namespace odds_and_ends { namespace node {

    template <typename Node>
    ::std::tuple<
        typename Node::traits::pointer,
        typename Node::traits::pointer,
        typename Node::traits::pointer
    >
        left_leaning_red_black_tree_balancer::separate(Node& node)
    {
        using ::std::swap;
        typedef typename Node::traits::pointer NodePointer;
        typedef ::std::tuple<NodePointer,NodePointer,NodePointer> Result;

        NodePointer succ_ptr = ::std::pointer_traits<NodePointer>::pointer_to(node);
        NodePointer root_ptr = succ_ptr;

        for (; root_ptr->parent(); root_ptr = root_ptr->parent())
        {
        }

        NodePointer node_ptr = nullptr;
        NodePointer next_ptr = nullptr;
        bool flag = false;

        if (succ_ptr->left())
        {
            if (succ_ptr->right())
            {
                node_ptr = succ_ptr->right();

                if (node_ptr->left())
                {
                    for (; node_ptr->left(); node_ptr = node_ptr->left())
                    {
                    }

                    swap(**succ_ptr, **node_ptr);
                    BOOST_ASSERT_MSG(
                        !node_ptr->right(),
                        "The node to be removed is not left-leaning."
                    );
                    next_ptr = node_ptr->parent();
                    BOOST_ASSERT_MSG(
                        node_ptr == next_ptr->left(),
                        "The parent of the node to be removed is not left-leaning."
                    );
                    next_ptr->unset_left();

                    if (node_ptr->red())
                    {
                        // Case 00.01
                        BOOST_ASSERT_MSG(
                            next_ptr->black(),
                            "*node_ptr must not have a red parent."
                        );

                        if (next_ptr->right())
                        {
                            BOOST_ASSERT_MSG(
                                next_ptr->right()->red(),
                                "*next_ptr->right() must be a red leaf node."
                            );
                            BOOST_ASSERT_MSG(
                                !next_ptr->right()->left(),
                                "*next_ptr->right() must be a red leaf node."
                            );
                            BOOST_ASSERT_MSG(
                                !next_ptr->right()->right(),
                                "*next_ptr->right() must be a red leaf node."
                            );
                            next_ptr->red(true);
                            next_ptr = next_ptr->rotate_left();
                            next_ptr->black(true);
                        }

                        // Removal of red leaf nodes does not unbalance the tree.
                        return Result(node_ptr, succ_ptr, root_ptr);
                    }
                }
                else  // if (!node_ptr->left())
                {
                    swap(**succ_ptr, **node_ptr);
                    BOOST_ASSERT_MSG(
                        !node_ptr->right(),
                        "The node to be removed is not left-leaning."
                    );
                    succ_ptr->unset_right();

                    if (node_ptr->red())
                    {
                        // Case 00.00
                        BOOST_ASSERT_MSG(
                            succ_ptr->black(),
                            "*node_ptr must not have a red parent."
                        );
                        // Removal of red leaf nodes does not unbalance the tree.
                        return Result(node_ptr, succ_ptr, root_ptr);
                    }
                }
            }
            else  // if (!succ_ptr->right())
            {
                BOOST_ASSERT(succ_ptr->black());
                node_ptr = succ_ptr->left();
                BOOST_ASSERT(node_ptr->red());
                swap(**succ_ptr, **node_ptr);
                succ_ptr->unset_left();

                // Find the actual successor to return.
                for (; (next_ptr = succ_ptr->parent()); )
                {
                    if (succ_ptr == next_ptr->left())
                    {
                        // Case 00.02
                        return Result(node_ptr, next_ptr, root_ptr);
                    }
                    else
                    {
                        succ_ptr = next_ptr;
                    }
                }

                // Case 00.03
                return Result(node_ptr, nullptr, root_ptr);
            }
        }
        else  // if (!succ_ptr->left())
        {
            BOOST_ASSERT_MSG(!succ_ptr->right(), "The node to be removed is not left-leaning.");

            if (root_ptr == succ_ptr)
            {
                // The node to be removed is the only node in the tree.
                return Result(succ_ptr, node_ptr, nullptr);
            }

            if (succ_ptr->red())
            {
                node_ptr = succ_ptr->parent();
                BOOST_ASSERT_MSG(node_ptr->black(), "*succ_ptr must not have a red parent.");

                if (succ_ptr == node_ptr->left())
                {
                    node_ptr->unset_left();

                    if (node_ptr->right())
                    {
                        BOOST_ASSERT_MSG(
                            node_ptr->right()->red(),
                            "The sibling of *succ_ptr must also be a red leaf node."
                        );
                        BOOST_ASSERT_MSG(
                            !node_ptr->right()->left(),
                            "The sibling of *succ_ptr must also be a red leaf node."
                        );
                        BOOST_ASSERT_MSG(
                            !node_ptr->right()->right(),
                            "The sibling of *succ_ptr must also be a red leaf node."
                        );
                        node_ptr->rotate_left()->black(true);
                        node_ptr->red(true);
                    }

                    // Case 00.04
                    return Result(succ_ptr, node_ptr, root_ptr);
                }
                else  // if (succ_ptr == node_ptr->right())
                {
                    BOOST_ASSERT_MSG(
                        node_ptr->left(),
                        "The parent of *succ_ptr is not left-leaning."
                    );
                    BOOST_ASSERT_MSG(
                        node_ptr->left()->red(),
                        "The sibling of *succ_ptr must also be a red leaf node."
                    );
                    BOOST_ASSERT_MSG(
                        !node_ptr->left()->left(),
                        "The sibling of *succ_ptr must also be a red leaf node."
                    );
                    BOOST_ASSERT_MSG(
                        !node_ptr->left()->right(),
                        "The sibling of *succ_ptr must also be a red leaf node."
                    );
                    node_ptr->unset_right();

                    // Find the actual successor to return.
                    for (; (next_ptr = node_ptr->parent()); )
                    {
                        if (node_ptr == next_ptr->left())
                        {
                            // Case 00.05
                            return Result(succ_ptr, next_ptr, root_ptr);
                        }
                        else
                        {
                            node_ptr = next_ptr;
                        }
                    }

                    // Case 00.06
                    return Result(succ_ptr, nullptr, root_ptr);
                }
            }
            else  // if (succ_ptr->black())
            {
                node_ptr = succ_ptr;
                succ_ptr = succ_ptr->parent();
                BOOST_ASSERT_MSG(succ_ptr, "Root nodes do not have parents.");

                if (node_ptr == succ_ptr->right())
                {
                    succ_ptr->unset_right();
                    flag = true;
                }
                else if (root_ptr == succ_ptr)
                {
                    succ_ptr = succ_ptr->right();
                    BOOST_ASSERT_MSG(
                        succ_ptr,
                        "At least one black descendant of *root_ptr must exist."
                    );

                    if (succ_ptr->left())
                    {
                        if (succ_ptr->right())
                        {
                            if (succ_ptr->left()->left())
                            {
                                BOOST_ASSERT_MSG(
                                    succ_ptr->left()->left()->red(),
                                    "*root_ptr->right()->left()->left() must be a red leaf node."
                                );
                                BOOST_ASSERT_MSG(
                                    !succ_ptr->left()->left()->left(),
                                    "*root_ptr->right()->left()->left() must be a red leaf node."
                                );
                                BOOST_ASSERT_MSG(
                                    !succ_ptr->left()->left()->right(),
                                    "*root_ptr->right()->left()->left() must be a red leaf node."
                                );

                                if (succ_ptr->left()->right())
                                {
                                    // Case 00.10
                                    BOOST_ASSERT_MSG(
                                        succ_ptr->left()->right()->red(),
                                    "*root_ptr->right()->left()->right() must be a red leaf node."
                                    );
                                    BOOST_ASSERT_MSG(
                                        !succ_ptr->left()->right()->left(),
                                    "*root_ptr->right()->left()->right() must be a red leaf node."
                                    );
                                    BOOST_ASSERT_MSG(
                                        !succ_ptr->left()->right()->right(),
                                    "*root_ptr->right()->left()->right() must be a red leaf node."
                                    );
                                    swap(**root_ptr, **node_ptr);
                                    succ_ptr = succ_ptr->left();
                                    swap(**root_ptr, **succ_ptr->left());
                                    swap(**succ_ptr, **succ_ptr->left());
                                    node_ptr = succ_ptr->right();
                                    swap(**succ_ptr, **node_ptr);
                                    succ_ptr->unset_right();
                                    succ_ptr = root_ptr->left();
                                }
                                else  // if (!root_ptr->right()->left()->right())
                                {
                                    // Case 00.09
                                    swap(**root_ptr, **node_ptr);
                                    succ_ptr = succ_ptr->left();
                                    node_ptr = succ_ptr->left();
                                    swap(**root_ptr, **node_ptr);
                                    succ_ptr->unset_left();
                                }
                            }
                            else  // if (!root_ptr->right()->left()->left())
                            {
                                BOOST_ASSERT_MSG(
                                    !succ_ptr->left()->right(),
                                    "*root_ptr->right()->left() is not left-leaning."
                                );

                                if (succ_ptr->right()->left())
                                {
                                    BOOST_ASSERT_MSG(
                                        succ_ptr->right()->left()->red(),
                                    "*root_ptr->right()->right()->left() must be a red leaf node."
                                    );
                                    BOOST_ASSERT_MSG(
                                        !succ_ptr->right()->left()->left(),
                                    "*root_ptr->right()->right()->left() must be a red leaf node."
                                    );
                                    BOOST_ASSERT_MSG(
                                        !succ_ptr->right()->left()->right(),
                                    "*root_ptr->right()->right()->left() must be a red leaf node."
                                    );

                                    if (succ_ptr->right()->right())
                                    {
                                        // Case 00.13
                                        BOOST_ASSERT_MSG(
                                            succ_ptr->right()->right()->red(),
                                    "*root_ptr->right()->right()->right() must be a red leaf node."
                                        );
                                        BOOST_ASSERT_MSG(
                                            !succ_ptr->right()->right()->left(),
                                    "*root_ptr->right()->right()->right() must be a red leaf node."
                                        );
                                        BOOST_ASSERT_MSG(
                                            !succ_ptr->right()->right()->right(),
                                    "*root_ptr->right()->right()->right() must be a red leaf node."
                                        );
                                        succ_ptr->right()->right()->black(true);
                                        succ_ptr->right()->red(true);
                                        succ_ptr->left()->red(true);
                                        succ_ptr->rotate_left();
                                        succ_ptr->black(true);
                                        swap(**root_ptr, **node_ptr);
                                        swap(**root_ptr, **succ_ptr->left());
                                        swap(**succ_ptr, **succ_ptr->left());
                                        node_ptr = succ_ptr->right();
                                        swap(**succ_ptr, **node_ptr);
                                        succ_ptr->unset_right();
                                    }
                                    else  // if (!root_ptr->right()->right()->right())
                                    {
                                        // Case 00.12
                                        succ_ptr->right()->black(true);
                                        succ_ptr->right()->rotate_right();
                                        succ_ptr->right()->red(true);
                                        succ_ptr->rotate_left();
                                        succ_ptr->black(true);
                                        swap(**root_ptr, **node_ptr);
                                        node_ptr = succ_ptr->left();
                                        swap(**root_ptr, **node_ptr);
                                        succ_ptr->unset_left();
                                    }
                                }
                                else  // if (!root_ptr->right()->right()->left())
                                {
                                    // Case 00.11
                                    BOOST_ASSERT_MSG(
                                        !succ_ptr->right()->right(),
                                        "*root_ptr->right()->right() is not left-leaning."
                                    );
                                    succ_ptr->left()->red(true);
                                    succ_ptr->black(true);
                                    node_ptr->black(true);
                                    swap(**root_ptr, **node_ptr);
                                    swap(**root_ptr, **succ_ptr->left());
                                    swap(**succ_ptr->left(), **succ_ptr);
                                    node_ptr = succ_ptr->right();
                                    swap(**succ_ptr, **node_ptr);
                                    succ_ptr->unset_right();
                                }
                            }
                        }
                        else  // if (!root_ptr->right()->right())
                        {
                            // Case 00.08
                            BOOST_ASSERT_MSG(
                                succ_ptr->left()->red(),
                                "*root_ptr->right()->left() must be a red leaf node."
                            );
                            BOOST_ASSERT_MSG(
                                !succ_ptr->left()->left(),
                                "*root_ptr->right()->left() must be a red leaf node."
                            );
                            BOOST_ASSERT_MSG(
                                !succ_ptr->left()->right(),
                                "*root_ptr->right()->left() must be a red leaf node."
                            );
                            swap(**root_ptr, **node_ptr);
                            node_ptr = succ_ptr->left();
                            swap(**root_ptr, **node_ptr);
                            succ_ptr->unset_left();
                        }

                        succ_ptr = root_ptr->left();
                    }
                    else  // if (!root_ptr->right()->left())
                    {
                        // Case 00.07
                        BOOST_ASSERT_MSG(!succ_ptr->right(), "*succ_ptr is not left-leaning.");
                        swap(**root_ptr, **node_ptr);
                        swap(**root_ptr, **succ_ptr);
                        node_ptr->red(true);
                        succ_ptr = node_ptr;
                        node_ptr = root_ptr->right();
                        root_ptr->unset_right();
                    }

                    return Result(node_ptr, succ_ptr, root_ptr);
                }
                else  // if ((node_ptr == succ_ptr->left()) && (root_ptr != succ_ptr))
                {
                    succ_ptr->unset_left();
                }
            }
        }

        BOOST_ASSERT(node_ptr->black());

        if (succ_ptr->red())
        {
            BOOST_ASSERT_MSG(succ_ptr->parent(), "Root nodes are black.");
            BOOST_ASSERT_MSG(
                succ_ptr->parent()->black(),
                "*succ_ptr must not have a red parent."
            );

            if (succ_ptr->left())
            {
                // *node_ptr was the right child of *succ_ptr.
                next_ptr = succ_ptr->left();
                BOOST_ASSERT_MSG(next_ptr->black(), "*succ_ptr must not have red children.");

                if (next_ptr->left())
                {
                    BOOST_ASSERT_MSG(
                        next_ptr->left()->red(),
                        "*next_ptr must be the only black descendant of *succ_ptr."
                    );

                    if (next_ptr->right())
                    {
                        // Case 01.02
                        BOOST_ASSERT_MSG(
                            next_ptr->right()->red(),
                            "*next_ptr must be the only black descendant of *succ_ptr."
                        );
                        // Flip colors to separate red nodes.
                        next_ptr->left()->black(true);
                        next_ptr->red(true);
                        succ_ptr->black(true);
                    }

                    // Case 01.01
                    // Rotate to maintain balance.
                    succ_ptr->rotate_right();
                }
                else  // if (!next_ptr->left())
                {
                    // Case 01.00
                    BOOST_ASSERT_MSG(
                        !next_ptr->right(),
                        "*succ_ptr->left() is not left-leaning."
                    );
                    next_ptr->red(true);
                    succ_ptr->black(true);
                }

                // Find the actual successor to return.
                for (; (next_ptr = succ_ptr->parent()); )
                {
                    if (succ_ptr == next_ptr->left())
                    {
                        return Result(node_ptr, next_ptr, root_ptr);
                    }
                    else
                    {
                        succ_ptr = next_ptr;
                    }
                }

                return Result(node_ptr, nullptr, root_ptr);
            }
            else  // if (!succ_ptr->left())
            {
                // Case 01.03
                // *node_ptr was the left child of *succ_ptr.
                BOOST_ASSERT_MSG(
                    succ_ptr->right(),
                    "Exactly one more black descendant of *succ_ptr must exist."
                );

                // Restore the left-leaning property.
                NodePointer parent_ptr = succ_ptr->rotate_left();

                BOOST_ASSERT_MSG(
                    parent_ptr->black(),
                    "Red nodes must not have red children or red parents."
                );
                BOOST_ASSERT(!succ_ptr->left());
                next_ptr = parent_ptr->right();

                if (next_ptr)
                {
                    // Case 01.04
                    BOOST_ASSERT_MSG(
                        next_ptr->red(),
"*parent_ptr should have been the only black descendant of *succ_ptr before rotate_left()."
                    );
                    BOOST_ASSERT_MSG(!next_ptr->left(), "*next_ptr must be a leaf node.");
                    BOOST_ASSERT_MSG(!next_ptr->right(), "*next_ptr must be a leaf node.");
                    BOOST_ASSERT_MSG(
                        succ_ptr->right(),
                        "*parent_ptr was not left-leaning before rotate_left()."
                    );
                    BOOST_ASSERT_MSG(
                        succ_ptr->right()->red(),
"*succ_ptr->right() was the left child of *parent_ptr before rotate_left()."
                    );
                    BOOST_ASSERT_MSG(
                        !succ_ptr->right()->left(),
                        "*succ_ptr->right() must be a leaf node."
                    );
                    BOOST_ASSERT_MSG(
                        !succ_ptr->right()->right(),
                        "*succ_ptr->right() must be a leaf node."
                    );
                    // Restore the left-leaning property here.
                    // Then flip colors to separate red nodes while maintaining
                    // the same number of black nodes in the subtrees of *parent_ptr.
                    succ_ptr->rotate_left()->black(true);
                    next_ptr->black(true);
                    parent_ptr->red(true);
                }

                return Result(node_ptr, succ_ptr, root_ptr);
            }
        }

        BOOST_ASSERT(succ_ptr->black());

        NodePointer sibling_ptr = nullptr;

        if (next_ptr)
        {
            // *succ_ptr is already correct.
            // *node_ptr was the left child of *next_ptr.
            sibling_ptr = next_ptr->right();

            if (next_ptr->red())
            {
                BOOST_ASSERT_MSG(
                    sibling_ptr,
                    "Exactly one more black descendant of *next_ptr must exist."
                );
                BOOST_ASSERT_MSG(sibling_ptr->black(), "*next_ptr must not have red children.");

                if (sibling_ptr->left())
                {
                    BOOST_ASSERT_MSG(
                        sibling_ptr->left()->red(),
                        "*next_ptr->right()->left() must be a red leaf node."
                    );
                    BOOST_ASSERT_MSG(
                        !sibling_ptr->left()->left(),
                        "*next_ptr->right()->left() must be a red leaf node."
                    );
                    BOOST_ASSERT_MSG(
                        !sibling_ptr->left()->right(),
                        "*next_ptr->right()->left() must be a red leaf node."
                    );

                    if (sibling_ptr->right())
                    {
                        // Case 01.07
                        BOOST_ASSERT_MSG(
                            sibling_ptr->right()->red(),
                            "*next_ptr->right()->right() must be a red leaf node."
                        );
                        BOOST_ASSERT_MSG(
                            !sibling_ptr->right()->left(),
                            "*next_ptr->right()->right() must be a red leaf node."
                        );
                        BOOST_ASSERT_MSG(
                            !sibling_ptr->right()->right(),
                            "*next_ptr->right()->right() must be a red leaf node."
                        );
                        sibling_ptr->right()->black(true);
                        sibling_ptr->red(true);
                        sibling_ptr = next_ptr->rotate_left();
                        next_ptr = next_ptr->rotate_left();
                        next_ptr->black(true);

                        if (!sibling_ptr->parent())
                        {
                            root_ptr = sibling_ptr;
                        }
                    }
                    else  // if (!next_ptr->right()->right())
                    {
                        // Case 01.06
                        sibling_ptr = sibling_ptr->rotate_right();
                        next_ptr->black(true);
                        next_ptr = next_ptr->rotate_left();

                        if (!next_ptr->parent())
                        {
                            root_ptr = next_ptr;
                        }
                    }
                }
                else  // if (!next_ptr->right()->left())
                {
                    // Case 01.05
                    BOOST_ASSERT_MSG(
                        !sibling_ptr->right(),
                        "*next_ptr->right() is not left-leaning."
                    );
                    next_ptr = next_ptr->rotate_left();

                    if (!next_ptr->parent())
                    {
                        root_ptr = next_ptr;
                    }
                }

                return Result(node_ptr, succ_ptr, root_ptr);
            }
            else  // if (next_ptr->black())
            {
                BOOST_ASSERT_MSG(
                    sibling_ptr,
                    "At least one more black descendant of *next_ptr must exist."
                );
            }
        }
        else if (succ_ptr->right())
        {
            // *node_ptr was the left child of *succ_ptr.
            next_ptr = succ_ptr;
            sibling_ptr = next_ptr->right();
            BOOST_ASSERT_MSG(
                sibling_ptr,
                "At least one more black descendant of *succ_ptr must exist."
            );
        }
        else
        {
            // *node_ptr was the right child of *succ_ptr.
            BOOST_ASSERT(succ_ptr->left());
            next_ptr = succ_ptr->left();
            BOOST_ASSERT_MSG(
                next_ptr,
                "At least one more black descendant of *succ_ptr must exist."
            );

            if (next_ptr->left())
            {
                if (next_ptr->red())
                {
                    BOOST_ASSERT_MSG(
                        next_ptr->left()->black(),
                        "*succ_ptr->left() must have two black children."
                    );
                    BOOST_ASSERT_MSG(
                        next_ptr->right(),
                        "*succ_ptr->left() must have two black children."
                    );
                    BOOST_ASSERT_MSG(
                        next_ptr->right()->black(),
                        "*succ_ptr->left() must have two black children."
                    );
                    succ_ptr->rotate_right();
                    next_ptr = succ_ptr->left();
                    BOOST_ASSERT_MSG(next_ptr, "rotate_right() did not work correctly.");

                    if (next_ptr->left())
                    {
                        // Case 02.03
                        succ_ptr->rotate_right();
                        BOOST_ASSERT_MSG(
                            !succ_ptr->left() || succ_ptr->left()->red(),
                            "*succ_ptr->left() is not left-leaning."
                        );
                        next_ptr->left()->black(true);
                        next_ptr->red(true);
                        next_ptr->parent()->black(true);
                        BOOST_ASSERT_MSG(
                            next_ptr->parent()->left(),
                            "rotate_right() did not work correctly."
                        );
                        BOOST_ASSERT_MSG(
                            next_ptr->parent()->left()->black(),
                            "rotate_right() did not work correctly."
                        );
                    }
                    else  // if (!succ_ptr->left()->left())
                    {
                        // Case 02.02
                        BOOST_ASSERT_MSG(
                            !next_ptr->right(),
                            "*succ_ptr->left() is not left-leaning."
                        );
                        next_ptr->red(true);
                        succ_ptr->parent()->black(true);
                        BOOST_ASSERT_MSG(
                            succ_ptr->parent()->left(),
                            "rotate_right() did not work correctly."
                        );
                        BOOST_ASSERT_MSG(
                            succ_ptr->parent()->left()->black(),
                            "rotate_right() did not work correctly."
                        );
                    }
                }
                else  // if (succ_ptr->left()->black())
                {
                    // Case 02.01
                    succ_ptr->rotate_right();
                    BOOST_ASSERT_MSG(
                        !succ_ptr->left() || succ_ptr->left()->red(),
                        "*succ_ptr->left() was the right child of *next_ptr."
                    );
                    next_ptr = next_ptr->left();
                    BOOST_ASSERT_MSG(next_ptr->red(), "*next_ptr must be a red leaf node.");
                    BOOST_ASSERT_MSG(!next_ptr->left(), "*next_ptr must be a red leaf node.");
                    BOOST_ASSERT_MSG(!next_ptr->right(), "*next_ptr must be a red leaf node.");
                    next_ptr->black(true);
                }

                // Find the actual successor to return.
                for (; (next_ptr = succ_ptr->parent()); )
                {
                    if (succ_ptr == next_ptr->left())
                    {
                        return Result(node_ptr, next_ptr, root_ptr);
                    }
                    else
                    {
                        succ_ptr = next_ptr;
                    }
                }

                return Result(node_ptr, nullptr, root_ptr);
            }
            else  // if (!succ_ptr->left()->left())
            {
                BOOST_ASSERT_MSG(!next_ptr->right(), "*succ_ptr->left() is not left-leaning.");
                BOOST_ASSERT_MSG(
                    next_ptr->black(),
                    "*succ_ptr->left() must be the only other black descendant of *succ_ptr."
                );

                if (succ_ptr->parent())
                {
                    next_ptr->red(true);
                    next_ptr = succ_ptr;

                    if (flag)
                    {
                        // Find the actual successor to return.
                        for (; succ_ptr; )
                        {
                            if (succ_ptr->parent() && (succ_ptr == succ_ptr->parent()->left()))
                            {
                                succ_ptr = succ_ptr->parent();
                                break;
                            }
                            else
                            {
                                succ_ptr = succ_ptr->parent();
                            }
                        }
                    }
                    // The red-black depth of *next_ptr has reduced by one.
                    // The main for-loop must perform more rebalancing.
                }
                else  // if (!succ_ptr->parent())
                {
                    // Case 02.00
                    // *succ_ptr and *succ_ptr->left() must be the only two nodes left in the tree.
                    BOOST_ASSERT(root_ptr == succ_ptr);
                    next_ptr->red(true);
                    return Result(node_ptr, nullptr, root_ptr);
                }
            }
        }

        if (sibling_ptr)
        {
            if (sibling_ptr->left())
            {
                if (sibling_ptr->right())
                {
                    if (sibling_ptr->red())
                    {
                        BOOST_ASSERT_MSG(
                            sibling_ptr->left()->black(),
                            "*next_ptr->right() must not have red children."
                        );
                        BOOST_ASSERT_MSG(
                            sibling_ptr->right()->black(),
                            "*next_ptr->right() must not have red children."
                        );
                        sibling_ptr->black(true);
                        next_ptr->rotate_left();
                        sibling_ptr = next_ptr->right();

                        if (sibling_ptr->left())
                        {
                            BOOST_ASSERT_MSG(
                                sibling_ptr->left()->red(),
                                "*next_ptr->right()->left() must be a red leaf node."
                            );
                            BOOST_ASSERT_MSG(
                                !sibling_ptr->left()->left(),
                                "*next_ptr->right()->left() must be a red leaf node."
                            );
                            BOOST_ASSERT_MSG(
                                !sibling_ptr->left()->right(),
                                "*next_ptr->right()->left() must be a red leaf node."
                            );

                            if (sibling_ptr->right())
                            {
                                // Case 02.08
                                BOOST_ASSERT_MSG(
                                    sibling_ptr->right()->red(),
                                    "*next_ptr->right()->right() must be a red leaf node."
                                );
                                BOOST_ASSERT_MSG(
                                    !sibling_ptr->right()->left(),
                                    "*next_ptr->right()->right() must be a red leaf node."
                                );
                                BOOST_ASSERT_MSG(
                                    !sibling_ptr->right()->right(),
                                    "*next_ptr->right()->right() must be a red leaf node."
                                );
                                next_ptr->rotate_left();
                                next_ptr->rotate_left()->black(true);
                                next_ptr->red(true);
                                sibling_ptr->right()->black(true);
                                sibling_ptr->red(true);
                            }
                            else  // if (!next_ptr->right()->right())
                            {
                                // Case 02.07
                                sibling_ptr->rotate_right()->black(true);
                                sibling_ptr->red(true);
                                next_ptr->rotate_left();
                                next_ptr->red(true);
                            }
                        }
                        else  // if (!next_ptr->right()->left())
                        {
                            // Case 02.06
                            BOOST_ASSERT_MSG(
                                !sibling_ptr->right(),
                                "*next_ptr->right() is not left-leaning."
                            );
                            next_ptr->rotate_left();
                            next_ptr->red(true);
                        }
                    }
                    else  // if (next_ptr->right()->black())
                    {
                        // Case 02.05
                        BOOST_ASSERT_MSG(
                            sibling_ptr->left()->red(),
"*sibling_ptr must be the only other black descendant of *next_ptr."
                        );
                        BOOST_ASSERT_MSG(
                            !sibling_ptr->left()->left(),
"*sibling_ptr must be the only other black descendant of *next_ptr."
                        );
                        BOOST_ASSERT_MSG(
                            !sibling_ptr->left()->right(),
"*sibling_ptr must be the only other black descendant of *next_ptr."
                        );
                        BOOST_ASSERT_MSG(
                            sibling_ptr->right()->red(),
"*sibling_ptr must be the only other black descendant of *next_ptr."
                        );
                        BOOST_ASSERT_MSG(
                            !sibling_ptr->right()->left(),
"*sibling_ptr must be the only other black descendant of *next_ptr."
                        );
                        BOOST_ASSERT_MSG(
                            !sibling_ptr->right()->right(),
"*sibling_ptr must be the only other black descendant of *next_ptr."
                        );
                        next_ptr->rotate_left();
                        next_ptr->rotate_left()->black(true);
                        next_ptr->red(true);
                        sibling_ptr->right()->black(true);
                    }
                }
                else  // if (!next_ptr->right()->right())
                {
                    // Case 02.04
                    BOOST_ASSERT_MSG(
                        sibling_ptr->black(),
                        "*sibling_ptr must be the other black descendant of *next_ptr."
                    );
                    BOOST_ASSERT_MSG(
                        sibling_ptr->left()->red(),
                        "The only child of a black node must be a red leaf node."
                    );
                    BOOST_ASSERT_MSG(
                        !sibling_ptr->left()->left(),
                        "The only child of a black node must be a red leaf node."
                    );
                    BOOST_ASSERT_MSG(
                        !sibling_ptr->left()->right(),
                        "The only child of a black node must be a red leaf node."
                    );
                    // Restore height balance with a double-rotation and a color flip.
                    sibling_ptr->rotate_right();
                    next_ptr->rotate_left()->black(true);
                }

                return Result(node_ptr, succ_ptr, root_ptr);
            }
            else  // if (!next_ptr->right()->left())
            {
                BOOST_ASSERT_MSG(
                    !sibling_ptr->right(),
                    "*next_ptr->right() is not left-leaning."
                );
                BOOST_ASSERT_MSG(
                    sibling_ptr->black(),
                    "*next_ptr->right() must be the only other black descendant of *next_ptr."
                );
                BOOST_ASSERT_MSG(
                    next_ptr->parent(),
                    "Case 00.07 should have been handled previously."
                );
                // Restore the left-leaning property here.
                next_ptr->rotate_left()->red(true);
                next_ptr = next_ptr->parent();
                // The red-black depth of *next_ptr has reduced by one.
                // The main for-loop must perform more rebalancing.
            }
        }

        NodePointer near_ptr;
        NodePointer far_ptr;

        for (NodePointer parent_ptr; (parent_ptr = next_ptr->parent()); next_ptr = parent_ptr)
        {
            flag = (next_ptr == parent_ptr->left());

            if (flag)
            {
                sibling_ptr = parent_ptr->right();
                near_ptr = sibling_ptr->left();
                far_ptr = sibling_ptr->right();
            }
            else  // if (next_ptr == parent_ptr->right())
            {
                sibling_ptr = parent_ptr->left();
                near_ptr = sibling_ptr->right();
                far_ptr = sibling_ptr->left();
            }

            // At this point, the red-black height of *next_ptr
            // is one less than that of *sibling_ptr.
            if (sibling_ptr->red())
            {
                // Case 03.01
                BOOST_ASSERT_MSG(parent_ptr->black(), "Red nodes must not have red parents.");
                BOOST_ASSERT_MSG(near_ptr->black(), "Red nodes must not have red children.");
                BOOST_ASSERT_MSG(far_ptr->black(), "Red nodes must not have red children.");
                sibling_ptr->black(true);
                parent_ptr->red(true);

                if (flag)
                {
                    if (root_ptr == parent_ptr)
                    {
                        root_ptr = parent_ptr->rotate_left();
                        root_ptr->black(true);
                    }
                    else
                    {
                        parent_ptr->rotate_left();
                    }

                    sibling_ptr = parent_ptr->right();
                    near_ptr = sibling_ptr->left();
                    far_ptr = sibling_ptr->right();
                }
                else  // if (!flag)
                {
                    if (root_ptr == parent_ptr)
                    {
                        root_ptr = parent_ptr->rotate_right();
                        root_ptr->black(true);
                    }
                    else
                    {
                        parent_ptr->rotate_right();
                    }

                    sibling_ptr = parent_ptr->left();
                    near_ptr = sibling_ptr->right();
                    far_ptr = sibling_ptr->left();
                }
            }

            if (parent_ptr->red() && sibling_ptr->black() && near_ptr->black() && far_ptr->black())
            {
                // Case 03.00
                parent_ptr->black(true);
                sibling_ptr->red(true);
                return Result(node_ptr, succ_ptr, root_ptr);
            }

            if (sibling_ptr->black() && near_ptr->red() && far_ptr->black())
            {
                // Case 03.03
                if (flag)
                {
                    sibling_ptr = sibling_ptr->rotate_right();
                    near_ptr = sibling_ptr->left();
                    far_ptr = sibling_ptr->right();
                }
                else
                {
                    sibling_ptr = sibling_ptr->rotate_left();
                    near_ptr = sibling_ptr->right();
                    far_ptr = sibling_ptr->left();
                }

                sibling_ptr->black(true);
                far_ptr->red(true);
            }

            if (sibling_ptr->black() && /*near_ptr->black() && */far_ptr->red())
            {
                // Case 03.02
                sibling_ptr->red(parent_ptr->red());
                parent_ptr->black(true);
                far_ptr->black(true);

                if (flag)
                {
                    parent_ptr = parent_ptr->rotate_left();
                }
                else
                {
                    parent_ptr = parent_ptr->rotate_right();
                }

                if (!parent_ptr->parent())
                {
                    root_ptr = parent_ptr;
                    root_ptr->black(true);
                }

                return Result(node_ptr, succ_ptr, root_ptr);
            }

            // Case 03.04
            BOOST_ASSERT(parent_ptr->black());
            BOOST_ASSERT(sibling_ptr->black());
            BOOST_ASSERT(near_ptr->black());
            BOOST_ASSERT(far_ptr->black());
            sibling_ptr->red(true);
        }

        return Result(node_ptr, succ_ptr, next_ptr);
    }
}}  // namespace odds_and_ends::node

#endif  // ODDS_AND_ENDS__NODE__BALANCER__LEFT_LEANING_RED_BLACK_TREE_HPP

