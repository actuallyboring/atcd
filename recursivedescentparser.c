// Exercise 6: Implement a recursive descent parser to validate strings of a grammar. id+id$
// id*id+id$

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s[100];
int i = 0;

void E();
void E1();

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
    if(s[i] == 'i')   // id starts with 'i'
    {
        printf("E -> id E'\n");
        match("i");
        match("d");
        E1();
    }
    else
        error();
}

void E1()
{
    if(s[i] == '+')
    {
        printf("E' -> + id E'\n");
        match("+");
        match("i");
        match("d");
        E1();
    }
    else if(s[i] == '*')
    {
        printf("E' -> * id E'\n");
        match("*");
        match("i");
        match("d");
        E1();
    }
    else
    {
        printf("E' -> epsilon\n");
        return;
    }
}

int main()
{
    printf("Grammar:\n");
    printf("E -> id E'\n");
    printf("E' -> + id E' | * id E' | e\n");

    printf("\nEnter string: ");
    scanf("%s", s);

    E();

    if(s[i] == '\0')
        printf("\nAccepted\n");
    else
        printf("\nRejected\n");

    return 0;
}

// how to run: gcc recursivedescentparser.c -o recursivedescentparser && ./recursivedescentparser

// Sample input: id+id*id