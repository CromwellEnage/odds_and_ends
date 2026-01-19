// Copyright (C) 2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__ALGORITHM__ADD_DISTANCE_HPP
#define ODDS_AND_ENDS__NODE__ALGORITHM__ADD_DISTANCE_HPP

#include <boost/mpl/bool.hpp>

namespace odds_and_ends { namespace node { namespace algorithm { namespace _detail {

    template <typename Size, typename Iterator>
    inline void add_distance(Size& size, Iterator itr_begin, Iterator itr_end, ::boost::mpl::true_)
    {
        size += itr_end - itr_begin;
    }

    template <typename Size, typename Iterator>
    void add_distance(Size& size, Iterator itr, Iterator itr_end, ::boost::mpl::false_)
    {
        for (; itr != itr_end; ++itr)
        {
            ++size;
        }
    }
}}}}  // namespace odds_and_ends::node::algorithm::_detail

#include <odds_and_ends/static_introspection/concept/is_indexable_iterator.hpp>

namespace odds_and_ends { namespace node { namespace algorithm {

    template <typename Size, typename Iterator>
    inline void add_distance(Size& size, Iterator itr_begin, Iterator itr_end)
    {
        ::odds_and_ends::node::algorithm::_detail::add_distance(
            size,
            itr_begin,
            itr_end,
            ::odds_and_ends::static_introspection::concept::is_indexable_iterator<Iterator>()
        );
    }
}}}  // namespace odds_and_ends::node::algorithm

#endif  // ODDS_AND_ENDS__NODE__ALGORITHM__ADD_DISTANCE_HPP

