
#ifndef ERROR_H
#define ERROR_H

enum {
    LEXER_STRAY_TOKEN
};

void lexer_error(const int line);
void parser_error(const char * message, const unsigned int line, const unsigned int col);

#endif
