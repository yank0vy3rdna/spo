REMOTE_TASKS_CMD=mono RemoteTasks/Portable.RemoteTasks.Manager.exe -ul $$(cat arch/.env | grep RemoteTasksLogin | awk '{print $$2}') -up $$(cat arch/.env | grep RemoteTasksPassword | awk '{print $$2}')

.PHONY: all clean
all: get_trace

clean:
	rm -rf *.o result out*

lex.yy.c: lexer.l
	flex lexer.l

error.o: error.c
	gcc -c -o error.o error.c

cfg.o: cfg.c
	gcc -c -o cfg.o cfg.c

preprocess_ast.o: preprocess_ast.c
	gcc -c -o preprocess_ast.o preprocess_ast.c

semantic_analyser.o: semantic_analyser.c
	gcc -c -o semantic_analyser.o semantic_analyser.c

symbolic_table.o: symbolic_table.c
	gcc -c -o symbolic_table.o symbolic_table.c

symbolic_table_asm.o: symbolic_table_asm.c
	gcc -c -o symbolic_table_asm.o symbolic_table_asm.c

asm_generator.o: asm_generator.c
	gcc -c -o asm_generator.o asm_generator.c

parser.tab.c: parser.y
	../bison/tests/bison -d -t parser.y
	echo '#include "ast.h"' | cat - parser.tab.h > temp && mv temp parser.tab.h

main.o: main.c
	gcc -c -o main.o main.c

ast.o: ast.c
	gcc -c -o ast.o ast.c

lex.yy.o: lex.yy.c
	gcc -c -o lex.yy.o lex.yy.c

parser.tab.o: parser.tab.c
	gcc -c -o parser.tab.o parser.tab.c

result: ast.o parser.tab.o lex.yy.o main.o error.o cfg.o preprocess_ast.o semantic_analyser.o symbolic_table.o asm_generator.o
	gcc main.o parser.tab.o lex.yy.o ast.o error.o cfg.o preprocess_ast.o semantic_analyser.o symbolic_table.o asm_generator.o -o result && chmod +x result

out.asm: result input.txt
	./result input.txt
	cat out.asm.data out.asm.code > out.asm

assemble_res.txt: out.asm arch/spo.target.pdsl
	$(REMOTE_TASKS_CMD) -s Assemble -w definitionFile arch/spo.target.pdsl archName spo asmListing out.asm > assemble_res.txt; cat assemble_res.txt

out.ptptb: assemble_res.txt
	$(REMOTE_TASKS_CMD) -g $$(cat assemble_res.txt | head -1 | awk  '{print $$6}') -r out.ptptb -o out.ptptb

exec_binary: out.ptptb
	$(REMOTE_TASKS_CMD) -s ExecuteBinaryWithInput -w \
		definitionFile arch/spo.target.pdsl \
		archName spo \
		binaryFileToRun out.ptptb \
		codeRamBankName code_ram \
		ipRegStorageName ip \
		stdinRegStName inp \
		stdoutRegStName outp \
		inputFile stdin.txt \
		finishMnemonicName hlt > exec_res.txt
	cat exec_res.txt
	echo "Success"

get_trace: exec_binary
	$(REMOTE_TASKS_CMD) -g $$(cat exec_res.txt | head -1 | awk  '{print $$6}')  -r trace.txt -o trace.txt
	cat trace.txt

test:
	$(REMOTE_TASKS_CMD) -t ExecuteBinaryWithInput