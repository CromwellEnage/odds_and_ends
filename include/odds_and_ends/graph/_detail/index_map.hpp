// Copyright (C) 2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__GRAPH___DETAIL__INDEX_MAP_HPP
#define ODDS_AND_ENDS__GRAPH___DETAIL__INDEX_MAP_HPP

#include <boost/property_map/property_map.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/apply_wrap.hpp>

namespace odds_and_ends { namespace graph { namespace _detail {

    template <typename Graph, typename PtrXForm, bool B>
    class index_map
    {
        typedef typename ::boost::mpl::apply_wrap1<PtrXForm,Graph const>::type _g_c_ptr;

        _g_c_ptr _g;

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

        index_map();
        index_map(Graph const& g);
        reference operator[](key_type key) const;
    };

    template <typename G, typename PtrXForm, bool B>
    inline index_map<G,PtrXForm,B>::index_map() : _g(nullptr)
    {
    }
}}}  // namespace odds_and_ends::graph::_detail

#include <memory>

namespace odds_and_ends { namespace graph { namespace _detail {

    template <typename G, typename PtrXForm, bool B>
    inline index_map<G,PtrXForm,B>::index_map(G const& g) :
        _g(::std::pointer_traits<_g_c_ptr>::pointer_to(g))
    {
    }

    template <typename G, typename PtrXForm, bool B>
    inline typename index_map<G,PtrXForm,B>::reference
        index_map<G,PtrXForm,B>::operator[](key_type key) const
    {
        return (*this->_g)[key];
    }

    template <typename Graph, typename PX, bool B>
    inline typename index_map<Graph,PX,B>::reference
        get(index_map<Graph,PX,B> const& m, typename index_map<Graph,PX,B>::key_type key)
    {
        return m[key];
    }
}}}  // namespace odds_and_ends::graph::_detail

#endif  // ODDS_AND_ENDS__GRAPH___DETAIL__INDEX_MAP_HPP

