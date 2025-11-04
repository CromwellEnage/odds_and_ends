// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__IS_INVOKE_RESULT_OF_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__IS_INVOKE_RESULT_OF_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/invoke_result.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T, typename F, typename ...Args>
    struct is_invoke_result_of :
        ::boost::mpl::if_<
            ::std::is_same<
                typename ::odds_and_ends::static_introspection
                ::invoke_result<F,Args...>::type,
                T
            >,
            ::boost::mpl::true_,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/is_invocable.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T, typename F, typename ...Args>
    struct is_invoke_result_of :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::is_invocable<F,Args...>,
            ::odds_and_ends::static_introspection::_detail
            ::is_invoke_result_of<T,F,Args...>,
            ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace odds_and_ends::static_introspection

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__IS_INVOKE_RESULT_OF_HPP

