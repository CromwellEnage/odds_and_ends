// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MULTI_ARRAY_INDEX_RANGE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MULTI_ARRAY_INDEX_RANGE_HPP

#include <type_traits>
#include <utility>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename I>
    struct has_index_range_operators :
        ::boost::mpl::eval_if<
            ::std::is_same<T,decltype(::std::declval<T>() <= ::std::declval<I>())>,
            ::boost::mpl::eval_if<
                ::std::is_same<T,decltype(::std::declval<I>() <= ::std::declval<T>())>,
                ::boost::mpl::eval_if<
                    ::std::is_same<T,decltype(::std::declval<T>() < ::std::declval<I>())>,
                    ::boost::mpl::eval_if<
                        ::std::is_same<T,decltype(::std::declval<I>() < ::std::declval<T>())>,
                        ::boost::mpl::eval_if<
                            ::std::is_same<T,decltype(::std::declval<T>() + ::std::declval<I>())>,
                            ::boost::mpl::if_<
                                ::std::is_same<
                                    T,
                                    decltype(::std::declval<T>() - ::std::declval<I>())
                                >,
                                ::boost::mpl::true_,
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
        >
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/concept/_detail/has_less_than_operator.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/has_less_than_or_equal_to_operator.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/has_plus_operator.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/has_minus_operator.hpp>
#include <odds_and_ends/static_introspection/nested_type/index_of.hpp>
#include <odds_and_ends/static_introspection/member_function/has_size.hpp>
#include <odds_and_ends/static_introspection/member_function/has_start.hpp>
#include <odds_and_ends/static_introspection/member_function/has_finish.hpp>
#include <odds_and_ends/static_introspection/member_function/has_stride.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T>
    class is_multi_array_index_range_impl
    {
        typedef typename ::odds_and_ends::static_introspection
        ::nested_type::index_of<T>::type _index_t;

    public:
        typedef typename ::boost::mpl::eval_if<
            typename ::boost::mpl::eval_if<
                typename ::boost::mpl::eval_if<
                    typename ::boost::mpl::eval_if<
                        typename ::boost::mpl::eval_if<
                            typename ::boost::mpl::eval_if<
                                typename ::odds_and_ends::static_introspection::concept::_detail
                                ::has_less_than_or_equal_to_operator<T,_index_t>::type,
                                ::odds_and_ends::static_introspection::concept::_detail
                                ::has_less_than_or_equal_to_operator<_index_t,T>,
                                ::boost::mpl::false_
                            >::type,
                            ::odds_and_ends::static_introspection::concept
                            ::_detail::has_less_than_operator<T,_index_t>,
                            ::boost::mpl::false_
                        >::type,
                        ::odds_and_ends::static_introspection::concept
                        ::_detail::has_less_than_operator<_index_t,T>,
                        ::boost::mpl::false_
                    >::type,
                    ::odds_and_ends::static_introspection::concept
                    ::_detail::has_plus_operator<T,_index_t>,
                    ::boost::mpl::false_
                >::type,
                ::odds_and_ends::static_introspection::concept
                ::_detail::has_minus_operator<T,_index_t>,
                ::boost::mpl::false_
            >::type,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::member_function::has_start<T,_index_t>,
                ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::member_function::has_finish<T,_index_t>,
                    ::boost::mpl::eval_if<
                        ::odds_and_ends::static_introspection
                        ::member_function::has_stride<T,_index_t>,
                        ::boost::mpl::eval_if<
                            ::odds_and_ends::static_introspection
                            ::member_function::has_size<T,_index_t>,
                            ::odds_and_ends::static_introspection::concept
                            ::_detail::has_index_range_operators<T,_index_t>,
                            ::boost::mpl::false_
                        >,
                        ::boost::mpl::false_
                    >,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type type;
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/member_function/has_get_start.hpp>
#include <odds_and_ends/static_introspection/member_function/has_get_finish.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T>
    struct is_multi_array_index_range :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::member_function::has_get_start<T>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::member_function::has_get_finish<T>,
                ::boost::mpl::eval_if<
                    ::odds_and_ends::static_introspection::member_function::has_start<T>,
                    ::boost::mpl::eval_if<
                        ::odds_and_ends::static_introspection::member_function::has_finish<T>,
                        ::boost::mpl::eval_if<
                            ::odds_and_ends::static_introspection::member_function::has_stride<T>,
                            ::odds_and_ends::static_introspection::concept
                            ::_detail::is_multi_array_index_range_impl<T>,
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
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_MULTI_ARRAY_INDEX_RANGE_HPP

