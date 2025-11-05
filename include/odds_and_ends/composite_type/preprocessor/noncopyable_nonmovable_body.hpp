// Copyright (C) 2012-2025 Cromwell D. Enage

#ifndef ODDS_AND_ENDS__COMPOSITE_TYPE__PP__NONCOPYABLE_NONMOVABLE_BODY_HPP
#define ODDS_AND_ENDS__COMPOSITE_TYPE__PP__NONCOPYABLE_NONMOVABLE_BODY_HPP

#define ODDS_AND_ENDS__COMPOSITE_TYPE__NONCOPYABLE_NONMOVABLE_BODY(Type)     \
    protected:                                                               \
    Type(Type const&) = delete;                                              \
    Type(Type&&) = delete;                                                   \
    Type& operator=(Type const&) = delete;                                   \
    Type& operator=(Type&&) = delete;                                        \
    // ODDS_AND_ENDS__COMPOSITE_TYPE__NONCOPYABLE_NONMOVABLE_BODY

#endif  // ODDS_AND_ENDS__COMPOSITE_TYPE__PP__NONCOPYABLE_NONMOVABLE_BODY_HPP

