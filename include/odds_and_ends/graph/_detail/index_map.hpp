// Copyright (C) 2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__GRAPH___DETAIL__INDEX_MAP_HPP
#define ODDS_AND_ENDS__GRAPH___DETAIL__INDEX_MAP_HPP

#include <boost/property_map/property_map.hpp>
#include <boost/mpl/if.hpp>

namespace odds_and_ends { namespace graph { namespace _detail {

    template <typename Graph, bool B>
    class index_map
    {
        Graph const& _g;

    public:
        typedef typename ::boost::mpl::if_c<
            B,
            typename Graph::vertex_descriptor,
            typename Graph::edge_descriptor
        >::type key_type;
        typedef typename ::boost::mpl::if_c<
            B,
            typename Graph::vertices_size_type,
            typename Graph::edges_size_type
        >::type value_type;
        typedef value_type reference;
        typedef ::boost::readable_property_map_tag category;

        index_map(Graph const& g);
        reference operator[](key_type key) const;
    };

    template <typename G, bool B>
    inline index_map<G,B>::index_map(G const& g) : _g(g)
    {
    }

    template <typename G, bool B>
    inline typename index_map<G,B>::reference index_map<G,B>::operator[](key_type key) const
    {
        return this->_g[key];
    }

    template <typename Graph, bool B>
    inline typename index_map<Graph,B>::reference
        get(index_map<Graph,B> const& m, typename index_map<Graph,B>::key_type key)
    {
        return m[key];
    }
}}}  // namespace odds_and_ends::graph::_detail

#endif  // ODDS_AND_ENDS__GRAPH___DETAIL__INDEX_MAP_HPP

