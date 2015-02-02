// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "EmptyBot.hpp"

// -----------------------------------------------------------------------------

bool EmptyBot::indexWithinRange(const int& idx) {
    if (idx >= numMotors ){
        CD_WARNING("Index out of range!! (%d >= %d)!!!\n",idx,numMotors);
        return false;
    }
    return true;
}

// -----------------------------------------------------------------------------

