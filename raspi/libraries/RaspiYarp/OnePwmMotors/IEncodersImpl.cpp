// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "OnePwmMotors.hpp"

namespace rd
{

bool OnePwmMotors::resetEncoder(int j)
{
    CD_INFO("(%d)\n",j);

    //-- Check index within range
    if ( ! this->indexWithinRange(j) ) return false;

    CD_WARNING("Not implemented yet.\n");

    return true;
}

bool OnePwmMotors::resetEncoders()
{
    CD_INFO("\n");

    CD_WARNING("Not implemented yet.\n");

    return true;
}

bool OnePwmMotors::setEncoder(int j, double val)
{  // encExposed = val;
    CD_INFO("(%d,%f)\n",j,val);

    //-- Check index within range
    if ( ! this->indexWithinRange(j) ) return false;

    CD_WARNING("Not implemented yet.\n");

    return true;
}

bool OnePwmMotors::setEncoders(const double *vals)
{
    CD_INFO("\n");

    bool ok = true;
    for(unsigned int i=0; i < gpios.size(); i++)
        ok &= setEncoder(i,vals[i]);
    return ok;
}

bool OnePwmMotors::getEncoder(int j, double *v)
{
    //CD_INFO("%d\n",j);  //-- Too verbose in stream.

    //-- Check index within range
    if ( ! this->indexWithinRange(j) ) return false;

    return true;
}

bool OnePwmMotors::getEncoders(double *encs)
{
    //CD_INFO("\n");  //-- Too verbose in stream.

    bool ok = true;
    for(unsigned int i=0; i < gpios.size(); i++)
        ok &= getEncoder(i,&encs[i]);
    return ok;
}

bool OnePwmMotors::getEncoderSpeed(int j, double *sp)
{
    //CD_INFO("(%d)\n",j);  //-- Too verbose in controlboardwrapper2 stream.

    //-- Check index within range
    if ( ! this->indexWithinRange(j) ) return false;

    //CD_WARNING("Not implemented yet.\n");  //-- Too verbose in controlboardwrapper2 stream.

    return true;
}

bool OnePwmMotors::getEncoderSpeeds(double *spds)
{
    CD_INFO("\n");

    bool ok = true;
    for(unsigned int i=0;i<gpios.size();i++)
        ok &= getEncoderSpeed(i,&spds[i]);
    return ok;
}

bool OnePwmMotors::getEncoderAcceleration(int j, double *spds)
{
    //CD_INFO("(%d)\n",j);  //-- Too verbose in controlboardwrapper2 stream.

    //-- Check index within range
    if ( ! this->indexWithinRange(j) ) return false;

    //CD_WARNING("Not implemented yet.\n");  //-- Too verbose in controlboardwrapper2 stream.

    return true;
}

bool OnePwmMotors::getEncoderAccelerations(double *accs)
{
    CD_INFO("\n");

    CD_WARNING("Not implemented yet.\n");

    return true;
}

}  // namespace rd

