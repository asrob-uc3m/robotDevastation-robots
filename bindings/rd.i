// Copyright: 
// Author: 
// CopyPolicy: 

//////////////////////////////////////////////////////////////////////////
// 
// This is a configuration file to explain ROBOT_DEVASTATION_ROBOTS to SWIG
//
// SWIG, for the most part, understands ROBOT_DEVASTATION_ROBOTS auto-magically.
// There are a few things that need to be explained:
//  + use of multiple inheritance
//  + use of names that clash with special names in Java/Python/Perl/...
//  + use of templates

%module rd

//%import "yarp.i"

%{
/* Includes the header in the wrapper code */
#include "RobotManager.hpp"
%}

/* Parse the header file to generate wrappers */
%include "RobotManager.hpp"

%{
#include <yarp/dev/all.h>
rd::RobotManager *viewRobotManager(yarp::dev::PolyDriver& d)
{
    rd::RobotManager *result;
    d.view(result);
    return result;
}
%}
extern rd::RobotManager *viewRobotManager(yarp::dev::PolyDriver& d);

