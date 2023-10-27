//
// Created by Andrey Kryukov on 26.10.2023.
//

#include "preprocess_ast.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

preparedFunc *findMain(preparedFunc *funcs, int count) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(funcs[i].identifier, "main") == 0) {
            return &funcs[i];
        }
    }
    return NULL;
}

preparedFunc *prepareProcedures(ASTNodes allProcedures) {
    preparedFunc *funcs = malloc(sizeof(preparedFunc) * allProcedures.count);
    for (int i = 0; i < allProcedures.count; ++i) {
        preparedFunc f = prepareProcedure(allProcedures.nodes[i]);
        funcs[i] = f;
    }
    return funcs;
}

preparedUnary prepareUnary(ASTNode *node) {
    preparedUnary unary = {};

    if (strcmp(node->type, "MINUS_UNARY") == 0) {
        unary.type = UNARY_TYPE_MINUS;
    } else if (strcmp(node->type, "NOT") == 0) {
        unary.type = UNARY_TYPE_NOT;
    }
    unary.operand = prepareExpression(node->left);
    return unary;
}

preparedBinary prepareBinaryExpr(ASTNode *node) {
    preparedBinary binary = {};
    if (strcmp(node->type, "PLUS") == 0) {
        binary.type = BINARY_TYPE_PLUS;
    } else if (strcmp(node->type, "MINUS") == 0) {
        binary.type = BINARY_TYPE_MINUS;
    } else if (strcmp(node->type, "STAR") == 0) {
        binary.type = BINARY_TYPE_STAR;
    } else if (strcmp(node->type, "SLASH") == 0) {
        binary.type = BINARY_TYPE_SLASH;
    } else if (strcmp(node->type, "PERCENT") == 0) {
        binary.type = BINARY_TYPE_PERCENT;
    } else if (strcmp(node->type, "EQUALITY") == 0) {
        binary.type = BINARY_TYPE_EQUAL;
    } else if (strcmp(node->type, "NOTEQUAL") == 0) {
        binary.type = BINARY_TYPE_NOTEQUAL;
    } else if (strcmp(node->type, "LESSTHAN") == 0) {
        binary.type = BINARY_TYPE_LESSTHAN;
    } else if (strcmp(node->type, "GREATERTHAN") == 0) {
        binary.type = BINARY_TYPE_GREATERTHAN;
    } else if (strcmp(node->type, "LESSTHANEQ") == 0) {
        binary.type = BINARY_TYPE_LESSTHANEQ;
    } else if (strcmp(node->type, "GREATERTHANEQ") == 0) {
        binary.type = BINARY_TYPE_GREATERTHANEQ;
    } else if (strcmp(node->type, "AND") == 0) {
        binary.type = BINARY_TYPE_AND;
    } else if (strcmp(node->type, "OR") == 0) {
        binary.type = BINARY_TYPE_OR;
    }
    binary.leftOperand = prepareExpression(node->left);
    binary.rightOperand = prepareExpression(node->right);
    return binary;
}

char *unaryStatements[] = {
        "MINUS_UNARY",
        "NOT"
};
char *binaryStatements[] = {
        "PLUS",
        "MINUS",
        "STAR",
        "SLASH",
        "PERCENT",
        "EQUALITY",
        "NOTEQUAL",
        "LESSTHAN",
        "GREATERTHAN",
        "LESSTHANEQ",
        "GREATERTHANEQ",
        "AND",
        "OR",
};
char *literalTypes[] = {
        "TRUE",
        "FALSE",
        "STR",
        "CHAR",
        "HEX",
        "BIN",
        "DEC",
};

expressionsList makeExpressionsList(ASTNode *node) {
    expressionsList list = {};
    list.expressionsCount = 0;
    if (strcmp(node->type, "optionalListExpr") == 0) {
        node = node->left;
    }
    ASTNode *i = node;
    while (i != NULL) {
        list.expressionsCount++;
        i = i->right;
    }
    list.expressions = malloc(sizeof(preparedExpression) * list.expressionsCount);
    for (int j = 0; j < list.expressionsCount; ++j) {
        preparedExpression *expr = prepareExpression(node->left);
        node = node->right;
        if (expr == NULL) {
            printf("# Empty expression warning: %s!\n", node->left->type);
            list.expressionsCount--;
            j--;
            continue;
        }
        list.expressions[j] = *expr;
    }

    return list;
}

