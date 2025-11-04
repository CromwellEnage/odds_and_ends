// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_SUBSCRIPTABLE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_SUBSCRIPTABLE_HPP

#include <utility>
#include <odds_and_ends/static_introspection/declref.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename Subscript, typename ResultPlaceholderExpr>
    struct is_subscriptable_impl :
        ::boost::mpl::apply1<
            ResultPlaceholderExpr,
            decltype(
                ::odds_and_ends::static_introspection::declref<T>()[::std::declval<Subscript>()]
            )
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <type_traits>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename Subscript>
    class has_subscript_operator
    {
        template <typename B, typename S>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(
                        ::odds_and_ends::static_introspection::declref<B>()[::std::declval<S>()]
                    )
                >::type
            );

        template <typename B, typename S>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::concept::_detail
                ::has_subscript_operator<T,Subscript>::template _check<T,Subscript>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename Subscript, typename ResultPlaceholderExpr>
    struct is_subscriptable :
        ::boost::mpl::if_<
            typename ::odds_and_ends::static_introspection::concept
            ::_detail::has_subscript_operator<T,Subscript>::type,
            ::odds_and_ends::static_introspection::concept::_detail
            ::is_subscriptable_impl<T,Subscript,ResultPlaceholderExpr>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <boost/ptr_container/ptr_list.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename C, typename A, typename Subscript, typename ResultPlaceholderExpr>
    struct is_subscriptable< ::boost::ptr_list<T,C,A>,Subscript,ResultPlaceholderExpr> :
        ::boost::mpl::false_
    {
    };

    template <typename T, typename C, typename A, typename Subscript, typename ResultPlaceholderExpr>
    struct is_subscriptable< ::boost::ptr_list<T,C,A> const,Subscript,ResultPlaceholderExpr> :
        ::boost::mpl::false_
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/is_lvalue_reference_of.hpp>
#include <odds_and_ends/static_introspection/remove_vref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename Subscript, typename ResultPlaceholderExpr>
    struct is_subscriptable :
        ::odds_and_ends::static_introspection::concept::_detail::is_subscriptable<
            typename ::odds_and_ends::static_introspection::remove_vref<T>::type,
            Subscript,
            ResultPlaceholderExpr
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_SUBSCRIPTABLE_HPP

