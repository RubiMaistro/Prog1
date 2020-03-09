% {

#include <string.h>
int szamok=0;
} %

%%
"0" { printf("O"); }
"1" { printf("I"); }
"2" { printf("Z"); }
"3" { printf("E"); }
"4" { printf("A"); }

"5" { printf("S"); }
"6" { printf("b"); }
"7" { printf("T"); }
"8" { printf("B"); }
"9" { printf("P"); }


"O" { printf("0"); }
"I" { printf("1"); }
"Z" { printf("2"); }
"E" { printf("3"); }
"A" { printf("4"); }

"S" { printf("5"); }
"b" { printf("6"); }
"T" { printf("7"); }
"B" { printf("8"); }
"P" { printf("9"); }

%%

int main()
{
   yylex();
   printf("%d szam", szamok);
retrun 0;
}