preparedCall prepareCall(ASTNode *node) {
    preparedCall call = {};
    call.procedureName = node->left->value;
    call.argumentExpressions = makeExpressionsList(node->right);
    return call;
}

preparedIndexer prepareIndexer(ASTNode *node) {
    preparedIndexer indexer = {};
    indexer.expression = prepareExpression(node);
    indexer.indexExpressions = makeExpressionsList(node->right);
    return indexer;
}

preparedLiteral prepareLiteral(ASTNode *node) {
    preparedLiteral literal = {};
    if (strcmp(node->type, "TRUE") == 0) {
        literal.type.type = BOOL;
        literal.type.arrayDem = 0;
        literal.b_value = BOOLEAN_TRUE;
    } else if (strcmp(node->type, "FALSE") == 0) {
        literal.type.type = BOOL;
        literal.type.arrayDem = 0;
        literal.b_value = BOOLEAN_FALSE;
    } else if (strcmp(node->type, "STR") == 0) {
        literal.type.type = CHARACTER;
        literal.type.arrayDem = 1;
        literal.s_value = node->value;
    } else if (strcmp(node->type, "CHAR") == 0) {
        literal.type.type = CHARACTER;
        literal.type.arrayDem = 0;
        literal.c_value = node->value[0];
    } else if (strcmp(node->type, "HEX") == 0 ||
               strcmp(node->type, "DEC") == 0 ||
               strcmp(node->type, "BIN") == 0
            ) {
        literal.type.type = INT;
        literal.type.arrayDem = 0;
        literal.i_value = atoi(node->value);
    }
    return literal;
}

preparedExpression *prepareExpression(ASTNode *node) {
    preparedExpression *expression = malloc(sizeof(preparedExpression));
    if (strcmp(node->type, "braces") == 0) {
        expression->type = BRACES;
        expression->expression = prepareExpression(node->left);
        return expression;
    } else if (strcmp(node->type, "CALL") == 0) {
        expression->type = CALL;
        expression->call = prepareCall(node);
    } else if (strcmp(node->type, "indexer") == 0) {
        expression->type = INDEXER;
        expression->indexer = prepareIndexer(node);
    }
    if (strcmp(node->type, "IDENTIFIER") == 0) {
        expression->type = PLACE;
        expression->identifier = node->value;
    } else {
        for (int i = 0; i < 13; ++i) {
            if (strcmp(node->type, binaryStatements[i]) == 0) {
                expression->type = BINARY;
                expression->binary = prepareBinaryExpr(node);
                return expression;
            }
        }
        for (int i = 0; i < 2; ++i) {
            if (strcmp(node->type, unaryStatements[i]) == 0) {
                expression->type = UNARY;
                expression->unary = prepareUnary(node);
                return expression;
            }
        }
        for (int i = 0; i < 7; i++) {
            if (strcmp(node->type, literalTypes[i]) == 0) {
                expression->type = LITERAL;
                expression->literal = prepareLiteral(node);
                return expression;
            }
        }
    }
    return expression;
}

conditionalStatement makeConditionalStatementFromIf(ASTNode *node) {
    conditionalStatement statement = {};
    statement.condition = *prepareExpression(node->left);
    statement.statement = prepareStatement(node->right->left);
    return statement;
}

