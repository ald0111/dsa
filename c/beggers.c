#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A = 10;
    int B[5][3] = {1, 3, 10, 6, 9, 2, 3, 5, 3, 2, 8, 4, 6, 7, 5};
    int *res = (int *)calloc(A, sizeof(int));

    // int *res = (int *)malloc(sizeof(int) * A);

    // for (size_t i = 0; i < 3; i++)
    // {
    //     int l, r, p;
    //     l = B[i][0];
    //     r = B[i][1];
    //     p = B[i][2];
    //     for (size_t j = l - 1; j < r; j++)
    //     {
    //         res[j] += p;
    //     }
    // }

    // *len1 = A;
    int i, j;

    for (i = 0; i < 5; i++)
    {
        int l, r, p;
        l = B[i][0];
        r = B[i][1];
        p = B[i][2];
        res[l - 1] += p;
        if (r < A)
        {
            res[r] -= p;
        }
        for (size_t i = 0; i < A; i++)
        {
            printf("%d \t", res[i]);
        }
        printf("\n");
    }
    int sum = 0;
    for (size_t i = 0; i < A; i++)
    {
        sum += res[i];
        res[i] = sum;
    }
    for (size_t i = 0; i < A; i++)
    {
        printf("%d \t", res[i]);
    }

    return 0;
}