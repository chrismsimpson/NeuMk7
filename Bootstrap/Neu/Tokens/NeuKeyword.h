#ifndef NEU_KEYWORD_H
#define NEU_KEYWORD_H

enum NeuKeywordType {

    neuKeywordTypeFunc
};

struct NeuKeyword {

    const enum NeuKeywordType keywordType;
};

#endif