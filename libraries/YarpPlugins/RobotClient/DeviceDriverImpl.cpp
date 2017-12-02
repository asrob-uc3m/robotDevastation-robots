// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "RobotClient.hpp"

namespace rd
{

bool RobotClient::open(yarp::os::Searchable& config)
{
    if ( config.check("name") )
    {
        robotName = config.find("name").asString();
    }

    std::string local_s("/robotDevastation");
    local_s += robotName;
    local_s += "/rpc:c";

    rpcClient.open(local_s);  //-- Default should look like "/......./rpc:c"

    std::string remote_s(robotName);
    remote_s += "/rpc:s";

    int tries = 0;
    while(tries++ < 10)
    {
        yarp::os::Network::connect(local_s,remote_s);
        if( rpcClient.getOutputCount() > 0) break;
        CD_DEBUG("Wait to connect to remote robot '%s', try %d...\n",remote_s.c_str(),tries);
        yarp::os::Time::delay(0.5);
    }

    if (tries == 11)
    {
        CD_ERROR("Timeout on connect to remote robot!\n");
        CD_INFO("If you prefer a fake robot use the '--mockRobotManager' parameter to run robotDevastation.\n");
        return false;
    }

    CD_SUCCESS("Connected to remote robot.\n");

    return true;
}

bool RobotClient::close()
{
    rpcClient.close();
    robotDevice.close();
    return true;
}

}  // namespace rd
