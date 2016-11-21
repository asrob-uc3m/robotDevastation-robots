// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "RdTwoPwmMotors.hpp"

namespace rd
{

bool RdTwoPwmMotors::open(yarp::os::Searchable& config)
{

    yarp::os::Bottle gpiosBottle = config.findGroup("gpios").tail();  //-- e.g. 17 27

    printf(BOLDBLUE);
    printf("RdTwoPwmMotors options:\n");
    printf("\t--gpios %s\n",gpiosBottle.toString().c_str());
    printf(RESET);

    if( gpiosBottle.size() < 1) {
        CD_ERROR("Please specify at least one gpio.\n");
        return false;
    }

    if (wiringPiSetup() == -1)
        return false;

    pinMode(RdTwoPwmMotors::LEFT_MOTOR_IN1, OUTPUT);
    pinMode(RdTwoPwmMotors::LEFT_MOTOR_IN2, OUTPUT);
    pinMode(RdTwoPwmMotors::RIGHT_MOTOR_IN1, OUTPUT);
    pinMode(RdTwoPwmMotors::RIGHT_MOTOR_IN2, OUTPUT);

    return true;
}

bool RdTwoPwmMotors::close()
{

    return true;
}

}  // namespace rd
