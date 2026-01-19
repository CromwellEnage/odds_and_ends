// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_MULTI_ARRAY_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_MULTI_ARRAY_HPP

#include <odds_and_ends/static_introspection/concept/is_multi_array_index_range.hpp>
#include <odds_and_ends/static_introspection/nested_type/index_range_of.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_base_multi_array_impl :
        ::odds_and_ends::static_introspection::concept::is_multi_array_index_range<
            typename ::odds_and_ends::static_introspection::nested_type::index_range_of<T>::type
        >
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/concept/_detail/maybe_contiguous_container.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_index.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_index_gen.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_index_range.hpp>
#include <odds_and_ends/static_introspection/member_function/has_origin.hpp>
#include <odds_and_ends/static_introspection/member_data/has_dimensionality.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_base_multi_array :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::_detail
            ::maybe_base_contiguous_container_with_any_data<T>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::member_data::has_dimensionality<T>,
                ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::nested_type::has_index_range<T>,
                    ::boost::mpl::eval_if<
                        ::odds_and_ends::static_introspection::nested_type::has_index_gen<T>,
                        ::boost::mpl::eval_if<
                            ::odds_and_ends::static_introspection::member_function::has_origin<T>,
                            ::boost::mpl::if_<
                                ::odds_and_ends::static_introspection::nested_type::has_index<T>,
                                ::odds_and_ends::static_introspection::concept
                                ::_detail::is_base_multi_array_impl<T>,
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

#include <odds_and_ends/static_introspection/member_function/has_index_bases.hpp>
#include <odds_and_ends/static_introspection/member_function/has_num_dimensions.hpp>
#include <odds_and_ends/static_introspection/member_function/has_num_elements.hpp>
#include <odds_and_ends/static_introspection/member_function/has_shape.hpp>
#include <odds_and_ends/static_introspection/member_function/has_strides.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    struct is_immutable_multi_array :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept
            ::_detail::is_immutable_minimal_container<T>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::member_function::has_num_dimensions<T>,
                ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::member_function::has_num_elements<T>,
                    ::boost::mpl::eval_if<
                        ::odds_and_ends::static_introspection::member_function::has_index_bases<T>,
                        ::boost::mpl::eval_if<
                            ::odds_and_ends::static_introspection::member_function::has_strides<T>,
                            ::odds_and_ends::static_introspection::member_function::has_shape<T>,
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

    template <typename T>
    struct is_strict_immutable_multi_array :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::_detail::is_immutable_container<T>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::member_function::has_num_dimensions<T>,
                ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::member_function::has_num_elements<T>,
                    ::boost::mpl::eval_if<
                        ::odds_and_ends::static_introspection::member_function::has_index_bases<T>,
                        ::boost::mpl::eval_if<
                            ::odds_and_ends::static_introspection::member_function::has_strides<T>,
                            ::odds_and_ends::static_introspection::member_function::has_shape<T>,
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

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__DETAIL__IS_MULTI_ARRAY_HPP

