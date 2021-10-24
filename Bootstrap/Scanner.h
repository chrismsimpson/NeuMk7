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

extern struct Scanner initScanner(
    const char * source, 
    const size_t length,
    const size_t limit);

extern struct Scanner initScannerWithString(
    const struct String source);

///

extern void scannerIncrementWithChar(
    struct Scanner * scanner,
    const char c);

///

extern const bool scannerIsAtEof(
    const struct Scanner * scanner);

///

extern const struct SourceLocation scannerLocation(
    struct Scanner * scanner);

///

extern const struct OptionalChar scannerNext(
    struct Scanner * scanner);

extern const size_t scannerNextWhile(
    struct Scanner * scanner,
    char * buffer,
    const bool (*test) (const char));

///

extern const struct OptionalChar scannerPeek(
    struct Scanner * scanner);

///

extern const char unsafeScannerPeek(
    struct Scanner * scanner);

extern void unsafeScannerPeekLength(
    struct Scanner * scanner,
    char * buffer,
    const size_t length);

#endif