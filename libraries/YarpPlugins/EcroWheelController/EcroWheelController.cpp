// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "EcroWheelController.hpp"

namespace rd
{

bool EcroWheelController::moveForward(int velocity)
{
    CD_INFO("(%d).\n",velocity);

    sendCurrentJointValues();

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

    return true;
}

bool EcroWheelController::tiltDown(int velocity)
{
    CD_INFO("\n");

    return true;
}

bool EcroWheelController::panLeft(int velocity)
{
    CD_INFO("\n");

    return true;
}

bool EcroWheelController::panRight(int velocity)
{
    CD_INFO("\n");

    return true;
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

        int16_t positions1 = 126;

        SerialPort::DataBuffer outputBuff;
        outputBuff.push_back(0x28);  // Wheel 1
        serialPort->Write( outputBuff );
        yarp::os::Time::delay(0.5);

        outputBuff.clear();
        outputBuff.push_back(0x20);  // Wheel 1
        serialPort->Write( outputBuff );
        yarp::os::Time::delay(0.05);

        /*int8_t positions1_high = positions1;
        positions1 <<= 8;
        int8_t positions1_low = positions1;
        printf("2 bytes: 0x%x\n",positions1);
        printf("high byte: 0x%x\n",positions1_high);
        printf("low byte: 0x%x\n",positions1_low);*/

        outputBuff.clear();
        outputBuff.push_back(0x02);  // Wheel 1
        serialPort->Write( outputBuff );
        yarp::os::Time::delay(0.05);

        outputBuff.clear();
        outputBuff.push_back(0x01);  // Wheel 1
        serialPort->Write( outputBuff );
        yarp::os::Time::delay(0.05);

        printf("high byte\n");

        return true;
    }
    else
    {
        CD_WARNING("Robot could not send joints (because it is not connected).\n");
        return false;
    }
}

}  // namespace rd
