#include<set>
#include<vector>
#include<iostream>

using namespace std;

vector<int>* brute(vector<int>& v1, vector<int>& v2) {
    set<int> s;
    for(auto i:v1) s.insert(i);
    for(auto i:v2) s.insert(i);
    vector<int> * res = new vector<int>;
    for(auto i:s) (*res).push_back(i);
    return res;
}

int main () {
    vector<int> v1= {1,1,2,3,4,5,6, 7,7};
    vector<int> v2 = {2,3,4,4,4,5};

    vector<int> * b = brute(v1,v2);
    for (auto i: *b)
    {
        cout << i << " ";
    }
    return 0;
}