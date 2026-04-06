// Exercise 10: To divide the given three-addreddd code into basic blocks.

#include <stdio.h>
#include <string.h>

char s[50][100];
int n;
int lead[50];

int isLeader(char *x)
{
    if(strstr(x,"goto") || strstr(x,"if"))
        return 1;
    if(strchr(x,':'))   // label like L1:
        return 1;
    return 0;
}

int main()
{
    int i, j;

    printf("Enter number of TAC lines: ");
    scanf("%d",&n);
    getchar();

    for(i=0;i<n;i++)
        gets(s[i]);

    // initialize leaders
    for(i=0;i<n;i++)
        lead[i]=0;

    lead[0]=1;  // first statement is always leader

    for(i=0;i<n;i++)
    {
        if(isLeader(s[i]))
        {
            if(i+1<n)
                lead[i+1]=1;   // next statement becomes leader
        }
    }

    int b = 1;

    printf("\nBasic Blocks:\n");

    for(i=0;i<n;i++)
    {
        if(lead[i])
        {
            printf("B%d:\n", b++);
            for(j=i; j<n && (j==i || !lead[j]); j++)
                printf("%s\n", s[j]);
        }
    }

    return 0;
}

// how to run: gcc 3AC.c -o 3AC && ./3AC
// sample input:
// Enter number of TAC lines: 5
// a=1
// b=2
// if a<b goto L1
// c=3
// L1: d=4
// goto L2