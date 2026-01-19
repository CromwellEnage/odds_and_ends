// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_MAX_SIZE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_MAX_SIZE_HPP

#include <odds_and_ends/static_introspection/member_function/_detail/has_max_size.hpp>
#include <odds_and_ends/static_introspection/declref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_max_size_ptr_container
    {
        typedef ::odds_and_ends::static_introspection::member_function::_detail::has_max_size<
            decltype(::odds_and_ends::static_introspection::declmref<T>().base()),
            ResultPlaceholderExpr
        > type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/nested_type/is_size_type_of.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/has_pointer_container_nested_types.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_max_size :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept
            ::_detail::has_pointer_container_nested_types<T>,
            ::odds_and_ends::static_introspection::member_function::_detail
            ::has_max_size_ptr_container<T,ResultPlaceholderExpr>,
            ::odds_and_ends::static_introspection::member_function
            ::_detail::has_max_size<T,ResultPlaceholderExpr>
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::member_function

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_MAX_SIZE_HPP

