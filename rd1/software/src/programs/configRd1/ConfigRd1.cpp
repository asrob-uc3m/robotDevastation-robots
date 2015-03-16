// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "ConfigRd1.hpp"

namespace teo
{

/************************************************************************/
ConfigRd1::ConfigRd1() { }

/************************************************************************/
bool ConfigRd1::configure(ResourceFinder &rf) {

    std::string webIp = rf.check("webIp",yarp::os::Value(DEFAULT_WEB_IP),"web server ip").asString();
    int webPort = rf.check("webPort",yarp::os::Value(DEFAULT_WEB_PORT),"web server port").asInt();
    std::string name = rf.check("name",Value(DEFAULT_WEB_NAME),"web yarp port name").asString();

    //-- Configure and open web server
    server.setReader(responder);
    Contact contact = Contact::byName(name);
    if (webPort!=0) {
        contact = contact.addSocket("",webIp,webPort);
    }
    if (!server.open(contact)) return false;
    contact = server.where();

    return true;
}

/************************************************************************/

bool ConfigRd1::updateModule() {
    CD_INFO("Alive...\n");
    return true;
}

/************************************************************************/

bool ConfigRd1::close() {

    return true;
}

/************************************************************************/

}  // namespace teo
