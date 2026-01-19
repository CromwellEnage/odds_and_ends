// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__IS_REVERSE_ITERATOR_OF_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__IS_REVERSE_ITERATOR_OF_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/nested_type/reverse_iterator_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    template <typename T1, typename T2>
    struct is_reverse_iterator_of_impl :
        ::boost::mpl::if_<
            ::std::is_same<
                typename ::odds_and_ends::static_introspection
                ::nested_type::reverse_iterator_of<T2>::type,
                T1
            >,
            ::boost::mpl::true_,
            ::boost::mpl::false_
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#include <odds_and_ends/static_introspection/nested_type/has_reverse_iterator.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    template <typename T1, typename T2>
    struct is_reverse_iterator_of :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::nested_type::has_reverse_iterator<T2>,
            ::odds_and_ends::static_introspection::nested_type
            ::_detail::is_reverse_iterator_of_impl<T1,T2>,
            ::boost::mpl::false_
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <odds_and_ends/static_introspection/remove_vref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {

    template <typename T1, typename T2>
    struct is_reverse_iterator_of :
        ::odds_and_ends::static_introspection::nested_type::_detail::is_reverse_iterator_of<
            typename ::odds_and_ends::static_introspection::remove_cvref<T1>::type,
            typename ::odds_and_ends::static_introspection::remove_vref<T2>::type
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::nested_type

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__IS_REVERSE_ITERATOR_OF_HPP

