//
// Created by Andrey Kryukov on 01.11.2023.
//

#include <printf.h>
#include <stdlib.h>
#include <string.h>
#include "asm_generator.h"
#include "symbolic_table_asm.h"

#define asm_code_header "[section code_ram]\nstart:\n"
#define asm_data_header "[section data_ram]\n"
#define asm_footer "halt:\n\thlt\n"


#define mnemonic_1(mnemonic, arg1) fprintf(asmCodeOut, "\t%s %s\n", mnemonic, arg1);
#define mnemonic_2(mnemonic, arg1, arg2) fprintf(asmCodeOut, "\t%s %s, %s\n", mnemonic, arg1, arg2);
#define mnemonic_2_i(mnemonic, arg1, arg2) fprintf(asmCodeOut, "\t%s %d, %s\n", mnemonic, arg1, arg2);
#define mnemonic_3(mnemonic, arg1, arg2, arg3) fprintf(asmCodeOut, "\t%s %s, %s, %s\n", mnemonic, arg1, arg2, arg3);

#define mov_i(from, to) mnemonic_2_i("mov", from, to)
#define push(reg) mnemonic_1("push", reg)
#define pop(reg) mnemonic_1("pop", reg)
#define add(op1, op2, to) mnemonic_3("add", op1, op2, to)
#define sub(op1, op2, to) mnemonic_3("sub", op1, op2, to)
#define mul(op1, op2, to) mnemonic_3("mul", op1, op2, to)
#define div(op1, op2, to) mnemonic_3("div", op1, op2, to)
#define rem(op1, op2, to) mnemonic_3("rem", op1, op2, to)
#define and(op1, op2, to) mnemonic_3("_and", op1, op2, to)
#define or(op1, op2, to) mnemonic_3("_or", op1, op2, to)
#define neg(op, to) mnemonic_2("neg", op, to)
#define not(op, to) mnemonic_2("_not", op, to)

#define jumpeq(op, to) mnemonic_2("jumpeq", op, to)
#define jumpgt(op, to) mnemonic_2("jumpgt", op, to)
#define jumpge(op, to) mnemonic_2("jumpge", op, to)
#define jumplt(op, to) mnemonic_2("jumplt", op, to)
#define jumple(op, to) mnemonic_2("jumple", op, to)
#define jump(to) mnemonic_1("jump", to)

#define load(from, to) mnemonic_2("load", from, to)
#define store(from, to) mnemonic_2("store", from, to)

char *labelName() {
    char *c = malloc(sizeof(char) * 32);
    sprintf(c, "label_%d", labelCounter++);
    return c;
}

#define put_label(name) fprintf(asmCodeOut, "%s:\n", name);
#define put_comment(comment) fprintf(asmCodeOut, "\t\t;%s\n", comment);
#define put_comment_var(comment) fprintf(asmDataOut, "\t\t;%s\n", comment);
#define put_label_var(name) fprintf(asmDataOut, "%s: dw 0x0\n", name);


int translate_literal(preparedLiteral literal) {
    switch (literal.type.type) {
        case INT:
            mov_i(literal.i_value, "r0")
            break;
        case BOOL:
            if (literal.b_value == BOOLEAN_TRUE) {
                mov_i(1, "r0")
            } else {
                mov_i(0, "r0")
            }
            break;
    }
    return 0;
}

int translate_expression(preparedExpression expression, asmSymbolicTable *table);

