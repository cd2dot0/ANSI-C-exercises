#include <stdio.h>
#include <ctype.h>

#define NUMBER '0' /* signal that a number was found */

int getch(void);
void ungetch(int);

/* getop_ch4: get next character or numeric operand; function from Chapter 4, pointer version */
int getop_ch4(char *s)
{
    int c;

    while ((*s = c = getch()) == ' ' || c == '\t')
        ;
    *(s + 1) = '\0';
    if(!isdigit(c) &&  c != '.')
        return c;  /* not a number */
    if(isdigit(c)) /* collect integer part */
        while(isdigit(*++s = c = getch()))
            ;
    if(c == '.') /* collect fraction part */
        while(isdigit(*++s = c = getch()))
            ;
    *s = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}
