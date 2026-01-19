// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__HAS_ITERATOR1_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__HAS_ITERATOR1_HPP

#include <boost/mpl/has_xxx.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(has_const_iterator1_void_or_not, const_iterator1, false)

    BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(has_iterator1_void_or_not, iterator1, false)
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#include <type_traits>
#include <odds_and_ends/static_introspection/concept/_detail/has_iterator_operators.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    template <typename T>
    class has_const_iterator1_non_void
    {
        typedef typename T::const_iterator1 _T_i;

    public:
        typedef typename ::boost::mpl::if_<
            ::std::is_void<_T_i>,
            ::boost::mpl::false_,
            ::odds_and_ends::static_introspection::concept::_detail::has_iterator_operators<_T_i>
        >::type type;
    };

    template <typename T>
    class has_iterator1_non_void
    {
        typedef typename T::iterator1 _T_i;

    public:
        typedef typename ::boost::mpl::if_<
            ::std::is_void<_T_i>,
            ::boost::mpl::false_,
            ::odds_and_ends::static_introspection::concept::_detail::has_iterator_operators<_T_i>
        >::type type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {
namespace _detail {

    template <typename T, typename _m_T = typename ::std::remove_const<T>::type>
    struct has_const_iterator1_impl :
        ::boost::mpl::eval_if<
            typename ::odds_and_ends::static_introspection::nested_type
            ::_detail::has_const_iterator1_void_or_not<_m_T>::type,
            ::odds_and_ends::static_introspection::nested_type
            ::_detail::has_const_iterator1_non_void<_m_T>,
            ::boost::mpl::false_
        >
    {
    };

    template <typename T>
    struct has_iterator1_impl :
        ::boost::mpl::eval_if<
            typename ::odds_and_ends::static_introspection::nested_type
            ::_detail::has_iterator1_void_or_not<T>::type,
            ::odds_and_ends::static_introspection::nested_type
            ::_detail::has_iterator1_non_void<T>,
            ::boost::mpl::false_
        >
    {
    };

    template <typename T>
    struct has_iterator1 :
        ::boost::mpl::eval_if<
            ::std::is_const<T>,
            ::odds_and_ends::static_introspection
            ::nested_type::_detail::has_const_iterator1_impl<T>,
            ::odds_and_ends::static_introspection
            ::nested_type::_detail::has_iterator1_impl<T>
        >::type
    {
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::nested_type

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/remove_vref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace nested_type {

    template <typename T>
    struct has_iterator1 :
        ::odds_and_ends::static_introspection::nested_type::_detail::has_iterator1<
            typename ::odds_and_ends::static_introspection::remove_vref<T>::type
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::nested_type

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__NESTED_TYPE__HAS_ITERATOR1_HPP

