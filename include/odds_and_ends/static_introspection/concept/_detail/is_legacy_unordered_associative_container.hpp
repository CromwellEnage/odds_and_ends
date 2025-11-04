// Copyright (C) 2012-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_LEGACY_UNORDERED_ASSOC_CONTAINER_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_LEGACY_UNORDERED_ASSOC_CONTAINER_HPP

#include <odds_and_ends/static_introspection/concept/_detail/is_legacy_associative_container.hpp>
#include <odds_and_ends/static_introspection/member_function/has_begin_bucket.hpp>
#include <odds_and_ends/static_introspection/member_function/has_end_bucket.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_base_legacy_unordered_associative_container :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_base_legacy_associative_container<T>,
            ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::member_function::has_begin_bucket<T>,
                ::odds_and_ends::static_introspection::member_function::has_end_bucket<T>,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/member_function/has_key_eq.hpp>
#include <odds_and_ends/static_introspection/member_function/has_bucket.hpp>
#include <odds_and_ends/static_introspection/member_function/has_bucket_size.hpp>
#include <odds_and_ends/static_introspection/member_function/has_bucket_count.hpp>
#include <odds_and_ends/static_introspection/member_function/has_max_bucket_count.hpp>
#include <odds_and_ends/static_introspection/member_function/has_cbegin_bucket.hpp>
#include <odds_and_ends/static_introspection/member_function/has_cend_bucket.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_const_legacy_unordered_associative_container :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_const_legacy_associative_container<T>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::member_function::has_max_bucket_count<T>,
                ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::member_function::has_bucket_count<T>,
                    ::boost::mpl::eval_if<
                        ::odds_and_ends::static_introspection
                        ::member_function::has_bucket_size<T>,
                        ::boost::mpl::eval_if<
                            ::odds_and_ends::static_introspection::member_function::has_bucket<T>,
                            ::boost::mpl::eval_if<
                                ::odds_and_ends::static_introspection
                                ::member_function::has_key_eq<T>,
                                ::boost::mpl::if_<
                                    ::odds_and_ends::static_introspection
                                    ::member_function::has_cbegin_bucket<T>,
                                    ::odds_and_ends::static_introspection
                                    ::member_function::has_cend_bucket<T>,
                                    ::boost::mpl::false_
                                >,
                                ::boost::mpl::false_
                            >,
                            ::boost::mpl::false_
                        >,
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

#endif
// ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_LEGACY_UNORDERED_ASSOC_CONTAINER_HPP

