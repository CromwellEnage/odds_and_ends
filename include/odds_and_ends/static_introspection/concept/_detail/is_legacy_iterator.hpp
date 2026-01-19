// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_LEGACY_ITERATOR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_LEGACY_ITERATOR_HPP

#include <odds_and_ends/static_introspection/concept/is_pre_incrementable.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_iterator_category.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_legacy_iterator_q :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::nested_type::has_iterator_category<T>,
            ::odds_and_ends::static_introspection::concept::is_pre_incrementable<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <type_traits>
#include <iterator>
#include <odds_and_ends/static_introspection/concept/_detail/has_dereference_operator.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_post_increment_dereferenceable.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_pointer.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_reference.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_legacy_iterator_uq :
        ::boost::mpl::eval_if<
            typename ::boost::mpl::eval_if<
                typename ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::nested_type::has_pointer<T>,
                    ::boost::mpl::true_,
                    ::odds_and_ends::static_introspection::nested_type
                    ::has_pointer< ::std::iterator_traits<T> >
                >::type,
                ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::nested_type::has_reference<T>,
                    ::boost::mpl::true_,
                    ::odds_and_ends::static_introspection::nested_type
                    ::has_reference< ::std::iterator_traits<T> >
                >,
                ::boost::mpl::false_
            >::type,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept
                ::_detail::has_dereference_operator<T>,
                ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::is_post_increment_dereferenceable<T>,
                    ::boost::mpl::if_<
                        ::std::is_copy_constructible<T>,
                        ::boost::mpl::true_,
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

#include <odds_and_ends/static_introspection/remove_cvref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <
        typename T,
        template <typename> class U1,
        template <typename> class U2,
        typename _u_T = typename ::odds_and_ends::static_introspection::remove_cvref<T>::type
    >
    struct is_legacy_iterator : ::boost::mpl::if_<U1<T>,U2<_u_T>,::boost::mpl::false_>::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_LEGACY_ITERATOR_HPP

