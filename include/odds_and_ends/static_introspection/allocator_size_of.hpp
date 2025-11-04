// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__ALLOCATOR_SIZE_OF_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__ALLOCATOR_SIZE_OF_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/allocator_difference_of.hpp>
#include <odds_and_ends/static_introspection/remove_vref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct allocator_size_of :
        ::std::make_unsigned<
            typename ::odds_and_ends::static_introspection::allocator_difference_of<
                typename ::odds_and_ends::static_introspection::remove_vref<T>::type
            >::type
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_size_type.hpp>
#include <odds_and_ends/static_introspection/nested_type/size_type_of.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/type_erasure/is_placeholder.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T>
    struct allocator_size_of :
        ::boost::mpl::eval_if<
            ::boost::type_erasure::is_placeholder<T>,
            ::boost::mpl::identity<void>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::nested_type::has_size_type<T>,
                ::odds_and_ends::static_introspection::nested_type::size_type_of<T>,
                ::odds_and_ends::static_introspection::_detail::allocator_size_of<T>
            >
        >
    {
    };
}}  // namespace boost::concept::traits

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__ALLOCATOR_SIZE_OF_HPP

