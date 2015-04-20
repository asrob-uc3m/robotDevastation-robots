// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "DoubleHBridge.hpp"

namespace rd
{

bool DoubleHBridge::getAxes(int *axes)
{
    *axes = gpios.size();
    return true;
}

bool DoubleHBridge::setPositionMode()
{
    CD_INFO("\n");

    CD_WARNING("Not implemented yet.\n");

    return true;
}

bool DoubleHBridge::positionMove(int j, double ref)
{  // encExposed = ref;
    CD_INFO("(%d,%f)\n",j,ref);

    //-- Check index within range
    if ( ! this->indexWithinRange(j) ) return false;

    return true;
}

bool DoubleHBridge::positionMove(const double *refs)
{  // encExposed = refs;
    CD_INFO("\n");

    CD_WARNING("Not implemented yet.\n");

    return true;
}

bool DoubleHBridge::relativeMove(int j, double delta)
{
    CD_INFO("(%d, %f)\n",j,delta);

    //-- Check index within range
    if ( ! this->indexWithinRange(j) ) return false;

    CD_WARNING("Not implemented yet.\n");

    return true;
}

bool DoubleHBridge::relativeMove(const double *deltas)
{  // encExposed = deltas + encExposed

    CD_WARNING("Not implemented yet.\n");

    return true;
}

bool DoubleHBridge::checkMotionDone(int j, bool *flag)
{
    CD_INFO("(%d)\n",j);

    CD_WARNING("Not implemented yet.\n");

    return true;
}

bool DoubleHBridge::checkMotionDone(bool *flag)
{
    CD_INFO("\n");

    bool ok = true;
    for(int j=0; j<gpios.size(); j++)
    {
        ok &= this->checkMotionDone(j,&flag[j]);
    }
    return ok;
}

bool DoubleHBridge::setRefSpeed(int j, double sp)
{
    CD_INFO("(%d, %f)\n",j,sp);

    //-- Check index within range
    if ( ! this->indexWithinRange(j) ) return false;

    return true;
}

bool DoubleHBridge::setRefSpeeds(const double *spds)
{
    CD_INFO("\n");

    bool ok = true;
    for(unsigned int i=0;i<gpios.size();i++)
        ok &= setRefSpeed(i,spds[i]);
    return ok;
}

bool DoubleHBridge::setRefAcceleration(int j, double acc)
{
    CD_INFO("(%d, %f)\n",j,acc);

    //-- Check index within range
    if ( ! this->indexWithinRange(j) ) return false;

    CD_WARNING("Not implemented yet.\n");

    return true;
}

bool DoubleHBridge::setRefAccelerations(const double *accs)
{
    CD_INFO("\n");

    bool ok = true;
    for(unsigned int i=0;i<gpios.size();i++)
        ok &= setRefAcceleration(i,accs[i]);
    return ok;
}

bool DoubleHBridge::getRefSpeed(int j, double *ref)
{
    CD_INFO("(%d)\n",j);

    //-- Check index within range
    if ( ! this->indexWithinRange(j) ) return false;

    CD_WARNING("Not implemented yet.\n");

    return true;
}

bool DoubleHBridge::getRefSpeeds(double *spds)
{
    CD_INFO("\n");

    bool ok = true;
    for(unsigned int i=0;i<gpios.size();i++)
        ok &= getRefSpeed(i,&spds[i]);
    return ok;
}

bool DoubleHBridge::getRefAcceleration(int j, double *acc)
{
    CD_INFO("(%d)\n",j);

    //-- Check index within range
    if ( ! this->indexWithinRange(j) ) return false;

    CD_WARNING("Not implemented yet.\n");

    return true;
}

bool DoubleHBridge::getRefAccelerations(double *accs)
{
    CD_INFO("\n");

    bool ok = true;
    for(unsigned int i=0;i<gpios.size();i++)
        ok &= getRefAcceleration(i,&accs[i]);
    return ok;
}

bool DoubleHBridge::stop(int j){
    CD_INFO("(%d)\n",j);

    //-- Check index within range
    if ( ! this->indexWithinRange(j) ) return false;

    // Clear and start again
    clear_channel_gpio(0, gpios[j]);
    add_channel_pulse(0, gpios[j], 0, 0);

    return true;
}

bool DoubleHBridge::stop()
{
    CD_INFO("\n");

    bool ok = true;
    for(unsigned int i=0;i<gpios.size();i++)
        ok &= stop(i);
    return ok;
}

}  // namespace rd
