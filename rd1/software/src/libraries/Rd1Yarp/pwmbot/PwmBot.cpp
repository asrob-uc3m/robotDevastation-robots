// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "PwmBot.hpp"

// -----------------------------------------------------------------------------

bool PwmBot::indexWithinRange(const int& idx) {
    if (idx >= gpios.size() ){
        CD_WARNING("Index out of range!! (%d >= " CD_SIZE_T ")!!!\n",idx,gpios.size());
        return false;
    }
    return true;
}

// -----------------------------------------------------------------------------
