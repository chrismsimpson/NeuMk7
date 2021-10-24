#ifndef PATH_TOKEN_H
#define PATH_TOKEN_H

#include "../../Common.h"
#include "../../SourceLocation.h"

#include "PathComponent.h"
#include "PathPunc.h"

enum PathTokenType {

    pathTokenTypeComponent,
    pathTokenTypePunc,
    pathTokenTypeUnexpected
};

union PathTokenValue {

    const struct PathComponent component;

    const struct PathPunc punc;
};

struct PathToken {

    const struct String source;

    const enum PathTokenType tokenType;

    const union PathTokenValue value;

    const struct SourceLocation start;

    const struct SourceLocation end;
};

struct OptionalPathToken {

    const enum Option option;

    const struct PathToken value;
};

struct SpanOfPathTokens {

    const struct PathToken * tokens;

    const size_t length;

    const size_t limit;
};

///

extern struct PathToken initPathTokenFromComponent(
    const struct String source,
    const struct SourceLocation start,
    const struct SourceLocation end);

extern struct PathToken initPathTokenFromPunc(
    const struct String source,
    const struct PathPunc punc,
    const struct SourceLocation start,
    const struct SourceLocation end);

extern struct PathToken initUnexpectedPathToken(
    const struct String source,
    const struct SourceLocation start,
    const struct SourceLocation end);

#endif