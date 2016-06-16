// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "RdOnePwmMotors.hpp"

namespace rd
{

bool RdOnePwmMotors::indexWithinRange(const int& idx)
{
    if (idx >= gpios.size() ){
        CD_WARNING("Index out of range!! (%d >= " CD_SIZE_T ")!!!\n",idx,gpios.size());
        return false;
    }
    return true;
}

bool RdOnePwmMotors::moveForward(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdOnePwmMotors::moveBackwards(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdOnePwmMotors::turnLeft(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdOnePwmMotors::turnRight(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdOnePwmMotors::stopMovement()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

//-- Robot camera related functions
bool RdOnePwmMotors::tiltUp(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdOnePwmMotors::tiltDown(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdOnePwmMotors::panLeft(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdOnePwmMotors::panRight(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdOnePwmMotors::stopCameraMovement()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdOnePwmMotors::connect()
{
    CD_INFO("\n");
    return true;
}


bool RdOnePwmMotors::disconnect()
{
    CD_INFO("\n");
    return true;
}

bool RdOnePwmMotors::test()
{
    CD_INFO("\n");
    return true;
}

void RdOnePwmMotors::setEnabled(bool enabled)
{
    CD_INFO("\n");
    return;
}

void RdOnePwmMotors::onDestroy()
{
    CD_INFO("\n");
    return;
}

}  // namespace rd
