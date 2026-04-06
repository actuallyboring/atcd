// Exercise 8: Implement TAC Generation for Control Statements.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int l = 1;

void if1(char *c)
{
    printf("if %s goto L%d\n", c, l);
    l++;
    printf("goto L%d\n", l);
    l++;
}

void ifelse(char *c)
{
    int x = l;

    printf("if %s goto L%d\n", c, x);
    printf("goto L%d\n", x+1);

    printf("L%d:\n", x);
    printf("... true block ...\n");
    printf("goto L%d\n", x+2);

    printf("L%d:\n", x+1);
    printf("... false block ...\n");

    l = x + 3;
}

void wh(char *c)
{
    int x = l;

    printf("L%d:\n", x);
    printf("if %s goto L%d\n", c, x+1);
    printf("goto L%d\n", x+2);

    printf("L%d:\n", x+1);
    printf("... loop body ...\n");
    printf("goto L%d\n", x);

    printf("L%d:\n", x+2);

    l = x + 3;
}

int main()
{
    if1("a<b");

    ifelse("a>b");

    wh("i<10");

    return 0;
}

// how to run: gcc TACgeneration.c -o TACgeneration && ./TACgeneration
// sample input: none (the code generates TAC for predefined conditions)