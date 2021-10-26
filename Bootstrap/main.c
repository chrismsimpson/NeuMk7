
#include <inttypes.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

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

    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

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

    ///

    bool match = scannerMatch(&tokenizer.scanner, 'c', 3);

    printf("match: %s\n", match ? "true" : "false");

    ///

    // char buf2[32];

    // scannerNextLength(&tokenizer.scanner, buf2, 4);

    // printf("buffer: %s\n", buf2);

    ///

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    uint64_t d = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;

    printf("time taken: %" PRIu64 "ms\n", d);
}