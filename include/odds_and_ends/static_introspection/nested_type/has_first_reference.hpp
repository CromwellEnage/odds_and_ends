// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__HAS_FIRST_REFERENCE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__HAS_FIRST_REFERENCE_HPP

#include <boost/mpl/has_xxx.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(has_first_reference_void_or_not, first_reference, false)

    BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(
        has_first_const_reference_void_or_not,
        first_const_reference,
        false
    )
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#include <type_traits>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    template <typename T>
    struct has_first_reference_non_void :
        ::boost::mpl::eval_if<
            ::std::is_void<typename T::first_reference>,
            ::boost::mpl::false_,
            ::boost::mpl::true_
        >
    {
    };

    template <typename T>
    struct has_first_reference_impl :
        ::boost::mpl::eval_if<
            typename ::odds_and_ends::static_introspection::nested_type
            ::_detail::has_first_reference_void_or_not<T>::type,
            ::odds_and_ends::static_introspection::nested_type
            ::_detail::has_first_reference_non_void<T>,
            ::boost::mpl::false_
        >
    {
    };

    template <typename T>
    struct has_first_const_reference_non_void :
        ::boost::mpl::eval_if<
            ::std::is_void<typename T::first_const_reference>,
            ::boost::mpl::false_,
            ::boost::mpl::true_
        >
    {
    };

    template <typename T>
    class has_first_const_reference_impl
    {
        typedef typename ::std::remove_const<T>::type _T_non_const;

    public:
        typedef typename ::boost::mpl::eval_if<
            typename ::odds_and_ends::static_introspection::nested_type
            ::_detail::has_first_const_reference_void_or_not<_T_non_const>::type,
            ::odds_and_ends::static_introspection::nested_type
            ::_detail::has_first_const_reference_non_void<_T_non_const>,
            ::boost::mpl::false_
        >::type type;
    };

    template <typename T>
    struct has_first_reference :
        ::boost::mpl::eval_if<
            ::std::is_const<T>,
            ::dds_and_ends::static_introspection::nested_type
            ::_detail::has_first_const_reference_impl<T>,
            ::dds_and_ends::static_introspection::nested_type
            ::_detail::has_first_reference_impl<T>
        >
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/remove_vref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {

    template <typename T>
    struct has_first_reference :
        ::odds_and_ends::static_introspection::nested_type::_detail::has_first_reference<
            typename ::odds_and_ends::static_introspection::remove_vref<T>::type
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::nested_type

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__HAS_FIRST_REFERENCE_HPP

