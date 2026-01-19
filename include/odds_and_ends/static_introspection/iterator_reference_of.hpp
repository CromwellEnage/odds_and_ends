// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__ITERATOR_REFERENCE_OF_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__ITERATOR_REFERENCE_OF_HPP

#include <utility>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct iterator_reference_of_impl
    {
        typedef decltype(*::std::declval<T&>()) type;
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/type_erasure/is_placeholder.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct iterator_reference_of :
        ::boost::mpl::eval_if<
            ::boost::type_erasure::is_placeholder<T>,
            ::boost::mpl::identity<void>,
            ::odds_and_ends::static_introspection::_detail::iterator_reference_of_impl<T>
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T>
    struct iterator_reference_of :
        ::odds_and_ends::static_introspection::_detail::iterator_reference_of<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type
        >
    {
    };
}}  // namespace odds_and_ends::static_introspection

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__ITERATOR_REFERENCE_OF_HPP

