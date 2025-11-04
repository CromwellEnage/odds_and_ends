// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__ALLOCATOR_PROPAGATE_ON_CONTAINER_OP_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__ALLOCATOR_PROPAGATE_ON_CONTAINER_OP_HPP

#include <boost/mpl/has_xxx.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(
        allocator_propagate_on_container_copy_assignment_void_or_not,
        propagate_on_container_copy_assignment,
        false
    )

    BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(
        allocator_propagate_on_container_move_assignment_void_or_not,
        propagate_on_container_move_assignment,
        false
    )

    BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(
        allocator_propagate_on_container_swap_void_or_not,
        propagate_on_container_swap,
        false
    )
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <type_traits>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct allocator_propagate_on_container_copy_assignment_non_void
    {
        typedef typename ::boost::mpl::if_<
            ::std::is_void<typename T::propagate_on_container_copy_assignment>,
            ::boost::mpl::false_,
            ::boost::mpl::true_
        >::type type;
    };

    template <typename T>
    struct allocator_propagate_on_container_move_assignment_non_void
    {
        typedef typename ::boost::mpl::if_<
            ::std::is_void<typename T::propagate_on_container_move_assignment>,
            ::boost::mpl::false_,
            ::boost::mpl::true_
        >::type type;
    };

    template <typename T>
    struct allocator_propagate_on_container_swap_non_void
    {
        typedef typename ::boost::mpl::if_<
            ::std::is_void<typename T::propagate_on_container_swap>,
            ::boost::mpl::false_,
            ::boost::mpl::true_
        >::type type;
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct allocator_propagate_on_container_copy_assignment_impl :
        ::boost::mpl::eval_if<
            typename ::odds_and_ends::static_introspection::_detail
            ::allocator_propagate_on_container_copy_assignment_void_or_not<T>::type,
            ::odds_and_ends::static_introspection::_detail
            ::allocator_propagate_on_container_copy_assignment_non_void<T>,
            ::boost::mpl::false_
        >::type
    {
    };

    template <typename T>
    struct allocator_propagate_on_container_move_assignment_impl :
        ::boost::mpl::eval_if<
            typename ::odds_and_ends::static_introspection::_detail
            ::allocator_propagate_on_container_move_assignment_void_or_not<T>::type,
            ::odds_and_ends::static_introspection::_detail
            ::allocator_propagate_on_container_move_assignment_non_void<T>,
            ::boost::mpl::false_
        >::type
    {
    };

    template <typename T>
    struct allocator_propagate_on_container_swap_impl :
        ::boost::mpl::eval_if<
            typename ::odds_and_ends::static_introspection::_detail
            ::allocator_propagate_on_container_swap_void_or_not<T>::type,
            ::odds_and_ends::static_introspection::_detail
            ::allocator_propagate_on_container_swap_non_void<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <boost/type_erasure/is_placeholder.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct allocator_propagate_on_container_copy_assignment :
        ::boost::mpl::if_<
            ::boost::type_erasure::is_placeholder<T>,
            void,
            ::odds_and_ends::static_introspection::_detail
            ::allocator_propagate_on_container_copy_assignment_impl<T>
        >::type
    {
    };

    template <typename T>
    struct allocator_propagate_on_container_move_assignment :
        ::boost::mpl::if_<
            ::boost::type_erasure::is_placeholder<T>,
            void,
            ::odds_and_ends::static_introspection::_detail
            ::allocator_propagate_on_container_move_assignment_impl<T>
        >::type
    {
    };

    template <typename T>
    struct allocator_propagate_on_container_swap :
        ::boost::mpl::if_<
            ::boost::type_erasure::is_placeholder<T>,
            void,
            ::odds_and_ends::static_introspection::_detail
            ::allocator_propagate_on_container_swap_impl<T>
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T>
    struct allocator_propagate_on_container_copy_assignment :
        ::odds_and_ends::static_introspection::_detail
        ::allocator_propagate_on_container_copy_assignment<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type
        >
    {
    };

    template <typename T>
    struct allocator_propagate_on_container_move_assignment :
        ::odds_and_ends::static_introspection::_detail
        ::allocator_propagate_on_container_move_assignment<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type
        >
    {
    };

    template <typename T>
    struct allocator_propagate_on_container_swap :
        ::odds_and_ends::static_introspection::_detail
        ::allocator_propagate_on_container_swap<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type
        >
    {
    };
}}  // namespace odds_and_ends::static_introspection

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__ALLOCATOR_PROPAGATE_ON_CONTAINER_OP_HPP

