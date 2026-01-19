// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__INDEX_OF_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__INDEX_OF_HPP

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    template <typename T>
    struct index_of_impl
    {
        typedef typename T::index type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#include <boost/type_erasure/is_placeholder.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    template <typename T>
    struct index_of :
        ::boost::mpl::eval_if<
            ::boost::type_erasure::is_placeholder<T>,
            ::boost::mpl::identity<void>,
            ::odds_and_ends::static_introspection::nested_type::_detail::index_of_impl<T>
        >
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {

    template <typename T>
    struct index_of :
        ::odds_and_ends::static_introspection::nested_type::_detail::index_of<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::nested_type

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__INDEX_OF_HPP

