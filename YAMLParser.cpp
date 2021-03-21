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

// destructor
YAMLParser::~YAMLParser() {

}

// parse the YAML
void YAMLParser::parse() {

    while (true) {
        if (isDone()) {
            break;
        } else if (isKey()) {

            // parse key
            std::string name;
            parseKey(name);

        } else if (isValue()) {

            // parse value
            std::string value;
            parseValue(value);

        } else {
            skipChar();
        }
    }
}

// is done parsing
bool YAMLParser::isDone() const {

    return pc == buffer.cend();
}

// YAML parsing is at a key
bool YAMLParser::isKey() const {

    return ::isKey(pc, invalue);
}

// Parse a YAML key
void YAMLParser::parseKey(std::string& name) {

    pc = ::parseKey(pc, buffer.cend(), name, invalue);

    // call extension point for key
    processKey(name);
}

// YAML parsing is at a value
bool YAMLParser::isValue() const {

    return ::isValue(pc, invalue);
}

// Parse a YAML value
void YAMLParser::parseValue(std::string& value) {

    pc = ::parseValue(pc, buffer.cend(), value, invalue);

    // call extension point for value
    processValue(value);
}

// Skip an input character
void YAMLParser::skipChar() {

    std::advance(pc, 1);
}
