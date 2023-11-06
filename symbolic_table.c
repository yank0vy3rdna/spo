//
// Created by Andrey Kryukov on 28.10.2023.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "symbolic_table.h"

symbolicTable *newSymbolicTable(symbolicTable *parent, int capacity) {
    symbolicTable *table = malloc(sizeof(symbolicTable));
    table->parent = parent;
    table->symbolsCount = 0;
    table->symbols = malloc(sizeof(symbol) * capacity);
    return table;
}

void symbolicTable_free(symbolicTable *table) {
    free(table->symbols);
    free(table);
}

symbol *symbolicTable_findSymbol(symbolicTable *table, char *identifier) {
    if (table == NULL) {
        return NULL;
    }
    for (int i = 0; i < table->symbolsCount; ++i) {
        if (strcmp(table->symbols[i].identifier, identifier) == 0) {
            return &table->symbols[i];
        }
    }

    return symbolicTable_findSymbol(table->parent, identifier);
}

//int findPreviousOffset(symbolicTable *table) {
//    if (table == NULL) {
//        return 0;
//    }
//    if (table->symbolsCount == 0) {
//        return findPreviousOffset(table->parent);
//    }
//    return table->symbols[table->symbolsCount - 1].offset;
//}

//int sizeOfSymbol(preparedType type) {
//    if (type.type == FUNC) {
//        return 0;
//    }
//    return 2;
//}

char *symbolicTable_currentFuncId(symbolicTable *table) {
    if (table == NULL) {
        return NULL;
    }
    if (table->currentFuncId == NULL) {
        return symbolicTable_currentFuncId(table->parent);
    }
    return table->currentFuncId;
}

int symbolicTable_putSymbol(symbolicTable *table, preparedType type, char *identifier, union ctx ctx,
                            enum symbolCategory category) {
    symbol *s = symbolicTable_findSymbol(table, identifier);
    if (s != NULL) {
        fprintf(stderr, "symbol %s already exists", identifier);
        return 1;
    }

    table->symbols[table->symbolsCount].type = type;
    table->symbols[table->symbolsCount].identifier = identifier;
    table->symbols[table->symbolsCount].ctx = ctx;
    table->symbols[table->symbolsCount].category = category;
//    table->symbols[table->symbolsCount].offset = findPreviousOffset(table) + sizeOfSymbol(type);

    table->symbolsCount++;
    return 0;
}