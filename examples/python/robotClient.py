#! /usr/bin/env python

import yarp
import rd

yarp.Network.init()

if yarp.Network.checkNetwork() != True:
    print "[error] Please try running yarp server"
    quit()

robotOptions = yarp.Property()
robotOptions.put('device','RobotClient')
robotOptions.put('name','/RobotServer')
robotDevice = yarp.PolyDriver(robotOptions)  # calls open -> connects

robot = rd.viewRobotManager(robotDevice)  # view the actual interface

print "moveForward"
robot.moveForward()

print "delay(5)"
yarp.Time.delay(5)

print "moveForward"
robot.stopMovement()

