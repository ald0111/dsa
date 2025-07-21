/*

//stdin
10
1 0 3 4 5 6 1 9 8 12


//stdout
4 - (length of longest consecutive subarray)
18 - (sum of elements in the longest consecutive array)

//constraints

Result {
    long maxLength;
    int maxPrimeMoney;
}

CityPrices {
    long * prices;
    long length;
}

void readCityPrices(long * prices, int n);
bool isIncreasingSubarray(long * arr, int n);
long longestIncreasingSubarray(long * arr, int length);
int calculateMaximumPrimeMoney(CityPrices * cityprices, Result * result);

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    long maxLength;
    int maxPrimeMoney;
} Result;

typedef struct
{
    long *prices;
    long length;
} CityPrices;

void readCityPrices(long *prices, int n);
int isIncreasingSubarray(long *arr, long start, long end); // boolean function
long longestIncreasingSubarray(long *arr, long length);
void calculateMaximumPrimeMoney(CityPrices *cityprices, Result *result);

int main()
{
    int c;
    scanf("%d", &c);
    CityPrices cp;
    Result res;
    cp.prices = (long *)malloc(sizeof(long) * c);
    cp.length = c;
    readCityPrices(cp.prices, c);
    calculateMaximumPrimeMoney(&cp, &res);
    printf("%ld %d", res.maxLength, res.maxPrimeMoney);
    return 0;
}

void readCityPrices(long *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        scanf("%ld", &arr[i]);
    }
    return;
}

int isIncreasingSubarray(long *arr, long start, long end)
{
    for (long i = start; i < end; i++)
    { // not end-1 but end
        if (arr[i] >= arr[i + 1])
        {
            return 0; // false
        }
    }
    return 1;
}

long longestIncreasingSubarray(long *arr, long length)
{
    long maxLen = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = i; j < length; j++)
        {
            // i and j represents all possible subarrays
            int t = isIncreasingSubarray(arr, i, j);
            if (t)
            {
                long l = j - i + 1;
                if (l > maxLen)
                    maxLen = l;
            }
        }
    }
    return maxLen;
}

void calculateMaximumPrimeMoney(CityPrices *cityprices, Result *result)
{
    long *prices = cityprices->prices;
    long len = cityprices->length;
    result->maxLength = longestIncreasingSubarray(prices, len);
    int start = 0;
    for (start = 0; start <= len - result->maxLength; start++)
    {
        int t = isIncreasingSubarray(prices, start, start + result->maxLength - 1);
        if (t)
        {
            break;
        }
    }
    int total = 0;
    for (long i = start; i <= start + result->maxLength - 1; i++)
    {
        total += prices[i];
    }
    result->maxPrimeMoney = total;
    return;
}