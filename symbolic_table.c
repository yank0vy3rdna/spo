//
// Created by Andrey Kryukov on 28.10.2023.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "symbolic_table.h"
#include "builtin_functions.h"

symbolicTable *newSymbolicTable(symbolicTable *parent) {
    symbolicTable *table = malloc(sizeof(symbolicTable));
    table->parent = parent;
    table->symbolsCount = 0;
    table->capacity = 5;
    table->symbols = malloc(sizeof(symbol) * table->capacity);
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


char *symbolicTable_currentFuncId(symbolicTable *table) {
    if (table == NULL) {
        return NULL;
    }
    if (table->currentFuncId == NULL) {
        return symbolicTable_currentFuncId(table->parent);
    }
    return table->currentFuncId;
}

int symbolicTable_putSymbol(symbolicTable *table, preparedType type, char *identifier, char *label, union ctx ctx,
                            enum symbolCategory category) {
    if (identifier == NULL) {
        fprintf(stderr, "identifier is NULL");
        return 1;
    }
    if (table->symbolsCount >= table->capacity) {
        fprintf(stderr, "table capacity exceed, double it: %d -> %d", table->capacity, table->capacity * 2);
        table->capacity *= 2;
        symbol *s = malloc(table->capacity * sizeof(symbol));
        for (int i = 0; i < table->symbolsCount; ++i) {
            s[i] = table->symbols[i];
        }
        free(table->symbols);
        table->symbols = s;
    }
    identifier = strToHeap(identifier);
    symbol *s = symbolicTable_findSymbol(table, identifier);
    if (s != NULL) {
        fprintf(stderr, "symbol %s already exists", identifier);
        return 3;
    }

    table->symbols[table->symbolsCount].type = type;
    table->symbols[table->symbolsCount].identifier = identifier;
    table->symbols[table->symbolsCount].ctx = ctx;
    table->symbols[table->symbolsCount].category = category;
    table->symbols[table->symbolsCount].label = label;

    table->symbolsCount++;
    return 0;
}