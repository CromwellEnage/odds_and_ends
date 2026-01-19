// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_CRBEGIN_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_CRBEGIN_HPP

#include <odds_and_ends/static_introspection/declref.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_crbegin_impl :
        ::boost::mpl::apply1<
            ResultPlaceholderExpr,
            decltype(::odds_and_ends::static_introspection::declcref<T>().crbegin())
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <type_traits>
#include <odds_and_ends/use_default_policy.hpp>
#include <odds_and_ends/static_introspection/nested_type/is_reverse_iterator_of.hpp>
#include <odds_and_ends/static_introspection/remove_vref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T>
    struct has_crbegin_impl<T,::odds_and_ends::use_default_policy> :
        ::odds_and_ends::static_introspection::nested_type::is_reverse_iterator_of<
            decltype(::odds_and_ends::static_introspection::declcref<T>().crbegin()),
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

    template <typename T>
    class has_crbegin
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(::odds_and_ends::static_introspection::declcref<B>().crbegin())
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::member_function
                ::_detail::has_crbegin<T>::template _check<T>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_crbegin :
        ::boost::mpl::if_<
            typename ::odds_and_ends::static_introspection
            ::member_function::_detail::has_crbegin<T>::type,
            ::odds_and_ends::static_introspection::member_function
            ::_detail::has_crbegin_impl<T,ResultPlaceholderExpr>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::member_function

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_CRBEGIN_HPP

