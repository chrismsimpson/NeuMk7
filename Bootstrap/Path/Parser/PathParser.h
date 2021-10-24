#ifndef PATH_PARSER_H
#define PATH_PARSER_H

#include <limits.h>

#include "../../Scanner.h"

#include "../Tokenizer/PathTokenizer.h"

struct PathParser {

    struct PathTokenizer tokenizer;
};

///

extern struct PathParser initPathParser(
    const char * source,
    const size_t length, 
    const size_t bufferSize);

///

extern void parsePathTokens(
    struct PathParser * parser,
    struct PathToken * tokens);

#endif