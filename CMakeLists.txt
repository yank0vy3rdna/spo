cmake_minimum_required(VERSION 3.26)
project(lab1 C)

set(CMAKE_C_STANDARD 11)
add_executable(lab1 main.c ast.c parser.tab.c lex.yy.c error.c
        cfg.c
        cfg.h
        preprocess_ast.c
        preprocess_ast.h
        semantic_analyser.c
        semantic_analyser.h
        symbolic_table.c
        symbolic_table.h
        asm_generator.c
        asm_generator.h
        builtin_functions.c
        builtin_functions.h
)
