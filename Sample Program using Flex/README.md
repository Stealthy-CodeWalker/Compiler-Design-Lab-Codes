# Pre-requisites

1. Flex for Windows or Lex for legacy systems/WSL
2. GCC compiler with extended linked libraries for token conversion, parsing and compilation

## Note: If you are planning to run it on WSL/Legacy Systems with Lex and YACC, change line 4 in calc.l file to `#include "y.tab.h"`

### RUN INSTRUCTIONS

## Using Flex in Windows

1. flex analyzer.l
2. gcc lex.yy.c -o analyzer
3. analyzer.exe

## Using Lex in Legacy/WSL

1. lex analyzer.l
2. gcc lex.yy.c -o analyzer
3. ./analyzer
