// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "RdArduinoClient.hpp"

namespace rd
{

bool RdArduinoClient::moveForward(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    return true;
}

bool RdArduinoClient::moveBackwards(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    return true;
}

bool RdArduinoClient::turnLeft(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    return true;
}

bool RdArduinoClient::turnRight(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    return true;
}

bool RdArduinoClient::stopMovement()
{
    CD_INFO(".\n");

    return true;
}

//-- Robot camera related functions
bool RdArduinoClient::tiltUp(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdArduinoClient::tiltDown(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdArduinoClient::panLeft(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdArduinoClient::panRight(int velocity)
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdArduinoClient::stopCameraMovement()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdArduinoClient::connect()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}


bool RdArduinoClient::disconnect()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool RdArduinoClient::test()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

void RdArduinoClient::setEnabled(bool enabled)
{
    CD_ERROR("Not implemented yet\n");
    return;
}

void RdArduinoClient::onDestroy()
{
    CD_ERROR("Not implemented yet\n");
    return;
}

}  // namespace rd
