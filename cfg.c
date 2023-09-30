//
// Created by Andrey Kryukov on 18.09.2023.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "cfg.h"

extern ASTNodes allNodes[maxCountOfNodesLists];
extern int fileNum;

ASTNodes findAllProcedures() {
    ASTNodes funcDefs = createNodes();
    for (int i = 0; i < fileNum; ++i) {
        for (int j = 0; j < allNodes[i].count; ++j) {
            if (strcmp(allNodes[i].nodes[j]->type, sourceItem) == 0) {
                funcDefs.nodes[funcDefs.count] = allNodes[i].nodes[j];
                funcDefs.count++;
            }
        }
    }
    return funcDefs;
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
    pf.body = procedure->right;
    return pf;
}

Block *NewBlock(int id, char *call) {
    Block *block = malloc(sizeof(Block));
    block->id = id;
    char *buf = malloc(strlen(call) * sizeof(char));
    strcpy(buf, call);
    block->call = buf;
    block->predecessors = NewLinkList();
    block->exits = NewLinkList();
    return block;
}

BlockList *NewBlockList() {
    BlockList *list = malloc(sizeof(BlockList));
    list->blocks = malloc(sizeof(Block *) * 1024);
    list->count = 0;
    return list;
}

void BlockList_push(BlockList *list, Block *block) {
    list->blocks[list->count] = block;
    list->count++;
};

LinkList *NewLinkList() {
    LinkList *list = malloc(sizeof(LinkList));
    list->links = malloc(sizeof(Link *) * 1024);
    list->count = 0;
    return list;
}

void LinkList_push(LinkList *list, Link *link) {
    list->links[list->count] = link;
    list->count++;
};

Link *NewLink(Block *source, Block *target, char *comment) {
    Link *link = malloc(sizeof(Link));
    link->source = source;
    link->target = target;
    link->comment = comment;
    return link;
}

void BlockList_pop(BlockList *list) {
    list->count--;
    if (list->count < 0) {
        list->count = 0;
    }
}

void CFGBuilder_init(CFGBuilder *cfgBuilder) {
    cfgBuilder->after_loop_block_stack = NewBlockList();
    cfgBuilder->curr_loop_guard_stack = NewBlockList();
    cfgBuilder->calls = NewBlockList();
    cfgBuilder->current_block = NULL;
}

Block *CFGBuilder_newBlock(CFGBuilder *cfgBuilder, char *call) {
    cfgBuilder->current_id++;
    return NewBlock(cfgBuilder->current_id, call);
}

void AddExit(Block *block, Block *nextBlock, char *comment) {
    Link *link = NewLink(block, nextBlock, comment);
    LinkList_push(block->exits, link);
    LinkList_push(nextBlock->predecessors, link);
}

void CFGBuilder_visitIf(CFGBuilder *cfgBuilder, ASTNode *node) {
    Block *ifBlock = CFGBuilder_newBlock(cfgBuilder, "");
    AddExit(cfgBuilder->current_block, ifBlock, "if");
    Block *afterIfBlock = CFGBuilder_newBlock(cfgBuilder, "");
    if (node->right->right != NULL) { // else block exists
        Block *elseBlock = CFGBuilder_newBlock(cfgBuilder, "");
        AddExit(cfgBuilder->current_block, elseBlock, "else");
        cfgBuilder->current_block = elseBlock;
        CFGBuilder_visit(cfgBuilder, node->right->right);
        if (cfgBuilder->current_block->exits->count == 0) {
            AddExit(cfgBuilder->current_block, afterIfBlock, "afterIf");
        }
    } else {
        AddExit(cfgBuilder->current_block, afterIfBlock, "afterIf");
    }
    cfgBuilder->current_block = ifBlock;
    CFGBuilder_visit(cfgBuilder, node->right->left);
    if (cfgBuilder->current_block->exits->count == 0) {
        AddExit(cfgBuilder->current_block, afterIfBlock, "afterIf");
    }
    cfgBuilder->current_block = afterIfBlock;
}

