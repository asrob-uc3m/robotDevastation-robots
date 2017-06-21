#include "BatteryComparatorMeter.hpp"


bool rd::BatteryComparatorMeter::getBatteryVoltage(double &voltage)
{
    CD_ERROR("Not supported by this device.\n");
    return false;
}

bool rd::BatteryComparatorMeter::getBatteryCurrent(double &current)
{
    CD_ERROR("Not supported by this device.\n");
    return false;
}

bool rd::BatteryComparatorMeter::getBatteryCharge(double &charge)
{
    return charge;
}

bool rd::BatteryComparatorMeter::getBatteryStatus(int &status)
{
    CD_WARNING("Suppport for this function is currently limited.\n");
    if (charge < 25)
        status = BATTERY_LOW_WARNING;
    else
        status = BATTERY_OK_IN_USE;

    return true;
}

bool rd::BatteryComparatorMeter::getBatteryTemperature(double &temperature)
{
    CD_ERROR("Not supported by this device.\n");
    return false;
}

bool rd::BatteryComparatorMeter::getBatteryInfo(yarp::os::ConstString &battery_info)
{
    battery_info = "7.4V 2S Battery meter based on 4 comparators";
    return true;
}
