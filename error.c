//
// Created by Andrey Kryukov on 15.09.2023.
//
#include "error.h"
#include <stdio.h>

void yyerror(const char* s){
    fprintf(stderr, "Ошибка: %s\n", s);
}