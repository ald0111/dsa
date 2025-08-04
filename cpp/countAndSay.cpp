#include<iostream>

using namespace std;

/*
1
11
21
1211
111221
312211
*/

void nextPattern(int count, string prev) { //3, "21"
    if(count>0) { // true
        string res;
        char c = prev[0]; // 2
        int charcount = 1;
        for (size_t i = 1; i < prev.length(); i++)
        {
            char t=prev[i]; // 1
            if(t==c) {
                charcount++;
            } else {
                //push to new string
                res += to_string(charcount);
                res += c;
                charcount=1;
                c=t;
            }
        }
        res += to_string(charcount);
        res += (c);
        cout << res << endl;
        nextPattern(count-1,res);
    }
    return;
}

int main() {
    int n; //5
    cin >> n;
    cout << 1 << endl;
    nextPattern(n-1,"1"); //4, "1"
    return 0;
}