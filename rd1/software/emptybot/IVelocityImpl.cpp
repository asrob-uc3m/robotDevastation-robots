// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "EmptyBot.hpp"

// ------------------ IVelocity Related ----------------------------------------

bool EmptyBot::setVelocityMode() {
    RD_INFO("\n");

    RD_WARNING("Not implemented yet.\n");

    return true;
}

// -----------------------------------------------------------------------------

bool EmptyBot::velocityMove(int j, double sp) {
    RD_INFO("(%d)\n",j);

    RD_WARNING("Not implemented yet.\n");

    return true;
}

// -----------------------------------------------------------------------------

bool EmptyBot::velocityMove(const double *sp) {
    RD_INFO("\n");

    bool ok = true;
    for(int j=0; j<numMotors; j++)
    {
        ok &= this->velocityMove(j,sp[j]);
    }
    return ok;
}

// -----------------------------------------------------------------------------

