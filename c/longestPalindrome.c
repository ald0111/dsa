/*
bool isPalindrome()
int findLongestPalindrome()

INPUT:
racecar

OUTPUT:
aceca

INPUT:
56648466

OUTPUT:
6648466

*/

#include<stdio.h>
#include<string.h>

int isPalindrome(char * s, int start, int end) {
    int isPal = 1;
    // printf("satrt - %d end - %d",start,end);
    while(start<end) {
        if (s[start]!=s[end])
        {
            isPal=0;
            break;
        }
        start++;
        end--;
    }
    return isPal;
}

void findLongestPalidrome(char * s, int len) {
    int maxLen=0;
    int maxI=0;
    int maxJ=0;
    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = 0; j < len; j++)
        {
            int palLen=j-i+1;
            if(palLen == len) continue;
            int res = isPalindrome(s,i,j);
            if (res)
            {
                if (palLen>maxLen)
                {
                    maxLen=palLen;
                    maxI=i;
                    maxJ=j;
                }
            }
        }
    }
    for(int i=maxI; i<=maxJ; i++) {
        printf("%c",s[i]);
    }
    return;
}

int main() {
    char s[1000];
    fgets(s, 1000, stdin);
    findLongestPalidrome(s,strlen(s));
    return 0;
}