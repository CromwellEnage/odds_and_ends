// Copyright (C) 2011-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__NODE__TRAVERSAL_STATE_HPP
#define ODDS_AND_ENDS__NODE__TRAVERSAL_STATE_HPP

namespace odds_and_ends { namespace node {

    struct traversal_state
    {
        typedef unsigned char value_tye;

        inline explicit traversal_state(value_tye const& b) : _value(b)
        {
        }

        inline value_tye get() const
        {
            return this->_value;
        }

    private:
        value_tye _value;
    };

    inline bool operator==(traversal_state const& lhs, traversal_state const& rhs)
    {
        return lhs.get() == rhs.get();
    }

    inline bool operator!=(traversal_state const& lhs, traversal_state const& rhs)
    {
        return lhs.get() != rhs.get();
    }

    static traversal_state const no_traversal = traversal_state(0);
    static traversal_state const breadth_first_traversal = traversal_state(1);
    static traversal_state const pre_order_traversal = traversal_state(2);
    static traversal_state const post_order_traversal = traversal_state(3);
    static traversal_state const in_order_traversal = traversal_state(4);
}}  // namespace odds_and_ends::node

#endif  // ODDS_AND_ENDS__NODE__TRAVERSAL_STATE_HPP

