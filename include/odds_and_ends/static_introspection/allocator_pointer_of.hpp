// Copyright (C) 2011-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__ALLOCATOR_POINTER_OF_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__ALLOCATOR_POINTER_OF_HPP

#include <type_traits>
#include <memory>
#include <odds_and_ends/static_introspection/_detail/allocator_pointer_of.hpp>
#include <odds_and_ends/static_introspection/nested_type/value_type_of.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct allocator_const_pointer_of_value
    {
        typedef typename ::std::pointer_traits<
            typename ::odds_and_ends::static_introspection::_detail::allocator_mutable_pointer_of<
                typename ::std::remove_const<T>::type
            >::type
        >::template rebind<
            typename ::std::add_const<
                typename ::odds_and_ends::static_introspection
                ::nested_type::value_type_of<T>::type
            >::type
        > type;
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection/nested_type/_detail/has_const_pointer.hpp>
#include <odds_and_ends/static_introspection/nested_type/_detail/const_pointer_of.hpp>
#include <boost/type_erasure/is_placeholder.hpp>
#include <boost/mpl/identity.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct allocator_const_pointer_of :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection
            ::nested_type::_detail::has_const_pointer_impl<T>,
            ::odds_and_ends::static_introspection::nested_type::_detail::const_pointer_of<T>,
            ::odds_and_ends::static_introspection::_detail::allocator_const_pointer_of_value<T>
        >
    {
    };

    template <typename T>
    struct allocator_pointer_of :
        ::boost::mpl::eval_if<
            ::boost::type_erasure::is_placeholder<typename ::std::remove_const<T>::type>,
            ::boost::mpl::identity<void>,
            ::boost::mpl::eval_if<
                ::std::is_const<T>,
                ::odds_and_ends::static_introspection
                ::_detail::allocator_const_pointer_of<T>,
                ::odds_and_ends::static_introspection
                ::_detail::allocator_mutable_pointer_of<T>
            >
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/remove_vref.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T>
    struct allocator_pointer_of :
        ::odds_and_ends::static_introspection::_detail::allocator_pointer_of<
            typename ::odds_and_ends::static_introspection::remove_vref<T>::type
        >
    {
    };
}}  // namespace odds_and_ends::static_introspection

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__ALLOCATOR_POINTER_OF_HPP

