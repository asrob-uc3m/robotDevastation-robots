// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "FakeMotorController.hpp"

namespace rd
{

bool FakeMotorController::open(yarp::os::Searchable& config)
{
    CD_INFO("[FakeMotorController]\n");
    return true;
}

bool FakeMotorController::close()
{

    return true;
}

}  // namespace rd
