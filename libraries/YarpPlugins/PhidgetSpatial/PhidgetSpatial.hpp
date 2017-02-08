// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#ifndef __PHIDGET_SPATIAL__
#define __PHIDGET_SPATIAL__

#include <yarp/os/all.h>
#include <yarp/dev/Drivers.h>
#include <yarp/dev/PolyDriver.h>

#include <vector>
#include <math.h>

#include <phidget21.h>

using namespace yarp::os;
using namespace yarp::dev;

namespace rd
{

/**
 * @ingroup YarpPlugins
 * @brief PhidgetSpatial
 */
class PhidgetSpatial : public DeviceDriver {
public:

// -------- DeviceDriver declarations. Implementation in IDeviceImpl.cpp --------

    /**
     * Open the DeviceDriver. 
     * @return true/false upon success/failure
     */
    virtual bool open(Searchable& config);
    virtual bool close();

    /**
     * Destructor.
     */
     ~PhidgetSpatial() {}

// -- Helper Funcion declarations. Implementation in HelperFuncs.cpp --
    ///////////////////////////////////////////////////////////////////////////
    // The following six functions have been extracted and modified from the - Spatial simple -
    // example ((creates an Spatial handle, hooks the event handlers, and then waits for an
    // encoder is attached. Once it is attached, the program will wait for user input so that
    // we can see the event data on the screen when using the encoder. Legal info:
    // Copyright 2008 Phidgets Inc.  All rights reserved.
    // This work is licensed under the Creative Commons Attribution 2.5 Canada License. 
    // view a copy of this license, visit http://creativecommons.org/licenses/by/2.5/ca/
    static int AttachHandler(CPhidgetHandle ENC, void *userptr);
    static int DetachHandler(CPhidgetHandle ENC, void *userptr);
    static int ErrorHandler(CPhidgetHandle ENC, void *userptr, int ErrorCode, const char *Description);
    static int SpatialDataHandler(CPhidgetSpatialHandle spatial, void *userptr, CPhidgetSpatial_SpatialEventDataHandle *data, int count);
    int display_properties(CPhidgetSpatialHandle phid);
    ///////////////////////////////////////////////////////////////////////////

// -- Shared Area Funcion declarations. Implementation in SharedArea.cpp --
    void setEncRaw(const int Index, const int Position);
    int getEncRaw(const int Index);
    double getEncExposed(const int Index);

// ------------------------------- Private -------------------------------------

private:
    Port port;
    CPhidgetSpatialHandle hSpatial0;
    Semaphore encRawMutex;  // SharedArea
    std::vector<int> encRaw;  // SharedArea
    std::vector<double> encRawExposed;  // For conversion.

};

}  // namespace rd

#endif

