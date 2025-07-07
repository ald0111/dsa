#include <set>
#include <vector>
#include <iostream>

using namespace std;

vector<int> *brute(vector<int> &v1, vector<int> &v2)
{
    set<int> s;
    for (auto i : v1)
        s.insert(i);
    for (auto i : v2)
        s.insert(i);
    vector<int> *res = new vector<int>;
    for (auto i : s)
        (*res).push_back(i);
    return res;
}

vector<int> unionOfArrays(vector<int> &v1, vector<int> &v2)
{
    vector<int> res;
    int i = 0;
    int j = 0;
    int n1 = v1.size();
    int n2 = v2.size();
    int c = -1;
    while (i < n1 && j < n2)
    {
        if (v1[i] <= v2[j])
        {
            if (c < 0 || v1[i] != res[c])
            {
                res.push_back(v1[i]);
                c++;
            }
            i++;
        }
        else
        {
            if (c < 0 || v2[j] != res[c])
            {
                res.push_back(v2[j]);
                c++;
            }
            j++;
        }
    }
    while (i < n1)
    {
        if (c < 0 || v1[i] != res[c])
        {
            res.push_back(v1[i]);
            c++;
        }
        i++;
    }
    while (j < n2)
    {
        if (c < 0 || v2[j] != res[c])
        {
            res.push_back(v2[j]);
            c++;
        }
        j++;
    }
    return res;
}

vector<int> intersectionOfArrays(vector<int> &v1, vector<int> &v2)
{
    vector<int> res;
    int i = 0;
    int j = 0;
    int n1 = v1.size();
    int n2 = v2.size();
    int c = -1;
    while (i < n1 && j < n2)
    {
        if (v1[i] == v2[j])
        {
            res.push_back(v1[i]);
            i++;
            j++;
            c++;
        }
        else if (v1[i] < v2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return res;
}

int main()
{
    vector<int> v1 = {1, 1, 2, 3, 4, 4, 5, 6, 7, 7};
    vector<int> v2 = {2, 3, 4, 4, 4, 5};

    vector<int> *b = brute(v1, v2);
    for (auto i : *b)
    {
        cout << i << " ";
    }

    cout << endl;

    vector<int> r = unionOfArrays(v1, v2);
    for (auto i : r)
        cout << i << " ";

    cout << endl;

    vector<int> r1 = intersectionOfArrays(v1, v2);
    for (auto i : r1)
        cout << i << " ";

    return 0;
}