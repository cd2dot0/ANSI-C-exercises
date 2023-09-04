#include <ctype.h>

/* atof_ch4: convert string s to double; function from Chapter 4, pointer version */
double atof_ch4(char *s)
{
    double val, power;
    int sign;

    for(; isspace(*s); s++) /* skip white space */
        ;
    sign = (*s == '-') ? -1 : 1;
    if(*s == '+' || *s == '-')
        s++;
    for(val = 0.0; isdigit(*s); s++)
        val = 10.0 * val + (*s - '0');
    if(*s == '.')
        s++;
    for(power = 1.0; isdigit(*s); s++)
    {
        val = 10.0 * val + (*s - '0');
        power *= 10;
    }
    return sign * val / power;
}
