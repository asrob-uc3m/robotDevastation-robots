// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "RaspiOnePwmMotorController.hpp"

namespace rd
{

bool RaspiOnePwmMotorController::indexWithinRange(const int& idx)
{
    if (idx >= gpios.size() ){
        CD_WARNING("Index out of range!! (%d >= " CD_SIZE_T ")!!!\n",idx,gpios.size());
        return false;
    }
    return true;
}

bool RaspiOnePwmMotorController::moveForward(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    clear_channel_gpio(0, gpios[0]);
    add_channel_pulse(0, gpios[0], 0, 2000 / PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);

    clear_channel_gpio(0, gpios[1]);
    add_channel_pulse(0, gpios[1], 0, 1000 / PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);

    return true;
}

bool RaspiOnePwmMotorController::moveBackwards(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    clear_channel_gpio(0, gpios[0]);
    add_channel_pulse(0, gpios[0], 0, 1000 / PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);

    clear_channel_gpio(0, gpios[1]);
    add_channel_pulse(0, gpios[1], 0, 2000 / PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);

    return true;
}

bool RaspiOnePwmMotorController::turnLeft(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    clear_channel_gpio(0, gpios[0]);
    add_channel_pulse(0, gpios[0], 0, 1250 / PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);

    clear_channel_gpio(0, gpios[1]);
    add_channel_pulse(0, gpios[1], 0, 1250 / PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);

    return true;
}

bool RaspiOnePwmMotorController::turnRight(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    clear_channel_gpio(0, gpios[0]);
    add_channel_pulse(0, gpios[0], 0, 1750 / PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);

    clear_channel_gpio(0, gpios[1]);
    add_channel_pulse(0, gpios[1], 0, 1750 / PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);

    return true;
}

bool RaspiOnePwmMotorController::stopMovement()
{
    CD_INFO(".\n");

    clear_channel_gpio(0, gpios[0]);
    add_channel_pulse(0, gpios[0], 0, 0 / PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);

    clear_channel_gpio(0, gpios[1]);
    add_channel_pulse(0, gpios[1], 0, 0 / PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);

    return true;
}

//-- Robot camera related functions
bool RaspiOnePwmMotorController::tiltUp(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RaspiOnePwmMotorController::tiltDown(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RaspiOnePwmMotorController::panLeft(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RaspiOnePwmMotorController::panRight(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RaspiOnePwmMotorController::stopCameraMovement()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RaspiOnePwmMotorController::connect()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}


bool RaspiOnePwmMotorController::disconnect()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RaspiOnePwmMotorController::test()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

void RaspiOnePwmMotorController::setEnabled(bool enabled)
{
    CD_ERROR("Not implemented yet\n");
    return;
}

void RaspiOnePwmMotorController::onDestroy()
{
    CD_ERROR("Not implemented yet\n");
    return;
}

}  // namespace rd
