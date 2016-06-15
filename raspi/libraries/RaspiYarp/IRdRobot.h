// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#ifndef __I_RD_ROBOT__
#define __I_RD_ROBOT__

#define VOCAB_MOVE_FORWARD VOCAB4('m','o','v','f')
#define VOCAB_MOVE_BACKWARDS VOCAB4('m','o','v','b')
#define VOCAB_TURN_LEFT VOCAB4('t','r','n','l')
#define VOCAB_TURN_RIGHT VOCAB4('t','r','n','r')
#define VOCAB_STOP_MOVEMENT VOCAB4('s','t','p','m')

#define VOCAB_TILT_UP VOCAB4('t','l','t','u')
#define VOCAB_TILT_DOWN VOCAB4('t','l','t','d')
#define VOCAB_PAN_LEFT VOCAB4('p','a','n','l')
#define VOCAB_PAN_RIGHT VOCAB4('p','a','n','r')
#define VOCAB_STOP_CAMERA_MOVEMENT VOCAB4('s','t','p','c')

namespace rd
{

/**
 *
 * @brief Abstract base for a RD robot.
 *
 */
class IRdRobot
{
public:
    /**
     * Destructor.
     */
    virtual ~IRdRobot() {}

    //-- Robot movement related functions
    virtual bool moveForward(int velocity = UNUSED) = 0;
    virtual bool moveBackwards(int velocity = UNUSED) = 0;
    virtual bool turnLeft(int velocity = UNUSED) = 0;
    virtual bool turnRight(int velocity = UNUSED) = 0;
    virtual bool stopMovement() = 0;

    //-- Robot camera related functions
    virtual bool tiltUp(int velocity = UNUSED) = 0;
    virtual bool tiltDown(int velocity = UNUSED) = 0;
    virtual bool panLeft(int velocity = UNUSED) = 0;
    virtual bool panRight(int velocity = UNUSED) = 0;
    virtual bool stopCameraMovement() = 0;

protected:
    static const int UNUSED = -1;
};

}  // namespace rd

#endif  //  __I_RD_ROBOT__

