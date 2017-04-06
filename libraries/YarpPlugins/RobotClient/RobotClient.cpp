// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "RobotClient.hpp"

namespace rd
{

RobotClient::RobotClient()
{
}

bool RobotClient::indexWithinRange(const int& idx)
{
    if (idx >= gpios.size() ){
        CD_WARNING("Index out of range!! (%d >= " CD_SIZE_T ")!!!\n",idx,gpios.size());
        return false;
    }
    return true;
}

bool RobotClient::moveForward(int velocity)
{
    CD_DEBUG("\n");
    return send1vocab1int(VOCAB_MOVE_FORWARD,velocity);
}

bool RobotClient::moveBackwards(int velocity)
{
    CD_DEBUG("\n");
    return send1vocab1int(VOCAB_MOVE_BACKWARDS,velocity);
}

bool RobotClient::turnLeft(int velocity)
{
    CD_DEBUG("\n");
    return send1vocab1int(VOCAB_TURN_LEFT,velocity);
}

bool RobotClient::turnRight(int velocity)
{
    CD_DEBUG("\n");
    return send1vocab1int(VOCAB_TURN_RIGHT,velocity);
}

bool RobotClient::stopMovement()
{
    CD_DEBUG("\n");
    return send1vocab(VOCAB_STOP_MOVEMENT);
}

bool RobotClient::tiltUp(int velocity)
{
    CD_DEBUG("\n");
    return send1vocab1int(VOCAB_TILT_UP,velocity);
}

bool RobotClient::tiltDown(int velocity)
{
    CD_DEBUG("\n");
    return send1vocab1int(VOCAB_TILT_DOWN,velocity);
}

bool RobotClient::panLeft(int velocity)
{
    CD_DEBUG("\n");
    return send1vocab1int(VOCAB_PAN_LEFT,velocity);
}

bool RobotClient::panRight(int velocity)
{
    CD_DEBUG("\n");
    return send1vocab1int(VOCAB_PAN_RIGHT,velocity);
}

bool RobotClient::stopCameraMovement()
{
    CD_DEBUG("\n");
    return send1vocab(VOCAB_STOP_CAMERA_MOVEMENT);
}

bool RobotClient::send1vocab1int(int vocab, int integer)
{
    yarp::os::Bottle cmd, response;
    cmd.addVocab(vocab);
    cmd.addInt(integer);
    rpcClient.write(cmd,response);
    if( response.get(0).asVocab() == VOCAB_OK )
        return true;
    else
        return false;
}

bool RobotClient::send1vocab(int vocab)
{
    yarp::os::Bottle cmd, response;
    cmd.addVocab(vocab);
    rpcClient.write(cmd,response);
    if( response.get(0).asVocab() == VOCAB_OK )
        return true;
    else
        return false;
}

}  // namespace rd