int translate_binary(preparedBinary binary, asmSymbolicTable *table) {
    translate_expression(*binary.leftOperand, table);
    translate_expression(*binary.rightOperand, table);
    pop("r1");
    pop("r0");
    switch (binary.type) {
        case BINARY_TYPE_PLUS:
            add("r0", "r1", "r0")
            break;
        case BINARY_TYPE_MINUS:
            sub("r0", "r1", "r0")
            break;
        case BINARY_TYPE_STAR:
            mul("r0", "r1", "r0")
            break;
        case BINARY_TYPE_SLASH:
            div("r0", "r1", "r0")
            break;
        case BINARY_TYPE_PERCENT:
            rem("r0", "r1", "r0")
            break;
        case BINARY_TYPE_EQUAL: {
            sub("r0", "r1", "r0") // a - b > 0
            char *label1 = labelName();
            char *label2 = labelName();
            jumpeq("r0", label1)
            mov_i(0, "r0")
            jump(label2)
            put_label(label1)
            mov_i(-1, "r0")
            put_label(label2)
            free(label1);
            free(label2);
        }
            break;
        case BINARY_TYPE_NOTEQUAL: {
            sub("r0", "r1", "r0") // a - b > 0
            char *label1 = labelName();
            char *label2 = labelName();
            jumpgt("r0", label1)
            mov_i(-1, "r0")
            jump(label2)
            put_label(label1)
            mov_i(0, "r0")
            put_label(label2)
            free(label1);
            free(label2);
        }
            break;
        case BINARY_TYPE_LESSTHAN: // a < b
        {
            sub("r0", "r1", "r0") // a - b > 0
            char *label1 = labelName();
            char *label2 = labelName();
            jumplt("r0", label1)
            mov_i(0, "r0")
            jump(label2)
            put_label(label1)
            mov_i(-1, "r0")
            put_label(label2)
            free(label1);
            free(label2);
        }
            break;
        case BINARY_TYPE_GREATERTHAN: // a > b
        {
            sub("r0", "r1", "r0") // a - b > 0
            char *label1 = labelName();
            char *label2 = labelName();
            jumpgt("r0", label1)
            mov_i(0, "r0")
            jump(label2)
            put_label(label1)
            mov_i(-1, "r0")
            put_label(label2)
            free(label1);
            free(label2);
        }
            break;
        case BINARY_TYPE_LESSTHANEQ: // a <= b
        {
            sub("r0", "r1", "r0") // a - b > 0
            char *label1 = labelName();
            char *label2 = labelName();
            jumple("r0", label1)
            mov_i(0, "r0")
            jump(label2)
            put_label(label1)
            mov_i(-1, "r0")
            put_label(label2)
            free(label1);
            free(label2);
        }
            break;
        case BINARY_TYPE_GREATERTHANEQ: // a >= b
        {
            sub("r0", "r1", "r0") // a - b > 0
            char *label1 = labelName();
            char *label2 = labelName();
            jumpge("r0", label1)
            mov_i(0, "r0")
            jump(label2)
            put_label(label1)
            mov_i(-1, "r0")
            put_label(label2)
            free(label1);
            free(label2);
        }
            break;
        case BINARY_TYPE_AND:
            and("r0", "r1", "r0")
            break;
        case BINARY_TYPE_OR:
            or("r0", "r1", "r0")
            break;
    }
    return 0;
}

int translate_place(char *identifier, asmSymbolicTable *table) {
    asmSymbol *s = asmSymbolicTable_findSymbol(table, identifier);
    if (s == NULL) {
        return 1;
    }
    load(s->label, "r0")
    return 0;
}

int labelCounter = 0;

int translate_expression(preparedExpression expression, asmSymbolicTable *table) {
    int res = 0;
    switch (expression.type) {
        case UNARY:
            break;
        case BINARY:
            res = translate_binary(expression.binary, table);
            break;
        case BRACES:
            return translate_expression(*expression.expression, table); // no need to push already pushed r0
            break;
        case CALL:
            break;
        case INDEXER:
            break;
        case PLACE:
            res = translate_place(expression.identifier, table);
            break;
        case LITERAL:
            res = translate_literal(expression.literal);
            break;
    }
    push("r0");
    return res;
}

int translate_variable(preparedVar var, asmSymbolicTable *table) {
    char *label = labelName();
    if (asmSymbolicTable_putSymbol(table, var.identifier, label, 2) != 0) {
        return 1;
    }
    put_comment_var(var.identifier)
    put_label_var(label)

    if (var.isInitValueExists > 0) {
        translate_expression(*var.initValue, table);
        pop("r0")
        store("r0", label)
    }

    return 0;
}

int translate_block(preparedBlock block, asmSymbolicTable *table, char *lastGoThroughLabel);

int translate_statement(preparedStatement statement, asmSymbolicTable *table, char *lastGoThroughLabel);

int translate_ifs(preparedIf ifs, asmSymbolicTable *table, char *lastGoThroughLabel) {
    put_comment("if")
    put_comment(ifs.statement.condition.astNode->value)
    if (translate_expression(ifs.statement.condition, table) != 0) { // r0 contains bool expression
        return 1;
    };
    char *goThrough = labelName();
    char *elseLabel;
    pop("r0")
    if (ifs.elseStatementExists == 1) {
        elseLabel = labelName();
        jumpeq("r0", elseLabel) // if r0 == 0 goto else conditional statement
    } else {
        jumpeq("r0", goThrough) // if r0 == 0 goto else conditional statement
    }
    put_comment("then")
    if (translate_statement(ifs.statement.statement, table, lastGoThroughLabel) != 0) {
        return 1;
    }
    if (ifs.elseStatementExists == 1) {
        jump(goThrough)
        put_label(elseLabel)
        put_comment("else")
        if (translate_statement(ifs.elseStatement, table, lastGoThroughLabel) != 0) {
            return 1;
        }
    }
    put_comment("endif")
    put_label(goThrough)
    return 0;
}

