#ifndef PATH_PARSER_H
#define PATH_PARSER_H

#include <limits.h>

#include "../../Scanner.h"

#include "../Tokenizer/PathTokenizer.h"
#include "../Tokens/PathToken.h"

struct PathParser {

    struct PathTokenizer tokenizer;
};

///

extern void initPathParser(
    const char * source,
    const size_t sourceLength,
    const size_t sourceLimit,
    struct PathToken * tokens,
    const size_t tokensLimit);

// extern struct PathParser initPathParser(
//     const char * source,
//     const size_t length, 
//     const size_t limit);

///

extern void parsePathTokens(
    struct PathParser * parser,
    struct PathToken * tokens);

#endif