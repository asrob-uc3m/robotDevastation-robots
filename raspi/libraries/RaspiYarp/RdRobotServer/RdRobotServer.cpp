// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "RdRobotServer.hpp"

namespace rd
{

bool RdRobotServer::indexWithinRange(const int& idx)
{
    if (idx >= gpios.size() ){
        CD_WARNING("Index out of range!! (%d >= " CD_SIZE_T ")!!!\n",idx,gpios.size());
        return false;
    }
    return true;
}

bool RdRobotServer::moveForward(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdRobotServer::moveBackwards(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdRobotServer::turnLeft(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdRobotServer::turnRight(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdRobotServer::stopMovement()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

//-- Robot camera related functions
bool RdRobotServer::tiltUp(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdRobotServer::tiltDown(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdRobotServer::panLeft(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdRobotServer::panRight(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdRobotServer::stopCameraMovement()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

}  // namespace rd

