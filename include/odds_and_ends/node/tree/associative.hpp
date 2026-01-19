// Copyright (C) 2011-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__TREE__ASSOCIATIVE_HPP
#define ODDS_AND_ENDS__NODE__TREE__ASSOCIATIVE_HPP

#include <type_traits>
#include <memory>
#include <utility>
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
#include <odds_and_ends/composite_type/event/conversion_assignment.hpp>
#include <odds_and_ends/composite_type/event/coercive_copy_constructor.hpp>
#include <odds_and_ends/composite_type/event/copy_assignment.hpp>
#include <odds_and_ends/composite_type/event/copy_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/coercive_move_constructor.hpp>
#include <odds_and_ends/composite_type/event/move_assignment.hpp>
#include <odds_and_ends/composite_type/event/move_2nd_stage.hpp>
#include <odds_and_ends/composite_type/event/swap.hpp>
#include <odds_and_ends/composite_type/preprocessor/noncopyable_nonmovable_body.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_hashed_associative_container.hpp>
#include <boost/container/map.hpp>
#include <boost/optional.hpp>
#include <boost/utility/value_init.hpp>
#include <boost/core/enable_if.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/quote.hpp>
#include <boost/assert.hpp>

namespace odds_and_ends { namespace node { namespace tree {

    template <
        typename Key,
        typename ContainerGenerator = typename ::boost::mpl::lambda<
            ::boost::container::map< ::boost::mpl::_1,::boost::mpl::_2>
        >::type,
        typename XForm = ::boost::mpl::quote1< ::std::add_pointer>
    >
    struct associative
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
                    typedef typename ::boost::mpl::apply_wrap1<XForm,Derived>::type _pointer_t;
                    typedef typename ::boost::mpl::apply_wrap2<
                        ContainerGenerator,
                        Key,
                        _pointer_t
                    >::type _children_t;

                    class _result_sorted : public _composite_parent_t
                    {
                        typedef ::boost::optional<Key> _key_store_t;

                        _key_store_t _key;
                        _children_t _children;

                    protected:
                        inline explicit _result_sorted(
                            ::odds_and_ends::composite_type
                            ::default_constructor_1st_stage_event const& e
                        ) : _composite_parent_t(e), _key(), _children()
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
                        inline _result_sorted(
                            ::std::allocator_arg_t const& o,
                            Alloc const& alloc,
                            Args&& ...args
                        ) : _composite_parent_t(o, alloc, ::std::forward<Args>(args)...),
                            _key(),
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
                        inline _result_sorted(
                            ::odds_and_ends::composite_type
                            ::variadic_constructor_1st_stage_event const& e,
                            A0&& a0,
                            Args&& ...args
                        ) : _composite_parent_t(
                                e,
                                ::std::forward<A0>(a0),
                                ::std::forward<Args>(args)...
                            ),
                            _key(),
                            _children()
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
                            return (
                                _composite_parent_t::post_construct(e, ::std::forward<Arg>(arg))
                            );
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
                        inline _result_sorted(
                            ::odds_and_ends::composite_type
                            ::arg_pack_constructor_1st_stage_event const& e,
                            ArgumentPack const& arg_pack
                        ) : _composite_parent_t(e, arg_pack), _key(), _children()
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
                        inline _result_sorted(
                            ::odds_and_ends::composite_type
                            ::coercive_copy_constructor_event const& e,
                            Copy const& copy
                        ) : _composite_parent_t(e, copy), _key(), _children()
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

                        template <typename Copy>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::copy_2nd_stage_event const& e,
                                Copy const& copy
                            )
                        {
                            return _composite_parent_t::post_construct(e, copy);
                        }

                        template <typename Source>
                        inline _result_sorted(
                            ::odds_and_ends::composite_type
                            ::coercive_move_constructor_event const& e,
                            Source&& source
                        ) : _composite_parent_t(e, static_cast<Source&&>(source)),
                            _key(),
                            _children()
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

