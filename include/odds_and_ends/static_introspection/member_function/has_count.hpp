// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_COUNT_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_COUNT_HPP

#include <utility>
#include <odds_and_ends/static_introspection/declref.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct has_count_impl :
        ::boost::mpl::apply1<
            ResultPlaceholderExpr,
            decltype(
                ::odds_and_ends::static_introspection::declcref<T>().count(
                    ::std::declval<Param>()
                )
            )
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <type_traits>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename P>
    class has_count_expr
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(
                        ::odds_and_ends::static_introspection::declcref<B>().count(
                            ::std::declval<P>()
                        )
                    )
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::member_function
                ::_detail::has_count_expr<T,P>::template _check<T>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename P, typename ResultPlaceholderExpr>
    struct has_count :
        ::boost::mpl::if_<
            typename ::odds_and_ends::static_introspection
            ::member_function::_detail::has_count_expr<T,P>::type,
            ::odds_and_ends::static_introspection::member_function::_detail
            ::has_count_impl<T,P,ResultPlaceholderExpr>,
            ::boost::mpl::false_
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection/nested_type/key_type_of.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_count_default :
        ::odds_and_ends::static_introspection::member_function::_detail::has_count<
            T,
            typename ::odds_and_ends::static_introspection::nested_type::key_type_of<T>::type,
            ResultPlaceholderExpr
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection/nested_type/has_key_type.hpp>
#include <odds_and_ends/use_default_policy.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_count<T,::odds_and_ends::use_default_policy,ResultPlaceholderExpr> :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::nested_type::has_key_type<T>,
            ::odds_and_ends::static_introspection::member_function
            ::_detail::has_count_default<T,ResultPlaceholderExpr>,
            ::boost::mpl::false_
        >
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/nested_type/is_size_type_of.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct has_count :
        ::odds_and_ends::static_introspection::member_function
        ::_detail::has_count<T,Param,ResultPlaceholderExpr>::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::member_function

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_COUNT_HPP

