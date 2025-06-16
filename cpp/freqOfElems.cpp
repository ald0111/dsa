#include<iostream>
#include<map>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    unordered_map<int,int> mpp;

    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " -> " << mpp[arr[i]] << endl;
    }
    cout << mpp[100];
    
    return 0;

}