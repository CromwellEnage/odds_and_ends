// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__IS_ITERATOR_TRAVERSAL_OF_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__IS_ITERATOR_TRAVERSAL_OF_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/iterator_traversal_of.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T1, typename T2>
    struct is_iterator_traversal_of :
        ::boost::mpl::if_<
            ::std::is_convertible<
                typename ::odds_and_ends::static_introspection::iterator_traversal_of<T2>::type,
                typename ::odds_and_ends::static_introspection::remove_cvref<T1>::type
            >,
            ::boost::mpl::true_,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_iterator_category.hpp>
#include <boost/iterator/iterator_categories.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T1, typename T2>
    struct is_iterator_traversal_of :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::nested_type::has_iterator_category<
                typename ::odds_and_ends::static_introspection::remove_cvref<T2>::type
            >,
            ::odds_and_ends::static_introspection::_detail::is_iterator_traversal_of<T1,T2>,
            ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace odds_and_ends::static_introspection

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__IS_ITERATOR_TRAVERSAL_OF_HPP

