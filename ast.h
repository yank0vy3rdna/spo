//
// Created by Andrey Kryukov on 14.09.2023.
//

#ifndef LAB1_AST_H
#define LAB1_AST_H

typedef struct ASTNode ASTNode;

struct ASTNode {
    char *type;
    ASTNode *left;
    ASTNode *right;
    char *value;
    int id;
};

void printAST();

ASTNode *createNode(char *type, ASTNode *left, ASTNode *right, char *value);

#endif //LAB1_AST_H
