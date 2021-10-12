#include <stdio.h>
#include <stdlib.h>

#include "../inc/lexer.h"
#include "../inc/parser.h"
#include "../inc/token.h"

#define CAPACITY 255

TOKEN *buffer;

int main(int argc, char **argv) {

    char *temp_pointer;

    if (argc <= 1) {
        while (1) {
            buffer = calloc(sizeof(TOKEN), CAPACITY);

            printf("RPN# ");

            temp_pointer = tokenize(stdin, buffer, CAPACITY);

            if (temp_pointer != NULL) {
                eval(buffer, CAPACITY);
                free(temp_pointer);
            }

            free(buffer);
        }
    }
    return 0;
    
}