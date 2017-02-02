// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "EcroPwmController.hpp"

namespace rd
{

bool EcroPwmController::moveForward(int velocity)
{
    CD_INFO("\n");
    if (velocity <= rightMotorRangeMax && velocity >= rightMotorRangeMin &&
        velocity <= leftMotorRangeMax && velocity >= leftMotorRangeMin )
    {
        rightMotorVelocity = rightMotorOffset+velocity; //-- 90º angle is 0 speed in driver
        leftMotorVelocity = leftMotorOffset+velocity;
    }

    return sendCurrentJointValues();
}

bool EcroPwmController::moveBackwards(int velocity)
{
    CD_INFO("\n");
    if (velocity <= rightMotorRangeMax && velocity >= rightMotorRangeMin &&
        velocity <= leftMotorRangeMax && velocity >= leftMotorRangeMin )
    {
        rightMotorVelocity = rightMotorOffset-velocity; //-- 90º angle is 0 speed in driver
        leftMotorVelocity = leftMotorOffset-velocity;
    }


    return sendCurrentJointValues();
}

bool EcroPwmController::turnLeft(int velocity)
{
    CD_INFO("\n");
    if (velocity <= rightMotorRangeMax && velocity >= rightMotorRangeMin &&
        velocity <= leftMotorRangeMax && velocity >= leftMotorRangeMin )
    {
        rightMotorVelocity = rightMotorOffset+velocity; //-- 90º angle is 0 speed in driver
        leftMotorVelocity = leftMotorOffset-velocity;
    }

     return sendCurrentJointValues();
}

bool EcroPwmController::turnRight(int velocity)
{
    CD_INFO("\n");
    if (velocity <= rightMotorRangeMax && velocity >= rightMotorRangeMin &&
        velocity <= leftMotorRangeMax && velocity >= leftMotorRangeMin )
    {
        rightMotorVelocity = rightMotorOffset-velocity; //-- 90º angle is 0 speed in driver
        leftMotorVelocity = leftMotorOffset+velocity;
    }

    return sendCurrentJointValues();
}

bool EcroPwmController::stopMovement()
{
    CD_INFO("\n");
    rightMotorVelocity = rightMotorOffset; //-- 90º angle is 0 speed in driver
    leftMotorVelocity = leftMotorOffset;

    return sendCurrentJointValues();
}

//-- Robot camera related functions
bool EcroPwmController::tiltUp(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    return true;
}

bool EcroPwmController::tiltDown(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    return true;
}

bool EcroPwmController::panLeft(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    return true;
}

bool EcroPwmController::panRight(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    return true;
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

        outputBuff.push_back( (char) leftMotorVelocity );
        outputBuff.push_back( (char) rightMotorVelocity );
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
