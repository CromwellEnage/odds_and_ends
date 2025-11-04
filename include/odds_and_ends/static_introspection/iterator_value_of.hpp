// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__ITERATOR_VALUE_OF_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__ITERATOR_VALUE_OF_HPP

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    struct error__iterator_value_does_not_exist
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <type_traits>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct has_iterator_value_of_pointer :
        ::std::is_object<typename ::std::remove_pointer<T>::type>
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection/nested_type/element_type_of.hpp>
#include <odds_and_ends/static_introspection/nested_type/value_type_of.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct has_same_iterator_value_and_element :
        ::std::is_same<
            typename ::odds_and_ends::static_introspection::nested_type::element_type_of<T>::type,
            typename ::odds_and_ends::static_introspection::nested_type::value_type_of<T>::type
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection/nested_type/has_value_type.hpp>
#include <boost/mpl/assert.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct insert_iterator_value_of
    {
        BOOST_MPL_ASSERT((
            ::odds_and_ends::static_introspection::nested_type::has_value_type<
                typename T::container_type
            >
        ));
        typedef typename T::container_type::value_type type;
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection/concept/_detail/has_pointer_container_nested_types.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_char_type.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_container_type.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_element_type.hpp>
#include <odds_and_ends/static_introspection/nested_type/_detail/char_type_of_actual.hpp>
#include <boost/type_erasure/is_placeholder.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T>
    struct iterator_value_of :
        ::boost::mpl::eval_if<
            ::boost::type_erasure::is_placeholder<T>,
            ::boost::mpl::identity<void>,
            ::boost::mpl::eval_if<
                ::std::is_array<T>,
                ::std::remove_extent<T>,
                ::boost::mpl::eval_if<
                    ::std::is_pointer<T>,
                    ::boost::mpl::eval_if<
                        ::odds_and_ends::static_introspection
                        ::_detail::has_iterator_value_of_pointer<T>,
                        ::std::remove_pointer<T>,
                        ::odds_and_ends::static_introspection
                        ::_detail::error__iterator_value_does_not_exist
                    >,
                    ::boost::mpl::eval_if<
                        ::odds_and_ends::static_introspection::nested_type::has_char_type<T>,
                        ::odds_and_ends::static_introspection
                        ::nested_type::_detail::char_type_of_actual<T>,
                        ::boost::mpl::eval_if<
                            ::odds_and_ends::static_introspection
                            ::nested_type::has_container_type<T>,
                            ::odds_and_ends::static_introspection
                            ::_detail::insert_iterator_value_of<T>,
                            ::boost::mpl::eval_if<
                                ::odds_and_ends::static_introspection
                                ::nested_type::has_value_type<T>,
/*
                                ::boost::mpl::eval_if<
                                    ::odds_and_ends::static_introspection
                                    ::nested_type::has_element_type<T>,
                                    ::boost::mpl::eval_if<
                                        ::odds_and_ends::static_introspection::_detail
                                        ::has_same_iterator_value_and_element<T>,
*/
                                        ::odds_and_ends::static_introspection
                                        ::nested_type::value_type_of<T>,
/*
                                        ::boost::mpl::eval_if<
                                            ::odds_and_ends::static_introspection::concept
                                            ::_detail::has_pointer_container_nested_types<T>,
                                            ::odds_and_ends::static_introspection
                                            ::nested_type::value_type_of<T>,
                                            ::odds_and_ends::static_introspection
                                            ::_detail::error__iterator_value_does_not_exist
                                        >
                                    >,
                                    ::odds_and_ends::static_introspection
                                    ::nested_type::value_type_of<T>
                                >,
*/
                                ::boost::mpl::eval_if<
                                    ::odds_and_ends::static_introspection
                                    ::nested_type::has_element_type<T>,
                                    ::odds_and_ends::static_introspection
                                    ::nested_type::element_type_of<T>,
                                    ::odds_and_ends::static_introspection
                                    ::_detail::error__iterator_value_does_not_exist
                                >
                            >
                        >
                    >
                >
            >
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <iterator>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T, typename CharT, typename Traits>
    struct iterator_value_of< ::std::ostream_iterator<T,CharT,Traits> > :
        ::odds_and_ends::static_introspection::remove_cvref<T>
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>

namespace odds_and_ends { namespace static_introspection {

    template <typename T>
    struct iterator_value_of :
        ::odds_and_ends::static_introspection::_detail::iterator_value_of<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type
        >
    {
    };
}}  // namespace odds_and_ends::static_introspection

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__ITERATOR_VALUE_OF_HPP

