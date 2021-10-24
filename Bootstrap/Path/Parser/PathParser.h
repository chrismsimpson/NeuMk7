#ifndef PATH_PARSER_H
#define PATH_PARSER_H

#include <limits.h>

#include "../../Scanner.h"

#include "../Tokenizer/PathTokenizer.h"
#include "../Tokens/PathToken.h"

#include "../Path.h"

struct PathParser {

    struct PathTokenizer tokenizer;
};

///

extern struct PathParser initPathParser(
    const char * source,
    const size_t sourceLength,
    const size_t sourceLimit,
    struct PathToken * tokens,
    const size_t tokensLimit);

extern struct PathParser initPathParserWithTokenizer(
    struct PathTokenizer tokenizer);

///

extern const struct Path pathParserPath(
    struct PathParser * parser,
    struct PathToken * tokens,
    const size_t tokensLimit);

///

extern const struct SpanOfPathTokens pathParserTokens(
    struct PathParser * parser,
    struct PathToken * tokens,
    const size_t tokensLimit);

#endif