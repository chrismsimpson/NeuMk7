#include "PathTokenizer.h"

struct PathTokenizer initPathTokenizer(
    const char * source, 
    const size_t sourceLength,
    const size_t sourceLimit,
    struct PathToken * tokens,
    const size_t tokensLimit) {

    return initPathTokenizerWithScanner(initScanner(source, sourceLength, sourceLimit), tokens, tokensLimit);
}

struct PathTokenizer initPathTokenizerWithScanner(
    struct Scanner scanner,
    struct PathToken * tokens,
    const size_t tokensLimit) {

    struct SpanOfPathTokens span = {tokens, 0, tokensLimit};

    ///

    struct PathTokenizer tokenizer = {scanner, span};

    ///

    return tokenizer;
}

///

// bool isPathTokenizerAtEof(
//     struct PathTokenizer * tokenizer) {

//     const struct SourceLocation tokenizerLocation = 
// }

///

// struct SourceLocation pathTokenizerLocation(
//     struct PathTokenizer * tokenizer) {

//     if (tokenizer.pos) {

//     }
// }

///

const struct PathToken unsafeNextPathToken(
    struct PathTokenizer * tokenizer) {

    const char nextChar = unsafeScannerPeek(&tokenizer->scanner);

    ///

    if (nextChar == '/') {

        return unsafeTokenizePathPuncSlash(tokenizer);
    }
    else if (isPathComponentPart(nextChar)) {

        return unsafeTokenizePathComponent(tokenizer);
    }
    else {

        return unsafeTokenizeUnexpectedPathToken(tokenizer);
    }
}

///

const struct PathToken unsafeTokenizePathComponent(
    struct PathTokenizer * tokenizer) {

    const struct SourceLocation start = scannerLocation(&tokenizer->scanner);

    ///

    const bool (*isComponentPart) (const char) = &isPathComponentPart;

    char componentBuffer[tokenizer->scanner.source.limit];

    const size_t read = scannerNextWhile(&tokenizer->scanner, componentBuffer, isComponentPart);

    ///

    const struct String source = {&tokenizer->scanner.source.source[start.position], read};

    ///

    const struct PathToken token = initPathTokenFromComponent(source, start, scannerLocation(&tokenizer->scanner));

    return token;
}

///

const struct PathToken unsafeTokenizePathPunc(
    struct PathTokenizer * tokenizer,
    const char c,
    const enum PathPuncType puncType) {

    const struct SourceLocation start = scannerLocation(&tokenizer->scanner);

    ///

    const struct OptionalChar n = scannerNext(&tokenizer->scanner);

    if (n.option == none) {

        printf("warn: unexpected nil char");
    }

    if (n.value != c) {

        printf("warn: unexpected char '%c'", n.value);
    }

    ///

    const struct String source = {&tokenizer->scanner.source.source[start.position], 1};

    ///

    const struct PathPunc punc = {puncType};

    ///

    const struct PathToken token = initPathTokenFromPunc(source, punc, start, scannerLocation(&tokenizer->scanner));

    return token;
}

const struct PathToken unsafeTokenizePathPuncSlash(
    struct PathTokenizer * tokenizer) {

    return unsafeTokenizePathPunc(tokenizer, '/', pathPuncTypeSlash);
}

///

const struct PathToken unsafeTokenizeUnexpectedPathToken(
    struct PathTokenizer * tokenizer) {

    const struct SourceLocation start = scannerLocation(&tokenizer->scanner);

    ///

    const struct OptionalChar n = scannerNext(&tokenizer->scanner);

    if (n.option == none) {

        printf("warn: unexpected nil char");
    }

    ///

    const struct String source = {&tokenizer->scanner.source.source[start.position], 1};

    ///

    const struct PathToken token = initUnexpectedPathToken(source, start, scannerLocation(&tokenizer->scanner));

    return token;
}