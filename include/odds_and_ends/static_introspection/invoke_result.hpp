// Based on "possible implementation code" from
// <https://en.cppreference.com/w/cpp/types/result_of.html>

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__INVOKE_RESULT_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__INVOKE_RESULT_HPP

#include <utility>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct invoke_impl
    {
        template <typename F, typename ...Args>
        static auto eval(F&& f, Args&&... args)
            -> decltype(::std::forward<F>(f)(::std::forward<Args>(args)...));
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <type_traits>
#include <functional>
#include <boost/core/enable_if.hpp>
#include <odds_and_ends/static_introspection/is_reference_wrapper.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename C, typename R>
    struct invoke_impl<R C::*>
    {
        template <
            typename T,
            typename D = typename ::std::decay<T>::type,
            typename = typename ::boost::enable_if< ::std::is_base_of<C,D> >::type
        >
        static auto get(T&&) -> T&&;

        template <
            typename T,
            typename D = typename ::std::decay<T>::type,
            typename = typename ::boost::enable_if<
                ::odds_and_ends::static_introspection::is_reference_wrapper<D>
            >::type
        >
        static auto get(T&& t) -> decltype(t.get());

        template <
            typename T,
            typename D = typename ::std::decay<T>::type,
            typename = typename ::boost::disable_if< ::std::is_base_of<C,D> >::type,
            typename = typename ::boost::disable_if<
                ::odds_and_ends::static_introspection::is_reference_wrapper<D>
            >::type
        >
        static auto get(T&& t) -> decltype(*::std::forward<T>(t));

        template <
            typename T,
            typename ...Args,
            typename F,
            typename = typename ::boost::enable_if< ::std::is_function<F> >::type
        >
        static auto eval(F C::*pmf, T&& t, Args&&... args)
            -> decltype(
                (
                    ::odds_and_ends::static_introspection::_detail
                    ::invoke_impl<R C::*>::get(::std::forward<T>(t)).*pmf
                )(::std::forward<Args>(args)...)
            );

        template <typename T>
        static auto eval(R C::*pmd, T&& t)
            -> decltype(
                ::odds_and_ends::static_introspection::_detail
                ::invoke_impl<R C::*>::get(::std::forward<T>(t)).*pmd
            );
    };

    template <
        typename F,
        typename ...Args,
        typename D = typename ::std::decay<F>::type
    >
    auto invoke(F&& f, Args&&... args)
        -> decltype(
            ::odds_and_ends::static_introspection::_detail::invoke_impl<D>
            ::eval(::std::forward<F>(f), ::std::forward<Args>(args)...)
        );

    template <typename AlwaysVoid, typename, typename ...>
    struct invoke_result
    {
    };

    template <typename F, typename ...Args>
    struct invoke_result<
        decltype(
            void(
                ::odds_and_ends::static_introspection::_detail::invoke(
                    ::std::declval<F>(),
                    ::std::declval<Args>()...
                )
            )
        ),
        F,
        Args...
    >
    {
        using type = decltype(
            ::odds_and_ends::static_introspection::_detail::invoke(
                ::std::declval<F>(),
                ::std::declval<Args>()...
            )
        );
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename F, typename ...Args>
    struct invoke_result :
        ::odds_and_ends::static_introspection::_detail::invoke_result<void,F,Args...>
    {
    };
}}  // namespace odds_and_ends::static_introspection

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__INVOKE_RESULT_HPP

