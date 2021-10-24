#ifndef PATH_PUNC_H
#define PATH_PUNC_H

enum PathPuncType {

    pathPuncTypeSlash
};

struct PathPunc {

    const enum PathPuncType puncType;
};

#endif