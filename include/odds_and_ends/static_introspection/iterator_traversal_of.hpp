// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__ITERATOR_TRAVERSAL_OF_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__ITERATOR_TRAVERSAL_OF_HPP

#include <type_traits>
#include <boost/iterator/iterator_categories.hpp>
#include <boost/mp11/utility.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename Category>
    struct iterator_traversal_from_category
    {
        using type = ::boost::mp11::mp_cond<
            ::std::is_convertible<Category,::boost::iterators::incrementable_traversal_tag>,
            Category,
            ::std::is_convertible<Category,::std::random_access_iterator_tag>,
            ::boost::iterators::random_access_traversal_tag,
            ::std::is_convertible<Category,::std::bidirectional_iterator_tag>,
            ::boost::iterators::bidirectional_traversal_tag,
            ::std::is_convertible<Category,::std::forward_iterator_tag>,
            ::boost::iterators::forward_traversal_tag,
            ::std::is_convertible<Category,::std::input_iterator_tag>,
            ::boost::iterators::single_pass_traversal_tag,
            ::std::is_convertible<Category,::std::output_iterator_tag>,
            ::boost::iterators::incrementable_traversal_tag,
            ::std::true_type,
            void
        >;
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection/iterator_category_of.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct iterator_traversal_of_impl
    {
        typedef typename ::odds_and_ends::static_introspection
        ::_detail::iterator_traversal_from_category<
            typename ::odds_and_ends::static_introspection::iterator_category_of<T>::type
        >::type type;
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/type_erasure/is_placeholder.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct iterator_traversal_of :
        ::boost::mpl::eval_if<
            ::boost::type_erasure::is_placeholder<T>,
            ::boost::mpl::identity<void>,
            ::odds_and_ends::static_introspection::_detail::iterator_traversal_of_impl<T>
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T>
    struct iterator_traversal_of :
        ::odds_and_ends::static_introspection::_detail::iterator_traversal_of<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type
        >
    {
    };
}}  // namespace odds_and_ends::static_introspection

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__ITERATOR_TRAVERSAL_OF_HPP

