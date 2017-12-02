// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#ifndef __LASER_TOWER_OF_DEATH__
#define __LASER_TOWER_OF_DEATH__

#include <yarp/os/all.h>
#include <yarp/dev/ControlBoardInterfaces.h>
#include <yarp/dev/Drivers.h>
#include <yarp/dev/PolyDriver.h>

#include <vector>
#include <stdlib.h>  // just for exit()

#include <SerialStream.h>

#include "ColorDebug.hpp"

#include "IRobotManager.hpp"

#define DEFAULT_SERIAL_PORT_NAME "/dev/ttyUSB0"

namespace rd
{

/**
 * @ingroup YarpPlugins
 * @brief EcroWheelController
 */
class EcroWheelController : public yarp::dev::DeviceDriver, public IRobotManager {

public:

    EcroWheelController() {}

    // -------- RobotManager declarations. Implementation in EcroWheelController.cpp --------

    //-- Robot movement related functions
    virtual bool moveForward(int velocity);
    virtual bool moveBackwards(int velocity);
    virtual bool turnLeft(int velocity);
    virtual bool turnRight(int velocity);
    virtual bool stopMovement();

    //-- Robot camera related functions
    virtual bool tiltUp(int velocity);
    virtual bool tiltDown(int velocity);
    virtual bool panLeft(int velocity);
    virtual bool panRight(int velocity);
    virtual bool stopCameraMovement();

    //-- Robot connection related functions
    /// @brief Connect to the remote robot
    virtual bool connect();

    /// @brief Disconnect from the remote robot
    virtual bool disconnect();

    /// @brief Test connection (not in used yet)
    virtual bool test();

    /// @brief Enable/disable sending commands through the manager
    virtual void setEnabled(bool enabled);

    //-- Other
    virtual void onDestroy();

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

    SerialPort * serialPort;
    bool sendCurrentJointValues(int16_t positions1);

    static const int panRangeMin = 0;
    static const int panRangeMax = 180;
    static const int panStep = 10;
    static const int panInitial = 90;

    static const int tiltRangeMin = 0;
    static const int tiltRangeMax = 180;
    static const int tiltStep = 10;
    static const int tiltInitial = 90;

};

}  // namespace rd

#endif  // __LASER_TOWER_OF_DEATH__

