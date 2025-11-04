// Copyright (C) 2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__FUNCTION_RESULT_TYPE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__FUNCTION_RESULT_TYPE_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T>
    struct function_result_type_ext
    {
        typedef typename T::result_type type;
    };
}}  // namespace odds_and_ends::static_introspection

#include <boost/function_types/is_function.hpp>
#include <boost/function_types/result_type.hpp>
#include <boost/type_erasure/is_placeholder.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct function_result_type :
        ::boost::mpl::eval_if<
            ::boost::type_erasure::is_placeholder<T>,
            ::boost::mpl::identity<void>,
            ::boost::mpl::eval_if<
                ::boost::function_types::is_function<T>,
                ::boost::function_types::function_result_type<T>,
                ::odds_and_ends::static_introspection::function_result_type_ext<T>
            >
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection/remove_cvref.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T>
    struct function_result_type :
        ::odds_and_ends::static_introspection::_detail::function_result_type<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type
        >
    {
    };
}}  // namespace odds_and_ends::static_introspection

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__FUNCTION_RESULT_TYPE_HPP

