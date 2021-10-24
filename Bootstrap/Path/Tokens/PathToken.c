#include "PathToken.h"

struct PathToken initPathTokenFromPunc(
    const char * source,
    const struct PathPunc punc,
    const struct SourceLocation start,
    const struct SourceLocation end) {

    const struct String s = {source, 1};

    ///

    const union PathTokenValue value = { .punc = punc };

    ///

    const struct PathToken token = {s, pathTokenTypePunc, value, start, end};

    return token;
}

extern struct PathToken initUnexpectedPathToken(
    const char * source,
    const struct SourceLocation start,
    const struct SourceLocation end) {

    const struct String s = {source, 1};

    ///

    const struct PathToken token = {s, pathTokenTypeUnexpected, {}, start, end};

    return token;
}