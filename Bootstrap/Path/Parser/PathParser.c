#include "PathParser.h"

struct PathParser initPathParser(
    const char * source, 
    const size_t length, 
    const size_t bufferSize) {

    struct PathParser parser = {initPathTokenizer(source, length, bufferSize)};

    ///

    return parser;
}

///

void parsePathTokens(
    struct PathParser * parser,
    struct PathToken * tokens) {

    
}