//
// Created by Andrey Kryukov on 14.09.2023.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast.h"


ASTNodes allNodes[maxCountOfNodesLists];
int fileNum;

void destroy() {
    for (int i = 0; i < fileNum; ++i) {
        for (int j = 0; j < allNodes[i].count; ++j) {
            free(allNodes[i].nodes[j]);
        }
        free(allNodes[i].nodes);
    }
}

ASTNodes createNodes() {
    ASTNodes nodes;
    nodes.nodes = malloc(1024 * 8 * sizeof(ASTNode *));
    nodes.count = 0;
    return nodes;
}

ASTNode *createNode(char *type, ASTNode *left, ASTNode *right, char *value) {
    ASTNode *node = malloc(sizeof(ASTNode));
    node->type = type;
    node->left = left;
    node->right = right;
    char *buf = malloc(1024 * sizeof(char));
    strcpy(buf, value);
    node->value = buf;
    allNodes[fileNum].nodes[allNodes[fileNum].count] = node;
    allNodes[fileNum].count++;
    return node;
}

void printNodeId(ASTNode *node) {
    printf("\"Type: %s, Id: %d", node->type, node->id);
    if (strlen(node->value) > 0) {
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
        printf(";\n");
        printNode(node->right);
    }
}

void printRoot() {
    printf("\"ROOT\"");
}

void printAST() {
    printf("digraph G {\n");
    int idCounter = 0;
    printRoot();
    printf(" [shape=Mdiamond];\n");

    for (int file = 0; file <= fileNum; ++file) {
        for (int i = 0; i < allNodes[file].count; ++i) {
            allNodes[file].nodes[i]->id = idCounter;
            idCounter++;
        }
        printRoot();
        printf(" -> ");
        printNodeId(allNodes[file].nodes[allNodes[file].count - 1]);
        printf(";\n");
        printNode(allNodes[file].nodes[allNodes[file].count - 1]);

    }
    printf("}\n");
}
