// Copyright (C) 2012-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__TREE__WITH_SIZE_HPP
#define ODDS_AND_ENDS__NODE__TREE__WITH_SIZE_HPP

#include <cstddef>
#include <utility>
#include <memory>
#include <odds_and_ends/node/event/post_insert.hpp>
#include <odds_and_ends/node/event/post_insert_left_tree.hpp>
#include <odds_and_ends/node/event/post_insert_right_tree.hpp>
#include <odds_and_ends/node/event/post_rotate_left_tree.hpp>
#include <odds_and_ends/node/event/post_rotate_right_tree.hpp>
#include <odds_and_ends/node/event/post_erase.hpp>
#include <odds_and_ends/node/event/post_erase_left_tree.hpp>
#include <odds_and_ends/node/event/post_erase_right_tree.hpp>
#include <odds_and_ends/node/event/pre_erase.hpp>
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
#include <boost/mpl/apply_wrap.hpp>
#include <boost/utility/value_init.hpp>

namespace odds_and_ends { namespace node { namespace tree {

    template <typename IntType = ::std::size_t>
    struct with_size
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
                        IntType _size;

                    protected:
                        inline explicit _result(
                            ::odds_and_ends::composite_type
                            ::default_constructor_1st_stage_event const& e
                        ) : _composite_parent_t(e), _size(::boost::initialized_value)
                        {
                        }

                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type
                                ::default_constructor_2nd_stage_event const& e
                            )
                        {
                            bool const result = _composite_parent_t::post_construct(e);
                            ++this->_size;
                            return result;
                        }

                        template <typename Alloc, typename ...Args>
                        inline _result(
                            ::std::allocator_arg_t const& o,
                            Alloc const& alloc,
                            Args&& ...args
                        ) : _composite_parent_t(o, alloc, ::std::forward<Args>(args)...),
                            _size(::boost::initialized_value)
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
                            bool const result = _composite_parent_t::post_construct(
                                e,
                                alloc,
                                ::std::forward<Args>(args)...
                            );
                            ++this->_size;
                            return result;
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
                            _size(::boost::initialized_value)
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
                            bool const result = _composite_parent_t::post_construct(
                                e,
                                ::std::forward<A0>(a0),
                                ::std::forward<Args>(args)...
                            );
                            ++this->_size;
                            return result;
                        }

