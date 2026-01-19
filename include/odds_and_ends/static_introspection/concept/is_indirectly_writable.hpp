// Copyright (C) 2025-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_INDIRECTLY_WRITABLE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_INDIRECTLY_WRITABLE_HPP

#include <type_traits>
#include <utility>
#include <odds_and_ends/static_introspection/declref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename U>
    class has_indirect_write_expr
    {
        template <typename B, typename V>
        static ::boost::type_traits::yes_type
            _check0(
                typename ::std::add_pointer<
                    decltype(
                        *::odds_and_ends::static_introspection::declmref<B>() =
                        ::std::forward<V>(::std::declval<V>())
                    )
                >::type
            );

        template <typename B, typename V>
        static ::boost::type_traits::no_type _check0(...);

        template <typename B, typename V>
        static ::boost::type_traits::yes_type
            _check1(
                typename ::std::add_pointer<
                    decltype(
                        *::std::forward<B>(::std::declval<B>()) =
                        ::std::forward<V>(::std::declval<V>())
                    )
                >::type
            );

        template <typename B, typename V>
        static ::boost::type_traits::no_type _check1(...);

        template <typename B, typename V>
        static ::boost::type_traits::yes_type
            _check2(
                typename ::std::add_pointer<
                    decltype(
                        const_cast<
                            decltype(*::std::declval<B&>()) const&&
                        >(*::odds_and_ends::static_introspection::declmref<B>()) =
                        ::std::forward<V>(::std::declval<V>())
                    )
                >::type
            );

        template <typename B, typename V>
        static ::boost::type_traits::no_type _check2(...);

        template <typename B, typename V>
        static ::boost::type_traits::yes_type
            _check3(
                typename ::std::add_pointer<
                    decltype(
                        const_cast<
                            decltype(*::std::declval<B&>()) const&&
                        >(*::std::forward<B>(::std::declval<B>())) =
                        ::std::forward<V>(::std::declval<V>())
                    )
                >::type
            );

        template <typename B, typename V>
        static ::boost::type_traits::no_type _check3(...);

    public:
        typedef ::boost::mpl::bool_<
            (
                sizeof(
                    ::odds_and_ends::static_introspection::concept::_detail
                    ::has_indirect_write_expr<T,U>::template _check0<T,U>(nullptr)
                ) == sizeof(::boost::type_traits::yes_type)
            ) && (
                sizeof(
                    ::odds_and_ends::static_introspection::concept::_detail
                    ::has_indirect_write_expr<T,U>::template _check1<T,U>(nullptr)
                ) == sizeof(::boost::type_traits::yes_type)
            ) && (
                sizeof(
                    ::odds_and_ends::static_introspection::concept::_detail
                    ::has_indirect_write_expr<T,U>::template _check2<T,U>(nullptr)
                ) == sizeof(::boost::type_traits::yes_type)
            ) && (
                sizeof(
                    ::odds_and_ends::static_introspection::concept::_detail
                    ::has_indirect_write_expr<T,U>::template _check3<T,U>(nullptr)
                ) == sizeof(::boost::type_traits::yes_type)
            )
        > type;
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename Value>
    struct is_indirectly_writable_impl :
        ::boost::mpl::eval_if<
            ::std::is_void<
                decltype(
                    *::odds_and_ends::static_introspection::declmref<T>() =
                    ::std::forward<Value>(::std::declval<Value>())
                )
            >,
            ::boost::mpl::false_,
            ::boost::mpl::eval_if<
                ::std::is_void<
                    decltype(
                        *::std::forward<T>(::std::declval<T>()) =
                        ::std::forward<Value>(::std::declval<Value>())
                    )
                >,
                ::boost::mpl::false_,
                ::boost::mpl::eval_if<
                    ::std::is_void<
                        decltype(
                            const_cast<
                                decltype(*::std::declval<T&>()) const&&
                            >(*::odds_and_ends::static_introspection::declmref<T>()) =
                            ::std::forward<Value>(::std::declval<Value>())
                        )
                    >,
                    ::boost::mpl::false_,
                    ::boost::mpl::if_<
                        ::std::is_void<
                            decltype(
                                const_cast<
                                    decltype(*::std::declval<T&>()) const&&
                                >(*::std::forward<T>(::std::declval<T>())) =
                                ::std::forward<Value>(::std::declval<Value>())
                            )
                        >,
                        ::boost::mpl::false_,
                        ::boost::mpl::true_
                    >
                >
            >
        >
    {
    };

    template <typename T, typename Value>
    struct is_indirectly_writable :
        ::boost::mpl::if_<
            typename ::odds_and_ends::static_introspection
            ::concept::_detail::has_indirect_write_expr<T,Value>::type,
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_indirectly_writable_impl<T,Value>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename Value>
    struct is_indirectly_writable :
        ::odds_and_ends::static_introspection::concept::_detail::is_indirectly_writable<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type,
            typename ::odds_and_ends::static_introspection::remove_cvref<Value>::type
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_INDIRECTLY_WRITABLE_HPP

