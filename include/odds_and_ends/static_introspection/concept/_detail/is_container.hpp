// Copyright (C) 2011-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_CONTAINER_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_CONTAINER_HPP

#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <
        typename IteratorPlaceholderExpr,
        template <typename> class UPred1,
        template <typename> class UPred2,
        template <typename, typename> class BPred
    >
    struct container_policy
    {
        template <typename T>
        struct apply :
            ::boost::mpl::eval_if<
                UPred1<T>,
                ::boost::mpl::if_<
                    UPred2<T>,
                    BPred<T,IteratorPlaceholderExpr>,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >
        {
        };
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/_detail/apply1_remove_cvref.hpp>
#include <odds_and_ends/static_introspection/_detail/apply1_remove_vref_add_const.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <
        typename T,
        typename IteratorPlaceholderExpr,
        template <typename> class BasePred,
        template <typename> class MutablePred,
        template <typename> class ConstPred,
        template <typename, typename> class IterPred
    >
    struct is_container :
        ::boost::mpl::eval_if<
            typename ::odds_and_ends::static_introspection::_detail::apply1_remove_cvref<
                ::odds_and_ends::static_introspection::concept::_detail
                ::container_policy<IteratorPlaceholderExpr,BasePred,MutablePred,IterPred>,
                T
            >::type,
            ::odds_and_ends::static_introspection::_detail::apply1_remove_vref_add_const<
                ::odds_and_ends::static_introspection::concept::_detail
                ::container_policy<IteratorPlaceholderExpr,BasePred,ConstPred,IterPred>,
                T
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_CONTAINER_HPP

