// Copyright (C) 2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__CONTAINER__SET_HPP
#define ODDS_AND_ENDS__NODE__CONTAINER__SET_HPP

#include <odds_and_ends/node/container/map.hpp>
#include <boost/parameter/parameters.hpp>

namespace odds_and_ends { namespace node { namespace container {

    template <
        typename Key,
        typename IsMulti,
        typename T0,
        typename T1,
        typename T2 = ::boost::parameter::void_,
        typename T3 = ::boost::parameter::void_,
        typename T4 = ::boost::parameter::void_,
        typename T5 = ::boost::parameter::void_,
        typename T6 = ::boost::parameter::void_
    >
    using set = ::odds_and_ends::node::container::map<Key,void,IsMulti,T0,T1,T2,T3,T4,T5,T6>;
}}}  // namespace odds_and_ends::node::container

#endif  // ODDS_AND_ENDS__NODE__CONTAINER__SET_HPP

