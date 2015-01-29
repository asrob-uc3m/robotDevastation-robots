// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#ifndef __RUN_BOT__
#define __RUN_BOT__

#include <yarp/os/RFModule.h>
#include <yarp/os/Module.h>
#include <yarp/os/Network.h>
#include <yarp/os/Port.h>
#include <yarp/os/BufferedPort.h>

#include <yarp/dev/PolyDriver.h>

#include "RdMacros.hpp"

#define DEFAULT_TYPE "pwmbot"
#define DEFAULT_PREFIX "0/rd2"
#define DEFAULT_CAMERA "on"

using namespace yarp::os;
using namespace yarp::dev;

/**
 * @ingroup LaunchRd2
 *
 * The LaunchRd2 class tests the Pwm class as a controlboard.
 * 
 */
class LaunchRd2 : public RFModule {

    public:
        LaunchRd2();
        bool configure(ResourceFinder &rf);

    protected:
        yarp::dev::PolyDriver cameraDevice;
        yarp::dev::PolyDriver robotDevice;

        virtual bool updateModule();
        virtual bool close();

//        double getPeriod();
//        bool interruptModule();
//        int period;

        std::string camera;

};

#endif  // __RUN_BOT__

