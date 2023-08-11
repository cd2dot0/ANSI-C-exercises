#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int maxline);
void reverse(char line[]);

/* reverse consecutive input lines */
main()
{
    char line[MAXLINE]; /* current input line */

    while(getline(line, MAXLINE) > 0)
    {
        reverse(line);
        printf("%s", line);
    }
    return 0;
}

/* reverse: reverse string s */
void reverse(char s[])
{
    int i, j;

    for(i = 0; s[i] != '\0'; ++i) // seek last element of line (null character)
        ;
    i = i - 2; // go back two elements (skip newline character)

    char temp_s[i+1]; // temporary array for characters

    j = 0;
    while(i >= 0)
    {
        temp_s[j] = s[i];
        --i;
        ++j;
    }
    for(--j; j >= 0; --j)
        s[j] = temp_s[j];
}
