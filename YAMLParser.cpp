/*
    YAMLParser.cpp

    Implementation file for YAML parsing class
*/

#include "YAMLParser.hpp"
#include "yaml_parser.hpp"

// constructor
YAMLParser::YAMLParser() {

}

// is done parsing
bool YAMLParser::isDone(std::string::const_iterator pc, std::string::const_iterator end) {

    return pc == end;
}

// YAML parsing is at a key
bool YAMLParser::isKey(std::string::const_iterator pc) {

    return ::isKey(pc, invalue);
}

// Parse a YAML key
std::string::const_iterator YAMLParser::parseKey(std::string::const_iterator pc, std::string::const_iterator end, std::string& name) {

    return ::parseKey(pc, end, name, invalue);
}

// YAML parsing is at a value
bool YAMLParser::isValue(std::string::const_iterator pc) {

    return ::isValue(pc, invalue);
}

// Parse a YAML value
std::string::const_iterator YAMLParser::parseValue(std::string::const_iterator pc, std::string::const_iterator end, std::string& value) {

    return ::parseValue(pc, end, value, invalue);
}

// Skip an input character
std::string::const_iterator YAMLParser::skipChar(std::string::const_iterator pc) {

    return std::next(pc);
}
