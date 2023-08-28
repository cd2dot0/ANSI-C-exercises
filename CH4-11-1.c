#include <stdio.h>
#include <ctype.h>

#define NUMBER '0' /* signal that a number was found */

int getch(void);

/* getop: get next character or numeric operand */
/* do not use ungetch function */
int getop(char s[])
{
    int i, c;
    static int memory = -1;

    if(memory != -1)
    {
        c = memory;
        memory = -1;
    }
    else
        c = getch();

    while ((s[0] = c) == ' ' || c == '\t')
        c = getch();
    s[1] = '\0';
    if(!isdigit(c) &&  c != '.')
        return c;  /* not a number */
    i = 0;
    if(isdigit(c)) /* collect integer part */
        while(isdigit(s[++i] = c = getch()))
            ;
    if(c == '.') /* collect fraction part */
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if(c != EOF)
        memory = c;
    return NUMBER;
}
