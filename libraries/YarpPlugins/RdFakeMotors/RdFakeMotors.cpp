// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "RdFakeMotors.hpp"

namespace rd
{

bool RdFakeMotors::indexWithinRange(const int& idx)
{
    if (idx >= gpios.size() ){
        CD_WARNING("Index out of range!! (%d >= " CD_SIZE_T ")!!!\n",idx,gpios.size());
        return false;
    }
    return true;
}

bool RdFakeMotors::moveForward(int velocity)
{
    CD_INFO("%d.\n",velocity);
    return true;
}

bool RdFakeMotors::moveBackwards(int velocity)
{
    CD_INFO("%d.\n",velocity);
    return true;
}

bool RdFakeMotors::turnLeft(int velocity)
{
    CD_INFO("%d.\n",velocity);
    return true;
}

bool RdFakeMotors::turnRight(int velocity)
{
    CD_INFO("%d.\n",velocity);
    return true;
}

bool RdFakeMotors::stopMovement()
{
    CD_INFO("\n");
    return true;
}

bool RdFakeMotors::tiltUp(int velocity)
{
    CD_INFO("%d.\n",velocity);
    return true;
}

bool RdFakeMotors::tiltDown(int velocity)
{
    CD_INFO("%d.\n",velocity);
    return true;
}

bool RdFakeMotors::panLeft(int velocity)
{
    CD_INFO("%d.\n",velocity);
    return true;
}

bool RdFakeMotors::panRight(int velocity)
{
    CD_INFO("%d.\n",velocity);
    return true;
}

bool RdFakeMotors::stopCameraMovement()
{
    CD_INFO("\n");
    return true;
}

bool RdFakeMotors::connect()
{
    CD_INFO("\n");
    return true;
}


bool RdFakeMotors::disconnect()
{
    CD_INFO("\n");
    return true;
}

bool RdFakeMotors::test()
{
    CD_INFO("\n");
    return true;
}

void RdFakeMotors::setEnabled(bool enabled)
{
    CD_INFO("\n");
    return;
}

void RdFakeMotors::onDestroy()
{
    CD_INFO("\n");
    return;
}

}  // namespace rd

