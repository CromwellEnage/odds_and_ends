// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__IS_ITERATOR_VALUE_OF_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__IS_ITERATOR_VALUE_OF_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/iterator_value_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T1, typename T2>
    struct is_iterator_value_of :
        ::boost::mpl::if_<
            ::std::is_same<
                typename ::odds_and_ends::static_introspection::iterator_value_of<T2>::type,
                T1
            >,
            ::boost::mpl::true_,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/has_iterator_value.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T1, typename T2>
    struct is_iterator_value_of :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::has_iterator_value<T2>,
            ::odds_and_ends::static_introspection::_detail::is_iterator_value_of<T1,T2>,
            ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace odds_and_ends::static_introspection

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__IS_ITERATOR_VALUE_OF_HPP

