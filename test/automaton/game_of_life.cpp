// Copyright (C) 2011-2026 Cromwell D. Enage

#include <odds_and_ends/graph/orthodiagrid.hpp>

typedef ::odds_and_ends::graph::orthodiagrid<> Graph;

#include <vector>
#include <odds_and_ends/automaton/base.hpp>
#include <odds_and_ends/automaton/transition_function/totalistic_boolean_cell.hpp>
#include <odds_and_ends/automaton/transition_function/input_rule.hpp>
#include <odds_and_ends/automaton/input_rule/cellular_graph.hpp>
#include <odds_and_ends/composite_type/composite_type.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/properties.hpp>
#include <boost/property_map/property_map.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/core/lightweight_test.hpp>

class life_program
{
    Graph _g;
    ::odds_and_ends::automaton::cellular_graph_input_rule<Graph> _rule;

    life_program() : _g(5, 5, true, true), _rule(_g)
    {
    }

    life_program(life_program const& copy);
    life_program& operator=(life_program const& copy);
    ~life_program() {}

public:
    static life_program const& get_instance()
    {
        static life_program instance;
        return instance;
    }

private:
    template <typename CellMap>
    void _run(CellMap cell_map, ::std::vector< ::std::vector<bool> > tests) const
    {
        typedef ::odds_and_ends::automaton::input_rule_transition_function<CellMap> TFunction;

        ::odds_and_ends::composite_type::composite_type<
            ::boost::mpl::deque< ::odds_and_ends::automaton::base<TFunction> >
        > game_of_life(TFunction(), cell_map);
        ::boost::graph_traits<Graph>::vertices_size_type j;

        for (::std::size_t i = 0; i < tests.size() << 1; ++i)
        {
            BOOST_TEST(game_of_life(this->_rule));

            for (j = 0; j < num_vertices(this->_g); ++j)
            {
                BOOST_TEST(
                    get(game_of_life.get_state(), vertex(j, this->_g)).get_state() ==
                    tests[i % tests.size()][j]
                );
            }
        }
    }

public:
    void run(::std::vector< ::std::vector<bool> > tests) const
    {
        typedef ::odds_and_ends::automaton
        ::totalistic_boolean_cell_transition_function<> CellFunction;
        typedef ::odds_and_ends::composite_type::composite_type<
            ::boost::mpl::deque< ::odds_and_ends::automaton::base<CellFunction> >
        > Cell;

        CellFunction cell_function;

        cell_function |= 3;
        cell_function &= 2, 3;

        ::std::vector<Cell> cells(num_vertices(this->_g), Cell(cell_function));

        cells[0](true);
        cells[2](true);
        cells[6](true);
        cells[7](true);
        cells[11](true);

        this->_run(
            ::boost::make_iterator_property_map(
                cells.begin(),
                get(::boost::vertex_index, this->_g)
            ),
            tests
        );
    }
};

int main()
{
    life_program::get_instance().run({
        {
            false, false, true , false, false,
            true , false, true , false, false,
            false, true , true , false, false,
            false, false, false, false, false,
            false, false, false, false, false
        },
        {
            false, true , false, false, false,
            false, false, true , true , false,
            false, true , true , false, false,
            false, false, false, false, false,
            false, false, false, false, false
        },
        {
            false, false, true , false, false,
            false, false, false, true , false,
            false, true , true , true , false,
            false, false, false, false, false,
            false, false, false, false, false
        },
        {
            false, false, false, false, false,
            false, true , false, true , false,
            false, false, true , true , false,
            false, false, true , false, false,
            false, false, false, false, false
        },
        {
            false, false, false, false, false,
            false, false, false, true , false,
            false, true , false, true , false,
            false, false, true , true , false,
            false, false, false, false, false
        },
        {
            false, false, false, false, false,
            false, false, true , false, false,
            false, false, false, true , true ,
            false, false, true , true , false,
            false, false, false, false, false
        },
        {
            false, false, false, false, false,
            false, false, false, true , false,
            false, false, false, false, true ,
            false, false, true , true , true ,
            false, false, false, false, false
        },
        {
            false, false, false, false, false,
            false, false, false, false, false,
            false, false, true , false, true ,
            false, false, false, true , true ,
            false, false, false, true , false
        },
        {
            false, false, false, false, false,
            false, false, false, false, false,
            false, false, false, false, true ,
            false, false, true , false, true ,
            false, false, false, true , true
        },
        {
            false, false, false, false, false,
            false, false, false, false, false,
            false, false, false, true , false,
            true , false, false, false, true ,
            false, false, false, true , true
        },
        {
            false, false, false, false, false,
            false, false, false, false, false,
            false, false, false, false, true ,
            true , false, false, false, false,
            true , false, false, true , true
        },
        {
            false, false, false, false, true ,
            false, false, false, false, false,
            false, false, false, false, false,
            true , false, false, true , false,
            true , false, false, false, true
        },
        {
            true , false, false, false, true ,
            false, false, false, false, false,
            false, false, false, false, false,
            true , false, false, false, false,
            true , false, false, true , false
        },
        {
            true , false, false, false, true ,
            false, false, false, false, false,
            false, false, false, false, false,
            false, false, false, false, true ,
            true , true , false, false, false
        },
        {
            true , true , false, false, true ,
            false, false, false, false, false,
            false, false, false, false, false,
            true , false, false, false, false,
            false, true , false, false, false
        },
        {
            true , true , false, false, false,
            true , false, false, false, false,
            false, false, false, false, false,
            false, false, false, false, false,
            false, true , false, false, true
        },
        {
            false, true , false, false, true ,
            true , true , false, false, false,
            false, false, false, false, false,
            false, false, false, false, false,
            false, true , false, false, false
        },
        {
            false, true , true , false, false,
            true , true , false, false, false,
            false, false, false, false, false,
            false, false, false, false, false,
            true , false, false, false, false
        },
        {
            false, false, true , false, false,
            true , true , true , false, false,
            false, false, false, false, false,
            false, false, false, false, false,
            false, true , false, false, false
        },
        {
            true , false, true , false, false,
            false, true , true , false, false,
            false, true , false, false, false,
            false, false, false, false, false,
            false, false, false, false, false
        }
    });
    return ::boost::report_errors();
}

