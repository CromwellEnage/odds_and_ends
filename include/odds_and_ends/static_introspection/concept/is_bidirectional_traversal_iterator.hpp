// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_BIDIRECTIONAL_TRAVERSAL_ITERATOR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_BIDIRECTIONAL_TRAVERSAL_ITERATOR_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/is_forward_traversal_iterator.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_bidirectional.hpp>
#include <odds_and_ends/static_introspection/is_iterator_traversal_of.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <boost/iterator/iterator_categories.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_bidirectional_traversal_iterator :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::_detail::is_bidirectional<
                typename ::odds_and_ends::static_introspection::remove_cvref<T>::type
            >,
            ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::is_iterator_traversal_of<
                    ::boost::iterators::bidirectional_traversal_tag,
                    T
                >,
                ::odds_and_ends::static_introspection::concept::is_forward_traversal_iterator<T>,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_BIDIRECTIONAL_TRAVERSAL_ITERATOR_HPP

