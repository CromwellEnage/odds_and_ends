// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_FINISH_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_FINISH_HPP

#include <utility>
#include <odds_and_ends/static_introspection/declref.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct has_finish_impl :
        ::boost::mpl::apply1<
            ResultPlaceholderExpr,
            decltype(
                ::odds_and_ends::static_introspection::declmref<T>().finish(
                    ::std::declval<Param>()
                )
            )
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/use_default_policy.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_finish_impl<T,::odds_and_ends::use_default_policy,ResultPlaceholderExpr> :
        ::boost::mpl::apply1<
            ResultPlaceholderExpr,
            decltype(::odds_and_ends::static_introspection::declcref<T>().finish())
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection/is_lvalue_reference_of.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename Param>
    struct has_finish_impl<T,Param,::odds_and_ends::use_default_policy> :
        ::odds_and_ends::static_introspection::is_lvalue_reference_of<
            decltype(
                ::odds_and_ends::static_introspection::declmref<T>().finish(
                    ::std::declval<Param>()
                )
            ),
            T
        >
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection/nested_type/is_index_of.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T>
    struct has_finish_impl<
        T,
        ::odds_and_ends::use_default_policy,
        ::odds_and_ends::use_default_policy
    > : ::odds_and_ends::static_introspection::nested_type::is_index_of<
            decltype(::odds_and_ends::static_introspection::declcref<T>().finish()),
            T
        >
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <type_traits>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename Param>
    class has_finish_expr
    {
        template <typename B, typename P>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(
                        ::odds_and_ends::static_introspection::declmref<B>().finish(
                            ::std::declval<P>()
                        )
                    )
                >::type
            );

        template <typename B, typename P>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::member_function
                ::_detail::has_finish_expr<T,Param>::_check<T,Param>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };

    template <typename T>
    class has_finish_expr<T,::odds_and_ends::use_default_policy>
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(::odds_and_ends::static_introspection::declcref<B>().finish())
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::member_function::_detail
                ::has_finish_expr<T,::odds_and_ends::use_default_policy>::_check<T>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct has_finish :
        ::boost::mpl::if_<
            typename ::odds_and_ends::static_introspection
            ::member_function::_detail::has_finish_expr<T,Param>::type,
            ::odds_and_ends::static_introspection::member_function
            ::_detail::has_finish_impl<T,Param,ResultPlaceholderExpr>,
            ::boost::mpl::false_
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct has_finish :
        ::odds_and_ends::static_introspection::member_function::_detail::has_finish<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type,
            Param,
            ResultPlaceholderExpr
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::member_function

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_FINISH_HPP

