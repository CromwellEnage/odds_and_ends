// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__FREE_FUNCTION__HAS_NUMERATOR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__FREE_FUNCTION__HAS_NUMERATOR_HPP

#include <odds_and_ends/static_introspection/declref.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/lambda.hpp>

namespace odds_and_ends { namespace static_introspection { namespace free_function {
namespace _detail {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_numerator_impl
    {
        typedef typename ::boost::mpl::apply_wrap1<
            typename ::boost::mpl::lambda<ResultPlaceholderExpr>::type,
            decltype(numerator(::odds_and_ends::static_introspection::declcref<T>()))
        >::type type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::free_function

#include <odds_and_ends/use_default_policy.hpp>
#include <odds_and_ends/static_introspection/concept/is_math_integral_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace free_function {
namespace _detail {

    template <typename T>
    struct has_numerator_impl<T,::odds_and_ends::use_default_policy>
    {
        typedef ::odds_and_ends::static_introspection::concept::is_math_integral_type<
            decltype(numerator(::odds_and_ends::static_introspection::declcref<T>()))
        > type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::free_function

#include <type_traits>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace free_function {
namespace _detail {

    template <typename T>
    class has_numerator
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(numerator(::odds_and_ends::static_introspection::declcref<B>()))
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::free_function
                ::_detail::has_numerator<T>::template _check<T>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::free_function

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace free_function {

    template <typename T, typename ResultPlaceholderExpr>
    struct has_numerator :
        ::boost::mpl::eval_if<
            typename ::odds_and_ends::static_introspection
            ::free_function::_detail::has_numerator<T>::type,
            ::odds_and_ends::static_introspection::free_function
            ::_detail::has_numerator_impl<T,ResultPlaceholderExpr>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::free_function

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__FREE_FUNCTION__HAS_NUMERATOR_HPP

