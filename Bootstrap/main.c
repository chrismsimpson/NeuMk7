
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#include "Scanner.h"
#include "Common.h"

void printFile();

///

int main() {

    printf("\n");

    ///

    printFile();

    ///

    return 0;
}

void printFile() {

    printf("//\n// File stuffs\n//\n\n");

    ///

    // struct stat fileStat;

    // if (stat(filename, &fileStat) == -1) {

    //     printf("warn: stat != -1\n");
    // }

    // size_t length = fileStat.st_size;

    // ///

    // size_t bufferLength = length + 1;

    // char buffer[bufferLength];

    // ///

    // FILE * file = fopen(filename, "r");

    // if (fread(&buffer, sizeof(char), length, file) != length) {

    //     printf("warn: fread != length\n");
    // }

    // ///

    // buffer[length] = '\0';

    // ///

    // struct Scanner scanner = initScanner(buffer, length, length);
}