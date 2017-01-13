// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "FakeMotorController.hpp"

namespace rd
{

bool FakeMotorController::indexWithinRange(const int& idx)
{
    if (idx >= gpios.size() ){
        CD_WARNING("Index out of range!! (%d >= " CD_SIZE_T ")!!!\n",idx,gpios.size());
        return false;
    }
    return true;
}

bool FakeMotorController::moveForward(int velocity)
{
    CD_INFO("%d.\n",velocity);
    return true;
}

bool FakeMotorController::moveBackwards(int velocity)
{
    CD_INFO("%d.\n",velocity);
    return true;
}

bool FakeMotorController::turnLeft(int velocity)
{
    CD_INFO("%d.\n",velocity);
    return true;
}

bool FakeMotorController::turnRight(int velocity)
{
    CD_INFO("%d.\n",velocity);
    return true;
}

bool FakeMotorController::stopMovement()
{
    CD_INFO("\n");
    return true;
}

bool FakeMotorController::tiltUp(int velocity)
{
    CD_INFO("%d.\n",velocity);
    return true;
}

bool FakeMotorController::tiltDown(int velocity)
{
    CD_INFO("%d.\n",velocity);
    return true;
}

bool FakeMotorController::panLeft(int velocity)
{
    CD_INFO("%d.\n",velocity);
    return true;
}

bool FakeMotorController::panRight(int velocity)
{
    CD_INFO("%d.\n",velocity);
    return true;
}

bool FakeMotorController::stopCameraMovement()
{
    CD_INFO("\n");
    return true;
}

bool FakeMotorController::connect()
{
    CD_INFO("\n");
    return true;
}


bool FakeMotorController::disconnect()
{
    CD_INFO("\n");
    return true;
}

bool FakeMotorController::test()
{
    CD_INFO("\n");
    return true;
}

void FakeMotorController::setEnabled(bool enabled)
{
    CD_INFO("\n");
    return;
}

void FakeMotorController::onDestroy()
{
    CD_INFO("\n");
    return;
}

}  // namespace rd

