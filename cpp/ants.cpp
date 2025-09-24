#include <iostream>

using namespace std;

int moveAnts(vector<int> &plank, int pos)
{
    int plankLength = plank.size();
    if (plank[pos] == 1)
    {
        if (pos + 1 == plankLength)
        {
            plank[pos] = 0;
            return 0;
        }
        else
        {
            if (plank[pos + 1] != 0)
            {
                plank[pos] *= -1;
            }
            else
            {
                plank[pos] = 0;
                plank[pos + 1] = 1;
                return 1;
            }
        }
    }
    else if (plank[pos] == -1)
    {
        if (pos - 1 < 0)
        {
            plank[pos] = 0;
            return 0;
        }
        else
        {
            if (plank[pos - 1] != 0)
            {
                plank[pos] *= -1;
            }
            else
            {
                plank[pos] = 0;
                plank[pos - 1] = -1;
            }
        }
    }
    return 0;
}

int evaluate(vector<int> &plank)
{
    int antsAlive = 1;
    int count = 0;
    char o = 'a';
    for (auto i : plank)
    {
        if (i == 0)
        {
            cout << "\t   \t";
        }
        else if (i == 1)
        {
            cout << "\t" << o++ << "->\t";
        }
        else if (i == -1)
        {
            cout << "\t<-" << o++ << "\t";
        }
    }
    cout << "t=" << count << "\n";
    while (antsAlive)
    {
        count++;
        antsAlive = 0;
        for (size_t i = 0; i < plank.size(); i++)
        {
            int t = i;
            int el = plank[i];
            if (el == 1 || el == -1)
            {
                antsAlive++;
                int d = moveAnts(plank, i);
                if (d == 1)
                {
                    t++;
                }
            }
            // cout << plank[i] << " ";
            i = t;
        }
        o = 'a';
        for (auto i : plank)
        {
            if (i == 0)
            {
                cout << "\t   \t";
            }
            else if (i == 1)
            {
                cout << "\t" << o++ << "->\t";
            }
            else if (i == -1)
            {
                cout << "\t<-" << o++ << "\t";
            }
        }
        cout << "t=" << count << "\n";
        if (antsAlive == 1 && (plank[plank.size() - 1] != 0 || plank[0] != 0))
            break;
    }
    return count;
}

int main()
{
    // l=10 n=3
    // [2,4,7]
    // [r,r,l]
    int length = 0;
    int ants = 0;
    cin >> length;
    cin >> ants;
    vector<int> plank(length, 0);
    for (int i = 0; i < ants; i++)
    {
        int t = 0;
        cin >> t;
        plank[t - 1] = 1;
    }
    for (auto &i : plank)
    {
        if (i == 1)
        {
            char t;
            cin >> t;
            if (t == 'R')
            {
                i = 1;
            }
            else
            {
                i = -1;
            }
        }
    }
    for (int i = 1; i < length; i++)
        cout << "\t-" << i << "-\t";
    cout << "\t-" << length << "\n";
    int c = evaluate(plank);
    cout << "Total count " << c << "\n";
    return 0;
}
/*
Test Case 1:
Input:
10
3
2 4 7
R R L
Expected Output:
Ants start at positions 2, 4, 7 with directions Right, Right, Left.
Simulation steps printed, ending with "Total count <steps>".

Test Case 2:
Input:
5
2
1 5
R L
Expected Output:
Ants at both ends moving outwards, both fall off quickly.

Test Case 3:
Input:
8
2
3 6
L R
Expected Output:
Ants move towards each other, may collide or pass depending on logic.

Test Case 4:
Input:
6
1
3
R
Expected Output:
Single ant moves right until it falls off.

Test Case 5:
Input:
7
3
2 4 6
L R L
Expected Output:
Multiple ants, mixed directions, possible collisions.
*/
