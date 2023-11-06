//
// Created by Andrey Kryukov on 28.10.2023.
//

#ifndef LAB1_SYMBOLIC_TABLE_H
#define LAB1_SYMBOLIC_TABLE_H

#include "preprocess_ast.h"

typedef struct symbolicTable symbolicTable;
typedef struct symbol symbol;


union ctx {
    preparedFunc func;
};
enum symbolCategory {
    SYMBOL_CATEGORY_FUNC,
    SYMBOL_CATEGORY_VAR
};
struct symbol {
    char *identifier;
    preparedType type;
    enum symbolCategory category;
    int offset;
    union ctx ctx;
};
struct symbolicTable {
    symbolicTable *parent;
    symbol *symbols;
    int symbolsCount;
    char *currentFuncId;
};
char *symbolicTable_currentFuncId(symbolicTable *table);
int symbolicTable_putSymbol(symbolicTable *table, preparedType type, char *identifier, union ctx ctx,
                            enum symbolCategory category);

symbol *symbolicTable_findSymbol(symbolicTable *table, char *identifier);

void symbolicTable_free(symbolicTable *table);

symbolicTable *newSymbolicTable(symbolicTable *parent, int capacity);

#endif //LAB1_SYMBOLIC_TABLE_H
