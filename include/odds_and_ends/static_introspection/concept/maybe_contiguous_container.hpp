// Copyright (C) 2025-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__MAYBE_CONTIGUOUS_CONTAINER_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__MAYBE_CONTIGUOUS_CONTAINER_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_container.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/maybe_contiguous_container.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_random_access_iterator.hpp>
#include <odds_and_ends/static_introspection/concept/is_random_access_traversal_iterator.hpp>
#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/less.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename StrictnessLevel>
    struct maybe_contiguous_container :
        ::boost::mpl::eval_if<
            ::boost::mpl::less< ::boost::mpl::integral_c<unsigned int,1>,StrictnessLevel>,
            ::boost::mpl::if_<
                ::boost::mpl::less< ::boost::mpl::integral_c<unsigned int,2>,StrictnessLevel>,
                ::odds_and_ends::static_introspection::concept::_detail::is_container<
                    T,
                    ::odds_and_ends::static_introspection::concept
                    ::is_legacy_random_access_iterator< ::boost::mpl::_>,
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::maybe_base_contiguous_container,
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::is_mutable_indexable_container,
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::is_immutable_reversible_container,
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::has_container_reverse_iterator
                >,
                ::odds_and_ends::static_introspection::concept::_detail::is_container<
                    T,
                    ::odds_and_ends::static_introspection::concept
                    ::is_random_access_traversal_iterator< ::boost::mpl::_>,
                    ::odds_and_ends::static_introspection::concept::_detail
                    ::maybe_base_contiguous_container_with_any_data,
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::is_mutable_indexable_container,
                    ::odds_and_ends::static_introspection
                    ::concept::_detail::is_immutable_container,
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::has_container_reverse_iterator
                >
            >,
            ::boost::mpl::if_<
                ::boost::mpl::less< ::boost::mpl::integral_c<unsigned int,0>,StrictnessLevel>,
                ::odds_and_ends::static_introspection::concept::_detail::is_container<
                    T,
                    ::odds_and_ends::static_introspection::concept
                    ::is_random_access_traversal_iterator< ::boost::mpl::_>,
                    ::odds_and_ends::static_introspection::concept::_detail
                    ::maybe_base_contiguous_container_with_any_data,
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::is_mutable_indexable_container,
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::is_immutable_minimal_container,
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::has_container_reverse_iterator
                >,
                ::odds_and_ends::static_introspection::concept::_detail::is_looser_container<
                    T,
                    ::odds_and_ends::static_introspection::concept
                    ::is_random_access_traversal_iterator< ::boost::mpl::_>,
                    ::odds_and_ends::static_introspection::concept::_detail
                    ::maybe_base_contiguous_container_with_any_data,
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::is_immutable_minimal_container,
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::has_container_reverse_iterator
                >
            >
        >::type
    {
    };
}}}  // namespace boost::concept::traits

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__MAYBE_CONTIGUOUS_CONTAINER_HPP

