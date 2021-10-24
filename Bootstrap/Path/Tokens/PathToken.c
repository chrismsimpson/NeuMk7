#include "PathToken.h"

const struct PathToken initPathTokenFromComponent(
    const struct String source,
    const struct SourceLocation start,
    const struct SourceLocation end) {

    const struct PathToken token = {source, pathTokenTypeComponent, {}, start, end};

    return token;
}

const struct PathToken initPathTokenFromPunc(
    const struct String source,
    const struct PathPunc punc,
    const struct SourceLocation start,
    const struct SourceLocation end) {

    const union PathTokenValue value = { .punc = punc };

    ///

    const struct PathToken token = {source, pathTokenTypePunc, value, start, end};

    return token;
}


const struct OptionalPathToken initNilPathToken() {

    struct OptionalPathToken t = {none, {}};

    ///

    return t;
}

const struct OptionalPathToken initOptionalPathToken(
    const struct PathToken token) {

    struct OptionalPathToken t = {some, token};

    ///

    return t;
}

const struct PathToken initUnexpectedPathToken(
    const struct String source,
    const struct SourceLocation start,
    const struct SourceLocation end) {

    const struct PathToken token = {source, pathTokenTypeUnexpected, {}, start, end};

    return token;
}