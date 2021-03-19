/*
    DockerReportParser.hpp

    Declaration file for DockerReportParser
*/

#ifndef INCLUDED_DOCKERREPORTPARSER_HPP
#define INCLUDED_DOCKERREPORTPARSER_HPP

#include "YAMLParser.hpp"

class DockerReportParser : public YAMLParser {
private:

    // process Key
    virtual void processKey(const std::string& name);

    // process Value
    virtual void processValue(const std::string& value);
};

#endif
