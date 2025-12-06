// Copyright (C) 2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__ALGORITHM__RED_BLACK_TREE_TEST_HPP
#define ODDS_AND_ENDS__NODE__ALGORITHM__RED_BLACK_TREE_TEST_HPP

namespace odds_and_ends { namespace node { namespace algorithm { namespace _detail {

    struct binary_noop
    {
        template <typename T0, typename T1>
        inline void operator()(T0 const&, T1 const&) const
        {
        }
    };
}}}}  // namespace odds_and_ends::node::algorithm::_detail

namespace odds_and_ends { namespace node { namespace algorithm {

    enum red_black_tree_test_bit
    {
        red_black_tree_test_bit_for_red_node_with_red_parent,
        red_black_tree_test_bit_for_black_node_with_single_left_black_child,
        red_black_tree_test_bit_for_black_node_with_single_right_black_child,
        red_black_tree_test_bit_count
    };

    template <typename Node>
    inline bool is_red_black_leaf_node(Node const& node)
    {
        if (node.red())
        {
            return (!node.left() && !node.right());
        }

        if (node.left())
        {
            if (node.left()->black())
            {
                return false;
            }

            if (node.left()->left() || node.left()->right())
            {
                return false;
            }
        }

        if (node.right())
        {
            if (node.right()->black())
            {
                return false;
            }

            if (node.right()->left() || node.right()->right())
            {
                return false;
            }
        }

        return true;
    }
}}}  // namespace odds_and_ends::node::algorithm

#include <memory>
#include <boost/utility/value_init.hpp>

namespace odds_and_ends { namespace node { namespace algorithm {

    template <typename Node>
    typename Node::traits::size_type get_red_black_depth(Node const& node)
    {
        typename Node::traits::size_type result = ::boost::initialized_value;

        for (
            typename Node::traits::const_pointer p = ::std::pointer_traits<
                typename Node::traits::const_pointer
            >::pointer_to(node);
            p;
            p = p->parent()
        )
        {
            if (p->black())
            {
                ++result;
            }
        }

        return result;
    }
}}}  // namespace odds_and_ends::node::algorithm

#include <vector>
#include <odds_and_ends/node/iterator/in_order_tree.hpp>

namespace odds_and_ends { namespace node { namespace algorithm {

    template <typename Node>
    ::std::vector<typename Node::traits::size_type> red_black_tree_test_depths(Node const& node)
    {
        static typename Node::traits::size_type const zero_v = ::boost::initialized_value;
        ::std::vector<typename Node::traits::size_type> result(node.size(), zero_v);
        ::odds_and_ends::node::in_order_tree_iterator<Node const> itr(node);

        for (
            typename Node::traits::size_type index = ::boost::initialized_value;
            index < node.size();
            ++index
        )
        {
            if (::odds_and_ends::node::algorithm::is_red_black_leaf_node(*itr))
            {
                result[index] = ::odds_and_ends::node::algorithm::get_red_black_depth(*itr);
            }

            ++itr;
        }

        BOOST_ASSERT(!itr);
        return result;
    }
}}}  // namespace odds_and_ends::node::algorithm

#include <bitset>
#include <boost/assert.hpp>

namespace odds_and_ends { namespace node { namespace algorithm {

