// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__HAS_ELEMENT_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__HAS_ELEMENT_HPP

#include <boost/mpl/has_xxx.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(has_element_void_or_not, element, false)
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#include <type_traits>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    template <typename T>
    struct has_element_non_void :
        ::boost::mpl::if_<
            ::std::is_void<typename T::element>,
            ::boost::mpl::false_,
            ::boost::mpl::true_
        >::type
    {
    };

    template <typename T>
    struct has_element_impl :
        ::boost::mpl::if_<
            typename ::odds_and_ends::static_introspection
            ::nested_type::_detail::has_element_void_or_not<T>::type,
            ::odds_and_ends::static_introspection
            ::nested_type::_detail::has_element_non_void<T>,
            ::boost::mpl::false_
        >
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {

    template <typename T>
    struct has_element :
        ::odds_and_ends::static_introspection::nested_type::_detail::has_element_impl<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::nested_type

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__HAS_ELEMENT_HPP

