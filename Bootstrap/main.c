
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#include "Scanner.h"
#include "Common.h"

#include "Path/Tokens/PathComponent.h"
#include "Path/Tokenizer/PathTokenizer.h"

void printDir();

void printFile(
    const char * filename);

void printNext(
    struct Scanner * scanner);

void printTokenizer();

///

int main() {

    printf("\n");

    ///

    printDir();

    ///

    printTokenizer();

    ///

    printFile("Tests/test01.neu");

    ///

    return 0;
}

void printTokenizer() {

    printf("//\n// Tokenizer stuffs\n//\n\n");

    ///

    char pathBuffer[PATH_MAX];

    getcwd(pathBuffer, sizeof(pathBuffer));

    const size_t length = strlen(pathBuffer);

    ///

    struct PathTokenizer tokenizer = initPathTokenizer(pathBuffer, length, PATH_MAX);

    ///

    printf("%s\n", tokenizer.scanner.source.source);

    

    ///

    printf("\n");
}

void printDir() {

    printf("//\n// Pathy stuffs\n//\n\n");

    ///

    char pathBuffer[PATH_MAX];

    getcwd(pathBuffer, sizeof(pathBuffer));

    const size_t length = strlen(pathBuffer);

    ///

    struct Scanner scanner = initScanner(pathBuffer, length, PATH_MAX);

    ///

    printf("%s\n", scanner.source.source);

    ///

    printNext(&scanner);

    ///

    const bool (*isComponentPart) (const char) = &isPathComponentPart;

    char componentBuffer[scanner.bufferSize];

    nextWhile(&scanner, isComponentPart, componentBuffer);

    printf("componentBuffer: %s\n\n", componentBuffer);
}

void printNext(
    struct Scanner * scanner) {

    const struct OptionalChar n = next(scanner);

    if (n.option == none) {

        printf("n is nil"); 
    }
    else {

        printf("n: %c\n", n.value);
    }
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

    struct Scanner scanner = initScanner(buffer, length, 65536);

    ///

    printf("%s\n", scanner.source.source);
}
