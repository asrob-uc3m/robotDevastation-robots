// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "RaspiOnePwmMotorController.hpp"

namespace rd
{

bool RaspiOnePwmMotorController::open(yarp::os::Searchable& config)
{

    yarp::os::Bottle gpiosBottle = config.findGroup("gpios").tail();  //-- e.g. 17 27

    printf(BOLDBLUE);
    printf("RaspiOnePwmMotorController options:\n");
    printf("\t--gpios %s\n",gpiosBottle.toString().c_str());
    printf(RESET);

    if( gpiosBottle.size() < 1) {
        CD_ERROR("Please specify at least one gpio.\n");
        return false;
    }

    if ( config.check("pcm") )
        setup(PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT, DELAY_VIA_PCM);
    else
        setup(PULSE_WIDTH_INCREMENT_GRANULARITY_US_DEFAULT, DELAY_VIA_PWM);

    init_channel(0, SUBCYCLE_TIME_US_DEFAULT);  //10ms;
    print_channel(0);

    for(int j=0; j < gpiosBottle.size(); j++)
    {
        int gpio = gpiosBottle.get(j).asInt();
        add_channel_pulse(0, gpio, 0, 0);
        gpios.push_back( gpiosBottle.get(j).asInt() );
        CD_SUCCESS("Configured gpio %d on channel 0.\n",gpio);
    }
    
    return true;
}

bool RaspiOnePwmMotorController::close()
{

    return true;
}

}  // namespace rd
