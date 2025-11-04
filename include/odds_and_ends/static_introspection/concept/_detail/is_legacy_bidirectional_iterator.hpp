// Copyright (C) 2012-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_LEGACY_BIDIRECTIONAL_ITERATOR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_LEGACY_BIDIRECTIONAL_ITERATOR_HPP

#include <odds_and_ends/static_introspection/concept/_detail/is_legacy_forward_iterator.hpp>
#include <odds_and_ends/static_introspection/concept/is_decrementable.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_legacy_bidirectional_iterator_q :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::concept::is_decrementable<T>,
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_legacy_input_iterator_q<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <type_traits>
#include <odds_and_ends/static_introspection/is_convertible_to_cref_of.hpp>
#include <odds_and_ends/static_introspection/iterator_reference_of.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_legacy_bidirectional_iterator_uq :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::is_convertible_to_cref_of<
                decltype(::odds_and_ends::static_introspection::declmref<T>()--),
                T
            >,
            ::boost::mpl::if_<
                ::std::is_same<
                    decltype(*::odds_and_ends::static_introspection::declmref<T>()--),
                    typename ::odds_and_ends::static_introspection::iterator_reference_of<T>::type
                >,
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_legacy_forward_iterator_uq<T>,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif
// ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_LEGACY_BIDIRECTIONAL_ITERATOR_HPP

