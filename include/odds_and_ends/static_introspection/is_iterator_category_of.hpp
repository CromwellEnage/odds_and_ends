// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__IS_ITERATOR_CATEGORY_OF_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__IS_ITERATOR_CATEGORY_OF_HPP

#include <odds_and_ends/static_introspection/iterator_category_of.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <type_traits>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T, typename Category>
    struct is_iterator_with_category :
        ::boost::mpl::if_<
            ::std::is_convertible<
                typename ::odds_and_ends::static_introspection::iterator_category_of<T>::type,
                typename ::odds_and_ends::static_introspection::remove_cvref<Category>::type
            >,
            ::boost::mpl::true_,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_iterator_category.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T1, typename T2>
    struct is_iterator_category_of :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::nested_type::has_iterator_category<T2>,
            ::odds_and_ends::static_introspection::_detail::is_iterator_with_category<T2,T1>,
            ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace odds_and_ends::static_introspection

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__IS_ITERATOR_CATEGORY_OF_HPP

