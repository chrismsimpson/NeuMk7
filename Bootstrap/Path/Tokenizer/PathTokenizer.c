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
