// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_NULLABLE_POINTER_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_NULLABLE_POINTER_HPP

#include <cstddef>
#include <type_traits>
#include <odds_and_ends/static_introspection/concept/is_lvalue_assignable.hpp>
#include <odds_and_ends/static_introspection/concept/is_equality_comparable.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <
        typename T,
        typename _u_T = typename ::odds_and_ends::static_introspection::remove_cvref<T>::type
    >
    struct is_nullable_pointer :
        ::boost::mpl::eval_if<
            ::std::is_default_constructible<_u_T>,
            ::boost::mpl::eval_if<
                ::std::is_copy_constructible<_u_T>,
                ::boost::mpl::eval_if<
                    ::std::is_copy_assignable<_u_T>,
                    ::boost::mpl::eval_if<
                        ::odds_and_ends::static_introspection::concept
                        ::is_lvalue_assignable<_u_T,::std::nullptr_t const>,
                        ::boost::mpl::if_<
                            ::odds_and_ends::static_introspection::concept
                            ::is_equality_comparable<T,::std::nullptr_t const>,
                            ::odds_and_ends::static_introspection
                            ::concept::is_lvalue_assignable<_u_T>,
                            ::boost::mpl::false_
                        >,
                        ::boost::mpl::false_
                    >,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_nullable_pointer :
        ::boost::mpl::if_<
            typename ::odds_and_ends::static_introspection
            ::concept::_detail::is_nullable_pointer<T>::type,
            ::odds_and_ends::static_introspection::concept::is_equality_comparable<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_NULLABLE_POINTER_HPP

