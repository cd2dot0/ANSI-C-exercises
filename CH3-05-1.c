/* itob: convert the integer n into a base b character represantation in the string s */
void itob(int n, char s[], unsigned int b)
{
    int i, sign;
    unsigned un, r;
    void reverse(char s[]);

    if((sign = n) < 0) /* record sign */
        un = 1 + (unsigned) ~n; // conversion to take account of two's complement
    else
        un = (unsigned) n;

    i = 0;
    do /* generate digits in reverse order */
    {
        if((r = un % b) < 10)
            s[i++] = r + '0'; /* get next digit */
        else
            s[i++] = r - 10 + 'A';
    }
    while ((un /= b) > 0); /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
