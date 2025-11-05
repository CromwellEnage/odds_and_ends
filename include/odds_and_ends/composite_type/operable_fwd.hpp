// Copyright (C) 2012-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__COMPOSITE_TYPE__OPERABLE_FWD_HPP
#define ODDS_AND_ENDS__COMPOSITE_TYPE__OPERABLE_FWD_HPP

namespace odds_and_ends { namespace composite_type {

    template <typename CompositeParentGenerator>
    struct pre_increment_operable;

    template <typename CompositeParentGenerator>
    struct increment_operable;

    template <typename CompositeParentGenerator>
    struct pre_decrement_operable;

    template <typename CompositeParentGenerator>
    struct decrement_operable;

    template <typename CompositeParentGenerator>
    struct addition_operable;

    template <typename CompositeParentGenerator>
    struct subtraction_operable;

    template <typename CompositeParentGenerator>
    struct multiplication_operable;

    template <typename CompositeParentGenerator>
    struct division_operable;

    template <typename CompositeParentGenerator>
    struct modulo_operable;

    template <typename CompositeParentGenerator>
    struct bit_and_operable;

    template <typename CompositeParentGenerator>
    struct bit_or_operable;

    template <typename CompositeParentGenerator>
    struct bit_xor_operable;

    template <typename CompositeParentGenerator>
    struct left_shift_operable;

    template <typename CompositeParentGenerator>
    struct right_shift_operable;
}}  // namespace odds_and_ends::composite_type

#endif  // ODDS_AND_ENDS__COMPOSITE_TYPE__OPERABLE_FWD_HPP

