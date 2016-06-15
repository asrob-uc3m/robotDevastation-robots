// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "RdFakeMotors.hpp"

namespace rd
{

bool RdFakeMotors::open(yarp::os::Searchable& config)
{
    CD_INFO("[RdFakeMotors]\n");
    return true;
}

bool RdFakeMotors::close()
{

    return true;
}

}  // namespace rd
