// Copyright (C) 2026 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__PARAMETER__TEMPLATE_HPP
#define ODDS_AND_ENDS__NODE__PARAMETER__TEMPLATE_HPP

#include <boost/parameter/template_keyword.hpp>

namespace odds_and_ends { namespace node { namespace parameter {
    namespace tag {

        struct _node_parent_generator_list;
        struct _balancer;
        struct _compare_generator;
        struct _container_generator;
        struct _size;
        struct _difference;
        struct _pointer_transform;
        struct _allocator_transform;
    }  // namespace tag

    template <typename T>
    struct _node_parent_generator_list :
        ::boost::parameter::template_keyword<
            ::odds_and_ends::node::parameter::tag::_node_parent_generator_list,
            T
        >
    {
    };

    template <typename T>
    struct _balancer :
        ::boost::parameter::template_keyword<
            ::odds_and_ends::node::parameter::tag::_balancer,
            T
        >
    {
    };

    template <typename T>
    struct _compare_generator :
        ::boost::parameter::template_keyword<
            ::odds_and_ends::node::parameter::tag::_compare_generator,
            T
        >
    {
    };

    template <typename T>
    struct _container_generator :
        ::boost::parameter::template_keyword<
            ::odds_and_ends::node::parameter::tag::_container_generator,
            T
        >
    {
    };

    template <typename T>
    struct _size :
        ::boost::parameter::template_keyword<
            ::odds_and_ends::node::parameter::tag::_size,
            T
        >
    {
    };

    template <typename T>
    struct _difference :
        ::boost::parameter::template_keyword<
            ::odds_and_ends::node::parameter::tag::_difference,
            T
        >
    {
    };

    template <typename T>
    struct _pointer_transform :
        ::boost::parameter::template_keyword<
            ::odds_and_ends::node::parameter::tag::_pointer_transform,
            T
        >
    {
    };

    template <typename T>
    struct _allocator_transform :
        ::boost::parameter::template_keyword<
            ::odds_and_ends::node::parameter::tag::_allocator_transform,
            T
        >
    {
    };
}}}  // namespace odds_and_ends::node::parameter

#endif  // ODDS_AND_ENDS__NODE__PARAMETER__TEMPLATE_HPP