    template <typename Node>
    ::std::vector<
        ::std::bitset< ::odds_and_ends::node::algorithm::red_black_tree_test_bit_count>
    >
        red_black_tree_test_invariants(Node const& node)
    {
        ::std::vector<
            ::std::bitset< ::odds_and_ends::node::algorithm::red_black_tree_test_bit_count>
        > result(node.size());
        ::odds_and_ends::node::in_order_tree_iterator<Node const> itr(node);

        for (
            typename Node::traits::size_type index = ::boost::initialized_value;
            index < node.size();
            ++index
        )
        {
            if (itr->red())
            {
                if (itr->parent() && itr->parent()->red())
                {
                    result[index].set(
                        ::odds_and_ends::node::algorithm
                        ::red_black_tree_test_bit_for_red_node_with_red_parent
                    );
                }
            }
            else
            {
                BOOST_ASSERT(itr->black());

                if (itr->left() && !itr->right() && itr->left()->black())
                {
                    result[index].set(
                        ::odds_and_ends::node::algorithm
                        ::red_black_tree_test_bit_for_black_node_with_single_left_black_child
                    );
                }

                if (!itr->left() && itr->right() && itr->right()->black())
                {
                    result[index].set(
                        ::odds_and_ends::node::algorithm
                        ::red_black_tree_test_bit_for_black_node_with_single_right_black_child
                    );
                }
            }

            ++itr;
        }

        BOOST_ASSERT(!itr);
        return result;
    }
}}}  // namespace odds_and_ends::node::algorithm

namespace odds_and_ends { namespace node { namespace algorithm { namespace _detail {

    template <typename TestResult, typename TestDepthsResult, typename F0, typename F1>
    bool
        red_black_tree_test(
            TestResult test_result,
            TestDepthsResult test_depths_result,
            F0 const& f0,
            F1 const& f1
        )
    {
        bool test_flag = true;

        for (
            typename TestResult::size_type index = ::boost::initialized_value;
            index < test_result.size();
            ++index
        )
        {
            if (
                test_result[index].test(
                    ::odds_and_ends::node::algorithm
                    ::red_black_tree_test_bit_for_red_node_with_red_parent
                )
            )
            {
                test_flag = false;
                f0(
                    index,
                    ::odds_and_ends::node::algorithm
                    ::red_black_tree_test_bit_for_red_node_with_red_parent
                );
            }

            if (
                test_result[index].test(
                    ::odds_and_ends::node::algorithm
                    ::red_black_tree_test_bit_for_black_node_with_single_left_black_child
                )
            )
            {
                test_flag = false;
                f0(
                    index,
                    ::odds_and_ends::node::algorithm
                    ::red_black_tree_test_bit_for_black_node_with_single_left_black_child
                );
            }

            if (
                test_result[index].test(
                    ::odds_and_ends::node::algorithm
                    ::red_black_tree_test_bit_for_black_node_with_single_right_black_child
                )
            )
            {
                test_flag = false;
                f0(
                    index,
                    ::odds_and_ends::node::algorithm
                    ::red_black_tree_test_bit_for_black_node_with_single_right_black_child
                );
            }
        }

        typename TestDepthsResult::value_type depth = ::boost::initialized_value;

        for (
            typename TestDepthsResult::size_type index = ::boost::initialized_value;
            index < test_depths_result.size();
            ++index
        )
        {
            if (test_depths_result[index])
            {
                f1(index, test_depths_result[index]);

                if (depth)
                {
                    if (test_depths_result[index] != depth)
                    {
                        test_flag = false;
                    }
                }
                else
                {
                    depth = test_depths_result[index];
                }
            }
        }

        return test_flag;
    }
}}}}  // namespace odds_and_ends::node::algorithm::_detail

namespace odds_and_ends { namespace node { namespace algorithm {

    template <typename Node, typename F0, typename F1>
    inline bool red_black_tree_test(Node const& node, F0 const& f0, F1 const& f1)
    {
        return ::odds_and_ends::node::algorithm::_detail::red_black_tree_test(
            ::odds_and_ends::node::algorithm::red_black_tree_test_invariants(node),
            ::odds_and_ends::node::algorithm::red_black_tree_test_depths(node),
            f0,
            f1
        );
    }

    template <typename Node>
    inline bool red_black_tree_test(Node const& node)
    {
        return ::odds_and_ends::node::algorithm::red_black_tree_test(
            node,
            ::odds_and_ends::node::algorithm::_detail::binary_noop(),
            ::odds_and_ends::node::algorithm::_detail::binary_noop()
        );
    }
}}}  // namespace odds_and_ends::node::algorithm

#endif  // ODDS_AND_ENDS__NODE__ALGORITHM__RED_BLACK_TREE_TEST_HPP

