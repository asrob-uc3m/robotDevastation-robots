// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "EcroWheelController.hpp"

namespace rd
{

bool EcroWheelController::open(yarp::os::Searchable& config)
{

    std::string serialPortName = config.check("serialPortName",yarp::os::Value(DEFAULT_SERIAL_PORT_NAME),"serialPortName").asString();

    printf("EcroWheelController options:\n");
    printf("\t--serialPortName %s [%s]\n",serialPortName.c_str(),DEFAULT_SERIAL_PORT_NAME);

    CD_DEBUG("init Serial Port.\n");
    serialPort = new SerialPort( serialPortName );  // "/dev/ttyUSB0"
    try
    {
        serialPort->Open( SerialPort::BAUD_19200, SerialPort::CHAR_SIZE_8,
                           SerialPort::PARITY_NONE, SerialPort::STOP_BITS_1,
                           SerialPort::FLOW_CONTROL_NONE );
    }
    catch ( SerialPort::OpenFailed e )
    {
        CD_ERROR("Error opening the serial port: %s\n", serialPortName.c_str());
        return false;
    }

    return true;
}

bool EcroWheelController::close()
{
    CD_INFO("Close Serial Port: %p\n",serialPort);
    serialPort->Close();
    delete serialPort;
    serialPort = 0;

    return true;
}

}  // namespace rd
