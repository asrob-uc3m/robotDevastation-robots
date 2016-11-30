// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "LaserTowerOfDeath.hpp"

namespace rd
{

const int LaserTowerOfDeath::LEFT_MOTOR_IN1 = 24;
const int LaserTowerOfDeath::LEFT_MOTOR_IN2 = 23;

const int LaserTowerOfDeath::RIGHT_MOTOR_IN1 = 22;
const int LaserTowerOfDeath::RIGHT_MOTOR_IN2 = 21;

bool LaserTowerOfDeath::indexWithinRange(const int& idx)
{
    if (idx >= gpios.size() ){
        CD_WARNING("Index out of range!! (%d >= " CD_SIZE_T ")!!!\n",idx,gpios.size());
        return false;
    }
    return true;
}


bool LaserTowerOfDeath::moveForward(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    digitalWrite(LEFT_MOTOR_IN1, 1);
    digitalWrite(LEFT_MOTOR_IN2, 0);
    digitalWrite(RIGHT_MOTOR_IN1, 1);
    digitalWrite(RIGHT_MOTOR_IN2, 0);
    return true;
}

bool LaserTowerOfDeath::moveBackwards(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    digitalWrite(LEFT_MOTOR_IN1, 0);
    digitalWrite(LEFT_MOTOR_IN2, 1);
    digitalWrite(RIGHT_MOTOR_IN1, 0);
    digitalWrite(RIGHT_MOTOR_IN2, 1);

    return true;
}

bool LaserTowerOfDeath::turnLeft(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    digitalWrite(LEFT_MOTOR_IN1, 0);
    digitalWrite(LEFT_MOTOR_IN2, 1);
    digitalWrite(RIGHT_MOTOR_IN1, 1);
    digitalWrite(RIGHT_MOTOR_IN2, 0);

    return true;
}

bool LaserTowerOfDeath::turnRight(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    digitalWrite(LEFT_MOTOR_IN1, 1);
    digitalWrite(LEFT_MOTOR_IN2, 0);
    digitalWrite(RIGHT_MOTOR_IN1, 0);
    digitalWrite(RIGHT_MOTOR_IN2, 1);

    return true;
}

bool LaserTowerOfDeath::stopMovement()
{
    CD_INFO(".\n");

    digitalWrite(LEFT_MOTOR_IN1, 1);
    digitalWrite(LEFT_MOTOR_IN2, 1);
    digitalWrite(RIGHT_MOTOR_IN1, 1);
    digitalWrite(RIGHT_MOTOR_IN2, 1);

    return true;
}

//-- Robot camera related functions
bool LaserTowerOfDeath::tiltUp(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool LaserTowerOfDeath::tiltDown(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool LaserTowerOfDeath::panLeft(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool LaserTowerOfDeath::panRight(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool LaserTowerOfDeath::stopCameraMovement()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool LaserTowerOfDeath::connect()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}


bool LaserTowerOfDeath::disconnect()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool LaserTowerOfDeath::test()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

void LaserTowerOfDeath::setEnabled(bool enabled)
{
    CD_ERROR("Not implemented yet\n");
    return;
}

void LaserTowerOfDeath::onDestroy()
{
    CD_ERROR("Not implemented yet\n");
    return;
}

}  // namespace rd
