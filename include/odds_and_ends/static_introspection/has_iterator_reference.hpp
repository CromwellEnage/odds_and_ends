// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__HAS_ITERATOR_REFERENCE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__HAS_ITERATOR_REFERENCE_HPP

#include <type_traits>
#include <utility>
#include <boost/type_traits/detail/yes_no_type.hpp>
#include <boost/mpl/bool.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    class has_iterator_reference
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check(typename ::std::add_pointer<decltype(*::std::declval<B&>())>::type);

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::_detail
                ::has_iterator_reference<T>::template _check<T>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/remove_cvref.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T>
    struct has_iterator_reference :
        ::odds_and_ends::static_introspection::_detail::has_iterator_reference<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type
        >::type
    {
    };
}}  // namespace odds_and_ends::static_introspection

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__HAS_ITERATOR_REFERENCE_HPP

