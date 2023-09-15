.PHONY: all clean
all: result

clean:
	rm -rf *.o result

out:
	mkdir out

lex.yy.c: lexer.l
	flex lexer.l

error.o: error.c
	gcc -c -o error.o error.c

parser.tab.c: parser.y
	bison -d -t parser.y
	echo '#include "ast.h"' | cat - parser.tab.h > temp && mv temp parser.tab.h

main.o: main.c out
	gcc -c -o main.o main.c

ast.o: ast.c
	gcc -c -o ast.o ast.c

lex.yy.o: lex.yy.c
	gcc -c -o lex.yy.o lex.yy.c

parser.tab.o: parser.tab.c
	gcc -c -o parser.tab.o parser.tab.c

result: ast.o parser.tab.o lex.yy.o main.o error.o
	gcc main.o parser.tab.o lex.yy.o ast.o error.o -o result && chmod +x result

run: result
	./result input.txt | graph-easy --html --output tree.html
