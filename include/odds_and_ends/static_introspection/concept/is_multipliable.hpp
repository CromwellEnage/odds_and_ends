// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MULTIPLIABLE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MULTIPLIABLE_HPP

#include <type_traits>
#include <utility>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename Factor, typename Product>
    struct is_multipliable_impl :
        ::boost::mpl::if_<
            ::std::is_convertible<
                decltype(::std::declval<T>() * ::std::declval<Factor>()),
                typename ::odds_and_ends::static_introspection::remove_cvref<Product>::type
            >,
            ::boost::mpl::true_,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename F>
    class has_multiplication_op
    {
        template <typename B, typename D>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(::std::declval<B>() * ::std::declval<D>())
                >::type
            );

        template <typename B, typename D>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::concept::_detail
                ::has_multiplication_op<T,F>::template _check<T,F>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };

    template <typename T, typename Factor, typename Product>
    struct is_multipliable :
        ::boost::mpl::if_<
            typename ::odds_and_ends::static_introspection::concept
            ::_detail::has_multiplication_op<T,Factor>::type,
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_multipliable_impl<T,Factor,Product>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/concept/is_multiplication_assignable.hpp>
#include <odds_and_ends/use_default_policy.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename Factor>
    struct is_multipliable<T,Factor,::odds_and_ends::use_default_policy> :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::is_multipliable<T,Factor,T>,
            ::boost::mpl::if_<
                ::std::is_const<T>,
                ::boost::mpl::true_,
                ::odds_and_ends::static_introspection::concept
                ::is_multiplication_assignable<T,Factor>
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/remove_vref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename Factor, typename Product>
    struct is_multipliable :
        ::odds_and_ends::static_introspection::concept::_detail::is_multipliable<
            typename ::odds_and_ends::static_introspection::remove_vref<T>::type,
            Factor,
            Product
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MULTIPLIABLE_HPP

