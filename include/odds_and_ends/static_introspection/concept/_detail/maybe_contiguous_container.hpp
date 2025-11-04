// Copyright (C) 2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__MAYBE_CONTIGUOUS_CONTAINER_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__MAYBE_CONTIGUOUS_CONTAINER_HPP

#include <odds_and_ends/static_introspection/concept/_detail/is_indexable_container.hpp>
#include <odds_and_ends/static_introspection/member_function/has_data.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct maybe_base_contiguous_container :
        ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_base_indexable_container<T>,
            ::odds_and_ends::static_introspection::member_function::has_data<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__MAYBE_CONTIGUOUS_CONTAINER_HPP

