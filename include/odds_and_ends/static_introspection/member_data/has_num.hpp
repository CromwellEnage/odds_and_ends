// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_DATA__HAS_NUM_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_DATA__HAS_NUM_HPP

#include <type_traits>
#include <cstdint>
#include <odds_and_ends/use_default_policy.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_data {
namespace _detail {

    template <typename T, typename PlaceholderExpr>
    struct has_num_impl1 :
        ::boost::mpl::eval_if<
            ::std::is_same<PlaceholderExpr,::odds_and_ends::use_default_policy>,
            ::boost::mpl::if_<
                ::std::is_convertible<T,::std::intmax_t>,
                ::boost::mpl::true_,
                ::boost::mpl::false_
            >,
            ::boost::mpl::apply1<PlaceholderExpr,T>
        >::type
    {
    };

    template <typename T, typename PlaceholderExpr>
    struct has_num_impl0 :
        ::odds_and_ends::static_introspection::member_data::_detail::has_num_impl1<
            typename ::std::remove_const<decltype(T::num)>::type,
            PlaceholderExpr
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_data

#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_data {
namespace _detail {

    template <typename T>
    class has_num_expr
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check(typename ::std::add_pointer<decltype(B::num)>::type);

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::member_data
                ::_detail::has_num_expr<T>::template _check<T>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };

    template <typename T, typename PlaceholderExpr>
    struct has_num :
        ::boost::mpl::eval_if<
            typename ::odds_and_ends::static_introspection
            ::member_data::_detail::has_num_expr<T>::type,
            ::odds_and_ends::static_introspection::member_data
            ::_detail::has_num_impl0<T,PlaceholderExpr>,
            ::boost::mpl::false_
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_data

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_data {

    template <typename T, typename PlaceholderExpr>
    struct has_num :
        ::odds_and_ends::static_introspection::member_data::_detail::has_num<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type,
            PlaceholderExpr
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::member_data

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_DATA__HAS_NUM_HPP

