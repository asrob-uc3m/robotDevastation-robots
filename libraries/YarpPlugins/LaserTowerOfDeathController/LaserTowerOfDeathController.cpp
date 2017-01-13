// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "LaserTowerOfDeathController.hpp"

namespace rd
{

bool LaserTowerOfDeathController::moveForward(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    return true;
}

bool LaserTowerOfDeathController::moveBackwards(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    return true;
}

bool LaserTowerOfDeathController::turnLeft(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    return true;
}

bool LaserTowerOfDeathController::turnRight(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    return true;
}

bool LaserTowerOfDeathController::stopMovement()
{
    CD_INFO(".\n");

    return true;
}

//-- Robot camera related functions
bool LaserTowerOfDeathController::tiltUp(int velocity)
{
    CD_INFO("\n");
    if (tiltJointValue < tiltRangeMax)
        tiltJointValue+=tiltStep;

    return sendCurrentJointValues();
}

bool LaserTowerOfDeathController::tiltDown(int velocity)
{
    CD_INFO("\n");
    if (  tiltJointValue > tiltRangeMin )
        tiltJointValue-=tiltStep;

    return sendCurrentJointValues();
}

bool LaserTowerOfDeathController::panLeft(int velocity)
{
    CD_INFO("\n");
    if (panJointValue < panRangeMax)
        panJointValue+=panStep;

    return sendCurrentJointValues();
}

bool LaserTowerOfDeathController::panRight(int velocity)
{
    CD_INFO("\n");
    if (  panJointValue > panRangeMin )
        panJointValue-=panStep;

    return sendCurrentJointValues();
}

bool LaserTowerOfDeathController::stopCameraMovement()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool LaserTowerOfDeathController::connect()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}


bool LaserTowerOfDeathController::disconnect()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool LaserTowerOfDeathController::test()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

void LaserTowerOfDeathController::setEnabled(bool enabled)
{
    CD_ERROR("Not implemented yet\n");
    return;
}

void LaserTowerOfDeathController::onDestroy()
{
    CD_ERROR("Not implemented yet\n");
    return;
}

bool LaserTowerOfDeathController::sendCurrentJointValues()
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

bool LaserTowerOfDeathController::checkConnection()
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
