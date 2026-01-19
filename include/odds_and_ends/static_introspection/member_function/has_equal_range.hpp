// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_EQUAL_RANGE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_EQUAL_RANGE_HPP

#include <utility>
#include <odds_and_ends/static_introspection/declref.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct has_equal_range_impl :
        ::boost::mpl::apply1<
            ResultPlaceholderExpr,
            decltype(
                ::odds_and_ends::static_introspection::declref<T>().equal_range(
                    ::std::declval<Param>()
                )
            )
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection/concept/_detail/is_range_or_pair.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/has_minimal_range_members.hpp>
#include <odds_and_ends/static_introspection/nested_type/is_iterator_of.hpp>
#include <odds_and_ends/use_default_policy.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/always.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename Param>
    struct has_equal_range_impl<T,Param,::odds_and_ends::use_default_policy> :
        ::odds_and_ends::static_introspection::concept::_detail::is_range_or_pair<
            decltype(
                ::odds_and_ends::static_introspection::declref<T>().equal_range(
                    ::std::declval<Param>()
                )
            ),
            ::odds_and_ends::static_introspection::nested_type::is_iterator_of< ::boost::mpl::_,T>,
            ::boost::mpl::always< ::boost::mpl::true_>,
            ::odds_and_ends::static_introspection::concept::_detail::has_minimal_range_members
        >
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <type_traits>
#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename Param>
    class has_equal_range_expr
    {
        template <typename B, typename P>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(
                        ::odds_and_ends::static_introspection::declref<B>().equal_range(
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
                ::has_equal_range_expr<T,Param>::template _check<T,Param>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct has_equal_range :
        ::boost::mpl::if_<
            typename ::odds_and_ends::static_introspection::member_function
            ::_detail::has_equal_range_expr<T,Param>::type,
            ::odds_and_ends::static_introspection::member_function::_detail
            ::has_equal_range_impl<T,Param,ResultPlaceholderExpr>,
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
    struct has_equal_range_with_default_param :
        ::odds_and_ends::static_introspection::member_function::_detail::has_equal_range<
            T,
            typename ::odds_and_ends::static_introspection::nested_type::key_type_of<T>::type,
            ResultPlaceholderExpr
        >
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection/nested_type/has_key_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_equal_range<T,::odds_and_ends::use_default_policy,ResultPlaceholderExpr> :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::nested_type::has_key_type<T>,
            ::odds_and_ends::static_introspection::member_function::_detail
            ::has_equal_range_with_default_param<T,ResultPlaceholderExpr>,
            ::boost::mpl::false_
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection_fwd.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct has_equal_range :
        ::odds_and_ends::static_introspection::member_function
        ::_detail::has_equal_range<T,Param,ResultPlaceholderExpr>
    {
    };
}}}  // namespace odds_and_ends::static_introspection::member_function

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_EQUAL_RANGE_HPP

