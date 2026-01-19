// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_LEGACY_FORWARD_ITERATOR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_LEGACY_FORWARD_ITERATOR_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/concept/_detail/is_legacy_input_iterator.hpp>
#include <odds_and_ends/static_introspection/is_convertible_to_cref_of.hpp>
#include <odds_and_ends/static_introspection/declref.hpp>
#include <odds_and_ends/static_introspection/iterator_reference_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_legacy_forward_iterator_uq_impl :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::is_convertible_to_cref_of<
                decltype(::odds_and_ends::static_introspection::declmref<T>()++),
                T
            >,
            ::boost::mpl::if_<
                ::std::is_same<
                    decltype(*::odds_and_ends::static_introspection::declmref<T>()++),
                    typename ::odds_and_ends::static_introspection
                    ::iterator_reference_of<T>::type
                >,
                ::odds_and_ends::static_introspection
                ::concept::_detail::is_legacy_iterator_uq<T>,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/concept/_detail/has_post_increment_operator.hpp>
#include <odds_and_ends/static_introspection/iterator_value_of.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_legacy_forward_iterator_uq :
/*
        ::boost::mpl::eval_if<
            ::std::is_same<
                typename ::odds_and_ends::static_introspection
                ::iterator_reference_of<T const>::type,
                typename ::std::add_lvalue_reference<
                    typename ::std::add_const<
                        typename ::odds_and_ends::static_introspection
                        ::iterator_value_of<T>::type
                    >::type
                >::type
            >,
            ::boost::mpl::eval_if<
                ::std::is_same<
                    typename ::odds_and_ends::static_introspection
                    ::iterator_reference_of<T>::type,
                    typename ::std::add_lvalue_reference<
                        typename ::odds_and_ends::static_introspection
                        ::iterator_value_of<T>::type
                    >::type
                >,
*/
                ::boost::mpl::if_<
                    typename ::odds_and_ends::static_introspection::concept
                    ::_detail::has_post_increment_operator<T>::type,
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::is_legacy_forward_iterator_uq_impl<T>,
                    ::boost::mpl::false_
/*
                >,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
*/
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_LEGACY_FORWARD_ITERATOR_HPP

