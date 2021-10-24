#include "Scanner.h"

struct Scanner initScanner(
    const char * source, 
    const size_t length,
    const size_t bufferSize) {

    struct String s = {source, length};

    ///

    return initScannerFromString(s, bufferSize);
}

struct Scanner initScannerFromString(
    const struct String source,
    const size_t bufferSize) {

    struct Scanner scanner = {source, bufferSize, 0, 1, 1};

    ///

    return scanner;
}

///

void incrementScannerForChar(
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

const bool isScannerAtEof(
    const struct Scanner * scanner) {

    return scanner->position >= scanner->source.length;
}

///

const struct OptionalChar next(
    struct Scanner * scanner) {

    const struct OptionalChar c = peek(scanner);

    ///

    if (c.option == some) {

        incrementScannerForChar(scanner, c.value);
    }

    ///

    return c;
}

void nextWhile(
    struct Scanner * scanner,
    const bool (*test) (const char),
    char * buffer) {

    int i = 0;

    while (!isScannerAtEof(scanner) && test(unsafePeek(scanner))) {

        const struct OptionalChar c = next(scanner);

        if (c.option == none) {

            printf("warn: unexpected nil char");

            return;
        }

        ///

        buffer[i] = c.value;

        ///

        i++;

        ///

        if (i >= scanner->bufferSize) {

            printf("warn: reached scanner buffer size");

            return;
        }
    }

    ///

    buffer[i] = '\0';
}

///

const struct OptionalChar peek(
    struct Scanner * scanner) {

    if (isScannerAtEof(scanner)) {

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