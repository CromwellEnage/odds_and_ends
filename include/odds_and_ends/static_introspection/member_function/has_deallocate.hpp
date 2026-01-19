// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_DEALLOCATE_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_DEALLOCATE_HPP

#include <type_traits>
#include <utility>
#include <odds_and_ends/static_introspection/allocator_pointer_of.hpp>
#include <odds_and_ends/static_introspection/allocator_size_of.hpp>
#include <odds_and_ends/static_introspection/declref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/detail/yes_no_type.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {
namespace _detail {

    template <typename T>
    class has_deallocate
    {
        template <typename B>
        static ::boost::type_traits::yes_type
            _check(
                typename ::std::add_pointer<
                    decltype(
                        ::odds_and_ends::static_introspection::declref<B>().deallocate(
                            ::std::declval<
                                typename ::odds_and_ends::static_introspection
                                ::allocator_pointer_of<B>::type
                            >(),
                            ::std::declval<
                                typename ::odds_and_ends::static_introspection
                                ::allocator_size_of<B>::type
                            >()
                        )
                    )
                >::type
            );

        template <typename B>
        static ::boost::type_traits::no_type _check(...);

    public:
        typedef ::boost::mpl::bool_<
            sizeof(
                ::odds_and_ends::static_introspection::member_function
                ::_detail::has_deallocate<T>::template _check<T>(nullptr)
            ) == sizeof(::boost::type_traits::yes_type)
        > type;
    };
}  // namespace _detail
}}}  // namespace odds_and_ends::static_introspection::member_function

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_pointer.hpp>
#include <odds_and_ends/static_introspection/nested_type/has_value_type.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace member_function {

    template <typename T>
    struct has_deallocate :
        ::boost::mpl::eval_if<
            typename ::boost::mpl::if_<
                ::odds_and_ends::static_introspection::nested_type::has_pointer<T>,
                ::boost::mpl::true_,
                ::odds_and_ends::static_introspection::nested_type::has_value_type<T>
            >::type,
            ::odds_and_ends::static_introspection::member_function::_detail::has_deallocate<T>,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::member_function

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__MEMBER_FUNCTION__HAS_DEALLOCATE_HPP

