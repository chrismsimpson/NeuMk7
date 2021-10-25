#include "NeuTokenizer.h"

struct NeuTokenizer initNeuTokenizer(
    const char * source, 
    const size_t sourceLength,
    const size_t sourceLimit) {

    return initNeuTokenizerWithScanner(initScanner(source, sourceLength, sourceLimit));
}

struct NeuTokenizer initNeuTokenizerWithScanner(
    struct Scanner scanner) {

    struct NeuTokenizer tokenizer = {scanner};

    return tokenizer;
}

///

void unsafeNeuTokenizerKeyword(
    struct NeuTokenizer * tokenizer) {

    const struct SourceLocation start = scannerLocation(&tokenizer->scanner);

    ///

    
}