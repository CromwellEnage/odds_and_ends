// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_GET_ALLOCATOR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_GET_ALLOCATOR_HPP

#include <odds_and_ends/static_introspection/declref.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_get_allocator_impl :
        ::boost::mpl::apply1<
            ResultPlaceholderExpr,
            decltype(::odds_and_ends::static_introspection::declcref<T>().get_allocator())
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <type_traits>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T>
    class has_get_allocator
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(::odds_and_ends::static_introspection::declcref<B>().get_allocator())
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::member_function
                ::_detail::has_get_allocator<T>::template _check<T>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/nested_type/is_allocator_type_of.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_get_allocator :
        ::boost::mpl::if_<
            typename ::odds_and_ends::static_introspection
            ::member_function::_detail::has_get_allocator<T>::type,
            ::odds_and_ends::static_introspection::member_function
            ::_detail::has_get_allocator_impl<T,ResultPlaceholderExpr>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::member_function

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_GET_ALLOCATOR_HPP