preparedIf *prepareIf(ASTNode *node) {
    preparedIf *ifp = malloc(sizeof(preparedIf));
    conditionalStatement firstStatement = makeConditionalStatementFromIf(node);
    ASTNode *i = node->right->right;
    ifp->countOfConditionalStatements = 1;
    while (i != NULL) {
        if (strcmp(i->type, "elseif") == 0) {
            ifp->countOfConditionalStatements++;
        }
        i = i->right;
    }
    ifp->statements = malloc(sizeof(conditionalStatement) * ifp->countOfConditionalStatements);
    ifp->statements[0] = firstStatement;
    int j = 1;
    i = node->right->right;
    while (i != NULL) {
        if (strcmp(i->type, "else") == 0) {
            ifp->elseStatement = prepareStatement(i->left);
            break;
        } else if (strcmp(i->type, "elseif") == 0) {
            ifp->statements[j] = makeConditionalStatementFromIf(i->left);
            j++;
            i = i->left->right->right;
        }
    }

    return ifp;
}

preparedType prepareType(ASTNode *node, int arrayDem) {
    preparedType type = {};
    type.arrayDem = arrayDem;
    if (strcmp(node->type, "TYPEDEF") == 0) {
        if (strcmp(node->value, "byte") == 0 ||
            strcmp(node->value, "int") == 0 ||
            strcmp(node->value, "uint") == 0 ||
            strcmp(node->value, "long") == 0 ||
            strcmp(node->value, "ulong") == 0) {
            type.type = INT;
            type.customTypeIdentifier = node->value;
        } else if (strcmp(node->value, "bool") == 0) {
            type.type = BOOL;
        } else if (strcmp(node->value, "void") == 0) {
            type.type = VOID;
        } else if (strcmp(node->value, "string") == 0) {
            type.type = CHARACTER;
            type.arrayDem++;
            type.customTypeIdentifier = node->value;
        } else if (strcmp(node->value, "char") == 0) {
            type.type = CHARACTER;
        }
    } else if (strcmp(node->type, "IDENTIFIER") == 0) {
        type.type = CUSTOM;
        type.customTypeIdentifier = node->value;
    } else if (strcmp(node->type, "array") == 0) {
        type = prepareType(node->left, arrayDem + strlen(node->value) - 1);
    }
    return type;
}

preparedVar prepareArgDef(ASTNode *node) {
    preparedVar var = {};
    var.isInitValueExists = 0;
    var.type = prepareType(node->left, 0);
    var.identifier = node->right->value;
    return var;
}

preparedVars prepareVars(ASTNode *node) {
    preparedVars vars = {};
    vars.count = 0;
    preparedType type = prepareType(node->left, 0);
    ASTNode *i = node->right;
    while (i != NULL) {
        vars.count++;
        i = i->right;
    }
    vars.vars = malloc(sizeof(preparedVar) * vars.count);
    i = node->right;
    for (int j = 0; j < vars.count; ++j) {
        preparedVar var = {};
        var.type = type;
        if (strcmp(i->left->type, "IDENTIFIER") == 0) {
            var.identifier = i->left->value;
            var.isInitValueExists = 0;
        } else {
            var.isInitValueExists = 1;
            var.initValue = prepareExpression(i->left->right);
            if (strcmp(i->left->left->type, "IDENTIFIER") != 0) {
                fprintf(stderr, "Variable name is not identifier");
                return vars;
            }
            var.identifier = i->left->left->value;
        }
        vars.vars[j] = var;
        i = i->right;
    }
    return vars;
}

preparedWhile prepareWhile(ASTNode *node) {
    preparedWhile whilep = {};
    preparedExpression *expr = prepareExpression(node->left);
    if (expr == NULL) {
        fprintf(stderr, "invalid expression");
        return whilep;
    }
    whilep.condition = *expr;
    whilep.block = prepareBlock(node->right);
    return whilep;
}

preparedDoWhile prepareDoWhile(ASTNode *node) {
    preparedDoWhile dowhile = {};
    preparedExpression *expr = prepareExpression(node->right);
    if (expr == NULL) {
        fprintf(stderr, "invalid expression");
        return dowhile;
    }
    dowhile.condition = *expr;
    dowhile.block = prepareBlock(node->left);
    return dowhile;
}

