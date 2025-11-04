// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_ALLOCATOR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_ALLOCATOR_HPP

#include <odds_and_ends/static_introspection/concept/is_nullable_pointer.hpp>
#include <odds_and_ends/static_introspection/allocator_pointer_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

#include <odds_and_ends/static_introspection/concept/is_legacy_random_access_iterator.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <
        typename T,
        typename _T_ptr = typename ::odds_and_ends
        ::static_introspection::allocator_pointer_of<T>::type
    >
    struct is_allocator_with_pointer :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::concept::is_nullable_pointer<_T_ptr>,
            ::odds_and_ends::static_introspection::concept
            ::is_legacy_random_access_iterator<_T_ptr>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/nested_type/has_pointer.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <
        typename T,
        typename _u_T = typename ::odds_and_ends::static_introspection::remove_cvref<T>::type
    >
    struct has_allocator_pointer :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::nested_type::has_pointer<_u_T>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_allocator_with_pointer<_u_T>,
                ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection::nested_type::has_pointer<T>,
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::is_allocator_with_pointer<T>,
                    ::boost::mpl::true_
                >,
                ::boost::mpl::false_
            >,
            ::boost::mpl::true_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_value_type.hpp>
#include <odds_and_ends/static_introspection/member_function/has_allocate.hpp>
#include <odds_and_ends/static_introspection/member_function/has_deallocate.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_allocator :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::nested_type::has_value_type<T>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::member_function::has_allocate<T>,
                ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection::member_function::has_deallocate<T>,
                    ::odds_and_ends::static_introspection
                    ::concept::_detail::has_allocator_pointer<T>,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace boost::concept::traits

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_ALLOCATOR_HPP

