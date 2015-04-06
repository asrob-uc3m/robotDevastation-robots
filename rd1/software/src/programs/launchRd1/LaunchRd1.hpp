// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#ifndef __LAUNCH_RD1__
#define __LAUNCH_RD1__

#include <yarp/os/RFModule.h>
#include <yarp/os/Module.h>
#include <yarp/os/Network.h>
#include <yarp/os/Port.h>
#include <yarp/os/BufferedPort.h>

#include <yarp/dev/PolyDriver.h>

#include "ColorDebug.hpp"

#define DEFAULT_TYPE "pwmbot"
#define DEFAULT_PREFIX "0/rd1"
#define DEFAULT_CAMERA "on"

using namespace yarp::os;
using namespace yarp::dev;

namespace rd
{

/**
 * @ingroup LaunchRd1
 *
 * The LaunchRd1 class tests the Pwm class as a controlboard.
 * 
 */
class LaunchRd1 : public RFModule {

    public:
        LaunchRd1();
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

}  // namespace rd

#endif  // __LAUNCH_RD1__

