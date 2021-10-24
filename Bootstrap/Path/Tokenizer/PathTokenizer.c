#include "PathTokenizer.h"

struct PathTokenizer initPathTokenizer(
    const char * source, 
    const size_t length,
    const size_t bufferSize) {

    return initPathTokenizerWithScanner(initScanner(source, length, bufferSize));
}

struct PathTokenizer initPathTokenizerWithScanner(
    struct Scanner scanner) {

    struct PathTokenizer tokenizer = {scanner};

    ///

    return tokenizer;
}

///

const struct PathToken unsafeNextPathToken(
    struct PathTokenizer * tokenizer) {

    const char nextChar = unsafePeek(&tokenizer->scanner);

    ///

    if (nextChar == '/') {

        return unsafeTokenizePathPuncSlash(tokenizer);
    }
    // else if (isPathComponentPart(nextChar)) {

    //     return unsafeTokenizePathComponent(tokenizer);
    // }
    else {

        return unsafeTokenizeUnexpectedPathToken(tokenizer);
    }
}

const struct PathToken unsafeTokenizePathPunc(
    struct PathTokenizer * tokenizer,
    const char c,
    const enum PathPuncType puncType) {

    const struct SourceLocation start = location(&tokenizer->scanner);

    ///

    const struct OptionalChar n = next(&tokenizer->scanner);

    if (n.option == none) {

        printf("warn: unexpected nil char");
    }

    if (n.value != c) {

        printf("warn: unexpected char '%c'", n.value);
    }

    ///

    const struct PathPunc punc = {puncType};

    ///

    const struct PathToken token = initPathTokenFromPunc(&n.value, punc, start, location(&tokenizer->scanner));

    return token;
}

const struct PathToken unsafeTokenizePathPuncSlash(
    struct PathTokenizer * tokenizer) {

    return unsafeTokenizePathPunc(tokenizer, '/', pathPuncTypeSlash);
}

// void unsafeTokenizePathComponent(
//     struct PathTokenizer * tokenizer) {

    
// }

const struct PathToken unsafeTokenizeUnexpectedPathToken(
    struct PathTokenizer * tokenizer) {

    const struct SourceLocation start = location(&tokenizer->scanner);

    ///

    const struct OptionalChar n = next(&tokenizer->scanner);

    if (n.option == none) {

        printf("warn: unexpected nil char");
    }

    ///

    const struct PathToken token = initUnexpectedPathToken(&n.value, start, location(&tokenizer->scanner));

    return token;

}