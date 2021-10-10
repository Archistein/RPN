#include <stdio.h>
#include <stdlib.h>

#include "../inc/token.h"

#define CAPACITY 255

void dump(int* stack, int pos) {
    if (pos > 1)
        puts("Dump of stack:");
    for(int i = 0;i < pos;i++) {
        printf("%d ", stack[i]);
    }
    puts("");
}

void push(int* stack, int* pos, int num) {
    if (*pos < CAPACITY)
        stack[(*pos)++] = num;
    else {
        puts("Error: stack overflow");
        exit(-2);
    }
}

void plus(int *stack, int* pos) {
    if (*pos > 1) {
        stack[*pos-2] += stack[*pos-1];
        stack[(*pos)--] = 0;
    } else {
        puts("Error: stack underflow");
        exit(-3);
    }
}

void minus(int *stack, int* pos) {
    if (*pos > 1) {
        stack[*pos-2] -= stack[*pos-1];
        stack[(*pos)--] = 0;
    } else {
        puts("Error: stack underflow");
        exit(-3);
    }
}

void mul(int *stack, int* pos) {
    if (*pos > 1) {
        stack[*pos-2] *= stack[*pos-1];
        stack[(*pos)--] = 0;
    } else {
        puts("Error: stack underflow");
        exit(-3);
    }
}

void divide(int *stack, int* pos) {
    if (*pos > 1) {
        if (stack[*pos-1] == 0) {
            puts("Error: division by zero");
            exit(-4);
        }
        stack[*pos-2] /= stack[*pos-1];
        stack[(*pos)--] = 0;
    } else {
        puts("Error: stack underflow");
        exit(-3);
    }
}


void eval(FILE* stream, TOKEN* buffer, size_t buff_cap) {
    
    int stack[CAPACITY] = {0};
    int pos = 0;

    TOKEN current_token;

    for(int i = 0;i < buff_cap;i++) {
        current_token = buffer[i];

        if (current_token.type == TNUMBER && current_token.value == NULL)
            break;

        if (current_token.type == TNUMBER)
            push(stack, &pos, atoi(current_token.value));
        
        if (current_token.type == TPLUS)
            plus(stack, &pos);

        if (current_token.type == TMINUS)
            minus(stack, &pos);

        if (current_token.type == TMUL)
            mul(stack, &pos);

        if (current_token.type == TDIV)
            divide(stack, &pos);

        if (current_token.type == TDUMP)
            dump(stack, pos);
    }

    dump(stack, pos);

}