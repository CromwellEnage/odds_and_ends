// Copyright (C) 2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__GRAPH__PARAMETER__TEMPLATE_HPP
#define ODDS_AND_ENDS__GRAPH__PARAMETER__TEMPLATE_HPP

#include <boost/parameter/template_keyword.hpp>

namespace odds_and_ends { namespace graph { namespace parameter {
    namespace tag {

        struct _vertex_index;
        struct _edge_index;
        struct _index_difference;
    }  // namespace tag

    template <typename T>
    struct _vertex_index :
        ::boost::parameter::template_keyword<
            ::odds_and_ends::graph::parameter::tag::_vertex_index,
            T
        >
    {
    };

    template <typename T>
    struct _edge_index :
        ::boost::parameter::template_keyword<
            ::odds_and_ends::graph::parameter::tag::_edge_index,
            T
        >
    {
    };

    template <typename T>
    struct _index_difference :
        ::boost::parameter::template_keyword<
            ::odds_and_ends::graph::parameter::tag::_index_difference,
            T
        >
    {
    };
}}}  // namespace odds_and_ends::graph::parameter

#endif  // ODDS_AND_ENDS__GRAPH__PARAMETER__TEMPLATE_HPP

