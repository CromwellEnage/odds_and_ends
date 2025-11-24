// Copyright (C) 2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__LINKED__BASE_HPP
#define ODDS_AND_ENDS__NODE__LINKED__BASE_HPP

#include <type_traits>
#include <utility>
#include <memory>
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
#include <boost/mpl/quote.hpp>

namespace odds_and_ends { namespace node { namespace linked {

    template <typename XForm = ::boost::mpl::quote1< ::std::add_pointer> >
    struct base
    {
        template <typename CompositeParentGenerator>
        struct apply
        {
            struct type
            {
                template <typename Derived>
                class apply
                {
                    typedef typename ::boost::mpl::apply_wrap1<XForm,Derived>::type _ptr_t;
                    typedef typename ::boost::mpl::apply_wrap1<XForm,Derived const>::type _ptr_c_t;
                    typedef typename ::boost::mpl::apply_wrap1<
                        CompositeParentGenerator,
                        Derived
                    >::type _composite_parent_t;

                    class _result : public _composite_parent_t
                    {
                        _ptr_t _next;

                    protected:
                        inline explicit _result(
                            ::odds_and_ends::composite_type
                            ::default_constructor_1st_stage_event const& e
                        ) : _composite_parent_t(e), _next(nullptr)
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
                            _next(nullptr)
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
                            _next(nullptr)
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
                        ) : _composite_parent_t(e, arg_pack), _next(nullptr)
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
                        ) : _composite_parent_t(e, arg), _next(nullptr)
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
                        ) : _composite_parent_t(e, copy), _next(nullptr)
                        {
                        }

                        template <typename Copy, typename Alloc>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::coercive_copy_constructor_event const& e,
                            Copy const& copy,
                            Alloc const& alloc
                        ) : _composite_parent_t(e, copy, alloc), _next(nullptr)
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
                        ) : _composite_parent_t(e, static_cast<Source&&>(source)), _next(nullptr)
                        {
                        }

                        template <typename Source, typename Alloc>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::coercive_move_constructor_event const& e,
                            Source&& source,
                            Alloc const& alloc
                        ) : _composite_parent_t(e, static_cast<Source&&>(source), alloc),
                            _next(nullptr)
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
                            typedef _ptr_c_t const_pointer;
                            typedef _ptr_t pointer;
                        };

                        inline typename traits::const_pointer next() const
                        {
                            return this->_next;
                        }

                        inline typename traits::pointer next()
                        {
                            return this->_next;
                        }

                        inline void insert_next(typename traits::pointer p)
                        {
                            if (this->_next)
                            {
                                p->_next = this->_next;
                            }

                            this->_next = p;
                        }

                        inline typename traits::pointer erase_next()
                        {
                            typename traits::pointer p = this->_next;

                            this->_next = this->_next->_next;
                            p->_next = nullptr;
                            return p;
                        }

                    protected:
                        inline void _set_next(typename traits::pointer p)
                        {
                            this->_next = p;
                        }

                        ODDS_AND_ENDS__COMPOSITE_TYPE__NONCOPYABLE_NONMOVABLE_BODY(_result)
                    };

                public:
                    typedef _result type;
                };
            };
        };
    };
}}}  // namespace odds_and_ends::node::linked

#endif  // ODDS_AND_ENDS__NODE__LINKED__BASE_HPP

