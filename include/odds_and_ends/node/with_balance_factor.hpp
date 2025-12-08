// Copyright (C) 2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__WITH_BALANCE_FACTOR_HPP
#define ODDS_AND_ENDS__NODE__WITH_BALANCE_FACTOR_HPP

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

namespace odds_and_ends { namespace node {

    struct with_balance_factor
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
                        char _balance_factor;

                    protected:
                        inline explicit _result(
                            ::odds_and_ends::composite_type
                            ::default_constructor_1st_stage_event const& e
                        ) : _composite_parent_t(e), _balance_factor(0)
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
                            _balance_factor(0)
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
                            _balance_factor(0)
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
                        ) : _composite_parent_t(e, arg_pack), _balance_factor(false)
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
                        ) : _composite_parent_t(e, arg), _balance_factor(false)
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
                        ) : _composite_parent_t(e, copy), _balance_factor(copy.balance_factor())
                        {
                        }

                        template <typename Copy, typename Alloc>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::coercive_copy_constructor_event const& e,
                            Copy const& copy,
                            Alloc const& alloc
                        ) : _composite_parent_t(e, copy, alloc),
                            _balance_factor(copy.balance_factor())
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
                            this->_balance_factor = copy.balance_factor();
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
                            this->_balance_factor = copy.balance_factor();
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
                            _balance_factor(source.balance_factor())
                        {
                        }

                        template <typename Source, typename Alloc>
                        inline _result(
                            ::odds_and_ends::composite_type
                            ::coercive_move_constructor_event const& e,
                            Source&& source,
                            Alloc const& alloc
                        ) : _composite_parent_t(e, static_cast<Source&&>(source), alloc),
                            _balance_factor(source.balance_factor())
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
                            this->_balance_factor = source.balance_factor();
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
                            this->_balance_factor = source.balance_factor();
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
                            typedef char balance_factor_type;
                        };

                        inline typename traits::balance_factor_type const& balance_factor() const
                        {
                            return this->_balance_factor;
                        }

                        inline typename traits::balance_factor_type& balance_factor()
                        {
                            return this->_balance_factor;
                        }

                        ODDS_AND_ENDS__COMPOSITE_TYPE__NONCOPYABLE_NONMOVABLE_BODY(_result)
                    };

                public:
                    typedef _result type;
                };
            };
        };
    };
}}  // namespace odds_and_ends::node

#endif  // ODDS_AND_ENDS__NODE__WITH_BALANCE_FACTOR_HPP

