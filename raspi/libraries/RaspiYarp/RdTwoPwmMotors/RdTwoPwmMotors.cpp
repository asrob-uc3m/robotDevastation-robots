// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "RdTwoPwmMotors.hpp"

namespace rd
{

const int RdTwoPwmMotors::LEFT_MOTOR_IN1 = 24;
const int RdTwoPwmMotors::LEFT_MOTOR_IN2 = 23;

const int RdTwoPwmMotors::RIGHT_MOTOR_IN1 = 22;
const int RdTwoPwmMotors::RIGHT_MOTOR_IN2 = 21;

bool RdTwoPwmMotors::indexWithinRange(const int& idx)
{
    if (idx >= gpios.size() ){
        CD_WARNING("Index out of range!! (%d >= " CD_SIZE_T ")!!!\n",idx,gpios.size());
        return false;
    }
    return true;
}


bool RdTwoPwmMotors::moveForward(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    digitalWrite(LEFT_MOTOR_IN1, 1);
    digitalWrite(LEFT_MOTOR_IN2, 0);
    digitalWrite(RIGHT_MOTOR_IN1, 1);
    digitalWrite(RIGHT_MOTOR_IN2, 0);
    return true;
}

bool RdTwoPwmMotors::moveBackwards(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    digitalWrite(LEFT_MOTOR_IN1, 0);
    digitalWrite(LEFT_MOTOR_IN2, 1);
    digitalWrite(RIGHT_MOTOR_IN1, 0);
    digitalWrite(RIGHT_MOTOR_IN2, 1);

    return true;
}

bool RdTwoPwmMotors::turnLeft(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    digitalWrite(LEFT_MOTOR_IN1, 1);
    digitalWrite(LEFT_MOTOR_IN2, 0);
    digitalWrite(RIGHT_MOTOR_IN1, 0);
    digitalWrite(RIGHT_MOTOR_IN2, 1);

    return true;
}

bool RdTwoPwmMotors::turnRight(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    digitalWrite(LEFT_MOTOR_IN1, 0);
    digitalWrite(LEFT_MOTOR_IN2, 1);
    digitalWrite(RIGHT_MOTOR_IN1, 1);
    digitalWrite(RIGHT_MOTOR_IN2, 0);

    return true;
}

bool RdTwoPwmMotors::stopMovement()
{
    CD_INFO(".\n");

    digitalWrite(LEFT_MOTOR_IN1, 1);
    digitalWrite(LEFT_MOTOR_IN2, 1);
    digitalWrite(RIGHT_MOTOR_IN1, 1);
    digitalWrite(RIGHT_MOTOR_IN2, 1);

    return true;
}

//-- Robot camera related functions
bool RdTwoPwmMotors::tiltUp(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdTwoPwmMotors::tiltDown(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdTwoPwmMotors::panLeft(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdTwoPwmMotors::panRight(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdTwoPwmMotors::stopCameraMovement()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdTwoPwmMotors::connect()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}


bool RdTwoPwmMotors::disconnect()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdTwoPwmMotors::test()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

void RdTwoPwmMotors::setEnabled(bool enabled)
{
    CD_ERROR("Not implemented yet\n");
    return;
}

void RdTwoPwmMotors::onDestroy()
{
    CD_ERROR("Not implemented yet\n");
    return;
}

}  // namespace rd
