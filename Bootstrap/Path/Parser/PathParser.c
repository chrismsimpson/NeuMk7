#include "PathParser.h"

struct PathParser initPathParser(
    const char * source,
    const size_t sourceLength,
    const size_t sourceLimit,
    struct PathToken * tokens,
    const size_t tokensLimit) {

    return initPathParserWithTokenizer(initPathTokenizer(source, sourceLength, sourceLimit, tokens, tokensLimit));
}

struct PathParser initPathParserWithTokenizer(
    struct PathTokenizer tokenizer) {

    struct PathParser parser = {tokenizer};

    return parser;
}

///

const struct Path pathParserPath(
    struct PathParser * parser,
    struct PathToken * tokens,
    const size_t tokensLimit) {

    const struct SpanOfPathTokens span = pathParserTokens(parser, tokens, tokensLimit);

    ///

    const struct Path p = {span};

    return p;
}

///

const struct SpanOfPathTokens pathParserTokens(
    struct PathParser * parser,
    struct PathToken * tokens,
    const size_t tokensLimit) {

    size_t i = 0;

    ///

    while (!pathTokenizerIsAtEof(&parser->tokenizer)) {

        const struct OptionalPathToken token = pathTokenizerNext(&parser->tokenizer);

        if (token.option == none) {

            printf("warn: nil path token");

            break;
        }

        ///

        memcpy(&tokens[i], &token.value, sizeof(token));

        ///

        i++;

        ///

        if (i >= tokensLimit) {

            printf("warn: path token limit reached");

            break;
        }
    }

    ///

    const struct SpanOfPathTokens span = {tokens, i, tokensLimit};

    return span;
}