Block *CFGBuilder_newloopguard(CFGBuilder *cfgBuilder) {
    if (cfgBuilder->current_block->exits->count == 0) {
        return cfgBuilder->current_block;
    }
    Block *loopguard = CFGBuilder_newBlock(cfgBuilder, "");
    AddExit(cfgBuilder->current_block, loopguard, "loop");
    return loopguard;
}

void CFGBuilder_visitDoWhile(CFGBuilder *cfgBuilder, ASTNode *node) {
    Block *loopguard = CFGBuilder_newloopguard(cfgBuilder);
    cfgBuilder->current_block = loopguard;
    BlockList_push(cfgBuilder->curr_loop_guard_stack, loopguard);

    Block *whileBlock = CFGBuilder_newBlock(cfgBuilder, "");
    AddExit(loopguard, whileBlock, "do while");
    cfgBuilder->current_block = whileBlock;
    Block *afterWhile = CFGBuilder_newBlock(cfgBuilder, "");

    BlockList_push(cfgBuilder->after_loop_block_stack, afterWhile);

    CFGBuilder_visit(cfgBuilder, node->left);


    AddExit(cfgBuilder->current_block, loopguard, "while cond is true");
    AddExit(cfgBuilder->current_block, afterWhile, "while cond is false");
    cfgBuilder->current_block = afterWhile;

    BlockList_pop(cfgBuilder->after_loop_block_stack);
    BlockList_pop(cfgBuilder->curr_loop_guard_stack);
}

void CFGBuilder_visitWhile(CFGBuilder *cfgBuilder, ASTNode *node) {
    Block *loopguard = CFGBuilder_newloopguard(cfgBuilder);
    cfgBuilder->current_block = loopguard;
    BlockList_push(cfgBuilder->curr_loop_guard_stack, loopguard);
    Block *whileBlock = CFGBuilder_newBlock(cfgBuilder, "");
    AddExit(cfgBuilder->current_block, whileBlock, "while cond is true");
    Block *afterWhile = CFGBuilder_newBlock(cfgBuilder, "");
    BlockList_push(cfgBuilder->after_loop_block_stack, afterWhile);
    AddExit(cfgBuilder->current_block, afterWhile, "while cond is false");
    cfgBuilder->current_block = whileBlock;
    CFGBuilder_visit(cfgBuilder, node->right);

    if (cfgBuilder->current_block->exits->count == 0) {
        AddExit(cfgBuilder->current_block, loopguard, "loop back");
    }
    cfgBuilder->current_block = afterWhile;
    BlockList_pop(cfgBuilder->after_loop_block_stack);
    BlockList_pop(cfgBuilder->curr_loop_guard_stack);
}

void CFGBuilder_visitBreak(CFGBuilder *cfgBuilder, ASTNode *node) {
    if (cfgBuilder->after_loop_block_stack->count == 0) {
        return;
    }
    AddExit(cfgBuilder->current_block,
            cfgBuilder->after_loop_block_stack->blocks[cfgBuilder->after_loop_block_stack->count - 1],
            "break");
}

//void CFGBuilder_visitCall(CFGBuilder *cfgBuilder, ASTNode *node) {
//    Block *block = CFGBuilder_newBlock(cfgBuilder, node->left->value);
//    AddExit(cfgBuilder->current_block,
//            block,
//            "call");
//    BlockList_push(cfgBuilder->calls, block);
//}


void CFGBuilder_visit(CFGBuilder *cfgBuilder, ASTNode *node) {
    if (!node) {
        return;
    }
    if (strcmp(node->type, "if") == 0) {
        CFGBuilder_visitIf(cfgBuilder, node);
        return;
    } else if (strcmp(node->type, "while") == 0) {
        CFGBuilder_visitWhile(cfgBuilder, node);
        return;
    } else if (strcmp(node->type, "dowhile") == 0) {
        CFGBuilder_visitDoWhile(cfgBuilder, node);
        return;
    } else if (strcmp(node->type, "break") == 0) {
        CFGBuilder_visitBreak(cfgBuilder, node);
        return;
    }
//    else if (strcmp(node->type, "CALL") == 0) {
//        CFGBuilder_visitCall(cfgBuilder, node);
//        return;
//    }
    else {
        if (node->left) {
            CFGBuilder_visit(cfgBuilder, node->left);
        }
        if (node->right) {
            CFGBuilder_visit(cfgBuilder, node->right);
        }
    }
}

