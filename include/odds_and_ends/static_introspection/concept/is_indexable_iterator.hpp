// Copyright (C) 2013-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_INDEXABLE_ITERATOR_HPP
#define ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_INDEXABLE_ITERATOR_HPP

#include <type_traits>
#include <utility>
#include <odds_and_ends/static_introspection/iterator_value_of.hpp>
#include <odds_and_ends/static_introspection/declref.hpp>
#include <boost/iterator/iterator_traits.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <typename T, typename Subscript>
    struct has_indexable_iterator_operator
    {
        template <typename Result>
        struct apply
        {
            typedef typename ::boost::mpl::eval_if<
                ::std::is_convertible<
                    Result,
                    typename ::odds_and_ends::static_introspection::iterator_value_of<T>::type
                >,
                ::boost::mpl::if_<
                    ::std::is_same<
                        decltype(
                            *(
                                ::odds_and_ends::static_introspection::declref<T>() +
                                ::std::declval<Subscript>()
                            )
                        ),
                        Result
                    >,
                    ::boost::mpl::true_,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >::type type;
        };
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection/concept/is_additive.hpp>
#include <odds_and_ends/static_introspection/concept/is_subscriptable.hpp>
#include <odds_and_ends/static_introspection/iterator_difference_of.hpp>
#include <boost/mpl/always.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept { namespace _detail {

    template <
        typename T,
        typename IsStrict,
        typename _Difference = typename ::std::add_const<
            typename ::odds_and_ends::static_introspection::iterator_difference_of<T>::type
        >::type
    >
    struct is_indexable_iterator :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::is_additive<T,_Difference>,
            ::boost::mpl::if_<
                IsStrict,
                ::odds_and_ends::static_introspection::concept::is_subscriptable<
                    T,
                    _Difference,
                    ::odds_and_ends::static_introspection::concept::_detail
                    ::has_indexable_iterator_operator<T,_Difference>
                >,
                ::odds_and_ends::static_introspection::concept::is_subscriptable<
                    T,
                    _Difference,
                    ::boost::mpl::always< ::boost::mpl::true_>
                >
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}}  // namespace odds_and_ends::static_introspection::concept::_detail

#include <odds_and_ends/static_introspection_fwd.hpp>
#include <odds_and_ends/static_introspection/concept/is_comparable.hpp>
#include <odds_and_ends/static_introspection/concept/_detail/is_bidirectional.hpp>
#include <odds_and_ends/static_introspection/has_iterator_difference.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename IsStrict>
    struct is_indexable_iterator_ext :
        ::boost::mpl::eval_if<
            ::odds_and_ends::static_introspection::concept::_detail::is_bidirectional<T>,
            ::boost::mpl::eval_if<
                ::odds_and_ends::static_introspection::concept
                ::_detail::is_indexable_iterator<T,IsStrict>,
                ::boost::mpl::if_<
                    ::odds_and_ends::static_introspection::concept::is_comparable<T>,
                    ::odds_and_ends::static_introspection::has_iterator_difference<T>,
                    ::boost::mpl::false_
                >,
                ::boost::mpl::false_
            >,
            ::boost::mpl::false_
        >::type
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#include <odds_and_ends/static_introspection/remove_cvref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename IsStrict>
    struct is_indexable_iterator :
        ::odds_and_ends::static_introspection::concept::is_indexable_iterator_ext<
            typename ::odds_and_ends::static_introspection::remove_cvref<T>::type,
            IsStrict
        >
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#include <iterator>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename IsStrict>
    struct is_indexable_iterator_ext< ::std::reverse_iterator<T>,IsStrict> :
        ::odds_and_ends::static_introspection::concept::is_indexable_iterator<T,IsStrict>
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#include <boost/move/move.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename IsStrict>
    struct is_indexable_iterator_ext< ::boost::move_iterator<T>,IsStrict> :
        ::odds_and_ends::static_introspection::concept::is_indexable_iterator<T,IsStrict>
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#include <boost/iterator/reverse_iterator.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename IsStrict>
    struct is_indexable_iterator_ext<
        ::boost::iterators::reverse_iterator<T>,
        IsStrict
    > : ::odds_and_ends::static_introspection::concept::is_indexable_iterator<T,IsStrict>
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#include <boost/intrusive/detail/reverse_iterator.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename IsStrict>
    struct is_indexable_iterator_ext< ::boost::intrusive::reverse_iterator<T>,IsStrict> :
        ::odds_and_ends::static_introspection::concept::is_indexable_iterator<T,IsStrict>
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#include <boost/ptr_container/detail/void_ptr_iterator.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename VoidIter, typename T, typename IsStrict>
    struct is_indexable_iterator_ext< ::boost::void_ptr_iterator<VoidIter,T>,IsStrict> :
        ::odds_and_ends::static_introspection::concept::is_indexable_iterator<VoidIter,IsStrict>
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#include <boost/numeric/ublas/detail/iterator.hpp>

namespace odds_and_ends { namespace static_introspection { namespace concept {

    template <typename T, typename IsStrict>
    struct is_indexable_iterator_ext<
        ::boost::numeric::ublas::reverse_iterator_base<T>,
        IsStrict
    > : ::odds_and_ends::static_introspection::concept::is_indexable_iterator<T,IsStrict>
    {
    };

    template <typename T, typename IsStrict>
    struct is_indexable_iterator_ext<
        ::boost::numeric::ublas::reverse_iterator_base1<T>,
        IsStrict
    > : ::odds_and_ends::static_introspection::concept::is_indexable_iterator<T,IsStrict>
    {
    };

    template <typename T, typename IsStrict>
    struct is_indexable_iterator_ext<
        ::boost::numeric::ublas::reverse_iterator_base2<T>,
        IsStrict
    > : ::odds_and_ends::static_introspection::concept::is_indexable_iterator<T,IsStrict>
    {
    };
}}}  // namespace odds_and_ends::static_introspection::concept

#endif  // ODDS_AND_ENDS__STATIC_INTROSPECTION__CONCEPT__IS_INDEXABLE_ITERATOR_HPP

