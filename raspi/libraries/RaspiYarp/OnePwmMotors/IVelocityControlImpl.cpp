// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "OnePwmMotors.hpp"

namespace rd
{

bool OnePwmMotors::setVelocityMode()
{
    CD_INFO("\n");

    CD_WARNING("Not implemented yet.\n");

    return true;
}

bool OnePwmMotors::velocityMove(int j, double sp)
{
    CD_INFO("(%d)\n",j);

    if (j%2 == 1) {
        sp *= -1;
    }

    if (sp>0) {
        clear_channel_gpio(0, gpios[j]);
        add_channel_pulse(0, gpios[j], 0, 2000 / PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);
    } else if (sp<0) {
        clear_channel_gpio(0, gpios[j]);
        add_channel_pulse(0, gpios[j], 0, 1000 / PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);
    } else {
        clear_channel_gpio(0, gpios[j]);
        add_channel_pulse(0, gpios[j], 0, 0 / PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);
    }

    return true;
}

bool OnePwmMotors::velocityMove(const double *sp)
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