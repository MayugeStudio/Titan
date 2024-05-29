#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Content {
    char  *data;
    size_t size;
};

struct Text {
    const char *data;
    const size_t size;
};

enum TokenType {
    KEYWORD,
    LITERAL,
};

enum Keyword {
    PROC,
};

enum Separator {
    SEMICOLON,
    OPEN_PAREN,
    CLOSE_PAREN,
    OPEN_CURLY,
    CLOSE_CURLY,
};

enum Literal {
    TEXT = 0,
};

struct Token {
    enum TokenType type;
};

struct Lexer {
    struct Content *source;
    struct Token *tokens;
    size_t tokens_size;
};

void load_content_from_file(FILE *file, struct Content *c);
void lexer_next(struct Lexer *lexer, struct Token *out);

#endif // LEXER_H
 
