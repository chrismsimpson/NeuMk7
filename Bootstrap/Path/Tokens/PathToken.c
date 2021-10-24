#include "PathToken.h"

struct PathToken initPathTokenFromComponent(
    const struct String source,
    const struct SourceLocation start,
    const struct SourceLocation end) {

    const struct PathToken token = {source, pathTokenTypeComponent, {}, start, end};

    return token;
}

struct PathToken initPathTokenFromPunc(
    const struct String source,
    const struct PathPunc punc,
    const struct SourceLocation start,
    const struct SourceLocation end) {

    const union PathTokenValue value = { .punc = punc };

    ///

    const struct PathToken token = {source, pathTokenTypePunc, value, start, end};

    return token;
}

extern struct PathToken initUnexpectedPathToken(
    const struct String source,
    const struct SourceLocation start,
    const struct SourceLocation end) {

    const struct PathToken token = {source, pathTokenTypeUnexpected, {}, start, end};

    return token;
}