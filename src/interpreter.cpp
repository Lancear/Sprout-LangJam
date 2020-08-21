#include "interpreter.hpp"
#include <stdio.h>

#define INDENT for(i=0;i<indent;i++)putchar(' ')

void dispatch(struct node * n) {
    static int indent = 0;
    int i;
    
    if(!n)
        return;
    
    INDENT; printf("cpp type: %d\n", n->type);
    INDENT; printf("cpp value: %s\n", n->value);
    if(!n->child) { INDENT; printf("child: (null)\n"); }
    else { INDENT; indent += 1; printf("child:\n"); dispatch(n->child); indent -= 1; }
    if(!n->brother) { INDENT; printf("brother: (null)\n"); }
    else { INDENT; indent += 1; printf("brother:\n"); dispatch(n->brother); indent -= 1; }
}