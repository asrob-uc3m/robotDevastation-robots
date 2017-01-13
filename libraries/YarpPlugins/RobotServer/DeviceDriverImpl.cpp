// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "RobotServer.hpp"

namespace rd
{

bool RobotServer::open(yarp::os::Searchable& config)
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
            CD_ERROR("\"--subdevice <name>\" not set in RobotServer\n");
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
        rpcServer.open(name->asString()+"/rpc:s");
    else
        rpcServer.open("/RobotServer/rpc:s");

    return true;
}

bool RobotServer::close()
{
    rpcServer.close();
    robotDevice.close();
    return true;
}

}  // namespace rd
