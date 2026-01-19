// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_ACCUMULATOR_FEATURE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_ACCUMULATOR_FEATURE_HPP

#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <odds_and_ends/static_introspection/nested_template/has_apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_accumulator_feature_with_impl :
        /*::odds_and_ends::static_introspection::nested_template::has_apply<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type::impl
        >*/::boost::mpl::true_
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/concept/is_mpl_boolean_constant.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_accumulator_feature_with_weight :
        ::odds_and_ends::static_introspection::concept::is_mpl_boolean_constant<
            typename ::odds_and_ends::static_introspection
            ::remove_cvref<T>::type::is_weight_accumulator
        >
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <type_traits>
#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_dependencies.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_impl.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_is_weight_accumulator.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_accumulator_feature :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::nested_type::has_impl<T>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_accumulator_feature_with_impl<T>,
                ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection
                    ::nested_type::has_is_weight_accumulator<T>,
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::is_accumulator_feature_with_weight<T>,
                    ::boost::mpl::true_
                >,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_ACCUMULATOR_FEATURE_HPP

