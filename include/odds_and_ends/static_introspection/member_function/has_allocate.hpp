// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_ALLOCATE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_ALLOCATE_HPP

#include <utility>
#include <odds_and_ends/static_introspection/allocator_size_of.hpp>
#include <odds_and_ends/static_introspection/declref.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename U, typename ResultPlaceholderExpr>
    struct has_allocate_impl :
        ::boost::mpl::apply1<
            ResultPlaceholderExpr,
            decltype(
                ::odds_and_ends::static_introspection::declref<T>().allocate(
                    ::std::declval<
                        typename ::odds_and_ends::static_introspection::allocator_size_of<T>::type
                    >(),
                    ::std::declval<U>()
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
    struct has_allocate_impl<T,::odds_and_ends::use_default_policy,ResultPlaceholderExpr> :
        ::boost::mpl::apply1<
            ResultPlaceholderExpr,
            decltype(
                ::odds_and_ends::static_introspection::declref<T>().allocate(
                    ::std::declval<
                        typename ::odds_and_ends::static_introspection::allocator_size_of<T>::type
                    >()
                )
            )
        >
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <type_traits>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename U>
    class has_allocate_expr
    {
        template <typename B, typename V>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(
                        ::odds_and_ends::static_introspection::declref<B>().allocate(
                            ::std::declval<
                                typename ::odds_and_ends::static_introspection
                                ::allocator_size_of<B>::type
                            >(),
                            ::std::declval<V>()
                        )
                    )
                >::type
            );

        template <typename B, typename V>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::member_function::_detail
                ::has_allocate_expr<T,U>::template _check<T,U>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };

    template <typename T>
    class has_allocate_expr<T,::odds_and_ends::use_default_policy>
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(
                        ::odds_and_ends::static_introspection::declref<B>().allocate(
                            ::std::declval<
                                typename ::odds_and_ends::static_introspection
                                ::allocator_size_of<B>::type
                            >()
                        )
                    )
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::member_function::_detail
                ::has_allocate_expr<T,::odds_and_ends::use_default_policy>
                ::template _check<T>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_pointer.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_value_type.hpp>
#include <odds_and_ends/static_introspection/is_allocator_pointer_of.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {

    template <typename T, typename U, typename ResultPlaceholderExpr>
    struct has_allocate :
        ::boost::mpl::eval_if<
            typename ::boost::mpl::eval_if<
                typename ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection::nested_type::has_pointer<T>,
                    ::boost::mpl::true_,
                    ::odds_and_ends::static_introspection::nested_type::has_value_type<T>
                >::type,
                ::odds_and_ends::static_introspection
                ::member_function::_detail::has_allocate_expr<T,U>,
                ::boost::mpl::false_
            >::type,
            ::odds_and_ends::static_introspection::member_function
            ::_detail::has_allocate_impl<T,U,ResultPlaceholderExpr>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::member_function

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_ALLOCATE_HPP

