
# TODO: simplify rules for .c=>.o.

.PHONY: clean all

all: sprout

clean:
	rm -f lex.yy.c parser.tab.c parser.tab.h *.o sprout

lex.yy.c: lexer.l
	flex lexer.l

lex.yy.o: lex.yy.c
	gcc $(CFLAGS) -c -o $@ $^

parser.tab.c: parser.y
	bison -d parser.y

parser.tab.o: parser.tab.c
	gcc $(CFLAGS) -c -o $@ $^

error.o: error.c
	gcc $(CFLAGS) -c -o $@ $^

node.o: node.c
	gcc $(CFLAGS) -c -o $@ $^

main.o: main.c
	gcc $(CFLAGS) -c -o $@ $^

codegen_stub.o: codegen_stub.c
	gcc $(CFLAGS) -c -o $@ $^

sprout: parser.tab.o lex.yy.o error.o node.o main.o codegen_stub.o
	gcc $(CFLAGS) -o $@ $^
