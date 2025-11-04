// Copyright (C) 2011-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__HAS_POINTER_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__HAS_POINTER_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/nested_type/_detail/has_const_pointer.hpp>
#include <odds_and_ends/static_introspection/nested_type/_detail/has_pointer.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    template <typename T>
    struct has_pointer :
        ::boost::mpl::if_<
            ::std::is_const<T>,
            ::odds_and_ends::static_introspection
            ::nested_type::_detail::has_const_pointer_impl<T>,
            ::odds_and_ends::static_introspection::nested_type::_detail::has_pointer_impl<T>
        >
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/remove_vref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {

    template <typename T>
    struct has_pointer :
        ::odds_and_ends::static_introspection::nested_type::_detail::has_pointer<
            typename ::odds_and_ends::static_introspection::remove_vref<T>::type
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::nested_type

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__HAS_POINTER_HPP

