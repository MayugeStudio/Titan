#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define ASSERT(expr) assert(expr)

#define INITIAL_LINES 10

enum TokenType {
    SEMI,
    OPEN_PAREN,
    CLOSE_PAREN,
};

enum Keyword {
    KEY_WORD_PROC,
};

enum Literal {
    LITERAL_TEXT,
};

struct Program {
    char *content;
};
void lexer(FILE *file);

void lexer(FILE *file, struct Program *content)
{
    size_t allocated = INITIAL_LINES;

    Program->content = malloc(allocated * sizeof(char*));
    if (Program->content == NULL)
    {
        
    }

    char current = fgetc(file);
    while (current != EOF)
    {
        printf("%c", current);
        current = fgetc(file);
    }
}

static void usage(FILE *stream, char *filename)
{
    fprintf(stream, "Usage: %s <fp.titan>\n", filename);
}

static char* shift_args(int *argc, char ***argv)
{
    ASSERT(*argc > 0);
    char* result = **argv;
    *argc -= 1;
    *argv += 1;
    return result;
}

int main(int argc, char** argv)
{
    char *program_name = shift_args(&argc, &argv);

    if (argc <= 0)
    {
        usage(stderr, program_name);
        fprintf(stderr, "not enough arguments");
        return -1;
    }

    char *fp = shift_args(&argc, &argv);

    FILE *file = fopen(fp, "r");
    lexer(file);
    fclose(file);
    return 0;
}

