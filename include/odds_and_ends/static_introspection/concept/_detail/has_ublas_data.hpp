// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__HAS_UBLAS_DATA_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__HAS_UBLAS_DATA_HPP

#include <odds_and_ends/static_introspection/concept/is_ublas_storage.hpp>
#include <odds_and_ends/static_introspection/nested_type/is_array_type_of.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct ublas_data_mfc
    {
        template <typename R>
        struct apply :
            ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::concept::is_ublas_storage<R>,
                ::odds_and_ends::static_introspection::nested_type::is_array_type_of<R,T>,
                ::boost::mpl::false_
            >
        {
        };
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/member_function/has_data.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct has_ublas_data :
        ::odds_and_ends::static_introspection::member_function::has_data<
            T,
            ::odds_and_ends::static_introspection::concept::_detail::ublas_data_mfc<T>
        >
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__HAS_UBLAS_DATA_HPP

