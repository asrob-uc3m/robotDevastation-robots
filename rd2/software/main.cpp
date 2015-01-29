/*
 * Copyright: (C) 2010 RobotCub Consortium
 * Author: Paul Fitzpatrick
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 */

#include <stdio.h>
#include <yarp/os/all.h>
#include <yarp/dev/all.h>

#include "RdMacros.hpp"
#include "LaunchRd2.hpp"

using namespace yarp::os;
using namespace yarp::dev;

YARP_DECLARE_PLUGINS(Rd2Yarp);

int main(int argc, char *argv[]) {

    YARP_REGISTER_PLUGINS(Rd2Yarp);

    ResourceFinder rf;
    rf.setVerbose(false);
    rf.setDefaultContext("launchRd2/conf");
    rf.setDefaultConfigFile("launchRd2.ini");
    rf.configure("RD2_YARP_ROOT", argc, argv);

    RD_INFO("Checking for yarp network...\n");
    Network yarp;
    if (!yarp.checkNetwork()) {
        RD_ERROR("Found no yarp network (try running \"yarpserver &\"), bye!\n");
        return -1;
    }
    RD_SUCCESS("Found yarp network.\n");

    LaunchRd2 mod;
    return mod.runModule(rf);
}

