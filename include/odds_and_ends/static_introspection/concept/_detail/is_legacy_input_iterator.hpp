// Copyright (C) 2011-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_LEGACY_INPUT_ITERATOR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_LEGACY_INPUT_ITERATOR_HPP

#include <odds_and_ends/static_introspection/concept/_detail/is_legacy_iterator.hpp>
#include <odds_and_ends/static_introspection/concept/is_equality_comparable.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_legacy_input_iterator_q :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::concept::is_equality_comparable<T>,
            ::odds_and_ends::static_introspection::concept::_detail::is_legacy_iterator_q<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <type_traits>
#include <odds_and_ends/static_introspection/declref.hpp>
#include <odds_and_ends/static_introspection/iterator_reference_of.hpp>
#include <odds_and_ends/static_introspection/iterator_value_of.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_legacy_input_iterator_uq_impl :
        ::boost::mpl::eval_if<
            ::std::is_convertible<
                decltype(*::odds_and_ends::static_introspection::declmref<T>()++),
                typename ::odds_and_ends::static_introspection::iterator_value_of<T>::type
            >,
            ::boost::mpl::if_<
                ::std::is_convertible<
                    typename ::odds_and_ends::static_introspection
                    ::iterator_reference_of<T>::type,
                    typename ::odds_and_ends::static_introspection::iterator_value_of<T>::type
                >,
                ::odds_and_ends::static_introspection
                ::concept::_detail::is_legacy_iterator_uq<T>,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/concept/_detail/has_post_increment_operator.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_legacy_input_iterator_uq :
        ::boost::mpl::if_<
            typename ::odds_and_ends::static_introspection::concept
            ::_detail::has_post_increment_operator<T>::type,
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_legacy_input_iterator_uq_impl<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/is_iterator_category_of.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <
        typename T,
        typename C,
        template <typename> class U1,
        template <typename> class U2
    >
    struct is_legacy_input_iterator :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::is_iterator_category_of<C,T>,
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_legacy_iterator<T,U1,U2>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_LEGACY_INPUT_ITERATOR_HPP

