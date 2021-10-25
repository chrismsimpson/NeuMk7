
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include "Common.h"
#include "Scanner.h"

#include "Neu/Tokenizer/NeuTokenizer.h"

void printFile();

///

int main() {

    printf("\n");

    ///

    printFile("Tests/test00.neu");

    ///

    return 0;
}

void printFile(
    const char * filename) {

    printf("//\n// File stuffs\n//\n\n");

    ///

    struct stat fileStat;

    if (stat(filename, &fileStat) == -1) {

        printf("warn: stat != -1\n");
    }

    size_t length = fileStat.st_size;

    ///

    size_t bufferLength = length + 1;

    char buffer[bufferLength];

    ///

    FILE * file = fopen(filename, "r");

    if (fread(&buffer, sizeof(char), length, file) != length) {

        printf("warn: fread != length\n");
    }

    ///

    buffer[length] = '\0';

    ///

    struct NeuTokenizer tokenizer = initNeuTokenizer(buffer, length, length);

    ///

    printf("source: %s\n", tokenizer.scanner.source.source);
}