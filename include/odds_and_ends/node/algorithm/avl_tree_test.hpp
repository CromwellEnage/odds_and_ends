// Copyright (C) 2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__ALGORITHM__AVL_TREE_TEST_HPP
#define ODDS_AND_ENDS__NODE__ALGORITHM__AVL_TREE_TEST_HPP

namespace odds_and_ends { namespace node { namespace algorithm {

    enum avl_tree_test_bit
    {
        avl_tree_test_bit_is_left_heavy,
        avl_tree_test_bit_is_right_heavy,
        avl_tree_test_bit_has_incorrect_balance_factor,
        avl_tree_test_bit_count
    };
}}}  // namespace odds_and_ends::node::algorithm

#include <odds_and_ends/node/iterator/in_order_tree.hpp>
#include <boost/utility/value_init.hpp>

namespace odds_and_ends { namespace node { namespace algorithm {

    template <typename Node, typename F>
    bool avl_tree_test(Node const& node, F f)
    {
        bool result = true;
        typename Node::traits::height_type one = ::boost::initialized_value;

        ++one;

        for (
            ::odds_and_ends::node::in_order_tree_iterator<Node const> itr(node, false);
            !(!itr);
            ++itr
        )
        {
            if (1 < itr->balance_factor())
            {
                result = false;

                if (f)
                {
                    f(
                        **itr,
                        ::odds_and_ends::node::algorithm::avl_tree_test_bit_is_right_heavy
                    );
                }
            }
            else if (itr->balance_factor() < -1)
            {
                result = false;

                if (f)
                {
                    f(
                        **itr,
                        ::odds_and_ends::node::algorithm::avl_tree_test_bit_is_left_heavy
                    );
                }
            }

            if (itr->left())
            {
                if (itr->right())
                {
                    if (itr->left()->height() + one < itr->right()->height())
                    {
                        result = false;

                        if (f)
                        {
                            f(
                                **itr,
                                ::odds_and_ends::node::algorithm::avl_tree_test_bit_is_right_heavy
                            );
                        }
                    }
                    else if (itr->right()->height() + one < itr->left()->height())
                    {
                        result = false;

                        if (f)
                        {
                            f(
                                **itr,
                                ::odds_and_ends::node::algorithm::avl_tree_test_bit_is_left_heavy
                            );
                        }
                    }

                    if (itr->left()->height() + itr->balance_factor() != itr->right()->height())
                    {
                        result = false;

                        if (f)
                        {
                            f(
                                **itr,
                                ::odds_and_ends::node::algorithm
                                ::avl_tree_test_bit_has_incorrect_balance_factor
                            );
                        }
                    }
                }
                else  // if (!itr->right())
                {
                    if (one <= itr->left()->height())
                    {
                        result = false;

                        if (f)
                        {
                            f(
                                **itr,
                                ::odds_and_ends::node::algorithm::avl_tree_test_bit_is_left_heavy
                            );
                        }
                    }

                    if (itr->height() != -itr->balance_factor())
                    {
                        result = false;

                        if (f)
                        {
                            f(
                                **itr,
                                ::odds_and_ends::node::algorithm
                                ::avl_tree_test_bit_has_incorrect_balance_factor
                            );
                        }
                    }
                }
            }
            else if (itr->right())
            {
                if (one <= itr->right()->height())
                {
                    result = false;

                    if (f)
                    {
                        f(
                            **itr,
                            ::odds_and_ends::node::algorithm::avl_tree_test_bit_is_right_heavy
                        );
                    }
                }

                if (itr->balance_factor() != itr->height())
                {
                    result = false;

                    if (f)
                    {
                        f(
                            **itr,
                            ::odds_and_ends::node::algorithm
                            ::avl_tree_test_bit_has_incorrect_balance_factor
                        );
                    }
                }
            }
            else if (0 != itr->balance_factor())
            {
                result = false;

                if (f)
                {
                    f(
                        **itr,
                        ::odds_and_ends::node::algorithm
                        ::avl_tree_test_bit_has_incorrect_balance_factor
                    );
                }
            }
        }

        return result;
    }
}}}  // namespace odds_and_ends::node::algorithm

#include <functional>

namespace odds_and_ends { namespace node { namespace algorithm {

    template <typename Node>
    inline bool avl_tree_test(Node const& node)
    {
        return ::odds_and_ends::node::algorithm::avl_tree_test(
            node,
            ::std::function<
                void(
                    typename Node::traits::value_type const&,
                    ::odds_and_ends::node::algorithm::avl_tree_test_bit
                )
            >()
        );
    }
}}}  // namespace odds_and_ends::node::algorithm

#endif  // ODDS_AND_ENDS__NODE__ALGORITHM__AVL_TREE_TEST_HPP

