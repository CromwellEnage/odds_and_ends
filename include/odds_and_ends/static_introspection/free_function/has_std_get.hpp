// Copyright (C) 2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__FREE_FUNCTION__HAS_STD_GET_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__FREE_FUNCTION__HAS_STD_GET_HPP

#include <cstddef>
#include <tuple>
#include <type_traits>
#include <utility>
#include <odds_and_ends/static_introspection/declref.hpp>
#include <odds_and_ends/static_introspection/is_lvalue_reference_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace free_function {
namespace _detail {

    template <typename T, ::std::size_t I>
    struct has_std_get_impl :
        ::boost::mpl::if_<
            ::std::is_same<
                decltype(::std::get<I>(::odds_and_ends::static_introspection::declref<T>())),
                typename ::std::add_lvalue_reference<
                    typename ::std::tuple_element<I,T>::type
                >::type
            >,
            ::boost::mpl::true_,
            ::boost::mpl::false_
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::free_function

#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace free_function {
namespace _detail {

    template <typename T, ::std::size_t I>
    class has_std_get_expr
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(::std::get<I>(::odds_and_ends::static_introspection::declref<B>()))
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::free_function::_detail
                ::has_std_get_expr<T,I>::template _check<T>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::free_function

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/aux_/has_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace free_function {
namespace _detail {

    template <typename T, ::std::size_t I>
    struct has_std_get :
        ::boost::mpl::eval_if<
            typename ::boost::mpl::eval_if<
                typename ::odds_and_ends::static_introspection
                ::free_function::_detail::has_std_get_expr<T,I>::type,
                ::boost::mpl::aux::has_type< ::std::tuple_element<I,T> >,
                ::boost::mpl::false_
            >::type,
            ::odds_and_ends::static_introspection::free_function::_detail::has_std_get_impl<T,I>,
            ::boost::mpl::false_
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::free_function

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/remove_vref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace free_function {

    template <typename T, ::std::size_t I>
    struct has_std_get :
        ::odds_and_ends::static_introspection::free_function::_detail::has_std_get<
            typename ::odds_and_ends::static_introspection::remove_vref<T>::type,
            I
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::free_function

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__FREE_FUNCTION__HAS_STD_GET_HPP

