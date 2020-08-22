.PHONY: clean all rebuild

PARSER_FILES	:= $(addprefix src/parser/, lex.yy.c parser.tab.c parser.tab.h)
C_FILES 		:= $(shell find src -name *.c) $(filter %.c, $(PARSER_FILES))
CPP_FILES 		:= $(shell find src -name *.cpp)
OBJ_FILES 		:= $(patsubst src/%.c, obj/%.o, $(C_FILES)) $(patsubst src/%.cpp, obj/%.o, $(CPP_FILES))
C_FLAGS   		:= -Ofast -march=native -funroll-loops
CPP_FLAGS 		:= $(shell llvm-config --cxxflags --ldflags --system-libs --libs all)

all: sprout

clean:
	rm -f $(PARSER_FILES) sprout
	rm -rf ./obj

rebuild: clean sprout

src/parser/lex.yy.c: src/parser/lexer.l src/parser/parser.tab.h
	flex -o $@ $^

src/parser/parser.tab.h src/parser/parser.tab.c: src/parser/parser.y
	bison -d -o $@ $^

obj/%.o: src/%.c
	mkdir -p $(@D)
	gcc -c -o $@ $^ $(C_FLAGS)

obj/%.o: src/%.cpp
	mkdir -p $(@D)
	g++ -c -o $@ $^ $(CPP_FLAGS)

sprout: $(OBJ_FILES)
	g++ -o $@ $^ $(CPP_FLAGS)
