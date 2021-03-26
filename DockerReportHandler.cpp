/*
    DockerReportHandler.cpp

    Implementation for DockerReportHandler class
*/

#include "DockerReportHandler.hpp"

// @get Version number
const std::string& DockerReportHandler::getVersion() const {

    return version;
}

// @get Key count
int DockerReportHandler::getKeyCount() const {

    return key_count;
}

// @get Ubuntu count
int DockerReportHandler::getUbuntuCount() const {

    return ubuntu_count;
}

// @get Fedora count
int DockerReportHandler::getFedoraCount() const {

    return fedora_count;
}

// @get CentOS count
int DockerReportHandler::getCentOSCount() const {

    return centos_count;
}

// @get OpenSuse count
int DockerReportHandler::getOpenSuseCount() const {

    return opensuse_count;
}


// process Key
void DockerReportHandler::processKey(const std::string& name) {

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
void DockerReportHandler::processValue(const std::string& value) {

    // save the version value
    if (inversion) {
        version = value;
        inversion = false;
    }
}
