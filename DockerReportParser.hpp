/*
    DockerReportParser.hpp

    Declaration file for DockerReportParser
*/

#ifndef INCLUDED_DOCKERREPORTPARSER_HPP
#define INCLUDED_DOCKERREPORTPARSER_HPP

#include "YAMLParser.hpp"

class DockerReportParser : public YAMLParser {
public:

    // @get Version number
    const std::string& getVersion() const;

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
