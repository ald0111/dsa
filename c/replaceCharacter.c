#include <stdio.h>
#include<ctype.h>
#include<string.h>

char replaceConsonants(char c)
{
    return tolower(c)=='z' ? (isupper(c) ? 'A' : 'a') : c+1;
}
char replaceVowels(char c)
{
    char vowels[] = "aeiou";
    char replacements[] = "uaeio";
    for (size_t i = 0; i < strlen(vowels); i++)
    {
        if (c==vowels[i])
        {
            return (isupper(c) ? toupper(replacements[i]) : replacements[i]);
        }
    }
    return c;
}

char replaceCharacter(char c)
{
    char vowels[] = "aeiou";
    for (size_t i = 0; i < strlen(vowels); i++)
    {
        if (c==vowels[i])
        {
            return replaceVowels(c);
        }
    }
    if (isalpha(c))
    {
        return replaceConsonants(c);
    }
    return c;
}

int main()
{
    char s[1000];
    fgets(s, sizeof(s), stdin);

    printf("%s\n", s);

    for (int i = 0; s[i] != '\0'; i++)
    {
        s[i] = replaceCharacter(s[i]);
    }

    printf("%s\n", s);

    return 0;
}