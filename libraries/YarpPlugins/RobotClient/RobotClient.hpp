// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#ifndef __RD_ROBOT_CLIENT__
#define __RD_ROBOT_CLIENT__

#include <yarp/os/all.h>
#include <yarp/dev/ControlBoardInterfaces.h>
#include <yarp/dev/Drivers.h>
#include <yarp/dev/PolyDriver.h>

#include <vector>
#include <stdlib.h>  // just for exit()

#include "IRobotManager.hpp"

#include "ColorDebug.hpp"

#define VOCAB_MOVE_FORWARD VOCAB4('m','o','v','f')
#define VOCAB_MOVE_BACKWARDS VOCAB4('m','o','v','b')
#define VOCAB_TURN_LEFT VOCAB4('t','r','n','l')
#define VOCAB_TURN_RIGHT VOCAB4('t','r','n','r')
#define VOCAB_STOP_MOVEMENT VOCAB4('s','t','p','m')

#define VOCAB_TILT_UP VOCAB4('t','l','t','u')
#define VOCAB_TILT_DOWN VOCAB4('t','l','t','d')
#define VOCAB_PAN_LEFT VOCAB4('p','a','n','l')
#define VOCAB_PAN_RIGHT VOCAB4('p','a','n','r')
#define VOCAB_STOP_CAMERA_MOVEMENT VOCAB4('s','t','p','c')

namespace rd
{

/**
 * @ingroup YarpPlugins
 * @brief RobotClient
 */
class RobotClient : public yarp::dev::DeviceDriver, public RobotManager
{

public:

    RobotClient();

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

    // -------- Implementation in RobotClient.cpp --------

    //-- Robot movement related functions
    virtual bool moveForward(int velocity = UNUSED);
    virtual bool moveBackwards(int velocity = UNUSED);
    virtual bool turnLeft(int velocity = UNUSED);
    virtual bool turnRight(int velocity = UNUSED);
    virtual bool stopMovement();

    //-- Robot camera related functions
    virtual bool tiltUp(int velocity = UNUSED);
    virtual bool tiltDown(int velocity = UNUSED);
    virtual bool panLeft(int velocity = UNUSED);
    virtual bool panRight(int velocity = UNUSED);
    virtual bool stopCameraMovement();

    //-- Robot connection related functions
    virtual bool connect() { return true; }
    virtual bool disconnect() { return true; }
    virtual bool test() {}
    virtual void setEnabled(bool enabled) {}

    virtual void onDestroy() {}

// ------------------------------- Private -------------------------------------

private:

    std::string robotName;

    /** Check if index is within range (referred to driver vector size).
     * @param idx index to check.
     * @return true/false on success/failure.
     */
    bool indexWithinRange(const int& idx);

    std::vector< int > gpios;

    static const int UNUSED = -1;

    yarp::os::RpcClient rpcClient;

    bool send1vocab1int(int vocab, int integer);
    bool send1vocab(int vocab);

    yarp::dev::PolyDriver robotDevice;
    RobotManager* iRdRobot;

};

}  // namespace rd

#endif  // __RD_ROBOT_CLIENT__
