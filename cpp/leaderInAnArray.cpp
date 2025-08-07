/*
Example 1:
Input:
 arr = [4, 7, 1, 0]
Output:
 7 1 0
Explanation:
 Rightmost element is always a leader. 7 and 1 are greater than the elements in their right side.

Example 2:
Input:
 arr = [10, 22, 12, 3, 0, 6]
Output:
 22 12 6
Explanation:
 6 is a leader. In addition to that, 12 is greater than all the elements in its right side (3, 0, 6),
  also 22 is greater than 12, 3, 0, 6.
*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    vector<int> ans;
    for (auto &i : nums)
    {
        cin >> i;
    }

    int rightMax = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] > rightMax)
        {
            rightMax = nums[i];
            ans.push_back(rightMax);
        }
    }

    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << "\t";

    return 0;
}