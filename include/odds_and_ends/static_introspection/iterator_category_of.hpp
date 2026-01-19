// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__ITERATOR_CATEGORY_OF_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__ITERATOR_CATEGORY_OF_HPP

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct iterator_category_of_impl_1
    {
        typedef typename T::iterator_category type;
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <iterator>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct iterator_category_of_impl_0
    {
        typedef typename ::std::iterator_traits<T>::iterator_category type;
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <type_traits>
#include <odds_and_ends/static_introspection/nested_type/has_iterator_category.hpp>
#include <boost/type_erasure/is_placeholder.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct iterator_category_of :
        ::boost::mpl::eval_if<
            ::boost::type_erasure::is_placeholder<T>,
            ::boost::mpl::identity<void>,
            ::boost::mpl::eval_if<
                ::std::is_pointer<T>,
                ::boost::mpl::identity< ::std::random_access_iterator_tag>,
                ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::nested_type::has_iterator_category<T>,
                ::odds_and_ends::static_introspection::_detail::iterator_category_of_impl_1<T>,
                ::odds_and_ends::static_introspection::_detail::iterator_category_of_impl_0<T>
            >
            >
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T>
    struct iterator_category_of :
        ::odds_and_ends::static_introspection::_detail::iterator_category_of<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type
        >
    {
    };
}}  // namespace odds_and_ends::static_introspection

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__ITERATOR_CATEGORY_OF_HPP

