//
// Created by Andrey Kryukov on 28.10.2023.
//

#ifndef LAB1_SYMBOLIC_TABLE_H
#define LAB1_SYMBOLIC_TABLE_H

#include "preprocess_ast.h"

typedef struct asmSymbolicTable asmSymbolicTable;
typedef struct asmSymbol asmSymbol;

enum asmSymbolCategory {
    SYMBOL_CATEGORY_FUNC,
    SYMBOL_CATEGORY_VAR
};
struct asmSymbol {
    char *identifier;
    preparedType type;
    enum asmSymbolCategory category;
    int offset;
    char *label;
};
struct asmSymbolicTable {
    asmSymbolicTable *parent;
    asmSymbol *symbols;
    int symbolsCount;
    char *currentFuncId;
};

char *asmSymbolicTable_currentFuncId(asmSymbolicTable *table);

int asmSymbolicTable_putSymbol(asmSymbolicTable *table, char *identifier, char *label, int sizeOf);

asmSymbol *asmSymbolicTable_findSymbol(asmSymbolicTable *table, char *identifier);

void asmSymbolicTable_free(asmSymbolicTable *table);

asmSymbolicTable *newAsmSymbolicTable(asmSymbolicTable *parent, int capacity);

#endif //LAB1_SYMBOLIC_TABLE_H
