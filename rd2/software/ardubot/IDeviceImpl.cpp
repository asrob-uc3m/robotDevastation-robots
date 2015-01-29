// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "ArduBot.hpp"

// ------------------- DeviceDriver Related ------------------------------------

bool ArduBot::open(Searchable& config) {

    numMotors = config.check("pwmPins",Value(DEFAULT_NUM_MOTORS),"Number of motors").asInt();

    //Bottle ids = config.findGroup("ids").tail();  //-- e.g. 15
    
    return true;
}

// -----------------------------------------------------------------------------

bool ArduBot::close() {

    return true;
}

// -----------------------------------------------------------------------------

