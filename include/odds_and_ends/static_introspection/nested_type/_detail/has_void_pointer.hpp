// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__DETAIL__HAS_VOID_POINTER_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__DETAIL__HAS_VOID_POINTER_HPP

#include <boost/mpl/has_xxx.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(has_const_void_pointer_void_or_not, const_void_pointer, false)

    BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(has_void_pointer_void_or_not, void_pointer, false)
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#include <type_traits>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    template <typename T>
    struct has_const_void_pointer_non_void :
        ::boost::mpl::if_<
            ::std::is_void<typename T::const_void_pointer>,
            ::boost::mpl::false_,
            ::boost::mpl::true_
        >::type
    {
    };

    template <typename T>
    struct has_void_pointer_non_void :
        ::boost::mpl::if_<
            ::std::is_void<typename T::void_pointer>,
            ::boost::mpl::false_,
            ::boost::mpl::true_
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    template <typename T, typename _m_T = typename ::std::remove_const<T>::type>
    struct has_const_void_pointer_impl :
        ::boost::mpl::eval_if<
            typename ::odds_and_ends::static_introspection::nested_type
            ::_detail::has_const_void_pointer_void_or_not<_m_T>::type,
            ::odds_and_ends::static_introspection::nested_type
            ::_detail::has_const_void_pointer_non_void<_m_T>,
            ::boost::mpl::false_
        >::type
    {
    };

    template <typename T>
    struct has_void_pointer_impl :
        ::boost::mpl::eval_if<
            typename ::odds_and_ends::static_introspection::nested_type
            ::_detail::has_void_pointer_void_or_not<T>::type,
            ::odds_and_ends::static_introspection::nested_type
            ::_detail::has_void_pointer_non_void<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__DETAIL__HAS_VOID_POINTER_HPP

