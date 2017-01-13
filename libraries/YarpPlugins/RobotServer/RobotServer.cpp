// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "RobotServer.hpp"

namespace rd
{

bool RobotServer::indexWithinRange(const int& idx)
{
    if (idx >= gpios.size() ){
        CD_WARNING("Index out of range!! (%d >= " CD_SIZE_T ")!!!\n",idx,gpios.size());
        return false;
    }
    return true;
}

bool RobotServer::read(yarp::os::ConnectionReader& connection)
{
    yarp::os::Bottle in, out;
    bool ok = in.read(connection);
    if (!ok) return false;

    // process data "in", prepare "out"
    CD_DEBUG("Got: %s\n",in.toString().c_str());

    if( in.get(0).asString() == "help")
    {
        out.addVocab(VOCAB_MOVE_FORWARD);
        out.addVocab(VOCAB_MOVE_BACKWARDS);
        out.addVocab(VOCAB_TURN_LEFT);
        out.addVocab(VOCAB_TURN_RIGHT);
        out.addVocab(VOCAB_STOP_MOVEMENT);
        out.addVocab(VOCAB_TILT_UP);
        out.addVocab(VOCAB_TILT_DOWN);
        out.addVocab(VOCAB_PAN_LEFT);
        out.addVocab(VOCAB_PAN_RIGHT);
        out.addVocab(VOCAB_STOP_CAMERA_MOVEMENT);
    }
    else if( in.get(0).asVocab() == VOCAB_MOVE_FORWARD)
    {
        iRdRobot->moveForward( in.get(1).asInt() );
        out.addVocab(VOCAB_OK);
    }
    else if( in.get(0).asVocab() == VOCAB_MOVE_BACKWARDS)
    {
        iRdRobot->moveBackwards( in.get(1).asInt() );
        out.addVocab(VOCAB_OK);
    }
    else if( in.get(0).asVocab() == VOCAB_TURN_LEFT)
    {
        iRdRobot->turnLeft( in.get(1).asInt() );
        out.addVocab(VOCAB_OK);
    }
    else if( in.get(0).asVocab() == VOCAB_TURN_RIGHT)
    {
        iRdRobot->turnRight( in.get(1).asInt() );
        out.addVocab(VOCAB_OK);
    }
    else if( in.get(0).asVocab() == VOCAB_STOP_MOVEMENT)
    {
        iRdRobot->stopMovement();
        out.addVocab(VOCAB_OK);
    }
    else if( in.get(0).asVocab() == VOCAB_TILT_UP)
    {
        iRdRobot->tiltUp( in.get(1).asInt() );
        out.addVocab(VOCAB_OK);
    }
    else if( in.get(0).asVocab() == VOCAB_TILT_DOWN)
    {
        iRdRobot->tiltDown( in.get(1).asInt() );
        out.addVocab(VOCAB_OK);
    }
    else if( in.get(0).asVocab() == VOCAB_PAN_LEFT)
    {
        iRdRobot->panLeft( in.get(1).asInt() );
        out.addVocab(VOCAB_OK);
    }
    else if( in.get(0).asVocab() == VOCAB_PAN_RIGHT)
    {
        iRdRobot->panRight( in.get(1).asInt() );
        out.addVocab(VOCAB_OK);
    }
    else if( in.get(0).asVocab() == VOCAB_STOP_CAMERA_MOVEMENT)
    {
        iRdRobot->stopCameraMovement();
        out.addVocab(VOCAB_OK);
    }
    else
    {
        out.addVocab(VOCAB_FAILED);
    }

    yarp::os::ConnectionWriter *returnToSender = connection.getWriter();
    if (returnToSender!=NULL) {
        out.write(*returnToSender);
    }
    return true;
}

}  // namespace rd

