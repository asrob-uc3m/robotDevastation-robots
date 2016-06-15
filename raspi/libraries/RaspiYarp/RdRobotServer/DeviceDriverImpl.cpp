// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "RdRobotServer.hpp"

namespace rd
{

bool RdRobotServer::open(yarp::os::Searchable& config)
{
    p.setReader(*this);

    yarp::os::Value *name;

    //Look for the portname to register (--name option)
    if (config.check("name",name))
        p.open(name->asString());
    else
        p.open("/RdRobotServer");

    return true;
}

bool RdRobotServer::close()
{

    return true;
}

}  // namespace rd
