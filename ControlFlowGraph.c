// Exercise 9: Construct a Control Flow Graph for any Basic Block.

#include <stdio.h>
#include <string.h>

char s[50][100];
int n;

int isJump(char *x)
{
    if(strstr(x,"goto") || strstr(x,"if"))
        return 1;
    return 0;
}

int main()
{
    int i, b[20], k = 0;

    printf("Enter no of statements: ");
    scanf("%d",&n);
    getchar();  

    for(i=0;i<n;i++)
    {
        fgets(s[i], sizeof(s[i]), stdin);
        s[i][strcspn(s[i], "\n")] = 0; // remove newline
    }

    b[k++] = 0;

    for(i=0;i<n;i++)
    {
        if(isJump(s[i]) && i+1<n)
            b[k++] = i+1;
    }

    printf("\nBasic Blocks:\n");

    for(i=0;i<k;i++)
    {
        printf("B%d: ", i+1);

        int start = b[i];
        int end = (i+1<k)? b[i+1] : n;

        for(int j=start;j<end;j++)
            printf("%s | ", s[j]);

        printf("\n");
    }

    printf("\nCFG Edges:\n");

    for(i=0;i<k;i++)
    {
        if(i+1<k)
            printf("B%d -> B%d\n", i+1, i+2);
        else
            printf("B%d -> End\n", i+1);
    }

    return 0;
}

// how to run: gcc ControlFlowGraph.c -o ControlFlowGraph && ./ControlFlowGraph
// sample input:
// 4
// a = 1
// b = 2
// if a < b goto L1
// goto L2