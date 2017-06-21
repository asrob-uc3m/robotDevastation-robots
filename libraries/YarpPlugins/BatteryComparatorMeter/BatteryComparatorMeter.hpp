// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#ifndef __BATTERY_COMPARATOR_METER__
#define __BATTERY_COMPARATOR_METER__

#include <yarp/os/all.h>
#include <yarp/dev/DeviceDriver.h>
#include <yarp/dev/IBattery.h>

#include <wiringPi.h>

#include "ColorDebug.hpp"

namespace rd
{

/**
 * @ingroup YarpPlugins
 * @brief BatteryComparatorMeter
 */
class BatteryComparatorMeter : public yarp::dev::DeviceDriver, public yarp::dev::IBattery {

public:
    // -------- DeviceDriver declarations. Implementation in DeviceDriverImpl.cpp --------

    /**
    * Open the DeviceDriver.
    * @param config is a list of parameters for the device.
    * Which parameters are effective for your device can vary.
    * See \ref dev_examples "device invocation examples".
    * If there is no example for your device,
    * you can run the "yarpdev" program with the verbose flag
    * set to probe what parameters the device is checking.
    * If that fails too,
    * you'll need to read the source code (please nag one of the
    * yarp developers to add documentation for your device).
    * @return true/false upon success/failure
    */
    virtual bool open(yarp::os::Searchable& config);

    /**
    * Close the DeviceDriver.
    * @return true/false on success/failure.
    */
    virtual bool close();

    // --------- IBattery declarations. Implementations in IBatteryImpl.cpp --------------

    virtual bool getBatteryVoltage(double &voltage);

    virtual bool getBatteryCurrent(double &current);

    virtual bool getBatteryCharge(double &charge);

    virtual bool getBatteryStatus(int &status);

    virtual bool getBatteryTemperature(double &temperature);

    virtual bool getBatteryInfo(yarp::os::ConstString &battery_info);

private:
    double charge;
    int pin_25, pin_50, pin_75, pin_100;

};

}  // namespace rd

#endif  //  __BATTERY_COMPARATOR_METER__

