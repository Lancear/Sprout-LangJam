
#include <stdio.h>
#include <assert.h>
#include "error.h"

void lexer_error(const int line) {
    fprintf(stderr, "[%d] LEXER ERROR\n", line);
}

void parser_error(const char * message, const unsigned int line, const unsigned int col) {
    fprintf(stderr, "[%d:%d] PARSER ERROR: %s\n", line, col, message);
}
