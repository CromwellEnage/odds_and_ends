// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_PUSH_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_PUSH_HPP

#include <type_traits>
#include <utility>
#include <odds_and_ends/static_introspection/declref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename Param>
    class has_push_expr
    {
        template <typename B, typename P>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(
                        ::odds_and_ends::static_introspection::declref<B>().push(
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
                ::_detail::has_push_expr<T,Param>::_check<T,Param>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection/nested_type/value_type_of.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T>
    class has_push_expr_default
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(
                        ::odds_and_ends::static_introspection::declref<B>().push(
                            ::odds_and_ends::static_introspection::declcref<
                                typename ::odds_and_ends::static_introspection
                                ::nested_type::value_type_of<B>::type
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
                ::odds_and_ends::static_introspection::member_function
                ::_detail::has_push_expr_default<T>::_check<T>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/remove_vref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {

    template <typename T, typename Param>
    struct has_push :
        ::odds_and_ends::static_introspection::member_function::_detail::has_push_expr<
            typename ::odds_and_ends::static_introspection::remove_vref<T>::type,
            Param
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection/nested_type/has_value_type.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T>
    struct has_push_default :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::nested_type::has_value_type<T>,
            ::odds_and_ends::static_introspection
            ::member_function::_detail::has_push_expr_default<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

namespace odds_and_ends { namespace static_introspection { namespace member_function {

    template <typename T>
    struct has_push<T,::odds_and_ends::use_default_policy> :
        ::odds_and_ends::static_introspection::member_function::_detail
        ::has_push_default<typename ::odds_and_ends::static_introspection::remove_vref<T>::type>
    {
    };
}}}  // namespace odds_and_ends::static_introspection::member_function

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_PUSH_HPP

