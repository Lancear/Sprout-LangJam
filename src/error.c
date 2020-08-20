
#include <stdio.h>
#include <assert.h>
#include "error.h"

void lexer_error(const int type) {
    fprintf(stderr, "TODO: Make me.\n");
    assert(0);
}

void parser_error(const char * message, const unsigned int line, const unsigned int col) {
    fprintf(stderr, "[%d:%d] %s\n", line, col, message);
}
