#include <stdio.h>
#include <stdlib.h>

#include "../inc/lexer.h"
#include "../inc/parser.h"
#include "../inc/token.h"

#define CAPACITY 255

static TOKEN buffer[CAPACITY];

int main(int argc, char **argv) {

    if (argc <= 1) {
        while (1) {
            printf("RPN# ");
            tokenize(stdin, buffer, CAPACITY);
        }
    }
    return 0;
    
}