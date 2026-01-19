// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_DATA__HAS_DIMENSIONALITY_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_DATA__HAS_DIMENSIONALITY_HPP

#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_data {
namespace _detail {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_dimensionality_impl :
        ::boost::mpl::apply1<ResultPlaceholderExpr,decltype(T::dimensionality)>::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_data

#include <type_traits>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_data {
namespace _detail {

    template <typename T>
    class has_dimensionality_expr
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check(typename ::std::add_pointer<decltype(B::dimensionality)>::type);

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::member_data
                ::_detail::has_dimensionality_expr<T>::_check<T>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_data

#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_data {
namespace _detail {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_dimensionality :
        ::boost::mpl::if_<
            typename ::odds_and_ends::static_introspection
            ::member_data::_detail::has_dimensionality_expr<T>::type,
            ::odds_and_ends::static_introspection::member_data::_detail
            ::has_dimensionality_impl<T,ResultPlaceholderExpr>,
            ::boost::mpl::false_
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_data

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/nested_type/is_size_type_of.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_data {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_dimensionality :
        ::odds_and_ends::static_introspection::member_data::_detail::has_dimensionality<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type,
            ResultPlaceholderExpr
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::member_data

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_DATA__HAS_DIMENSIONALITY_HPP

