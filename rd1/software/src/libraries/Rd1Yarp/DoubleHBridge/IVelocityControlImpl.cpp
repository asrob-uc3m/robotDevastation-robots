// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "DoubleHBridge.hpp"

namespace rd
{

bool DoubleHBridge::setVelocityMode()
{
    CD_INFO("\n");

    CD_WARNING("Not implemented yet.\n");

    return true;
}

bool DoubleHBridge::velocityMove(int j, double sp)
{
    CD_INFO("(%d,%f)\n",j,sp);

    if (sp>0) {
        clear_channel_gpio(0, gpios[j*2+1]);
        add_channel_pulse(0, gpios[j*2+1], 0, GPIO_MAX / PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);
    } else {
        clear_channel_gpio(0, gpios[j*2+1]);
        add_channel_pulse(0, gpios[j*2+1], 0, 0 / PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);
    }

    clear_channel_gpio(0, gpios[j*2]);
    add_channel_pulse(0, gpios[j*2], 0, fabs(sp) / PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT);

    return true;
}

bool DoubleHBridge::velocityMove(const double *sp)
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
