// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "RdTwoPwmMotors.hpp"

namespace rd
{

const int RdTwoPwmMotors::LEFT_MOTOR_IN1 = 19;
const int RdTwoPwmMotors::LEFT_MOTOR_IN2 = 13;

const int RdTwoPwmMotors::RIGHT_MOTOR_IN1 = 6;
const int RdTwoPwmMotors::RIGHT_MOTOR_IN2 = 5;

bool RdTwoPwmMotors::indexWithinRange(const int& idx)
{
    if (idx >= gpios.size() ){
        CD_WARNING("Index out of range!! (%d >= " CD_SIZE_T ")!!!\n",idx,gpios.size());
        return false;
    }
    return true;
}

bool RdTwoPwmMotors::clearChannels()
{
    clear_channel_gpio(0, LEFT_MOTOR_IN1);
    clear_channel_gpio(0, LEFT_MOTOR_IN2);
    clear_channel_gpio(0, RIGHT_MOTOR_IN1);
    clear_channel_gpio(0, RIGHT_MOTOR_IN2);
}

bool RdTwoPwmMotors::moveForward(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    clearChannels();
    add_channel_pulse(0, LEFT_MOTOR_IN1,  0, PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);
    add_channel_pulse(0, LEFT_MOTOR_IN2,  0, 0);
    add_channel_pulse(0, RIGHT_MOTOR_IN1, 0, PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);
    add_channel_pulse(0, RIGHT_MOTOR_IN2, 0, 0);
    return true;
}

bool RdTwoPwmMotors::moveBackwards(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    clearChannels();
    add_channel_pulse(0, LEFT_MOTOR_IN1,  0, 0);
    add_channel_pulse(0, LEFT_MOTOR_IN2,  0, PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);
    add_channel_pulse(0, RIGHT_MOTOR_IN1, 0, 0);
    add_channel_pulse(0, RIGHT_MOTOR_IN2, 0, PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);

    return true;
}

bool RdTwoPwmMotors::turnLeft(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    clearChannels();
    add_channel_pulse(0, LEFT_MOTOR_IN1,  0, PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);
    add_channel_pulse(0, LEFT_MOTOR_IN2,  0, 0);
    add_channel_pulse(0, RIGHT_MOTOR_IN1, 0, 0);
    add_channel_pulse(0, RIGHT_MOTOR_IN2, 0, PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);

    return true;
}

bool RdTwoPwmMotors::turnRight(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    clearChannels();
    add_channel_pulse(0, LEFT_MOTOR_IN1,  0, 0);
    add_channel_pulse(0, LEFT_MOTOR_IN2,  0, PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);
    add_channel_pulse(0, RIGHT_MOTOR_IN1, 0, PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);
    add_channel_pulse(0, RIGHT_MOTOR_IN2, 0, 0);

    return true;
}

bool RdTwoPwmMotors::stopMovement()
{
    CD_INFO(".\n");

    clearChannels();
    add_channel_pulse(0, LEFT_MOTOR_IN1,  0, PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);
    add_channel_pulse(0, LEFT_MOTOR_IN2,  0, PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);
    add_channel_pulse(0, RIGHT_MOTOR_IN1, 0, PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);
    add_channel_pulse(0, RIGHT_MOTOR_IN2, 0, PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);

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
