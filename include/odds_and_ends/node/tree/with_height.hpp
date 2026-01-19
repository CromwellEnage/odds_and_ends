// Copyright (C) 2011-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__TREE__WITH_HEIGHT_HPP
#define ODDS_AND_ENDS__NODE__TREE__WITH_HEIGHT_HPP

#include <cstddef>
#include <type_traits>
#include <utility>
#include <memory>
#include <odds_and_ends/node/event/pre_clear.hpp>
#include <odds_and_ends/node/event/pre_erase.hpp>
#include <odds_and_ends/node/event/post_clear.hpp>
#include <odds_and_ends/node/event/post_erase.hpp>
#include <odds_and_ends/node/event/post_erase_left_tree.hpp>
#include <odds_and_ends/node/event/post_erase_right_tree.hpp>
#include <odds_and_ends/node/event/post_insert.hpp>
#include <odds_and_ends/node/event/post_insert_left_tree.hpp>
#include <odds_and_ends/node/event/post_insert_right_tree.hpp>
#include <odds_and_ends/node/event/post_rotate_left_tree.hpp>
#include <odds_and_ends/node/event/post_rotate_right_tree.hpp>
#include <odds_and_ends/composite_type/event/default_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/default_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/allocator_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/variadic_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/variadic_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/arg_pack_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/arg_pack_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/conversion_assignment.hpp>
#include <odds_and_ends/composite_type/event/coercive_copy_constructor.hpp>
#include <odds_and_ends/composite_type/event/copy_assignment.hpp>
#include <odds_and_ends/composite_type/event/copy_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/coercive_move_constructor.hpp>
#include <odds_and_ends/composite_type/event/move_assignment.hpp>
#include <odds_and_ends/composite_type/event/move_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/swap.hpp>
#include <odds_and_ends/composite_type/preprocessor/noncopyable_nonmovable_body.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/utility/value_init.hpp>

namespace odds_and_ends { namespace node { namespace tree {

    template <typename IntType = ::std::size_t>
    struct with_height
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
                        IntType _height;

                    protected:
                        inline explicit _result(
                            ::odds_and_ends::composite_type
                            ::default_constructor_1st_stage_event const& e
                        ) : _composite_parent_t(e), _height(::boost::initialized_value)
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
                            _height(::boost::initialized_value)
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
                            _height(::boost::initialized_value)
                        {
                        }

                        template <typename Arg>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type
                                ::conversion_assignment_event const& e,
                                Arg&& arg
                            )
                        {
                            bool const result = (
                                _composite_parent_t::post_construct(e, ::std::forward<Arg>(arg))
                            );
                            this->_height = ::boost::initialized_value;
                            return result;
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
                            this->_update_height(
                                ::std::is_same<
                                    typename traits::child_iterator::pointer,
                                    typename traits::pointer
                                >()
                            );
                            return result;
                        }

                        template <typename ArgumentPack>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::arg_pack_constructor_1st_stage_event const& e,
                            ArgumentPack const& arg_pack
                        ) : _composite_parent_t(e, arg_pack), _height(::boost::initialized_value)
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

