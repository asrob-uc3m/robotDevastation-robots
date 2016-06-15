// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#ifndef __ONE_PWM_MOTORS__
#define __ONE_PWM_MOTORS__

#include <yarp/os/all.h>
#include <yarp/dev/ControlBoardInterfaces.h>
#include <yarp/dev/Drivers.h>
#include <yarp/dev/PolyDriver.h>

#include <vector>
#include <stdlib.h>  // just for exit()

#include "ColorDebug.hpp"

#include "pwm.hpp"

using namespace yarp::os;

namespace rd
{

class RdOnePwmMotors : public yarp::dev::DeviceDriver {

  public:

        //-- Robot movement related functions
        bool moveForward(int velocity = UNUSED);
        bool moveBackwards(int velocity = UNUSED);
        bool turnLeft(int velocity = UNUSED);
        bool turnRight(int velocity = UNUSED);
        bool stopMovement();

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
    virtual bool open(Searchable& config);

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

        static const int UNUSED = -1;

};

}  // namespace rd

#endif

