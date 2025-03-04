%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>

%}

%%

"int"|"char"|"return"|"auto"|"double"|"int"|"struct"|"break"|"else"|"long"|"switch"|"case"|"enum"|"register"|"typedef"|"char"|"extern"|"return"|"union"|"const"|"float"|"short"|"unsigned"|"continue"|"for"|"signed"|"void"|"default"|"goto"|"sizeof"|"volatile"|"do"|"if"|"static"|"while"   { printf("Keyword: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]* { printf("Identifier: %s\n", yytext); }
[=+*/-] { printf("Operator: %s\n", yytext); }
[0-9]+ { printf("Constant: %s\n", yytext); }
['"].['"] { printf("String: %s\n", yytext); }
[{}()\[\],;] { printf("Punctuation: %s\n", yytext); }
"//".*\n { /* Ignore single-line comments */ }
"/*"([^*]|(\*+[^*/]))*"*/" { /* Ignore multi-line comments */ }
[ \t\n] { /* Ignore whitespace */ }
. { printf("Unknown token: %s\n", yytext); }

%%

int main()
{
    printf("Enter code: \n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
