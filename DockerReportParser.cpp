/*
    DockerReportParser.cpp

    Implementation for DockerReportParser class
*/

#include "DockerReportParser.hpp"

// process Key
void DockerReportParser::processKey(const std::string& name) {

    // update docker counters and version
    if (name == "version") {
        inversion = true;
    } else {
        ++key_count;
        std::string name_prefix = name.substr(0, name.find('_'));
        if (name_prefix == "ubuntu") {
            ++ubuntu_count;
        } else if (name_prefix == "fedora") {
            ++fedora_count;
        } else if (name_prefix == "centos") {
            ++centos_count;
        } else if (name_prefix == "opensuse") {
            ++opensuse_count;
        }
    }
}

// process Value
void DockerReportParser::processValue(const std::string& value) {

    // save the version value
    if (inversion) {
        version = value;
        inversion = false;
    }
}
