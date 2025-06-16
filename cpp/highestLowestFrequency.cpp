#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mpp[arr[i]]++;
    }

    int lowest = INT_MAX;
    int highest = 0;
    int highElem;
    int lowElem;

    for (auto s : mpp)
    {
        if (s.second > highest)
        {
            highest = s.second;
            highElem = s.first;
        }
        if (s.second < lowest)
        {
            lowest = s.second;
            lowElem = s.first;
        }
    }
    cout << "Highest element is " << highElem << endl;
    cout << "lowest element is " << lowElem << endl;

    return 0;
}