/*
    DockerReportParser.cpp

    Implementation for DockerReportParser class
*/

#include "DockerReportParser.hpp"

// process Key
void DockerReportParser::processKey(const std::string& name) {

}

// process Value
void DockerReportParser::processValue(const std::string& value) {

    // save the version value
    if (inversion) {
        version = value;
        inversion = false;
    }
}
