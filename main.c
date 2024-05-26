#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASSERT(expr) assert(expr)

struct Program {
    char *content;
    size_t content_size;
};

void titan_load_program(FILE *file, struct Program *p);

void titan_load_program(FILE *file, struct Program *p)
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
        char *new_content = realloc(p->content, p->content_size + len + 1);
        if (new_content == NULL) {
            fprintf(stderr, "ERROR: faild to allocate memory");
            free(p->content);
            fclose(file);
            return;
        }
        p->content = new_content;

        // Append p->content to line
        strcpy(p->content + p->content_size, line);
        // Update p->content_size
        p->content_size += len;
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

struct Program program = { 0 };

int main(int argc, char** argv)
{
    char *program_name = shift_args(&argc, &argv);

    if (argc <= 0) {
        usage(stderr, program_name);
        fprintf(stderr, "ERROR: Not enough arguments were provided\n");
        return -1;
    }

    char *fp = shift_args(&argc, &argv);

    FILE *file = fopen(fp, "r");
    if (file == NULL) {
        fprintf(stderr, "ERROR: Could not open file %s\n", fp);
        return -1;
    }

    titan_load_program(file, &program);

    printf("%s\n", program.content);

    fclose(file);
    free(program.content);
    return 0;
}

