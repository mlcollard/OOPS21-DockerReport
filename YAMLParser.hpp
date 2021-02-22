/*
    YAMLParser.hpp

    Declaration file for YAML parsing class
*/

#ifndef INCLUDED_YAMLPARSER_HPP
#define INCLUDED_YAMLPARSER_HPP

#include <string>

class YAMLParser {
public:

    // constructor
    YAMLParser();

    // is done parsing
    bool isDone(std::string::const_iterator pc, std::string::const_iterator end);

    // YAML parsing is at a key
    bool isKey(std::string::const_iterator pc);

    // Parse a YAML key
    std::string::const_iterator parseKey(std::string::const_iterator pc, std::string::const_iterator end, std::string& name);

    // YAML parsing is at a value
    bool isValue(std::string::const_iterator pc);

    // Parse a YAML value
    std::string::const_iterator parseValue(std::string::const_iterator pc, std::string::const_iterator end, std::string& value);

    // Skip an input character
    std::string::const_iterator  skipChar(std::string::const_iterator pc);

private:
    bool invalue = false;
    std::string buffer;
    std::string::const_iterator pc;
};

#endif
