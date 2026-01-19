// Copyright (C) 2012-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_REVERSIBLE_CONTAINER_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_REVERSIBLE_CONTAINER_HPP

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_container.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_reversible_container.hpp>
#include <odds_and_ends/static_introspection/concept/is_legacy_bidirectional_iterator.hpp>
#include <odds_and_ends/static_introspection/concept/is_bidirectional_traversal_iterator.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/less.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename StrictnessLevel>
    struct is_reversible_container :
        ::boost::mpl::eval_if<
            ::boost::mpl::less< ::boost::mpl::integral_c<unsigned int,2>,StrictnessLevel>,
            ::boost::mpl::if_<
                ::boost::mpl::less< ::boost::mpl::integral_c<unsigned int,3>,StrictnessLevel>,
                ::odds_and_ends::static_introspection::concept::_detail::is_container<
                    T,
                    ::odds_and_ends::static_introspection::concept
                    ::is_legacy_bidirectional_iterator< ::boost::mpl::_>,
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::is_base_reversible_container,
                    ::odds_and_ends::static_introspection::concept::_detail::is_mutable_container,
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::is_immutable_reversible_container,
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::has_container_reverse_iterator
                >,
                ::odds_and_ends::static_introspection::concept::_detail::is_container<
                    T,
                    ::odds_and_ends::static_introspection::concept
                    ::is_bidirectional_traversal_iterator< ::boost::mpl::_>,
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::is_base_reversible_container,
                    ::odds_and_ends::static_introspection::concept::_detail::is_mutable_container,
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::is_immutable_reversible_container,
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::has_container_reverse_iterator
                >
            >,
            ::boost::mpl::eval_if<
                ::boost::mpl::less< ::boost::mpl::integral_c<unsigned int,1>,StrictnessLevel>,
                ::odds_and_ends::static_introspection::concept::_detail::is_container<
                    T,
                    ::odds_and_ends::static_introspection::concept
                    ::is_bidirectional_traversal_iterator< ::boost::mpl::_>,
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::is_base_reversible_container,
                    ::odds_and_ends::static_introspection::concept::_detail::is_mutable_container,
                    ::odds_and_ends::static_introspection
                    ::concept::_detail::is_immutable_container,
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::has_container_reverse_iterator
                >,
                ::boost::mpl::if_<
                    ::boost::mpl::less< ::boost::mpl::integral_c<unsigned int,0>,StrictnessLevel>,
                    ::odds_and_ends::static_introspection::concept::_detail::is_loose_container<
                        T,
                        ::odds_and_ends::static_introspection::concept
                        ::is_bidirectional_traversal_iterator< ::boost::mpl::_>,
                        ::odds_and_ends::static_introspection::concept
                        ::_detail::is_base_reversible_container,
                        ::odds_and_ends::static_introspection
                        ::concept::_detail::is_mutable_container,
                        ::odds_and_ends::static_introspection::concept
                        ::_detail::has_container_reverse_iterator
                    >,
                    ::odds_and_ends::static_introspection::concept::_detail::is_looser_container<
                        T,
                        ::odds_and_ends::static_introspection::concept
                        ::is_bidirectional_traversal_iterator< ::boost::mpl::_>,
                        ::odds_and_ends::static_introspection::concept
                        ::_detail::is_base_reversible_container,
                        ::odds_and_ends::static_introspection::concept
                        ::_detail::is_immutable_minimal_container,
                        ::odds_and_ends::static_introspection::concept
                        ::_detail::has_container_reverse_iterator
                    >
                >
            >
        >::type
    {
    };
}}}  // namespace boost::concept::traits

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_REVERSIBLE_CONTAINER_HPP

