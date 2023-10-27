//
// Created by Andrey Kryukov on 26.10.2023.
//

#ifndef LAB1_PREPROCESS_AST_H
#define LAB1_PREPROCESS_AST_H

#include "ast.h"

typedef struct preparedStatement preparedStatement;
typedef struct preparedUnary preparedUnary;
typedef struct preparedExpression preparedExpression;
typedef struct preparedBlock preparedBlock;
typedef struct preparedBinary preparedBinary;
typedef struct preparedCall preparedCall;
typedef struct preparedIndexer preparedIndexer;
typedef enum statementType statementType;
typedef enum expressionType expressionType;
typedef enum binaryType binaryType;
typedef struct expressionsList expressionsList;
typedef enum unaryType unaryType;
typedef struct preparedLiteral preparedLiteral;
typedef enum primitiveType primitiveType;
typedef struct preparedType preparedType;
typedef enum BOOLEAN BOOLEAN;
typedef struct conditionalStatement conditionalStatement;
typedef struct preparedIf preparedIf;
typedef struct preparedWhile preparedWhile;
typedef struct preparedDoWhile preparedDoWhile;
typedef struct preparedVars preparedVars;
typedef struct preparedVar preparedVar;

enum primitiveType {
    CHARACTER, INT, BOOL, VOID, CUSTOM
};
struct preparedType {
    primitiveType type;
    char *customTypeIdentifier;
    int arrayDem;
};
enum BOOLEAN {
    BOOLEAN_TRUE,
    BOOLEAN_FALSE
};
struct preparedLiteral {
    preparedType type;
    char c_value;
    int i_value;
    char *s_value;
    BOOLEAN b_value;
};
struct preparedVar {
    preparedType type;
    char *identifier;
    preparedExpression *initValue;
    int isInitValueExists;
};
struct expressionsList {
    preparedExpression *expressions;
    int expressionsCount;
};
struct preparedCall {
    char *procedureName;
    expressionsList argumentExpressions;
};
struct preparedIndexer {
    preparedExpression *expression;
    expressionsList indexExpressions;
};

enum binaryType {
    BINARY_TYPE_ASSIGMENT,
    BINARY_TYPE_PLUS,
    BINARY_TYPE_MINUS,
    BINARY_TYPE_STAR,
    BINARY_TYPE_SLASH,
    BINARY_TYPE_PERCENT,
    BINARY_TYPE_EQUAL,
    BINARY_TYPE_NOTEQUAL,
    BINARY_TYPE_LESSTHAN,
    BINARY_TYPE_GREATERTHAN,
    BINARY_TYPE_LESSTHANEQ,
    BINARY_TYPE_GREATERTHANEQ,
    BINARY_TYPE_AND,
    BINARY_TYPE_OR,
};
struct preparedBinary {
    binaryType type;
    preparedExpression *leftOperand;
    preparedExpression *rightOperand;
};
enum unaryType {
    UNARY_TYPE_MINUS,
    UNARY_TYPE_NOT
};
struct preparedUnary {
    unaryType type;
    preparedExpression *operand;
};
enum expressionType {
    UNARY,
    BINARY,
    BRACES,
    CALL,
    INDEXER,
    PLACE,
    LITERAL
};

struct preparedExpression {
    expressionType type;

    union {
        preparedUnary unary;
        preparedBinary binary;
        preparedExpression *expression;
        preparedCall call;
        preparedIndexer indexer;
        preparedLiteral literal;
        char *identifier;
    };
};
enum statementType {
    STATEMENT_TYPE_BLOCK,
    STATEMENT_TYPE_VAR,
    STATEMENT_TYPE_IF,
    STATEMENT_TYPE_WHILE,
    STATEMENT_TYPE_DO_WHILE,
    STATEMENT_TYPE_BREAK,
    STATEMENT_TYPE_EXPRESSION
};
struct preparedBlock {
    preparedStatement *statements;
    int statementsCount;
};
struct preparedVars {
    preparedVar *vars;
    int count;
};
struct preparedWhile {
    preparedExpression condition;
    preparedBlock block;
};
struct preparedDoWhile {
    preparedExpression condition;
    preparedBlock block;
};
struct preparedStatement {
    statementType type;
    union {
        preparedBlock block;
        preparedExpression expression;
        preparedIf *ifp;
        preparedVars vars;
        preparedWhile whilep;
        preparedDoWhile dowhile;
    };
};

typedef struct preparedFunc preparedFunc;


struct preparedFunc {
    char *identifier;
    preparedVars args;
    preparedType returnType;
    preparedBlock body;
};
struct conditionalStatement {
    preparedExpression condition;
    preparedStatement statement;
};
struct preparedIf {
    conditionalStatement *statements;
    int countOfConditionalStatements;
    preparedStatement elseStatement;
};


preparedBlock prepareBlock(ASTNode *body);

preparedExpression *prepareExpression(ASTNode *node);

preparedStatement prepareStatement(ASTNode *node);

preparedFunc prepareProcedure(ASTNode *procedure);

void processSemantics(ASTNodes allProcedures);

#endif //LAB1_PREPROCESS_AST_H