int translate_while(preparedWhile whilep, asmSymbolicTable *table) {
    put_comment("while")
    char *loopbackLabel = labelName();
    put_label(loopbackLabel)
    put_comment(whilep.condition.astNode->value)
    if (translate_expression(whilep.condition, table) != 0) { // r0 contains bool expression
        return 1;
    };
    char *goThrough = labelName();
    pop("r0")
    jumpeq("r0", goThrough) // if r0 == 0 goto else conditional statement
    put_comment("while body")
    if (translate_block(whilep.block, table, goThrough) != 0) {
        return 1;
    }
    jump(loopbackLabel)
    put_label(goThrough)
    put_comment("end while")
    return 0;
}

int translate_dowhile(preparedDoWhile doWhile, asmSymbolicTable *table) {
    put_comment("doWhile")
    char *loopbackLabel = labelName();
    put_label(loopbackLabel)

    char *goThrough = labelName();

    put_comment("doWhile body")
    if (translate_block(doWhile.block, table, goThrough) != 0) {
        return 1;
    }
    put_comment("doWhile condition")
    put_comment(doWhile.condition.astNode->value)
    if (translate_expression(doWhile.condition, table) != 0) { // r0 contains bool expression
        return 1;
    };
    pop("r0") // get result of expression
    not("r0", "r0") // invert
    jumpeq("r0", loopbackLabel) // if result of expression is true goto start of do while body
    put_label(goThrough)
    put_comment("end doWhile")
    return 0;
}

int translate_assigment(preparedAssigment assigment, asmSymbolicTable *table) {
    asmSymbol *s = asmSymbolicTable_findSymbol(table, assigment.to.identifier);
    if (s == NULL) {
        return 1;
    }
    translate_expression(*assigment.rightPart, table);
    pop("r0")
    store("r0", s->label)
    return 0;
}

int translate_statement(preparedStatement statement, asmSymbolicTable *table, char *lastGoThroughLabel) {
    switch (statement.type) {
        case STATEMENT_TYPE_BLOCK:
            return translate_block(statement.block, table, lastGoThroughLabel);
        case STATEMENT_TYPE_VAR:
            for (int i = 0; i < statement.vars.count; ++i) {
                if (translate_variable(statement.vars.vars[i], table) != 0) {
                    return 1;
                }
            }
            break;
        case STATEMENT_TYPE_IF:
            return translate_ifs(*statement.ifp, table, lastGoThroughLabel);
        case STATEMENT_TYPE_WHILE:
            return translate_while(statement.whilep, table); // don't pass lastGoThroughLabel
        case STATEMENT_TYPE_DO_WHILE:
            return translate_dowhile(statement.dowhile, table);
        case STATEMENT_TYPE_BREAK:
            if (lastGoThroughLabel == NULL) {
                fprintf(stderr, "unexpected break\n");
                return 1;
            }
            put_comment("break")
            jump(lastGoThroughLabel)
            break;
        case STATEMENT_TYPE_EXPRESSION:
            return translate_expression(statement.expression, table);
        case STATEMENT_TYPE_ASSIGMENT:
            return translate_assigment(statement.assigment, table);
        case STATEMENT_TYPE_RETURN:
            break;
    }
    return 0;
}

int translate_block(preparedBlock block, asmSymbolicTable *table, char *lastGoThroughLabel) {
    for (int i = 0; i < block.statementsCount; ++i) {
        if (translate_statement(block.statements[i], table, lastGoThroughLabel) != 0) {
            return 1;
        }
    }
    return 0;
}

int translate_procedure(int num, preparedFunc *funcs, int count, asmSymbolicTable *table) {
    table = newAsmSymbolicTable(table, 1024);
    asmSymbol *s = asmSymbolicTable_findSymbol(table, funcs[num].identifier);
    preparedFunc func = funcs[num];

    put_comment_var("--------- function ---------")
    put_comment("--------- function ---------")

    put_comment_var(func.identifier)
    put_comment(func.identifier)

    put_label(s->label)
    for (int i = 0; i < func.args.count; ++i) {
        if (translate_variable(func.args.vars[i], table) != 0) {
            return 1;
        }
    }
    if (translate_block(func.body, table, NULL) != 0) {
        return 1;
    }

    return 0;
}

int generate_asm(preparedFunc *funcs, int count) {
    asmSymbolicTable *table = newAsmSymbolicTable(NULL, count);
    for (int i = 0; i < count; ++i) {
        if (asmSymbolicTable_putSymbol(table, funcs[i].identifier, labelName(), 0) != 0) {
            return 1;
        }
    }
    fprintf(asmCodeOut, asm_code_header);
    fprintf(asmDataOut, asm_data_header);
    for (int i = 0; i < count; ++i) {
        if (translate_procedure(i, funcs, count, table) != 0) {
            return 2;
        }
    }
    fprintf(asmCodeOut, asm_footer);

    return 0;
}