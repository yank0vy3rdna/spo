#include <string.h>
#include "main.h"
#include "cfg.h"
#include "preprocess_ast.h"
#include "semantic_analyser.h"
#include "asm_generator.h"

#define codeAsmOutFilename "out.asm.code"
#define dataAsmOutFilename "out.asm.data"

extern ASTNodes allNodes[maxCountOfNodesLists];
extern int fileNum;

int main(int argc, char *argv[]) {
    if (argc > maxCountOfNodesLists) {
        printf("Max count of input files - 1024");
        return 1;
    }
//    yydebug = 1;
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
        preparedFunc *funcsAfterPreprocessing = prepareProcedures(allProcedures);
        if (processSemantics(funcsAfterPreprocessing, allProcedures.count) != 0) {
            return 1;
        }

        FILE *code = fopen(codeAsmOutFilename, "w+");
        if (!code) {
            printf("Не удалось открыть файл: "codeAsmOutFilename);
            return 1;
        }
        FILE *data = fopen(dataAsmOutFilename, "w+");
        if (!data) {
            fclose(code);
            printf("Не удалось открыть файл: "dataAsmOutFilename);
            return 1;
        }
        asmCodeOut = code;
        asmDataOut = data;
        int res = generate_asm(funcsAfterPreprocessing, allProcedures.count);
        fclose(code);
        fclose(data);
        if (res != 0) {
            return 1;
        }

        destroy();
    } else {
        printf("Использование: %s <input_file>\n", argv[0]);
        return 1;
    }
    return 0;
}
