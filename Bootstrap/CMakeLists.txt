project (main)

add_executable(main
    Neu/Tokenizer/NeuTokenizer.c
    Neu/Tokens/NeuToken.c
    Neu/Tokens/NeuKeyword.c
    Path/Parser/PathParser.c
    Path/Tokenizer/PathTokenizer.c
    Path/Tokens/PathComponent.c
    Path/Tokens/PathPunc.c
    Path/Tokens/PathToken.c
    Common.c
    main.c
    Scanner.c
    )