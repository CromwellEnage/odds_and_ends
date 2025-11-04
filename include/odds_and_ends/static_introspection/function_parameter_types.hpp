// Copyright (C) 2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__FUNCTION_PARAMETER_TYPES_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__FUNCTION_PARAMETER_TYPES_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <boost/mpl/deque.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename F, typename ...Args>
    struct function_parameter_types_ext<F(Args...)>
    {
        typedef ::boost::mpl::deque<Args...> type;
    };
}}  // namespace odds_and_ends::static_introspection

#include <boost/function_types/is_function.hpp>
#include <boost/function_types/parameter_types.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename F, typename ClassTransform>
    struct function_parameter_types :
        ::boost::mpl::if_<
            ::boost::function_types::is_function<F>,
            ::boost::function_types::parameter_types<F,ClassTransform>,
            ::odds_and_ends::static_introspection
            ::function_parameter_types_ext<F>
        >::type
    {
    };
}}  // namespace odds_and_ends::static_introspection

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__FUNCTION_PARAMETER_TYPES_HPP

