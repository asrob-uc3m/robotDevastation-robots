// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "RaspiTwoPwmMotorController.hpp"

namespace rd
{

const int RaspiTwoPwmMotorController::LEFT_MOTOR_IN1 = 24;
const int RaspiTwoPwmMotorController::LEFT_MOTOR_IN2 = 23;

const int RaspiTwoPwmMotorController::RIGHT_MOTOR_IN1 = 22;
const int RaspiTwoPwmMotorController::RIGHT_MOTOR_IN2 = 21;

bool RaspiTwoPwmMotorController::indexWithinRange(const int& idx)
{
    if (idx >= gpios.size() ){
        CD_WARNING("Index out of range!! (%d >= " CD_SIZE_T ")!!!\n",idx,gpios.size());
        return false;
    }
    return true;
}


bool RaspiTwoPwmMotorController::moveForward(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    digitalWrite(LEFT_MOTOR_IN1, 1);
    digitalWrite(LEFT_MOTOR_IN2, 0);
    digitalWrite(RIGHT_MOTOR_IN1, 1);
    digitalWrite(RIGHT_MOTOR_IN2, 0);
    return true;
}

bool RaspiTwoPwmMotorController::moveBackwards(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    digitalWrite(LEFT_MOTOR_IN1, 0);
    digitalWrite(LEFT_MOTOR_IN2, 1);
    digitalWrite(RIGHT_MOTOR_IN1, 0);
    digitalWrite(RIGHT_MOTOR_IN2, 1);

    return true;
}

bool RaspiTwoPwmMotorController::turnLeft(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    digitalWrite(LEFT_MOTOR_IN1, 0);
    digitalWrite(LEFT_MOTOR_IN2, 1);
    digitalWrite(RIGHT_MOTOR_IN1, 1);
    digitalWrite(RIGHT_MOTOR_IN2, 0);

    return true;
}

bool RaspiTwoPwmMotorController::turnRight(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    digitalWrite(LEFT_MOTOR_IN1, 1);
    digitalWrite(LEFT_MOTOR_IN2, 0);
    digitalWrite(RIGHT_MOTOR_IN1, 0);
    digitalWrite(RIGHT_MOTOR_IN2, 1);

    return true;
}

bool RaspiTwoPwmMotorController::stopMovement()
{
    CD_INFO(".\n");

    digitalWrite(LEFT_MOTOR_IN1, 1);
    digitalWrite(LEFT_MOTOR_IN2, 1);
    digitalWrite(RIGHT_MOTOR_IN1, 1);
    digitalWrite(RIGHT_MOTOR_IN2, 1);

    return true;
}

//-- Robot camera related functions
bool RaspiTwoPwmMotorController::tiltUp(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RaspiTwoPwmMotorController::tiltDown(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RaspiTwoPwmMotorController::panLeft(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RaspiTwoPwmMotorController::panRight(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RaspiTwoPwmMotorController::stopCameraMovement()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RaspiTwoPwmMotorController::connect()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}


bool RaspiTwoPwmMotorController::disconnect()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RaspiTwoPwmMotorController::test()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

void RaspiTwoPwmMotorController::setEnabled(bool enabled)
{
    CD_ERROR("Not implemented yet\n");
    return;
}

void RaspiTwoPwmMotorController::onDestroy()
{
    CD_ERROR("Not implemented yet\n");
    return;
}

}  // namespace rd
