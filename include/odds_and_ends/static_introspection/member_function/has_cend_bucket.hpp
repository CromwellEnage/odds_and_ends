// Copyright (C) 2016-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_CEND_BUCKET_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_CEND_BUCKET_HPP

#include <utility>
#include <odds_and_ends/static_introspection/declref.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct has_cend_bucket_impl :
        ::boost::mpl::apply1<
            ResultPlaceholderExpr,
            decltype(
                ::odds_and_ends::static_introspection::declcref<T>().cend(
                    ::std::declval<Param>()
                )
            )
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <type_traits>
#include <odds_and_ends/static_introspection/nested_type/is_local_iterator_of.hpp>
#include <odds_and_ends/static_introspection/remove_vref.hpp>
#include <odds_and_ends/use_default_policy.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename Param>
    struct has_cend_bucket_impl<T,Param,::odds_and_ends::use_default_policy> :
        ::odds_and_ends::static_introspection::nested_type::is_local_iterator_of<
            decltype(
                ::odds_and_ends::static_introspection::declcref<T>().cend(
                    ::std::declval<Param>()
                )
            ),
            typename ::std::add_const<
                typename ::odds_and_ends::static_introspection::remove_vref<T>::type
            >::type
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
    class has_cend_bucket_expr
    {
        template <typename B, typename P>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(
                        ::odds_and_ends::static_introspection::declcref<B>().cend(
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
                ::has_cend_bucket_expr<T,Param>::template _check<T,Param>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct has_cend_bucket :
        ::boost::mpl::if_<
            typename ::odds_and_ends::static_introspection::member_function
            ::_detail::has_cend_bucket_expr<T,Param>::type,
            ::odds_and_ends::static_introspection::member_function::_detail
            ::has_cend_bucket_impl<T,Param,ResultPlaceholderExpr>,
            ::boost::mpl::false_
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection/concept/_detail/has_pointer_container_nested_types.hpp>
#include <odds_and_ends/static_introspection/nested_type/size_type_of.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_cend_bucket_default :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::member_function::_detail::has_cend_bucket<
                T,
                typename ::odds_and_ends::static_introspection::nested_type::size_type_of<T>::type,
                ResultPlaceholderExpr
            >,
            ::boost::mpl::true_,
            ::odds_and_ends::static_introspection::concept
            ::_detail::has_pointer_container_nested_types<T>
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection/nested_type/has_size_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_cend_bucket<T,::odds_and_ends::use_default_policy,ResultPlaceholderExpr> :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::nested_type::has_size_type<T>,
            ::odds_and_ends::static_introspection::member_function
            ::_detail::has_cend_bucket_default<T,ResultPlaceholderExpr>,
            ::boost::mpl::false_
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection_fwd.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {

    template <typename T, typename Param, typename ResultPlaceholderExpr>
    struct has_cend_bucket :
        ::odds_and_ends::static_introspection::member_function
        ::_detail::has_cend_bucket<T,Param,ResultPlaceholderExpr>
    {
    };
}}}  // namespace odds_and_ends::static_introspection::member_function

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_CEND_BUCKET_HPP

