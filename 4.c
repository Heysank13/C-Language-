#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m, n, i, j, a[10][10], b[10][10], c[10][10], count1 = 0, count2 = 0;

    printf("Enter the value of m and n:\n");
    scanf("%d %d", &m, &n);
    printf("Enter the elements of first matrix:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the elements of second matrix:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
                count1++;
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (b[i][j] == 0)
                count2++;
        }
    }
    if ((count1 > (m * n) / 2) && (count2 > (m * n) / 2))
    {
        printf("Given matrix is Sparsh Matrix\n");
        printf("Addition of two Sparsh Matrix is:\n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
                c[i][j] = a[i][j] + b[i][j];
        }

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf(" %d ", c[i][j]);
            }
        }
    }
    else{
        printf("Given Matrix is Not Sparsh Matrix");
    }
}