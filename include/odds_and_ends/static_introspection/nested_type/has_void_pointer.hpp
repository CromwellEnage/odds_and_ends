// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__HAS_VOID_POINTER_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__HAS_VOID_POINTER_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/nested_type/_detail/has_void_pointer.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    template <typename T>
    struct has_void_pointer :
        ::boost::mpl::if_<
            ::std::is_const<T>,
            ::odds_and_ends::static_introspection::nested_type
            ::_detail::has_const_void_pointer_impl<T>,
            ::odds_and_ends::static_introspection
            ::nested_type::_detail::has_void_pointer_impl<T>
        >
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {

    template <typename T>
    struct has_void_pointer :
        ::odds_and_ends::static_introspection::nested_type::_detail::has_void_pointer<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::nested_type

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__HAS_VOID_POINTER_HPP

