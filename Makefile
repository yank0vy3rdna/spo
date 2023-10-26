REMOTE_TASKS_CMD=mono RemoteTasks/Portable.RemoteTasks.Manager.exe -ul $$(cat arch/.env | grep RemoteTasksLogin | awk '{print $$2}') -up $$(cat arch/.env | grep RemoteTasksPassword | awk '{print $$2}')

.PHONY: all clean
all: result

clean:
	rm -rf *.o result

lex.yy.c: lexer.l
	flex lexer.l

error.o: error.c
	gcc -c -o error.o error.c

cfg.o: cfg.c
	gcc -c -o cfg.o cfg.c

parser.tab.c: parser.y
	bison -d -t parser.y
	echo '#include "ast.h"' | cat - parser.tab.h > temp && mv temp parser.tab.h

main.o: main.c
	gcc -c -o main.o main.c

ast.o: ast.c
	gcc -c -o ast.o ast.c

lex.yy.o: lex.yy.c
	gcc -c -o lex.yy.o lex.yy.c

parser.tab.o: parser.tab.c
	gcc -c -o parser.tab.o parser.tab.c

result: ast.o parser.tab.o lex.yy.o main.o error.o cfg.o
	gcc main.o parser.tab.o lex.yy.o ast.o error.o cfg.o -o result && chmod +x result

run: result
	./result input.txt input2.txt

run_assemble:
	$(REMOTE_TASKS_CMD) -s Assemble -w definitionFile arch/spo.target.pdsl archName spo asmListing spo.asm > assemble_res.txt
	cat assemble_res.txt

get_results: run_assemble
	$(REMOTE_TASKS_CMD) -g $$(cat assemble_res.txt | head -1 | awk  '{print $$6}') -r out.ptptb -o out.ptptb

exec_binary: get_results
	$(REMOTE_TASKS_CMD) -s ExecuteBinary -w definitionFile arch/spo.target.pdsl archName spo binaryFileToRun out.ptptb codeRamBankName code_ram ipRegStorageName ip finishMnemonicName hlt > exec_res.txt
	cat exec_res.txt
	echo "Success"

get_trace: exec_binary
	$(REMOTE_TASKS_CMD) -g $$(cat exec_res.txt | head -1 | awk  '{print $$6}')  -r trace.txt -o trace.txt
	cat trace.txt