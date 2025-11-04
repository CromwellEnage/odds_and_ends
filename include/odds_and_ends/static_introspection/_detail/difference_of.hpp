// Copyright (C) 2013-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__DETAIL__DIFFERENCE_OF_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__DETAIL__DIFFERENCE_OF_HPP

#include <cstddef>
#include <type_traits>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/type_erasure/is_placeholder.hpp>

namespace odds_and_ends { namespace static_introspection { namespace _detail {

    template <typename T, template <typename> class U>
    struct difference_of :
        ::boost::mpl::eval_if<
            ::boost::type_erasure::is_placeholder<T>,
            ::boost::mpl::identity<void>,
            ::boost::mpl::eval_if<
                ::std::is_pointer<T>,
                ::boost::mpl::identity< ::std::ptrdiff_t>,
                U<T>
            >
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::_detail

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__DETAIL__DIFFERENCE_OF_HPP

