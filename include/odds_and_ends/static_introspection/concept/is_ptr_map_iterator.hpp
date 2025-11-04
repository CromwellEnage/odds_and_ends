// Copyright (C) 2012-2018 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_CONCEPT_TRAITS_QUERY_IS_PTR_MAP_ITERATOR_HPP
#define BOOST_CONCEPT_TRAITS_QUERY_IS_PTR_MAP_ITERATOR_HPP

#include <boost/concept/traits/query_fwd.hpp>
#include <boost/ptr_container/detail/map_iterator.hpp>
#include <boost/mpl/bool.hpp>

//[reference__is_ptr_map_iterator
namespace boost { namespace concept { namespace traits {

    template <typename T>
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
    struct is_ptr_map_iterator : _mpl_false_
//<-
#else
    struct is_ptr_map_iterator : ::boost::mpl::false_
#endif
//->
    {
    };

    template <typename I, typename F, typename S>
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
    struct is_ptr_map_iterator< _ptr_map_iterator_<I,F,S> >
      : _mpl_true_
//<-
#else
    struct is_ptr_map_iterator< ::boost::ptr_map_iterator<I,F,S> >
      : ::boost::mpl::true_
#endif
//->
    {
    };

    template <typename I, typename F, typename S>
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
    struct is_ptr_map_iterator< _ptr_map_iterator_<I,F,S> const>
      : _mpl_true_
//<-
#else
    struct is_ptr_map_iterator< ::boost::ptr_map_iterator<I,F,S> const>
      : ::boost::mpl::true_
#endif
//->
    {
    };

    template <typename I, typename F, typename S>
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
    struct is_ptr_map_iterator< _ptr_map_iterator_<I,F,S>&>
      : _mpl_true_
//<-
#else
    struct is_ptr_map_iterator< ::boost::ptr_map_iterator<I,F,S>&>
      : ::boost::mpl::true_
#endif
//->
    {
    };

    template <typename I, typename F, typename S>
//<-
#if defined(BOOST_CONCEPT_CONFIG_DOCUMENTATION)
//->
    struct is_ptr_map_iterator< _ptr_map_iterator_<I,F,S> const&>
      : _mpl_true_
//<-
#else
    struct is_ptr_map_iterator< ::boost::ptr_map_iterator<I,F,S> const&>
      : ::boost::mpl::true_
#endif
//->
    {
    };
}}}  // namespace boost::concept::traits
//]

#endif  // include guard

