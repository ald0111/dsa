#include<stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for (size_t i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }   
}