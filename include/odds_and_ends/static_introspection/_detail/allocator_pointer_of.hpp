// Copyright (C) 2011-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__DETAIL__ALLOCATOR_POINTER_OF_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__DETAIL__ALLOCATOR_POINTER_OF_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/nested_type/value_type_of.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct allocator_pointer_of_value :
        ::std::add_pointer<
            typename ::odds_and_ends::static_introspection::nested_type::value_type_of<T>::type
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection/nested_type/_detail/has_pointer.hpp>
#include <odds_and_ends/static_introspection/nested_type/_detail/pointer_of.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct allocator_mutable_pointer_of :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::nested_type::_detail::has_pointer_impl<T>,
            ::odds_and_ends::static_introspection::nested_type::_detail::pointer_of<T>,
            ::odds_and_ends::static_introspection::_detail::allocator_pointer_of_value<T>
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__DETAIL__ALLOCATOR_POINTER_OF_HPP

