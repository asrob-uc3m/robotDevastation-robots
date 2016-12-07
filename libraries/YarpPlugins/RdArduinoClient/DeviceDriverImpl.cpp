// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "RdArduinoClient.hpp"

namespace rd
{

bool RdArduinoClient::open(yarp::os::Searchable& config)
{

    yarp::os::Bottle gpiosBottle = config.findGroup("gpios").tail();  //-- e.g. 17 27

    //printf(BOLDBLUE);
    //printf("RdArduinoClient options:\n");
    //printf("\t--gpios %s\n",gpiosBottle.toString().c_str());
    //printf(RESET);

    if( gpiosBottle.size() < 1) {
        CD_ERROR("Please specify at least one gpio.\n");
        return false;
    }

    return true;
}

bool RdArduinoClient::close()
{

    return true;
}

}  // namespace rd
