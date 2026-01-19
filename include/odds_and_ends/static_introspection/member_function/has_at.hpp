// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_AT_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_AT_HPP

#include <utility>
#include <odds_and_ends/static_introspection/declref.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename Index, typename ResultPlaceholderExpr>
    struct has_at_impl :
        ::boost::mpl::apply1<
            ResultPlaceholderExpr,
            decltype(
                ::odds_and_ends::static_introspection
                ::declref<T>().at(::std::declval<Index>())
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

    template <typename T, typename Index>
    class has_at_expr
    {
        template <typename B, typename S>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(
                        ::odds_and_ends::static_introspection
                        ::declref<B>().at(::std::declval<S>())
                    )
                >::type
            );

        template <typename B, typename S>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::member_function::_detail
                ::has_at_expr<T,Index>::template _check<T,Index>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename Index, typename ResultPlaceholderExpr>
    struct has_at :
        ::boost::mpl::if_<
            typename ::odds_and_ends::static_introspection
            ::member_function::_detail::has_at_expr<T,Index>::type,
            ::odds_and_ends::static_introspection::member_function
            ::_detail::has_at_impl<T,Index,ResultPlaceholderExpr>,
            ::boost::mpl::false_
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <boost/ptr_container/ptr_list.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T, typename C, typename A, typename Index, typename ResultPlaceholderExpr>
    struct has_at< ::boost::ptr_list<T,C,A>,Index,ResultPlaceholderExpr> :
        ::boost::mpl::false_
    {
    };

    template <typename T, typename C, typename A, typename Index, typename ResultPlaceholderExpr>
    struct has_at< ::boost::ptr_list<T,C,A> const,Index,ResultPlaceholderExpr> :
        ::boost::mpl::false_
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/nested_type/is_reference_of.hpp>
#include <odds_and_ends/static_introspection/remove_vref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {

    template <typename T, typename Index, typename ResultPlaceholderExpr>
    struct has_at :
        ::odds_and_ends::static_introspection::member_function::_detail::has_at<
            typename ::odds_and_ends::static_introspection::remove_vref<T>::type,
            Index,
            ResultPlaceholderExpr
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::member_function

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_AT_HPP

