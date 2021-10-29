all: main parser lexer build run

main: src/main.c
	gcc -c src/main.c -o buld/obj/main.o

parser: src/parser.c
	gcc -c src/parser.c -o buld/obj/parser.o

lexer: src/lexer.c
	gcc -c src/lexer.c -o buld/obj/lexer.o

build: buld/obj/*.o
	gcc buld/obj/*.o -o build/rpn

run:
	./build/rpn