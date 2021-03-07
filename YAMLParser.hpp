/*
    YAMLParser.hpp

    Declaration file for YAML parsing class
*/

#ifndef INCLUDED_YAMLPARSER_HPP
#define INCLUDED_YAMLPARSER_HPP

#include <functional>
#include <string>

class YAMLParser {
public:

    // constructor
    YAMLParser(std::function<void(const std::string&)> handleKey,
               std::function<void(const std::string&)> handleValue);

    // parse the YAML
    void parse();

private:

    // is done parsing
    bool isDone();

    // YAML parsing is at a key
    bool isKey();

    // Parse a YAML key
    void parseKey(std::string& name);

    // YAML parsing is at a value
    bool isValue();

    // Parse a YAML value
    void parseValue(std::string& value);

    // Skip an input character
    void skipChar();

    std::function<void(const std::string&)> handleKey;
    std::function<void(const std::string&)> handleValue;
    bool invalue = false;
    std::string buffer;
    std::string::const_iterator pc;
};

#endif
