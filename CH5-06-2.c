#include <ctype.h>

/* atoi_ch2: convert s to integer; function from Chapter 2, pointer version */
int atoi_ch2(char *s)
{
    int n;

    n = 0;
    for(; *s >= '0' && *s <= '9'; s++)
        n = 10 * n + (*s - '0');

    return n;
}

/* atoi_ch3: convert s to integer; function from Chapter 3, pointer version */
int atoi_ch3(char *s)
{
    int n, sign;

    for(; isspace(*s); s++) /* skip white space */
        ;
    sign = (*s == '-') ? -1 : 1;
    if(*s == '+' || *s == '-') /* skip sign */
        s++;
    for(n = 0; isdigit(*s); s++)
        n = 10 * n + (*s - '0');
    return sign * n;
}
