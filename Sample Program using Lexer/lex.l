%{
#include <stdio.h>
%}

DIGIT [0-9]
WS [ \t \n ]
PLUS "+"
MINUS "-"
DIVIDE "/"
MODULUS "%"
MULTIPLY "*"
LPAREN "("
RPAREN ")"
OP {PLUS}|{MINUS}|{DIVIDE}|{MODULUS}|{MULTIPLY}
NUM {DIGIT}+(\.{DIGIT}+)?


%%

{NUM} {printf("Digit: %s\n",yytext);}
{OP} {printf("Operator: %s\n",yytext);}
{LPAREN} {printf("Left Parantheses: %s\n",yytext);}
{RPAREN} {printf("Right Parantheses: %s\n",yytext);}
{WS} ;
. ;

%%

int yywrap(){
    return 1;
}

int main(){
    FILE *fp;
    fp = fopen("ip.txt","r");
    yyin = fp;
    yylex();
    return 0;
}