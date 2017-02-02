// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "EcroPwmController.hpp"

namespace rd
{

bool EcroPwmController::moveForward(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    return true;
}

bool EcroPwmController::moveBackwards(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    return true;
}

bool EcroPwmController::turnLeft(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    return true;
}

bool EcroPwmController::turnRight(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    return true;
}

bool EcroPwmController::stopMovement()
{
    CD_INFO(".\n");

    return true;
}

//-- Robot camera related functions
bool EcroPwmController::tiltUp(int velocity)
{
    CD_INFO("\n");
    if (tiltJointValue < tiltRangeMax)
        tiltJointValue+=tiltStep;

    return sendCurrentJointValues();
}

bool EcroPwmController::tiltDown(int velocity)
{
    CD_INFO("\n");
    if (  tiltJointValue > tiltRangeMin )
        tiltJointValue-=tiltStep;

    return sendCurrentJointValues();
}

bool EcroPwmController::panLeft(int velocity)
{
    CD_INFO("\n");
    if (panJointValue < panRangeMax)
        panJointValue+=panStep;

    return sendCurrentJointValues();
}

bool EcroPwmController::panRight(int velocity)
{
    CD_INFO("\n");
    if (  panJointValue > panRangeMin )
        panJointValue-=panStep;

    return sendCurrentJointValues();
}

bool EcroPwmController::stopCameraMovement()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool EcroPwmController::connect()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}


bool EcroPwmController::disconnect()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool EcroPwmController::test()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

void EcroPwmController::setEnabled(bool enabled)
{
    CD_ERROR("Not implemented yet\n");
    return;
}

void EcroPwmController::onDestroy()
{
    CD_ERROR("Not implemented yet\n");
    return;
}

bool EcroPwmController::sendCurrentJointValues()
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

bool EcroPwmController::checkConnection()
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
