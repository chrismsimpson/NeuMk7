project (main)

add_executable(main
    Path/Parser/PathParser.h
    Path/Tokenizer/PathTokenizer.c
    Path/Tokens/PathComponent.c
    Path/Tokens/PathPunc.c
    Path/Tokens/PathToken.c
    Common.c
    main.c
    Scanner.c
    )