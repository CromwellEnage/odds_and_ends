// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__FREE_FUNCTION__HAS_FRACTIONAL_PART_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__FREE_FUNCTION__HAS_FRACTIONAL_PART_HPP

#include <odds_and_ends/static_introspection/declref.hpp>
#include <odds_and_ends/static_introspection/concept/is_math_rational_type.hpp>
#include <odds_and_ends/static_introspection/free_function/has_numerator.hpp>
#include <odds_and_ends/static_introspection/free_function/has_denominator.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace free_function {
namespace _detail {

    template <typename T, typename ResultPlaceholderExpr>
    class has_fractional_part_impl
    {
        typedef decltype(
            fractional_part(::odds_and_ends::static_introspection::declcref<T>())
        ) _f_t;

    public:
        typedef typename ::boost::mpl::if_<
            ::odds_and_ends::static_introspection::free_function
            ::has_numerator<_f_t,ResultPlaceholderExpr>,
            ::odds_and_ends::static_introspection::free_function
            ::has_denominator<_f_t,ResultPlaceholderExpr>,
            ::boost::mpl::false_
        >::type type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::free_function

#include <type_traits>
#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace free_function {
namespace _detail {

    template <typename T>
    class has_fractional_part_expr
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(fractional_part(::odds_and_ends::static_introspection::declcref<B>()))
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

     public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::free_function::_detail
                ::has_fractional_part_expr<T>::template _check<T>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::free_function

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace free_function {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_fractional_part :
        ::boost::mpl::eval_if<
            typename ::odds_and_ends::static_introspection
            ::free_function::_detail::has_fractional_part_expr<T>::type,
            ::odds_and_ends::static_introspection::free_function
            ::_detail::has_fractional_part_impl<T,ResultPlaceholderExpr>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::free_function

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__FREE_FUNCTION__HAS_FRACTIONAL_PART_HPP

