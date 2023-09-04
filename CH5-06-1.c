#include <stdio.h>

/* getline_ch1: read a line into s, return length; function from Chapter 1, pointer version */
int getline_ch1(char *s, int lim)
{
    int c;
    char *s0;

    s0 = s; // remember initial address

    for(; s - s0 < lim - 1 && (c = getchar()) != EOF && c != '\n'; s++)
        *s = c;
    if(c == '\n')
    {
        *s++ = c;
    }
    *s = '\0';
    return s - s0;
}

/* getline_ch4: read a line into s, return length; function from Chapter 4, pointer version */
int getline_ch4(char *s, int lim)
{
    int c;
    char *s0;

    s0 = s; // remember initial address

    while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if(c == '\n')
        *s++ = c;
    *s = '\0';
    return s - s0;
}
