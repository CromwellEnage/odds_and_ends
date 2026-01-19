// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_FORWARD_TRAVERSAL_ITERATOR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_FORWARD_TRAVERSAL_ITERATOR_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/declref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_forward_traversal_iterator_impl
    {
        typedef typename ::boost::mpl::eval_if<
            ::std::is_same<
                decltype(++::odds_and_ends::static_introspection::declref<T>()),
                typename ::std::add_lvalue_reference<T>::type
            >,
            ::boost::mpl::if_<
                ::std::is_default_constructible<T>,
                ::boost::mpl::true_,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type type;
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/remove_cvref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_forward_traversal_iterator
    {
        typedef typename ::odds_and_ends::static_introspection
        ::concept::_detail::is_forward_traversal_iterator_impl<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type
        >::type type;
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/is_single_pass_iterator.hpp>
#include <odds_and_ends/static_introspection/is_iterator_traversal_of.hpp>
#include <boost/iterator/iterator_categories.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_forward_traversal_iterator :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::is_single_pass_iterator<T>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::is_iterator_traversal_of<
                    ::boost::iterators::forward_traversal_tag,
                    T
                >,
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_forward_traversal_iterator<T>,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_FORWARD_TRAVERSAL_ITERATOR_HPP

