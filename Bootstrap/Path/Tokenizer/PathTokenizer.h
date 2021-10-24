#ifndef PATH_TOKENIZER_H
#define PATH_TOKENIZER_H

#include <stdbool.h>
#include <limits.h>

#include "../../Scanner.h"
#include "../../SourceLocation.h"

#include "../Tokens/PathComponent.h"
#include "../Tokens/PathPunc.h"
#include "../Tokens/PathToken.h"

struct PathTokenizer {

    struct Scanner scanner;

    struct SpanOfPathTokens span;

    size_t position;
};

///

extern struct PathTokenizer initPathTokenizer(
    const char * source, 
    const size_t sourceLength,
    const size_t sourceLimit,
    struct PathToken * tokens,
    const size_t tokensLimit);

extern struct PathTokenizer initPathTokenizerWithScanner(
    struct Scanner scanner,
    struct PathToken * tokens,
    const size_t tokensLimit);

///

extern const bool pathTokenizerIsAtEof(
    struct PathTokenizer * tokenizer);

///

extern const struct SourceLocation pathTokenizerLocation(
    struct PathTokenizer * tokenizer);

///

extern void pathTokenizerNext(
    struct PathTokenizer * tokenizer);

///

extern const struct PathToken unsafePathTokenizerNext(
    struct PathTokenizer * tokenizer);

///

extern const struct PathToken unsafePathTokenizerComponent(
    struct PathTokenizer * tokenizer);

///

extern const struct PathToken unsafePathTokenizerPunc(
    struct PathTokenizer * tokenizer,
    const char c,
    const enum PathPuncType puncType);

extern const struct PathToken unsafePathTokenizerSlash(
    struct PathTokenizer * tokenizer);

///

extern const struct PathToken unsafePathTokenizerUnexpected(
    struct PathTokenizer * tokenizer);

#endif