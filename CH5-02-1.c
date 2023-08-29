#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

/* getfloat: get next floating-point from input into *pn */
int getfloat(double *pn)
{
    int c, sign;
    double pow;

    while(isspace(c = getch())) /* skip white space */
        ;
    if(!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
    {
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if(c == '+' || c == '-') // plus or minus sign
        c = getch();
    for(*pn = 0.0; isdigit(c); c = getch()) // integer part
        *pn = 10.0 * *pn + (c - '0');
    if(c == '.')
        c = getch();
    for(pow = 1.0; isdigit(c); c = getch()) // fraction part
    {
        *pn = 10.0 * *pn + (c - '0');
        pow *= 10.0;
    }
    *pn *= sign / pow;
    if(c != EOF)
        ungetch(c);
    return c;
}
