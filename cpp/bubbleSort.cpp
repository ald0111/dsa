#include <iostream>

using namespace std;

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool sorted = true;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                sorted = false;
            }
        }
        if (sorted)
        {
            break;
        }
    }
}
// worst case O(n^2)
// best case O(n)

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bubble_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}