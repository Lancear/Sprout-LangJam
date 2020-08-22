.PHONY: clean all rebuild

PARSERFILES := $(addprefix src/parser/, lex.yy.c parser.tab.c parser.tab.h)
CFILES := $(shell find src -name *.c) $(filter %.c, $(PARSERFILES))
CPPFILES := $(shell find src -name *.cpp)
OBJFILES := $(patsubst src/%.c, obj/%.o, $(CFILES)) $(patsubst src/%.cpp, obj/%.o, $(CPPFILES))

CFLAGS=-Ofast -march=native -funroll-loops

all: sprout

clean:
	rm -f $(PARSERFILES) sprout
	rm -rf ./obj

rebuild: clean sprout

src/parser/lex.yy.c: src/parser/lexer.l src/parser/parser.tab.h
	flex -o $@ $^

src/parser/parser.tab.h src/parser/parser.tab.c: src/parser/parser.y
	bison -d -o $@ $^

obj/%.o: src/%.c
	mkdir -p $(@D)
	gcc $(CFLAGS) -c -o $@ $^

obj/%.o: src/%.cpp
	mkdir -p $(@D)
	g++ $(CPPFLAGS) -c -o $@ $^

sprout: $(OBJFILES)
	g++ $(CPPFLAGS) -o $@ $^
