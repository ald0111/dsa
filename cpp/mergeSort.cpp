#include <iostream>

using namespace std;

void merge(int *arr, int start, int mid, int end, int *temp)
{
    // merge
    for (int i = start; i < mid + 1; i++)
    {
        temp[i] = arr[i];
    }
    for (int i = mid + 1; i < end + 1; i++)
    {
        temp[i] = arr[i];
    }

    int l = start;
    int r = mid + 1;
    int c = start;

    while (l <= mid && r <= end)
    {
        if (temp[l] <= temp[r])
        {
            arr[c] = temp[l];
            l++;
        }
        else
        {
            arr[c] = temp[r];
            r++;
        }
        c++;
    }
    while (l <= mid)
    {
        arr[c] = temp[l];
        l++;
        c++;
    }
    while (r <= end)
    {
        arr[c] = temp[r];
        r++;
        c++;
    }
}

void mS(int *arr, int start, int end, int *temp)
{
    // base case for recursion
    if (start >= end)
    {
        return;
    }

    // split
    int mid = (start + end) / 2;

    // sort
    mS(arr, start, mid, temp);
    mS(arr, mid + 1, end, temp);

    // merge
    merge(arr, start, mid, end, temp);
}

void mergeSort(int *arr, int start, int end)
{
    int *temp = new int[end];
    mS(arr, start, end - 1, temp);
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// time complexity: O(n log n)
// space complexity: O(n)
//      |----- due to the auxilary temp array used when merging the sorted sub arrays