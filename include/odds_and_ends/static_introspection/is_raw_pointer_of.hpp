// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__IS_RAW_POINTER_OF_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__IS_RAW_POINTER_OF_HPP

#include <type_traits>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/apply.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T1, typename T2, typename BinaryPlaceholderExpr>
    struct is_raw_pointer_of_impl :
        ::boost::mpl::if_<
            typename ::boost::mpl::apply2<
                BinaryPlaceholderExpr,
                typename ::std::add_pointer<
                    typename ::std::remove_reference<T2>::type
                >::type,
                typename ::std::remove_reference<T1>::type
            >::type,
            ::boost::mpl::true_,
            ::boost::mpl::false_
        >::type
    {
    };

    template <typename T1, typename T2, typename BinaryPlaceholderExpr>
    struct is_raw_const_pointer_of_impl :
        ::boost::mpl::if_<
            typename ::boost::mpl::apply2<
                BinaryPlaceholderExpr,
                typename ::std::add_pointer<
                    typename ::std::add_const<
                        typename ::std::remove_reference<T2>::type
                    >::type,
                >::type
                typename ::std::remove_reference<T1>::type
            >::type,
            ::boost::mpl::true_,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T1, typename T2, typename BinaryPlaceholderExpr>
    struct is_raw_pointer_of :
        ::boost::mpl::if_<
            ::std::is_const<
                typename ::std::remove_pointer<
                    typename ::std::remove_reference<T1>::type
                >::type
            >,
            ::odds_and_ends::static_introspection::_detail
            ::is_raw_const_pointer_of_impl<T1,T2,BinaryPlaceholderExpr>,
            ::odds_and_ends::static_introspection::_detail
            ::is_raw_pointer_of_impl<T1,T2,BinaryPlaceholderExpr>
        >::type
    {
    };
}}  // namespace odds_and_ends::static_introspection

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__IS_RAW_POINTER_OF_HPP

