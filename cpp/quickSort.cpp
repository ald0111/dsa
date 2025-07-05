#include <iostream>
#include <vector>

using namespace std;

int partitionIndex(vector<int> &arr, int low, int high)
{
    int i = low;
    int j = high;

    int pivot = arr[low];
    int pi = low;

    while (i < j)
    {
        while (arr[i] <= pivot && i < high)
        {
            i++;
        }
        while (arr[j] > pivot && j > low)
        {
            j--;
        }
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    pi = j;
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return pi;
}

void qS(vector<int> &arr, int start, int end)
{
    // base case
    if (start >= end)
    {
        return;
    }

    // find pivot element
    //  int pivot = arr[start];

    // find the pivot element's correct index position
    int pi = partitionIndex(arr, start, end);

    // sort the array to the left of pivot element
    qS(arr, start, pi - 1);

    // sort the array to the right of pivot element
    qS(arr, pi + 1, end);
}

void quickSort(vector<int> &arr, int start, int end)
{
    qS(arr, start, end - 1);
}

int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// time complexity: O(n log n)
// space complexity: 0(1)