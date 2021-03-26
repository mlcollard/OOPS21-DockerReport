/*
    ParserEngine.cpp

    Implementation file for ParserEngine
*/

#include "ParserEngine.hpp"
#include "YAMLParser.hpp"

// parse the YAML according to the handler
void goParse(YAMLParserHandler& handler) {

    YAMLParser parser(handler);
    parser.parse();
}
