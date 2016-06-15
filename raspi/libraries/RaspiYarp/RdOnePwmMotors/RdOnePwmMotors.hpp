// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#ifndef __RD_ONE_PWM_MOTORS__
#define __RD_ONE_PWM_MOTORS__

#include <yarp/os/all.h>
#include <yarp/dev/ControlBoardInterfaces.h>
#include <yarp/dev/Drivers.h>
#include <yarp/dev/PolyDriver.h>

#include <vector>
#include <stdlib.h>  // just for exit()

#include "ColorDebug.hpp"

#include "IRdRobot.h"

#include "pwm.hpp"

namespace rd
{

class RdOnePwmMotors : public yarp::dev::DeviceDriver, public IRdRobot {

public:

    // -------- IRdRobot declarations. Implementation in RdOnePwmMotors.cpp --------

    //-- Robot movement related functions
    virtual bool moveForward(int velocity = UNUSED);
    virtual bool moveBackwards(int velocity = UNUSED);
    virtual bool turnLeft(int velocity = UNUSED);
    virtual bool turnRight(int velocity = UNUSED);
    virtual bool stopMovement();

    //-- Robot camera related functions
    bool tiltUp(int velocity = UNUSED);
    bool tiltDown(int velocity = UNUSED);
    bool panLeft(int velocity = UNUSED);
    bool panRight(int velocity = UNUSED);
    bool stopCameraMovement();

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

    // ------------------------------- Private -------------------------------------

private:

    /** Check if index is within range (referred to driver vector size).
     * @param idx index to check.
     * @return true/false on success/failure.
     */
    bool indexWithinRange(const int& idx);

    std::vector< int > gpios;

};

}  // namespace rd

#endif  // __RD_ONE_PWM_MOTORS__

