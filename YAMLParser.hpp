/*
    YAMLParser.hpp

    Declaration file for YAML parsing class
*/

#ifndef INCLUDED_YAMLPARSER_HPP
#define INCLUDED_YAMLPARSER_HPP

#include "YAMLParserHandler.hpp"

#include <functional>
#include <string>

class YAMLParser {
public:

    // constructor
    YAMLParser(YAMLParserHandler& handler);

    // parse the YAML
    void parse();

    // destructor
    virtual ~YAMLParser();

private:

    // is done parsing
    bool isDone() const;

    // YAML parsing is at a key
    bool isKey() const;

    // Parse a YAML key
    void parseKey(std::string& name);

    // YAML parsing is at a value
    bool isValue() const;

    // Parse a YAML value
    void parseValue(std::string& value);

    // Skip an input character
    void skipChar();

    bool invalue = false;
    std::string buffer;
    std::string::const_iterator pc;

    YAMLParserHandler& handler;
};

#endif
