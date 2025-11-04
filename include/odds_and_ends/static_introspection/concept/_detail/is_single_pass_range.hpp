// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_SINGLE_PASS_RANGE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_SINGLE_PASS_RANGE_HPP

#include <type_traits>
#include <boost/range/iterator.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename PlaceholderExpr>
    struct is_single_pass_range
    {
        template <typename T>
        class apply
        {
            typedef typename ::boost::range_iterator<T>::type _T_iterator;

        public:
            typedef typename ::boost::mpl::eval_if<
                ::std::is_convertible<
                    _T_iterator,
                    typename ::boost::range_iterator<typename ::std::add_const<T>::type>::type
                >,
                ::boost::mpl::apply1<PlaceholderExpr,_T_iterator>,
                ::boost::mpl::false_
            >::type type;
        };
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_SINGLE_PASS_RANGE_HPP

