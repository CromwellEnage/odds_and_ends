// Copyright (C) 2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__GRAPH___DETAIL__EDGE_ITERATOR_HPP
#define ODDS_AND_ENDS__GRAPH___DETAIL__EDGE_ITERATOR_HPP

#include <boost/graph/graph_traits.hpp>
#include <boost/mpl/apply_wrap.hpp>

namespace odds_and_ends { namespace graph { namespace _detail {

    template <typename Graph, typename PtrXForm, typename IndexDiff>
    class edge_iterator
    {
        typedef typename ::boost::mpl::apply_wrap1<PtrXForm,Graph const>::type _graph_ptr;

    public:
        typedef typename ::boost::graph_traits<Graph>::edge_descriptor const value_type;
        typedef value_type& reference;
        typedef typename ::boost::mpl::apply_wrap1<PtrXForm,value_type>::type pointer;
        typedef IndexDiff difference_type;

    private:
        _graph_ptr _g;
        typename ::boost::graph_traits<Graph>::edges_size_type _current_index;
        typename ::boost::graph_traits<Graph>::edge_descriptor _current_edge;

    public:
        edge_iterator();
        edge_iterator(Graph const& g, typename ::boost::graph_traits<Graph>::edges_size_type i);
        reference operator*() const;
        pointer operator->() const;
        edge_iterator& operator++();
        edge_iterator operator++(int);
        edge_iterator& operator--();
        edge_iterator operator--(int);
        edge_iterator& operator+=(difference_type const& d);
        edge_iterator operator+(difference_type const& d) const;
        edge_iterator& operator-=(difference_type const& d);
        edge_iterator operator-(difference_type const& d) const;

    private:
        friend inline bool operator==(edge_iterator const& lhs, edge_iterator const& rhs)
        {
            return lhs._current_index == rhs._current_index;
        }

        friend inline bool operator!=(edge_iterator const& lhs, edge_iterator const& rhs)
        {
            return lhs._current_index != rhs._current_index;
        }

        friend inline bool operator<(edge_iterator const& lhs, edge_iterator const& rhs)
        {
            return lhs._current_index < rhs._current_index;
        }

        friend inline bool operator<=(edge_iterator const& lhs, edge_iterator const& rhs)
        {
            return lhs._current_index <= rhs._current_index;
        }

        friend inline bool operator>(edge_iterator const& lhs, edge_iterator const& rhs)
        {
            return lhs._current_index > rhs._current_index;
        }

        friend inline bool operator>=(edge_iterator const& lhs, edge_iterator const& rhs)
        {
            return lhs._current_index >= rhs._current_index;
        }

        friend inline difference_type
            operator-(edge_iterator const& lhs, edge_iterator const& rhs)
        {
            difference_type d = static_cast<difference_type>(lhs._current_index);
            d -= rhs._current_index;
            return d;
        }
    };

    template <typename Graph, typename PtrXForm, typename IndexDiff>
    inline typename edge_iterator<Graph,PtrXForm,IndexDiff>::reference
        edge_iterator<Graph,PtrXForm,IndexDiff>::operator*() const
    {
        return this->_current_edge;
    }
}}}  // namespace odds_and_ends::graph::_detail

#include <boost/utility/value_init.hpp>

namespace odds_and_ends { namespace graph { namespace _detail {

    template <typename Graph, typename PtrXForm, typename IndexDiff>
    inline edge_iterator<Graph,PtrXForm,IndexDiff>::edge_iterator() :
        _g(nullptr), _current_index(::boost::initialized_value), _current_edge(Graph::null_edge())
    {
    }
}}}  // namespace odds_and_ends::graph::_detail

#include <memory>

namespace odds_and_ends { namespace graph { namespace _detail {

    template <typename Graph, typename PtrXForm, typename IndexDiff>
    inline edge_iterator<Graph,PtrXForm,IndexDiff>::edge_iterator(
        Graph const& g,
        typename ::boost::graph_traits<Graph>::edges_size_type i
    ) : _g(::std::pointer_traits<_graph_ptr>::pointer_to(g)),
        _current_index(i),
        _current_edge(edge(i, g))
    {
    }

    template <typename Graph, typename PtrXForm, typename IndexDiff>
    inline typename edge_iterator<Graph,PtrXForm,IndexDiff>::pointer
        edge_iterator<Graph,PtrXForm,IndexDiff>::operator->() const
    {
        return ::std::pointer_traits<pointer>::pointer_to(this->_current_edge);
    }

    template <typename Graph, typename PtrXForm, typename IndexDiff>
    inline edge_iterator<Graph,PtrXForm,IndexDiff>&
        edge_iterator<Graph,PtrXForm,IndexDiff>::operator++()
    {
        this->_current_edge = edge((++this->_current_index), *this->_g);
        return *this;
    }

    template <typename Graph, typename PtrXForm, typename IndexDiff>
    inline edge_iterator<Graph,PtrXForm,IndexDiff>
        edge_iterator<Graph,PtrXForm,IndexDiff>::operator++(int)
    {
        edge_iterator<Graph,PtrXForm,IndexDiff> itr(*this);
        ++(*this);
        return itr;
    }

    template <typename Graph, typename PtrXForm, typename IndexDiff>
    inline edge_iterator<Graph,PtrXForm,IndexDiff>&
        edge_iterator<Graph,PtrXForm,IndexDiff>::operator--()
    {
        this->_current_edge = edge((--this->_current_index), *this->_g);
        return *this;
    }

    template <typename Graph, typename PtrXForm, typename IndexDiff>
    inline edge_iterator<Graph,PtrXForm,IndexDiff>
        edge_iterator<Graph,PtrXForm,IndexDiff>::operator--(int)
    {
        edge_iterator<Graph,PtrXForm,IndexDiff> itr(*this);
        --(*this);
        return itr;
    }

    template <typename Graph, typename PtrXForm, typename IndexDiff>
    inline edge_iterator<Graph,PtrXForm,IndexDiff>&
        edge_iterator<Graph,PtrXForm,IndexDiff>::operator+=(difference_type const& d)
    {
        this->_current_edge = edge((this->_current_index += d), *this->_g);
        return *this;
    }

    template <typename Graph, typename PtrXForm, typename IndexDiff>
    inline edge_iterator<Graph,PtrXForm,IndexDiff>
        edge_iterator<Graph,PtrXForm,IndexDiff>::operator+(difference_type const& d) const
    {
        edge_iterator<Graph,PtrXForm,IndexDiff> itr(*this);
        itr += d;
        return itr;
    }

    template <typename Graph, typename PtrXForm, typename IndexDiff>
    inline edge_iterator<Graph,PtrXForm,IndexDiff>&
        edge_iterator<Graph,PtrXForm,IndexDiff>::operator-=(difference_type const& d)
    {
        this->_current_edge = edge((this->_current_index -= d), *this->_g);
        return *this;
    }

    template <typename Graph, typename PtrXForm, typename IndexDiff>
    inline edge_iterator<Graph,PtrXForm,IndexDiff>
        edge_iterator<Graph,PtrXForm,IndexDiff>::operator-(difference_type const& d) const
    {
        edge_iterator<Graph,PtrXForm,IndexDiff> itr(*this);
        itr -= d;
        return itr;
    }
}}}  // namespace odds_and_ends::graph::_detail

#endif  // ODDS_AND_ENDS__GRAPH___DETAIL__EDGE_ITERATOR_HPP

