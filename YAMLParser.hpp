/*
    YAMLParser.hpp

    Declaration file for YAML parsing class
*/

#ifndef INCLUDED_YAMLPARSER_HPP
#define INCLUDED_YAMLPARSER_HPP

#include <string>

class YAMLParser {
public:
    // YAML parsing is at a key
    bool isKey(std::string::const_iterator pc);

    // Parse a YAML key
    std::string::const_iterator parseKey(std::string::const_iterator pc, std::string::const_iterator end, std::string& name);

    // YAML parsing is at a value
    bool isValue(std::string::const_iterator pc);

    // Parse a YAML value
    std::string::const_iterator parseValue(std::string::const_iterator pc, std::string::const_iterator end, std::string& value);

private:
    bool invalue = false;
};

#endif
