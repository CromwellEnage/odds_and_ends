// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__ALLOCATOR_IS_ALWAYS_EQUAL_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__ALLOCATOR_IS_ALWAYS_EQUAL_HPP

#include <boost/mpl/has_xxx.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    BOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(
        allocator_is_always_equal_void_or_not,
        is_always_equal,
        false
    )
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <type_traits>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct allocator_is_always_equal_non_void
    {
        typedef typename ::boost::mpl::if_<
            ::std::is_void<typename T::is_always_equal>,
            ::boost::mpl::false_,
            ::boost::mpl::true_
        >::type type;
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct allocator_is_always_equal_impl :
        ::boost::mpl::eval_if<
            typename ::odds_and_ends::static_introspection::_detail
            ::allocator_is_always_equal_void_or_not<T>::type,
            ::odds_and_ends::static_introspection::_detail
            ::allocator_is_always_equal_non_void<T>,
            ::boost::mpl::if_<
                ::std::is_empty<T>,
                ::boost::mpl::true_,
                ::boost::mpl::false_
            >
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <boost/type_erasure/is_placeholder.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct allocator_is_always_equal :
        ::boost::mpl::if_<
            ::boost::type_erasure::is_placeholder<T>,
            void,
            ::odds_and_ends::static_introspection::_detail::allocator_is_always_equal_impl<T>
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T>
    struct allocator_is_always_equal :
        ::odds_and_ends::static_introspection::_detail::allocator_is_always_equal<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type
        >
    {
    };
}}  // namespace odds_and_ends::static_introspection

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__ALLOCATOR_IS_ALWAYS_EQUAL_HPP

