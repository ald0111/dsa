/*
Test case - 1
//stdin

5
listen - (OG)
stilen 
nsltie
stinel
hello
world

//stdout

listen
hello
world



Test case - 2
//stdin

5
abc - OG
cba
def
fba

//stdout

abc
def

*/


#include<stdio.h>

int isAnagram(char * originalWord, char * testWord) {
    int fq[256] = {0};
    for(int i=0; originalWord[i]!='\0'; i++) fq[(int) originalWord[i]]++;
    for(int i=0; testWord[i]!='\0'; i++) fq[(int) testWord[i]]--;
    for(int i=0; i<256; i++) 
    {
        if (fq[i]!=0)
        {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    scanf("%d",&n);
    char originalWord[1000];
    char testWord[1000];
    getchar();
    gets(originalWord);
    printf("%s\n",originalWord);
    for (int i = 1; i < n; i++)
    {
        //read testword from stdin
        gets(testWord);
        //find if OG and testword are anagrams.
        // if not print
        int res = isAnagram(originalWord, testWord);
        if (res)
        {
            continue;
        } else {
            printf("%s\n",testWord);
        }
    }
    return 0;
}