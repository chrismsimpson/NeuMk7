#ifndef NEU_TOKENIZER_H
#define NEU_TOKENIZER_H

#include "../../Scanner.h"
#include "../../SourceLocation.h"

struct NeuTokenizer {

    struct Scanner scanner;
};

///

extern struct NeuTokenizer initNeuTokenizer(
    const char * source,
    const size_t sourceLength,
    const size_t sourceLimit);

extern struct NeuTokenizer initNeuTokenizerWithScanner(
    struct Scanner scanner);

///

extern void unsafeNeuTokenizerKeyword(
    struct NeuTokenizer * tokenizer);

#endif