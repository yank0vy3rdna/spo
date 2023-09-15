//
// Created by Andrey Kryukov on 14.09.2023.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast.h"

ASTNode **allNodes;
u_int64_t allNodesCount;

ASTNode *createNode(char *type, ASTNode *left, ASTNode *right, char *value) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = type;
    node->left = left;
    node->right = right;
    char *buf= malloc(1024* sizeof(char)) ;
    strcpy(buf, value);
    node->value = buf;
    allNodes[allNodesCount] = node;
    allNodesCount++;
    return node;
}
void printNodeId(ASTNode *node) {
    printf("\"Type: %s, Id: %d", node->type, node->id);
    if (strlen(node->value)>0){
        printf(", Value: %s", node->value);
    }
    printf("\"");
}

void printNode(ASTNode *node) {
    if (node->left) {
        printNodeId(node);
        printf(" -> ");
        printNodeId(node->left);
        printf(";\n");
        printNode(node->left);
    }
    if (node->right) {
        printNodeId(node);
        printf(" -> ");
        printNodeId(node->right);
        printf(";\n");printNode(node->right);
    }
}

void printAST() {
    for (int i = 0; i < allNodesCount; ++i) {
        allNodes[i]->id = i;
    }
    printf("digraph G {\n");
    printNode(allNodes[allNodesCount - 1]);

    printNodeId(allNodes[allNodesCount - 1]);
    printf(" [shape=Mdiamond];\n");
    printf("}\n");
}
