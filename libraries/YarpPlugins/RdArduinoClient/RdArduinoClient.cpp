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
    CD_INFO("\n");
    if (tiltJointValue < tiltRangeMax)
        tiltJointValue+=tiltStep;

    return sendCurrentJointValues();
}

bool RdArduinoClient::tiltDown(int velocity)
{
    CD_INFO("\n");
    if (  tiltJointValue > tiltRangeMin )
        tiltJointValue-=tiltStep;

    return sendCurrentJointValues();
}

bool RdArduinoClient::panLeft(int velocity)
{
    CD_INFO("\n");
    if (panJointValue < panRangeMax)
        panJointValue+=panStep;

    return sendCurrentJointValues();
}

bool RdArduinoClient::panRight(int velocity)
{
    CD_INFO("\n");
    if (  panJointValue > panRangeMin )
        panJointValue-=panStep;

    return sendCurrentJointValues();
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

bool RdArduinoClient::sendCurrentJointValues()
{
    if ( serialPort->IsOpen() )
    {
        SerialPort::DataBuffer outputBuff;
        outputBuff.push_back(0x50); //-- 0x50 -> Set pos to all joints

        outputBuff.push_back( (char) panJointValue );
        outputBuff.push_back( (char) tiltJointValue );
        serialPort->Write( outputBuff );

        return true;
    }
    else
    {
        CD_WARNING("Robot could not send joints (because it is not connected).\n");
        return false;
    }
}

bool RdArduinoClient::checkConnection()
{
    //-- Read welcome message to check if connected to the robot
    SerialPort::DataBuffer buffer;
    try {
        serialPort->Read( buffer, 13, 1500);
    }
    catch ( SerialPort::ReadTimeout e)
    {
        std::cout << "Timeout! Exiting..." << std::endl;
        return false;
    }

    //-- Check if connected
    std::string welcomeMessage = "[Debug] Ok!\r\n";
    bool diffFlag = false;

    for (int i = 0; i < (int) buffer.size(); i++)
    {
        if ( welcomeMessage[i] != buffer[i] )
            diffFlag = true;
    }

    return !diffFlag;
}

}  // namespace rd
