// Copyright (C) 2011-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__DETAIL__HAS_REVERSE_ITERATOR_MEMBER_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__DETAIL__HAS_REVERSE_ITERATOR_MEMBER_HPP

#include <boost/mpl/has_xxx.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(
        has_const_reverse_iterator_void_or_not,
        const_reverse_iterator,
        false
    )

    BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(
        has_mutable_reverse_iterator_void_or_not,
        reverse_iterator,
        false
    )
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#include <type_traits>
#include <odds_and_ends/static_introspection/concept/_detail/has_reverse_iterator_operators.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    template <typename T>
    class has_const_reverse_iterator_non_void
    {
        typedef typename T::const_reverse_iterator _T_i;

    public:
        typedef typename ::boost::mpl::if_<
            ::std::is_void<_T_i>,
            ::boost::mpl::false_,
            ::odds_and_ends::static_introspection::concept
            ::_detail::has_reverse_iterator_operators<_T_i>
        >::type type;
    };

    template <typename T>
    class has_mutable_reverse_iterator_non_void
    {
        typedef typename T::reverse_iterator _T_i;

    public:
        typedef typename ::boost::mpl::if_<
            ::std::is_void<_T_i>,
            ::boost::mpl::false_,
            ::odds_and_ends::static_introspection::concept
            ::_detail::has_reverse_iterator_operators<_T_i>
        >::type type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    template <typename T, typename _m_T = typename ::std::remove_const<T>::type>
    struct has_const_reverse_iterator_member :
        ::boost::mpl::eval_if<
            typename ::odds_and_ends::static_introspection::nested_type
            ::_detail::has_const_reverse_iterator_void_or_not<_m_T>::type,
            ::odds_and_ends::static_introspection::nested_type
            ::_detail::has_const_reverse_iterator_non_void<_m_T>,
            ::boost::mpl::false_
        >::type
    {
    };

    template <typename T>
    struct has_mutable_reverse_iterator_member :
        ::boost::mpl::eval_if<
            typename ::odds_and_ends::static_introspection::nested_type
            ::_detail::has_mutable_reverse_iterator_void_or_not<T>::type,
            ::odds_and_ends::static_introspection::nested_type
            ::_detail::has_mutable_reverse_iterator_non_void<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#endif
// ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__DETAIL__HAS_REVERSE_ITERATOR_MEMBER_HPP

