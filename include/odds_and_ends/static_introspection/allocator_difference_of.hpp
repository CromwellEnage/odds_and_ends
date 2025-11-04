// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__ALLOCATOR_DIFFERENCE_OF_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__ALLOCATOR_DIFFERENCE_OF_HPP

#include <memory>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct allocator_difference_of
    {
        typedef typename ::std::allocator_traits<T>::difference_type type;
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/_detail/difference_of.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T>
    struct allocator_difference_of :
        ::odds_and_ends::static_introspection::_detail::difference_of<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type,
            ::odds_and_ends::static_introspection::_detail::allocator_difference_of
        >
    {
    };
}}  // namespace odds_and_ends::static_introspection

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__ALLOCATOR_DIFFERENCE_OF_HPP

