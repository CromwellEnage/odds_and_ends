// Copyright (C) 2011-2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__AUTOMATON__INPUT_RULE__CELLULAR_GRAPH_HPP
#define ODDS_AND_ENDS__AUTOMATON__INPUT_RULE__CELLULAR_GRAPH_HPP

#include <odds_and_ends/use_default_policy.hpp>

namespace odds_and_ends { namespace automaton {

    template <typename Graph, typename ContainerGen = ::odds_and_ends::use_default_policy>
    class cellular_graph_input_rule
    {
        Graph const& _g;

    public:
        typedef bool result_type;

        explicit cellular_graph_input_rule(Graph const& g);

        template <typename CellMap>
        bool operator()(CellMap& cell_map) const;

    private:
        template <typename CellMap, typename StateMap>
        bool _process_input(CellMap& cell_map, StateMap state_map) const;
    };

    template <typename Graph, typename ContainerGen>
    inline cellular_graph_input_rule<Graph,ContainerGen>::cellular_graph_input_rule(
        Graph const& g
    ) : _g(g)
    {
    }
}}  // namespace odds_and_ends::automaton

#include <utility>
#include <odds_and_ends/graph/property_map_functor.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/iterator/transform_iterator.hpp>

namespace odds_and_ends { namespace automaton {

    template <typename Graph, typename ContainerGen>
    template <typename CellMap, typename StateMap>
    bool
        cellular_graph_input_rule<Graph,ContainerGen>::_process_input(
            CellMap& cell_map,
            StateMap state_map
        ) const
    {
        typename ::boost::graph_traits<Graph>::vertex_iterator v_itr, v_end;

        for (::std::tie(v_itr, v_end) = vertices(this->_g); v_itr != v_end; ++v_itr)
        {
            put(state_map, *v_itr, get(cell_map, *v_itr).get_state());
        }

        ::odds_and_ends::graph::property_map_functor<StateMap> getter(state_map);
        typename ::boost::graph_traits<Graph>::adjacency_iterator a_itr, a_end;
        bool result = false;

        for (::std::tie(v_itr, v_end) = vertices(this->_g); v_itr != v_end; ++v_itr)
        {
            ::std::tie(a_itr, a_end) = adjacent_vertices(*v_itr, this->_g);

            if (
                get(cell_map, *v_itr)(
                    ::std::make_pair(
                        ::boost::make_transform_iterator(a_itr, getter),
                        ::boost::make_transform_iterator(a_end, getter)
                    )
                )
            )
            {
                result = true;
            }
        }

        return result;
    }
}}  // namespace odds_and_ends::automaton

#include <vector>
#include <boost/graph/properties.hpp>
#include <boost/property_map/property_map.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/apply_wrap.hpp>

namespace odds_and_ends { namespace automaton {

    template <typename Graph, typename ContainerGen>
    template <typename CellMap>
    inline bool cellular_graph_input_rule<Graph,ContainerGen>::operator()(CellMap& cell_map) const
    {
        typedef typename ::boost::property_traits<CellMap>::value_type::traits::state_type State;
        typename ::boost::mpl::eval_if<
            ::std::is_same<ContainerGen,::odds_and_ends::use_default_policy>,
            ::boost::mpl::identity< ::std::vector<State> >,
            ::boost::mpl::apply_wrap1<ContainerGen,State>
        >::type machines(num_vertices(this->_g));
        return this->_process_input(
            cell_map,
            ::boost::make_iterator_property_map(
                machines.begin(),
                get(::boost::vertex_index, this->_g)
            )
        );
    }
}}  // namespace odds_and_ends::automaton

#endif  // ODDS_AND_ENDS__AUTOMATON__INPUT_RULE__CELLULAR_GRAPH_HPP