CFG *CFGBuilder_build(CFGBuilder *cfgBuilder, char *procedureName, ASTNode *node, int nextId) {
    cfgBuilder->current_id = nextId;
    cfgBuilder->current_block = CFGBuilder_newBlock(cfgBuilder, "");
    cfgBuilder->cfg = NewCFG(procedureName, cfgBuilder->current_block);

    CFGBuilder_visit(cfgBuilder, node);

    cfgBuilder->cfg->nextId = cfgBuilder->current_id;

    return cfgBuilder->cfg;
}

CFG *NewCFG(char *procedureName, Block *entryblock) {
    CFG *cfg = malloc(sizeof(CFG));
    cfg->finalblocks = NewBlockList();
    cfg->procedureName = procedureName;
    cfg->entryblock = entryblock;
    return cfg;
}

void Block_print(Block *block) {
    printf("\"%d\"", block->id);
}

void Link_print(Link *link) {
    Block_print(link->source);
    printf(" -> ");
    Block_print(link->target);
    printf("[label=\"%s\"];\n", link->comment);
}

int seenOrNot(int id, int count, int *seen) {
    for (int i = 0; i < count; ++i) {
        if (seen[i] == id) {
            return 1;
        }
    }
    return 0;
}

CFG *CFG_find(CFG **cfgs, int countCfgs, char *procedureName) {
    for (int i = 0; i < countCfgs; ++i) {
        if (strcmp(cfgs[i]->procedureName, procedureName) == 0) {
            return cfgs[i];
        }
    }
    return NULL;
}

Block *BlockFindLast(Block *block) {
    if (block->exits->count == 0) {
        return block;
    }
    return BlockFindLast(block->exits->links[0]->target);
}

void recPrint(Block *block, int *seen, int *count, CFG **cfgs, int countCfgs) {
    if (seenOrNot(block->id, *count, seen) != 0) {
        return;
    }
    seen[*count] = block->id;
    (*count)++;
//    if (strlen(block->call) > 0) {
//        CFG *calledProcedure = CFG_find(cfgs, countCfgs, block->call);
//        if (calledProcedure == NULL) {
//            printf("procedure %s not found", block->call);
//            exit(1);
//        }
//        Block_print(block);
//        printf(" -> ");
//        Block_print(calledProcedure->entryblock);
//        printf("[label=\"call procedure %s\"];\n", block->call);
//
//        Block *lastProcBlock = BlockFindLast(calledProcedure->entryblock);
//
//        if (block->exits->count>0){
//            Block_print(lastProcBlock);
//            printf(" -> ");
//            Block_print(block);
//        }

//        return;
//    } else {
        for (int i = 0; i < block->exits->count; ++i) {
            Link_print(block->exits->links[i]);
            recPrint(block->exits->links[i]->target, seen, count, cfgs, countCfgs);
        }
        if (block->exits->count == 0) {
            Block_print(block);
            printf(" -> end;\n");
        }
//    }
}

void CFG_print(CFG *cfg, int num, CFG **cfgs, int countCfgs) {
    cfg->entryblock->id = -cfg->entryblock->id;
    int seen[1024];
    int count = 0;
    printf("subgraph cluster_%d {\n", num);
    printf("color=black;\n");
    printf("label=%s;\n", cfg->procedureName);
    recPrint(cfg->entryblock, seen, &count, cfgs, countCfgs);
    printf("}\nstart -> ");
    Block_print(cfg->entryblock);
    printf(";\n");
}

CFG *makeCFG(preparedFunc pf, int nextId, int num) {
    CFGBuilder cfgBuilder = {};
    CFGBuilder_init(&cfgBuilder);

    CFG *cfg = CFGBuilder_build(&cfgBuilder, pf.identifier, pf.body, nextId);

    return cfg;
}

