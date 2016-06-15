// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "RdRobotServer.hpp"

namespace rd
{

bool RdRobotServer::open(Searchable& config)
{

    printf(BOLDBLUE);
    printf("RdRobotServer options:\n");
//    printf("\t--gpios %s\n",gpiosBottle.toString().c_str());
    printf(RESET);

    return true;
}

bool RdRobotServer::close()
{

    return true;
}

}  // namespace rd