                        template <typename Copy>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::coercive_copy_constructor_event const& e,
                            Copy const& copy
                        ) : _composite_parent_t(e, copy), _height(copy.height())
                        {
                        }

                        template <typename Copy, typename Alloc>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::coercive_copy_constructor_event const& e,
                            Copy const& copy,
                            Alloc const& alloc
                        ) : _composite_parent_t(e, copy, alloc), _height(copy.height())
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
                            this->_height = copy.height();
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
                            this->_height = copy.height();
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
                            _height(::std::move(source._height))
                        {
                        }

                        template <typename Source, typename Alloc>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::coercive_move_constructor_event const& e,
                            Source&& source,
                            Alloc const& alloc
                        ) : _composite_parent_t(e, static_cast<Source&&>(source), alloc),
                            _height(::std::move(source._height))
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
                            this->_height = ::std::move(source._height);
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
                            this->_height = ::std::move(source._height);
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
                            typedef IntType height_type;
                        };

                        inline typename traits::height_type const& height() const
                        {
                            return this->_height;
                        }

                    protected:
                        inline bool listen_to(::odds_and_ends::node::post_insert_event const& e)
                        {
                            bool const result = _composite_parent_t::listen_to(e);
                            this->_update_height(
                                ::std::is_same<
                                    typename traits::child_iterator::pointer,
                                    typename traits::pointer
                                >()
                            );
                            return result;
                        }

                        inline bool
                            listen_to(::odds_and_ends::node::post_insert_left_tree_event const& e)
                        {
                            bool const result = _composite_parent_t::listen_to(e);
                            this->_update_height(
                                ::std::is_same<
                                    typename traits::child_iterator::pointer,
                                    typename traits::pointer
                                >()
                            );
                            return result;
                        }

                        inline bool
                            listen_to(::odds_and_ends::node::post_insert_right_tree_event const& e)
                        {
                            bool const result = _composite_parent_t::listen_to(e);
                            this->_update_height(
                                ::std::is_same<
                                    typename traits::child_iterator::pointer,
                                    typename traits::pointer
                                >()
                            );
                            return result;
                        }

                        inline bool listen_to(::odds_and_ends::node::pre_clear_event const& e)
                        {
                            return _composite_parent_t::listen_to(e);
                        }

                        inline bool listen_to(::odds_and_ends::node::pre_erase_event const& e)
                        {
                            return _composite_parent_t::listen_to(e);
                        }

                        inline bool listen_to(::odds_and_ends::node::post_clear_event const& e)
                        {
                            bool const result = _composite_parent_t::listen_to(e);
                            this->_update_height(
                                ::std::is_same<
                                    typename traits::child_iterator::pointer,
                                    typename traits::pointer
                                >()
                            );
                            return result;
                        }

                        inline bool listen_to(::odds_and_ends::node::post_erase_event const& e)
                        {
                            bool const result = _composite_parent_t::listen_to(e);
                            this->_update_height(
                                ::std::is_same<
                                    typename traits::child_iterator::pointer,
                                    typename traits::pointer
                                >()
                            );
                            return result;
                        }

                        inline bool
                            listen_to(::odds_and_ends::node::post_erase_left_tree_event const& e)
                        {
                            bool const result = _composite_parent_t::listen_to(e);
                            this->_update_height(
                                ::std::is_same<
                                    typename traits::child_iterator::pointer,
                                    typename traits::pointer
                                >()
                            );
                            return result;
                        }

                        inline bool
                            listen_to(::odds_and_ends::node::post_erase_right_tree_event const& e)
                        {
                            bool const result = _composite_parent_t::listen_to(e);
                            this->_update_height(
                                ::std::is_same<
                                    typename traits::child_iterator::pointer,
                                    typename traits::pointer
                                >()
                            );
                            return result;
                        }

                        inline bool
                            listen_to(::odds_and_ends::node::post_rotate_left_tree_event const& e)
                        {
                            bool const result = _composite_parent_t::listen_to(e);
                            this->_update_height(
                                ::std::is_same<
                                    typename traits::child_iterator::pointer,
                                    typename traits::pointer
                                >()
                            );
                            return result;
                        }

                        inline bool
                            listen_to(::odds_and_ends::node::post_rotate_right_tree_event const& e)
                        {
                            bool const result = _composite_parent_t::listen_to(e);
                            this->_update_height(
                                ::std::is_same<
                                    typename traits::child_iterator::pointer,
                                    typename traits::pointer
                                >()
                            );
                            return result;
                        }

                        inline bool
                            listen_to(
                                ::odds_and_ends::composite_type::swap_event const& e,
                                Derived& other
                            )
                        {
                            using ::std::swap;
                            bool const result = _composite_parent_t::listen_to(e, other);
                            swap(this->_height, other._height);
                            return result;
                        }

                        ODDS_AND_ENDS__COMPOSITE_TYPE__NONCOPYABLE_NONMOVABLE_BODY(_result)

                    private:
                        static inline IntType _get_height(typename traits::const_pointer p)
                        {
                            return p->height();
                        }

                        void _update_height(::std::false_type)
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
                                p->_height = ::boost::initialized_value;

                                for (itr = p->begin(); itr != p->end(); ++itr)
                                {
                                    if (p->_height < _result::_get_height(itr->second))
                                    {
                                        p->_height = _result::_get_height(itr->second);
                                    }
                                }

                                if (p->begin() != p->end())
                                {
                                    ++p->_height;
                                }
                            }
                        }

                        void _update_height(::std::true_type)
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
                                p->_height = ::boost::initialized_value;

                                for (itr = p->begin(); itr != p->end(); ++itr)
                                {
                                    if (p->_height < itr->height())
                                    {
                                        p->_height = itr->height();
                                    }
                                }

                                if (p->begin() != p->end())
                                {
                                    ++p->_height;
                                }
                            }
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

#endif  // ODDS_AND_ENDS__NODE__TREE__WITH_HEIGHT_HPP

