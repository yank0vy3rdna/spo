//
// Created by Andrey Kryukov on 01.11.2023.
//

#ifndef LAB1_ASM_GENERATOR_H
#define LAB1_ASM_GENERATOR_H

#include "preprocess_ast.h"

int labelCounter;
FILE *asmCodeOut;
FILE *asmDataOut;

int generate_asm(preparedFunc *funcs, int count);

#endif //LAB1_ASM_GENERATOR_H
