// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_RESIZE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_RESIZE_HPP

#include <boost/cstdint.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename Element, ::boost::uintmax_t Arity>
    class has_resize_impl;

    template <typename T, ::boost::uintmax_t Arity>
    class has_resize_with_value_type;
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <type_traits>
#include <utility>
#include <odds_and_ends/static_introspection/declref.hpp>
#include <odds_and_ends/static_introspection/nested_type/size_type_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename U>
    class has_resize_impl<T,U,1>
    {
        template <typename B, typename V>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(
                        ::odds_and_ends::static_introspection::declmref<B>().resize(
                            ::std::declval<
                                typename ::odds_and_ends::static_introspection
                                ::nested_type::size_type_of<B>::type
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
                ::has_resize_impl<T,U,1>::template _check<T,U>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };

    template <typename T, typename U>
    class has_resize_impl<T,U,2>
    {
        template <typename B, typename V>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(
                        ::odds_and_ends::static_introspection::declmref<B>().resize(
                            ::std::declval<
                                typename ::odds_and_ends::static_introspection
                                ::nested_type::size_type_of<B>::type
                            >(),
                            ::std::declval<
                                typename ::odds_and_ends::static_introspection
                                ::nested_type::size_type_of<B>::type
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
                ::has_resize_impl<T,U,2>::template _check<T,U>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection/nested_type/value_type_of.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T>
    class has_resize_with_value_type<T,1>
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(
                        ::odds_and_ends::static_introspection::declmref<B>().resize(
                            ::std::declval<
                                typename ::odds_and_ends::static_introspection
                                ::nested_type::size_type_of<B>::type
                            >(),
                            ::std::declval<
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
                ::odds_and_ends::static_introspection::member_function::_detail
                ::has_resize_with_value_type<T,1>::template _check<T>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };

    template <typename T>
    class has_resize_with_value_type<T,2>
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(
                        ::odds_and_ends::static_introspection::declmref<B>().resize(
                            ::std::declval<
                                typename ::odds_and_ends::static_introspection
                                ::nested_type::size_type_of<B>::type
                            >(),
                            ::std::declval<
                                typename ::odds_and_ends::static_introspection
                                ::nested_type::size_type_of<B>::type
                            >(),
                            ::std::declval<
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
                ::odds_and_ends::static_introspection::member_function::_detail
                ::has_resize_with_value_type<T,2>::template _check<T>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };

    template <typename T, typename Element, typename SizeArity>
    struct has_resize :
        ::odds_and_ends::static_introspection::member_function
        ::_detail::has_resize_impl<T,Element,SizeArity::value>
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/use_default_policy.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_value_type.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename SizeArity>
    struct has_resize<T,::odds_and_ends::use_default_policy,SizeArity> :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::nested_type::has_value_type<T>,
            ::odds_and_ends::static_introspection::member_function
            ::_detail::has_resize_with_value_type<T,SizeArity::value>,
            ::boost::mpl::false_
        >
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_size_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {

    template <typename T, typename U, typename SizeArity>
    struct has_resize :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::nested_type::has_size_type<T>,
            ::odds_and_ends::static_introspection::member_function
            ::_detail::has_resize<T,U,SizeArity>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::member_function

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_RESIZE_HPP

