//
// Created by Andrey Kryukov on 09.09.2023.
//

#ifndef LAB1_MAIN_H
#define LAB1_MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include "parser.tab.h"

extern int yyparse();
extern FILE* yyin;

#endif //LAB1_MAIN_H
