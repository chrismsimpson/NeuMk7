#ifndef PATH_TOKEN_H
#define PATH_TOKEN_H

#include "../../Common.h"
#include "../../SourceLocation.h"

#include "PathComponent.h"
#include "PathPunc.h"

enum PathTokenType {

    pathTokenTypeComponent,
    pathTokenTypePunc
};

union PathTokenValue {

    const struct PathComponent component;

    const struct PathPunc punc;
};

struct PathToken {

    const enum PathTokenType tokenType;

    const union PathTokenValue value;

    const struct SourceLocation start;

    const struct SourceLocation end;
};

struct OptionalPathToken {

    const enum Option option;

    const struct PathToken value;
};

#endif