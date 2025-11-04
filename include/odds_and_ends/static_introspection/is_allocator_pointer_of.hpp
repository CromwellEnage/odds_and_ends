// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__IS_ALLOCATOR_POINTER_OF_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__IS_ALLOCATOR_POINTER_OF_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/allocator_pointer_of.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T1, typename T2>
    struct is_allocator_pointer_of :
        ::boost::mpl::if_<
            ::std::is_same<
                typename ::odds_and_ends::static_introspection::remove_cvref<T1>::type,
                typename ::odds_and_ends::static_introspection::allocator_pointer_of<T2>::type
            >,
            ::boost::mpl::true_,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_pointer.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_value_type.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T1, typename T2>
    struct is_allocator_pointer_of :
        ::boost::mpl::if_<
            typename ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::nested_type::has_pointer<T2>,
                ::boost::mpl::true_,
                ::odds_and_ends::static_introspection::nested_type::has_value_type<T2>
            >::type,
            ::odds_and_ends::static_introspection::_detail::is_allocator_pointer_of<T1,T2>,
            ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace odds_and_ends::static_introspection

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__IS_ALLOCATOR_POINTER_OF_HPP

