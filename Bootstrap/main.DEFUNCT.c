
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#include "Scanner.h"
#include "Common.h"

#include "Path/Parser/PathParser.h"
#include "Path/Tokenizer/PathTokenizer.h"
#include "Path/Tokens/PathComponent.h"
#include "Path/Tokens/PathToken.h"

void printDir();

void printFile(
    const char * filename);

void printNext(
    struct Scanner * scanner);

void printTokenizer();

void printTokenizerNext();

void printParser();

///

int main() {

    printf("\n");

    ///

    printParser();

    // printTokenizerNext();

    // printDir();

    ///

    // printTokenizer();

    ///

    // printFile("Tests/test01.neu");

    ///

    return 0;
}

void printParser() {

    printf("//\n// Parser stuffs\n//\n\n");

    ///

    char pathBuffer[PATH_MAX];

    getcwd(pathBuffer, sizeof(pathBuffer));

    const size_t pathLength = strlen(pathBuffer);

    ///

    struct PathToken tokens[PATH_MAX];

    ///

    struct PathParser parser = initPathParser(pathBuffer, pathLength, PATH_MAX, tokens, PATH_MAX);

    printf("source: %s\n", parser.tokenizer.scanner.source.source);

    ///

    struct PathToken parsedTokens[PATH_MAX];

    const struct Path path = pathParserPath(&parser, parsedTokens, PATH_MAX);
    
    printf("# of tokens: %ld\n", path.span.length);

    ///

    for (size_t i = 0; i < path.span.length; i++) {

        const struct PathToken t = path.span.tokens[i];

        char tBuffer[t.source.length + 1];

        strncpy(tBuffer, (const char *) t.source.source, t.source.length);

        tBuffer[t.source.length] = '\0';

        printf("token: %s\n", tBuffer);
    }
}

void printTokenizerNext() {

    printf("//\n// Tokenizer stuffs\n//\n\n");

    ///

    char pathBuffer[PATH_MAX];

    getcwd(pathBuffer, sizeof(pathBuffer));

    const size_t length = strlen(pathBuffer);

    ///

    struct PathToken tokens[PATH_MAX];

    ///

    struct PathTokenizer tokenizer = initPathTokenizer(pathBuffer, length, PATH_MAX, tokens, PATH_MAX);

    ///

    struct OptionalPathToken t1 = pathTokenizerNext(&tokenizer);

    if (t1.option == none) {

        printf("token is nil\n");
    }
    else {

        char t1Buffer[t1.value.source.length + 1];

        strncpy(t1Buffer, (const char *) t1.value.source.source, t1.value.source.length);

        t1Buffer[t1.value.source.length] = '\0';

        printf("token: %s\n", t1Buffer);
    }

    ///

    struct OptionalPathToken t2 = pathTokenizerNext(&tokenizer);

    if (t2.option == none) {

        printf("token is nil\n");
    }
    else {

        char t2Buffer[t2.value.source.length + 1];

        strncpy(t2Buffer, (const char *) t2.value.source.source, t2.value.source.length);

        t2Buffer[t2.value.source.length] = '\0';

        printf("token: %s\n", t2Buffer);
    }
}

void printTokenizer() {

    printf("//\n// Tokenizer stuffs\n//\n\n");

    ///

    char pathBuffer[PATH_MAX];

    getcwd(pathBuffer, sizeof(pathBuffer));

    const size_t length = strlen(pathBuffer);

    ///

    struct PathToken tokens[PATH_MAX];

    ///

    struct PathTokenizer tokenizer = initPathTokenizer(pathBuffer, length, PATH_MAX, tokens, PATH_MAX);

    ///

    const struct PathToken slash = unsafePathTokenizerNext(&tokenizer);

        ///

        char slashBuffer[slash.source.length + 1];

        strncpy(slashBuffer, (const char *) slash.source.source, slash.source.length);

        slashBuffer[slash.source.length] = '\0';

        printf("slash: %s\n", slashBuffer);

    ///

    const struct PathToken users = unsafePathTokenizerComponent(&tokenizer);

        ///

        char usersBuffer[users.source.length + 1];

        strncpy(usersBuffer, (const char *) users.source.source, users.source.length);

        usersBuffer[users.source.length] = '\0';

        printf("users: %s\n", usersBuffer);


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

    char componentBuffer[scanner.source.limit];

    const size_t read = scannerNextWhile(&scanner, componentBuffer, isComponentPart);

    printf("componentBuffer: %s\n\n", componentBuffer);
}

void printNext(
    struct Scanner * scanner) {

    const struct OptionalChar n = scannerNext(scanner);

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
