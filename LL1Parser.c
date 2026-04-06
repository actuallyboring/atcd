// Exercise 7: Construction of Parse Tree using LL(1) Parser for any CFG.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s[100];
int i = 0;

void E(), E1(), T(), T1(), F();

void error()
{
    printf("\nRejected\n");
    exit(0);
}

void match(char *t)
{
    int k, l = strlen(t);
    for(k = 0; k < l; k++)
    {
        if(s[i] == t[k])
        {
            printf("matched: %c\n", s[i]);
            i++;
        }
        else
            error();
    }
}

void E()
{
    printf("E -> T E'\n");
    T();
    E1();
}

void E1()
{
    if(s[i] == '+')
    {
        printf("E' -> + T E'\n");
        match("+");
        T();
        E1();
    }
    else
    {
        printf("E' -> e\n");
    }
}

void T()
{
    printf("T -> F T'\n");
    F();
    T1();
}

void T1()
{
    if(s[i] == '*')
    {
        printf("T' -> * F T'\n");
        match("*");
        F();
        T1();
    }
    else
    {
        printf("T' -> e\n");
    }
}

void F()
{
    if(s[i] == 'i')   // id = "id"
    {
        printf("F -> id\n");
        match("i");
        match("d");
    }
    else if(s[i] == '(')
    {
        printf("F -> (E)\n");
        match("(");
        E();
        match(")");
    }
    else
        error();
}

int main()
{
    printf("Grammar:\n");
    printf("E -> T E'\n");
    printf("E' -> + T E' | e\n");
    printf("T -> F T'\n");
    printf("T' -> * F T' | e\n");
    printf("F -> id | (E)\n");

    printf("\nEnter string: ");
    scanf("%s", s);

    E();

    if(s[i] == '\0')
        printf("\nAccepted\n");
    else
        printf("\nRejected\n");

    return 0;
}

// how to run: gcc LL1Parser.c -o LL1Parser && ./LL1Parser
// sample input: id+id*id