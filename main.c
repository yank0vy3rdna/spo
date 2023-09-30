#include "main.h"
#include "cfg.h"

extern ASTNodes allNodes[maxCountOfNodesLists];
extern int fileNum;

int main(int argc, char *argv[]) {
    if (argc > maxCountOfNodesLists) {
        printf("Max count of input files - 1024");
        return 1;
    }
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            FILE *input_file = fopen(argv[i], "r");
            if (input_file) {
                allNodes[fileNum] = createNodes();
                yyin = input_file;
                yyparse();
                fclose(input_file);
                fileNum++;
            } else {
                printf("Не удалось открыть файл: %s\n", argv[i]);
            }
        }
        ASTNodes allProcedures = findAllProcedures();
        int nextId = 0;
        CFG **cfgs = malloc(allProcedures.count * sizeof(CFG *));
        for (int i = 0; i < allProcedures.count; ++i) {
            preparedFunc func = prepareProcedure(allProcedures.nodes[i]);
            CFG *cfg = makeCFG(func, nextId, i);
            cfgs[i] = cfg;
            nextId = cfg->nextId;

        }
        printf("digraph G {");

        for (int i = 0; i < allProcedures.count; ++i) {
            CFG_print(cfgs[i], i, cfgs, allProcedures.count);

        }

        printf("start [shape=Mdiamond]; end [shape=Msquare];}\n");

        destroy();
    } else {
        printf("Использование: %s <input_file>\n", argv[0]);
        return 1;
    }
    return 0;
}
