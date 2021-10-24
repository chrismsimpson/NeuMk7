#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>

enum Result {

    success,
    failure
};

enum Option {

    none,
    some
};

struct OptionalChar {

    const enum Option option;

    const char value;
};

///

extern const struct OptionalChar initNilChar();

extern const struct OptionalChar initOptionalChar(
    const char value);

///

struct String {

    const char * source;

    const size_t length;

};

struct OptionalString {

    const enum Option option;

    const struct String value;
};

#endif