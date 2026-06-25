// Copyright (C) 2012-2026 Cromwell D. Enage
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

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

