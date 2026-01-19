// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__IS_CONVERTIBLE_TO_CREF_OF_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__IS_CONVERTIBLE_TO_CREF_OF_HPP

#include <type_traits>
#include <odds_and_ends/static_introspection_fwd.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T1, typename T2>
    struct is_convertible_to_cref_of :
        ::boost::mpl::if_<
            ::std::is_convertible<
                T1,
                typename ::std::add_lvalue_reference<
                    typename ::std::add_const<
                        typename ::std::remove_reference<T2>::type
                    >::type
                >::type
            >,
            ::boost::mpl::true_,
            ::boost::mpl::false_
        >::type
    {
    };
}}  // namespace odds_and_ends::static_introspection

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__IS_CONVERTIBLE_TO_CREF_OF_HPP

