%{
#include <stdio.h>
int count = 0; /* Moved the count variable declaration to the top */
%}

%%

[A-Z] {
    printf("Capital letter found: %c\n", yytext[0]);
    count++; /* Increment count for each capital letter found */
}

. ; /* No action for non-capital letters */

\n { /* Do nothing for newline characters */ }

%%

int yywrap() {
    return 1; /* Return 1 to indicate the end of input */
}

int main() {
    FILE *fp;
    char filename[50];
    printf("Enter the filename: \n");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    yyin = fp; /* Set the input stream for the lexer */
    yylex(); /* Start the lexer */
    printf("\nNumber of Capital letters in the given input - %d\n", count);
    fclose(fp); /* Close the file */
    return 0;
}
