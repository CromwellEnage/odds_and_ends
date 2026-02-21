// Copyright (C) 2011-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__GRAPH__PROPERTY_MAP_FUNCTOR_HPP
#define ODDS_AND_ENDS__GRAPH__PROPERTY_MAP_FUNCTOR_HPP

#include <boost/property_map/property_map.hpp>

namespace odds_and_ends { namespace graph {

    template <typename Map>
    class property_map_functor
    {
        Map& _map;

    public:
        typedef typename ::boost::property_traits<Map>::key_type argument_type;
        typedef typename ::boost::property_traits<Map>::value_type result_type;

        explicit property_map_functor(Map& map);
        result_type operator()(argument_type const& arg) const;
    };

    template <typename Map>
    inline property_map_functor<Map>::property_map_functor(Map& map) : _map(map)
    {
    }

    template <typename Map>
    inline typename property_map_functor<Map>::result_type
        property_map_functor<Map>::operator()(argument_type const& arg) const
    {
        return get(this->_map, arg);
    }
}}  // namespace odds_and_ends::graph

#endif  // ODDS_AND_ENDS__GRAPH__PROPERTY_MAP_FUNCTOR_HPP

