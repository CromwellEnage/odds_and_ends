// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_READABLE_ITERATOR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_READABLE_ITERATOR_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection/iterator_value_of.hpp>
#include <odds_and_ends/static_introspection/declref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_readable_iterator_impl :
        ::boost::mpl::if_<
            ::std::is_convertible<
                decltype(*::odds_and_ends::static_introspection::declref<T>()),
                typename ::odds_and_ends::static_introspection::iterator_value_of<T>::type
            >,
            ::std::is_copy_constructible<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/concept/is_lvalue_assignable.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/has_dereference_operator.hpp>
#include <odds_and_ends/static_introspection/has_iterator_value.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_readable_iterator :
        ::boost::mpl::eval_if<
            typename ::odds_and_ends::static_introspection
            ::concept::_detail::has_dereference_operator<T>::type,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept::is_lvalue_assignable<T>,
                ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::has_iterator_value<T>,
                    ::boost::mpl::if_<
                        ::odds_and_ends::static_introspection::concept
                        ::_detail::is_readable_iterator_impl<T>,
                        ::boost::mpl::true_,
                        ::boost::mpl::false_
                    >,
                    ::boost::mpl::if_<
                        ::std::is_pointer<T>,
                        ::boost::mpl::true_,
                        ::boost::mpl::false_
                    >
                >,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_readable_iterator :
        ::odds_and_ends::static_introspection::concept::_detail::is_readable_iterator<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_READABLE_ITERATOR_HPP

