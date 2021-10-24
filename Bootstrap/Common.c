#include "Common.h"

const struct OptionalChar initNilChar() {

    struct OptionalChar c = {none, '\0'};
    
    ///

    return c;
}

const struct OptionalChar initOptionalChar(
    const char value) {

    struct OptionalChar c = {some, value};
    
    ///

    return c;
}