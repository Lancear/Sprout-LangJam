
#include <stdio.h>

#include "lexer.h"

int main(int argc, char * argv[]) {
    if(argc != 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return 1;
    }

    process_file(argv[1]);
    
    return 0;
}
