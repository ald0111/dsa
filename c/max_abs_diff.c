#include <stdio.h>
#include <stdlib.h>

int myFnc(int i, int j, int *A)
{
    return (abs((A[i] - A[j])) + abs((i - j)));
}
int maxArr(int *A, int n1)
{
    int i, j;
    int max = myFnc(0, 0, A);
    for (i = 1; i < n1; i++)
    {
        for (j = 0; j < n1; j++)
        {
            int l = myFnc(i, j, A);
            if (l > max)
                max = l;
        }
    }
    return max;
}
int main()
{
    int Ar[] = {7, 1, 3, 2, 9, -11, 8};
    printf("%d", maxArr(Ar, 7));
}