preparedStatement prepareStatement(ASTNode *node) {
    preparedStatement statement = {};
    if (strcmp(node->type, "var") == 0) {
        statement.type = STATEMENT_TYPE_VAR;
        statement.vars = prepareVars(node);
    } else if (strcmp(node->type, "if") == 0) {
        statement.type = STATEMENT_TYPE_IF;
        statement.ifp = prepareIf(node);
    } else if (strcmp(node->type, "block") == 0) {
        statement.type = STATEMENT_TYPE_BLOCK;
        statement.block = prepareBlock(node);
    } else if (strcmp(node->type, "while") == 0) {
        statement.type = STATEMENT_TYPE_WHILE;
        statement.whilep = prepareWhile(node);
    } else if (strcmp(node->type, "dowhile") == 0) {
        statement.type = STATEMENT_TYPE_DO_WHILE;
        statement.dowhile = prepareDoWhile(node);
    } else if (strcmp(node->type, "break") == 0) {
        statement.type = STATEMENT_TYPE_BREAK;
    } else {
        preparedExpression *expression = prepareExpression(node);
        if (expression == NULL) {
            fprintf(stderr, "invalid expression");
            return statement;
        }
        statement.type = STATEMENT_TYPE_EXPRESSION;
        statement.expression = *expression;
    }
    return statement;
}

preparedBlock prepareBlock(ASTNode *body) {
    preparedBlock block = {};
    if (body->left == NULL) {
        return block;
    }
    ASTNode *listStatement = body->left;
    ASTNode *i = listStatement;
    block.statementsCount = 0;
    while (i != NULL) {
        block.statementsCount++;
        i = i->right;
    }
    i = listStatement;
    block.statements = malloc(sizeof(preparedStatement) * block.statementsCount);
    int j = 0;
    while (i != NULL) {
        block.statements[j] = prepareStatement(i->left);
        j++;
        i = i->right;
    }
    return block;
}


preparedVars prepareFuncArgs(ASTNode *node) {
    preparedVars args = {};
    args.count = 0;
    if (node == NULL) {
        return args;
    }
    ASTNode *i = node;
    while (i != NULL) {
        args.count++;
        if (strcmp(i->type, "argDef") == 0) {
            break;
        }
        i = i->right;
    }
    args.vars = malloc(sizeof(preparedVar) * args.count);
    i = node;
    for (int j = 0; j < args.count; ++j) {
        if (j == args.count - 1) {
            args.vars[j] = prepareArgDef(node);
        } else {
            args.vars[j] = prepareArgDef(node->left);
        }
        i = i->right;
    }
    return args;
}

preparedFunc prepareProcedure(ASTNode *procedure) {
    preparedFunc pf = {};
    if (!procedure) {
        printf("null procedure");
        return pf;
    }
    if (strcmp(procedure->type, sourceItem) != 0) {
        printf("procedure not sourceItem");
        return pf;
    }
    if (!procedure->left) {
        printf("procedure without funcSignature");
        return pf;
    }
    if (!procedure->right) {
        printf("procedure without body");
        return pf;
    }
    if (!procedure->left->left) {
        printf("funcSignature without argDef");
        return pf;
    }
    if (!procedure->left->left->right) {
        printf("argDef without identifier");
        return pf;
    }
    pf.identifier = procedure->left->left->right->value;
    pf.args = prepareFuncArgs(procedure->left->right);
    pf.returnType = prepareType(procedure->left->left->left, 0);
    pf.body = prepareBlock(procedure->right);
    return pf;
}

void processSemantics(ASTNodes allProcedures) {
    preparedFunc *funcs = prepareProcedures(allProcedures);
    preparedFunc *main = findMain(funcs, allProcedures.count);
    if (main == NULL) {
        printf("main procedure not found\n");
        return;
    }
}
/*
 *
 * Call -> push instruction pointer to stack
 * push frame pointer to stack
 * make frame pointer equal to stack pointer
 * push arguments to stack, add to stack pointer size of arguments and size of memory the function need for variables
 * goto procedure pointer
 * do some stuff ...
 * put return value into r0
 * make stack pointer equal frame pointer
 * pop old frame pointer from stack
 * pop old instruction pointer from stack
 */

