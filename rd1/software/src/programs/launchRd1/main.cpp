/*
 * Copyright: (C) 2010 RobotCub Consortium
 * Author: Paul Fitzpatrick
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 */

#include <stdio.h>
#include <yarp/os/all.h>
#include <yarp/dev/all.h>

#include "ColorDebug.hpp"
#include "LaunchRd1.hpp"

YARP_DECLARE_PLUGINS(Rd1Yarp)

int main(int argc, char *argv[]) {

    YARP_REGISTER_PLUGINS(Rd1Yarp);

    yarp::os::ResourceFinder rf;
    rf.setVerbose(false);
    rf.setDefaultContext("launchRd1");
    rf.setDefaultConfigFile("launchRd1.ini");
    rf.configure(argc, argv);

    CD_INFO("Checking for yarp network...\n");
    yarp::os::Network yarp;
    if (!yarp.checkNetwork()) {
        CD_ERROR("Found no yarp network (try running \"yarpserver &\"), bye!\n");
        return -1;
    }
    CD_SUCCESS("Found yarp network.\n");

    rd::LaunchRd1 mod;
    return mod.runModule(rf);
}

