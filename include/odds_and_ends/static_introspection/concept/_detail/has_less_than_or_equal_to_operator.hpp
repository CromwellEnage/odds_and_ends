// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__HAS_LESS_THAN_OR_EQUAL_TO_OP_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__HAS_LESS_THAN_OR_EQUAL_TO_OP_HPP

#include <type_traits>
#include <utility>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename U>
    class has_less_than_or_equal_to_operator
    {
        template <typename L, typename R>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(::std::declval<L>() <= ::std::declval<R>())
                >::type
            );

        template <typename L, typename R>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::concept::_detail
                ::has_less_than_or_equal_to_operator<T,U>::template _check<T,U>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__HAS_LESS_THAN_OR_EQUAL_TO_OP_HPP

