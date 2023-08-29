#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn, push alone characters + and - back on the input */
int getint(int *pn)
{
    int c, c_prev, sign;

    while(isspace(c = getch())) /* skip white space */
        ;
    if(!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if(c == '+' || c == '-')
    {
        c_prev = c; // save the sign
        c = getch();
    }
    if(isdigit(c)) // check if there is a digit after the sign
    {
        for(*pn = 0; isdigit(c); c = getch())
            *pn = 10 * *pn + (c - '0');
        *pn *= sign;
        if(c != EOF)
            ungetch(c);
        return c;
    }
    if(c != EOF)
        ungetch(c); // push back a non-digit character
    ungetch(c_prev); // push back the sign
    return 0;
}
