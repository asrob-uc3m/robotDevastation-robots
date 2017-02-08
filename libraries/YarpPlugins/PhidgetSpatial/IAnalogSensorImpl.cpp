// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "PhidgetSpatial.hpp"

namespace rd
{

// -----------------------------------------------------------------------------

int PhidgetSpatial::read(yarp::sig::Vector &out)
{
    hSemaphore.wait();

    out.resize(DEFAULT_NUM_CHANNELS);



    hSemaphore.post();

    return yarp::dev::IAnalogSensor::AS_OK;
}

// -----------------------------------------------------------------------------

int PhidgetSpatial::getState(int ch)
{
    return yarp::dev::IAnalogSensor::AS_OK;
}

// -----------------------------------------------------------------------------

int PhidgetSpatial::getChannels()
{
    return DEFAULT_NUM_CHANNELS;
}

// -----------------------------------------------------------------------------

int PhidgetSpatial::calibrateSensor()
{
    return true;
}

// -----------------------------------------------------------------------------

int PhidgetSpatial::calibrateSensor(const yarp::sig::Vector& value)
{
    return true;
}

// -----------------------------------------------------------------------------

int PhidgetSpatial::calibrateChannel(int ch)
{
    return true;
}

// -----------------------------------------------------------------------------

int PhidgetSpatial::calibrateChannel(int ch, double value)
{
    return true;
}

// -----------------------------------------------------------------------------

}  // namespace rd
