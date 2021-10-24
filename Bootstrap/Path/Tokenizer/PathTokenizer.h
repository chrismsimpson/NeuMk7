#ifndef PATH_TOKENIZER_H
#define PATH_TOKENIZER_H

#include <limits.h>

#include "../../Scanner.h"

#include "../Tokens/PathComponent.h"
#include "../Tokens/PathPunc.h"
#include "../Tokens/PathToken.h"

struct PathTokenizer {

    struct Scanner scanner;
};

///

extern struct PathTokenizer initPathTokenizer(
    const char * source, 
    const size_t length,
    const size_t bufferSize);

extern struct PathTokenizer initPathTokenizerWithScanner(
    struct Scanner scanner);

///

extern const struct PathToken unsafeNextPathToken(
    struct PathTokenizer * tokenizer);

///

extern const struct PathToken unsafeTokenizePathComponent(
    struct PathTokenizer * tokenizer);

///

extern const struct PathToken unsafeTokenizePathPunc(
    struct PathTokenizer * tokenizer,
    const char c,
    const enum PathPuncType puncType);

extern const struct PathToken unsafeTokenizePathPuncSlash(
    struct PathTokenizer * tokenizer);

///

extern const struct PathToken unsafeTokenizeUnexpectedPathToken(
    struct PathTokenizer * tokenizer);

#endif