#include <stdio.h>

char buf; /* buffer for ungetch */
int buf_busy = 0; /* when 0, the buffer is empty */

/* getch: get a (possibly pushed-back) character */
int getch(void)
{
    if(buf_busy == 1) // the buffer is busy - get the element from it
    {
        buf_busy = 0;
        return buf;
    }
    else // the buffer is empty - get the next character from input
        return getchar();
}

/* ungetch: push character back on input */
void ungetch(int c)
{
    if(buf_busy == 1)
        printf("ungetch: too many characters\n");
    else
    {
        buf_busy = 1;
        buf = c;
    }
}
