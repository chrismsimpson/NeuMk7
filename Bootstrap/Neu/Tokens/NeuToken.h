#ifndef NEU_TOKEN_H
#define NEU_TOKEN_H

#include "NeuKeyword.h"

enum NeuTokenType {

    neuTokenTypeKeyword
};

union NeuTokenValue {

    const struct NeuKeyword keyword;
};

struct NeuToken {

    const enum NeuTokenType tokenType;

    const union NeuTokenValue value;
};

#endif