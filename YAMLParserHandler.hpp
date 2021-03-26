/*
    YAMLParserHandler.hpp

    Declaration file for YAML parsing class handler
*/

#ifndef INCLUDED_YAMLPARSERHANDLER_HPP
#define INCLUDED_YAMLPARSERHANDLER_HPP

#include <string>

class YAMLParserHandler {
protected:

    // process Key
    virtual void processKey(const std::string& name) = 0;

    // process Value
    virtual void processValue(const std::string& value) = 0;
};

#endif
