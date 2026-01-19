// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_SUBTRACTABLE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_SUBTRACTABLE_HPP

#include <type_traits>
#include <utility>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename Subtrahend, typename Difference>
    struct is_subtractable_impl :
        ::boost::mpl::if_<
            ::std::is_convertible<
                decltype(::std::declval<T>() - ::std::declval<Subtrahend>()),
                typename ::odds_and_ends::static_introspection::remove_cvref<Difference>::type
            >,
            ::boost::mpl::true_,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/has_minus_operator.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename Subtrahend, typename Difference>
    struct is_subtractable :
        ::boost::mpl::if_<
            typename ::odds_and_ends::static_introspection::concept
            ::_detail::has_minus_operator<T,Subtrahend>::type,
            ::odds_and_ends::static_introspection::concept::_detail
            ::is_subtractable_impl<T,Subtrahend,Difference>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#include <odds_and_ends/static_introspection/concept/is_subtraction_assignable.hpp>
#include <odds_and_ends/static_introspection/remove_vref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename Subtrahend>
    struct is_subtractable_impl<T,Subtrahend,::odds_and_ends::use_default_policy> :
        ::boost::mpl::if_<
            ::std::is_const<typename ::odds_and_ends::static_introspection::remove_vref<T>::type>,
            ::boost::mpl::true_,
            ::odds_and_ends::static_introspection::concept
            ::is_subtraction_assignable<T,Subtrahend>
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/use_default_policy.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename Subtrahend>
    struct is_subtractable<T,Subtrahend,::odds_and_ends::use_default_policy> :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::concept::is_subtractable<T,Subtrahend,T>,
            ::odds_and_ends::static_introspection::concept::_detail
            ::is_subtractable_impl<T,Subtrahend,::odds_and_ends::use_default_policy>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_SUBTRACTABLE_HPP

