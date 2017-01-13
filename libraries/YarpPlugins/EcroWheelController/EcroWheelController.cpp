// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "EcroWheelController.hpp"

namespace rd
{

bool EcroWheelController::moveForward(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    return true;
}

bool EcroWheelController::moveBackwards(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    return true;
}

bool EcroWheelController::turnLeft(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    return true;
}

bool EcroWheelController::turnRight(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    return true;
}

bool EcroWheelController::stopMovement()
{
    CD_INFO(".\n");

    return true;
}

//-- Robot camera related functions
bool EcroWheelController::tiltUp(int velocity)
{
    CD_INFO("\n");
    if (tiltJointValue < tiltRangeMax)
        tiltJointValue+=tiltStep;

    return sendCurrentJointValues();
}

bool EcroWheelController::tiltDown(int velocity)
{
    CD_INFO("\n");
    if (  tiltJointValue > tiltRangeMin )
        tiltJointValue-=tiltStep;

    return sendCurrentJointValues();
}

bool EcroWheelController::panLeft(int velocity)
{
    CD_INFO("\n");
    if (panJointValue < panRangeMax)
        panJointValue+=panStep;

    return sendCurrentJointValues();
}

bool EcroWheelController::panRight(int velocity)
{
    CD_INFO("\n");
    if (  panJointValue > panRangeMin )
        panJointValue-=panStep;

    return sendCurrentJointValues();
}

bool EcroWheelController::stopCameraMovement()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool EcroWheelController::connect()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}


bool EcroWheelController::disconnect()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

bool EcroWheelController::test()
{
    CD_ERROR("Not implemented yet\n");
    return false;
}

void EcroWheelController::setEnabled(bool enabled)
{
    CD_ERROR("Not implemented yet\n");
    return;
}

void EcroWheelController::onDestroy()
{
    CD_ERROR("Not implemented yet\n");
    return;
}

bool EcroWheelController::sendCurrentJointValues()
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

bool EcroWheelController::checkConnection()
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
