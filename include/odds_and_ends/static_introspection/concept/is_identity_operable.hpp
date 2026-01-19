// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_IDENTITY_OPERABLE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_IDENTITY_OPERABLE_HPP

#include <type_traits>
#include <utility>
#include <odds_and_ends/static_introspection/remove_vref.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename ResultPlaceholderExpr>
    struct is_identity_operable_impl :
        ::boost::mpl::apply1<
            ResultPlaceholderExpr,
            decltype(
                +::std::declval<
                    typename ::std::add_const<
                        typename ::odds_and_ends::static_introspection::remove_vref<T>::type
                    >::type
                >()
            )
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <boost/mpl/bool.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    class is_identity_operable
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check(typename ::std::add_pointer<decltype(+::std::declval<B>())>::type);

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::concept::_detail
                ::is_identity_operable<T>::template _check<T>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/is_convertible_to_cref_of.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename ResultPlaceholderExpr>
    struct is_identity_operable :
        ::boost::mpl::if_<
            typename ::odds_and_ends::static_introspection
            ::concept::_detail::is_identity_operable<
                typename ::std::add_const<
                    typename ::odds_and_ends::static_introspection::remove_vref<T>::type
                >::type
            >::type,
            ::odds_and_ends::static_introspection::concept::_detail
            ::is_identity_operable_impl<T,ResultPlaceholderExpr>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_IDENTITY_OPERABLE_HPP

