all: main parser lexer build run

main: src/main.c
	gcc -c src/main.c -o obj/main.o

parser: src/parser.c
	gcc -c src/parser.c -o obj/parser.o

lexer: src/lexer.c
	gcc -c src/lexer.c -o obj/lexer.o

build: obj/main.o obj/lexer.o obj/parser.o
	gcc obj/main.o obj/lexer.o obj/parser.o -o build/rpn.out

run:
	./build/rpn.out