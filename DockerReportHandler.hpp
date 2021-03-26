/*
    DockerReportHandler.hpp

    Declaration file for DockerReportHandler
*/

#ifndef INCLUDED_DOCKERREPORTHANDLER_HPP
#define INCLUDED_DOCKERREPORTHANDLER_HPP

#include "YAMLParser.hpp"

class DockerReportHandler : public YAMLParser {
public:

    // @get Version number
    const std::string& getVersion() const;

    // @get Key count
    int getKeyCount() const;

    // @get Ubuntu count
    int getUbuntuCount() const;

    // @get Fedora count
    int getFedoraCount() const;

    // @get CentOS count
    int getCentOSCount() const;

    // @get OpenSuse count
    int getOpenSuseCount() const;

private:

    // process Key
    virtual void processKey(const std::string& name);

    // process Value
    virtual void processValue(const std::string& value);

public:
    std::string version;
    bool inversion = false;
    int key_count = 0;
    int ubuntu_count = 0;
    int fedora_count = 0;
    int centos_count = 0;
    int opensuse_count = 0;
};

#endif
