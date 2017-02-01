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
#include "RdRobotManager.hpp"
%}

/* Parse the header file to generate wrappers */
%include "RdRobotManager.hpp"

/*%extend ColorClient {
	int size() {
		int buffer;
		bool ok = self->size(buffer);
		if (!ok) return 0;
		return buffer;
	}
}*/

