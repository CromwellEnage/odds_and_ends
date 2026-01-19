// Copyright (C) 2012-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_LEGACY_RANDOM_ACCESS_ITERATOR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_LEGACY_RANDOM_ACCESS_ITERATOR_HPP

#include <odds_and_ends/static_introspection/concept/_detail/is_legacy_bidirectional_iterator.hpp>
#include <odds_and_ends/static_introspection/concept/is_comparable.hpp>
#include <odds_and_ends/static_introspection/has_iterator_difference.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_legacy_random_access_iterator_q :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::has_iterator_difference<T>,
            ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::concept::is_comparable<T>,
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_legacy_bidirectional_iterator_q<T>,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <type_traits>
#include <odds_and_ends/static_introspection/is_convertible_to_cref_of.hpp>
#include <odds_and_ends/static_introspection/iterator_reference_of.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_legacy_random_access_iterator_uq_impl :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::is_convertible_to_cref_of<
                decltype(::odds_and_ends::static_introspection::declmref<T>()--),
                T
            >,
            ::boost::mpl::if_<
                ::std::is_same<
                    decltype(*::odds_and_ends::static_introspection::declmref<T>()--),
                    typename ::odds_and_ends::static_introspection::iterator_reference_of<T>::type
                >,
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_legacy_bidirectional_iterator_uq<T>,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/concept/is_addable.hpp>
#include <odds_and_ends/static_introspection/concept/is_subtractable.hpp>
#include <odds_and_ends/static_introspection/concept/is_subscriptable.hpp>
#include <odds_and_ends/static_introspection/is_iterator_reference_of.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_legacy_random_access_iterator_uq :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::is_subtractable<
                T,
                T,
                typename ::odds_and_ends::static_introspection::iterator_difference_of<T>::type
            >,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept::is_subtractable<
                    T,
                    typename ::odds_and_ends::static_introspection
                    ::iterator_difference_of<T>::type
                >,
                ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::concept::is_addable<
                        T,
                        typename ::odds_and_ends::static_introspection
                        ::iterator_difference_of<T>::type
                    >,
                    ::boost::mpl::if_<
                        ::odds_and_ends::static_introspection::concept::is_subscriptable<
                            T,
                            typename ::odds_and_ends::static_introspection
                            ::iterator_difference_of<T>::type,
                            ::odds_and_ends::static_introspection
                            ::is_iterator_reference_of< ::boost::mpl::_,T>
                        >,
                        ::odds_and_ends::static_introspection::concept
                        ::_detail::is_legacy_bidirectional_iterator_uq<T>,
                        ::boost::mpl::false_
                    >,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <iterator>
#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_legacy_forward_iterator.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_legacy_random_access_iterator :
        ::odds_and_ends::static_introspection::concept::_detail::is_legacy_input_iterator<
            T,
            ::std::random_access_iterator_tag,
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_legacy_random_access_iterator_q,
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_legacy_random_access_iterator_uq
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_LEGACY_RANDOM_ACCESS_ITERATOR_HPP

