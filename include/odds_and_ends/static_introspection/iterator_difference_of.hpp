// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__ITERATOR_DIFFERENCE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__ITERATOR_DIFFERENCE_HPP

#include <iterator>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct iterator_difference_of_impl
    {
        typedef typename ::std::iterator_traits<T>::difference_type type;
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <utility>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct iterator_difference_of_minus
    {
        typedef decltype(::std::declval<T>() - ::std::declval<T>()) type;
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection/nested_type/_detail/has_difference_type.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct iterator_difference_of :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::nested_type::_detail
            ::has_difference_type< ::std::iterator_traits<T> >,
            ::odds_and_ends::static_introspection
            ::_detail::iterator_difference_of_impl<T>,
            ::odds_and_ends::static_introspection
            ::_detail::iterator_difference_of_minus<T>
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/_detail/difference_of.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T>
    struct iterator_difference_of :
        ::odds_and_ends::static_introspection::_detail::difference_of<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type,
            ::odds_and_ends::static_introspection::_detail::iterator_difference_of
        >
    {
    };
}}  // namespace odds_and_ends::static_introspection

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__ITERATOR_DIFFERENCE_HPP

