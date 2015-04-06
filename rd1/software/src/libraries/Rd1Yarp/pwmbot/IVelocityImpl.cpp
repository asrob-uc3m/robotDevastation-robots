// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "PwmBot.hpp"

namespace rd
{

bool PwmBot::setVelocityMode()
{
    CD_INFO("\n");

    CD_WARNING("Not implemented yet.\n");

    return true;
}

bool PwmBot::velocityMove(int j, double sp)
{
    CD_INFO("(%d)\n",j);

    // Clear and start again
    clear_channel_gpio(0, gpios[j]);
    add_channel_pulse(0, gpios[j], 0, sp / PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);

    return true;
}

bool PwmBot::velocityMove(const double *sp)
{
    CD_INFO("\n");

    bool ok = true;
    for(int j=0; j<gpios.size(); j++)
    {
        ok &= this->velocityMove(j,sp[j]);
    }
    return ok;
}

}  // namespace rd
