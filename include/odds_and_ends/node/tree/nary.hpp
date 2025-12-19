// Copyright (C) 2011-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__TREE__NARY_HPP
#define ODDS_AND_ENDS__NODE__TREE__NARY_HPP

#include <type_traits>
#include <memory>
#include <utility>
#include <odds_and_ends/node/iterator/indirect.hpp>
#include <odds_and_ends/node/event/pre_clear.hpp>
#include <odds_and_ends/node/event/pre_erase.hpp>
#include <odds_and_ends/node/event/post_clear.hpp>
#include <odds_and_ends/node/event/post_erase.hpp>
#include <odds_and_ends/node/event/post_insert.hpp>
#include <odds_and_ends/composite_type/event/default_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/variadic_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/variadic_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/arg_pack_ctor_1st_stage.hpp>
#include <odds_and_ends/composite_type/event/arg_pack_ctor_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/coercive_copy_constructor.hpp>
#include <odds_and_ends/composite_type/event/copy_assignment.hpp>
#include <odds_and_ends/composite_type/event/copy_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/coercive_move_constructor.hpp>
#include <odds_and_ends/composite_type/event/move_assignment.hpp>
#include <odds_and_ends/composite_type/event/move_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/swap.hpp>
#include <odds_and_ends/composite_type/preprocessor/noncopyable_nonmovable_body.hpp>
#include <boost/utility/value_init.hpp>
#include <boost/core/enable_if.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/quote.hpp>

namespace odds_and_ends { namespace node { namespace tree {

    template <
        typename ContainerGenerator,
        typename XForm = ::boost::mpl::quote1< ::std::add_pointer>
    >
    struct nary
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
                    typedef typename ::boost::mpl::apply_wrap1<
                        ContainerGenerator,
                        typename ::boost::mpl::apply_wrap1<XForm,Derived>::type
                    >::type _children_t;

                    class _result : public _composite_parent_t
                    {
                        _children_t _children;

                    protected:
                        inline explicit _result(
                            ::odds_and_ends::composite_type
                            ::default_constructor_1st_stage_event const& e
                        ) : _composite_parent_t(e), _children()
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
                            _children(alloc)
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
                            _children()
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
                        ) : _composite_parent_t(e, arg_pack), _children()
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
                        ) : _composite_parent_t(e, copy), _children()
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
                            return result;
                        }

