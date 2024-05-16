### Pre-requisites
1. Flex and BISON for Windows or Lex and YACC for legacy systems/WSL
2. GCC compiler with extended linked libraries for token conversion, parsing and compilation

### Note: If you are planning to run it on WSL/Legacy Systems with Lex and YACC, change line 4 in calc.l file to `#include "y.tab.h"`

### RUN INSTRUCTIONS
## Using Flex and Bison in Windows
1. flex calc.l
2. bison -d calc.y
3. gcc lex.yy.c calc.tab.c -o calculator 
4. calculator.exe

## Using Lex and YACC in Legacy/WSL
1. lex calc.l
2. yacc -d calc.y
3. gcc lex.yy.c y.tab.c -o calculator 
4. ./calculator