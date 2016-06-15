// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "RdRobotServer.hpp"

namespace rd
{

bool RdRobotServer::open(yarp::os::Searchable& config)
{
    rpcServer.setReader(*this);

    yarp::os::Value *name;
    if (config.check("subdevice",name))
        {
            CD_INFO("Subdevice %s\n", name->toString().c_str());
            if (name->isString())
                {
                    // maybe user isn't doing nested configuration
                    yarp::os::Property p;
                    p.fromString(config.toString());
                    p.put("device",name->toString());
                    robotDevice.open(p);
                }
            else
                robotDevice.open(*name);
            if (!robotDevice.isValid())
                CD_ERROR("cannot make <%s>\n", name->toString().c_str());
        }
    else
        {
            CD_ERROR("\"--subdevice <name>\" not set in RdRobotServer\n");
            return false;
        }
    if( ! robotDevice.isValid() )
    {
        CD_ERROR("device not valid\n");
        return false;
    }
    if( ! robotDevice.view( iRdRobot ) )
    {
        CD_ERROR("iRdRobot view failed\n");
        return false;
    }

    //Look for the portname to register (--name option)
    if (config.check("name",name))
        rpcServer.open(name->asString());
    else
        rpcServer.open("/RdRobotServer");

    return true;
}

bool RdRobotServer::close()
{
    rpcServer.close();
    return true;
}

}  // namespace rd
