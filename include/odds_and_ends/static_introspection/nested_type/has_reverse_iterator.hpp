// Copyright (C) 2011-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__HAS_REVERSE_ITERATOR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__HAS_REVERSE_ITERATOR_HPP

#include <boost/mpl/aux_/has_type.hpp>
#include <boost/range/reverse_iterator.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    template <typename T>
    struct has_range_reverse_iterator :
        ::boost::mpl::aux::has_type< ::boost::range_reverse_iterator<T> >
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#include <type_traits>
#include <odds_and_ends/static_introspection/nested_type/_detail/has_reverse_iterator_member.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    template <typename T>
    struct has_reverse_iterator :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::nested_type
            ::_detail::has_range_reverse_iterator<T>,
            ::boost::mpl::true_,
            ::boost::mpl::if_<
                ::std::is_const<T>,
                ::odds_and_ends::static_introspection::nested_type
                ::_detail::has_const_reverse_iterator_member<T>,
                ::odds_and_ends::static_introspection::nested_type
                ::_detail::has_mutable_reverse_iterator_member<T>
            >
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/remove_vref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {

    template <typename T>
    struct has_reverse_iterator :
        ::odds_and_ends::static_introspection::nested_type::_detail::has_reverse_iterator<
            typename ::odds_and_ends::static_introspection::remove_vref<T>::type
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::nested_type

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__HAS_REVERSE_ITERATOR_HPP

