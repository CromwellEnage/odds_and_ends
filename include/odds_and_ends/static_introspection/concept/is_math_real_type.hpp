// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MATH_REAL_TYPE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MATH_REAL_TYPE_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/is_lvalue_assignable.hpp>
#include <odds_and_ends/static_introspection/concept/is_identity_operable.hpp>
#include <odds_and_ends/static_introspection/concept/is_negatable.hpp>
#include <odds_and_ends/static_introspection/concept/is_addable.hpp>
#include <odds_and_ends/static_introspection/concept/is_subtractable.hpp>
#include <odds_and_ends/static_introspection/concept/is_multipliable.hpp>
#include <odds_and_ends/static_introspection/concept/is_dividable.hpp>
#include <odds_and_ends/static_introspection/concept/is_comparable.hpp>
#include <odds_and_ends/static_introspection/is_convertible_to_cref_of.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <odds_and_ends/use_default_policy.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename PlaceholderExpr>
    struct is_math_real_type :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::is_lvalue_assignable<
                typename ::odds_and_ends::static_introspection::remove_cvref<T>::type,
                ::odds_and_ends::use_default_policy,
                PlaceholderExpr
            >,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept::is_identity_operable<T>,
                ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::concept::is_addable<T>,
                    ::boost::mpl::eval_if<
                        ::odds_and_ends::static_introspection::concept::is_subtractable<T>,
                        ::boost::mpl::eval_if<
                            ::odds_and_ends::static_introspection::concept::is_multipliable<T>,
                            ::boost::mpl::eval_if<
                                ::odds_and_ends::static_introspection::concept::is_dividable<T>,
                                ::boost::mpl::if_<
                                    ::odds_and_ends::static_introspection
                                    ::concept::is_negatable<T>,
                                    ::odds_and_ends::static_introspection
                                    ::concept::is_comparable<T>,
                                    ::boost::mpl::false_
                                >,
                                ::boost::mpl::false_
                            >,
                            ::boost::mpl::false_
                        >,
                        ::boost::mpl::false_
                    >,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MATH_REAL_TYPE_HPP

