#ifndef SCANNER_H
#define SCANNER_H

#include <string.h>
#include <stdbool.h>

#include "Common.h"

#include "SourceLocation.h"

struct Scanner {

    const struct String source;

    ///

    int position;

    int lineNumber;

    int column;
};

///

extern void incrementScannerWithChar(
    struct Scanner * scanner,
    const char c);

///

extern struct Scanner initScanner(
    const char * source, 
    const size_t length,
    const size_t limit);

extern struct Scanner initScannerWithString(
    const struct String source);

///

extern const bool scannerIsAtEof(
    const struct Scanner * scanner);

///

extern const struct SourceLocation scannerLocation(
    struct Scanner * scanner);

///

extern const struct OptionalChar next(
    struct Scanner * scanner);

extern const size_t nextWhile(
    struct Scanner * scanner,
    char * buffer,
    const bool (*test) (const char));

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