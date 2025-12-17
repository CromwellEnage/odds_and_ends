// Copyright (C) 2011-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__TREE__BINARY_HPP
#define ODDS_AND_ENDS__NODE__TREE__BINARY_HPP

#include <cstddef>
#include <utility>
#include <memory>
#include <odds_and_ends/node/iterator/binary_tree_child.hpp>
#include <odds_and_ends/node/event/pre_clear.hpp>
#include <odds_and_ends/node/event/pre_erase.hpp>
#include <odds_and_ends/node/event/post_clear.hpp>
#include <odds_and_ends/node/event/post_erase_left_tree.hpp>
#include <odds_and_ends/node/event/post_erase_right_tree.hpp>
#include <odds_and_ends/node/event/post_insert_left_tree.hpp>
#include <odds_and_ends/node/event/post_insert_right_tree.hpp>
#include <odds_and_ends/node/event/post_rotate_left_tree.hpp>
#include <odds_and_ends/node/event/post_rotate_right_tree.hpp>
#include <odds_and_ends/node/algorithm/is_ancestor_of.hpp>
#include <odds_and_ends/composite_type/event/default_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/default_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/allocator_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/variadic_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/variadic_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/arg_pack_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/arg_pack_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/conversion_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/conversion_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/coercive_copy_constructor.hpp>
#include <odds_and_ends/composite_type/event/copy_assignment.hpp>
#include <odds_and_ends/composite_type/event/copy_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/coercive_move_constructor.hpp>
#include <odds_and_ends/composite_type/event/move_assignment.hpp>
#include <odds_and_ends/composite_type/event/move_2nd_stage.hpp>
#include <odds_and_ends/composite_type/preprocessor/noncopyable_nonmovable_body.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/assert.hpp>

namespace odds_and_ends { namespace node { namespace tree {

    template <typename ItrDiff = ::std::ptrdiff_t>
    struct binary
    {
        template <typename CompositeParentGenerator>
        struct apply
        {
            struct type
            {
                template <typename Derived>
                class apply
                {
                    typedef typename ::boost::mpl::apply_wrap1<
                        CompositeParentGenerator,
                        Derived
                    >::type _composite_parent_t;

                    class _result : public _composite_parent_t
                    {
                        typename _composite_parent_t::traits::pointer _left;
                        typename _composite_parent_t::traits::pointer _right;

                    protected:
                        inline explicit _result(
                            ::odds_and_ends::composite_type
                            ::default_constructor_1st_stage_event const& e
                        ) : _composite_parent_t(e), _left(nullptr), _right(nullptr)
                        {
                        }

                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type
                                ::default_constructor_2nd_stage_event const& e
                            )
                        {
                            return _composite_parent_t::post_construct(e);
                        }

                        template <typename Alloc, typename ...Args>
                        inline _result(
                            ::std::allocator_arg_t const& o,
                            Alloc const& alloc,
                            Args&& ...args
                        ) : _composite_parent_t(o, alloc, ::std::forward<Args>(args)...),
                            _left(nullptr),
                            _right(nullptr)
                        {
                        }

                        template <typename Alloc, typename ...Args>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type
                                ::allocator_constructor_2nd_stage_event const& e,
                                Alloc const& alloc,
                                Args&& ...args
                            )
                        {
                            return _composite_parent_t::post_construct(
                                e,
                                alloc,
                                ::std::forward<Args>(args)...
                            );
                        }

                        template <typename A0, typename ...Args>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::variadic_constructor_1st_stage_event const& e,
                            A0&& a0,
                            Args&& ...args
                        ) : _composite_parent_t(
                                e,
                                ::std::forward<A0>(a0),
                                ::std::forward<Args>(args)...
                            ),
                            _left(nullptr),
                            _right(nullptr)
                        {
                        }

                        template <typename A0, typename ...Args>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type
                                ::variadic_constructor_2nd_stage_event const& e,
                                A0&& a0,
                                Args&&... args
                            )
                        {
                            return _composite_parent_t::post_construct(
                                e,
                                ::std::forward<A0>(a0),
                                ::std::forward<Args>(args)...
                            );
                        }

