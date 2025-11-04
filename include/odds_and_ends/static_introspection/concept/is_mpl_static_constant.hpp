// Copyright (C) 2005-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MPL_STATIC_CONSTANT_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MPL_STATIC_CONSTANT_HPP

#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <boost/mpl/equal_to.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <
        typename T,
        typename _mutable_T =
        typename ::odds_and_ends::static_introspection::remove_cvref<T>::type
    >
    struct is_mpl_static_constant :
        ::boost::mpl::equal_to<_mutable_T,typename _mutable_T::type>
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/is_std_integral_constant.hpp>
#include <odds_and_ends/static_introspection/nested_type/is_tag_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/integral_c_tag.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_mpl_static_constant :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::is_std_integral_constant<T>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::nested_type
                ::is_tag_of< ::boost::mpl::integral_c_tag,T>,
                ::odds_and_ends::static_introspection
                ::concept::_detail::is_mpl_static_constant<T>,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MPL_STATIC_CONSTANT_HPP

