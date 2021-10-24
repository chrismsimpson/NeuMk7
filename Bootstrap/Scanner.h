#ifndef SCANNER_H
#define SCANNER_H

#include <string.h>
#include <stdbool.h>

#include "Common.h"

struct Scanner {

    const struct String source;

    const size_t bufferSize;

    ///

    int position;

    int lineNumber;

    int column;
};

///

extern void incrementScannerForChar(
    struct Scanner * scanner,
    const char c);

///

extern struct Scanner initScanner(
    const char * source, 
    const size_t length,
    const size_t bufferSize);

extern struct Scanner initScannerFromString(
    const struct String source,
    const size_t bufferSize);

///

extern const bool isScannerAtEof(
    const struct Scanner * scanner);

///

extern const struct OptionalChar next(
    struct Scanner * scanner);

extern void nextWhile(
    struct Scanner * scanner,
    const bool (*test) (const char),
    char * buffer);

///

extern const struct OptionalChar peek(
    struct Scanner * scanner);

///

extern const char unsafePeek(
    struct Scanner * scanner);

extern void unsafePeekLength(
    struct Scanner * scanner,
    char * buffer,
    const size_t length);

#endif