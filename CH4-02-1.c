#include <ctype.h>

/* atof_exp: convert string s to double, handle scientific notation */
double atof_exp(char s[])
{
    double val, power, n, x;
    int i, sign, sign_exp, exp;

    for(i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1; // check sign
    if(s[i] == '+' || s[i] == '-')
        i++;
    for(val = 0.0; isdigit(s[i]); i++) // calculate integer part
        val = 10.0 * val + (s[i] - '0');

    if(s[i] == '.') // detect fraction
        i++;
    for(power = 1.0; isdigit(s[i]); i++) // calculate fractional part
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    n = 1.0;
    if(s[i] == 'e' || s[i] == 'E') // detect scientific notation
    {
        i++;
        sign_exp = (s[i] == '-') ? -1 : 1; // check sign of exponent
        if(s[i] == '+' || s[i] == '-')
            i++;
        for(exp = 0; isdigit(s[i]); i++) // save the exponent
            exp = 10 * exp + (s[i] - '0');
        if(sign_exp == 1) // positive exponent
            x = 10.0;
        else if (sign_exp == -1) // negative exponent
            x = 1.0/10.0;
        for(; exp != 0; exp--)
            n *= x; // multiplying by 0.1 is less accurate than dividing by 10
    }

    return sign * val / power * n;
}
