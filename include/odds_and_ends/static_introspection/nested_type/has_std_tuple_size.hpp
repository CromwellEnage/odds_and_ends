// Copyright (C) 2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__HAS_STD_TUPLE_SIZE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__HAS_STD_TUPLE_SIZE_HPP

#include <utility>
#include <boost/mpl/aux_/has_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    template <typename T>
    struct has_std_tuple_size_type : ::boost::mpl::aux::has_type< ::std::tuple_size<T> >
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#include <odds_and_ends/static_introspection/concept/is_std_integral_constant.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    template <typename T>
    struct has_std_tuple_size_impl :
        ::odds_and_ends::static_introspection::concept::is_std_integral_constant<
            typename ::std::tuple_size<T>::type
        >
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    template <typename T>
    struct has_std_tuple_size :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::nested_type
            ::_detail::has_std_tuple_size_type<T>,
            ::odds_and_ends::static_introspection::nested_type
            ::_detail::has_std_tuple_size_impl<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {

    template <typename T>
    struct has_std_tuple_size :
        ::odds_and_ends::static_introspection::nested_type::_detail::has_std_tuple_size<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::nested_type

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__HAS_STD_TUPLE_SIZE_HPP

