// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__IS_EXPRESSION_TYPE_OF_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__IS_EXPRESSION_TYPE_OF_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/nested_type/expression_type_of.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    template <typename T1, typename T2>
    struct is_expression_type_of_impl :
        ::boost::mpl::if_<
            ::std::is_same<
                typename ::odds_and_ends::static_introspection::remove_cvref<T1>::type,
                typename ::odds_and_ends::static_introspection
                ::nested_type::expression_type_of<T2>::type
            >,
            ::boost::mpl::true_,
            ::boost::mpl::false_
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_expression_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {

    template <typename T1, typename T2>
    struct is_expression_type_of :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::nested_type::has_expression_type<T2>,
            ::odds_and_ends::static_introspection::nested_type
            ::_detail::is_expression_type_of_impl<T1,T2>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::nested_type

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__IS_EXPRESSION_TYPE_OF_HPP

