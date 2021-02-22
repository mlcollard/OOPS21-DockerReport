/*
    YAMLParser.cpp

    Implementation file for YAML parsing class
*/

#include "YAMLParser.hpp"
#include "yaml_parser.hpp"
#include <iostream>
#include <sstream>

// constructor
YAMLParser::YAMLParser() {

    // input complete file into a string
    std::ostringstream sstream;
    sstream << std::cin.rdbuf();
    buffer = sstream.str();

    pc = buffer.cbegin();
}

// is done parsing
bool YAMLParser::isDone() {

    return pc == buffer.cend();
}

// YAML parsing is at a key
bool YAMLParser::isKey() {

    return ::isKey(pc, invalue);
}

// Parse a YAML key
void YAMLParser::parseKey(std::string& name) {

    pc = ::parseKey(pc, buffer.cend(), name, invalue);
}

// YAML parsing is at a value
bool YAMLParser::isValue() {

    return ::isValue(pc, invalue);
}

// Parse a YAML value
void YAMLParser::parseValue(std::string& value) {

    pc = ::parseValue(pc, buffer.cend(), value, invalue);
}

// Skip an input character
void YAMLParser::skipChar() {

    std::advance(pc, 1);
}