                        template <typename ArgumentPack>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::arg_pack_constructor_1st_stage_event const& e,
                            ArgumentPack const& arg_pack
                        ) : _composite_parent_t(e, arg_pack), _size(::boost::initialized_value)
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
                            bool const result = _composite_parent_t::post_construct(e, arg_pack);
                            ++this->_size;
                            return result;
                        }

                        template <typename Arg>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::conversion_constructor_1st_stage_event const& e,
                            Arg const& arg
                        ) : _composite_parent_t(e, arg), _size(::boost::initialized_value)
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
                            bool const result = _composite_parent_t::post_construct(e, arg);
                            ++this->_size;
                            return result;
                        }

                        template <typename Copy>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::coercive_copy_constructor_event const& e,
                            Copy const& copy
                        ) : _composite_parent_t(e, copy), _size(copy.size())
                        {
                        }

                        template <typename Copy, typename Alloc>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::coercive_copy_constructor_event const& e,
                            Copy const& copy,
                            Alloc const& alloc
                        ) : _composite_parent_t(e, copy, alloc), _size(copy.size())
                        {
                        }

                        template <typename Copy>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::copy_assignment_event const& e,
                                Copy const& copy
                            )
                        {
                            bool const result = _composite_parent_t::post_construct(e, copy);
                            this->_size = copy.size();
                            return result;
                        }

                        template <typename Copy, typename Alloc>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::copy_assignment_event const& e,
                                Copy const& copy,
                                Alloc const& alloc
                            )
                        {
                            bool const result = (
                                _composite_parent_t::post_construct(e, copy, alloc)
                            );
                            this->_size = copy.size();
                            return result;
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
                            _size(::std::move(source._size))
                        {
                        }

                        template <typename Source, typename Alloc>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::coercive_move_constructor_event const& e,
                            Source&& source,
                            Alloc const& alloc
                        ) : _composite_parent_t(e, static_cast<Source&&>(source), alloc),
                            _size(::std::move(source._size))
                        {
                        }

                        template <typename Source>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::move_assignment_event const& e,
                                Source&& source
                            )
                        {
                            bool const result = _composite_parent_t::post_construct(
                                e,
                                static_cast<Source&&>(source)
                            );
                            this->_size = ::std::move(source._size);
                            return result;
                        }

                        template <typename Source, typename Alloc>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::move_assignment_event const& e,
                                Source&& source,
                                Alloc const& alloc
                            )
                        {
                            bool const result = _composite_parent_t::post_construct(
                                e,
                                static_cast<Source&&>(source),
                                alloc
                            );
                            this->_size = ::std::move(source._size);
                            return result;
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
                            typedef IntType size_type;
                        };

                        inline typename traits::size_type const& size() const
                        {
                            return this->_size;
                        }

                    protected:
                        bool listen_to(::odds_and_ends::node::post_insert_event const& e)
                        {
                            bool const result = _composite_parent_t::listen_to(e);
                            this->_post_insert_update_size();
                            return result;
                        }

                        bool
                            listen_to(::odds_and_ends::node::post_insert_left_tree_event const& e)
                        {
                            bool const result = _composite_parent_t::listen_to(e);
                            this->_post_insert_update_size();
                            return result;
                        }

                        bool
                            listen_to(::odds_and_ends::node::post_insert_right_tree_event const& e)
                        {
                            bool const result = _composite_parent_t::listen_to(e);
                            this->_post_insert_update_size();
                            return result;
                        }

                        bool listen_to(::odds_and_ends::node::pre_erase_event const& e)
                        {
                            bool const result = _composite_parent_t::listen_to(e);

                            for (
                                typename traits::pointer p = this->parent();
                                p;
                                p = p->parent()
                            )
                            {
                                p->_size -= this->size();
                            }

                            return result;
                        }

                        bool listen_to(::odds_and_ends::node::post_erase_event const& e)
                        {
                            return _composite_parent_t::listen_to(e);
                        }

                        bool listen_to(::odds_and_ends::node::post_erase_left_tree_event const& e)
                        {
                            return _composite_parent_t::listen_to(e);
                        }

                        bool listen_to(::odds_and_ends::node::post_erase_right_tree_event const& e)
                        {
                            return _composite_parent_t::listen_to(e);
                        }

                        inline bool
                            listen_to(::odds_and_ends::node::post_rotate_left_tree_event const& e)
                        {
                            bool const result = _composite_parent_t::listen_to(e);
                            this->_post_rotate_update_size();
                            return result;
                        }

                        inline bool
                            listen_to(::odds_and_ends::node::post_rotate_right_tree_event const& e)
                        {
                            bool const result = _composite_parent_t::listen_to(e);
                            this->_post_rotate_update_size();
                            return result;
                        }

                        ODDS_AND_ENDS__COMPOSITE_TYPE__NONCOPYABLE_NONMOVABLE_BODY(_result)

                    private:
                        inline void _post_insert_update_size()
                        {
                            typename traits::child_iterator itr;

                            for (
                                typename traits::pointer p = (
                                    ::std::pointer_traits<typename traits::pointer>::pointer_to(
                                        this->derived()
                                    )
                                );
                                p;
                                p = p->parent()
                            )
                            {
                                p->_size = ::boost::initialized_value;

                                for (itr = p->begin(); itr != p->end(); ++itr)
                                {
                                    p->_size += itr->size();
                                }

                                ++p->_size;
                            }
                        }

                        inline void _post_rotate_update_size()
                        {
                            this->parent()->_size = this->_size;
                            this->_size = (
                                this->left() ? this->left()->size() : ::boost::initialized_value
                            ) + (
                                this->right() ? this->right()->size() : ::boost::initialized_value
                            );
                            ++this->_size;
                        }

                        friend class _result;
                    };

                public:
                    typedef _result type;
                };
            };
        };
    };
}}}  // namespace odds_and_ends::node::tree

#endif  // ODDS_AND_ENDS__NODE__TREE__WITH_SIZE_HPP