                    public:
                        inline ~_result_sorted()
                        {
                        }

                        struct traits : _composite_parent_t::traits
                        {
                            typedef typename _children_t::iterator child_iterator;
                            typedef typename _children_t::const_iterator child_const_iterator;
                            typedef typename _children_t::reverse_iterator child_reverse_iterator;
                            typedef typename _children_t
                            ::const_reverse_iterator child_const_reverse_iterator;
                        };

                        inline bool is_leaf() const
                        {
                            return this->_children.empty();
                        }

                        inline Key const& key() const
                        {
                            return *this->_key;
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
                                _result_sorted::_set_parent(
                                    itr->second,
                                    static_cast<typename traits::pointer>(nullptr)
                                );
                            }

                            this->_children.clear();
                            this->handle(::odds_and_ends::node::post_clear_event());
                        }

                        inline typename traits::child_const_iterator cbegin() const
                        {
                            return this->_children.cbegin();
                        }

                        inline typename traits::child_const_iterator begin() const
                        {
                            return this->_children.begin();
                        }

                        inline typename traits::child_iterator begin()
                        {
                            return this->_children.begin();
                        }

                        inline typename traits::child_const_iterator cend() const
                        {
                            return this->_children.cend();
                        }

                        inline typename traits::child_const_iterator end() const
                        {
                            return this->_children.end();
                        }

                        inline typename traits::child_iterator end()
                        {
                            return this->_children.end();
                        }

                        inline typename traits::child_const_reverse_iterator crbegin() const
                        {
                            return this->_children.crbegin();
                        }

                        inline typename traits::child_const_reverse_iterator rbegin() const
                        {
                            return this->_children.rbegin();
                        }

                        inline typename traits::child_reverse_iterator rbegin()
                        {
                            return this->_children.rbegin();
                        }

                        inline typename traits::child_const_reverse_iterator crend() const
                        {
                            return this->_children.crend();
                        }

                        inline typename traits::child_const_reverse_iterator rend() const
                        {
                            return this->_children.rend();
                        }

                        inline typename traits::child_reverse_iterator rend()
                        {
                            return this->_children.rend();
                        }

                        inline typename traits::const_pointer
                            get(typename _children_t::key_type const& key) const
                        {
                            typename _children_t::const_iterator itr = this->_children.find(key);
                            return (itr == this->_children.end()) ? nullptr : itr->second;
                        }

                        template <typename K>
                        inline typename traits::const_pointer get(K const& key) const
                        {
                            typename _children_t::const_iterator itr = this->_children.find(key);
                            return (itr == this->_children.end()) ? nullptr : itr->second;
                        }

                        inline typename traits::pointer
                            get(typename _children_t::key_type const& key)
                        {
                            typename _children_t::iterator itr = this->_children.find(key);
                            return (itr == this->_children.end()) ? nullptr : itr->second;
                        }

                        template <typename K>
                        inline typename traits::pointer get(K const& key)
                        {
                            typename _children_t::iterator itr = this->_children.find(key);
                            return (itr == this->_children.end()) ? nullptr : itr->second;
                        }

                        inline bool unset(typename _children_t::key_type const& key)
                        {
                            typename _children_t::iterator itr = this->_children.find(key);

                            if (itr == this->_children.end())
                            {
                                return false;
                            }
                            else
                            {
                                BOOST_ASSERT(!!itr->second);
                                _result_sorted::_pre_erase(itr->second);
                                this->_children.erase(itr);
                                this->handle(::odds_and_ends::node::post_erase_event());
                                return true;
                            }
                        }

