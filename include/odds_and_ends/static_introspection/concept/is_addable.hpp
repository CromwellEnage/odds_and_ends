// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_ADDABLE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_ADDABLE_HPP

#include <type_traits>
#include <utility>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename Addend, typename Sum>
    struct is_addable_impl :
        ::boost::mpl::if_<
            ::std::is_convertible<
                decltype(::std::declval<T>() + ::std::declval<Addend>()),
                typename ::odds_and_ends::static_introspection::remove_cvref<Sum>::type
            >,
            ::boost::mpl::true_,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename Addend>
    class has_addition_op
    {
        template <typename B, typename D>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(::std::declval<B>() + ::std::declval<D>())
                >::type
            );

        template <typename B, typename D>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::concept::_detail
                ::has_addition_op<T,Addend>::template _check<T,Addend>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename Addend, typename Sum>
    struct is_addable :
        ::boost::mpl::if_<
            typename ::odds_and_ends::static_introspection
            ::concept::_detail::has_addition_op<T,Addend>::type,
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_addable_impl<T,Addend,Sum>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#include <odds_and_ends/static_introspection/concept/is_addition_assignable.hpp>
#include <odds_and_ends/static_introspection/remove_vref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename Addend>
    struct is_addable_impl<T,Addend,::odds_and_ends::use_default_policy> :
        ::boost::mpl::if_<
            ::std::is_const<typename ::odds_and_ends::static_introspection::remove_vref<T>::type>,
            ::boost::mpl::true_,
            ::odds_and_ends::static_introspection::concept::is_addition_assignable<T,Addend>
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/use_default_policy.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename Addend>
    struct is_addable<T,Addend,::odds_and_ends::use_default_policy> :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::concept::is_addable<T,Addend,T>,
            ::odds_and_ends::static_introspection::concept::_detail
            ::is_addable_impl<T,Addend,::odds_and_ends::use_default_policy>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_ADDABLE_HPP

