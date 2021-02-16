/*
    yaml_parser.cpp

    Implementation file for YAML parsing functions
*/

#include "yaml_parser.hpp"

namespace {

    // skip over initial whitespace in [pc, endpc)
    std::string::const_iterator skipWhitespace(std::string::const_iterator pc, std::string::const_iterator endpc) {

        return std::find_if_not(pc, endpc, [] (char c) { return isspace(c); });
    }

    // parse a name from pc to endpc
    std::string::const_iterator parseName(std::string::const_iterator pc, std::string::const_iterator endpc, std::string& name) {

        auto endname = std::find_if_not(pc, endpc, [] (char c) { return isalnum(c) || c == '_' || c == '.'; });
        if (endname == endpc)
            exit(1);
        name.assign(pc, endname);

        return endname;
    }

    // parse a value from pc to endpc
    std::string::const_iterator parseString(std::string::const_iterator pc, std::string::const_iterator endpc, std::string& value) {

        if (*pc == '"')
            std::advance(pc, 1);
        auto valueend = std::find_if(pc, endpc, [] (char c) { return c == '"' || c == ' ' || c == '\n'; });
        value.assign(pc, valueend);
        if (*valueend == '"')
            std::advance(valueend, 1);

        return valueend;
    }

}

// YAML parsing is at a key
bool isKey(std::string::const_iterator pc, bool invalue) {

    return !invalue && isalpha(*pc);
}

// YAML parsing is at a value
bool isValue(std::string::const_iterator pc, bool invalue) {

    return invalue && (isalpha(*pc) || *pc == '"');
}

// Parse a YAML key
std::string::const_iterator parseKey(std::string::const_iterator pc, std::string::const_iterator endpc, std::string& name, bool& invalue) {

    pc = parseName(pc, endpc, name);
    pc = skipWhitespace(pc, endpc);

    // skip over required ':' that ends the key
    if (*pc != ':')
        exit(1);
    std::advance(pc, 1);

    pc = skipWhitespace(pc, endpc);
    invalue = true;

    return pc;
}

// Parse a YAML value
std::string::const_iterator parseValue(std::string::const_iterator pc, std::string::const_iterator endpc, std::string& value, bool& invalue) {

    pc = skipWhitespace(pc, endpc);
    pc = parseString(pc, endpc, value);
    pc = skipWhitespace(pc, endpc);
    invalue = false;

    return pc;
}
