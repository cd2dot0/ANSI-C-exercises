#include  <stdio.h>

#define BUFSIZE 100

// EOF = -1, so the character has negative value. We necessarily must change
// char type to int for buf variable, otherwise the conversion char -> int
// in getch function gives different results, which depend on the platform.

int buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

/* getch: get a (possibly pushed-back) character */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