                        template <typename Copy>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::copy_2nd_stage_event const& e,
                                Copy const& copy
                            )
                        {
                            bool const result = _composite_parent_t::post_construct(e, copy);
                            return result;
                        }

                        template <typename Source>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::coercive_move_constructor_event const& e,
                            Source&& source
                        ) : _composite_parent_t(e, static_cast<Source&&>(source)), _children()
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
                            return result;
                        }

                        template <typename Source>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::move_2nd_stage_event const& e,
                                Source&& source
                            )
                        {
                            bool const result = _composite_parent_t::post_construct(
                                e,
                                static_cast<Source&&>(source)
                            );
                            return result;
                        }

                    public:
                        inline ~_result()
                        {
                        }

                        struct traits : _composite_parent_t::traits
                        {
                            typedef ::odds_and_ends::node::indirect_iterator<
                                typename _children_t::iterator,
                                XForm
                            > child_iterator;
                            typedef ::odds_and_ends::node::indirect_iterator<
                                typename _children_t::const_iterator,
                                XForm
                            > child_const_iterator;
                            typedef ::odds_and_ends::node::indirect_iterator<
                                typename _children_t::reverse_iterator,
                                XForm
                            > child_reverse_iterator;
                            typedef ::odds_and_ends::node::indirect_iterator<
                                typename _children_t::const_reverse_iterator,
                                XForm
                            > child_const_reverse_iterator;
                        };

                        inline bool is_leaf()
                        {
                            return this->_children.empty();
                        }

                        inline typename traits::child_const_iterator cbegin() const
                        {
                            return typename traits::child_const_iterator(this->_children.cbegin());
                        }

                        inline typename traits::child_const_iterator begin() const
                        {
                            return typename traits::child_const_iterator(this->_children.begin());
                        }

                        inline typename traits::child_iterator begin()
                        {
                            return typename traits::child_iterator(this->_children.begin());
                        }

                        inline typename traits::child_const_iterator cend() const
                        {
                            return typename traits::child_const_iterator(this->_children.cend());
                        }

                        inline typename traits::child_const_iterator end() const
                        {
                            return typename traits::child_const_iterator(this->_children.end());
                        }

                        inline typename traits::child_iterator end()
                        {
                            return typename traits::child_iterator(this->_children.end());
                        }

                        inline typename traits::child_const_reverse_iterator crbegin() const
                        {
                            return typename traits::child_const_reverse_iterator(
                                this->_children.crbegin()
                            );
                        }

                        inline typename traits::child_const_reverse_iterator rbegin() const
                        {
                            return typename traits::child_const_reverse_iterator(
                                this->_children.rbegin()
                            );
                        }

                        inline typename traits::child_reverse_iterator rbegin()
                        {
                            return typename traits::child_reverse_iterator(
                                this->_children.rbegin()
                            );
                        }

                        inline typename traits::child_const_reverse_iterator crend() const
                        {
                            return typename traits::child_const_reverse_iterator(
                                this->_children.crend()
                            );
                        }

                        inline typename traits::child_const_reverse_iterator rend() const
                        {
                            return typename traits::child_const_reverse_iterator(
                                this->_children.rend()
                            );
                        }

                        inline typename traits::child_reverse_iterator rend()
                        {
                            return typename traits::child_reverse_iterator(this->_children.rend());
                        }

                        inline void push_front(typename traits::pointer p)
                        {
                            this->_children.push_front(p);
                            p->parent(
                                ::std::pointer_traits<typename traits::pointer>::pointer_to(
                                    this->derived()
                                )
                            );
                            this->handle(::odds_and_ends::node::post_insert_event());
                        }

                        inline void push_back(typename traits::pointer p)
                        {
                            this->_children.push_back(p);
                            p->parent(
                                ::std::pointer_traits<typename traits::pointer>::pointer_to(
                                    this->derived()
                                )
                            );
                            this->handle(::odds_and_ends::node::post_insert_event());
                        }

                        inline typename traits::child_iterator
                            insert(
                                typename traits::child_const_iterator pos,
                                typename traits::pointer p
                            )
                        {
                            typename _children_t::iterator itr = (
                                this->_children.insert(pos.base(), p)
                            );
                            p->parent(
                                ::std::pointer_traits<typename traits::pointer>::pointer_to(
                                    this->derived()
                                )
                            );
                            this->handle(::odds_and_ends::node::post_insert_event());
                            return typename traits::child_iterator(itr);
                        }

                        inline void pop_front()
                        {
                            _result::_pre_erase(this->_children.front());
                            this->_children.pop_front();
                            this->handle(::odds_and_ends::node::post_erase_event());
                        }

                        inline void pop_back()
                        {
                            _result::_pre_erase(this->_children.back());
                            this->_children.pop_back();
                            this->handle(::odds_and_ends::node::post_erase_event());
                        }

                        inline typename traits::child_iterator
                            erase(typename traits::child_const_iterator pos)
                        {
                            _result::_pre_erase(
                                const_cast<typename traits::pointer>(*pos.base())
                            );
                            typename _children_t::iterator itr = this->_children.erase(pos.base());
                            this->handle(::odds_and_ends::node::post_erase_event());
                            return itr;
                        }

                        void clear()
                        {
                            this->handle(::odds_and_ends::node::pre_clear_event());

                            for (
                                typename _children_t::iterator itr = this->_children.begin();
                                itr != this->_children.end();
                                ++itr
                            )
                            {
                                (*itr)->parent(nullptr);
                            }

                            this->_children.clear();
                            this->handle(::odds_and_ends::node::post_clear_event());
                        }

                    protected:
                        bool
                            listen_to(
                                ::odds_and_ends::composite_type::swap_event const& e,
                                Derived& other
                            )
                        {
                            using ::std::swap;
                            bool const result = _composite_parent_t::listen_to(e, other);

                            if (
                                ::std::pointer_traits<typename traits::pointer>::pointer_to(
                                    other
                                ) == this->parent()
                            )
                            {
                                if (other.parent())
                                {
                                    for (
                                        typename _children_t::size_type i = (
                                            ::boost::initialized_value
                                        );
                                        i < other.parent()->_children.size();
                                        ++i
                                    )
                                    {
                                        if (
                                            other.parent()->_children[i] == ::std::pointer_traits<
                                                typename traits::pointer
                                            >::pointer_to(other)
                                        )
                                        {
                                            other.parent()->_children[i] = ::std::pointer_traits<
                                                typename traits::pointer
                                            >::pointer_to(this->derived());
                                        }
                                    }
                                }

                                for (
                                    typename _children_t::iterator itr = this->_children.begin();
                                    itr != this->_children.end();
                                    ++itr
                                )
                                {
                                    (*itr)->parent(
                                        ::std::pointer_traits<
                                            typename traits::pointer
                                        >::pointer_to(other.parent())
                                    );
                                }

                                for (
                                    typename _children_t::size_type i = ::boost::initialized_value;
                                    i < other._children.size();
                                    ++i
                                )
                                {
                                    if (
                                        other._children[i] == ::std::pointer_traits<
                                            typename traits::pointer
                                        >::pointer_to(this->derived())
                                    )
                                    {
                                        other._children[i] = ::std::pointer_traits<
                                            typename traits::pointer
                                        >::pointer_to(other);
                                    }
                                    else
                                    {
                                        other._children[i]->parent(
                                            ::std::pointer_traits<
                                                typename traits::pointer
                                            >::pointer_to(this->derived())
                                        );
                                    }
                                }

                                this->parent(other.parent());
                                other.parent(
                                    ::std::pointer_traits<
                                        typename traits::pointer
                                    >::pointer_to(this->derived())
                                );
                            }
                            else if (
                                ::std::pointer_traits<typename traits::pointer>::pointer_to(
                                    this->derived()
                                ) == other.parent()
                            )
                            {
                                if (this->parent())
                                {
                                    for (
                                        typename _children_t::size_type i = (
                                            ::boost::initialized_value
                                        );
                                        i < this->parent()->_children.size();
                                        ++i
                                    )
                                    {
                                        if (
                                            this->parent()->_children[i] == ::std::pointer_traits<
                                                typename traits::pointer
                                            >::pointer_to(this->derived())
                                        )
                                        {
                                            this->parent()->_children[i] = ::std::pointer_traits<
                                                typename traits::pointer
                                            >::pointer_to(other);
                                        }
                                    }
                                }

                                for (
                                    typename _children_t::iterator itr = other._children.begin();
                                    itr != other._children.end();
                                    ++itr
                                )
                                {
                                    (*itr)->parent(
                                        ::std::pointer_traits<
                                            typename traits::pointer
                                        >::pointer_to(this->derived().parent())
                                    );
                                }

                                for (
                                    typename _children_t::size_type i = ::boost::initialized_value;
                                    i < this->_children.size();
                                    ++i
                                )
                                {
                                    if (
                                        this->_children[i] == ::std::pointer_traits<
                                            typename traits::pointer
                                        >::pointer_to(other)
                                    )
                                    {
                                        this->_children[i] = ::std::pointer_traits<
                                            typename traits::pointer
                                        >::pointer_to(this->derived());
                                    }
                                    else
                                    {
                                        this->_children[i]->parent(
                                            ::std::pointer_traits<
                                                typename traits::pointer
                                            >::pointer_to(other)
                                        );
                                    }
                                }

                                other.parent(this->parent());
                                this->parent(
                                    ::std::pointer_traits<
                                        typename traits::pointer
                                    >::pointer_to(other)
                                );
                            }
                            else
                            {
                                if (this->parent())
                                {
                                    for (
                                        typename _children_t::size_type i = (
                                            ::boost::initialized_value
                                        );
                                        i < this->parent()->_children.size();
                                        ++i
                                    )
                                    {
                                        if (
                                            this->parent()->_children[i] == ::std::pointer_traits<
                                                typename traits::pointer
                                            >::pointer_to(this->derived())
                                        )
                                        {
                                            this->parent()->_children[i] = ::std::pointer_traits<
                                                typename traits::pointer
                                            >::pointer_to(other);
                                        }
                                    }
                                }

                                if (other.parent())
                                {
                                    for (
                                        typename _children_t::size_type i = (
                                            ::boost::initialized_value
                                        );
                                        i < other.parent()->_children.size();
                                        ++i
                                    )
                                    {
                                        if (
                                            other.parent()->_children[i] == ::std::pointer_traits<
                                                typename traits::pointer
                                            >::pointer_to(other)
                                        )
                                        {
                                            other.parent()->_children[i] = ::std::pointer_traits<
                                                typename traits::pointer
                                            >::pointer_to(this->derived());
                                        }
                                    }
                                }

                                for (
                                    typename _children_t::iterator itr = this->_children.begin();
                                    itr != this->_children.end();
                                    ++itr
                                )
                                {
                                    (*itr)->parent(
                                        ::std::pointer_traits<
                                            typename traits::pointer
                                        >::pointer_to(other)
                                    );
                                }

                                for (
                                    typename _children_t::iterator itr = other._children.begin();
                                    itr != other._children.end();
                                    ++itr
                                )
                                {
                                    (*itr)->parent(
                                        ::std::pointer_traits<
                                            typename traits::pointer
                                        >::pointer_to(this->derived())
                                    );
                                }

                                typename traits::pointer p = this->parent();

                                this->parent(other.parent());
                                other.parent(p);
                            }

                            swap(this->_children, other._children);
                            return result;
                        }

                        template <typename Event, typename ...Args>
                        inline typename ::boost::disable_if<
                            ::std::is_same<Event,::odds_and_ends::composite_type::swap_event>,
                            bool
                        >::type
                            listen_to(Event const& e, Args&&... args)
                        {
                            return (
                                _composite_parent_t::listen_to(e, ::std::forward<Args>(args)...)
                            );
                        }

                    private:
                        template <typename Ptr>
                        inline static void _pre_erase(Ptr ptr)
                        {
                            ptr->handle(::odds_and_ends::node::pre_erase_event());
                            ptr->parent(nullptr);
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

#endif  // ODDS_AND_ENDS__NODE__TREE__NARY_HPP

