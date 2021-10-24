#include "Scanner.h"

struct Scanner initScanner(
    const char * source, 
    const size_t length,
    const size_t limit) {

    struct String s = {source, length, limit};

    ///

    return initScannerWithString(s);
}

struct Scanner initScannerWithString(
    const struct String source) {

    struct Scanner scanner = {source, 0, 1, 1};

    ///

    return scanner;
}

///

void scannerIncrementWithChar(
    struct Scanner * scanner,
    const char c) {

    scanner->position++;

    ///

    switch (c) {

        case '\n':

            scanner->lineNumber++;

            scanner->column = 0;

            break;

        ///

        default:

            scanner->column++;

            break;
    }
}

///

const bool scannerIsAtEof(
    const struct Scanner * scanner) {

    return scanner->position >= scanner->source.length;
}

///


const struct SourceLocation scannerLocation(
    struct Scanner * scanner) {

    const struct SourceLocation l = {scanner->position, scanner->lineNumber, scanner->column};

    ///

    return l;
}

///

const struct OptionalChar scannerNext(
    struct Scanner * scanner) {

    const struct OptionalChar c = peek(scanner);

    ///

    if (c.option == some) {

        scannerIncrementWithChar(scanner, c.value);
    }

    ///

    return c;
}

const size_t nextWhile(
    struct Scanner * scanner,
    char * buffer,
    const bool (*test) (const char)) {

    size_t i = 0;

    while (!scannerIsAtEof(scanner) && test(unsafePeek(scanner))) {

        const struct OptionalChar c = scannerNext(scanner);

        if (c.option == none) {

            printf("warn: unexpected nil char");

            return i;
        }

        ///

        buffer[i] = c.value;

        ///

        i++;

        ///

        if (i >= scanner->source.limit) {

            printf("warn: reached scanner buffer size");

            return i;
        }
    }

    ///

    buffer[i] = '\0';

    ///

    return i;
}

///

const struct OptionalChar peek(
    struct Scanner * scanner) {

    if (scannerIsAtEof(scanner)) {

        return initNilChar();
    }

    ///

    return initOptionalChar(unsafePeek(scanner));
}

///

const char unsafePeek(
    struct Scanner * scanner) {

    char buffer;

    unsafePeekLength(scanner, &buffer, 1);

    return buffer;
}

void unsafePeekLength(
    struct Scanner * scanner,
    char * buffer,
    const size_t length) {

    strncpy(buffer, &scanner->source.source[scanner->position], length);
}