#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "lexer.h"

#define ASSERT(expr) assert(expr)

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

struct Content content = { 0 };

int main(int argc, char** argv)
{
    char *program_name = shift_args(&argc, &argv);

    if (argc <= 0) {
        usage(stderr, program_name);
        fprintf(stderr, "ERROR: invalid usage\n");
        return -1;
    }

    char *fp = shift_args(&argc, &argv);

    FILE *file = fopen(fp, "r");
    if (file == NULL) {
        fprintf(stderr, "ERROR: Could not open file %s\n", fp);
        return -1;
    }

    load_content_from_file(file, &content);

    printf("%s\n", content.data);

    fclose(file);
    free(content.data);
    return 0;
}

