// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "EmptyBot.hpp"

// ------------------ IEncoder Related -----------------------------------------

bool EmptyBot::resetEncoder(int j) {
    CD_INFO("(%d)\n",j);

    //-- Check index within range
    if ( ! this->indexWithinRange(j) ) return false;

    CD_WARNING("Not implemented yet.\n");

    return true;
}

// -----------------------------------------------------------------------------

bool EmptyBot::resetEncoders() {
    CD_INFO("\n");

    CD_WARNING("Not implemented yet.\n");

    return true;
}

// -----------------------------------------------------------------------------

bool EmptyBot::setEncoder(int j, double val) {  // encExposed = val;
    CD_INFO("(%d,%f)\n",j,val);

    //-- Check index within range
    if ( ! this->indexWithinRange(j) ) return false;

    CD_WARNING("Not implemented yet.\n");

    return true;
}

// -----------------------------------------------------------------------------

bool EmptyBot::setEncoders(const double *vals) {
    CD_INFO("\n");

    bool ok = true;
    for(unsigned int i=0; i < numMotors; i++)
        ok &= setEncoder(i,vals[i]);
    return ok;
}

// -----------------------------------------------------------------------------

bool EmptyBot::getEncoder(int j, double *v) {
    //CD_INFO("%d\n",j);  //-- Too verbose in stream.

    //-- Check index within range
    if ( ! this->indexWithinRange(j) ) return false;

    return true;
}

// -----------------------------------------------------------------------------

bool EmptyBot::getEncoders(double *encs) {
    //CD_INFO("\n");  //-- Too verbose in stream.

    bool ok = true;
    for(unsigned int i=0; i < numMotors; i++)
        ok &= getEncoder(i,&encs[i]);
    return ok;
}

// -----------------------------------------------------------------------------

bool EmptyBot::getEncoderSpeed(int j, double *sp) {
    CD_INFO("(%d)\n",j);

    //-- Check index within range
    if ( ! this->indexWithinRange(j) ) return false;

    CD_WARNING("Not implemented yet.\n");

    return true;
}

// -----------------------------------------------------------------------------

bool EmptyBot::getEncoderSpeeds(double *spds) {
    CD_INFO("\n");

    bool ok = true;
    for(unsigned int i=0;i<numMotors;i++)
        ok &= getEncoderSpeed(i,&spds[i]);
    return ok;
}

// -----------------------------------------------------------------------------

bool EmptyBot::getEncoderAcceleration(int j, double *spds) {
    CD_INFO("(%d)\n",j);

    //-- Check index within range
    if ( ! this->indexWithinRange(j) ) return false;

    CD_WARNING("Not implemented yet.\n");

    return true;
}

// -----------------------------------------------------------------------------

bool EmptyBot::getEncoderAccelerations(double *accs) {
    CD_INFO("\n");

    CD_WARNING("Not implemented yet.\n");

    return true;
}

// -----------------------------------------------------------------------------