                        inline void
                            set_ptr(
                                typename _children_t::key_type const& key,
                                typename traits::pointer p
                            )
                        {
                            BOOST_ASSERT(!!p);

                            typename _children_t::iterator itr = this->_children.find(key);

                            if (itr == this->_children.end())
                            {
                                this->_children.emplace(key, p);
                            }
                            else
                            {
                                BOOST_ASSERT(!!itr->second);
                                _result_sorted::_pre_erase(itr->second);
                                itr->second = nullptr;
                                this->handle(::odds_and_ends::node::post_erase_event());
                                itr->second = p;
                            }

                            p->_key = key;
                            p->parent(
                                ::std::pointer_traits<typename traits::pointer>::pointer_to(
                                    this->derived()
                                )
                            );
                            this->handle(::odds_and_ends::node::post_insert_event());
                        }

                        inline void
                            set(
                                typename _children_t::key_type const& key,
                                Derived& d
                            )
                        {
                            this->set_ptr(
                                key,
                                ::std::pointer_traits<typename traits::pointer>::pointer_to(d)
                            );
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
                                    other.parent()->_children.find(
                                        other.key()
                                    )->second = ::std::pointer_traits<
                                        typename traits::pointer
                                    >::pointer_to(this->derived());
                                }

                                for (
                                    typename _children_t::iterator itr = this->_children.begin();
                                    itr != this->_children.end();
                                    ++itr
                                )
                                {
                                    _result_sorted::_set_parent(
                                        itr->second,
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
                                    if (
                                        itr->second == ::std::pointer_traits<
                                            typename traits::pointer
                                        >::pointer_to(this->derived())
                                    )
                                    {
                                        itr->second = ::std::pointer_traits<
                                            typename traits::pointer
                                        >::pointer_to(other);
                                    }
                                    else
                                    {
                                        _result_sorted::_set_parent(
                                            itr->second,
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
                                    this->parent()->_children.find(
                                        this->key()
                                    )->second = ::std::pointer_traits<
                                        typename traits::pointer
                                    >::pointer_to(other);
                                }

                                for (
                                    typename _children_t::iterator itr = other._children.begin();
                                    itr != other._children.end();
                                    ++itr
                                )
                                {
                                    _result_sorted::_set_parent(
                                        itr->second,
                                        ::std::pointer_traits<
                                            typename traits::pointer
                                        >::pointer_to(this->derived())
                                    );
                                }

                                for (
                                    typename _children_t::iterator itr = this->_children.begin();
                                    itr != this->_children.end();
                                    ++itr
                                )
                                {
                                    if (
                                        itr->second == ::std::pointer_traits<
                                            typename traits::pointer
                                        >::pointer_to(other)
                                    )
                                    {
                                        itr->second = ::std::pointer_traits<
                                            typename traits::pointer
                                        >::pointer_to(this->derived());
                                    }
                                    else
                                    {
                                        _result_sorted::_set_parent(
                                            itr->second,
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
                            else  // if neither node is a parent/child of the other
                            {
                                if (this->parent())
                                {
                                    this->parent()->_children.find(
                                        this->key()
                                    )->second = ::std::pointer_traits<
                                        typename traits::pointer
                                    >::pointer_to(other);
                                }

                                if (other.parent())
                                {
                                    other.parent()->_children.find(
                                        other.key()
                                    )->second = ::std::pointer_traits<
                                        typename traits::pointer
                                    >::pointer_to(this->derived());
                                }

                                for (
                                    typename _children_t::iterator itr = this->_children.begin();
                                    itr != this->_children.end();
                                    ++itr
                                )
                                {
                                    _result_sorted::_set_parent(
                                        itr->second,
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
                                    _result_sorted::_set_parent(
                                        itr->second,
                                        ::std::pointer_traits<
                                            typename traits::pointer
                                        >::pointer_to(this->derived())
                                    );
                                }

                                typename traits::pointer p = this->parent();

                                this->parent(other.parent());
                                other.parent(p);
                            }

                            swap(this->_key, other._key);
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
                        static inline void _pre_erase(typename traits::pointer p)
                        {
                            p->handle(::odds_and_ends::node::pre_erase_event());
                            p->parent(nullptr);
                            p->_key = _key_store_t();
                        }

                        static inline void
                            _set_parent(typename traits::pointer c, typename traits::pointer p)
                        {
                            c->parent(p);

                            if (!p)
                            {
                                c->_key = _key_store_t();
                            }
                        }

                        ODDS_AND_ENDS__COMPOSITE_TYPE__NONCOPYABLE_NONMOVABLE_BODY(
                            _result_sorted
                        )
                        friend class _result_sorted;
                    };

                    class _result_hashed : public _composite_parent_t
                    {
                        typedef ::boost::optional<Key> _key_store_t;

                        _key_store_t _key;
                        _children_t _children;

                    protected:
                        inline explicit _result_hashed(
                            ::odds_and_ends::composite_type
                            ::default_constructor_1st_stage_event const& e
                        ) : _composite_parent_t(e), _key(), _children()
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
                        inline _result_hashed(
                            ::std::allocator_arg_t const& o,
                            Alloc const& alloc,
                            Args&& ...args
                        ) : _composite_parent_t(o, alloc, ::std::forward<Args>(args)...),
                            _key(),
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
                        inline _result_hashed(
                            ::odds_and_ends::composite_type
                            ::variadic_constructor_1st_stage_event const& e,
                            A0&& a0,
                            Args&& ...args
                        ) : _composite_parent_t(
                                e,
                                ::std::forward<A0>(a0),
                                ::std::forward<Args>(args)...
                            ),
                            _key(),
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
                        inline _result_hashed(
                            ::odds_and_ends::composite_type
                            ::arg_pack_constructor_1st_stage_event const& e,
                            ArgumentPack const& arg_pack
                        ) : _composite_parent_t(e, arg_pack), _key(), _children()
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
                        inline _result_hashed(
                            ::odds_and_ends::composite_type
                            ::coercive_copy_constructor_event const& e,
                            Copy const& copy
                        ) : _composite_parent_t(e, copy), _key(), _children()
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

                        template <typename Copy>
                        inline bool
                            post_construct(
                                ::odds_and_ends::composite_type::copy_2nd_stage_event const& e,
                                Copy const& copy
                            )
                        {
                            return _composite_parent_t::post_construct(e, copy);
                        }

                        template <typename Source>
                        inline _result_hashed(
                            ::odds_and_ends::composite_type
                            ::coercive_move_constructor_event const& e,
                            Source&& source
                        ) : _composite_parent_t(e, static_cast<Source&&>(source)),
                            _key(),
                            _children()
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

                    public:
                        inline ~_result_hashed()
                        {
                        }

                        struct traits : _composite_parent_t::traits
                        {
                            typedef typename _children_t::iterator child_iterator;
                            typedef typename _children_t::const_iterator child_const_iterator;
                            typedef typename _children_t::local_iterator child_local_iterator;
                            typedef typename _children_t
                            ::const_local_iterator child_const_local_iterator;
                        };

                        inline bool is_leaf() const
                        {
                            return this->_children.empty();
                        }

                        inline Key const& key() const
                        {
                            return *this->_key;
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
                                _result_hashed::_set_parent(
                                    itr->second,
                                    static_cast<typename traits::pointer>(nullptr)
                                );
                            }

                            this->_children.clear();
                            this->handle(::odds_and_ends::node::post_clear_event());
                        }

                        inline typename traits::child_const_iterator cbegin() const
                        {
                            return this->_children.cbegin();
                        }

                        inline typename traits::child_const_iterator begin() const
                        {
                            return this->_children.begin();
                        }

                        inline typename traits::child_iterator begin()
                        {
                            return this->_children.begin();
                        }

                        inline typename traits::child_const_iterator cend() const
                        {
                            return this->_children.cend();
                        }

                        inline typename traits::child_const_iterator end() const
                        {
                            return this->_children.end();
                        }

                        inline typename traits::child_iterator end()
                        {
                            return this->_children.end();
                        }

                        inline typename _children_t::size_type bucket_count() const
                        {
                            return this->_children.bucket_count();
                        }

                        inline typename _children_t::size_type bucket(Key const& key) const
                        {
                            return this->_children.bucket(key);
                        }

                        template <typename K>
                        inline typename _children_t::size_type bucket(K const& key) const
                        {
                            return this->_children.bucket(key);
                        }

                        inline typename _children_t::size_type
                            bucket_size(typename _children_t::size_type bucket) const
                        {
                            return this->_children.bucket_size(bucket);
                        }

                        inline typename traits::child_const_local_iterator
                            cbegin(typename _children_t::size_type bucket) const
                        {
                            return this->_children.cbegin(bucket);
                        }

                        inline typename traits::child_const_local_iterator
                            begin(typename _children_t::size_type bucket) const
                        {
                            return this->_children.begin(bucket);
                        }

                        inline typename traits::child_local_iterator
                            begin(typename _children_t::size_type bucket)
                        {
                            return this->_children.begin(bucket);
                        }

                        inline typename traits::child_const_local_iterator
                            cend(typename _children_t::size_type bucket) const
                        {
                            return this->_children.cend(bucket);
                        }

                        inline typename traits::child_const_local_iterator
                            end(typename _children_t::size_type bucket) const
                        {
                            return this->_children.end(bucket);
                        }

                        inline typename traits::child_local_iterator
                            end(typename _children_t::size_type bucket)
                        {
                            return this->_children.end(bucket);
                        }

                        inline typename traits::const_pointer
                            get(typename _children_t::key_type const& key) const
                        {
                            typename _children_t::const_iterator itr = this->_children.find(key);
                            return (itr == this->_children.end()) ? nullptr : itr->second;
                        }

                        template <typename K>
                        inline typename traits::const_pointer get(K const& key) const
                        {
                            typename _children_t::const_iterator itr = this->_children.find(key);
                            return (itr == this->_children.end()) ? nullptr : itr->second;
                        }

                        inline typename traits::pointer
                            get(typename _children_t::key_type const& key)
                        {
                            typename _children_t::iterator itr = this->_children.find(key);
                            return (itr == this->_children.end()) ? nullptr : itr->second;
                        }

                        template <typename K>
                        inline typename traits::pointer get(K const& key)
                        {
                            typename _children_t::iterator itr = this->_children.find(key);
                            return (itr == this->_children.end()) ? nullptr : itr->second;
                        }

                        inline bool unset(typename _children_t::key_type const& key)
                        {
                            typename _children_t::iterator itr = this->_children.find(key);

                            if (itr == this->_children.end())
                            {
                                return false;
                            }
                            else
                            {
                                BOOST_ASSERT(!!itr->second);
                                _result_hashed::_pre_erase(itr->second);
                                this->_children.erase(itr);
                                this->handle(::odds_and_ends::node::post_erase_event());
                                return true;
                            }
                        }

                        inline void
                            set_ptr(
                                typename _children_t::key_type const& key,
                                typename traits::pointer p
                            )
                        {
                            BOOST_ASSERT(!!p);

                            typename _children_t::iterator itr = this->_children.find(key);

                            if (itr == this->_children.end())
                            {
                                this->_children.emplace(key, p);
                            }
                            else
                            {
                                BOOST_ASSERT(!!itr->second);
                                _result_hashed::_pre_erase(itr->second);
                                itr->second = nullptr;
                                this->handle(::odds_and_ends::node::post_erase_event());
                                itr->second = p;
                            }

                            p->_key = key;
                            p->parent(
                                ::std::pointer_traits<typename traits::pointer>::pointer_to(
                                    this->derived()
                                )
                            );
                            this->handle(::odds_and_ends::node::post_insert_event());
                        }

                        inline void set(typename _children_t::key_type const& key, Derived& d)
                        {
                            this->set_ptr(
                                key,
                                ::std::pointer_traits<typename traits::pointer>::pointer_to(d)
                            );
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
                                    other.parent()->_children.find(
                                        other.key()
                                    )->second = ::std::pointer_traits<
                                        typename traits::pointer
                                    >::pointer_to(this->derived());
                                }

                                for (
                                    typename _children_t::iterator itr = this->_children.begin();
                                    itr != this->_children.end();
                                    ++itr
                                )
                                {
                                    _result_hashed::_set_parent(
                                        itr->second,
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
                                    if (
                                        itr->second == ::std::pointer_traits<
                                            typename traits::pointer
                                        >::pointer_to(this->derived())
                                    )
                                    {
                                        itr->second = ::std::pointer_traits<
                                            typename traits::pointer
                                        >::pointer_to(other);
                                    }
                                    else
                                    {
                                        _result_hashed::_set_parent(
                                            itr->second,
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
                                    this->parent()->_children.find(
                                        this->key()
                                    )->second = ::std::pointer_traits<
                                        typename traits::pointer
                                    >::pointer_to(other);
                                }

                                for (
                                    typename _children_t::iterator itr = other._children.begin();
                                    itr != other._children.end();
                                    ++itr
                                )
                                {
                                    _result_hashed::_set_parent(
                                        itr->second,
                                        ::std::pointer_traits<
                                            typename traits::pointer
                                        >::pointer_to(this->derived())
                                    );
                                }

                                for (
                                    typename _children_t::iterator itr = this->_children.begin();
                                    itr != this->_children.end();
                                    ++itr
                                )
                                {
                                    if (
                                        itr->second == ::std::pointer_traits<
                                            typename traits::pointer
                                        >::pointer_to(other)
                                    )
                                    {
                                        itr->second = ::std::pointer_traits<
                                            typename traits::pointer
                                        >::pointer_to(this->derived());
                                    }
                                    else
                                    {
                                        _result_hashed::_set_parent(
                                            itr->second,
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
                            else  // if neither node is a parent/child of the other
                            {
                                if (this->parent())
                                {
                                    this->parent()->_children.find(
                                        this->key()
                                    )->second = ::std::pointer_traits<
                                        typename traits::pointer
                                    >::pointer_to(other);
                                }

                                if (other.parent())
                                {
                                    other.parent()->_children.find(
                                        other.key()
                                    )->second = ::std::pointer_traits<
                                        typename traits::pointer
                                    >::pointer_to(this->derived());
                                }

                                for (
                                    typename _children_t::iterator itr = this->_children.begin();
                                    itr != this->_children.end();
                                    ++itr
                                )
                                {
                                    _result_hashed::_set_parent(
                                        itr->second,
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
                                    _result_hashed::_set_parent(
                                        itr->second,
                                        ::std::pointer_traits<
                                            typename traits::pointer
                                        >::pointer_to(this->derived())
                                    );
                                }

                                typename traits::pointer p = this->parent();

                                this->parent(other.parent());
                                other.parent(p);
                            }

                            swap(this->_key, other._key);
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
                        static inline void _pre_erase(typename traits::pointer p)
                        {
                            p->handle(::odds_and_ends::node::pre_erase_event());
                            p->parent(nullptr);
                            p->_key = _key_store_t();
                        }

                        static inline void
                            _set_parent(typename traits::pointer c, typename traits::pointer p)
                        {
                            c->parent(p);

                            if (!p)
                            {
                                c->_key = _key_store_t();
                            }
                        }

                        ODDS_AND_ENDS__COMPOSITE_TYPE__NONCOPYABLE_NONMOVABLE_BODY(_result_hashed)
                        friend class _result_hashed;
                    };

                public:
                    typedef typename ::boost::mpl::if_<
                        ::odds_and_ends::static_introspection::concept
                        ::is_legacy_hashed_associative_container<_children_t>,
                        _result_hashed,
                        _result_sorted
                    >::type type;
                };
            };
        };
    };
}}}  // namespace odds_and_ends::node::tree

#endif  // ODDS_AND_ENDS__NODE__TREE__ASSOCIATIVE_HPP