                        template <typename ArgumentPack>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::arg_pack_constructor_1st_stage_event const& e,
                            ArgumentPack const& arg_pack
                        ) : _composite_parent_t(e, arg_pack), _left(nullptr),  _right(nullptr)
                        {
                        }

                        template <typename ArgumentPack>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type
                                ::arg_pack_constructor_2nd_stage_event const& e,
                                ArgumentPack const& arg_pack
                            )
                        {
                            return _composite_parent_t::post_construct(e, arg_pack);
                        }

                        template <typename Arg>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::conversion_constructor_1st_stage_event const& e,
                            Arg const& arg
                        ) : _composite_parent_t(e, arg), _left(nullptr), _right(nullptr)
                        {
                        }


                        template <typename Arg>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type
                                ::conversion_constructor_2nd_stage_event const& e,
                                Arg const& arg
                            )
                        {
                            return _composite_parent_t::post_construct(e, arg);
                        }

                        template <typename Copy>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::coercive_copy_constructor_event const& e,
                            Copy const& copy
                        ) : _composite_parent_t(e, copy), _left(nullptr), _right(nullptr)
                        {
                        }

                        template <typename Copy, typename Alloc>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::coercive_copy_constructor_event const& e,
                            Copy const& copy,
                            Alloc const& alloc
                        ) : _composite_parent_t(e, copy, alloc), _left(nullptr), _right(nullptr)
                        {
                        }

                        template <typename Copy>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::copy_assignment_event const& e,
                                Copy const& copy
                            )
                        {
                            return _composite_parent_t::post_construct(e, copy);
                        }

                        template <typename Copy, typename Alloc>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::copy_assignment_event const& e,
                                Copy const& copy,
                                Alloc const& alloc
                            )
                        {
                            return _composite_parent_t::post_construct(e, copy, alloc);
                        }

                        template <typename Copy>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::copy_2nd_stage_event const& e,
                                Copy const& copy
                            )
                        {
                            return _composite_parent_t::post_construct(e, copy);
                        }

                        template <typename Copy, typename Alloc>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::copy_2nd_stage_event const& e,
                                Copy const& copy,
                                Alloc const& alloc
                            )
                        {
                            return _composite_parent_t::post_construct(e, copy, alloc);
                        }

                        template <typename Source>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::coercive_move_constructor_event const& e,
                            Source&& source
                        ) : _composite_parent_t(e, static_cast<Source&&>(source)),
                            _left(nullptr),
                            _right(nullptr)
                        {
                        }

                        template <typename Source, typename Alloc>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::coercive_move_constructor_event const& e,
                            Source&& source,
                            Alloc const& alloc
                        ) : _composite_parent_t(e, static_cast<Source&&>(source), alloc),
                            _left(nullptr),
                            _right(nullptr)
                        {
                        }

                        template <typename Source>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::move_assignment_event const& e,
                                Source&& source
                            )
                        {
                            return _composite_parent_t::post_construct(
                                e,
                                static_cast<Source&&>(source)
                            );
                        }

                        template <typename Source, typename Alloc>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::move_assignment_event const& e,
                                Source&& source,
                                Alloc const& alloc
                            )
                        {
                            return _composite_parent_t::post_construct(
                                e,
                                static_cast<Source&&>(source),
                                alloc
                            );
                        }

                        template <typename Source>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::move_2nd_stage_event const& e,
                                Source&& source
                            )
                        {
                            return _composite_parent_t::post_construct(
                                e,
                                static_cast<Source&&>(source)
                            );
                        }

                        template <typename Source, typename Alloc>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::move_2nd_stage_event const& e,
                                Source&& source,
                                Alloc const& alloc
                            )
                        {
                            return _composite_parent_t::post_construct(
                                e,
                                static_cast<Source&&>(source),
                                alloc
                            );
                        }

                    public:
                        inline ~_result()
                        {
                        }

                        struct traits : _composite_parent_t::traits
                        {
                            typedef ::odds_and_ends::node::binary_tree_child_iterator<
                                Derived,
                                ::boost::mpl::false_,
                                ItrDiff
                            > child_iterator;
                            typedef ::odds_and_ends::node::binary_tree_child_iterator<
                                Derived const,
                                ::boost::mpl::false_,
                                ItrDiff
                            > child_const_iterator;
                            typedef ::odds_and_ends::node::binary_tree_child_iterator<
                                Derived,
                                ::boost::mpl::true_,
                                ItrDiff
                            > child_reverse_iterator;
                            typedef ::odds_and_ends::node::binary_tree_child_iterator<
                                Derived const,
                                ::boost::mpl::true_,
                                ItrDiff
                            > child_const_reverse_iterator;
                        };

                        inline typename traits::const_pointer left() const
                        {
                            return this->_left;
                        }

                        inline typename traits::pointer left()
                        {
                            return this->_left;
                        }

                        inline typename traits::const_pointer right() const
                        {
                            return this->_right;
                        }

                        inline typename traits::pointer right()
                        {
                            return this->_right;
                        }

                        inline bool is_leaf()
                        {
                            return !this->_left && !this->_right;
                        }

                        inline typename traits::child_const_iterator begin() const
                        {
                            return typename traits::child_const_iterator(
                                ::std::pointer_traits<typename traits::pointer>::pointer_to(
                                    this->derived()
                                ),
                                false
                            );
                        }

                        inline typename traits::child_iterator begin()
                        {
                            return typename traits::child_iterator(
                                ::std::pointer_traits<typename traits::pointer>::pointer_to(
                                    this->derived()
                                ),
                                false
                            );
                        }

                        inline typename traits::child_const_iterator end() const
                        {
                            return typename traits::child_const_iterator(
                                ::std::pointer_traits<typename traits::pointer>::pointer_to(
                                    this->derived()
                                )
                            );
                        }

                        inline typename traits::child_iterator end()
                        {
                            return typename traits::child_iterator(
                                ::std::pointer_traits<typename traits::pointer>::pointer_to(
                                    this->derived()
                                )
                            );
                        }

                        inline typename traits::child_const_reverse_iterator rbegin() const
                        {
                            return typename traits::child_const_reverse_iterator(
                                ::std::pointer_traits<typename traits::pointer>::pointer_to(
                                    this->derived()
                                ),
                                false
                            );
                        }

                        inline typename traits::child_reverse_iterator rbegin()
                        {
                            return typename traits::child_reverse_iterator(
                                ::std::pointer_traits<typename traits::pointer>::pointer_to(
                                    this->derived()
                                ),
                                false
                            );
                        }

                        inline typename traits::child_const_reverse_iterator rend() const
                        {
                            return typename traits::child_const_reverse_iterator(
                                ::std::pointer_traits<typename traits::pointer>::pointer_to(
                                    this->derived()
                                )
                            );
                        }

                        inline typename traits::child_reverse_iterator rend()
                        {
                            return typename traits::child_reverse_iterator(
                                ::std::pointer_traits<typename traits::pointer>::pointer_to(
                                    this->derived()
                                )
                            );
                        }

                    private:
                        inline void _set_left(typename traits::pointer p)
                        {
                            this->_left = p;
                            p->parent(
                                ::std::pointer_traits<typename traits::pointer>::pointer_to(
                                    this->derived()
                                )
                            );
                        }

                        inline void _set_right(typename traits::pointer p)
                        {
                            this->_right = p;
                            p->parent(
                                ::std::pointer_traits<typename traits::pointer>::pointer_to(
                                    this->derived()
                                )
                            );
                        }

                    public:
                        inline void unset_left()
                        {
                            BOOST_ASSERT_MSG(
                                this->_left,
                                "This node has no left child to remove."
                            );
                            this->_left->handle(::odds_and_ends::node::pre_erase_event());
                            this->_left->parent(nullptr);
                            this->_left = nullptr;
                            this->handle(::odds_and_ends::node::post_erase_left_tree_event());
                        }

                        inline void set_left_ptr(typename traits::pointer p)
                        {
                            BOOST_ASSERT(!!p);
                            BOOST_ASSERT(
                                ::std::pointer_traits<typename traits::pointer>::pointer_to(
                                    this->derived()
                                ) != p
                            );
                            BOOST_ASSERT(
                                !::odds_and_ends::node::algorithm::is_ancestor_of(
                                    p,
                                    ::std::pointer_traits<typename traits::pointer>::pointer_to(
                                        this->derived()
                                    )
                                )
                            );

                            if (this->_left)
                            {
                                this->unset_left();
                            }

                            this->_set_left(p);
                            this->handle(::odds_and_ends::node::post_insert_left_tree_event());
                        }

                        inline void set_left(Derived& n)
                        {
                            this->set_left_ptr(
                                ::std::pointer_traits<typename traits::pointer>::pointer_to(n)
                            );
                        }

                        inline void unset_right()
                        {
                            BOOST_ASSERT_MSG(
                                this->_right,
                                "This node has no right child to remove."
                            );
                            this->_right->handle(::odds_and_ends::node::pre_erase_event());
                            this->_right->parent(nullptr);
                            this->_right = nullptr;
                            this->handle(::odds_and_ends::node::post_erase_right_tree_event());
                        }

                        inline void set_right_ptr(typename traits::pointer p)
                        {
                            BOOST_ASSERT(!!p);
                            BOOST_ASSERT(
                                ::std::pointer_traits<typename traits::pointer>::pointer_to(
                                    this->derived()
                                ) != p
                            );
                            BOOST_ASSERT(
                                !::odds_and_ends::node::algorithm::is_ancestor_of(
                                    p,
                                    ::std::pointer_traits<typename traits::pointer>::pointer_to(
                                        this->derived()
                                    )
                                )
                            );

                            if (this->_right)
                            {
                                this->unset_right();
                            }

                            this->_set_right(p);
                            this->handle(::odds_and_ends::node::post_insert_right_tree_event());
                        }

                        inline void set_right(Derived& n)
                        {
                            this->set_right_ptr(
                                ::std::pointer_traits<typename traits::pointer>::pointer_to(n)
                            );
                        }

                        inline void clear()
                        {
                            this->handle(::odds_and_ends::node::pre_clear_event());

                            if (this->_left)
                            {
                                this->_left->parent(nullptr);
                                this->_left = nullptr;
                            }

                            if (this->_right)
                            {
                                this->_right->parent(nullptr);
                                this->_right = nullptr;
                            }

                            this->handle(::odds_and_ends::node::post_clear_event());
                        }

                        inline typename traits::pointer rotate_left()
                        {
                            typename traits::pointer p = this->_right;

                            BOOST_ASSERT_MSG(p, "This node has no right child to rotate to.");

                            if (p->left())
                            {
                                this->_set_right(p->left());
                            }
                            else
                            {
                                this->_right = nullptr;
                            }

                            typename traits::pointer t = (
                                ::std::pointer_traits<typename traits::pointer>::pointer_to(
                                    this->derived()
                                )
                            );

                            if (t->parent())
                            {
                                if (t->parent()->left() == t)
                                {
                                    t->parent()->_set_left(p);
                                }
                                else
                                {
                                    t->parent()->_set_right(p);
                                }
                            }
                            else
                            {
                                p->parent(nullptr);
                            }

                            p->_set_left(t);
                            this->handle(::odds_and_ends::node::post_rotate_left_tree_event());
                            return p;
                        }

                        inline typename traits::pointer rotate_right()
                        {
                            typename traits::pointer p = this->_left;

                            BOOST_ASSERT_MSG(p, "This node has no left child to rotate to.");

                            if (p->right())
                            {
                                this->_set_left(p->right());
                            }
                            else
                            {
                                this->_left = nullptr;
                            }

                            typename traits::pointer t = (
                                ::std::pointer_traits<typename traits::pointer>::pointer_to(
                                    this->derived()
                                )
                            );

                            if (t->parent())
                            {
                                if (t->parent()->left() == t)
                                {
                                    t->parent()->_set_left(p);
                                }
                                else
                                {
                                    t->parent()->_set_right(p);
                                }
                            }
                            else
                            {
                                p->parent(nullptr);
                            }

                            p->_set_right(t);
                            this->handle(::odds_and_ends::node::post_rotate_right_tree_event());
                            return p;
                        }

                        ODDS_AND_ENDS__COMPOSITE_TYPE__NONCOPYABLE_NONMOVABLE_BODY(_result)
                    };

                public:
                    typedef _result type;
                };
            };
        };
    };
}}}  // namespace odds_and_ends::node::tree

#endif  // ODDS_AND_ENDS__NODE__TREE__BINARY_HPP

