#include "PathParser.h"

struct PathParser initPathParser(
    const char * source,
    const size_t sourceLength,
    const size_t sourceLimit,
    struct PathToken * tokens,
    const size_t tokensLimit) {

    return initPathParserWithTokenizer(initPathTokenizer(source, sourceLength, sourceLimit, tokens, tokensLimit));
}

struct PathParser initPathParserWithTokenizer(
    struct PathTokenizer tokenizer) {

    struct PathParser parser = {tokenizer};

    return parser;
}

///

void pathParserTokens(
    struct PathParser * parser,
    struct PathToken * tokens) {

    // while () {

    // }
}