// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#ifndef __I_RD_ROBOT__
#define __I_RD_ROBOT__

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

