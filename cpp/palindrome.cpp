#include<iostream>
#include<string>

using namespace std;

bool isPalindrome(string s) {
    int frontPointer = 0;
    int lastPointer = s.size()-1;
    while(frontPointer<lastPointer) {

        int a = s[frontPointer];
        int b = s[lastPointer];

        if (!isalnum(a)) // if a is not a character, skip the current position from left
        {
            frontPointer++;
            continue;
        }
        if (!isalnum(b))  // if b is not a character, skip the current position from right
        {
            lastPointer--;
            continue;
        }
        
        
        if (a>90) a-=32; // if a is small letter, convert it to capital case
        if (b>90) b-=32; // if b is small letter, convert it to capital case
        if (a==b) // check if the left and right positions match
        {
            frontPointer++;
            lastPointer--;
        } else { // if they don't match they can't be the same string when reversed
            return false;
        }
    }
    return true;
}

int main() {
    // string s = "Ab   a";
    string s = "A man, a plan, a canal: Panama";
    cout << "The string " << s << " is palindrome? " << isPalindrome(s);
    return 0;
}