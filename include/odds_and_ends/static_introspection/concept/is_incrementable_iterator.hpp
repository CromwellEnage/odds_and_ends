// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_INCREMENTABLE_ITERATOR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_INCREMENTABLE_ITERATOR_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection_fwd.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_incrementable_iterator_ext :
        ::boost::mpl::if_<
            ::std::is_copy_constructible<T>,
            ::boost::mpl::true_/*::std::is_copy_assignable<T>*/,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#include <odds_and_ends/static_introspection/concept/is_incrementable.hpp>
#include <odds_and_ends/static_introspection/is_iterator_traversal_of.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <boost/iterator/iterator_categories.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_incrementable_iterator :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::is_incrementable_iterator_ext<
                typename ::odds_and_ends::static_introspection::remove_cvref<T>::type
            >,
            ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::concept::is_incrementable<T>,
                ::odds_and_ends::static_introspection::is_iterator_traversal_of<
                    ::boost::iterators::incrementable_traversal_tag,
                    T
                >,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#include <boost/iterator/function_input_iterator.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename F, typename S>
    struct is_incrementable_iterator_ext<
        ::boost::iterators::function_input_iterator<F,S>
    > : ::odds_and_ends::static_introspection::concept::is_incrementable<S>
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_INCREMENTABLE_ITERATOR_HPP

