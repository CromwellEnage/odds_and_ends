// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__ALLOCATOR_VOID_POINTER_OF_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__ALLOCATOR_VOID_POINTER_OF_HPP

#include <type_traits>
#include <memory>
#include <odds_and_ends/static_introspection/_detail/allocator_pointer_of.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct allocator_void_pointer_of_void
    {
        typedef ::std::pointer_traits<
            typename ::odds_and_ends::static_introspection
            ::_detail::allocator_mutable_pointer_of<T>::type
        >::template rebind<void> type;
    };

    template <typename T>
    struct allocator_const_void_pointer_of_void
    {
        typedef ::std::pointer_traits<
            typename ::odds_and_ends::static_introspection::_detail::allocator_mutable_pointer_of<
                typename ::std::remove_const<T>::type
            >::type
        >::template rebind<void const> type;
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection/nested_type/_detail/has_void_pointer.hpp>
#include <odds_and_ends/static_introspection/nested_type/_detail/void_pointer_of.hpp>
#include <boost/type_erasure/is_placeholder.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct allocator_void_pointer_of :
        ::boost::mpl::eval_if<
            ::boost::type_erasure::is_placeholder<typename ::std::remove_const<T>::type>,
            ::boost::mpl::identity<void>,
            ::boost::mpl::eval_if<
                ::std::is_const<T>,
                ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::nested_type
                    ::_detail::has_const_void_pointer_impl<T>,
                    ::odds_and_ends::static_introspection
                    ::nested_type::_detail::const_void_pointer_of<T>,
                    ::odds_and_ends::static_introspection::_detail
                    ::allocator_const_void_pointer_of_void<T>
                >,
                ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection
                    ::nested_type::_detail::has_void_pointer_impl<T>,
                    ::odds_and_ends::static_introspection
                    ::nested_type::_detail::void_pointer_of<T>,
                    ::odds_and_ends::static_introspection
                    ::_detail::allocator_void_pointer_of_void<T>
                >
            >
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/remove_vref.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T>
    struct allocator_void_pointer_of :
        ::odds_and_ends::static_introspection::_detail::allocator_void_pointer_of<
            typename ::odds_and_ends::static_introspection::remove_vref<T>::type
        >
    {
    };
}}  // namespace odds_and_ends::static_introspection

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__ALLOCATOR_VOID_POINTER_OF_HPP

