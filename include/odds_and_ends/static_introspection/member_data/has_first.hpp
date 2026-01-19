// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_DATA__HAS_FIRST_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_DATA__HAS_FIRST_HPP

#include <odds_and_ends/static_introspection/declref.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_data {
namespace _detail {

    template <typename T, typename PlaceholderExpr>
    struct has_first_impl :
        ::boost::mpl::apply1<
            PlaceholderExpr,
            decltype(::odds_and_ends::static_introspection::declref<T>().first)
        >::type
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
    class has_first
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(::odds_and_ends::static_introspection::declref<B>().first)
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::member_data
                ::_detail::has_first<T>::template _check<T>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_data

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/nested_type/is_first_type_of.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_data {

    template <typename T, typename PlaceholderExpr>
    struct has_first :
        ::boost::mpl::if_<
            typename ::odds_and_ends::static_introspection
            ::member_data::_detail::has_first<T>::type,
            ::odds_and_ends::static_introspection::member_data
            ::_detail::has_first_impl<T,PlaceholderExpr>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::member_data

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_DATA__HAS_FIRST_HPP

