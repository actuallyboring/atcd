// Exp.No.9 Construct the DAG for common sub-expression elimination.

#include <stdio.h>
#include <string.h>

struct op
{
    char l;
    char r[20];
} op[10], pr[10];

int main()
{
    int i, j, n, z = 0, m, q;
    char temp, t;
    char *p, *l;

    printf("enter no of values: ");
    scanf("%d", &n);
    getchar();

    for(i = 0; i < n; i++)
    {
        printf("left: ");
        scanf(" %c", &op[i].l);
        printf("right: ");
        scanf("%s", op[i].r);
    }

    printf("\nIntermediate Code\n");
    for(i = 0; i < n; i++)
        printf("%c = %s\n", op[i].l, op[i].r);

    // Dead code elimination (basic copy)
    for(i = 0; i < n; i++)
    {
        pr[z].l = op[i].l;
        strcpy(pr[z].r, op[i].r);
        z++;
    }

    printf("\nAfter Dead Code Elimination\n");
    for(i = 0; i < z; i++)
        printf("%c = %s\n", pr[i].l, pr[i].r);

    // Common Subexpression Elimination
    for(m = 0; m < z; m++)
    {
        for(j = m + 1; j < z; j++)
        {
            if(strcmp(pr[m].r, pr[j].r) == 0)
            {
                t = pr[j].l;

                // replace duplicate with original variable
                for(i = 0; i < z; i++)
                {
                    l = strchr(pr[i].r, t);
                    if(l)
                        *l = pr[m].l;
                }

                pr[j].l = '0';   // mark duplicate
                strcpy(pr[j].r, "0");
            }
        }
    }

    printf("\nAfter Common Subexpression Elimination\n");
    for(i = 0; i < z; i++)
    {
        if(pr[i].l != '0')
            printf("%c = %s\n", pr[i].l, pr[i].r);
    }

    // Duplicate removal (final optimization)
    printf("\nOptimized Code\n");
    for(i = 0; i < z; i++)
    {
        if(pr[i].l != '0')
            printf("%c = %s\n", pr[i].l, pr[i].r);
    }

    return 0;
}

// how to run: gcc DAG.c -o DAG && ./DAG

// sample input:
// enter no of values: 4
// left: a
// right: b+c
// left: b
// right: d+e
// left: c
// right: b+c
// left: d
// right: a+b