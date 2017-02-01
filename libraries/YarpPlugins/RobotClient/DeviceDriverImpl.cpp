// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "RobotClient.hpp"

namespace rd
{

bool RobotClient::open(yarp::os::Searchable& config)
{

    std::string local_s("/robotDevastation/");
    local_s += robotName;
    local_s += "/rpc:c";

    rpcClient.open(local_s);  //-- Default should look like "/robotDevastation/rd1/rpc:c"

    std::string remote_s("/");
    remote_s += robotName;
    remote_s += "/rpc:s";

    return true;
}

bool RobotClient::close()
{
    rpcClient.close();
    robotDevice.close();
    return true;
}

}  // namespace rd
