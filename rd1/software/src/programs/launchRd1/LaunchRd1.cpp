// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "LaunchRd1.hpp"

namespace rd
{

LaunchRd1::LaunchRd1() { }

bool LaunchRd1::configure(yarp::os::ResourceFinder &rf)
{
    printf(BOLDBLUE);
    printf("LaunchRd1 options:\n");

    std::string type = rf.check("type",yarp::os::Value(DEFAULT_TYPE),"Name of robot type").asString();
    printf("\t--type %s (Name of robot type)\n", type.c_str() );

    std::string prefix = rf.check("prefix",yarp::os::Value(DEFAULT_PREFIX),"Name of robot without slash").asString();
    printf("\t--prefix %s (Prefix for robot port name, without slash)\n", prefix.c_str() );
    std::string prefixWithSlash("/");
    prefixWithSlash += prefix;

    camera = rf.check("camera",yarp::os::Value(DEFAULT_CAMERA),"Camera on or off").asString();
    if( camera == "on" )
        printf("\t--camera on (Camera on or off)\n" );
    else
        printf("\t--camera off (Camera on or off)\n" );

    printf(RESET);

    if( camera == "on" )
    {
        std::string cameraPortName(prefixWithSlash);
        cameraPortName += "/img:o";
        yarp::os::Property cameraOptions;
        cameraOptions.put("device","grabber");
        cameraOptions.put("subdevice","opencv_grabber");
        cameraOptions.put("name",cameraPortName);
        cameraDevice.open(cameraOptions);

        if (!cameraDevice.isValid())
        {
            CD_ERROR("Camera class instantiation not worked.\n");
            // cameraDevice.close();  // un-needed?
            return false;
        }
    }    

    yarp::os::Property robotOptions;
    robotOptions.fromString(rf.toString());
    robotOptions.put("device","controlboardwrapper2");
    robotOptions.put("subdevice",type);
    robotOptions.put("name",prefixWithSlash);

    robotDevice.open(robotOptions);
    
    if (!robotDevice.isValid())
    {
        CD_ERROR("Robot class instantiation not worked.\n");
        CD_ERROR("Be sure CMake \"ENABLE_Rd1Yarp_%s\" variable is set \"ON\"\n",type.c_str());
        CD_ERROR("\"SKIP_%s is set\" --> should be --> \"ENABLE_%s is set\"\n",type.c_str(),type.c_str());
        CD_ERROR("Also check board-motor communications.\n");
        // robotDevice.close();  // un-needed?
        return false;
    }

    return true;
}

bool LaunchRd1::updateModule()
{
    CD_INFO("Alive\n");
    return true;
}

bool LaunchRd1::close()
{
    if( camera == "on" )
    {
        cameraDevice.close();
    }    

    robotDevice.close();

    return true;
}

}  // namespace rd

