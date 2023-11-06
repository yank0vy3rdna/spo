//
// Created by Andrey Kryukov on 28.10.2023.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "symbolic_table_asm.h"

asmSymbolicTable *newAsmSymbolicTable(asmSymbolicTable *parent, int capacity) {
    asmSymbolicTable *table = malloc(sizeof(asmSymbolicTable));
    table->parent = parent;
    table->symbolsCount = 0;
    table->symbols = malloc(sizeof(asmSymbol) * capacity);
    return table;
}

void asmSymbolicTable_free(asmSymbolicTable *table) {
    free(table->symbols);
    free(table);
}

asmSymbol *asmSymbolicTable_findSymbol(asmSymbolicTable *table, char *identifier) {
    if (table == NULL) {
        return NULL;
    }
    for (int i = 0; i < table->symbolsCount; ++i) {
        if (strcmp(table->symbols[i].identifier, identifier) == 0) {
            return &table->symbols[i];
        }
    }

    return asmSymbolicTable_findSymbol(table->parent, identifier);
}

int findPreviousOffset(asmSymbolicTable *table) {
    if (table == NULL) {
        return 0;
    }
    if (table->symbolsCount == 0) {
        return findPreviousOffset(table->parent);
    }
    return table->symbols[table->symbolsCount - 1].offset;
}


char *asmSymbolicTable_currentFuncId(asmSymbolicTable *table) {
    if (table == NULL) {
        return NULL;
    }
    if (table->currentFuncId == NULL) {
        return asmSymbolicTable_currentFuncId(table->parent);
    }
    return table->currentFuncId;
}

int asmSymbolicTable_putSymbol(asmSymbolicTable *table, char *identifier, char *label, int sizeOf) {
    asmSymbol *s = asmSymbolicTable_findSymbol(table, identifier);
    if (s != NULL) {
        fprintf(stderr, "symbol %s already exists", identifier);
        return 1;
    }

    table->symbols[table->symbolsCount].identifier = identifier;
    table->symbols[table->symbolsCount].label=label;
    table->symbols[table->symbolsCount].offset = findPreviousOffset(table) + sizeOf;

    table->symbolsCount++;
    return 0;
}