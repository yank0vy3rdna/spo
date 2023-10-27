cmake_minimum_required(VERSION 3.26)
project(lab1 C)

set(CMAKE_C_STANDARD 11)
add_executable(lab1 main.c ast.c parser.tab.c lex.yy.c error.c
        cfg.c
        cfg.h
        preprocess_ast.c
        semantic_analyser.c
        semantic_analyser.h)
