#pragma once

typedef enum {
    TNUMBER,
    TPLUS,
    TMINUS,
    TDIV,
    TMUL,
} TOKEN_TYPE;

typedef struct {
    TOKEN_TYPE type;
    char* value;
} TOKEN;