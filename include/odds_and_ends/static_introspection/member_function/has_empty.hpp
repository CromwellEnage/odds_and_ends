// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_EMPTY_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_EMPTY_HPP

#include <odds_and_ends/static_introspection/member_function/_detail/has_empty.hpp>
#include <odds_and_ends/static_introspection/declref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_empty_ptr_container :
        ::odds_and_ends::static_introspection::member_function::_detail::has_empty<
            decltype(::odds_and_ends::static_introspection::declref<T>().base()),
            ResultPlaceholderExpr
        >
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/is_boolean_expression.hpp>
#include <odds_and_ends/static_introspection/concept/is_pointer_container.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_empty :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::is_pointer_container<T>,
            ::odds_and_ends::static_introspection::member_function
            ::_detail::has_empty_ptr_container<T,ResultPlaceholderExpr>,
            ::odds_and_ends::static_introspection::member_function
            ::_detail::has_empty<T,ResultPlaceholderExpr>
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::member_function

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_EMPTY_HPP

