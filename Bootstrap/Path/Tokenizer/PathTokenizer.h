#ifndef PATH_TOKENIZER_H
#define PATH_TOKENIZER_H

#include "../../Scanner.h"

struct PathTokenizer {

    struct Scanner scanner;
};

///

extern struct PathTokenizer initPathTokenizer(
    const char * source, 
    const size_t length,
    const size_t bufferSize);

extern struct PathTokenizer initPathTokenizerWithScanner(
    struct Scanner scanner);

#endif