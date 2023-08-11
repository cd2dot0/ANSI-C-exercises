#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
/* correctly print the length of arbitrary long input lines, and as much as possbile of the text */
main()
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */

    max = 0;
    while((len = getline(line, MAXLINE)) > 0)
    {
        printf("%d: %s\n", len, line); // print line with its length
        if(len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    if(max > 0) /* there was a line */
        printf("%s", longest);
    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[],int lim)
{
    int c, i;
    // counter increments until newline character (then you need to add 1 after the for loop
    // to take account of this character) or EOF appears
    for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if(i < lim - 1)
            s[i] = c; // assign characters to penultimate place (last place reserved for null character)
    if(i < lim - 1) // at least 2 places left
    {
        if(c == '\n')
        {
            s[i] = c;
            ++i; // take account of newline character in counter
        }
        s[i] = '\0';
    }
    else // line is too long - last place must be occupied by null character
    {
        if(c == '\n')
            ++i; // take account of newline character in counter
    }
        s[lim - 1] = '\0';

    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}
