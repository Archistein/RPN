#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inc/token.h"

/*
TODO: implement isInt and isDouble
*/

int isNum(char *str) {
    int tempvar;
    return sscanf(str, "%d", &tempvar) == 1;
}

char* tokenize(FILE* stream, TOKEN* buffer, size_t buff_cap) {

    unsigned int pos = 0; // Current position in the buffer

    char *str = (char*) malloc(buff_cap*sizeof(char));   
    size_t temp_sz = getline(&str, &buff_cap, stream);
    str[temp_sz-1] = ' '; // Delete newline character from str
    char *toks = strtok(str, " ");

    while (toks != NULL) {

        if (pos >= buff_cap) {
            puts("Error: buffer overflow");
            exit(-1);
        }

        if (isNum(toks)) 
            buffer[pos++] = (TOKEN) {TNUMBER, toks};
        else if (!strcmp(toks, "+"))
            buffer[pos++] = (TOKEN) {TPLUS, NULL};
        else if (!strcmp(toks, "-"))
            buffer[pos++] = (TOKEN) {TMINUS, NULL};
        else if (!strcmp(toks, "*"))
            buffer[pos++] = (TOKEN) {TMUL, NULL};
        else if (!strcmp(toks, "/"))
            buffer[pos++] = (TOKEN) {TDIV, NULL};
        else if (!strcmp(toks, "dump"))
            buffer[pos++] = (TOKEN) {TDUMP, NULL};
        else {
            printf("Error: unexpected token (%s)\n", toks);
            return NULL;
        }
        toks = strtok(NULL, " ");

    }

    return pos > 0 ? str : NULL;

}
