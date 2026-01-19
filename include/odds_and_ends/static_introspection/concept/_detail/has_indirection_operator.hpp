// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__HAS_INDIRECTION_OPERATOR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__HAS_INDIRECTION_OPERATOR_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/declref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    class has_indirection_operator_expr
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(::odds_and_ends::static_introspection::declref<B>().operator->())
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::concept::_detail
                ::has_indirection_operator_expr<T>::template _check<T>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct has_indirection_operator_impl :
        ::boost::mpl::if_<
            ::std::is_void<
                decltype(::odds_and_ends::static_introspection::declref<T>().operator->())
            >,
            ::boost::mpl::false_,
            ::boost::mpl::true_
        >::type
    {
    };

    template <typename T>
    struct has_indirection_operator :
        ::boost::mpl::if_<
            typename ::odds_and_ends::static_introspection::concept
            ::_detail::has_indirection_operator_expr<T>::type,
            ::odds_and_ends::static_introspection::concept
            ::_detail::has_indirection_operator_impl<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__HAS_INDIRECTION_OPERATOR_HPP

