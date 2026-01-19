// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_GET_START_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_GET_START_HPP

#include <utility>
#include <odds_and_ends/static_introspection/declref.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct has_get_start_impl :
        ::boost::mpl::apply1<
            ResultPlaceholderExpr,
            decltype(
                ::odds_and_ends::static_introspection::declcref<T>().get_start(
                    ::std::declval<Param>()
                )
            )
        >
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/use_default_policy.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_get_start_impl<T,::odds_and_ends::use_default_policy,ResultPlaceholderExpr> :
        ::boost::mpl::apply1<
            ResultPlaceholderExpr,
            decltype(
                ::odds_and_ends::static_introspection::declcref<T>().get_start(
                    ::std::declval<typename T::index>()
                )
            )
        >
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <boost/mpl/bool.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename Param>
    class has_get_start_expr
    {
        template <typename B, typename P>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(
                        ::odds_and_ends::static_introspection::declcref<B>().get_start(
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
                ::odds_and_ends::static_introspection::member_function::_detail
                ::has_get_start_expr<T,Param>::_check<T,Param>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct has_get_start :
        ::boost::mpl::eval_if<
            typename ::odds_and_ends::static_introspection
            ::member_function::_detail::has_get_start_expr<T,Param>::type,
            ::odds_and_ends::static_introspection::member_function
            ::_detail::has_get_start_impl<T,Param,ResultPlaceholderExpr>,
            ::boost::mpl::false_
        >
    {
    };

    template <typename T, typename ResultPlaceholderExpr>
    struct has_get_start_default :
        ::odds_and_ends::static_introspection::member_function::_detail
        ::has_get_start<T,typename T::index,ResultPlaceholderExpr>
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection/nested_type/has_index.hpp>
#include <odds_and_ends/use_default_policy.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_get_start<T,::odds_and_ends::use_default_policy,ResultPlaceholderExpr> :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::nested_type::has_index<T>,
            ::odds_and_ends::static_introspection::member_function::_detail
            ::has_get_start_default<T,ResultPlaceholderExpr>,
            ::boost::mpl::false_
        >
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/nested_type/is_index_of.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct has_get_start :
        ::odds_and_ends::static_introspection::member_function::_detail::has_get_start<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type,
            Param,
            ResultPlaceholderExpr
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::member_function

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_GET_START_HPP

