
#include "codegen_stub.h"
#include <stdio.h>

#define INDENT for(i=0;i<indent;i++)putchar(' ')

void dispatch(struct node * n) {
    static int indent = 0;
    int i;
    
    if(!n)
        return;
    
    INDENT; printf("type: %d\n", n->type);
    if(n->value != NULL) { INDENT; printf("value: %s\n", n->value); }
    if(n->child)   { INDENT; indent += 1; printf("child:\n"); dispatch(n->child); indent -= 1; }
    if(n->brother) { INDENT; indent += 1; printf("brother:\n"); dispatch(n->brother); indent -= 1; }
}
