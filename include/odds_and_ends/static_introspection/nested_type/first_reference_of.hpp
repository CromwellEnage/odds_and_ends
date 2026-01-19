// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__FIRST_REFERENCE_OF_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__FIRST_REFERENCE_OF_HPP

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    template <typename T>
    struct first_reference_of_impl
    {
        typedef typename T::first_reference type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#include <type_traits>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    template <typename T>
    struct first_const_reference_of_impl
    {
        typedef typename ::std::remove_const<T>::type::first_const_reference type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#include <boost/type_erasure/is_placeholder.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    template <typename T>
    struct first_const_reference_of :
        ::boost::mpl::eval_if<
            ::boost::type_erasure::is_placeholder<typename ::std::remove_const<T>::type>,
            ::boost::mpl::identity<void>,
            ::odds_and_ends::static_introspection::nested_type
            ::_detail::first_const_reference_of_impl<T>
        >
    {
    };

    template <typename T>
    struct first_reference_of :
        ::boost::mpl::eval_if<
            ::std::is_const<T>,
            ::odds_and_ends::static_introspection
            ::nested_type::_detail::first_const_reference_of<T>,
            ::boost::mpl::eval_if<
                ::boost::type_erasure::is_placeholder<T>,
                ::boost::mpl::identity<void>,
                ::odds_and_ends::static_introspection
                ::nested_type::_detail::first_reference_of_impl<T>
            >
        >
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/remove_vref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {

    template <typename T>
    struct first_reference_of :
        ::odds_and_ends::static_introspection::nested_type::_detail::first_reference_of<
            typename ::odds_and_ends::static_introspection::remove_vref<T>::type
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::nested_type

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__FIRST_REFERENCE_OF_HPP

