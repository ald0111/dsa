#include<stdio.h>

int maxProduct(int * nums, int n) {
    if (n<3)
    {
        printf("Invalid arguments");
        return 0;
    }
    
    int maxProd=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                int prod=nums[i]*nums[j]*nums[k];
                maxProd = prod>maxProd?prod:maxProd;
            }   
        }
    }
    return maxProd;
}

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Maximum product is: %d", maxProduct(arr,n));
    return 0;
}