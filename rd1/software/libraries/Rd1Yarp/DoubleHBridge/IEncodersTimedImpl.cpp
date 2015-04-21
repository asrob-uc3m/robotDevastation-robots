// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "DoubleHBridge.hpp"

namespace rd
{

bool DoubleHBridge::getEncodersTimed(double *encs, double *time)
{
    CD_INFO("\n");

    bool ok = true;
    for(unsigned int i=0; i < DEFAULT_NUM_MOTORS; i++)
        ok &= getEncoderTimed(i,&(encs[i]),&(time[i]));
    return ok;
}

bool DoubleHBridge::getEncoderTimed(int j, double *encs, double *time)
{
    //CD_INFO("(%d)\n",j);  //-- Too verbose in controlboardwrapper2 stream.

    *time = yarp::os::Time::now();
    return this->getEncoder( j, &(encs[j]) );
}

}  // namespace rd

