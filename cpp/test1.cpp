#include<iostream>
#include<utility>

using namespace std;
int main () {
    pair<int,int> p1;
    p1 = make_pair(1,2);
    cout << p1.first << endl << p1.second;
    return 0;
}