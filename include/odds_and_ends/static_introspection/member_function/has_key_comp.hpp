// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_KEY_COMP_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_KEY_COMP_HPP

#include <odds_and_ends/static_introspection/declref.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_key_comp_impl :
        ::boost::mpl::apply1<
            ResultPlaceholderExpr,
            decltype(::odds_and_ends::static_introspection::declcref<T>().key_comp())
        >
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <type_traits>
#include <odds_and_ends/static_introspection/nested_type/key_compare_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T>
    struct has_key_comp_default :
        ::boost::mpl::if_<
            ::std::is_same<
                typename ::odds_and_ends::static_introspection
                ::nested_type::key_compare_of<T>::type,
                decltype(::odds_and_ends::static_introspection::declcref<T>().key_comp())
            >,
            ::boost::mpl::true_,
            ::boost::mpl::false_
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection/nested_type/has_key_compare.hpp>
#include <odds_and_ends/use_default_policy.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T>
    struct has_key_comp_impl<T,::odds_and_ends::use_default_policy> :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::nested_type::has_key_compare<T>,
            ::odds_and_ends::static_introspection
            ::member_function::_detail::has_key_comp_default<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T>
    class has_key_comp_expr
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(::odds_and_ends::static_introspection::declcref<B>().key_comp())
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::member_function::_detail
                ::has_key_comp_expr<T>::template _check<T>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };

    template <typename T, typename ResultPlaceholderExpr>
    struct has_key_comp :
        ::boost::mpl::if_<
            typename ::odds_and_ends::static_introspection
            ::member_function::_detail::has_key_comp_expr<T>::type,
            ::odds_and_ends::static_introspection::member_function::_detail
            ::has_key_comp_impl<T,ResultPlaceholderExpr>,
            ::boost::mpl::false_
        >::type
    {
    };

    template <typename T, typename ResultPlaceholderExpr>
    struct has_key_comp_ptr_container :
        ::odds_and_ends::static_introspection::member_function::_detail::has_key_comp<
            decltype(::odds_and_ends::static_introspection::declmref<T>().base()),
            ResultPlaceholderExpr
        >
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/is_pointer_container.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_key_comp :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::concept::is_pointer_container<T>,
            ::odds_and_ends::static_introspection::member_function::_detail
            ::has_key_comp_ptr_container<T,ResultPlaceholderExpr>,
            ::odds_and_ends::static_introspection::member_function
            ::_detail::has_key_comp<T,ResultPlaceholderExpr>
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::member_function

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_KEY_COMP_HPP

