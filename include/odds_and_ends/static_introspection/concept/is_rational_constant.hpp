// Copyright (C) 2013-2026 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_RATIONAL_CONSTANT_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_RATIONAL_CONSTANT_HPP

#include <odds_and_ends/static_introspection/nested_type/type_of.hpp>
#include <odds_and_ends/static_introspection/concept/is_std_ratio.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_rational_constant :
        ::odds_and_ends::static_introspection::concept::is_std_ratio<
            typename ::odds_and_ends::static_introspection::nested_type::type_of<T>::type
        >
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_type.hpp>
#include <odds_and_ends/static_introspection/nested_type/is_type_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_rational_constant :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::_detail::is_rational_constant<T>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::nested_type::is_type_of<T,T>,
                ::boost::mpl::true_,
                ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection::nested_type::has_type<T>,
                    ::odds_and_ends::static_introspection
                    ::concept::_detail::is_rational_constant<T>,
                    ::boost::mpl::false_
                >
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_RATIONAL_CONSTANT_HPP

