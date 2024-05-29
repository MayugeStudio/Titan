#include "lexer.h"

#include <string.h>

void load_content_from_file(FILE *file, struct Content *c)
{
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        size_t len = strlen(line);
        
        // Remove newline character
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }
        
        // Reallocate memory for content
        char *new_data = realloc(c->data, c->size + len + 1);
        if (new_data == NULL) {
            fprintf(stderr, "ERROR: faild to allocate memory");
            free(c->data);
            fclose(file);
            return;
        }
        c->data = new_data;

        // Append t->content to line
        strcpy(c->data + c->size, line);
        // Update t->content_size
        c->size += len;
    }
}

void lexer_next(struct Lexer *lexer, struct Token *out)
{
    lexer->source
}

