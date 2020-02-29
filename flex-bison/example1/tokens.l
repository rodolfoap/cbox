%{
#include <stdio.h>
%}

%%
[0-9]+           	printf("%s\t [NUMBER]\n", yytext);
[a-zA-Z][a-zA-Z0-9]*    printf("%s\t [WORD]\n", yytext);
%%
