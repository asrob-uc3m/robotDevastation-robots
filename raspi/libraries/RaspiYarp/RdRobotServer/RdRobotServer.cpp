// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "RdRobotServer.hpp"

namespace rd
{

bool RdRobotServer::indexWithinRange(const int& idx)
{
    if (idx >= gpios.size() ){
        CD_WARNING("Index out of range!! (%d >= " CD_SIZE_T ")!!!\n",idx,gpios.size());
        return false;
    }
    return true;
}

bool RdRobotServer::read(yarp::os::ConnectionReader& connection)
{
    yarp::os::Bottle in, out;
    bool ok = in.read(connection);
    if (!ok) return false;

    // process data "in", prepare "out"
    CD_INFO("Got: %s\n",in.toString().c_str());
    out.addVocab(VOCAB_OK);

    yarp::os::ConnectionWriter *returnToSender = connection.getWriter();
    if (returnToSender!=NULL) {
        out.write(*returnToSender);
    }
    return true;
}

}  // namespace rd

