#include <stdio.h>
#include <stdlib.h>

int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    int digitPointer = digitsSize - 1;
    int incrementedDigit = digits[digitPointer] + 1;

    int *newDigits = (int *)malloc(sizeof(int) * (digitsSize + 1));

    newDigits[digitPointer + 1] = (digits[digitPointer] + 1) % 10;
    while (digitPointer > 0)
    {
        if (incrementedDigit == 10)
        {
            digitPointer--;
            incrementedDigit = digits[digitPointer] + 1;
            newDigits[digitPointer + 1] = incrementedDigit % 10;
        }
        else
        {
            digitPointer--;
            newDigits[digitPointer + 1] = digits[digitPointer];
        }
    }
    if (incrementedDigit == 10)
    {
        // printf("new array size here");
        newDigits[0] = 1;
        *returnSize = digitsSize + 1;
        return newDigits;
    }
    else
    {
        for (int i = 0; i < digitsSize; i++)
        {
            newDigits[i] = newDigits[i + 1];
        }
        *returnSize = digitsSize;
        return newDigits;
    }
}

int main()
{
    int arr[10] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9}; // input
    int arrLen = 10;
    int returnSize = 0;

    int *newArr = plusOne(arr, arrLen, &returnSize);

    for (size_t i = 0; i < returnSize; i++)
    {
        printf("%d\t", newArr[i]);
    }
    return 0;
}