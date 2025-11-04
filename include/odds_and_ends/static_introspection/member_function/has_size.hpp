// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_SIZE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_SIZE_HPP

#include <odds_and_ends/static_introspection/member_function/_detail/has_size.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <odds_and_ends/static_introspection/declref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <
        typename T,
        typename Param,
        typename ResultPlaceholderExpr,
        typename _mutable_T = typename ::odds_and_ends::static_introspection::remove_cvref<T>::type
    >
    struct has_size_of_pointer_container :
        ::odds_and_ends::static_introspection::member_function::_detail::has_size<
            decltype(::odds_and_ends::static_introspection::declmref<_mutable_T>().base()),
            Param,
            ResultPlaceholderExpr
        >
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/nested_type/is_size_type_of.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/has_pointer_container_nested_types.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct has_size :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::concept
            ::_detail::has_pointer_container_nested_types<T>,
            ::odds_and_ends::static_introspection::member_function::_detail
            ::has_size_of_pointer_container<T,Param,ResultPlaceholderExpr>,
            ::odds_and_ends::static_introspection::member_function
            ::_detail::has_size<T,Param,ResultPlaceholderExpr>
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::member_function

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_SIZE_HPP

