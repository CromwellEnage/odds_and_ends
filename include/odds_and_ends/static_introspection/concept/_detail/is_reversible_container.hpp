// Copyright (C) 2012-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_REVERSIBLE_CONTAINER_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_REVERSIBLE_CONTAINER_HPP

#include <odds_and_ends/static_introspection/concept/_detail/is_container_impl.hpp>
#include <odds_and_ends/static_introspection/nested_type/reverse_iterator_of.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename IteratorPlaceholderExpr>
    struct has_container_reverse_iterator :
        ::boost::mpl::if_<
            typename ::boost::mpl::apply1<
                IteratorPlaceholderExpr,
                typename ::odds_and_ends::static_introspection
                ::nested_type::reverse_iterator_of<T>::type
            >::type,
            ::odds_and_ends::static_introspection::concept::_detail
            ::has_container_iterator<T,IteratorPlaceholderExpr>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/nested_type/has_reverse_iterator.hpp>
#include <odds_and_ends/static_introspection/member_function/has_rbegin.hpp>
#include <odds_and_ends/static_introspection/member_function/has_rend.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_base_reversible_container :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::_detail::is_base_container<T>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::nested_type::has_reverse_iterator<T>,
                ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection::member_function::has_rbegin<T>,
                    ::odds_and_ends::static_introspection::member_function::has_rend<T>,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/member_function/has_crbegin.hpp>
#include <odds_and_ends/static_introspection/member_function/has_crend.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_const_reversible_container :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::_detail::is_const_container<T>,
            ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::member_function::has_crbegin<T>,
                ::odds_and_ends::static_introspection::member_function::has_crend<T>,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_REVERSIBLE_CONTAINER_HPP

